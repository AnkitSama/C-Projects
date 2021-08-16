#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std;

bool status ;
const int height = 20;
const int breadth = 40;
int x,y;
int fruitx,fruity;
enum eDirection{STOP = 0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
int score = 0;


int tailx[100],taily[100];
int tail_count = 0;

void setup()
{

    status  = true;
    dir = STOP;
    srand(time(0));
    x = rand() % breadth;
    y = rand() % height;
    fruitx = rand() % (breadth-1);
    fruity = rand() % (height-2);
}

void draw()
{
    system("cls");
    //upperwall
    for(int i = 0;i<breadth;i++)
    {
        cout<<"#";
    }
    cout<<endl;

    //left and right wall
    for(int i = 0;i<height-2;i++)
    {
        for(int j=0;j<breadth;j++)
        {
            if(j==0 || j==breadth-1)
            {
                cout<<"#";
                continue;
            }

            if(i==y && j==x)
            {
                cout<<"0";
            }
            else if(i==fruity && j==fruitx)
            {
                cout<<"*";
            }
            else
            {
                bool track = true;
                for(int k = 0;k<tail_count;k++)
                {
                    if(i==taily[k] && j==tailx[k])
                    {
                        cout<<"o";
                        track = false;
                        break;
                    }
                }
                if(track)
                cout<<" ";
            }
        }
        cout<<endl;
    }

    //lower wall
    for(int i = 0;i<breadth;i++)
    {
        cout<<"#";
    }
    cout<<endl;
    cout<<"Score : "<<score;
    cout<<endl<<x<<endl<<y<<endl<<fruitx<<endl<<fruity;
}

void input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            status = false;
            break;
        }
    }
}

void logic()
{
    int prevx = tailx[0];
    int prevy = taily[0];
    int prev2x,prev2y;

    tailx[0] = x;
    taily[0] = y;


    for (int i = 1; i < tail_count; i++)
    {
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }

    switch(dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;

    }

    for(int i = 0;i<tail_count;i++)
    {
        if(tailx[i]==x && taily[i]==y)
        {
            status = false;
        }
    }

    if(fruitx == x && fruity == y)
    {
        fruitx = rand() % (breadth-1);
        fruity = rand() % (height-2);
        score += 10;

        //increasing tail
        tail_count++;
    }


    if(x>breadth-2)
    {
        x = 1;
    }
    if(x<1)
    {
        x = breadth-2;
    }
    if(y>height-3)
    {
        y = 0;
    }
    if(y<0)
    {
        y = height-2;
    }
}
int main()
{
    setup();
    while(status)
    {
        draw();
        input();
        logic();
    }
    return 0;
}
