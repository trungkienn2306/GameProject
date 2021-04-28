#include "Text.h"

Text::Text(int _posX, int _posY, int _width, int _height)
{
    posX = _posX;
    posY = _posY;
    width = _width;
    height = _height;
    textTexture = NULL;
}

void Text::Draw()
{
    SDL_Rect temp = { posX, posY, width, height };
    SDL_RenderCopy(gRenderer, textTexture, NULL, &temp);
}

bool Text::LoadText(const std::string& path , TTF_Font* font)
{
    SDL_Color color = {COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B};
    SDL_Surface* surface = TTF_RenderText_Solid(font, path.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(gRenderer, surface);
    width = surface->w;
    height = surface->h;
    SDL_FreeSurface(surface);
    textTexture = texture;
    return textTexture != NULL;
}
