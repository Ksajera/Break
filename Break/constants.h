// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 constants.h v1.0

#ifndef _CONSTANTS_H            // Prevent multiple definitions if this 
#define _CONSTANTS_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include <windows.h>

//-----------------------------------------------
// Useful macros
//-----------------------------------------------
// Safely delete pointer referenced item
#define SAFE_DELETE(ptr)       { if (ptr) { delete (ptr); (ptr)=NULL; } }
// Safely release pointer referenced item
#define SAFE_RELEASE(ptr)      { if(ptr) { (ptr)->Release(); (ptr)=NULL; } }
// Safely delete pointer referenced array
#define SAFE_DELETE_ARRAY(ptr) { if(ptr) { delete [](ptr); (ptr)=NULL; } }
// Safely call onLostDevice
#define SAFE_ON_LOST_DEVICE(ptr)    { if(ptr) { ptr->onLostDevice(); } }
// Safely call onResetDevice
#define SAFE_ON_RESET_DEVICE(ptr)   { if(ptr) { ptr->onResetDevice(); } }


//-----------------------------------------------
//                  Constants
//-----------------------------------------------

// window
const char CLASS_NAME[] = "Break";
const char GAME_TITLE[] = "Break";
const bool FULLSCREEN = false;              // windowed or fullscreen
const UINT GAME_WIDTH =  640;               // width of game in pixels
const UINT GAME_HEIGHT = 480;               // height of game in pixels
//const UINT GAME_WIDTH = 1920;               // width of game in pixels
//const UINT GAME_HEIGHT = 1080;               // height of game in pixels
//const UINT SCREEN_WIDTH = 1920;               // width of game in pixels
//const UINT SCREEN_HEIGHT = 480;

// game
const double PI = 3.14159265;
const float FRAME_RATE = 200.0f;                // the target frame rate (frames/sec)
const float MIN_FRAME_RATE = 10.0f;             // the minimum frame rate
const float MIN_FRAME_TIME = 1.0f/FRAME_RATE;   // minimum desired time for 1 frame
const float MAX_FRAME_TIME = 1.0f/MIN_FRAME_RATE; // maximum time used in calculations
const float GRAVITY = 6.67428e-11f;             // gravitational constant
const float MASS_PLANET = 1.0e14f;
const float MASS_SHIP = 5.0f;
const float ENEMY_MOVE_SPEED = 100;
const float ENEMY_FOV_ANGLE = 45;
const float ENEMY_FOV_ANGLE_START = 45;
const float ENEMY_FOV_RANGE = 5;
const float BACKSTAB_RANGE = 3;
const int TILE_SIZE = 32;
const int SPEED_MODIFIER = 100;// 30;
const int MAX_SPEED_MODIFIER = 5; //tiles per second
const int MAX_MOVE_SPEED = TILE_SIZE * MAX_SPEED_MODIFIER;
const int SNEAK_SPEED_MODIFIER = 2;
const int MOVE_SPEED = TILE_SIZE * SPEED_MODIFIER;
const int WORLD_WIDTH = GAME_WIDTH / TILE_SIZE;
const int WORLD_HEIGHT = GAME_HEIGHT / TILE_SIZE;
const int MAX_PROJECTILES = 1000;
const int PROJECTILE_SPEED = 50 * TILE_SIZE;
const int FIRE_RATE = 5; //per second
const float FIRE_DELAY = 1.0f / FIRE_RATE;
const float TIME_TAKEN_TO_IGNORE = 3;
const float TIME_TAKEN_TO_ALERT = 3;
const float PATROL_DURATION = 5;
const float IDLE_DURATION = 2;

// graphic images
const char NEBULA_IMAGE[] =   "pictures\\orion.jpg";     // photo source NASA/courtesy of nasaimages.org 
const char TEXTURES_IMAGE[] = "pictures\\textures.png";  // game textures
const char PLAYERSHIP_IMAGE[] = "pictures\\spaceship.png";
const char HEART_IMAGE[] = "pictures\\heart.png";
const char DIRT_IMAGE[] = "pictures\\dirt.jpg";
const char GRASS_IMAGE[] = "pictures\\grass.jpg";
const char FLOOR_IMAGE[] = "pictures\\floor1.png";
const char PLAYER_IMAGE[] = "pictures\\player.png";
const char ENEMY_IMAGE[] = "pictures\\enemy.png";
const char BULLET_TEXTURE[] = "pictures\\bullet.png";
const char HANDGUN_TEXTURE[] = "pictures\\handgun.png";
const char RIFLE_TEXTURE[] = "pictures\\rifle.png";
const char ARROW_TEXTURE[] = "pictures\\arrow.png";
const char FOV_TEXTURE[] = "pictures\\fov.png";
const char TILE_MAP_IMAGE[] = "pictures\\pics\\PlatformTiles.png";


// key mappings
// In this game simple constants are used for key mappings. If variables were used
// it would be possible to save and restore key mappings from a data file.
const UCHAR ESC_KEY      = VK_ESCAPE;       // escape key
const UCHAR ALT_KEY      = VK_MENU;         // Alt key
const UCHAR ENTER_KEY    = VK_RETURN;       // Enter key

const UCHAR FORWARD_KEY = 'W';
const UCHAR ROTATE_LEFT_KEY = 'A';
const UCHAR BACKWARD_KEY = 'S';
const UCHAR ROTATE_RIGHT_KEY = 'D';

const int HEART_WIDTH = 136;
const int HEART_HEIGHT = 120;
const int HEART_OFFSET = 6;
const float HEART_SCALE = 0.5;

const int FONT_SIZE = 48;
const char FONT_NAME[] = "ARIAL";

#endif
