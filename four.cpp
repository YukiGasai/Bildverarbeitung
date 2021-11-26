#include "four.h"

using namespace bvme;


CImage TiefpassIdeal(CImage& inputImage, int radius) {

	inputImage.showImage("Eingabe");

	CImage fourier = inputImage.FourierTransformation(false);

	fourier.showImage("Fourier Bild");
	

	Complex value;

	int width = inputImage.getWidth();
	int height = inputImage.getHeight();


	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (pow(y - height / 2, 2) + pow(x - width / 2, 2) > radius * radius){
				value.real(0);
				value.imag(0);
				fourier.setComplexPointValue(y, x, value);
			}
		}
	}
	fourier= fourier.FourierTransformation(true);

	fourier.showImage("Idealer Tiefpass Bild");
	return fourier;
}



CImage TiefpassGauss(CImage& inputImage, int radius) {

	inputImage.showImage("Eingabe");

	CImage fourier = inputImage.FourierTransformation(false);

	fourier.showImage("Fourier Bild");


	Complex value;

	int width = inputImage.getWidth();
	int height = inputImage.getHeight();


	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			float D = pow(y - height / 2, 2) + pow(x - width / 2, 2);

			float H = exp(-1 * D / (2 * radius * radius));

			value = fourier.getComplexPointValue(y, x);

			double real = value.real();
			double imag = value.imag();

			value.real(real * H);
			value.imag(imag * H);

			fourier.setComplexPointValue(y, x, value);

		}
	}

	fourier = fourier.FourierTransformation(true);
	fourier.showImage("Gauß Tiefpass Bild");

	return fourier;
}



CImage HochpassIdeal(CImage& inputImage, int radius) {

	inputImage.showImage("Eingabe");

	CImage fourier = inputImage.FourierTransformation(false);

	fourier.showImage("Fourier Bild");


	Complex value;

	int width = inputImage.getWidth();
	int height = inputImage.getHeight();


	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (pow(y - height / 2, 2) + pow(x - width / 2, 2) < radius * radius) {
				value.real(0);
				value.imag(0);
				fourier.setComplexPointValue(y, x, value);
			}
		}
	}
	fourier = fourier.FourierTransformation(true);

	fourier.showImage("Idealer Hochpass Bild");
	return fourier;
}



CImage HochpassGauss(CImage& inputImage, int radius) {

	inputImage.showImage("Eingabe");

	CImage fourier = inputImage.FourierTransformation(false);

	fourier.showImage("Fourier Bild");


	Complex value;

	int width = inputImage.getWidth();
	int height = inputImage.getHeight();


	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			float D = pow(y - height / 2, 2) + pow(x - width / 2, 2);

			float H = 1/*Wenn 2 gesetzt ist wird das alte bild auf das Kanten bild addiert und das Ergebnis ist das geschärfte OrginalBild*/ - exp(-1 * D / (2 * radius * radius));

			value = fourier.getComplexPointValue(y, x);

			double real = value.real();
			double imag = value.imag();

			value.real(real * H);
			value.imag(imag * H);

			fourier.setComplexPointValue(y, x, value);

		}
	}

	fourier = fourier.FourierTransformation(true);
	fourier.showImage("Gauß Hochpass Bild");

	return fourier;
}

