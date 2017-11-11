//------------------------------------------------------------
//
// C++ course assignment code 
//
// G. Papaioannou, 2015
//
//
//-------------------------------------------------------------

#ifndef _PPM
#define _PPM



namespace imaging
{

	Image * ReadPPM(const char * filename);
	bool WritePPM(Image & image, const char * filename);

} //namespace imaging

#endif