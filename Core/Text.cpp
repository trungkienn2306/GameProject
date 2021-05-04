#include "Text.h"

Text::Text()
{
    width = 0;
    height = 0;
    textTexture = NULL;
}

Text::~Text()
{
    Free();
}

void Text::Draw(const int &posX,const int &posY)
{
    SDL_Rect temp = { posX, posY, width, height };
    SDL_RenderCopy(gRenderer, textTexture, NULL, &temp);
}

bool Text::LoadText(const std::string& path , TTF_Font* gFont)
{
    Free();
    SDL_Color color = {COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B};
    SDL_Surface* surface = TTF_RenderText_Solid(gFont, path.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(gRenderer, surface);
    width = surface->w;
    height = surface->h;
    SDL_FreeSurface(surface);
    textTexture = texture;
    return textTexture != NULL;
}

void Text::Free()
{
    if (textTexture == NULL)
    {
        SDL_DestroyTexture(textTexture);
        textTexture = NULL;
        width = 0;
        height = 0;
    }
}

int Text::getWidth()
{
    return width;
}

int Text::getHeight()
{
    return height;
}
