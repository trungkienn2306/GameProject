#ifndef THREAT_H
#define THREAT_H

#include "CommonFunc.h"


#define WIDTH_THREAT 65
#define HEIGHT_THREAT 140
#define BORDER_WIDTH_LEFT_X_VAL 110
#define BORDER_WIDTH_RIGHT_X_VAL 620
#define SPACE_Y_BETWEEN_THREATS 3000

#define THREAT_COLLISION_WIDTH 50
#define THREAT_COLLISION_HEIGHT 120

#define SPAWN_Y -200

struct Threat : public CommonFunc
{
    Threat();
    ~Threat();

    void HandleMove(int THREAT_SPEED);

    void Draw(SDL_Renderer* des);


    SDL_Rect threatRect;
};

#endif // THREAT_H
