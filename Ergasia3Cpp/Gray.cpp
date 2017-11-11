#include "Gray.h"
using namespace imaging;
using namespace filters;

Image& Gray::operator<<(Image& source) {
	for (int i = 0; i < source.getHeight()*source.getWidth(); i++) {
		float m = (source.getRawDataPtr()[i].r + source.getRawDataPtr()[i].g + source.getRawDataPtr()[i].b) / 3;
		source.getRawDataPtr()[i] = Vec3<float>(m, m, m);
	}
	return source;
}