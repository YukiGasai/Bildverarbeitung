#pragma once
#include "CImage.h"

bvme::CImage greyScale(bvme::CImage* inputImage, int t = -1);

bvme::CImage findMinMaxPoints(bvme::CImage* inputImage);