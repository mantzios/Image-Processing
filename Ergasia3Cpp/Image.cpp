#include "Image.h"
#include "Serializable.h"
#include "ppm_format.h"
#include <string>
#include <iostream>
using namespace imaging;
using namespace math;

Vec3<float> Image::getPixel(unsigned int x, unsigned int y) const {
	if (x > width || y > height){
		return Vec3<float>();
	}
	return this->operator()(x,y);
}

Vec3<float> Image::getPixel(unsigned int x, unsigned int y){
	if (x > width || y > height) {
		return Vec3<float>();
	}
	return this->operator()(x, y);
}


Image::Image() :Array<Vec3<float>>(0, 0) {}

void Image::setData(const Vec3<float>* & data_ptr) {
	buffer = new Vec3<float>[width * height];
	memcpy(buffer, data_ptr, width * height * sizeof(Vec3<float>));
}

Vec3<float>* Image::getRawDataPtr(){
	return (Vec3<float>*)Array<Vec3<float>>::getRawDataPtr();
}

Image& Image::operator = (const Image& right){
	if (&right == this) {
		return *this;
	}
	
	if (buffer != nullptr){
		delete[] buffer;
	}
	width = right.width;
	height = right.height;
	buffer = new Vec3<float>[width*height];
	memcpy(buffer, right.buffer, width*height*sizeof(Vec3<float>));
	return *this;
}

void Image::setPixel(unsigned int x, unsigned int y, Vec3<float>& value) {
	if (x > width || y > height){
		return;
	}
	this->operator()(x, y) = value;
}

Image::Image(unsigned int width, unsigned int height) : Array<Vec3<float>>(width, height){}

Image::Image(unsigned int width, unsigned int height, const Vec3<float> * data_ptr):Array<Vec3<float>>(width, height)
{
	setData(data_ptr);
}


Image::Image(const Image & right):Array<Vec3<float>>(right){}


Image::~Image(){}


void Image::resize(unsigned int new_width, unsigned int new_height) {
	Array<Vec3<float>>::resize(new_width, new_height);
}


bool Image::operator<<(std::string filename) {
	Image* temp = ReadPPM(filename.c_str());
	if (temp != nullptr){
		*this = *temp;
		return true;
	}
	else{
		return false;
	}
}

bool Image::operator>>(std::string filename) {
	
	if (WritePPM(*this, filename.c_str())) {
		return true;
	}
	else {
		std::cout << "Error during writting" << std::endl;
		return false;
	}
}