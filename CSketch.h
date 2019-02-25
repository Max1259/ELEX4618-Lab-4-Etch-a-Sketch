#pragma once

#include "stdafx.h"
#include "CBase4618.h"

#include <string>

using namespace std;

/**
*
* @brief Inherits draw and update functions from CBase4618 class, and sets the image size and comport to read from and write to
*
* This class inherits draw and update functions from CBase4618 to create a basic Etch-a-sketch. The constructor sets the image size and comport to be read from
*
* @author Max Horie
*
*/
class CSketch: public CBase4618 {

public:

	/**
	*
	* @brief Constructor, sets size of image and com port
	* 
	* @param size Size of the image to draw on
	* @param _com The com port to initialize
	*
	* @return nothing to return
	*/
	CSketch(cv::Size size, string _com);
	void draw();
	void update();

};
