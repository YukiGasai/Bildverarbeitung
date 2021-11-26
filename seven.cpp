#include "seven.h"
#include "two.h"
#include <iostream>

using namespace bvme;

CImage HistogrammLinearisierungRGB(CImage& inputImage) {

	const int width = inputImage.getWidth();
	const int height = inputImage.getHeight();

	CImage redImage = CImage(height, width, true);
	CImage greenImage = CImage(height, width, true);
	CImage blueImage = CImage(height, width, true);

	CImage resultImage = CImage(height, width,false);
	
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
		
			CColor redGrey = CColor(inputImage.getPointValue(y, x).getRed());
			CColor greenGrey = CColor(inputImage.getPointValue(y, x).getGreen());
			CColor blueGrey = CColor(inputImage.getPointValue(y, x).getBlue());
			
			redImage.setPointValue(y, x, redGrey);
			greenImage.setPointValue(y, x, greenGrey);
			blueImage.setPointValue(y, x, blueGrey);

		}
	}


	redImage = Histogrammlinearisierung(&redImage);
	greenImage = Histogrammlinearisierung(&greenImage);
	blueImage = Histogrammlinearisierung(&blueImage);

	redImage.showImage("RED");
	greenImage.showImage("Green");
	blueImage.showImage("Blue");

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			
			int red   = redImage.getPointValue(y, x).getGrey();
			int green = greenImage.getPointValue(y, x).getGrey();
			int blue  = blueImage.getPointValue(y, x).getGrey();

		
			CColor resultColor = CColor(red,green,blue);

			resultImage.setPointValue(y, x, resultColor);

		}
	}

	return resultImage;
}