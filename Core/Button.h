#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "Global.h"

class Button{
private:
    int posX;
    int posY;
    int width;
    int height;
    SDL_Texture* button_1;
    SDL_Texture* button_2;
    SDL_Texture* current_button;
    SDL_Texture* compare_button;
public:
    Button(int _posX, int _posY, int _width, int _height, SDL_Texture* _button_1, SDL_Texture* _button_2) ;
    void HandleEvent(int x, int y) ;
    void Draw() ;
    bool ontheButton(int x, int y) ;

};

#endif // BUTTON_H_INCLUDED
