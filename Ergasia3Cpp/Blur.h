#ifndef _BLUR
#define _BLUR

#include "Image.h"
#include "Filter.h"

namespace imaging{
	namespace filters {
		class Blur : public Filter{
		protected:
			Vec3<float> tmp;
			Vec3<float>* temp;
		public:
			Blur() {};
			~Blur() {};
			Image& operator << (Image& source);
		};
	}
		
}
#endif