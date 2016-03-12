#include "node.h"

node::node(int x,int y,int h,int direction)
{
    next=NULL;

    for(int i=0;i<4;i++)
        b[i]=0;
        b[direction]=1;
    sqr.x=x; sqr.y=y; sqr.w=sqr.h=h;
}


SDL_Rect* node::Get_Sqr(){ return (&sqr); }
node*     node:: Get_Next(){ return next; }


void node:: Node_Stop()
{
    for(int i=0;i<4;i++)
       b[i]=0;
}

void node:: Herit_Pred(node *p,int step)
{
    if(p->next->next)
        Herit_Pred(p->next,step);

    p->next->sqr=p->sqr;
    for(int i=0;i<4;i++)
            {
                p->next->b[i]=p->b[i];
            }
}

bool node::Move_On(int step)
{
    if(Limits(840,640,20))
        return false;

    if(b[0])
        {
            Herit_Pred(this,step);
            sqr.y-=step;
       }
    if(b[1])
        {
            Herit_Pred(this,step);
            sqr.y+=step;
        }
    if(b[2])
        {
            Herit_Pred(this,step);
            sqr.x-=step;
        }
    if(b[3])
        {
            Herit_Pred(this,step);
            sqr.x+=step;
        }
        return true;
}


bool node:: Limits(int width, int heigth,int l)
{


    if(sqr.x ==0 || sqr.y == 0 )
        {
            Node_Stop();
            return true;
        }
    if(sqr.x+l==width)
        {
            Node_Stop();
            return true;
        }
    if(sqr.y+l==heigth)
        {
            Node_Stop();
            return true;
        }
     return false;

}


void node::Go_Up()
{
    if(!b[1])
        {
            b[2]=b[3]=0;
            b[0]=1;
        }
}


void node::Go_Down()
{
    if(!b[0])
        {
            b[2]=b[3]=0;
            b[1]=1;
        }
}


void node::Go_Left()
{
    if(!b[3])
        {
            b[0]=b[1]=0;
            b[2]=1;
        }
}


void node::Go_Right()
{
    if(!b[2])
        {
            b[0]=b[1]=0;
            b[3]=1;
        }
}



node* node:: Get_Last()
{
    node *p=this;
    node *temp=p->next;

    while(temp)
    {
        p=temp;
        temp=temp->next;
    }

    return(p);

}

void node::Add_Node(int h)
{
    node* p=Get_Last(),*temp=NULL;

    if(p->b[0])
        {
            temp=new node(p->sqr.x,p->sqr.y+h,h,0);
        }

    if(p->b[1])
        {
            temp=new node(p->sqr.x,p->sqr.y-h,h,1);
        }

    if(p->b[2])
        {
            temp=new node(p->sqr.x+h,p->sqr.y,h,2);
        }


    if(p->b[3])
        {
            temp=new node(p->sqr.x-h,p->sqr.y,h,3);
        }

    p->next=temp;
}


node :: ~node()
{

}


