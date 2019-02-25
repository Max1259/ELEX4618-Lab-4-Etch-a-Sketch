#include "stdafx.h"
#include "CBase4618.h"

#include <iostream>

#define DIGITAL 0

using namespace std;

void CBase4618::run() {

	do {
		update();
		draw();
		cv::imshow("Retch-a-Sketch", _canvas);

	} while (cv::waitKey(10) != 'q');

	ctrl.set_data(DIGITAL, 37, 0);
	ctrl.set_data(DIGITAL, 38, 0);
	ctrl.set_data(DIGITAL, 39, 0);
}

void draw() {}
void update() {}