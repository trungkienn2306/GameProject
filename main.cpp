#include "Threat.h"
#include "Player.h"
#include "Global.h"
#include "Button.h"
#include "Text.h"

using namespace std;

 int START_BUTTON_POSX = 200 ;
 int START_BUTTON_POSY = 300;
 int QUIT_BUTTON_POSX = 500;
 int QUIT_BUTTON_POSY = 300;
 int START_BUTTON_HEIGHT  = 4*25;
 int START_BUTTON_WIDTH  = 6*25;
 int QUIT_BUTTON_HEIGHT  = 4*25;
 int QUIT_BUTTON_WIDTH  = 6*25;
 int REPLAY_BUTTON_POSX = 200;
 int REPLAY_BUTTON_POSY = 300;
 int REPLAY_BUTTON_HEIGHT = 4*25;
 int REPLAY_BUTTON_WIDTH = 6*25;

 SDL_Texture* start_button_texture_1  = NULL;
 SDL_Texture* start_button_texture_2= NULL;

 SDL_Texture* quit_button_texture_1 = NULL;
 SDL_Texture* quit_button_texture_2 = NULL;

 SDL_Texture* replay_button_texture_1 = NULL;
 SDL_Texture* replay_button_texture_2 = NULL;

 int fontsize = 24;
 int TEXT_POSX = 0;
 int TEXT_POSY = 0;
 int TEXT_WIDTH = 0;
 int TEXT_HEIGHT = 0;


 int THREAT_SPEED = 3;

 int start_time = 0;
 int start_score = 0;
 Uint32 current_time = 0;
 int current_score = 0;

//Starts up SDL and creates window
bool init(SDL_Window* &gWindow, SDL_Renderer* &gRenderer, const int SCREEN_WIDTH, const int SCREEN_HEIGHT );

//Frees media and shuts down SDL
void close(SDL_Window* &gWindow, SDL_Renderer* &gRenderer, CommonFunc gBackgroundTexture);

//Load up only background
bool checkBackground(SDL_Renderer* &gRenderer);

CommonFunc gBackgroundTexture;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//The window events
SDL_Event gEvent;


void LoadGraphic()
{
    start_button_texture_1 = IMG_LoadTexture(gRenderer, "img//start1.png");
    start_button_texture_2 = IMG_LoadTexture(gRenderer, "img//start2.png");
    quit_button_texture_1 = IMG_LoadTexture(gRenderer, "img//quit1.png");
    quit_button_texture_2 = IMG_LoadTexture(gRenderer, "img//quit2.png");

}

void LoadReplay()
{
    replay_button_texture_1 = IMG_LoadTexture(gRenderer, "img//replay1.png");
    replay_button_texture_2 = IMG_LoadTexture(gRenderer, "img//replay2.png");
}


int main(int argc, char* argv[])
{
    bool quit_game = false;
    while (!quit_game)
    {
        srand (time(NULL));

        int backGround_y = 0;

        //Start up SDL and create window
        if( !init(gWindow, gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT) )
        {
            printf( "Failed to initialize!\n" );
            return -1;
        }

        //Open Background Texture
        if (checkBackground(gRenderer) == false)
        {
            printf( "Failed to render background!\n" );
            return -1;
        }

        //Load Music
        Mix_Music* music = Mix_LoadMUS("audio//music.mp3");
        Mix_Music* gameover = Mix_LoadMUS("audio//gameover.mp3");


        //Open Menu
        LoadGraphic();
        bool quit_menu = false ;
        int x,y ;
        Button start_button(START_BUTTON_POSX,START_BUTTON_POSY,START_BUTTON_WIDTH,START_BUTTON_HEIGHT
                            , start_button_texture_1,start_button_texture_2) ;
        Button quit_button(QUIT_BUTTON_POSX,QUIT_BUTTON_POSY,QUIT_BUTTON_WIDTH,QUIT_BUTTON_HEIGHT
                           , quit_button_texture_1,quit_button_texture_2) ;
        start_button.Draw();
        quit_button.Draw();
        while(!quit_menu)
        {
            while(SDL_PollEvent(&gEvent))
            {
                if(gEvent.type == SDL_QUIT)
                {
                    close(gWindow, gRenderer, gBackgroundTexture);
                    return 0;
                }
                else
                {
                    if(gEvent.type == SDL_MOUSEMOTION)
                    {
                        SDL_GetMouseState(&x,&y) ;
                        start_button.HandleEvent(x,y) ;
                        quit_button.HandleEvent(x,y) ;
                    }
                    if(gEvent.type == SDL_MOUSEBUTTONDOWN)
                    {
                        SDL_GetMouseState(&x,&y);
                        if(quit_button.ontheButton(x,y))
                        {
                            close(gWindow, gRenderer, gBackgroundTexture);
                            return 0;
                        }
                        if(start_button.ontheButton(x,y))
                        {

                        quit_menu = true;
                        }

                    }
                }
            }
        }

        //Load explosion
        CommonFunc explosion;
        explosion.loadFromFile("img//explosion.png", gRenderer);

        //Load Text
        TTF_Font* font = TTF_OpenFont("arial.ttf", fontsize);
        Text scoreText (TEXT_POSX, TEXT_POSY, TEXT_WIDTH, TEXT_HEIGHT);
        scoreText.LoadText("SCORE: ", font);

        //Load Player
        Player player;
        player.loadFromFile("img//audi.png", gRenderer);

        //Load Threat
        Threat* ptr_MoreThreats = new Threat[NUMBER_THREATS];
        for (int i = 0; i < NUMBER_THREATS; i++)
        {
            Threat* ptr_threat = ptr_MoreThreats + i;
            ptr_threat->loadFromFile("img//police.png", gRenderer);
        }

        //Open music
        Mix_PlayMusic(music,-1);

        //Initialize score
        start_time = 0;
        start_score = 0;
        current_time = 0;
        current_score = 0;

        //Main game loop flag
        bool quit = false;
        while ( !quit )
        {
            current_time = SDL_GetTicks()/1000;
            int time_counter = current_time - start_time;
            if (time_counter >= 5)
            {
                current_score += 1;
                start_time = current_time;
            }

            int score_counter = current_score - start_score;
            cerr << current_score << endl;
            if (score_counter >= 3 )
            {
                THREAT_SPEED += 1;
                start_score = current_score;
                cerr << THREAT_SPEED << endl;
            }


            while (SDL_PollEvent(&gEvent) != 0 )
            {
                //User requests quit
                if( gEvent.type == SDL_QUIT )
                {
                    quit = true;
                    return 1;
                }
                //Player's controller
                player.handelInput(gEvent, gRenderer);

            }

            //Clear Screen
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( gRenderer );


            //Render background texture to screen
            backGround_y += 2;
            gBackgroundTexture.render(gRenderer, NULL, 0, backGround_y);
            gBackgroundTexture.render(gRenderer, NULL, 0, backGround_y - SCREEN_HEIGHT);
            if (backGround_y >= SCREEN_HEIGHT)
            {
                backGround_y = 0;
            }


            //Render Threats
            for (int ii = 0; ii < NUMBER_THREATS; ii++)
            {
                Threat* ptr_threat = ptr_MoreThreats + ii;
                if (ptr_threat)
                {
                    ptr_threat->HandleMove(THREAT_SPEED);
                    ptr_threat->Draw(gRenderer);

                    //check collision
                    bool is_col = SDLCommonFunc::CheckCollision(player.playerRect, ptr_threat->threatRect);
                    if (is_col)
                    {
                        quit = true;
                    }
                }
            }

            //Render Player
            player.handleMove(gRenderer);
            player.render(gRenderer, NULL, player.playerRect.x, player.playerRect.y);

            //Draw Text
            scoreText.Draw();

            SDL_Delay(10);
            //Update screen
            SDL_RenderPresent( gRenderer );
        }
        //Render explosion
        explosion.render(gRenderer, NULL, player.playerRect.x-25, player.playerRect.y-40);
        SDL_RenderPresent(gRenderer);

        Mix_HaltMusic();
        TTF_CloseFont(font);

        //Game over music
        Mix_PlayMusic(gameover, 1);

        delete [] ptr_MoreThreats;

        //Open replay menu
        LoadReplay();
        Button replay_button(REPLAY_BUTTON_POSX,REPLAY_BUTTON_POSY,REPLAY_BUTTON_WIDTH,REPLAY_BUTTON_HEIGHT
                             , replay_button_texture_1,replay_button_texture_2);
        replay_button.Draw();
        quit_button.Draw();
        bool quit_replayMenu = false;
        while(!quit_replayMenu)
        {
            while(SDL_PollEvent(&gEvent))
            {
                if(gEvent.type == SDL_QUIT)
                {
                    close(gWindow, gRenderer, gBackgroundTexture);
                    return 0;
                }
                else
                {
                    if(gEvent.type == SDL_MOUSEMOTION)
                    {
                        SDL_GetMouseState(&x,&y) ;
                        replay_button.HandleEvent(x,y) ;
                        quit_button.HandleEvent(x,y) ;
                    }
                    if(gEvent.type == SDL_MOUSEBUTTONDOWN)
                    {
                        SDL_GetMouseState(&x,&y);
                        if(quit_button.ontheButton(x,y))
                        {
                            close(gWindow, gRenderer, gBackgroundTexture);
                            return 0;
                        }
                        if(replay_button.ontheButton(x,y))
                        {
                            quit_replayMenu = true;
                        }

                    }
                }
            }
        }
        SDL_DestroyWindow( gWindow );
    }
    close(gWindow, gRenderer, gBackgroundTexture);
    return 0;
}

bool init(SDL_Window* &gWindow, SDL_Renderer* &gRenderer, const int SCREEN_WIDTH, const int SCREEN_HEIGHT)
{
	//Initialization flag
	bool success = true;

    SDL_Init(SDL_INIT_EVERYTHING);

    TTF_Init();

    gWindow = SDL_CreateWindow( "CAR GAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED
                               , SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );

    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048) ;

	return success;
}


bool checkBackground(SDL_Renderer* &gRenderer)
{
    bool check = gBackgroundTexture.loadFromFile("img//background.png", gRenderer);
    if (check == false) return false;

    return true;
}

void close(SDL_Window* &gWindow, SDL_Renderer* &gRenderer, CommonFunc gBackgroundTexture)
{
	//Free loaded images
	gBackgroundTexture.Free();
	SDL_DestroyTexture(start_button_texture_1);
    SDL_DestroyTexture(start_button_texture_2);
    SDL_DestroyTexture(quit_button_texture_1);
    SDL_DestroyTexture(quit_button_texture_2);
    start_button_texture_1  = NULL;
    start_button_texture_2= NULL;
    quit_button_texture_1 = NULL;
    quit_button_texture_2 = NULL;

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
