#ifndef GLOBAL_H
#define GLOBAL_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <ctime>
#include <sstream>


extern SDL_Window* gWindow ;


extern SDL_Renderer* gRenderer ;


extern SDL_Event gEvent;


//The number of threats
const int NUMBER_THREATS = 4;
extern int THREAT_SPEED;

//Screen dimension constants
const int SCREEN_WIDTH = 790;
const int SCREEN_HEIGHT = 649;

//Color Key
const int COLOR_KEY_R = 255;
const int COLOR_KEY_G = 255;
const int COLOR_KEY_B = 255;

extern TTF_Font* gFont;

extern int START_BUTTON_POSX;
extern int START_BUTTON_POSY;
extern int QUIT_BUTTON_POSX;
extern int QUIT_BUTTON_POSY;
extern int START_BUTTON_HEIGHT;
extern int START_BUTTON_WIDTH;
extern int QUIT_BUTTON_HEIGHT;
extern int QUIT_BUTTON_WIDTH;

extern SDL_Texture* start_button_texture_1;
extern SDL_Texture* start_button_texture_2;

extern SDL_Texture* quit_button_texture_1;
extern SDL_Texture* quit_button_texture_2;

extern SDL_Texture* replay_button_texture_1;
extern SDL_Texture* replay_button_texture_2;

#endif // GLOBAL_H
