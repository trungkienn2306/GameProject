#include "Threat.h"

using namespace std;

Threat::Threat()
{
    threatRect.x = SCREEN_WIDTH-300;
    threatRect.y = SPAWN_Y;
    threatRect.w = 50;
    threatRect.h = 120;
    pRect.w = WIDTH_THREAT;
    pRect.h = HEIGHT_THREAT;
}

Threat::~Threat()
{

}

void Threat::HandleMove(int THREAT_SPEED)
{
    threatRect.y += THREAT_SPEED;
    int rand_x_val = rand()%BORDER_WIDTH_RIGHT_X_VAL + BORDER_WIDTH_LEFT_X_VAL;
    int rand_y_val = rand()%SPACE_Y_BETWEEN_THREATS;

    if (rand_x_val > BORDER_WIDTH_RIGHT_X_VAL)
    {
        rand_x_val -= BORDER_WIDTH_LEFT_X_VAL;
    }

    if (threatRect.y > SCREEN_HEIGHT)
    {
        threatRect.y = SPAWN_Y-rand_y_val;
        threatRect.x = rand_x_val;
    }

}

void Threat::Draw(SDL_Renderer* des)
{
    SDL_Rect renderQuad = {threatRect.x, threatRect.y, WIDTH_THREAT, HEIGHT_THREAT};
    SDL_RenderCopy(des, pTexture, NULL, &renderQuad);
}




