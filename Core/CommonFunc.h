#ifndef COMMONFUNC_H
#define COMMONFUNC_H

#include "Global.h"


struct CommonFunc
{
public:
    CommonFunc();
    ~CommonFunc();

    virtual bool loadFromFile(const std::string &path, SDL_Renderer* renderer);

    void render(SDL_Renderer* des, const SDL_Rect* clip , const int &x, const int &y );


    void Free();

    //The actual hardware texture
    SDL_Texture* pTexture;
    SDL_Rect pRect;



};

namespace SDLCommonFunc
    {
        bool CheckCollision (const SDL_Rect& object1,const SDL_Rect& object2);

    }

#endif // COMMONFUNC_H
