#include "three.h"

using namespace bvme;

CImage Wichzeichnen(CImage& inputImage, int** mask, int size) {



	//Get Basic Data from Array
	int ImageHeight = inputImage.getHeight();
	int ImageWidth = inputImage.getWidth();

	CImage resultImage = CImage(ImageHeight, ImageWidth, 1);

	int divisor = 0;

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			divisor += mask[x][y];
		}
	}


	int offset = (int)size / 2;


	for (int y = offset; y < ImageHeight - offset; y++)
	{
		for (int x = offset; x < ImageWidth - offset; x++)
		{
			int cluster = 0;

			for (int ymask = 0; ymask < size; ymask++)
			{
				for (int xmask = 0; xmask < size; xmask++)
				{

					int inputGrey = (inputImage.getPointValue(y - offset + ymask, x - offset + xmask).getBlue() + inputImage.getPointValue(y - offset + ymask, x - offset + xmask).getGreen() + inputImage.getPointValue(y - offset + ymask, x - offset + xmask).getRed()) / 3;

					//std::cout << "OLD GREY " << inputGrey << std::endl;
					cluster += mask[xmask][ymask] * inputGrey;
				}
			}
			int newGrayValue = cluster;
			if (divisor > 0) {
				newGrayValue = cluster / divisor;
			}


			//std::cout << newGrayValue <<  std::endl;
			CColor newGrey = CColor(abs(newGrayValue));

			resultImage.setPointValue(y, x, newGrey);

		}
	}
	return resultImage;

}

