#ifndef _COLOR
#define _COLOR

#include "Image.h"
#include "Filter.h"

namespace imaging {
	namespace filters {
		class Color : public Filter {
		protected:
			float red;
			float green;
			float blue;
			Vec3<float> * tmp;
		public:
			void setColors(float r, float g, float b) { red = r; green = g; blue = b;}
			Color() {};
			~Color() {};
			Image& operator << (Image& source);
		};
	}

}
#endif
