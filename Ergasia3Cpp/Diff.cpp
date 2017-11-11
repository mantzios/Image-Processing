#include "Diff.h"
#include <algorithm>
using namespace imaging;
using namespace filters;

Image& Diff::operator<<(Image& source) {
	int sum = 0;
	tmp = new Vec3<float>[source.getHeight()*source.getWidth()];
	red = new float[9];
	green = new float[9];
	blue = new float[9];
	for (int i = 0; i < 9; i++) {
		red[i] = 2.0;
		green[i] = 2.0;
		blue[i] = 2.0;
	}

	float p, o, v;

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

			p = red[sum - 1] - red[0];
			o = green[sum - 1] - green[0];
			v = blue[sum - 1] - blue[0];
			tmp[j*source.getWidth() + i] = Vec3<float>(p, o, v);
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