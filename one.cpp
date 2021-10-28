#include <iostream>
#include <stdexcept>
#include "CImage.h"
#include "CColor.h"
#include "one.h"

using namespace bvme;


CImage greyScale(CImage* inputImage, int t) {

	if (t > 255) {
		throw std::invalid_argument("t is out of bounds");
	}
	int width = inputImage->getWidth();
	int height = inputImage->getHeight();

	CImage* image = new CImage(height, width, true);
	for (int y = 0; y < width; y++)
	{
		for (int x = 0; x < height; x++)
		{

			int red = inputImage->getPointValue(x, y).getRed();
			int green = inputImage->getPointValue(x, y).getGreen();
			int blue = inputImage->getPointValue(x, y).getBlue();

			float gray = (red + green + blue) / 3;

			if (t != -1) {
				if (gray > t) {
					gray = 255;
				}
				else {
					gray = 0;
				}
			}
			CColor color = CColor(gray);
			image->setPointValue(x, y, color);
		}
	}
	return *image;
}

CImage findMinMaxPoints(CImage* inputImage) {
	int width = inputImage->getWidth();
	int height = inputImage->getHeight();


	int maxGray = 0;
	int maxX = 0;
	int maxY = 0;
	int minGray = 255;
	int minX = 0;
	int minY = 0;

	CImage* image = new CImage(height, width, true);
	for (int y = 0; y < width; y++)
	{
		for (int x = 0; x < height; x++)
		{

			int red = inputImage->getPointValue(x, y).getRed();
			int green = inputImage->getPointValue(x, y).getGreen();
			int blue = inputImage->getPointValue(x, y).getBlue();

			float gray = (red + green + blue) / 3;

			CColor color = CColor(gray);

			image->setPointValue(x, y, color);

			if (gray > maxGray) {
				maxGray = gray;
				maxX = x;
				maxY = y;
			}

			if (gray < minGray) {
				minGray = gray;
				minX = x;
				minY = y;
			}
		}
	}

	CColor color1 = CColor(255);
	CColor color2 = CColor(0);

	for (int x = minX - 10; x < minX + 10; x++)
	{
		for (int y = minY - 10; y < minY + 10; y++)
		{
			image->setPointValue(x, y, color1);
		}
	}

	for (int x = maxX - 10; x < maxX + 10; x++)
	{
		for (int y = maxY - 10; y < maxY + 10; y++)
		{
			image->setPointValue(x, y, color2);
		}
	}

	std::cout << "MIN VALUE " << minGray << " at " << minX << " " << minY << std::endl;
	std::cout << "MAX VALUE " << maxGray << " at " << maxX << " " << maxY << std::endl;
	return *image;
}

