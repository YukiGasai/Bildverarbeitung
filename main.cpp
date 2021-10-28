#include <iostream>
#include "CImage.h"
#include "CColor.h"
#include "one.h"
#include "two.h"
#define SIZE 3

using namespace bvme;



CImage Wichzeichnen(CImage& inputImage, int** mask,int size) {



	//Get Basic Data from Array
	int ImageHeight = inputImage.getHeight();
	int ImageWidth = inputImage.getWidth();

	CImage resultImage = CImage(ImageHeight-2, ImageWidth-2, 1);

	int divisor = 0;

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			divisor += mask[x][y];
		}
	}


	int offset = (int)size / 2;


	for (int y = offset; y < ImageHeight- offset; y++)
	{
		for (int x = offset; x < ImageWidth- offset; x++)
		{
			int cluster = 0;

			for (int ymask = 0; ymask < size; ymask++)
			{
				for (int xmask = 0; xmask < size; xmask++)
				{
					
					int inputGrey = (inputImage.getPointValue(y- offset +ymask, x- offset +xmask).getBlue() + inputImage.getPointValue(y - offset + ymask, x - offset + xmask).getGreen() + inputImage.getPointValue(y - offset + ymask, x - offset + xmask).getRed()) / 3;
					
					//std::cout << "OLD GREY " << inputGrey << std::endl;
					cluster += mask[xmask][ymask] * inputGrey;
				}
			}
			int newGrayValue = cluster;
			if (divisor > 0) {
				newGrayValue = cluster / divisor;
			}

		
			//std::cout << newGrayValue <<  std::endl;
			CColor newGrey = CColor(newGrayValue);
			
			resultImage.setPointValue(y, x, newGrey);

		}
	}



	resultImage.showImage();

	return resultImage;

}



int main()
{

	// relativ ausgehend von main.cpp, absolute Pfadangaben sind auch möglich
	
	//CImage imageRose("Images/rose.bmp");



	CImage imageText("Images/mond.bmp");

	/*

	CImage grauBild = greyScale(&imageRose);

	grauBild.showImage();

	CImage grauBild2 = greyScale(&imageText,80);

	grauBild2.showImage();


	CImage aufgabe2Bild = findMinMaxPoints(&imageRose);

	aufgabe2Bild.showImage();

	*/




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

	mask[0][0] = -1;
	mask[1][0] = -1;
	mask[2][0] = -1;
	mask[0][1] = -1;
	mask[1][1] = 8;
	mask[2][1] = -1;
	mask[0][2] = -1;
	mask[1][2] = -1;
	mask[2][2] = -1;

	imageText.showImage();


	Wichzeichnen(imageText, mask, size).save("Images/new.bmp");




	/*
	CImage imageFlauRose("Images/rose_flau.bmp");

	//getMiddleGrayLevel(imageText);
	Histogrammlinearisierung(&imageFlauRose).showImage();
	*/
	system("pause");
	return 0;
}