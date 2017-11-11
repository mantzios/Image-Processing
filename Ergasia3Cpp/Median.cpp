#include "Median.h"
#include <algorithm>
using namespace imaging;
using namespace filters;

Image& Median::operator<<(Image& source) {
	int sum = 0;
	tmp = new Vec3<float>[source.getHeight()*source.getWidth()];
	red = new float[9];
	green = new float[9];
	blue = new float[9];
	for (int j = 0; j < source.getHeight(); j++) {
		for (int i = 0; i < source.getWidth(); i++) {
			for (int k = -1; k <= 1; k++) {
				for (int m = -1; m <= 1; m++) {
					if ((i + k) >= 0 && (i + k) <= source.getWidth() - 1) {
						if ((j + m) >= 0 && (j + m) <= source.getHeight() - 1) {

							red[sum] = source.getPixel(i + k, j + m).r;
							green[sum] = source.getPixel(i + k, j + m).g;
							blue[sum] = source.getPixel(i + k, j + m).b;
							sum++;


						}
					}
				}
			}

			std::sort(red, red + sum);
			std::sort(green, green + sum);
			std::sort(blue, blue + sum);

			tmp[j*source.getWidth() + i] = Vec3<float>(red[(sum - 1) / 2], green[(sum - 1) / 2], blue[(sum - 1) / 2]);

			sum = 0;
		}
	}
	memcpy(source.getRawDataPtr(), tmp, source.getHeight()*source.getWidth()*sizeof(Vec3<float>));
	delete[] tmp;
	delete[] red;
	delete[] green;
	delete[] blue;
	return source;
}
