 #include "node.h"
#include <math.h>
#include <time.h>
#include <SDL/SDL_ttf.h>

#ifndef SNAKE_H
#define SNAKE_H

class snake
{
    private:
        node        *first;
        SDL_Surface *screen,*background,*noeud,*food,*text,*scor;
        int          l,width,height,score,addscore;
        SDL_Event    event;
        SDL_Rect     R_Food,Bor;
        SDL_Color    color;
        Uint32       Bor_Color;
        TTF_Font    *font;
        bool         Eated();
        int          F_Rand(int);

    public:

        snake(int,int,int);
        void Init();
        void Ready();
        void WaitKey();
        void Draw_Bg();
        void Draw_Node();
        void Draw_Food(int*);
        void Draw_Border();
        bool Go_To();
        void Draw_Score();
        void Game_Over();
        void Free_Snake();
        void Fill_Screen();
        ~snake();

};


#endif
