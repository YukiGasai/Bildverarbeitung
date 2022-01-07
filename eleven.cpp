#include "eleven.h"
#include <stack>
#include <tuple>
#include <iostream>

using namespace bvme;



void FloodFill(CImage* image, int x, int y, int* label, std::stack<std::tuple<int, int>>* toProcess) {

	int width = image->getWidth();
	int height = image->getHeight();
	toProcess->pop();

	int value = image->getPointValue(x,y).getGrey();

	if (value == 255 ) {
		if (value == 255) {
			CColor c(100);
			image->setPointValue(x, y, c);
		}
		else {
			CColor c(1);
			image->setPointValue(x, y, c);
		}

		if (x + 1 < width) {
			toProcess->push(std::tuple<int, int>{ x + 1, y });
		}
		if (x - 1 >= 0) {
			toProcess->push(std::tuple<int, int>{ x - 1, y });
		}
		if (y + 1 < height) {
			toProcess->push(std::tuple<int, int>{ x , y + 1 });
		}
		if (y - 1 >= 0) {
			toProcess->push(std::tuple<int, int>{ x , y - 1 });
		}

		//8 Nachbarschaft
		/*
		if (y - 1 >= 0 && x - 1 >= 0) {
			toProcess->push(std::tuple<int, int>{ x - 1 , y - 1 });
		}

		if (y - 1 >= 0 && x + 1 < width) {
			toProcess->push(std::tuple<int, int>{ x + 1, y - 1 });
		}

		if (y + 1 < height && x - 1 >= 0) {
			toProcess->push(std::tuple<int, int>{ x - 1, y + 1 });
		}

		if (y + 1 < height && x + 1 < width) {
			toProcess->push(std::tuple<int, int>{ x + 1, y + 1 });
		}
		*/
	}
	

	
}

std::tuple<int, int> FindStart(CImage* image) {

	int width = image->getWidth();
	int height = image->getHeight();
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int value = image->getPointValue(x, y).getGrey();
			if (value == 255) {
				return std::tuple<int, int> {x, y};
			}
		}
	}
	return std::tuple<int, int> {0, 0};
}

void FloodFillMain(CImage* inputImage) {

	std::stack<std::tuple<int,int>> toProcess;

	toProcess.empty();


	

	int label = 110;
	std::tuple<int, int> start = FindStart(inputImage);
	toProcess.push(start);
	



	while (toProcess.size() > 0) {

		std::tuple<int, int> pos = toProcess.top();
		
		FloodFill(inputImage, std::get<0>(pos), std::get<1>(pos), &label, &toProcess);
	}
}