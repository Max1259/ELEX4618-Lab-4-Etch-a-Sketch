#include "stdafx.h"

#include <string>
#include <iostream>
#include <thread>

#include "Client.h"
#include "Server.h"
#include "Serial.h" // Must include Windows.h after Winsock2.h, so Serial must include after Client/Server
#include "CControl.h"
#include "CBase4618.h"
#include "CSketch.h"

// OpenCV Include
#include "opencv.hpp"

// OpenCV Library
#pragma comment(lib,".\\opencv\\lib\\opencv_world310d.lib")

using namespace std;

int main() {

	string comstring = "COM5";
	int width, height;

	cout << "Enter canvas height: ";
	cin >> height;
	cout << "Enter canvas width: ";
	cin >> width;

	cv::Size size(width, height);
	CSketch sketch(size, comstring);
	sketch.run();
	return 0;
}