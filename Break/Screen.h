#ifndef _SCREEN_H             // Prevent multiple definitions if this 
#define _SCREEN_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "textureManager.h"
#include "constants.h"
#include "player.h"

class Screen
{
	protected:
		Graphics *graphics;  //pointer to graphics 
		TextureManager *textureManager;   //pointer to texture manager;
		//screenData

	public:
		//Constructor
		Screen();

		//Destructor
		virtual ~Screen();

		//////////////////////////////////////
		//			Get functions			//
		//////////////////////////////////////

		
};
#endif
