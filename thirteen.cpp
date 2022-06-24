#include "thirteen.h"
#include <math.h>
using namespace bvme;


bvme::CImage Hough(bvme::CImage& inputImage) {

	int x = 0;
	int y = 0;

	//(m, n) <- size(I)
	int height = inputImage.getHeight();
	int width = inputImage.getWidth();
	//o=180
	int o = 180;

	//p=root(m2 + n2)
	int p = sqrt(height* height + width * width);

	//hough: Array of size (o, p), initialized with 0
	CImage hough(o, p, true);



	//or all (u, v) element of (m, n) do
	for (int u = 0; u < height; u++)
	{
		for (int v = 0; v < width; v++)
		{
			//if I(u, v) > 0 then
			if (inputImage.getPointValue(u,v).getGrey() > 0) {
				x = u - height / 2;
				y = v - width / 2;

				for (int i = 0; i <= 180; i++) {
					double teta = 3.141592 / o * i;
					double r = x*cos(teta) + y*sin(teta);
					int j = p   / 2 + round(r);
					int oldGreyValue = hough.getPointValue(i, j).getGrey();

					oldGreyValue++;

					CColor c(oldGreyValue);

					hough.setPointValue(i, j, c);
				}
			}

		}
	}
	return hough;

}


