#include "ten.h"

using namespace bvme;

CImage Dilatation(CImage& inputImage, int size) {

	int offeset = size / 2;

	int width = inputImage.getWidth() - offeset;
	int height = inputImage.getHeight() - offeset;

	CImage resultImage(height, width, true);
	CColor white(255);
	CColor black(0);

	for (int x = offeset; x < height; x++)
	{
		for (int y = offeset; y < width; y++)
		{
			for (int yOffset = -1 * offeset; yOffset <= offeset; yOffset++)
			{
				for (int xOffset = -1 * offeset; xOffset <= offeset; xOffset++)
				{
					int greyValue = inputImage.getPointValue(x + xOffset, y + yOffset).getGrey();

					if (greyValue == 255)
					{
						resultImage.setPointValue(x, y, white);
					}
				}
			}
		}
	}

	return resultImage;

}



CImage Erosion(CImage& inputImage, int size) {

	int offeset = size / 2;

	int width = inputImage.getWidth() - offeset;
	int height = inputImage.getHeight() - offeset;

	CImage resultImage(height, width, true);
	CColor white(255);
	CColor black(0);

	for (int x = offeset; x < height; x++)
	{
		for (int y = offeset; y < width; y++)
		{
			bool is255 = true;
			for (int yOffset = -1 * offeset; yOffset <= offeset; yOffset++)
			{
				for (int xOffset = -1 * offeset; xOffset <= offeset; xOffset++)
				{
					int greyValue = inputImage.getPointValue(x + xOffset, y + yOffset).getGrey();

					if (greyValue != 255)
					{
						is255 = false;
					}
				}

				if (is255) {
					resultImage.setPointValue(x, y, white);
				}

			}
		}
	}

	return resultImage;

}