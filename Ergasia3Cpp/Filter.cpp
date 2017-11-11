#include <iostream>
#include <string>
#include <fstream>
#include "Image.h"
#include "Blur.h"
#include "Color.h"
#include "Diff.h"
#include "Gray.h"
#include "Median.h"
using namespace std;
using namespace imaging;
using namespace filters;
			
void printLuminosity(Image& source);
Image & noise(Image & source);

int main(int argc, char* argv[]) {
	Image img;
	Blur blr;
	Median mdn;
	Gray gry;
	Diff dff;
	Color clr;
	if (img << argv[argc - 1]) {
		printLuminosity(img);
		//img=noise(img);
		//img >> "noise.ppm";
		if (strcmp(argv[1], "filter") == 0) {
			for (int i = 2; i < argc - 1; i++) {
				if (strcmp(argv[i], "-f") == 0) {}

				if (strcmp(argv[i], "gray") == 0) {
					gry << img;
					cout << "Filter Gray Applied" << endl;
				}

				if (strcmp(argv[i], "diff") == 0) {
					dff << img;
					cout << "Filter Diff Applied" << endl;
				}

				if (strcmp(argv[i], "median") == 0) {
					mdn << img;
					cout << "Filter Median Applied" << endl;
				}

				if (strcmp(argv[i], "blur") == 0) {
					blr << img;
					cout << "Filter Blur Applied" << endl;
				}

				if (strcmp(argv[i], "color") == 0) {
					if (strcmp(argv[i + 1], "-f") == 0 || i + 1 == argc - 1) {}
					else {
						clr.setColors(stof(argv[i + 1]), stof(argv[i + 2]), stof(argv[i + 3]));
						clr << img;
						cout << "Filter Color with Red = " << argv[i + 1] << " Green = " << argv[i + 2] << " Blue = " << argv[i + 3] << " Applied" << endl;
					}
				}
			}
		}
		string f = argv[argc - 1];
		f = f.substr(0, f.find("."));
		img >> f.append(".filtered.ppm");
		cout << "Image is written to " << f << endl;

	}
	
	
	system("PAUSE");
	return 0;
}

void printLuminosity(Image& source) {
	Vec3<float> luminosity;
	for (int i = 0; i < source.getHeight()*source.getWidth(); i++) {
		luminosity += source.getRawDataPtr()[i];
	}
	luminosity.r /= source.getHeight()*source.getWidth();
	luminosity.g /= source.getHeight()*source.getWidth();					
	luminosity.b /= source.getHeight()*source.getWidth();

	cout << "Image dimensions are: " << source.getWidth() << " x " << source.getHeight() << endl;
	cout << "The average color of the Image is(" << luminosity.r << ", " << luminosity.g << ", " << luminosity.b << ")" << endl;
}

Image & noise(Image & source){
	int x;
	int y;
	Vec3<float> s = Vec3<float>(0, 0, 0);
	for (int i = 0; i < 20000; i++){
		x = rand()%(source.getWidth());
		y = rand()%(source.getHeight());
		source.setPixel(x, y, s);
	}
	return source;
}