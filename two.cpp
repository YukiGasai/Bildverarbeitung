#include <iostream>
#include "CImage.h"
#include "CColor.h"
#include "two.h"
using namespace bvme;

int getMiddleGrayLevel(CImage* inputImage) {

	const int width = inputImage->getWidth();
	const int height = inputImage->getHeight();
	int oldMiddle = 0;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			oldMiddle += inputImage->getPointValue(y, x).getBlue();
			oldMiddle += inputImage->getPointValue(y, x).getGreen();
			oldMiddle += inputImage->getPointValue(y, x).getRed();

		}
	}

	oldMiddle = oldMiddle / (width * height * 3);

	while (true) {

		int smalerGrayAvaerage = 0;
		int biggerGrayAvaerage = 0;
		int smallLength = 0;
		int bigLength = 0;


		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				int currentGrey = 0;
				currentGrey += inputImage->getPointValue(y, x).getBlue();
				currentGrey += inputImage->getPointValue(y, x).getGreen();
				currentGrey += inputImage->getPointValue(y, x).getRed();

				currentGrey = (int)(currentGrey / 3);

				if (currentGrey < oldMiddle) {
					smalerGrayAvaerage += currentGrey;
					smallLength++;
				}
				else {
					biggerGrayAvaerage += currentGrey;
					bigLength++;
				}
			}
		}

		smalerGrayAvaerage = smalerGrayAvaerage / smallLength;
		biggerGrayAvaerage = biggerGrayAvaerage / bigLength;

		int newMiddle = (smalerGrayAvaerage + biggerGrayAvaerage) / 2;

		if (abs(oldMiddle - newMiddle) < 1) {
			return newMiddle;
		}

		oldMiddle = newMiddle;

		std::cout << newMiddle << std::endl;
	}
}



CImage Histogrammlinearisierung(CImage* inputImage) {
	float histogramm[256] = { 0 };

	float newHistogramm[256] = { 0 };

	const int width = inputImage->getWidth();
	const int height = inputImage->getHeight();

	CImage resultImage = CImage(height, width, true);

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int currentGray = 0;
			currentGray += inputImage->getPointValue(y, x).getBlue();
			currentGray += inputImage->getPointValue(y, x).getGreen();
			currentGray += inputImage->getPointValue(y, x).getRed();
			currentGray = currentGray / 3;

			histogramm[currentGray] += 1;

		}
	}

	float cumulatedValue = 0;

	for (int i = 0; i < 256; i++)
	{
		cumulatedValue += histogramm[i] / (width * height);

		newHistogramm[i] = cumulatedValue;
	}


	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int currentGray = 0;
			currentGray += inputImage->getPointValue(y, x).getBlue();
			currentGray += inputImage->getPointValue(y, x).getGreen();
			currentGray += inputImage->getPointValue(y, x).getRed();
			currentGray = currentGray / 3;

			int betterGray = newHistogramm[currentGray] * 255;

			CColor color = CColor(betterGray);

			resultImage.setPointValue(y, x, color);

		}
	}


	return resultImage;
}



