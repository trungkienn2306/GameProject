#include "Button.h"

Button:: Button(int _posX, int _posY, int _width, int _height,SDL_Texture* _button_1, SDL_Texture* _button_2)
{
    posX = _posX;
    posY = _posY;
    width = _width;
    height = _height;
    button_1 = _button_1;
    button_2 = _button_2;
    current_button = button_1;
    compare_button = NULL;
}
void Button:: HandleEvent(int x, int y)
{
    if( ontheButton(x, y) )
    {
        compare_button = button_2;
    }
    else compare_button = button_1;
    if(compare_button != current_button)
    {
        current_button = compare_button;
        Draw();
    }
}
void Button::Draw()
{
    SDL_Rect temp = {posX, posY, width, height};
    SDL_RenderCopy(gRenderer, current_button , NULL, &temp);
    SDL_RenderPresent(gRenderer);
}
bool Button:: ontheButton(int x, int y)
{
    if(x >= posX && x <= posX+width && y >= posY && y <= posY+ height)
        return true;

    else return false;
}
