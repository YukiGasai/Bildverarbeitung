#include "eight.h"
#include "three.h"

using namespace bvme;


CImage Sobelfilter(CImage& inputImage) {

	int width = inputImage.getWidth();
	int height = inputImage.getHeight();

	int size = 3;

	int** mask = new int* [size];
	for (int i = 0; i < size; ++i)
		mask[i] = new int[size];



	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			mask[x][y] = 1;
		}
	}

	mask[0][0] = 1;
	mask[1][0] = 2;
	mask[2][0] = 1;
	mask[0][1] = 0;
	mask[1][1] = 0;
	mask[2][1] = 0;
	mask[0][2] = -1;
	mask[1][2] = -2;
	mask[2][2] = -1;



	CImage horizontal = Wichzeichnen(inputImage, mask, size);
	horizontal.showImage("horizontal");


	mask[0][0] = 1;
	mask[1][0] = 0;
	mask[2][0] = -1;
	mask[0][1] = 2;
	mask[1][1] = 0;
	mask[2][1] = -2;
	mask[0][2] = 1;
	mask[1][2] = 0;
	mask[2][2] = -1;

	CImage vertical = Wichzeichnen(inputImage, mask, size);
	vertical.showImage("vertical");

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int greyValue =abs((horizontal.getPointValue(y, x).getGrey() + vertical.getPointValue(y, x).getGrey()) / 2);
			CColor newGrey(greyValue);
			horizontal.setPointValue(y, x, newGrey);
		}
	}

	horizontal.showImage("DONE");
	return horizontal;
}