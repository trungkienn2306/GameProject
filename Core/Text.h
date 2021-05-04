#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include "Global.h"

class Text
{
private:
    int width;
    int height;
    SDL_Texture* textTexture;
public:
    ~Text();
    Text();
    void Draw(const int &posX,const int &posY);
    bool LoadText(const std::string& path, TTF_Font* font);
    void Free();
    int getWidth();
    int getHeight();
};


#endif // TEXT_H_INCLUDED
