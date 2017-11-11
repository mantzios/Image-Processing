#include <fstream>
#include <string>
#include <iostream>
#include "Image.h"
#include "ppm_format.h"

using namespace imaging;
using namespace std;





Image * imaging::ReadPPM(const char * filename) {
	unsigned int width;
	unsigned int height;
	string isP6;
	unsigned int pixel_max = 0;
	ifstream in;
	in.open(filename, ios::binary);
	if (!in) {
		cerr << "Error opening file!!" << endl;
		system("pause");
		exit(1);
	}
	in >> isP6 >> width >> height >> pixel_max;
	if (isP6 != "P6") {
		cerr << "Error!! This is not a P6 File..!!" << endl;
		system("PAUSE");
		exit(1);
	}

	if (width <= 0) {
		cerr << "Error!! Not a proper Width for This Image!!" << endl;
		system("PAUSE");
		exit(1);
	}

	if (height <= 0) {
		cerr << "Error!! Not a proper Heigth for This Image!!" << endl;
		system("PAUSE");
		exit(1);
	}

	if (pixel_max > 255 || pixel_max == 0) {
		cerr << "Error!! Not a proper Value for a Pixel!!" << endl;
		system("PAUSE");
		exit(1);
	}


	char* h = new char[3 * width*height];
	in.get();
	in.read((char*)h, 3 * width*height);

	unsigned char r, g, b;
	Vec3<float>* imag = new Vec3<float>[width*height];
	for (int i = 0; i < 3*width*height; i +=3) {
		r = (unsigned char)h[i];
		g = (unsigned char)h[i + 1];
		b = (unsigned char)h[i + 2];
		*imag = Vec3<float>((float)r/255.0, (float)g/255.0, (float)b/255.0);
		imag++;
	}
	imag -= width*height;
	delete[] h;

	in.close();

	Image* image = new Image(width, height, imag);
	delete[] imag;
	return image;
}

bool imaging::WritePPM(Image & image, const char * filename) {
	ofstream out;
	out.open(filename, ofstream::out | ofstream::binary);
	if (!out) {
		cerr << "Error Opening!!" << endl;
		system("pause");
		exit(1);
	}
	out << "P6" << endl << image.getWidth() << endl << image.getHeight() << endl << 255 << " ";

	char* img = new char[3 * image.getWidth()*image.getHeight()];
	int h = 0;
	for (int i = 0; i < image.getHeight()*image.getWidth(); i++) {
		img[h] = (char)(image.getRawDataPtr()[i].r * 255);
		img[h + 1] = (char)(image.getRawDataPtr()[i].g * 255);
		img[h + 2] = (char)(image.getRawDataPtr()[i].b * 255);
		h += 3;
	}
	out.write(img, 3 * image.getWidth()*image.getHeight());
	
	delete[] img;
	out.close();
	return true;
}
