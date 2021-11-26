#include "five.h"
#include "CImage.h"
#include "CColor.h"
#include <iostream>

using namespace bvme;

int cmpfunc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int LevelA(const int ZXY, const int SMax, const int size, int* _array) {

	int ZMed = _array[(size * size) / 2];
	int ZMin = _array[0];
	int ZMax = _array[size * size - 1];

	int A1 = ZMed - ZMin;
	int A2 = ZMed - ZMax;

	if (A1 > 0 && A2 < 0) {
		//=================================LEVEL B START
		int B1 = ZXY - ZMin;
		int B2 = ZXY - ZMax;
		if (B1 > 0 && B2 < 0) {
			return ZXY;
		}
		else {
			return ZMed;
		}
		//=================================LEVEL B ENDE
	}
	else {
		if (size + 2 <= SMax) {
			return -1;
			//Return -1 to make the wile loop change the window size and run again
		}
		else {
			return ZXY;
		}
	}
}



CImage MedianFilter(CImage& inputImage, int SMax) {
	int size = 3;

	int width = inputImage.getWidth();
	int height = inputImage.getHeight();

	CImage resultImage = CImage(height, width, true);

	int maxOffset = SMax / 2;


	//Loop over every Pixel in image except the frame
	for (int x = maxOffset; x < height- maxOffset; x++)
	{
		for (int y = maxOffset; y < width - maxOffset; y++)
		{

			int resultgrey = -1;


			//Try to get a new grey value as long as the result grey is -1
			do {
				//create new mask
				int* array = new int[size * size];

				//get masks offset
				int offeset = size / 2;

				//save all neigbour pixels into array
				for (int yOffset = -1 * offeset; yOffset <= offeset; yOffset++)
				{
					for (int xOffset = -1 * offeset; xOffset <= offeset; xOffset++)
					{
						int index = (xOffset + offeset) * size + (yOffset + offeset);
						array[index] = inputImage.getPointValue(x + xOffset, y + yOffset).getGrey();
					}
				}

				//get original pixel
				int ZXY = array[size*size/2];

				//sort every from low to highest
				qsort(array, size * size, sizeof(int), cmpfunc);

				//get new grey value
				resultgrey = LevelA(ZXY, SMax, size, array);
				if (resultgrey == -1) {
					//inncrease size if frame has to increase
					size = size + 2;
				}
				//delete old frame array
				delete[] array;

				//if framesize has to be increased run again
			} while (resultgrey == -1);

			//for the next pixel start frame size again with 3
			size = 3;

			//set point in new Image with new Grey
			CColor greyValue = CColor(resultgrey);
			resultImage.setPointValue(x, y, greyValue);
			
		}
	}

	resultImage.showImage();
	
	return resultImage;
}