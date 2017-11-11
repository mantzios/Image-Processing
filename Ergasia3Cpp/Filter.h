//------------------------------------------------------------
//
// C++ course assignment code 
//
// G. Papaioannou, 2014
//
//
//-------------------------------------------------------------

#ifndef _FILTER
#define _FILTER

#include "Image.h"

namespace imaging
{
	namespace filters {
		class Filter
		{
		public:

			Filter() {};
			virtual ~Filter() {};
			virtual Image& operator << (Image& source) = 0;
		};
	}
}
#endif