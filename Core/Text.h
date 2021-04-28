#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include "Global.h"

class Text
{
private:
    int posX;
    int posY;
    int width;
    int height;
    SDL_Texture* textTexture;
public:
    Text(int _posX, int _posY, int _width, int _height);
    void Draw();
    bool LoadText(const std::string& path, TTF_Font* font);
};


#endif // TEXT_H_INCLUDED
