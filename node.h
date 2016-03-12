#include <iostream>
#include<SDL/SDL.h>

#ifndef NODE_H
#define NODE_H

using namespace std;


class node
{
    private:

        SDL_Rect sqr;
        bool     b[4];
        node    *next;
        void     Node_Stop();
        bool     Limits(int,int,int);
        node    *Get_Last();
        void     Herit_Pred(node*,int);

    public:

        node(int,int,int,int);
        void      Add_Node(int);
        SDL_Rect *Get_Sqr();
        node*     Get_Next();
        void      Go_Up();
        void      Go_Down();
        void      Go_Left();
        void      Go_Right();
        bool      Move_On(int);
        ~node();
};





#endif
