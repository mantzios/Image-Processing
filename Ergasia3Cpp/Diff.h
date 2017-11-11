#ifndef _DIFF
#define _DIFF

#include "Image.h"
#include "Filter.h"

namespace imaging {
	namespace filters {
		class Diff : public Filter {
		protected:
			float * red;
			float * green;
			float * blue;
			Vec3<float> * tmp;
		public:
			Diff() {};
			~Diff() {};

			Image& operator << (Image& source);


		};
	}

}
#endif