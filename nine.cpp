#include <iostream>
#include "nine.h"

using namespace bvme;


CImage copyImage(CImage& inputImage) {
	int width = inputImage.getWidth();
	int height = inputImage.getHeight();

	CImage out(height, width, true);

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int grey = inputImage.getPointValue(y, x).getGrey();
			CColor color(grey);
			out.setPointValue(y, x, color);
		}
	}
	return out;
}


CImage Wavelettransformation(CImage& inputImage, int reduction) {

	int width = inputImage.getWidth();
	int height = inputImage.getHeight();
	CImage result = CImage(height, width, true);

	for (int i = 1; i <= reduction; i++)
	{
		width = inputImage.getWidth() / i;
		height = inputImage.getHeight() / i;


		for (int x = 0; x < height; x++)
		{
			for (int y = 0; y < width; y += 2)
			{
				//new Image Pixel
				int oldGrey = inputImage.getPointValue(x, y).getGrey();
				int newGrey = (inputImage.getPointValue(x, y).getGrey() + inputImage.getPointValue(x, y + 1).getGrey()) / 2;
				CColor c1 = CColor(newGrey);
				result.setPointValue(x, y / 2, c1);

				//New Error Pixel
				newGrey = newGrey - oldGrey;
				CColor c2 = CColor(newGrey);
				result.setPointValue(x, width / 2 + y / 2, c2);
			}
		}

		inputImage = copyImage(result);

		for (int y = 0; y < width / 2; y++)
		{
			for (int x = 0; x < height; x += 2) {
				//new Image Pixel
				int oldGrey = inputImage.getPointValue(x, y).getGrey();
				int newGrey = (inputImage.getPointValue(x, y).getGrey() + inputImage.getPointValue(x + 1, y).getGrey()) / 2;
				CColor c1 = CColor(newGrey);
				result.setPointValue(x / 2, y, c1);

				//New Error Pixel
				newGrey = newGrey - oldGrey;
				CColor c2 = CColor(newGrey);
				result.setPointValue(height / 2 + x / 2, y, c2);
			}
		}

		inputImage = copyImage(result);
	}



	return result;

}



