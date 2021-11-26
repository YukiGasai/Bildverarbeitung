#include <iostream>
#include "CImage.h"
#include "CColor.h"
#include "one.h"
#include "two.h"
#include "three.h"
#include "four.h"
#include "five.h"
#include "seven.h"
#include "eight.h"
#define SIZE 3

using namespace bvme;




int main()
{

	// relativ ausgehend von main.cpp, absolute Pfadangaben sind auch möglich
	
	CImage imageRose("Images/rose.bmp");



	//CImage imageText("Images/mond.bmp");

	/*

	CImage grauBild = greyScale(&imageRose);

	grauBild.showImage();

	CImage grauBild2 = greyScale(&imageText,80);

	grauBild2.showImage();


	CImage aufgabe2Bild = findMinMaxPoints(&imageRose);

	aufgabe2Bild.showImage();

	*/



	/*
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

	//imageText.showImage();


	//Wichzeichnen(imageText, mask, size).save("Images/new.bmp");
	*/


	/*
	CImage fourierText("Images/rose_fourier.bmp");
	fourierText = fourierText.getGreyscaleImage();
	HochpassGauss(fourierText);
	*/

	
	/*
	CImage saltPepperSchmetterling("Images/schmetterling_saltpepper.bmp");
	saltPepperSchmetterling = saltPepperSchmetterling.getGreyscaleImage();
	CImage result = MedianFilter(saltPepperSchmetterling,11);
	*/

	
	//CImage imageFlauRose("Images/rose_flau.bmp");
	CImage imageText("Images/mond.bmp");

	//imageFlauRose = imageFlauRose.getGreyscaleImage();

	//HistogrammLinearisierungRGB(imageRose).showImage();

	/*
	* 	CImage imageFlauRose("Images/rose_flau.bmp");
	//getMiddleGrayLevel(imageText);
	Histogrammlinearisierung(&imageFlauRose).showImage();
	*/











	Sobelfilter(imageRose);

	




	system("pause");
	return 0;
}