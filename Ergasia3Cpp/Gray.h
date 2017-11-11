#ifndef _GRAY
#define _GRAY

#include "Image.h"
#include "Filter.h"

namespace imaging {
	namespace filters {
		class Gray : public Filter {
		public:
			Gray() {};
			~Gray() {};

			Image& operator << (Image& source);


		};
	}

}
#endif