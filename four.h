#pragma once
#include <CImage.h>


//Hochpassfilter
//Hohe frequnzen = KANTEN und Rauschen
//Deshalb weichzeichnung -> ungewollt


bvme::CImage TiefpassIdeal(bvme::CImage& image, int radius = 50);
bvme::CImage TiefpassGauss(bvme::CImage& image, int radius = 50);
bvme::CImage HochpassIdeal(bvme::CImage& image, int radius = 50);
bvme::CImage HochpassGauss(bvme::CImage& image, int radius = 50);