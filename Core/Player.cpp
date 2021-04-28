#include "Player.h"

using namespace std;

Player::Player()
{
    playerRect.x = START_X;
    playerRect.y = START_Y;
    playerRect.w = PLAYER_COLLISION_WIDTH;
    playerRect.h = PLAYER_COLLISION_HEIGHT;
    pRect.w = WIDTH_PLAYER;
    pRect.h = HEIGHT_PLAYER;
}

Player::~Player()
{

}


void Player::handelInput(SDL_Event event, SDL_Renderer* &gRenderer)
{
    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_RIGHT:
            {
                playerRect.x += PLAYER_SPEED;

            }
            break;
        case SDLK_LEFT:
            {
                playerRect.x -= PLAYER_SPEED;

            }
            break;
        case SDLK_UP:
            {
                playerRect.y -= PLAYER_SPEED;

            }
            break;
        case SDLK_DOWN:
            {
                playerRect.y += PLAYER_SPEED;

            }
            break;
        default:
            break;
        }
    }
    else if (event.type == SDL_KEYUP)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            playerRect.y -= 0;

            break;
        case SDLK_DOWN:
            playerRect.y += 0;

            break;
        case SDLK_RIGHT:
            playerRect.x += 0;

            break;
        case SDLK_LEFT:
            playerRect.x -= 0;

            break;

        default:
            break;
        }
    }

    else if (event.type == SDL_MOUSEBUTTONDOWN)
    {

    }
    else if (event.type == SDL_MOUSEBUTTONUP)
    {

    }
}

void Player::handleMove(SDL_Renderer* renderer)
{

    if (playerRect.x < BORDER_WIDTH_LEFT_X_VAL)
    {
        playerRect.x = BORDER_WIDTH_LEFT_X_VAL;
    }

    if ( playerRect.x > BORDER_WIDTH_RIGHT_X_VAL)
    {
        playerRect.x = BORDER_WIDTH_RIGHT_X_VAL;
    }

    if (playerRect.y < 0)
    {
        playerRect.y = 0;
    }
    if ((playerRect.y + HEIGHT_PLAYER) > SCREEN_HEIGHT)
    {
        playerRect.y -= PLAYER_SPEED;
    }


}

void Player::draw(SDL_Renderer* des)
{
    SDL_Rect renderQuad = {playerRect.x, playerRect.y, WIDTH_PLAYER, HEIGHT_PLAYER};
    //cerr << playerRect.x << " " << playerRect.y << endl;
    SDL_RenderCopy(des, pTexture, NULL, &renderQuad);

}


