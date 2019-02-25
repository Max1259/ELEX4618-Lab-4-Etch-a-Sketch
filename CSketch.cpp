#include "stdafx.h"
#include "CBase4618.h"
#include "CSketch.h"

#define RED		cv::Scalar(0,0,255)
#define YELLOW  cv::Scalar(0,255,255)
#define GREEN   cv::Scalar(0,255,0)
#define BLUE    cv::Scalar(255,0,0)
#define PINK    cv::Scalar(255,0,255)

#define PUSH1 32
#define PUSH2 33

#define DIGITAL 0

cv::Scalar colour_array[] = { RED, YELLOW, GREEN, BLUE, PINK };

int _reset = 0;
int prev_x = 0;
int prev_y = 0;
int i = 0;
int _colour = 0;

CSketch::CSketch(cv::Size size, string _com) {

	ctrl.init_com(_com);

	_canvas = cv::Mat::zeros(size, CV_8UC3);

	ctrl.set_data(DIGITAL, 39, 1);
}

void CSketch::draw() {

	if (_reset == 1) {

		_canvas = cv::Mat::zeros(_canvas.size(), CV_8UC3);
		_reset = 0;
	}

	if (i == 0) {

		cv::line(_canvas, cv::Point(x, y), cv::Point(x, y), colour_array[_colour], 1, 4);
		i++;
	}
	else {

		cv::line(_canvas, cv::Point(x, y), cv::Point(prev_x, prev_y), colour_array[_colour], 1, 4);
	}

	prev_x = x;
	prev_y = y;
}

void CSketch::update() {

	if (ctrl.get_button(PUSH2) == 0) {

		_reset = 1;
	}

	if (ctrl.get_button(PUSH1) == 0) {

		ctrl.set_data(DIGITAL, 37, 0);
		ctrl.set_data(DIGITAL, 38, 0);
		ctrl.set_data(DIGITAL, 39, 0);

		if (_colour < 4) { _colour++; }

		else { _colour = 0; }

		switch (_colour) {
		case 0:
			ctrl.set_data(DIGITAL, 39, 1);
			break;
		case 1:
			ctrl.set_data(DIGITAL, 39, 1);
			ctrl.set_data(DIGITAL, 38, 1);
			break;
		case 2:
			ctrl.set_data(DIGITAL, 38, 1);
			break;
		case 3:
			ctrl.set_data(DIGITAL, 37, 1);
			break;
		case 4:
			ctrl.set_data(DIGITAL, 39, 1);
			ctrl.set_data(DIGITAL, 37, 1);
			break;
		}
	}

	tie(x, y) = ctrl.get_analog();

	x = (_canvas.size().width * 1.4) * x - (_canvas.size().width / 5);

	if (x > _canvas.size().width) { x = _canvas.size().width - 1; }
	if (x < 0) { x = 0; }

	y = (_canvas.size().height * 1.4) * y - (_canvas.size().height / 5);

	if (y > _canvas.size().height) { y = _canvas.size().height - 1; }
	if (y < 0) { y = 0; }
}

