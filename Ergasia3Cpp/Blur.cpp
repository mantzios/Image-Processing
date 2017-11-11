#include <algorithm>
#include "Blur.h"

using namespace imaging;
using namespace filters;

Image& Blur::operator<< (Image& source) {
	temp = new Vec3<float>[source.getHeight()*source.getWidth()];
	/*int i = 0, j = 0;
	for (int i = 0; i < source.getHeight(); i++) {
		for (int j = 0; j < source.getWidth(); j++) {
			if (i == 0) {									//h prwth grammh
				if (j == 0) {										//to pixel 0,0
					tmp = source.getPixel(0, 0) + source.getPixel(1, 0) + source.getPixel(0, 1) + source.getPixel(1, 1);
					tmp /= 4;
					temp[i * source.getWidth() + j] = tmp;
				}
				else if (j > 0 && j < source.getWidth() - 1) {		//to pixel x,0
					tmp = source.getPixel(j - 1, i) + source.getPixel(j, i) + source.getPixel(j + 1, i) + source.getPixel(j - 1, i + 1) + source.getPixel(j, i + 1) + source.getPixel(j + 1, i + 1);
					tmp /= 6;
					temp[i * source.getWidth() + j] = tmp;
				}
				else {												// to pixel width,0
					tmp = source.getPixel(j, i) + source.getPixel(j - 1, i) + source.getPixel(j, i + 1) + source.getPixel(j - 1, i + 1);
					tmp /= 4;
					temp[i * source.getWidth() + j] = tmp;
				}
			}
			else if (i == source.getHeight() - 1) {			//h teleutaia grammh ths eikonas
				if (j == 0) {										// to pixel 0, height
					tmp = source.getPixel(j, i) + source.getPixel(j + 1, i) + source.getPixel(j, i - 1) + source.getPixel(j + 1, i - 1);
					tmp /= 4;
					temp[i * source.getWidth() + j] = tmp;
				}
				else if (j > 0 && j < source.getWidth() - 1) {		//to pixel x,height
					tmp = source.getPixel(j - 1, i) + source.getPixel(j, i) + source.getPixel(j + 1, i) + source.getPixel(j - 1, i - 1) + source.getPixel(j, i - 1) + source.getPixel(j + 1, i - 1);
					tmp /= 6;
					temp[i * source.getWidth() + j] = tmp;
				}
				else {												// to pixel width,height
					tmp = source.getPixel(j, i) + source.getPixel(j - 1, i) + source.getPixel(j, i - 1) + source.getPixel(j - 1, i - 1);
					tmp /= 4;
					temp[i * source.getWidth() + j] = tmp;
				}
			}
			else {											//to height den einai oute 0 oute sthn teleutaia seira ths eikonas
				if (j == 0) {										//an einai to prwto pixel 0,height
					tmp = source.getPixel(j, i - 1) + source.getPixel(j + 1, i - 1) + source.getPixel(j, i) + source.getPixel(j + 1, i) + source.getPixel(j, i + 1) + source.getPixel(j + 1, i + 1);
					tmp /= 6;
					temp[i * source.getWidth() + j] = tmp;
				}
				else if (j == source.getWidth() - 1) {				//an einai to teleutaio terma de3ia
					tmp = source.getPixel(j, i - 1) + source.getPixel(j - 1, i - 1) + source.getPixel(j, i) + source.getPixel(j - 1, i) + source.getPixel(j, i + 1) + source.getPixel(j - 1, i + 1);
					tmp /= 6;
					temp[i * source.getWidth() + j] = tmp;
				}
				else {												//opoiodhpote allo pixel sthn eikona
					tmp = source.getPixel(j - 1, i - 1) + source.getPixel(j, i - 1) + source.getPixel(j + 1, i - 1) + source.getPixel(j - 1, i) + source.getPixel(j, i) + source.getPixel(j + 1, i) + source.getPixel(j - 1, i + 1) + source.getPixel(j, i + 1) + source.getPixel(j + 1, i + 1);
					tmp /= 9;
					temp[i * source.getWidth() + j] = tmp;
				}
			}
		}//for tou platous
	}//for tou upsous
	
	memcpy(source.getRawDataPtr(), temp, source.getHeight()*source.getWidth()*sizeof(Vec3<float>));
	delete[] temp;
	return source;
	*/
	int sum = 0;
	Vec3<float>  tmp;
	for (int j = 0; j < source.getHeight(); j++) {
		for (int i = 0; i < source.getWidth(); i++) {

			for (int k = -1; k <= 1; k++) {
				for (int m = -1; m <= 1; m++) {
					if ((i + k) >= 0 && (i + k) <= source.getWidth() - 1) {
						if ((j + m) >= 0 && (j + m) <= source.getHeight() - 1) {
							tmp += source.getPixel(i+k, j+m);
							sum++;


						}
					}
				}
			}
			tmp /= sum;
			temp[j*source.getWidth() + i] = tmp;
			sum = 0;
			tmp = 0;
		}
	}
	memcpy(source.getRawDataPtr(), temp, source.getHeight()*source.getWidth()*sizeof(Vec3<float>));
	delete[] temp;
	return source;
	
}