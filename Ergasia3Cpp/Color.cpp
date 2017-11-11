#include "Color.h"
using namespace imaging;
using namespace filters;

Image& Color::operator<<(Image& source) {
	for (int i = 0; i < source.getWidth()*source.getHeight(); i++) {
		source.getRawDataPtr()[i].r *= red;
		source.getRawDataPtr()[i].g *= green;
		source.getRawDataPtr()[i].b *= blue;
	}
		return source;
}