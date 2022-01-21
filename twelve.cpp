#include "twelve.h"
#include "three.h"

#include <iostream>

using namespace bvme;


CImage Moravec(CImage& inputImage, int size) {
	
	//Get Basic Data from Array
	int ImageHeight = inputImage.getHeight();
	int ImageWidth = inputImage.getWidth();

	CImage resultImage = CImage(ImageHeight, ImageWidth, 1);


	int offset = (int)size / 2;
	int c = 0;
	for (int y = offset; y < ImageHeight - offset; y++)
	{
		for (int x = offset; x < ImageWidth - offset; x++)
		{
			int newGrey = 0;
			int centerValue = inputImage.getPointValue(y,x).getGrey();


			newGrey += abs(inputImage.getPointValue(y - 1, x - 1).getGrey() - centerValue);
			newGrey += abs(inputImage.getPointValue(y - 0, x - 1).getGrey() - centerValue);
			newGrey += abs(inputImage.getPointValue(y + 1, x - 1).getGrey() - centerValue);

			newGrey += abs(inputImage.getPointValue(y - 1, x - 0).getGrey() - centerValue);
			newGrey += abs(inputImage.getPointValue(y - 0, x - 0).getGrey() - centerValue);
			newGrey += abs(inputImage.getPointValue(y + 1, x - 0).getGrey() - centerValue);

			newGrey += abs(inputImage.getPointValue(y - 1, x + 0).getGrey() - centerValue);
			newGrey += abs(inputImage.getPointValue(y - 0, x + 0).getGrey() - centerValue);
			newGrey += abs(inputImage.getPointValue(y + 1, x + 0).getGrey() - centerValue);
		
		


			CColor newGreyColor = CColor(newGrey);


			resultImage.setPointValue(y, x, newGreyColor);

		}
	}

	return resultImage;
}



CImage GetBinary(CImage& inputImage) {
	int ImageHeight = inputImage.getHeight();
	int ImageWidth = inputImage.getWidth();

	for (int y = 0; y < ImageHeight; y++)
	{
		for (int x = 0; x < ImageWidth; x++)
		{
			int grey = inputImage.getPointValue(y, x).getGrey();
			if (grey != 0) {
				CColor newGreyColor = CColor(1);
				inputImage.setPointValue(y, x, newGreyColor);
			}
		}
	}
	return inputImage;
}


CImage LightUp(CImage& inputImage) {
	int ImageHeight = inputImage.getHeight();
	int ImageWidth = inputImage.getWidth();

	for (int y = 0; y < ImageHeight; y++)
	{
		for (int x = 0; x < ImageWidth; x++)
		{
		
			int newGrey = inputImage.getPointValue(y, x).getGrey();
			if (newGrey > 3) {
				CColor newGreyColor = CColor(255);
				inputImage.setPointValue(y, x, newGreyColor);
			}
			else {
				CColor newGreyColor = CColor(newGrey*20);
				inputImage.setPointValue(y, x, newGreyColor);
			}
		}
	}
	return inputImage;
}