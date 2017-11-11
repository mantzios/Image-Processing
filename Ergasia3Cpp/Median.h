#ifndef _MEDIAN
#define _MEDIAN

#include "Image.h"
#include "Filter.h"

namespace imaging {
	namespace filters {
		class Median : public Filter {
		protected:
			float * red;
			float * green;
			float * blue;
			Vec3<float> * tmp;
		public:
			Median() {};
			~Median() {};

			Image& operator << (Image& source);


		};
	}

}
#endif
