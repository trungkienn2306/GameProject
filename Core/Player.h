#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "CommonFunc.h"

#define WIDTH_PLAYER 63
#define HEIGHT_PLAYER 138

#define BORDER_WIDTH_LEFT_X_VAL 110
#define BORDER_WIDTH_RIGHT_X_VAL 620
#define PLAYER_COLLISION_WIDTH 55
#define PLAYER_COLLISION_HEIGHT 125

#define PLAYER_SPEED 10

#define START_X 365
#define START_Y 510

struct Player : public CommonFunc
{
        Player();
        ~Player();

        void handelInput(SDL_Event event, SDL_Renderer* &gRenderer);
        void handleMove(SDL_Renderer* renderer);
        void draw(SDL_Renderer* des);

        SDL_Rect playerRect;

};


#endif // PLAYER_H_INCLUDED
