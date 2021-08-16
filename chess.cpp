#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

bool game = true;
int arr[8][31] = {0};
bool castle = true;
bool long_castle = true;
bool bcastle = true;
bool blong_castle = true;
bool w_enpassant[29] = {0};
bool b_enpassant[29] = {0};
int white_king_i;
int white_king_j;
int black_king_i;
int black_king_j;

int Rank(char c)
{
    int x;
     switch(c)
            {
            case '1':
                x = 7;
                break;
            case '2':
                x = 6;
                break;
            case '3':
                x = 5;
                break;
            case '4':
                x = 4;
                break;
            case '5':
                x = 3;
                break;
            case '6':
                x = 2;
                break;
            case '7':
                x = 1;
                break;
            case '8':
                x = 0;
                break;
            default:
                x = -1;
            }
        return x;
}

int file(char c)
{
    int a;

            switch(c)
            {
            case 'a':
                a = 1;
                break;
            case 'b':
                a = 5;
                break;
            case 'c':
                a = 9;
                break;
            case 'd':
                a = 13;
                break;
            case 'e':
                a = 17;
                break;
            case 'f':
                a = 21;
                break;
            case 'g':
                a = 25;
                break;
            case 'h':
                a = 29;
                break;
            default:
                a = -1;
            }
    return a;
}

void start()
{
    for(int i = 0;i<31;i++)
    {
        if((i-1)%4==0)
        {
            arr[1][i] = 11;
            arr[6][i] = 1;
        }
    }

    arr[0][1] = 12;
    arr[0][5] = 13;
    arr[0][9] = 14;
    arr[0][13] = 15;
    arr[0][17] = 16;
    arr[0][21] = 14;
    arr[0][25] = 13;
    arr[0][29] = 12;

    arr[7][1] = 2;
    arr[7][5] = 3;
    arr[7][9] = 4;
    arr[7][13] = 5;
    arr[7][17] = 6;
    arr[7][21] = 4;
    arr[7][25] = 3;
    arr[7][29] = 2;
}

void board()
{
    cout<<" ";
    for(int i = 0;i<31;i++)
        cout<<"-";
    cout<<endl;


    for(int i = 0;i<8;i++)
    {
        cout<<"|";
        for(int j = 0;j<31;j++)
        {
            if((j+1)%4==0)
            {
                cout<<"|";
                continue;
            }

            if(arr[i][j]==0)
                cout<<" ";
            else
            {
                switch(arr[i][j])
                {
                case 1:
                    cout<<"P";
                    break;
                case 2:
                    cout<<"R";
                    break;
                case 3:
                    cout<<"N";
                    break;
                case 4:
                    cout<<"B";
                    break;
                case 5:
                    cout<<"Q";
                    break;
                case 6:
                    cout<<"K";
                    break;
                case 11:
                    cout<<"o";
                    break;
                case 12:
                    cout<<"#";
                    break;
                case 13:
                    cout<<"%";
                    break;
                case 14:
                    cout<<"^";
                    break;
                case 15:
                    cout<<"&";
                    break;
                case 16:
                    cout<<"$";
                    break;
                }
            }
        }
        cout<<"|";
        cout<<endl;

        cout<<" ";
    for(int i = 0;i<31;i++)
        cout<<"-";
    cout<<endl;
    }
}

void white_enpassant()
{
    for(int i = 1;i<=29;i += 4)
        w_enpassant[i] = false;
}

void black_enpassant()
{
    for(int i = 1;i<=29;i += 4)
        b_enpassant[i] = false;
}

bool black_check()
{
    int i = black_king_i;
    int j = black_king_j;

    //diagonal attack
    while(i>=1 && j<=25)
    {
        if(arr[i-1][j+4]==5 || arr[i-1][j+4]==4)
        {
            return true;
        }
        if(arr[i-1][j+4] != 0)
            break;

        i--;
        j += 4;
    }

    i = black_king_i;
    j = black_king_j;

    while(i>=1 && j>=5)
    {
        if(arr[i-1][j-4]==5 || arr[i-1][j-4]==4)
        {
            return true;
        }
        if(arr[i-1][j-4] != 0)
            break;

        i--;
        j -= 4;
    }

    i = black_king_i;
    j = black_king_j;

    while(i<=6 && j>=5)
    {
        if(arr[i+1][j-4]==5 || arr[i+1][j-4]==4)
        {
            return true;
        }
        if(arr[i+1][j-4] != 0)
            break;

        i++;
        j -= 4;
    }

    i = black_king_i;
    j = black_king_j;

    while(i<=6 && j<=25)
    {
        if(arr[i+1][j+4]==5 || arr[i+1][j+4]==4)
        {
            return true;
        }
        if(arr[i+1][j+4] != 0)
            break;

        i++;
        j += 4;
    }


    //attack in lines and files
    i = black_king_i;
    j = black_king_j;
    while(i>=1)
    {
        if(arr[i-1][j]==2 || arr[i-1][j]==5)
        {
            return true;
        }
        if(arr[i-1][j] != 0)
            break;

        i--;
    }

    i = black_king_i;
    j = black_king_j;
    while(i<=6)
    {
        if(arr[i+1][j]==2 || arr[i+1][j]==5)
        {
            return true;
        }
        if(arr[i+1][j] != 0)
            break;

        i++;
    }

    i = black_king_i;
    j = black_king_j;
    while(j>=5)
    {
        if(arr[i][j-4]==2 || arr[i][j-4]==5)
        {
            return true;
        }
        if(arr[i][j-4] != 0)
            break;

        j -= 4;
    }

    i = black_king_i;
    j = black_king_j;
    while(j<=25)
    {
        if(arr[i][j+4]==2 || arr[i][j+4]==5)
        {
            return true;
        }
        if(arr[i][j+4] != 0)
            break;

        j += 4;
    }

    //attack by knight
    i = black_king_i;
    j = black_king_j;
    if((i+2)<=7 && (j+4)<=29)
    {
        if(arr[i+2][j+4]==3)
        {
            return true;
        }
    }

    if((i+2)<=7 && (j-4)>=1)
    {
        if(arr[i+2][j-4]==3)
        {
            return true;
        }
    }

    if((i-2)>=0 && (j+4)<=29)
    {
        if(arr[i-2][j+4]==3)
        {
            return true;
        }
    }

    if((i-2)>=0 && (j-4)>=1)
    {
        if(arr[i-2][j-4]==3)
        {
            return true;
        }
    }

    if((i+1)<=7 && (j+8)<=29)
    {
        if(arr[i+1][j+8]==3)
        {
            return true;
        }
    }

    if((i+1)<=7 && (j-8)>=1)
    {
        if(arr[i+1][j-8]==3)
        {
            return true;
        }
    }

    if((i-1)>=0 && (j+8)<=29)
    {
        if(arr[i-1][j+8]==3)
        {
            return true;
        }
    }

    if((i-1)>=0 && (j-8)>=1)
    {
        if(arr[i-1][j-8]==3)
        {
            return true;
        }
    }

    //Attack by pawn
    if(i<=5 && j<=25)
    {
        if(arr[i+1][j+4]==1)
        {
            return true;
        }
    }
    if(i<=1 && j>=5)
    {
        if(arr[i+1][j-4]==1)
        {
            return true;
        }
    }

    //attack by king
    if(i>=1)
    {
        if(arr[i-1][j]==6)
            return true;

        if(j+4<=25)
        {
            if(arr[i-1][j+4]==6)
                return true;
        }

        if(j-4<=5)
        {
            if(arr[i-1][j-4]==6)
                return true;
        }
    }

    if(i<=6)
    {
        if(arr[i+1][j]==6)
            return true;

        if(j+4<=25)
        {
            if(arr[i+1][j+4]==6)
                return true;
        }

        if(j-4<=5)
        {
            if(arr[i+1][j-4]==6)
                return true;
        }
    }

    if(j+4<=25)
    {
        if(arr[i][j+4]==6)
            return true;
    }

    if(j-4>=5)
    {
        if(arr[i][j-4]==6)
            return true;
    }

    return false;
}

bool white_check()
{
    int i = white_king_i;
    int j = white_king_j;

    //diagonal attack
    while(i>=1 && j<=25)
    {
        if(arr[i-1][j+4]==15 || arr[i-1][j+4]==14)
        {
            return true;
        }
        if(arr[i-1][j+4] != 0)
            break;

        i--;
        j += 4;
    }

    i = white_king_i;
    j = white_king_j;

    while(i>=1 && j>=5)
    {
        if(arr[i-1][j-4]==15 || arr[i-1][j-4]==14)
        {
            return true;
        }
        if(arr[i-1][j-4] != 0)
            break;

        i--;
        j -= 4;
    }

    i = white_king_i;
    j = white_king_j;

    while(i<=6 && j>=5)
    {
        if(arr[i+1][j-4]==15 || arr[i+1][j-4]==14)
        {
            return true;
        }
        if(arr[i+1][j-4] != 0)
            break;

        i++;
        j -= 4;
    }

    i = white_king_i;
    j = white_king_j;

    while(i<=6 && j<=25)
    {
        if(arr[i+1][j+4]==15 || arr[i+1][j+4]==14)
        {
            return true;
        }
        if(arr[i+1][j+4] != 0)
            break;

        i++;
        j += 4;
    }


    //attack in lines and files
    i = white_king_i;
    j = white_king_j;
    while(i>=1)
    {
        if(arr[i-1][j]==12 || arr[i-1][j]==15)
        {
            return true;
        }
        if(arr[i-1][j] != 0)
            break;

        i--;
    }

    i = white_king_i;
    j = white_king_j;
    while(i<=6)
    {
        if(arr[i+1][j]==12 || arr[i+1][j]==15)
        {
            return true;
        }
        if(arr[i+1][j] != 0)
            break;

        i++;
    }

    i = white_king_i;
    j = white_king_j;
    while(j>=5)
    {
        if(arr[i][j-4]==12 || arr[i][j-4]==15)
        {
            return true;
        }
        if(arr[i][j-4] != 0)
            break;

        j -= 4;
    }

    i = white_king_i;
    j = white_king_j;
    while(j<=25)
    {
        if(arr[i][j+4]==12 || arr[i][j+4]==15)
        {
            return true;
        }
        if(arr[i][j+4] != 0)
            break;

        j += 4;
    }

    //attack by knight
    i = white_king_i;
    j = white_king_j;
    if((i+2)<=7 && (j+4)<=29)
    {
        if(arr[i+2][j+4]==13)
        {
            return true;
        }
    }

    if((i+2)<=7 && (j-4)>=1)
    {
        if(arr[i+2][j-4]==13)
        {
            return true;
        }
    }

    if((i-2)>=0 && (j+4)<=29)
    {
        if(arr[i-2][j+4]==13)
        {
            return true;
        }
    }

    if((i-2)>=0 && (j-4)>=1)
    {
        if(arr[i-2][j-4]==13)
        {
            return true;
        }
    }

    if((i+1)<=7 && (j+8)<=29)
    {
        if(arr[i+1][j+8]==13)
        {
            return true;
        }
    }

    if((i+1)<=7 && (j-8)>=1)
    {
        if(arr[i+1][j-8]==13)
        {
            return true;
        }
    }

    if((i-1)>=0 && (j+8)<=29)
    {
        if(arr[i-1][j+8]==13)
        {
            return true;
        }
    }

    if((i-1)>=0 && (j-8)>=1)
    {
        if(arr[i-1][j-8]==13)
        {
            return true;
        }
    }

    //Attack by pawn
    if(i>=1 && j<=25)
    {
        if(arr[i-1][j+4]==11)
        {
            return true;
        }
    }
    if(i>=1 && j>=5)
    {
        if(arr[i-1][j-4]==11)
        {
            return true;
        }
    }

    //attack by king
    if(i>=1)
    {
        if(arr[i-1][j]==16)
            return true;

        if(j+4<=25)
        {
            if(arr[i-1][j+4]==16)
                return true;
        }

        if(j-4<=5)
        {
            if(arr[i-1][j-4]==16)
                return true;
        }
    }

    if(i<=6)
    {
        if(arr[i+1][j]==16)
            return true;

        if(j+4<=25)
        {
            if(arr[i+1][j+4]==16)
                return true;
        }

        if(j-4<=5)
        {
            if(arr[i+1][j-4]==16)
                return true;
        }
    }

    if(j+4<=25)
    {
        if(arr[i][j+4]==16)
            return true;
    }

    if(j-4>=5)
    {
        if(arr[i][j-4]==16)
            return true;
    }

    return false;
}

bool attack_on_black(int x,int a)
{
    int i = x;
    int j = a;

    //diagonal attack
    while(i>=1 && j<=25)
    {
        if(arr[i-1][j+4]==5 || arr[i-1][j+4]==4)
        {
            return true;
        }
        if(arr[i-1][j+4] != 0)
            break;

        i--;
        j += 4;
    }

    i = x;
    j = a;

    while(i>=1 && j>=5)
    {
        if(arr[i-1][j-4]==5 || arr[i-1][j-4]==4)
        {
            return true;
        }
        if(arr[i-1][j-4] != 0)
            break;

        i--;
        j -= 4;
    }

    i = x;
    j = a;

    while(i<=6 && j>=5)
    {
        if(arr[i+1][j-4]==5 || arr[i+1][j-4]==4)
        {
            return true;
        }
        if(arr[i+1][j-4] != 0)
            break;

        i++;
        j -= 4;
    }

    i = x;
    j = a;

    while(i<=6 && j<=25)
    {
        if(arr[i+1][j+4]==5 || arr[i+1][j+4]==4)
        {
            return true;
        }
        if(arr[i+1][j+4] != 0)
            break;

        i++;
        j += 4;
    }


    //attack in lines and files
    i = x;
    j = a;
    while(i>=1)
    {
        if(arr[i-1][j]==2 || arr[i-1][j]==5)
        {
            return true;
        }
        if(arr[i-1][j] != 0)
            break;

        i--;
    }

    i = x;
    j = a;
    while(i<=6)
    {
        if(arr[i+1][j]==2 || arr[i+1][j]==5)
        {
            return true;
        }
        if(arr[i+1][j] != 0)
            break;

        i++;
    }

    i = x;
    j = a;
    while(j>=5)
    {
        if(arr[i][j-4]==2 || arr[i][j-4]==5)
        {
            return true;
        }
        if(arr[i][j-4] != 0)
            break;

        j -= 4;
    }

    i = x;
    j = a;
    while(j<=25)
    {
        if(arr[i][j+4]==2 || arr[i][j+4]==5)
        {
            return true;
        }
        if(arr[i][j+4] != 0)
            break;

        j += 4;
    }

    //attack by knight
    i = x;
    j = a;
    if((i+2)<=7 && (j+4)<=29)
    {
        if(arr[i+2][j+4]==3)
        {
            return true;
        }
    }

    if((i+2)<=7 && (j-4)>=1)
    {
        if(arr[i+2][j-4]==3)
        {
            return true;
        }
    }

    if((i-2)>=0 && (j+4)<=29)
    {
        if(arr[i-2][j+4]==3)
        {
            return true;
        }
    }

    if((i-2)>=0 && (j-4)>=1)
    {
        if(arr[i-2][j-4]==3)
        {
            return true;
        }
    }

    if((i+1)<=7 && (j+8)<=29)
    {
        if(arr[i+1][j+8]==3)
        {
            return true;
        }
    }

    if((i+1)<=7 && (j-8)>=1)
    {
        if(arr[i+1][j-8]==3)
        {
            return true;
        }
    }

    if((i-1)>=0 && (j+8)<=29)
    {
        if(arr[i-1][j+8]==3)
        {
            return true;
        }
    }

    if((i-1)>=0 && (j-8)>=1)
    {
        if(arr[i-1][j-8]==3)
        {
            return true;
        }
    }
    //pawn move
    if(i+1<=6)
    {
        if(arr[i+1][j]==1 && arr[i][j]==0)
            return true;
    }
    if(i==4)
    {
        if(arr[6][a]==1 && arr[4][a]==0)
            return true;
    }
    if(arr[x][a] != 0)
    {
        if(j+4<=29 && i<=5)
        {
            if(arr[i+1][j+4]==1)
                return true;
        }

        if(j-4<=1 && i<=5)
        {
            if(arr[i+1][j-4]==1)
                return true;
        }
    }

    return false;
}

bool attack_on_white(int x,int a)
{
    int i = x;
    int j = a;

    //diagonal attack
    while(i>=1 && j<=25)
    {
        if(arr[i-1][j+4]==15 || arr[i-1][j+4]==14)
        {
            return true;
        }
        if(arr[i-1][j+4] != 0)
            break;

        i--;
        j += 4;
    }

    i = x;
    j = a;

    while(i>=1 && j>=5)
    {
        if(arr[i-1][j-4]==15 || arr[i-1][j-4]==14)
        {
            return true;
        }
        if(arr[i-1][j-4] != 0)
            break;

        i--;
        j -= 4;
    }

    i = x;
    j = a;

    while(i<=6 && j>=5)
    {
        if(arr[i+1][j-4]==15 || arr[i+1][j-4]==14)
        {
            return true;
        }
        if(arr[i+1][j-4] != 0)
            break;

        i++;
        j -= 4;
    }

    i = x;
    j = a;

    while(i<=6 && j<=25)
    {
        if(arr[i+1][j+4]==15 || arr[i+1][j+4]==14)
        {
            return true;
        }
        if(arr[i+1][j+4] != 0)
            break;

        i++;
        j += 4;
    }


    //attack in lines and files
    i = x;
    j = a;
    while(i>=1)
    {
        if(arr[i-1][j]==12 || arr[i-1][j]==15)
        {
            return true;
        }
        if(arr[i-1][j] != 0)
            break;

        i--;
    }

    i = x;
    j = a;
    while(i<=6)
    {
        if(arr[i+1][j]==12 || arr[i+1][j]==15)
        {
            return true;
        }
        if(arr[i+1][j] != 0)
            break;

        i++;
    }

    i = x;
    j = a;
    while(j>=5)
    {
        if(arr[i][j-4]==12 || arr[i][j-4]==15)
        {
            return true;
        }
        if(arr[i][j-4] != 0)
            break;

        j -= 4;
    }

    i = x;
    j = a;
    while(j<=25)
    {
        if(arr[i][j+4]==12 || arr[i][j+4]==15)
        {
            return true;
        }
        if(arr[i][j+4] != 0)
            break;

        j += 4;
    }

    //attack by knight
    i = x;
    j = a;
    if((i+2)<=7 && (j+4)<=29)
    {
        if(arr[i+2][j+4]==13)
        {
            return true;
        }
    }

    if((i+2)<=7 && (j-4)>=1)
    {
        if(arr[i+2][j-4]==13)
        {
            return true;
        }
    }

    if((i-2)>=0 && (j+4)<=29)
    {
        if(arr[i-2][j+4]==13)
        {
            return true;
        }
    }

    if((i-2)>=0 && (j-4)>=1)
    {
        if(arr[i-2][j-4]==13)
        {
            return true;
        }
    }

    if((i+1)<=7 && (j+8)<=29)
    {
        if(arr[i+1][j+8]==13)
        {
            return true;
        }
    }

    if((i+1)<=7 && (j-8)>=1)
    {
        if(arr[i+1][j-8]==13)
        {
            return true;
        }
    }

    if((i-1)>=0 && (j+8)<=29)
    {
        if(arr[i-1][j+8]==13)
        {
            return true;
        }
    }

    if((i-1)>=0 && (j-8)>=1)
    {
        if(arr[i-1][j-8]==13)
        {
            return true;
        }
    }
    //pawn move
    if(i-1>=1)
    {
        if(arr[i-1][j]==11 && arr[i][j]==0)
            return true;
    }
    if(i==3)
    {
        if(arr[1][a]==11 && arr[3][j]==0)
            return true;
    }
    if(arr[x][a] != 0)
    {
        if(j+4<=29 && i>=2)
        {
            if(arr[i-1][j+4]==11)
                return true;
        }

        if(j-4<=1 && i>=2)
        {
            if(arr[i-1][j-4]==11)
                return true;
        }
    }

    return false;
}

void pawn(string m)
{
    //Move
    if(m[1]>='a' && m[1]<='h' && m[2]>='3' && m[2]<='8')
    {
        int a = file(m[1]);
        int x = Rank(m[2]);

        //Normal Move
        if(arr[x+1][a]==1)
        {
                if(arr[x][a]==0)
                {
                    if(x==0)
                    {
                        if(m[3]=='=' && (m[4]=='Q' || m[4]=='R' || m[4]=='B' || m[4]=='N'))
                        {
                            switch(m[4])
                            {
                            case 'R':
                                arr[x][a] = 2;
                                arr[x+1][a] = 0;
                                if(white_check())
                                {
                                    arr[x][a] = 0;
                                    arr[x+1][a] = 1;
                                }
                                return;
                            case 'N':
                                arr[x][a] = 3;
                                arr[x+1][a] = 0;
                                if(white_check())
                                {
                                    arr[x][a] = 0;
                                    arr[x+1][a] = 1;
                                }
                                return;
                            case 'B':
                                arr[x][a] = 4;
                                arr[x+1][a] = 0;
                                if(white_check())
                                {
                                    arr[x][a] = 0;
                                    arr[x+1][a] = 1;
                                }
                                return;
                            case 'Q':
                                arr[x][a] = 5;
                                arr[x+1][a] = 0;
                                if(white_check())
                                {
                                    arr[x][a] = 0;
                                    arr[x+1][a] = 1;
                                }
                                return;
                            }
                        }
                        else
                        {
                            cout<<"\nEnter the piece you want to promote to : ";
                            char p;
                            cin>>p;

                        if(p=='Q' || p=='R' || p=='B' || p=='N')
                        {
                            switch(p)
                            {
                            case 'R':
                                arr[x][a] = 2;
                                arr[x+1][a] = 0;
                                if(white_check())
                                {
                                    arr[x][a] = 0;
                                    arr[x+1][a] = 1;
                                }
                                return;
                            case 'N':
                                arr[x][a] = 3;
                                arr[x+1][a] = 0;
                                if(white_check())
                                {
                                    arr[x][a] = 0;
                                    arr[x+1][a] = 1;
                                }
                                return;
                            case 'B':
                                arr[x][a] = 4;
                                arr[x+1][a] = 0;
                                if(white_check())
                                {
                                    arr[x][a] = 0;
                                    arr[x+1][a] = 1;
                                }
                                return;
                            case 'Q':
                                arr[x][a] = 5;
                                arr[x+1][a] = 0;
                                if(white_check())
                                {
                                    arr[x][a] = 0;
                                    arr[x+1][a] = 1;
                                }
                                return;
                            }
                        }
                        return;
                    }
                }
                    arr[x+1][a] = 0;
                    arr[x][a] = 1;
                    if(white_check())
                    {
                        arr[x+1][a] = 1;
                        arr[x][a] = 0;
                    }
                    return;
                }
        }


        if(arr[6][a]==1 &&  m[2]=='4')
        {
            if(arr[5][a]==0 && arr[4][a]==0)
            {
                arr[6][a] = 0;
                arr[4][a] = 1;
                if(white_check())
                {
                    arr[6][a] = 1;
                    arr[4][a] = 0;
                    return;
                }
                b_enpassant[a] = true;
            }
        }
    }

    //Capture
    if(m[2]=='x' && m[1]>='a' && m[1]<='h' && m[4]>='3' && m[4]<='8' && m[3]>='a' && m[3]<='h')
    {
        int a = file(m[1]);
        int b = file(m[3]);
        int x = Rank(m[4]);

        if(a-b != 4 && b-a !=4)
        {
            return;
        }


            if(arr[x+1][a]==1)
            {
                if(arr[x][b]==11 || arr[x][b]==12 || arr[x][b]==13 || arr[x][b]==14 || arr[x][b]==15 || arr[x][b]==16)
                {
                    int c = arr[x][b];
                    if(x==0)
                    {
                        if(m[5]=='=' && (m[6]=='Q' || m[6]=='R' || m[6]=='B' || m[6]=='N'))
                        {
                            switch(m[6])
                            {
                            case 'R':
                                arr[x][b] = 2;
                                arr[x+1][a] = 0;
                                if(white_check())
                                {
                                    arr[x][b] = c;
                                    arr[x+1][a] = 1;
                                }
                                return;
                            case 'N':
                                arr[x][b] = 3;
                                arr[x+1][a] = 0;
                                if(white_check())
                                {
                                    arr[x][b] = c;
                                    arr[x+1][a] = 1;
                                }
                                return;
                            case 'B':
                                arr[x][b] = 4;
                                arr[x+1][a] = 0;
                                if(white_check())
                                {
                                    arr[x][b] = c;
                                    arr[x+1][a] = 1;
                                }
                                return;
                            case 'Q':
                                arr[x][b] = 5;
                                arr[x+1][a] = c;
                                if(white_check())
                                {
                                    arr[x][b] = c;
                                    arr[x+1][a] = 1;
                                }
                                return;
                            }
                        }
                        else
                        {
                            cout<<"\nEnter the piece you want to promote to : ";
                            char p;
                            cin>>p;

                        if(p=='Q' || p=='R' || p=='B' || p=='N')
                        {
                            switch(p)
                            {
                            case 'R':
                                arr[x][b] = 2;
                                arr[x+1][a] = 0;
                                if(white_check())
                                {
                                    arr[x][b] = c;
                                    arr[x+1][a] = 1;
                                }
                                return;
                            case 'N':
                                arr[x][b] = 3;
                                arr[x+1][a] = 0;
                                if(white_check())
                                {
                                    arr[x][b] = c;
                                    arr[x+1][a] = 1;
                                }
                                return;
                            case 'B':
                                arr[x][b] = 4;
                                arr[x+1][a] = 0;
                                if(white_check())
                                {
                                    arr[x][b] = c;
                                    arr[x+1][a] = 1;
                                }
                                return;
                            case 'Q':
                                arr[x][b] = 5;
                                arr[x+1][a] = c;
                                if(white_check())
                                {
                                    arr[x][b] = c;
                                    arr[x+1][a] = 1;
                                }
                                return;
                            }
                        }
                        return;
                        }
                    }
                    arr[x+1][a] = 0;
                    arr[x][b] = 1;
                    if(white_check())
                    {
                        arr[x][b] = c;
                        arr[x+1][a] = 1;
                    }
                    return;
                }

                if(x==2)
                {
                    if(arr[x][b]==0 && arr[x+1][b]==11 && w_enpassant[b])
                    {
                        arr[x][b] = 1;
                        arr[x+1][a] = 0;
                        arr[x+1][b] = 0;
                        if(white_check())
                        {
                            arr[x][b] = 0;
                            arr[x+1][a] = 1;
                            arr[x+1][b] = 11;
                        }
                    }
                }
            }
     }
}

void bpawn(string m)
{
    //move
    if(m[1]>='a' && m[1]<='h' && m[2]>='1' && m[2]<='6')
    {
        int a = file(m[1]);
        int x = Rank(m[2]);

        if(arr[x-1][a]==11)
        {
            if(arr[x][a]==0)
            {
                if(x==7)
                    {
                        if(m[3]=='=' && (m[4]=='q' || m[4]=='r' || m[4]=='b' || m[4]=='n'))
                        {
                            switch(m[4])
                            {
                            case 'r':
                                arr[x][a] = 12;
                                arr[x-1][a] = 0;
                                if(black_check())
                                {
                                    arr[x][a] = 0;
                                    arr[x-1][a] = 11;
                                }
                                return;
                            case 'n':
                                arr[x][a] = 13;
                                arr[x-1][a] = 0;
                                if(black_check())
                                {
                                    arr[x][a] = 0;
                                    arr[x-1][a] = 11;
                                }
                                return;
                            case 'b':
                                arr[x][a] = 14;
                                arr[x-1][a] = 0;
                                if(black_check())
                                {
                                    arr[x][a] = 0;
                                    arr[x-1][a] = 11;
                                }
                                return;
                            case 'q':
                                arr[x][a] = 15;
                                arr[x-1][a] = 0;
                                if(black_check())
                                {
                                    arr[x][a] = 0;
                                    arr[x-1][a] = 11;
                                }
                                return;
                            }
                        }
                        else
                        {
                            cout<<"\nEnter the piece you want to promote to : ";
                            char p;
                            cin>>p;

                        if(p=='q' || p=='r' || p=='b' || p=='n')
                        {
                            switch(p)
                            {
                            case 'r':
                                arr[x][a] = 12;
                                arr[x-1][a] = 0;
                                if(black_check())
                                {
                                    arr[x][a] = 0;
                                    arr[x-1][a] = 11;
                                }
                                return;
                            case 'n':
                                arr[x][a] = 13;
                                arr[x-1][a] = 0;
                                if(black_check())
                                {
                                    arr[x][a] = 0;
                                    arr[x-1][a] = 11;
                                }
                                return;
                            case 'b':
                                arr[x][a] = 14;
                                arr[x-1][a] = 0;
                                if(black_check())
                                {
                                    arr[x][a] = 0;
                                    arr[x-1][a] = 11;
                                }
                                return;
                            case 'q':
                                arr[x][a] = 15;
                                arr[x-1][a] = 0;
                                if(black_check())
                                {
                                    arr[x][a] = 0;
                                    arr[x-1][a] = 11;
                                }
                                return;
                            }
                        }
                        return;
                    }
                }
                arr[x-1][a] = 0;
                arr[x][a] = 11;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[x-1][a] = 11;
                }
                return;
            }
        }

        if(arr[1][a]==11 && m[2]=='5')
        {
            if(arr[2][a]==0 && arr[3][a]==0)
            {
                arr[1][a] = 0;
                arr[3][a] = 11;
                if(black_check())
                {
                    arr[3][a] = 0;
                    arr[1][a] = 11;
                    return;
                }
                w_enpassant[a] = true;

            }
        }
    }

    //capture
    if(m[2]=='x' && m[1]>='a' && m[1]<='h' && m[3]>='a' && m[3]<='h' && m[4]>='1' && m[4]<='6')
    {
        int a = file(m[1]);
        int b = file(m[3]);
        int x = Rank(m[4]);
        int c = arr[x][a];

        if(a-b != 4 && b-a !=4)
        {
            return;
        }

            if(arr[x-1][a]==11)
            {
                if(arr[x][b]==1 || arr[x][b]==2 || arr[x][b]==3 || arr[x][b]==4 || arr[x][b]==5 || arr[x][b]==6)
                {
                    if(x==7)
                    {
                        if(m[5]=='=' && (m[6]=='q' || m[6]=='r' || m[6]=='b' || m[6]=='n'))
                        {
                            switch(m[6])
                            {
                            case 'r':
                                arr[x][b] = 12;
                                arr[x-1][a] = 0;
                                if(black_check())
                                {
                                    arr[x][b] = c;
                                    arr[x-1][a] = 11;
                                }
                                return;
                            case 'n':
                                arr[x][b] = 13;
                                arr[x-1][a] = 0;
                                if(black_check())
                                {
                                    arr[x][b] = c;
                                    arr[x-1][a] = 11;
                                }
                                return;
                            case 'b':
                                arr[x][b] = 14;
                                arr[x-1][a] = 0;
                                if(black_check())
                                {
                                    arr[x][b] = c;
                                    arr[x-1][a] = 11;
                                }
                                return;
                            case 'q':
                                arr[x][b] = 15;
                                arr[x-1][a] = 0;
                                if(black_check())
                                {
                                    arr[x][b] = c;
                                    arr[x-1][a] = 11;
                                }
                                return;
                            }
                        }
                        else
                        {
                            cout<<"\nEnter the piece you want to promote to : ";
                            char p;
                            cin>>p;

                        if(p=='q' || p=='r' || p=='b' || p=='n')
                        {
                            switch(p)
                            {
                            case 'r':
                                arr[x][b] = 12;
                                arr[x-1][a] = 0;
                                if(black_check())
                                {
                                    arr[x][b] = c;
                                    arr[x-1][a] = 11;
                                }
                                return;
                            case 'n':
                                arr[x][b] = 13;
                                arr[x-1][a] = 0;
                                if(black_check())
                                {
                                    arr[x][b] = c;
                                    arr[x-1][a] = 11;
                                }
                                return;
                            case 'b':
                                arr[x][b] = 14;
                                arr[x-1][a] = 0;
                                if(black_check())
                                {
                                    arr[x][b] = c;
                                    arr[x-1][a] = 11;
                                }
                                return;
                            case 'q':
                                arr[x][b] = 15;
                                arr[x-1][a] = 0;
                                if(black_check())
                                {
                                    arr[x][b] = c;
                                    arr[x-1][a] = 11;
                                }
                                return;
                            }
                        }
                        return;
                        }
                    }
                    arr[x-1][a] = 0;
                    arr[x][b] = 11;
                    if(black_check())
                    {
                        arr[x][b] = c;
                        arr[x-1][a] = 11;
                    }
                    return;
                }

                if(x==5)
                {
                    if(arr[x][b]==0 && arr[x-1][b]==1 && b_enpassant[b])
                    {
                        arr[x][b] = 11;
                        arr[x-1][a] = 0;
                        arr[x-1][b] = 0;
                        if(black_check())
                        {
                            arr[x][b] = 0;
                            arr[x-1][b] = 1;
                            arr[x-1][a] = 11;
                        }
                    }
                }
            }
    }
}

void rook(string m)
{
    //move
    if((m[1]>='a' && m[1]<='h') && (m[2]>='1' && m[2]<='8'))
    {
        int a = file(m[1]);
        int x = Rank(m[2]);

        for(int i = 0;i<8;i++)
        {
            if(arr[i][a]==2)
            {
                bool check = true;
                int j = i;
                while(j<x)
                {
                    if(arr[++j][a] != 0)
                    {
                        check = false;
                        break;
                    }
                }
                while(j>x)
                {
                    if(arr[--j][a] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[i][a] = 0;
                    arr[x][a] = 2;
                    if(white_check())
                    {
                        arr[i][a] = 2;
                        arr[x][a] = 0;
                        return;
                    }
                    if(i==7 && a==1)
                    {
                        long_castle = false;
                    }
                    if(i==7 && a==29)
                    {
                        castle = false;
                    }
                    return;
                }
            }
        }


        for(int i = 1;i<=29;i += 4)
        {
            if(arr[x][i]==2)
            {
                bool check = true;
                int j = i;
                while(j<a)
                {
                    if(arr[x][j+4] != 0)
                    {
                        check = false;
                        break;
                    }
                    j += 4;
                }
                while(j>a)
                {
                    if(arr[x][j-4] != 0)
                    {
                        check = false;
                        break;
                    }
                    j -= 4;
                }

                if(check && arr[x][a]==0)
                {
                    arr[x][a] = 2;
                    arr[x][i] = 0;
                    if(white_check())
                    {
                        arr[x][a] = 0;
                        arr[x][i] = 2;
                        return;
                    }
                    if(i==1 && x==7)
                    {
                        long_castle = false;
                    }
                    if(i==29 && x==7)
                    {
                        castle = false;
                    }
                    return;
                }
            }
        }
    }

    //Two Possible Moves part 1
    if((m[1]>='a' && m[1]<='h') && (m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8'))
    {
        int b = file(m[1]);
        int a = file(m[2]);
        int x = Rank(m[3]);

        for(int i = 0;i<8;i++)
        {
            if(arr[i][a]==2 && a==b)
            {
                bool check = true;
                int j = i;
                while(j<x)
                {
                    if(arr[++j][a] != 0)
                    {
                        check = false;
                        break;
                    }
                }
                while(j>x)
                {
                    if(arr[--j][a] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[i][a] = 0;
                    arr[x][a] = 2;
                    if(white_check())
                    {
                        arr[i][a] = 2;
                        arr[x][a] = 0;
                        return;
                    }
                    if(i==7 && a==1)
                    {
                        long_castle = false;
                    }
                    if(i==7 && a==29)
                    {
                        castle = false;
                    }
                    return;
                }
            }
        }


        for(int i = 1;i<=29;i += 4)
        {
            if(arr[x][i]==2 && i==b)
            {
                bool check = true;
                int j = i;
                while(j<a)
                {
                    if(arr[x][j+4] != 0)
                    {
                        check = false;
                        break;
                    }
                    j += 4;
                }
                while(j>a)
                {
                    if(arr[x][j-4] != 0)
                    {
                        check = false;
                        break;
                    }
                    j -= 4;
                }

                if(check && arr[x][a]==0)
                {
                    arr[x][a] = 2;
                    arr[x][i] = 0;
                    if(white_check())
                    {
                        arr[x][a] = 0;
                        arr[x][i] = 2;
                        return;
                    }
                    if(i==1 && x==7)
                    {
                        long_castle = false;
                    }
                    if(i==29 && x==7)
                    {
                        castle = false;
                    }
                    return;
                }
            }
        }
    }

    //Two Possible Moves part 2
    if((m[1]>='1' && m[1]<='8') && (m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8'))
    {
        int b = Rank(m[1]);
        int a = file(m[2]);
        int x = Rank(m[3]);

        for(int i = 0;i<8;i++)
        {
            if(arr[i][a]==2 && i==b)
            {
                bool check = true;
                int j = i;
                while(j<x)
                {
                    if(arr[++j][a] != 0)
                    {
                        check = false;
                        break;
                    }
                }
                while(j>x)
                {
                    if(arr[--j][a] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[i][a] = 0;
                    arr[x][a] = 2;
                    if(white_check())
                    {
                        arr[i][a] = 2;
                        arr[x][a] = 0;
                        return;
                    }
                    if(i==7 && a==1)
                    {
                        long_castle = false;
                    }
                    if(i==7 && a==29)
                    {
                        castle = false;
                    }
                    return;
                }
            }
        }

        for(int i = 1;i<=29;i += 4)
        {
            if(arr[x][i]==2 && x==b)
            {
                bool check = true;
                int j = i;
                while(j<a)
                {
                    if(arr[x][j+4] != 0)
                    {
                        check = false;
                        break;
                    }
                    j += 4;
                }
                while(j>a)
                {
                    if(arr[x][j-4] != 0)
                    {
                        check = false;
                        break;
                    }
                    j -= 4;
                }

                if(check && arr[x][a]==0)
                {
                    arr[x][a] = 2;
                    arr[x][i] = 0;
                    if(white_check())
                    {
                        arr[x][a] = 0;
                        arr[x][i] = 2;
                        return;
                    }
                    if(i==1 && x==7)
                    {
                        long_castle = false;
                    }
                    if(i==29 && x==7)
                    {
                        castle = false;
                    }
                    return;
                }
            }
        }
    }

    //capture
    if((m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8') && m[1]=='x')
    {
        int a = file(m[2]);
        int x = Rank(m[3]);
        int c = arr[x][a];

        for(int i = 0;i<8;i++)
        {
            if(arr[i][a]==2)
            {
                bool check = true;
                int j = i;
                while(j<x)
                {
                    if(arr[++j][a] != 0)
                    {
                        if(!(arr[j][a]==11 || arr[j][a]==12 || arr[j][a]==13 || arr[j][a]==14 || arr[j][a]==15 || arr[j][a]==16))
                            check = false;
                        break;
                    }
                }
                while(j>x)
                {
                    if(arr[--j][a] != 0)
                    {
                        if(!(arr[j][a]==11 || arr[j][a]==12 || arr[j][a]==13 || arr[j][a]==14 || arr[j][a]==15 || arr[j][a]==16))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==x)
                {
                    arr[i][a] = 0;
                    arr[x][a] = 2;
                    if(white_check())
                    {
                        arr[i][a] = 2;
                        arr[x][a] = c;
                        return;
                    }
                    if(i==7 && a==1)
                    {
                        long_castle = false;
                    }
                    if(i==7 && a==29)
                    {
                        castle = false;
                    }
                    return;
                }
            }
        }


        for(int i = 1;i<=29;i += 4)
        {
            if(arr[x][i]==2)
            {
                bool check = true;
                int j = i;
                while(j<a)
                {
                    if(arr[x][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                while(j>a)
                {
                    if(arr[x][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a)
                {
                    arr[x][a] = 2;
                    arr[x][i] = 0;
                    if(white_check())
                    {
                        arr[x][a] = c;
                        arr[x][i] = 2;
                        return;
                    }
                    if(i==1 && x==7)
                    {
                        long_castle = false;
                    }
                    if(i==29 && x==7)
                    {
                        castle = false;
                    }
                    return;
                }
            }
        }
    }

    //Two Possible Captures part 1
    if((m[1]>='a' && m[1]<='h') && (m[3]>='a' && m[3]<='h') && m[2]=='x' && (m[4]>='1' && m[4]<='8'))
    {
        int b = file(m[1]);
        int a = file(m[3]);
        int x = Rank(m[4]);
        int c = arr[x][a];

        for(int i = 0;i<8;i++)
        {
            if(arr[i][a]==2 && a==b)
            {
                bool check = true;
                int j = i;
                while(j<x)
                {
                    if(arr[++j][a] != 0)
                    {
                        if(!(arr[j][a]==11 || arr[j][a]==12 || arr[j][a]==13 || arr[j][a]==14 || arr[j][a]==15 || arr[j][a]==16))
                            check = false;
                        break;
                    }
                }
                while(j>x)
                {
                    if(arr[--j][a] != 0)
                    {
                        if(!(arr[j][a]==11 || arr[j][a]==12 || arr[j][a]==13 || arr[j][a]==14 || arr[j][a]==15 || arr[j][a]==16))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==x)
                {
                    arr[i][a] = 0;
                    arr[x][a] = 2;
                    if(white_check())
                    {
                        arr[i][a] = 2;
                        arr[x][a] = c;
                        return;
                    }
                    if(i==7 && a==1)
                    {
                        long_castle = false;
                    }
                    if(i==7 && a==29)
                    {
                        castle = false;
                    }
                    return;
                }
            }
        }


        for(int i = 1;i<=29;i += 4)
        {
            if(arr[x][i]==2 && i==b)
            {
                bool check = true;
                int j = i;
                while(j<a)
                {
                    if(arr[x][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                while(j>a)
                {
                    if(arr[x][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a)
                {
                    arr[x][a] = 2;
                    arr[x][i] = 0;
                    if(white_check())
                    {
                        arr[x][i] = 2;
                        arr[x][a] = c;
                        return;
                    }
                    if(i==1 && x==7)
                    {
                        long_castle = false;
                    }
                    if(i==29 && x==7)
                    {
                        castle = false;
                    }
                    return;
                }
            }
        }
    }

     //Two Possible Captures part 2
    if((m[1]>='1' && m[1]<='8') && (m[3]>='a' && m[3]<='h') && m[2]=='x' && (m[4]>='1' && m[4]<='8'))
    {
        int b = Rank(m[1]);
        int a = file(m[3]);
        int x = Rank(m[4]);
        int c = arr[x][a];

        for(int i = 0;i<8;i++)
        {
            if(arr[i][a]==2 && i==b)
            {
                bool check = true;
                int j = i;
                while(j<x)
                {
                    if(arr[++j][a] != 0)
                    {
                        if(!(arr[j][a]==11 || arr[j][a]==12 || arr[j][a]==13 || arr[j][a]==14 || arr[j][a]==15 || arr[j][a]==16))
                            check = false;
                        break;
                    }
                }
                while(j>x)
                {
                    if(arr[--j][a] != 0)
                    {
                        if(!(arr[j][a]==11 || arr[j][a]==12 || arr[j][a]==13 || arr[j][a]==14 || arr[j][a]==15 || arr[j][a]==16))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==x)
                {
                    arr[i][a] = 0;
                    arr[x][a] = 2;
                    if(white_check())
                    {
                        arr[i][a] = 2;
                        arr[x][a] = c;
                        return;
                    }
                    if(i==7 && a==1)
                    {
                        long_castle = false;
                    }
                    if(i==7 && a==29)
                    {
                        castle = false;
                    }
                    return;
                }
            }
        }

        for(int i = 1;i<=29;i += 4)
        {
            if(arr[x][i]==2 && x==b)
            {
                bool check = true;
                int j = i;
                while(j<a)
                {
                    if(arr[x][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                while(j>a)
                {
                    if(arr[x][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a)
                {
                    arr[x][a] = 2;
                    arr[x][i] = 0;
                    if(white_check())
                    {
                        arr[x][i] = 2;
                        arr[x][a] = c;
                        return;
                    }
                    if(i==1 && x==7)
                    {
                        long_castle = false;
                    }
                    if(i==29 && x==7)
                    {
                        castle = false;
                    }
                    return;
                }
            }
        }
    }
}

void brook(string m)
{
    //move
    if((m[1]>='a' && m[1]<='h') && (m[2]>='1' && m[2]<='8'))
    {
        int a = file(m[1]);
        int x = Rank(m[2]);

        for(int i = 0;i<8;i++)
        {
            if(arr[i][a]==12)
            {
                bool check = true;
                int j = i;
                while(j<x)
                {
                    if(arr[++j][a] != 0)
                    {
                        check = false;
                        break;
                    }
                }
                while(j>x)
                {
                    if(arr[--j][a] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[i][a] = 0;
                    arr[x][a] = 12;
                    if(black_check())
                    {
                        arr[i][a] = 12;
                        arr[x][a] = 0;
                        return;
                    }
                    if(i==0 && a==1)
                    {
                        blong_castle = false;
                    }
                    if(i==0 && a==29)
                    {
                        bcastle = false;
                    }
                    return;
                }
            }
        }


        for(int i = 1;i<=29;i += 4)
        {
            if(arr[x][i]==12)
            {
                bool check = true;
                int j = i;
                while(j<a)
                {
                    if(arr[x][j+4] != 0)
                    {
                        check = false;
                        break;
                    }
                    j += 4;
                }
                while(j>a)
                {
                    if(arr[x][j-4] != 0)
                    {
                        check = false;
                        break;
                    }
                    j -= 4;
                }

                if(check && arr[x][a]==0)
                {
                    arr[x][a] = 12;
                    arr[x][i] = 0;
                    if(black_check())
                    {
                        arr[x][i] = 12;
                        arr[x][a] = 0;
                        return;
                    }
                    if(i==1 && x==0)
                    {
                        blong_castle = false;
                    }
                    if(i==29 && x==0)
                    {
                        bcastle = false;
                    }
                    return;
                }
            }
        }
    }

    //Two Possible Moves Part 1
    if((m[1]>='a' && m[1]<='h') && (m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8'))
    {
        int b = file(m[1]);
        int a = file(m[2]);
        int x = Rank(m[3]);

        for(int i = 0;i<8;i++)
        {
            if(arr[i][a]==12 && a==b)
            {
                bool check = true;
                int j = i;
                while(j<x)
                {
                    if(arr[++j][a] != 0)
                    {
                        check = false;
                        break;
                    }
                }
                while(j>x)
                {
                    if(arr[--j][a] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[i][a] = 0;
                    arr[x][a] = 12;
                    if(black_check())
                    {
                        arr[i][a] = 12;
                        arr[x][a] = 0;
                        return;
                    }
                    if(i==0 && a==1)
                    {
                        blong_castle = false;
                    }
                    if(i==0 && a==29)
                    {
                        bcastle = false;
                    }
                    return;
                }
            }
        }


        for(int i = 1;i<=29;i += 4)
        {
            if(arr[x][i]==12 && i==b)
            {
                bool check = true;
                int j = i;
                while(j<a)
                {
                    if(arr[x][j+4] != 0)
                    {
                        check = false;
                        break;
                    }
                    j += 4;
                }
                while(j>a)
                {
                    if(arr[x][j-4] != 0)
                    {
                        check = false;
                        break;
                    }
                    j -= 4;
                }

                if(check && arr[x][a]==0)
                {
                    arr[x][a] = 12;
                    arr[x][i] = 0;
                    if(black_check())
                    {
                        arr[x][i] = 12;
                        arr[x][a] = 0;
                        return;
                    }
                    if(i==1 && x==0)
                    {
                        blong_castle = false;
                    }
                    if(i==29 && x==0)
                    {
                        bcastle = false;
                    }
                    return;
                }
            }
        }
    }

    //Two Possible Moves Part 1
    if((m[1]>='1' && m[1]<='8') && (m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8'))
    {
        int b = Rank(m[1]);
        int a = file(m[2]);
        int x = Rank(m[3]);

        for(int i = 0;i<8;i++)
        {
            if(arr[i][a]==12 && i==b)
            {
                bool check = true;
                int j = i;
                while(j<x)
                {
                    if(arr[++j][a] != 0)
                    {
                        check = false;
                        break;
                    }
                }
                while(j>x)
                {
                    if(arr[--j][a] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[i][a] = 0;
                    arr[x][a] = 12;
                    if(black_check())
                    {
                        arr[i][a] = 12;
                        arr[x][a] = 0;
                        return;
                    }
                    if(i==0 && a==1)
                    {
                        blong_castle = false;
                    }
                    if(i==0 && a==29)
                    {
                        bcastle = false;
                    }
                    return;
                }
            }
        }

        for(int i = 1;i<=29;i += 4)
        {
            if(arr[x][i]==12 && x==b)
            {
                bool check = true;
                int j = i;
                while(j<a)
                {
                    if(arr[x][j+4] != 0)
                    {
                        check = false;
                        break;
                    }
                    j += 4;
                }
                while(j>a)
                {
                    if(arr[x][j-4] != 0)
                    {
                        check = false;
                        break;
                    }
                    j -= 4;
                }

                if(check && arr[x][a]==0)
                {
                    arr[x][a] = 12;
                    arr[x][i] = 0;
                    if(black_check())
                    {
                        arr[x][i] = 12;
                        arr[x][a] = 0;
                        return;
                    }
                    if(i==1 && x==0)
                    {
                        blong_castle = false;
                    }
                    if(i==29 && x==0)
                    {
                        bcastle = false;
                    }
                    return;
                }
            }
        }
    }

    //capture
    if((m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8') && m[1]=='x')
    {
        int a = file(m[2]);
        int x = Rank(m[3]);
        int c = arr[x][a];

        for(int i = 0;i<8;i++)
        {
            if(arr[i][a]==12)
            {
                bool check = true;
                int j = i;
                while(j<x)
                {
                    if(arr[++j][a] != 0)
                    {
                        if(!(arr[j][a]==1 || arr[j][a]==2 || arr[j][a]==3 || arr[j][a]==4 || arr[j][a]==5 || arr[j][a]==6))
                            check = false;
                        break;
                    }
                }
                while(j>x)
                {
                    if(arr[--j][a] != 0)
                    {
                        if(!(arr[j][a]==1 || arr[j][a]==2 || arr[j][a]==3 || arr[j][a]==4 || arr[j][a]==5 || arr[j][a]==6))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==x)
                {
                    arr[i][a] = 0;
                    arr[x][a] = 12;
                    if(black_check())
                    {
                        arr[i][a] = 12;
                        arr[x][a] = c;
                        return;
                    }
                    if(i==0 && a==1)
                    {
                        blong_castle = false;
                    }
                    if(i==0 && a==29)
                    {
                        bcastle = false;
                    }
                    return;
                }
            }
        }


        for(int i = 1;i<=29;i += 4)
        {
            if(arr[x][i]==12)
            {
                bool check = true;
                int j = i;
                while(j<a)
                {
                    if(arr[x][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                while(j>a)
                {
                    if(arr[x][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==1) && j==a)
                {
                    arr[x][a] = 12;
                    arr[x][i] = 0;
                    if(black_check())
                    {
                        arr[x][a] = c;
                        arr[x][i] = 12;
                        return;
                    }
                    if(i==1 && x==0)
                    {
                        blong_castle = false;
                    }
                    if(i==29 && x==0)
                    {
                        bcastle = false;
                    }
                    return;
                }
            }
        }
    }

    //Two possible captures part 1
    if((m[1]>='a' && m[1]<='h') && (m[3]>='a' && m[3]<='h') && m[2]=='x' && (m[4]>='1' && m[4]<='8'))
    {
        int b = file(m[1]);
        int a = file(m[3]);
        int x = Rank(m[4]);
        int c = arr[x][a];

        for(int i = 0;i<8;i++)
        {
            if(arr[i][a]==12 && a==b)
            {
                bool check = true;
                int j = i;
                while(j<x)
                {
                    if(arr[++j][a] != 0)
                    {
                        if(!(arr[j][a]==1 || arr[j][a]==2 || arr[j][a]==3 || arr[j][a]==4 || arr[j][a]==5 || arr[j][a]==6))
                            check = false;
                        break;
                    }
                }
                while(j>x)
                {
                    if(arr[--j][a] != 0)
                    {
                        if(!(arr[j][a]==1 || arr[j][a]==2 || arr[j][a]==3 || arr[j][a]==4 || arr[j][a]==5 || arr[j][a]==6))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==x)
                {
                    arr[i][a] = 0;
                    arr[x][a] = 12;
                    if(black_check())
                    {
                        arr[i][a] = 12;
                        arr[x][a] = c;
                        return;
                    }
                    if(i==0 && a==1)
                    {
                        blong_castle = false;
                    }
                    if(i==0 && a==29)
                    {
                        bcastle = false;
                    }
                    return;
                }
            }
        }


        for(int i = 1;i<=29;i += 4)
        {
            if(arr[x][i]==12 && i==b)
            {
                bool check = true;
                int j = i;
                while(j<a)
                {
                    if(arr[x][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                while(j>a)
                {
                    if(arr[x][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==1) && j==a)
                {
                    arr[x][a] = 12;
                    arr[x][i] = 0;
                    if(black_check())
                    {
                        arr[x][a] = c;
                        arr[x][i] = 12;
                        return;
                    }
                    if(i==1 && x==0)
                    {
                        blong_castle = false;
                    }
                    if(i==29 && x==0)
                    {
                        bcastle = false;
                    }
                    return;
                }
            }
        }
    }

    //Two possible captures part 2
    if((m[1]>='1' && m[1]<='8') && (m[3]>='a' && m[3]<='h') && m[2]=='x' && (m[4]>='1' && m[4]<='8'))
    {
        int b = Rank(m[1]);
        int a = file(m[3]);
        int x = Rank(m[4]);
        int c = arr[x][a];

        for(int i = 0;i<8;i++)
        {
            if(arr[i][a]==12 && i==b)
            {
                bool check = true;
                int j = i;
                while(j<x)
                {
                    if(arr[++j][a] != 0)
                    {
                        if(!(arr[j][a]==1 || arr[j][a]==2 || arr[j][a]==3 || arr[j][a]==4 || arr[j][a]==5 || arr[j][a]==6))
                            check = false;
                        break;
                    }
                }
                while(j>x)
                {
                    if(arr[--j][a] != 0)
                    {
                        if(!(arr[j][a]==1 || arr[j][a]==2 || arr[j][a]==3 || arr[j][a]==4 || arr[j][a]==5 || arr[j][a]==6))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==x)
                {
                    arr[i][a] = 0;
                    arr[x][a] = 12;
                    if(black_check())
                    {
                        arr[i][a] = 12;
                        arr[x][a] = c;
                        return;
                    }
                    if(i==0 && a==1)
                    {
                        blong_castle = false;
                    }
                    if(i==0 && a==29)
                    {
                        bcastle = false;
                    }
                    return;
                }
            }
        }

        for(int i = 1;i<=29;i += 4)
        {
            if(arr[x][i]==12 && x==b)
            {
                bool check = true;
                int j = i;
                while(j<a)
                {
                    if(arr[x][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                while(j>a)
                {
                    if(arr[x][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==1) && j==a)
                {
                    arr[x][a] = 12;
                    arr[x][i] = 0;
                    if(black_check())
                    {
                        arr[x][a] = c;
                        arr[x][i] = 12;
                        return;
                    }
                    if(i==1 && x==0)
                    {
                        blong_castle = false;
                    }
                    if(i==29 && x==0)
                    {
                        bcastle = false;
                    }
                    return;
                }
            }
        }
    }
}

void bishop(string m)
{
    //move
    if((m[1]>='a' && m[1]<='h') && (m[2]>='1' && m[2]<='8'))
    {
        int a = file(m[1]);
        int x = Rank(m[2]);

        int j = a;
        int i = x;

        while(i>=0 && j>=1)
        {
            if(arr[--i][--(--(--(--j)))] == 4)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i<x)
                {
                    if(arr[++i][++(++(++(++j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 4;
                    if(white_check())
                    {
                        arr[m][n] = 4;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i>=0 && j<=29)
        {
            if(arr[--i][++(++(++(++j)))] == 4)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i<x)
                {
                    if(arr[++i][--(--(--(--j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 4;
                    if(white_check())
                    {
                        arr[m][n] = 4;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i<=7 && j>=1)
        {
            if(arr[++i][--(--(--(--j)))] == 4)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i>x)
                {
                    if(arr[--i][++(++(++(++j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 4;
                    if(white_check())
                    {
                        arr[m][n] = 4;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i<=7 && j<=29)
        {
            if(arr[++i][++(++(++(++j)))] == 4)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i>x)
                {
                    if(arr[--i][--(--(--(--j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 4;
                    if(white_check())
                    {
                        arr[m][n] = 4;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }
    }

    //Two Possible moves part 1
    if((m[1]>='a' && m[1]<='h') && (m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8'))
    {
        int b = file(m[1]);
        int a = file(m[2]);
        int x = Rank(m[3]);

        int j = a;
        int i = x;

        while(i>=0 && j>=1)
        {
            if(arr[--i][--(--(--(--j)))] == 4)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i<x)
                {
                    if(arr[++i][++(++(++(++j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && n==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 4;
                    if(white_check())
                    {
                        arr[m][n] = 4;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i>=0 && j<=29)
        {
            if(arr[--i][++(++(++(++j)))] == 4)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i<x)
                {
                    if(arr[++i][--(--(--(--j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0  && n==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 4;
                    if(white_check())
                    {
                        arr[m][n] = 4;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i<=7 && j>=1)
        {
            if(arr[++i][--(--(--(--j)))] == 4)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i>x)
                {
                    if(arr[--i][++(++(++(++j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0  && n==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 4;
                    if(white_check())
                    {
                        arr[m][n] = 4;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i<=7 && j<=29)
        {
            if(arr[++i][++(++(++(++j)))] == 4)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i>x)
                {
                    if(arr[--i][--(--(--(--j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0  && n==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 4;
                    if(white_check())
                    {
                        arr[m][n] = 4;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }
    }

    //Two Possible moves part 2
    if((m[1]>='1' && m[1]<='8') && (m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8'))
    {
        int b = Rank(m[1]);
        int a = file(m[2]);
        int x = Rank(m[3]);

        int j = a;
        int i = x;

        while(i>=0 && j>=1)
        {
            if(arr[--i][--(--(--(--j)))] == 4)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i<x)
                {
                    if(arr[++i][++(++(++(++j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && m==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 4;
                    if(white_check())
                    {
                        arr[m][n] = 4;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i>=0 && j<=29)
        {
            if(arr[--i][++(++(++(++j)))] == 4)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i<x)
                {
                    if(arr[++i][--(--(--(--j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0  && m==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 4;
                    if(white_check())
                    {
                        arr[m][n] = 4;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i<=7 && j>=1)
        {
            if(arr[++i][--(--(--(--j)))] == 4)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i>x)
                {
                    if(arr[--i][++(++(++(++j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0  && m==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 4;
                    if(white_check())
                    {
                        arr[m][n] = 4;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i<=7 && j<=29)
        {
            if(arr[++i][++(++(++(++j)))] == 4)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i>x)
                {
                    if(arr[--i][--(--(--(--j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0  && m==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 4;
                    if(white_check())
                    {
                        arr[m][n] = 4;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }
    }

    //capture
    if((m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8') && m[1]=='x')
    {
        int a = file(m[2]);
        int x = Rank(m[3]);
        int c = arr[x][a];

        int j = a;
        int i = x;

        while(i>=0 && j>=1)
        {
            if(arr[--i][--(--(--(--j)))] == 4)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i<x)
                {
                    if(arr[++i][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 4;
                    if(white_check())
                    {
                        arr[m][n] = 4;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }
        j = a;
        i = x;

        while(i>=0 && j<=29)
        {
            if(arr[--i][++(++(++(++j)))] == 4)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i<x)
                {
                    if(arr[++i][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 4;
                    if(white_check())
                    {
                        arr[m][n] = 4;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }

        j = a;
        i = x;

        while(i<=7 && j>=1)
        {
            if(arr[++i][--(--(--(--j)))] == 4)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i>x)
                {
                    if(arr[--i][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 4;
                    if(white_check())
                    {
                        arr[m][n] = 4;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }

        j = a;
        i = x;

        while(i<=7 && j<=29)
        {
            if(arr[++i][++(++(++(++j)))] == 4)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i>x)
                {
                    if(arr[--i][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 4;
                    if(white_check())
                    {
                        arr[m][n] = 4;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }
    }

     //two possibel captures part 1
    if((m[1]>='a' && m[1]<='h') && (m[3]>='a' && m[3]<='h') && m[2]=='x' && (m[4]>='1' && m[4]<='8'))
    {
        int b = file(m[1]);
        int a = file(m[3]);
        int x = Rank(m[4]);
        int c = arr[x][a];

        int j = a;
        int i = x;

        while(i>=0 && j>=1)
        {
            if(arr[--i][--(--(--(--j)))] == 4)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i<x)
                {
                    if(arr[++i][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && n==b && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 4;
                    if(white_check())
                    {
                        arr[m][n] = 4;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }
        j = a;
        i = x;

        while(i>=0 && j<=29)
        {
            if(arr[--i][++(++(++(++j)))] == 4)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i<x)
                {
                    if(arr[++i][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && n==b && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 4;
                    if(white_check())
                    {
                        arr[m][n] = 4;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }

        j = a;
        i = x;

        while(i<=7 && j>=1)
        {
            if(arr[++i][--(--(--(--j)))] == 4)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i>x)
                {
                    if(arr[--i][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && n==b && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 4;
                    if(white_check())
                    {
                        arr[m][n] = 4;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }

        j = a;
        i = x;

        while(i<=7 && j<=29)
        {
            if(arr[++i][++(++(++(++j)))] == 4)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i>x)
                {
                    if(arr[--i][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && n==b && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 4;
                    if(white_check())
                    {
                        arr[m][n] = 4;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }
    }

     //two possibel captures part 2
    if((m[1]>='1' && m[1]<='8') && (m[3]>='a' && m[3]<='h') && m[2]=='x' && (m[4]>='1' && m[4]<='8'))
    {
        int b = Rank(m[1]);
        int a = file(m[3]);
        int x = Rank(m[4]);
        int c = arr[x][a];

        int j = a;
        int i = x;

        while(i>=0 && j>=1)
        {
            if(arr[--i][--(--(--(--j)))] == 4)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i<x)
                {
                    if(arr[++i][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && m==b && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 4;
                    if(white_check())
                    {
                        arr[m][n] = 4;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }
        j = a;
        i = x;

        while(i>=0 && j<=29)
        {
            if(arr[--i][++(++(++(++j)))] == 4)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i<x)
                {
                    if(arr[++i][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && m==b && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 4;
                    if(white_check())
                    {
                        arr[m][n] = 4;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }

        j = a;
        i = x;

        while(i<=7 && j>=1)
        {
            if(arr[++i][--(--(--(--j)))] == 4)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i>x)
                {
                    if(arr[--i][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && m==b && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 4;
                    if(white_check())
                    {
                        arr[m][n] = 4;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }

        j = a;
        i = x;

        while(i<=7 && j<=29)
        {
            if(arr[++i][++(++(++(++j)))] == 4)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i>x)
                {
                    if(arr[--i][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && m==b && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 4;
                    if(white_check())
                    {
                        arr[m][n] = 4;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }
    }
}

void bbishop(string m)
{
    //move
    if((m[1]>='a' && m[1]<='h') && (m[2]>='1' && m[2]<='8'))
    {
        int a = file(m[1]);
        int x = Rank(m[2]);

        int j = a;
        int i = x;

        while(i>=0 && j>=1)
        {
            if(arr[--i][--(--(--(--j)))] == 14)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i<x)
                {
                    if(arr[++i][++(++(++(++j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 14;
                    if(black_check())
                    {
                        arr[m][n] = 14;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i>=0 && j<=29)
        {
            if(arr[--i][++(++(++(++j)))] == 14)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i<x)
                {
                    if(arr[++i][--(--(--(--j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 14;
                    if(black_check())
                    {
                        arr[m][n] = 14;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i<=7 && j>=1)
        {
            if(arr[++i][--(--(--(--j)))] == 14)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i>x)
                {
                    cout<<i<<j<<endl;
                    if(arr[--i][++(++(++(++j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 14;
                    if(black_check())
                    {
                        arr[m][n] = 14;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i<=7 && j<=29)
        {
            if(arr[++i][++(++(++(++j)))] == 14)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i>x)
                {
                    if(arr[--i][--(--(--(--j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 14;
                    if(black_check())
                    {
                        arr[m][n] = 14;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }
    }

    //Two possible moves part 1
    if((m[1]>='a' && m[1]<='h') && (m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8'))
    {
        int b = file(m[1]);
        int a = file(m[2]);
        int x = Rank(m[3]);

        int j = a;
        int i = x;

        while(i>=0 && j>=1)
        {
            if(arr[--i][--(--(--(--j)))] == 14)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i<x)
                {
                    if(arr[++i][++(++(++(++j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && n==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 14;
                    if(black_check())
                    {
                        arr[m][n] = 14;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i>=0 && j<=29)
        {
            if(arr[--i][++(++(++(++j)))] == 14)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i<x)
                {
                    if(arr[++i][--(--(--(--j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && n==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 14;
                    if(black_check())
                    {
                        arr[m][n] = 14;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i<=7 && j>=1)
        {
            if(arr[++i][--(--(--(--j)))] == 14)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i>x)
                {
                    cout<<i<<j<<endl;
                    if(arr[--i][++(++(++(++j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && n==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 14;
                    if(black_check())
                    {
                        arr[m][n] = 14;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i<=7 && j<=29)
        {
            if(arr[++i][++(++(++(++j)))] == 14)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i>x)
                {
                    if(arr[--i][--(--(--(--j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && n==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 14;
                    if(black_check())
                    {
                        arr[m][n] = 14;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }
    }

    //Two possible moves part 2
    if((m[1]>='1' && m[1]<='8') && (m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8'))
    {
        int b = Rank(m[1]);
        int a = file(m[2]);
        int x = Rank(m[3]);

        int j = a;
        int i = x;

        while(i>=0 && j>=1)
        {
            if(arr[--i][--(--(--(--j)))] == 14)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i<x)
                {
                    if(arr[++i][++(++(++(++j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && m==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 14;
                    if(black_check())
                    {
                        arr[m][n] = 14;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i>=0 && j<=29)
        {
            if(arr[--i][++(++(++(++j)))] == 14)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i<x)
                {
                    if(arr[++i][--(--(--(--j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && m==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 14;
                    if(black_check())
                    {
                        arr[m][n] = 14;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i<=7 && j>=1)
        {
            if(arr[++i][--(--(--(--j)))] == 14)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i>x)
                {
                    cout<<i<<j<<endl;
                    if(arr[--i][++(++(++(++j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && m==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 14;
                    if(black_check())
                    {
                        arr[m][n] = 14;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i<=7 && j<=29)
        {
            if(arr[++i][++(++(++(++j)))] == 14)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i>x)
                {
                    if(arr[--i][--(--(--(--j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && m==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 14;
                    if(black_check())
                    {
                        arr[m][n] = 14;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }
    }

    //capture
    if((m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8') && m[1]=='x')
    {
        int a = file(m[2]);
        int x = Rank(m[3]);
        int c = arr[x][a];

        int j = a;
        int i = x;

        while(i>=0 && j>=1)
        {
            if(arr[--i][--(--(--(--j)))] == 14)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i<x)
                {
                    if(arr[++i][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 14;
                    if(black_check())
                    {
                        arr[m][n] = 14;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }
        j = a;
        i = x;

        while(i>=0 && j<=29)
        {
            if(arr[--i][++(++(++(++j)))] == 14)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i<x)
                {
                    if(arr[++i][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 14;
                    if(black_check())
                    {
                        arr[m][n] = 14;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }

        j = a;
        i = x;

        while(i<=7 && j>=1)
        {
            if(arr[++i][--(--(--(--j)))] == 14)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i>x)
                {
                    if(arr[--i][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 14;
                    if(black_check())
                    {
                        arr[m][n] = 14;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }

        j = a;
        i = x;

        while(i<=7 && j<=29)
        {
            if(arr[++i][++(++(++(++j)))] == 14)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i>x)
                {
                    if(arr[--i][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 14;
                    if(black_check())
                    {
                        arr[m][n] = 14;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }
    }

    //Two possible capture part 1
    if((m[1]>='a' && m[1]<='h') && (m[3]>='a' && m[3]<='h') && m[2]=='x' && (m[4]>='1' && m[4]<='8'))
    {
        int b = file(m[1]);
        int a = file(m[3]);
        int x = Rank(m[4]);
        int c = arr[x][a];

        int j = a;
        int i = x;

        while(i>=0 && j>=1)
        {
            if(arr[--i][--(--(--(--j)))] == 14)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i<x)
                {
                    if(arr[++i][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && n==b && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 14;
                    if(black_check())
                    {
                        arr[m][n] = 14;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }
        j = a;
        i = x;

        while(i>=0 && j<=29)
        {
            if(arr[--i][++(++(++(++j)))] == 14)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i<x)
                {
                    if(arr[++i][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && n==b && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 14;
                    if(black_check())
                    {
                        arr[m][n] = 14;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }

        j = a;
        i = x;

        while(i<=7 && j>=1)
        {
            if(arr[++i][--(--(--(--j)))] == 14)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i>x)
                {
                    if(arr[--i][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && n==b && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 14;
                    if(black_check())
                    {
                        arr[m][n] = 14;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }

        j = a;
        i = x;

        while(i<=7 && j<=29)
        {
            if(arr[++i][++(++(++(++j)))] == 14)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i>x)
                {
                    if(arr[--i][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && n==b && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 14;
                    if(black_check())
                    {
                        arr[m][n] = 14;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }
    }

    //Two possible capture part 2
    if((m[1]>='1' && m[1]<='h') && (m[3]>='8' && m[3]<='h') && m[2]=='x' && (m[4]>='1' && m[4]<='8'))
    {
        int b = Rank(m[1]);
        int a = file(m[3]);
        int x = Rank(m[4]);
        int c = arr[x][a];

        int j = a;
        int i = x;

        while(i>=0 && j>=1)
        {
            if(arr[--i][--(--(--(--j)))] == 14)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i<x)
                {
                    if(arr[++i][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && m==b && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 14;
                    if(black_check())
                    {
                        arr[m][n] = 14;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }
        j = a;
        i = x;

        while(i>=0 && j<=29)
        {
            if(arr[--i][++(++(++(++j)))] == 14)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i<x)
                {
                    if(arr[++i][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && m==b && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 14;
                    if(black_check())
                    {
                        arr[m][n] = 14;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }

        j = a;
        i = x;

        while(i<=7 && j>=1)
        {
            if(arr[++i][--(--(--(--j)))] == 14)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i>x)
                {
                    if(arr[--i][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && m==b && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 14;
                    if(black_check())
                    {
                        arr[m][n] = 14;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }

        j = a;
        i = x;

        while(i<=7 && j<=29)
        {
            if(arr[++i][++(++(++(++j)))] == 14)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i>x)
                {
                    if(arr[--i][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && m==b && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 14;
                    if(black_check())
                    {
                        arr[m][n] = 14;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }
    }
}

void queen(string m)
{
    //move
    //horizontal and vertical
    if((m[1]>='a' && m[1]<='h') && (m[2]>='1' && m[2]<='8'))
    {
        int a = file(m[1]);
        int x = Rank(m[2]);

        for(int i = 0;i<8;i++)
        {
            if(arr[i][a]==5)
            {
                bool check = true;
                int j = i;
                while(j<x)
                {
                    if(arr[++j][a] != 0)
                    {
                        check = false;
                        break;
                    }
                }
                while(j>x)
                {
                    if(arr[--j][a] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[i][a] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[i][a] = 5;
                        arr[x][a] = 0;
                    }
                    return;
                }
            }
        }


        for(int i = 1;i<=29;i += 4)
        {
            if(arr[x][i]==5)
            {
                bool check = true;
                int j = i;
                while(j<a)
                {
                    if(arr[x][j+4] != 0)
                    {
                        check = false;
                        break;
                    }
                    j += 4;
                }
                while(j>a)
                {
                    if(arr[x][j-4] != 0)
                    {
                        check = false;
                        break;
                    }
                    j -= 4;
                }

                if(check && arr[x][a]==0)
                {
                    arr[x][a] = 5;
                    arr[x][i] = 0;
                    if(white_check())
                    {
                        arr[x][i] = 5;
                        arr[x][a] = 0;
                    }
                    return;
                }
            }
        }

        //diagonal
        int j = a;
        int i = x;

        while(i>=0 && j>=1)
        {
            if(arr[--i][--(--(--(--j)))] == 5)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i<x)
                {
                    if(arr[++i][++(++(++(++j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[m][n] = 5;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i>=0 && j<=29)
        {
            if(arr[--i][++(++(++(++j)))] == 5)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i<x)
                {
                    if(arr[++i][--(--(--(--j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[m][n] = 5;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i<=7 && j>=1)
        {
            if(arr[++i][--(--(--(--j)))] == 5)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i>x)
                {
                    cout<<i<<j<<endl;
                    if(arr[--i][++(++(++(++j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[m][n] = 5;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i<=7 && j<=29)
        {
            if(arr[++i][++(++(++(++j)))] == 5)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i>x)
                {
                    if(arr[--i][--(--(--(--j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[m][n] = 5;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }
    }

    //Two possible moves part 1
    if((m[1]>='a' && m[1]<='h') && (m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8'))
    {
        int b = file(m[1]);
        int a = file(m[2]);
        int x = Rank(m[3]);

        for(int i = 0;i<8;i++)
        {
            if(arr[i][a]==5 && a==b)
            {
                bool check = true;
                int j = i;
                while(j<x)
                {
                    if(arr[++j][a] != 0)
                    {
                        check = false;
                        break;
                    }
                }
                while(j>x)
                {
                    if(arr[--j][a] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[i][a] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[i][a] = 5;
                        arr[x][a] = 0;
                    }
                    return;
                }
            }
        }


        for(int i = 1;i<=29;i += 4)
        {
            if(arr[x][i]==5 && i==b)
            {
                bool check = true;
                int j = i;
                while(j<a)
                {
                    if(arr[x][j+4] != 0)
                    {
                        check = false;
                        break;
                    }
                    j += 4;
                }
                while(j>a)
                {
                    if(arr[x][j-4] != 0)
                    {
                        check = false;
                        break;
                    }
                    j -= 4;
                }

                if(check && arr[x][a]==0)
                {
                    arr[x][a] = 5;
                    arr[x][i] = 0;
                    if(white_check())
                    {
                        arr[x][i] = 5;
                        arr[x][a] = 0;
                    }
                    return;
                }
            }
        }

        //diagonal
        int j = a;
        int i = x;

        while(i>=0 && j>=1)
        {
            if(arr[--i][--(--(--(--j)))] == 5)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i<x)
                {
                    if(arr[++i][++(++(++(++j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && n==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[m][n] = 5;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i>=0 && j<=29)
        {
            if(arr[--i][++(++(++(++j)))] == 5)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i<x)
                {
                    if(arr[++i][--(--(--(--j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && n==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[m][n] = 5;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i<=7 && j>=1)
        {
            if(arr[++i][--(--(--(--j)))] == 5)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i>x)
                {
                    cout<<i<<j<<endl;
                    if(arr[--i][++(++(++(++j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && n==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[m][n] = 5;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i<=7 && j<=29)
        {
            if(arr[++i][++(++(++(++j)))] == 5)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i>x)
                {
                    if(arr[--i][--(--(--(--j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && n==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[m][n] = 5;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }
    }

    //Two possible moves part 2
    if((m[1]>='1' && m[1]<='8') && (m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8'))
    {
        int b = Rank(m[1]);
        int a = file(m[2]);
        int x = Rank(m[3]);

        for(int i = 0;i<8;i++)
        {
            if(arr[i][a]==5 && i==b)
            {
                bool check = true;
                int j = i;
                while(j<x)
                {
                    if(arr[++j][a] != 0)
                    {
                        check = false;
                        break;
                    }
                }
                while(j>x)
                {
                    if(arr[--j][a] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[i][a] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[i][a] = 5;
                        arr[x][a] = 0;
                    }
                    return;
                }
            }
        }


        for(int i = 1;i<=29;i += 4)
        {
            if(arr[x][i]==5 && x==b)
            {
                bool check = true;
                int j = i;
                while(j<a)
                {
                    if(arr[x][j+4] != 0)
                    {
                        check = false;
                        break;
                    }
                    j += 4;
                }
                while(j>a)
                {
                    if(arr[x][j-4] != 0)
                    {
                        check = false;
                        break;
                    }
                    j -= 4;
                }

                if(check && arr[x][a]==0)
                {
                    arr[x][a] = 5;
                    arr[x][i] = 0;
                    if(white_check())
                    {
                        arr[x][i] = 5;
                        arr[x][a] = 0;
                    }
                    return;
                }
            }
        }

        //diagonal
        int j = a;
        int i = x;

        while(i>=0 && j>=1)
        {
            if(arr[--i][--(--(--(--j)))] == 5)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i<x)
                {
                    if(arr[++i][++(++(++(++j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && m==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[m][n] = 5;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i>=0 && j<=29)
        {
            if(arr[--i][++(++(++(++j)))] == 5)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i<x)
                {
                    if(arr[++i][--(--(--(--j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && m==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[m][n] = 5;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i<=7 && j>=1)
        {
            if(arr[++i][--(--(--(--j)))] == 5)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i>x)
                {
                    cout<<i<<j<<endl;
                    if(arr[--i][++(++(++(++j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && m==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[m][n] = 5;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i<=7 && j<=29)
        {
            if(arr[++i][++(++(++(++j)))] == 5)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i>x)
                {
                    if(arr[--i][--(--(--(--j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && m==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[m][n] = 5;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }
    }

    //capture
    if((m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8') && m[1]=='x')
    {
        int a = file(m[2]);
        int x = Rank(m[3]);
        int c = arr[x][a];

        //vertical and horizontal
        for(int i = 0;i<8;i++)
        {
            if(arr[i][a]==5)
            {
                bool check = true;
                int j = i;
                while(j<x)
                {
                    if(arr[++j][a] != 0)
                    {
                        if(!(arr[j][a]==11 || arr[j][a]==12 || arr[j][a]==13 || arr[j][a]==14 || arr[j][a]==15 || arr[j][a]==16))
                            check = false;
                        break;
                    }
                }
                while(j>x)
                {
                    if(arr[--j][a] != 0)
                    {
                        if(!(arr[j][a]==11 || arr[j][a]==12 || arr[j][a]==13 || arr[j][a]==14 || arr[j][a]==15 || arr[j][a]==16))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==x)
                {
                    arr[i][a] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[i][a] = 5;
                        arr[x][a] = c;
                    }
                    return;
                }
            }
        }


        for(int i = 1;i<=29;i += 4)
        {
            if(arr[x][i]==5)
            {
                bool check = true;
                int j = i;
                while(j<a)
                {
                    if(arr[x][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                while(j>a)
                {
                    if(arr[x][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a)
                {
                    arr[x][a] = 5;
                    arr[x][i] = 0;
                    if(white_check())
                    {
                        arr[x][i] = 5;
                        arr[x][a] = c;
                    }
                    return;
                }
            }
        }

        //diagonal
        int j = a;
        int i = x;

        while(i>=0 && j>=1)
        {
            if(arr[--i][--(--(--(--j)))] == 5)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i<x)
                {
                    if(arr[++i][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[m][n] = 5;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }
        j = a;
        i = x;

        while(i>=0 && j<=29)
        {
            if(arr[--i][++(++(++(++j)))] == 5)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i<x)
                {
                    if(arr[++i][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[m][n] = 5;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }

        j = a;
        i = x;

        while(i<=7 && j>=1)
        {
            if(arr[++i][--(--(--(--j)))] == 5)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i>x)
                {
                    if(arr[--i][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[m][n] = 5;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }

        j = a;
        i = x;

        while(i<=7 && j<=29)
        {
            if(arr[++i][++(++(++(++j)))] == 5)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i>x)
                {
                    if(arr[--i][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[m][n] = 5;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }
    }

    //Two possible captures part 1
    if((m[1]>='a' && m[1]<='h') && (m[3]>='a' && m[3]<='h') && m[2]=='x' && (m[4]>='1' && m[4]<='8'))
    {
        int b = file(m[1]);
        int a = file(m[3]);
        int x = Rank(m[4]);
        int c = arr[x][a];

        //vertical and horizontal
        for(int i = 0;i<8;i++)
        {
            if(arr[i][a]==5 && a==b)
            {
                bool check = true;
                int j = i;
                while(j<x)
                {
                    if(arr[++j][a] != 0)
                    {
                        if(!(arr[j][a]==11 || arr[j][a]==12 || arr[j][a]==13 || arr[j][a]==14 || arr[j][a]==15 || arr[j][a]==16))
                            check = false;
                        break;
                    }
                }
                while(j>x)
                {
                    if(arr[--j][a] != 0)
                    {
                        if(!(arr[j][a]==11 || arr[j][a]==12 || arr[j][a]==13 || arr[j][a]==14 || arr[j][a]==15 || arr[j][a]==16))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==x)
                {
                    arr[i][a] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[i][a] = 5;
                        arr[x][a] = c;
                    }
                    return;
                }
            }
        }


        for(int i = 1;i<=29;i += 4)
        {
            if(arr[x][i]==5 && i==b)
            {
                bool check = true;
                int j = i;
                while(j<a)
                {
                    if(arr[x][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                while(j>a)
                {
                    if(arr[x][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a)
                {
                    arr[x][a] = 5;
                    arr[x][i] = 0;
                    if(white_check())
                    {
                        arr[x][i] = 5;
                        arr[x][a] = c;
                    }
                    return;
                }
            }
        }

        //diagonal
        int j = a;
        int i = x;

        while(i>=0 && j>=1)
        {
            if(arr[--i][--(--(--(--j)))] == 5)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i<x)
                {
                    if(arr[++i][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && n==b && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[m][n] = 5;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }
        j = a;
        i = x;

        while(i>=0 && j<=29)
        {
            if(arr[--i][++(++(++(++j)))] == 5)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i<x)
                {
                    if(arr[++i][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && n==b && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[m][n] = 5;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }

        j = a;
        i = x;

        while(i<=7 && j>=1)
        {
            if(arr[++i][--(--(--(--j)))] == 5)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i>x)
                {
                    if(arr[--i][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && n==b && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[m][n] = 5;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }

        j = a;
        i = x;

        while(i<=7 && j<=29)
        {
            if(arr[++i][++(++(++(++j)))] == 5)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i>x)
                {
                    if(arr[--i][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && n==b && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[m][n] = 5;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }
    }

    //Two possible captures part 1
    if((m[1]>='1' && m[1]<='8') && (m[3]>='a' && m[3]<='h') && m[2]=='x' && (m[4]>='1' && m[4]<='8'))
    {
        int b = Rank(m[1]);
        int a = file(m[3]);
        int x = Rank(m[4]);
        int c = arr[x][a];

        //vertical and horizontal
        for(int i = 0;i<8;i++)
        {
            if(arr[i][a]==5 && i==b)
            {
                bool check = true;
                int j = i;
                while(j<x)
                {
                    if(arr[++j][a] != 0)
                    {
                        if(!(arr[j][a]==11 || arr[j][a]==12 || arr[j][a]==13 || arr[j][a]==14 || arr[j][a]==15 || arr[j][a]==16))
                            check = false;
                        break;
                    }
                }
                while(j>x)
                {
                    if(arr[--j][a] != 0)
                    {
                        if(!(arr[j][a]==11 || arr[j][a]==12 || arr[j][a]==13 || arr[j][a]==14 || arr[j][a]==15 || arr[j][a]==16))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==x)
                {
                    arr[i][a] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[i][a] = 5;
                        arr[x][a] = c;
                    }
                    return;
                }
            }
        }

        for(int i = 1;i<=29;i += 4)
        {
            if(arr[x][i]==5 && x==b)
            {
                bool check = true;
                int j = i;
                while(j<a)
                {
                    if(arr[x][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                while(j>a)
                {
                    if(arr[x][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a)
                {
                    arr[x][a] = 5;
                    arr[x][i] = 0;
                    if(white_check())
                    {
                        arr[x][i] = 5;
                        arr[x][a] = c;
                    }
                    return;
                }
            }
        }

        //diagonal
        int j = a;
        int i = x;

        while(i>=0 && j>=1)
        {
            if(arr[--i][--(--(--(--j)))] == 5)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i<x)
                {
                    if(arr[++i][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && m==b && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[m][n] = 5;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }
        j = a;
        i = x;

        while(i>=0 && j<=29)
        {
            if(arr[--i][++(++(++(++j)))] == 5)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i<x)
                {
                    if(arr[++i][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && m==b && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[m][n] = 5;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }

        j = a;
        i = x;

        while(i<=7 && j>=1)
        {
            if(arr[++i][--(--(--(--j)))] == 5)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i>x)
                {
                    if(arr[--i][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && m==b && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[m][n] = 5;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }

        j = a;
        i = x;

        while(i<=7 && j<=29)
        {
            if(arr[++i][++(++(++(++j)))] == 5)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i>x)
                {
                    if(arr[--i][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==11 || arr[x][j]==12 || arr[x][j]==13 || arr[x][j]==14 || arr[x][j]==15 || arr[x][j]==16))
                            check = false;
                        break;
                    }
                }

                if(check && m==b && (arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 5;
                    if(white_check())
                    {
                        arr[m][n] = 5;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }
    }
}

void bqueen(string m)
{
    //move
    //horizontal and vertical
    if((m[1]>='a' && m[1]<='h') && (m[2]>='1' && m[2]<='8'))
    {
        int a = file(m[1]);
        int x = Rank(m[2]);

        for(int i = 0;i<8;i++)
        {
            if(arr[i][a]==15)
            {
                bool check = true;
                int j = i;
                while(j<x)
                {
                    if(arr[++j][a] != 0)
                    {
                        check = false;
                        break;
                    }
                }
                while(j>x)
                {
                    if(arr[--j][a] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[i][a] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[i][a] = 15;
                        arr[x][a] = 0;
                    }
                    return;
                }
            }
        }


        for(int i = 1;i<=29;i += 4)
        {
            if(arr[x][i]==15)
            {
                bool check = true;
                int j = i;
                while(j<a)
                {
                    if(arr[x][j+4] != 0)
                    {
                        check = false;
                        break;
                    }
                    j += 4;
                }
                while(j>a)
                {
                    if(arr[x][j-4] != 0)
                    {
                        check = false;
                        break;
                    }
                    j -= 4;
                }

                if(check && arr[x][a]==0)
                {
                    arr[x][a] = 15;
                    arr[x][i] = 0;
                    if(black_check())
                    {
                        arr[x][i] = 15;
                        arr[x][a] = 0;
                    }
                    return;
                }
            }
        }

        //diagonal
        int j = a;
        int i = x;

        while(i>=0 && j>=1)
        {
            if(arr[--i][--(--(--(--j)))] == 15)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i<x)
                {
                    if(arr[++i][++(++(++(++j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[m][n] = 15;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i>=0 && j<=29)
        {
            if(arr[--i][++(++(++(++j)))] == 15)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i<x)
                {
                    if(arr[++i][--(--(--(--j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[m][n] = 15;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i<=7 && j>=1)
        {
            if(arr[++i][--(--(--(--j)))] == 15)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i>x)
                {
                    cout<<i<<j<<endl;
                    if(arr[--i][++(++(++(++j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[m][n] = 15;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i<=7 && j<=29)
        {
            if(arr[++i][++(++(++(++j)))] == 15)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i>x)
                {
                    if(arr[--i][--(--(--(--j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[m][n] = 15;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }
    }

    //Two possible moves part 1
    if((m[1]>='a' && m[1]<='h') && (m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8'))
    {
        int b = file(m[1]);
        int a = file(m[2]);
        int x = Rank(m[3]);

        for(int i = 0;i<8;i++)
        {
            if(arr[i][a]==15 && a==b)
            {
                bool check = true;
                int j = i;
                while(j<x)
                {
                    if(arr[++j][a] != 0)
                    {
                        check = false;
                        break;
                    }
                }
                while(j>x)
                {
                    if(arr[--j][a] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[i][a] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[i][a] = 15;
                        arr[x][a] = 0;
                    }
                    return;
                }
            }
        }


        for(int i = 1;i<=29;i += 4)
        {
            if(arr[x][i]==15 && i==b)
            {
                bool check = true;
                int j = i;
                while(j<a)
                {
                    if(arr[x][j+4] != 0)
                    {
                        check = false;
                        break;
                    }
                    j += 4;
                }
                while(j>a)
                {
                    if(arr[x][j-4] != 0)
                    {
                        check = false;
                        break;
                    }
                    j -= 4;
                }

                if(check && arr[x][a]==0)
                {
                    arr[x][a] = 15;
                    arr[x][i] = 0;
                    if(black_check())
                    {
                        arr[x][i] = 15;
                        arr[x][a] = 0;
                    }
                    return;
                }
            }
        }

        //diagonal
        int j = a;
        int i = x;

        while(i>=0 && j>=1)
        {
            if(arr[--i][--(--(--(--j)))] == 15)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i<x)
                {
                    if(arr[++i][++(++(++(++j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && n==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[m][n] = 15;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i>=0 && j<=29)
        {
            if(arr[--i][++(++(++(++j)))] == 15)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i<x)
                {
                    if(arr[++i][--(--(--(--j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && n==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[m][n] = 15;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i<=7 && j>=1)
        {
            if(arr[++i][--(--(--(--j)))] == 15)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i>x)
                {
                    cout<<i<<j<<endl;
                    if(arr[--i][++(++(++(++j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && n==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[m][n] = 15;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i<=7 && j<=29)
        {
            if(arr[++i][++(++(++(++j)))] == 15)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i>x)
                {
                    if(arr[--i][--(--(--(--j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && n==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[m][n] = 15;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }
    }

    //Two possible moves part 2
    if((m[1]>='1' && m[1]<='8') && (m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8'))
    {
        int b = Rank(m[1]);
        int a = file(m[2]);
        int x = Rank(m[3]);

        for(int i = 0;i<8;i++)
        {
            if(arr[i][a]==15 && i==b)
            {
                bool check = true;
                int j = i;
                while(j<x)
                {
                    if(arr[++j][a] != 0)
                    {
                        check = false;
                        break;
                    }
                }
                while(j>x)
                {
                    if(arr[--j][a] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0)
                {
                    arr[i][a] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[i][a] = 15;
                        arr[x][a] = 0;
                    }
                    return;
                }
            }
        }


        for(int i = 1;i<=29;i += 4)
        {
            if(arr[x][i]==15 && x==b)
            {
                bool check = true;
                int j = i;
                while(j<a)
                {
                    if(arr[x][j+4] != 0)
                    {
                        check = false;
                        break;
                    }
                    j += 4;
                }
                while(j>a)
                {
                    if(arr[x][j-4] != 0)
                    {
                        check = false;
                        break;
                    }
                    j -= 4;
                }

                if(check && arr[x][a]==0)
                {
                    arr[x][a] = 15;
                    arr[x][i] = 0;
                    if(black_check())
                    {
                        arr[x][i] = 15;
                        arr[x][a] = 0;
                    }
                    return;
                }
            }
        }

        //diagonal
        int j = a;
        int i = x;

        while(i>=0 && j>=1)
        {
            if(arr[--i][--(--(--(--j)))] == 15)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i<x)
                {
                    if(arr[++i][++(++(++(++j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && m==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[m][n] = 15;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i>=0 && j<=29)
        {
            if(arr[--i][++(++(++(++j)))] == 15)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i<x)
                {
                    if(arr[++i][--(--(--(--j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && m==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[m][n] = 15;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i<=7 && j>=1)
        {
            if(arr[++i][--(--(--(--j)))] == 15)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i>x)
                {
                    cout<<i<<j<<endl;
                    if(arr[--i][++(++(++(++j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && m==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[m][n] = 15;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }

        i = x;
        j = a;
        while(i<=7 && j<=29)
        {
            if(arr[++i][++(++(++(++j)))] == 15)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i>x)
                {
                    if(arr[--i][--(--(--(--j)))] != 0)
                    {
                        check = false;
                        break;
                    }
                }

                if(check && arr[x][a]==0 && m==b)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[m][n] = 15;
                        arr[x][a] = 0;
                    }
                    return;
                }
                break;
            }
        }
    }

    //capture
    if((m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8') && m[1]=='x')
    {
        int a = file(m[2]);
        int x = Rank(m[3]);
        int c = arr[x][a];

        //vertical and horizontal
        for(int i = 0;i<8;i++)
        {
            if(arr[i][a]==15)
            {
                bool check = true;
                int j = i;
                while(j<x)
                {
                    if(arr[++j][a] != 0)
                    {
                        if(!(arr[j][a]==1 || arr[j][a]==2 || arr[j][a]==3 || arr[j][a]==4 || arr[j][a]==5 || arr[j][a]==6))
                            check = false;
                        break;
                    }
                }
                while(j>x)
                {
                    if(arr[--j][a] != 0)
                    {
                        if(!(arr[j][a]==1 || arr[j][a]==2 || arr[j][a]==3 || arr[j][a]==4 || arr[j][a]==5 || arr[j][a]==6))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==x)
                {
                    arr[i][a] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[i][a] = 15;
                        arr[x][a] = c;
                    }
                    return;
                }
            }
        }


        for(int i = 1;i<=29;i += 4)
        {
            if(arr[x][i]==15)
            {
                bool check = true;
                int j = i;
                while(j<a)
                {
                    if(arr[x][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                while(j>a)
                {
                    if(arr[x][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==a)
                {
                    arr[x][a] = 15;
                    arr[x][i] = 0;
                    if(black_check())
                    {
                        arr[x][i] = 15;
                        arr[x][a] = c;
                    }
                    return;
                }
            }
        }

        //diagonal
        int j = a;
        int i = x;

        while(i>=0 && j>=1)
        {
            if(arr[--i][--(--(--(--j)))] == 15)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i<x)
                {
                    if(arr[++i][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[m][n] = 15;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }
        j = a;
        i = x;

        while(i>=0 && j<=29)
        {
            if(arr[--i][++(++(++(++j)))] == 15)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i<x)
                {
                    if(arr[++i][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[m][n] = 15;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }

        j = a;
        i = x;

        while(i<=7 && j>=1)
        {
            if(arr[++i][--(--(--(--j)))] == 15)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i>x)
                {
                    if(arr[--i][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[m][n] = 15;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }

        j = a;
        i = x;

        while(i<=7 && j<=29)
        {
            if(arr[++i][++(++(++(++j)))] == 15)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i>x)
                {
                    if(arr[--i][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[m][n] = 15;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }
    }

    //Two possible captures part 1
    if((m[1]>='a' && m[1]<='h') && (m[3]>='a' && m[3]<='h') && m[2]=='x' && (m[4]>='1' && m[4]<='8'))
    {
        int b = file(m[1]);
        int a = file(m[3]);
        int x = Rank(m[4]);
        int c = arr[x][a];

        //vertical and horizontal
        for(int i = 0;i<8;i++)
        {
            if(arr[i][a]==15 && a==b)
            {
                bool check = true;
                int j = i;
                while(j<x)
                {
                    if(arr[++j][a] != 0)
                    {
                        if(!(arr[j][a]==1 || arr[j][a]==2 || arr[j][a]==3 || arr[j][a]==4 || arr[j][a]==5 || arr[j][a]==6))
                            check = false;
                        break;
                    }
                }
                while(j>x)
                {
                    if(arr[--j][a] != 0)
                    {
                        if(!(arr[j][a]==1 || arr[j][a]==2 || arr[j][a]==3 || arr[j][a]==4 || arr[j][a]==5 || arr[j][a]==6))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==x)
                {
                    arr[i][a] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[i][a] = 15;
                        arr[x][a] = c;
                    }
                    return;
                }
            }
        }


        for(int i = 1;i<=29;i += 4)
        {
            if(arr[x][i]==15 && i==b)
            {
                bool check = true;
                int j = i;
                while(j<a)
                {
                    if(arr[x][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                while(j>a)
                {
                    if(arr[x][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==a)
                {
                    arr[x][a] = 15;
                    arr[x][i] = 0;
                    if(black_check())
                    {
                        arr[x][i] = 15;
                        arr[x][a] = c;
                    }
                    return;
                }
            }
        }

        //diagonal
        int j = a;
        int i = x;

        while(i>=0 && j>=1)
        {
            if(arr[--i][--(--(--(--j)))] == 15)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i<x)
                {
                    if(arr[++i][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && n==b && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[m][n] = 15;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }
        j = a;
        i = x;

        while(i>=0 && j<=29)
        {
            if(arr[--i][++(++(++(++j)))] == 15)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i<x)
                {
                    if(arr[++i][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && n==b && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[m][n] = 15;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }

        j = a;
        i = x;

        while(i<=7 && j>=1)
        {
            if(arr[++i][--(--(--(--j)))] == 15)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i>x)
                {
                    if(arr[--i][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && n==b && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[m][n] = 15;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }

        j = a;
        i = x;

        while(i<=7 && j<=29)
        {
            if(arr[++i][++(++(++(++j)))] == 15)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i>x)
                {
                    if(arr[--i][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && n==b && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[m][n] = 15;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }
    }

    //Two possible captures part 2
    if((m[1]>='1' && m[1]<='8') && (m[3]>='a' && m[3]<='h') && m[2]=='x' && (m[4]>='1' && m[4]<='8'))
    {
        int b = Rank(m[1]);
        int a = file(m[3]);
        int x = Rank(m[4]);
        int c = arr[x][a];

        //vertical and horizontal
        for(int i = 0;i<8;i++)
        {
            if(arr[i][a]==15 && i==b)
            {
                bool check = true;
                int j = i;
                while(j<x)
                {
                    if(arr[++j][a] != 0)
                    {
                        if(!(arr[j][a]==1 || arr[j][a]==2 || arr[j][a]==3 || arr[j][a]==4 || arr[j][a]==5 || arr[j][a]==6))
                            check = false;
                        break;
                    }
                }
                while(j>x)
                {
                    if(arr[--j][a] != 0)
                    {
                        if(!(arr[j][a]==1 || arr[j][a]==2 || arr[j][a]==3 || arr[j][a]==4 || arr[j][a]==5 || arr[j][a]==6))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==x)
                {
                    arr[i][a] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[i][a] = 15;
                        arr[x][a] = c;
                    }
                    return;
                }
            }
        }

        for(int i = 1;i<=29;i += 4)
        {
            if(arr[x][i]==15 && x==b)
            {
                bool check = true;
                int j = i;
                while(j<a)
                {
                    if(arr[x][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                while(j>a)
                {
                    if(arr[x][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==a)
                {
                    arr[x][a] = 15;
                    arr[x][i] = 0;
                    if(black_check())
                    {
                        arr[x][i] = 15;
                        arr[x][a] = c;
                    }
                    return;
                }
            }
        }

        //diagonal
        int j = a;
        int i = x;

        while(i>=0 && j>=1)
        {
            if(arr[--i][--(--(--(--j)))] == 15)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i<x)
                {
                    if(arr[++i][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && m==b && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[m][n] = 15;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }
        j = a;
        i = x;

        while(i>=0 && j<=29)
        {
            if(arr[--i][++(++(++(++j)))] == 15)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i<x)
                {
                    if(arr[++i][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && m==b && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[m][n] = 15;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }

        j = a;
        i = x;

        while(i<=7 && j>=1)
        {
            if(arr[++i][--(--(--(--j)))] == 15)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j<a && i>x)
                {
                    if(arr[--i][++(++(++(++j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && m==b && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[m][n] = 15;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }

        j = a;
        i = x;

        while(i<=7 && j<=29)
        {
            if(arr[++i][++(++(++(++j)))] == 15)
            {
                int m = i;
                int n = j;
                bool check = true;
                while(j>a && i>x)
                {
                    if(arr[--i][--(--(--(--j)))] != 0)
                    {
                        if(!(arr[x][j]==1 || arr[x][j]==2 || arr[x][j]==3 || arr[x][j]==4 || arr[x][j]==5 || arr[x][j]==6))
                            check = false;
                        break;
                    }
                }

                if(check && m==b && (arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6) && j==a && i==x)
                {
                    arr[m][n] = 0;
                    arr[x][a] = 15;
                    if(black_check())
                    {
                        arr[m][n] = 15;
                        arr[x][a] = c;
                    }
                    return;
                }
                break;
            }
        }
    }
}

void king(string m)
{
    //simple move
    if((m[1]>='a' && m[1]<='h') && (m[2]>='1' && m[2]<='8'))
    {
        int a = file(m[1]);
        int x = Rank(m[2]);

        if(arr[x][a] != 0)
        {
            return;
        }

        int j = a;
        int i = x;

        if((j+4)<=29)
        {
            if(arr[i][++(++(++(++j)))]==6)
            {
                arr[x][a] = 6;
                arr[i][j] = 0;
                white_king_i = x;
                white_king_j = a;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i][j] = 6;
                    white_king_i = i;
                    white_king_j = j;
                    return;
                }
                castle = false;
                long_castle = false;
                return;
            }

            j -= 4;
        }

        if((j-4)>=1)
        {
            if(arr[i][--(--(--(--j)))]==6)
            {
                arr[x][a] = 6;
                arr[i][j] = 0;
                white_king_i = x;
                white_king_j = a;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i][j] = 6;
                    white_king_i = i;
                    white_king_j = j;
                    return;
                }
                castle = false;
                long_castle = false;
                return;
            }
            j += 4;
        }

        if((i+1)<=7)
        {
            if(arr[++i][j]==6)
            {
                arr[x][a] = 6;
                arr[i][j] = 0;
                white_king_i = x;
                white_king_j = a;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i][j] = 6;
                    white_king_i = i;
                    white_king_j = j;
                    return;
                }
                castle = false;
                long_castle = false;
                return;
            }

            i--;
        }

        if((i-1)>=0)
        {
            if(arr[--i][j]==6)
            {
                arr[x][a] = 6;
                arr[i][j] = 0;
                white_king_i = x;
                white_king_j = a;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i][j] = 6;
                    white_king_i = i;
                    white_king_j = j;
                    return;
                }
                castle = false;
                long_castle = false;
                return;
            }
            i++;
        }

        if((i+1)<=7 && (j+4)<=29)
        {
            if(arr[i+1][j+4]==6)
            {
                arr[x][a] = 6;
                arr[i+1][j+4] = 0;
                white_king_i = x;
                white_king_j = a;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i+1][j+4] = 6;
                    white_king_i = i+1;
                    white_king_j = j+j;
                    return;
                }
                castle = false;
                long_castle = false;
                return;
            }
        }

        if((i+1)<=7 && (j-4)>=1)
        {
            if(arr[i+1][j-4]==6)
            {
                arr[x][a] = 6;
                arr[i+1][j-4] = 0;
                white_king_i = x;
                white_king_j = a;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i+1][j-4] = 6;
                    white_king_i = i+1;
                    white_king_j = j-4;
                    return;
                }
                castle = false;
                long_castle = false;
                return;
            }
        }

        if((i-1)>=0 && (j+4)<=29)
        {
            if(arr[i-1][j+4]==6)
            {
                arr[x][a] = 6;
                arr[i-1][j+4] = 0;
                white_king_i = x;
                white_king_j = a;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i-1][j+4] = 6;
                    white_king_i = i-1;
                    white_king_j = j+4;
                    return;
                }
                castle = false;
                long_castle = false;
                return;
            }
        }

        if((i-1)>=0 && (j-4)>=1)
        {
            if(arr[i-1][j-4]==6)
            {
                arr[x][a] = 6;
                arr[i-1][j-4] = 0;
                white_king_i = x;
                white_king_j = a;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i+1][j+4] = 6;
                    white_king_i = i+1;
                    white_king_j = j+4;
                    return;
                }
                castle = false;
                long_castle = false;
                return;
            }
        }
    }

    //Capture
    if((m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8') && m[1]=='x')
    {
        int a = file(m[2]);
        int x = Rank(m[3]);
        int c = arr[x][a];

        if(!(arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16))
        {
            return;
        }

        int j = a;
        int i = x;

        if((j+4)<=29)
        {
            if(arr[i][++(++(++(++j)))]==6)
            {
                arr[x][a] = 6;
                arr[i][j] = 0;
                white_king_i = x;
                white_king_j = a;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i][j] = 6;
                    white_king_i = i;
                    white_king_j = j;
                    return;
                }
                castle = false;
                long_castle = false;
                return;
            }

            j -= 4;
        }

        if((j-4)>=1)
        {
            if(arr[i][--(--(--(--j)))]==6)
            {
                arr[x][a] = 6;
                arr[i][j] = 0;
                white_king_i = x;
                white_king_j = a;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i][j] = 6;
                    white_king_i = i;
                    white_king_j = j;
                    return;
                }
                castle = false;
                long_castle = false;
                return;
            }
            j += 4;
        }

        if((i+1)<=7)
        {
            if(arr[++i][j]==6)
            {
                arr[x][a] = 6;
                arr[i][j] = 0;
                white_king_i = x;
                white_king_j = a;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i][j] = 6;
                    white_king_i = i;
                    white_king_j = j;
                    return;
                }
                castle = false;
                long_castle = false;
                return;
            }

            i--;
        }

        if((i-1)>=0)
        {
            if(arr[--i][j]==6)
            {
                arr[x][a] = 6;
                arr[i][j] = 0;
                white_king_i = x;
                white_king_j = a;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i][j] = 6;
                    white_king_i = i;
                    white_king_j = j;
                    return;
                }
                castle = false;
                long_castle = false;
                return;
            }
            i++;
        }

        if((i+1)<=7 && (j+4)<=29)
        {
            if(arr[i+1][j+4]==6)
            {
                arr[x][a] = 6;
                arr[i+1][j+4] = 0;
                white_king_i = x;
                white_king_j = a;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i+1][j+4] = 6;
                    white_king_i = i+1;
                    white_king_j = j+4;
                    return;
                }
                castle = false;
                long_castle = false;
                return;
            }
        }

        if((i+1)<=7 && (j-4)>=1)
        {
            if(arr[i+1][j-4]==6)
            {
                arr[x][a] = 6;
                arr[i+1][j-4] = 0;
                white_king_i = x;
                white_king_j = a;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i+1][j-4] = 6;
                    white_king_i = i+1;
                    white_king_j = j-4;
                    return;
                }
                castle = false;
                long_castle = false;
                return;
            }
        }

        if((i-1)>=0 && (j+4)<=29)
        {
            if(arr[i-1][j+4]==6)
            {
                arr[x][a] = 6;
                arr[i-1][j+4] = 0;
                white_king_i = x;
                white_king_j = a;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i-1][j+4] = 6;
                    white_king_i = i-1;
                    white_king_j = j+4;
                    return;
                }
                castle = false;
                long_castle = false;
                return;
            }
        }

        if((i-1)>=0 && (j-4)>=1)
        {
            if(arr[i-1][j-4]==6)
            {
                arr[x][a] = 6;
                arr[i-1][j-4] = 0;
                white_king_i = x;
                white_king_j = a;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i-1][j-4] = 6;
                    white_king_i = i-1;
                    white_king_j = j-4;
                    return;
                }
                castle = false;
                long_castle = false;
                return;
            }
        }

    }
}

void bking(string m)
{
    //simple move
    if((m[1]>='a' && m[1]<='h') && (m[2]>='1' && m[2]<='8'))
    {
        int a = file(m[1]);
        int x = Rank(m[2]);

        if(arr[x][a] != 0)
        {
            return;
        }

        int j = a;
        int i = x;

        if((j+4)<=29)
        {
            if(arr[i][++(++(++(++j)))]==16)
            {
                arr[x][a] = 16;
                arr[i][j] = 0;
                black_king_i = x;
                black_king_j = a;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i][j] = 16;
                    black_king_i = i;
                    black_king_j = j;
                    return;
                }
                bcastle = false;
                blong_castle = false;
                return;
            }

            j -= 4;
        }

        if((j-4)>=1)
        {
            if(arr[i][--(--(--(--j)))]==16)
            {
                arr[x][a] = 16;
                arr[i][j] = 0;
                black_king_i = x;
                black_king_j = a;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i][j] = 16;
                    black_king_i = i;
                    black_king_j = j;
                    return;
                }
                bcastle = false;
                blong_castle = false;
                return;
            }
            j += 4;
        }

        if((i+1)<=7)
        {
            if(arr[++i][j]==16)
            {
                arr[x][a] = 16;
                arr[i][j] = 0;
                black_king_i = x;
                black_king_j = a;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i][j] = 16;
                    black_king_i = i;
                    black_king_j = j;
                    return;
                }
                bcastle = false;
                blong_castle = false;
                return;
            }

            i--;
        }

        if((i-1)>=0)
        {
            if(arr[--i][j]==16)
            {
                arr[x][a] = 16;
                arr[i][j] = 0;
                black_king_i = x;
                black_king_j = a;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i][j] = 16;
                    black_king_i = i;
                    black_king_j = j;
                    return;
                }
                bcastle = false;
                blong_castle = false;
                return;
            }
            i++;
        }

        if((i+1)<=7 && (j+4)<=29)
        {
            if(arr[i+1][j+4]==16)
            {
                arr[x][a] = 16;
                arr[i+1][j+4] = 0;
                black_king_i = x;
                black_king_j = a;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i+1][j+4] = 16;
                    black_king_i = i+1;
                    black_king_j = j+4;
                    return;
                }
                bcastle = false;
                blong_castle = false;
                return;
            }
        }

        if((i+1)<=7 && (j-4)>=1)
        {
            if(arr[i+1][j-4]==16)
            {
                arr[x][a] = 16;
                arr[i+1][j-4] = 0;
                black_king_i = x;
                black_king_j = a;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i+1][j-4] = 16;
                    black_king_i = i+1;
                    black_king_j = j-4;
                    return;
                }
                bcastle = false;
                blong_castle = false;
                return;
            }
        }

        if((i-1)>=0 && (j+4)<=29)
        {
            if(arr[i-1][j+4]==16)
            {
                arr[x][a] = 16;
                arr[i-1][j+4] = 0;
                black_king_i = x;
                black_king_j = a;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i-1][j+4] = 16;
                    black_king_i = i-1;
                    black_king_j = j+4;
                    return;
                }
                bcastle = false;
                blong_castle = false;
                return;
            }
        }

        if((i-1)>=0 && (j-4)>=1)
        {
            if(arr[i-1][j-4]==16)
            {
                arr[x][a] = 16;
                arr[i-1][j-4] = 0;
                black_king_i = x;
                black_king_j = a;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i-1][j-4] = 16;
                    black_king_i = i-1;
                    black_king_j = j-4;
                    return;
                }
                bcastle = false;
                blong_castle = false;
                return;
            }
        }
    }

    //Capture
    if((m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8') && m[1]=='x')
    {
        int a = file(m[2]);
        int x = Rank(m[3]);
        int c = arr[x][a];

        if(!(arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6))
        {
            return;
        }

        int j = a;
        int i = x;

        if((j+4)<=29)
        {
            if(arr[i][++(++(++(++j)))]==16)
            {
                arr[x][a] = 16;
                arr[i][j] = 0;
                black_king_i = x;
                black_king_j = a;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i][j] = 16;
                    black_king_i = i;
                    black_king_j = j;
                    return;
                }
                bcastle = false;
                blong_castle = false;
                return;
            }

            j -= 4;
        }

        if((j-4)>=1)
        {
            if(arr[i][--(--(--(--j)))]==16)
            {
                arr[x][a] = 16;
                arr[i][j] = 0;
                black_king_i = x;
                black_king_j = a;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i][j] = 16;
                    black_king_i = i;
                    black_king_j = j;
                    return;
                }
                bcastle = false;
                blong_castle = false;
                return;
            }
            j += 4;
        }

        if((i+1)<=7)
        {
            if(arr[++i][j]==16)
            {
                arr[x][a] = 16;
                arr[i][j] = 0;
                black_king_i = x;
                black_king_j = a;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i][j] = 16;
                    black_king_i = i;
                    black_king_j = j;
                    return;
                }
                bcastle = false;
                blong_castle = false;
                return;
            }

            i--;
        }

        if((i-1)>=0)
        {
            if(arr[--i][j]==16)
            {
                arr[x][a] = 16;
                arr[i][j] = 0;
                black_king_i = x;
                black_king_j = a;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i][j] = 16;
                    black_king_i = i;
                    black_king_j = j;
                    return;
                }
                bcastle = false;
                blong_castle = false;
                return;
            }
            i++;
        }

        if((i+1)<=7 && (j+4)<=29)
        {
            if(arr[i+1][j+4]==16)
            {
                arr[x][a] = 16;
                arr[i+1][j+4] = 0;
                black_king_i = x;
                black_king_j = a;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i+1][j+4] = 16;
                    black_king_i = i+1;
                    black_king_j = j+4;
                    return;
                }
                bcastle = false;
                blong_castle = false;
                return;
            }
        }

        if((i+1)<=7 && (j-4)>=1)
        {
            if(arr[i+1][j-4]==16)
            {
                arr[x][a] = 16;
                arr[i+1][j-4] = 0;
                black_king_i = x;
                black_king_j = a;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i+1][j-4] = 16;
                    black_king_i = i+1;
                    black_king_j = j-4;
                    return;
                }
                bcastle = false;
                blong_castle = false;
                return;
            }
        }

        if((i-1)>=0 && (j+4)<=29)
        {
            if(arr[i-1][j+4]==16)
            {
                arr[x][a] = 16;
                arr[i-1][j+4] = 0;
                black_king_i = x;
                black_king_j = a;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i-1][j+4] = 16;
                    black_king_i = i-1;
                    black_king_j = j+4;
                    return;
                }
                bcastle = false;
                blong_castle = false;
                return;
            }
        }

        if((i-1)>=0 && (j-4)>=1)
        {
            if(arr[i-1][j-4]==16)
            {
                arr[x][a] = 16;
                arr[i-1][j-4] = 0;
                black_king_i = x;
                black_king_j = a;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i-1][j-4] = 16;
                    black_king_i = i-1;
                    black_king_j = j-4;
                    return;
                }
                bcastle = false;
                blong_castle = false;
                return;
            }
        }
    }
}

void knight(string m)
{
    //move
    if((m[1]>='a' && m[1]<='h') && (m[2]>='1' && m[2]<='8'))
    {
        int a = file(m[1]);
        int x = Rank(m[2]);

        if(arr[x][a] != 0)
        {
            return;
        }

        int j = a;
        int i = x;

        if((i+2)<=7 && (j+4)<=29)
        {
            if(arr[i+2][j+4]==3)
            {
                arr[x][a] = 3;
                arr[i+2][j+4] = 0;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i+2][j+4] = 3;
                }
                return;
            }
        }

        if((i+2)<=7 && (j-4)>=1)
        {
            if(arr[i+2][j-4]==3)
            {
                arr[x][a] = 3;
                arr[i+2][j-4] = 0;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i+2][j-4] = 3;
                }
                return;
            }
        }

        if((i-2)>=0 && (j+4)<=29)
        {
            if(arr[i-2][j+4]==3)
            {
                arr[x][a] = 3;
                arr[i-2][j+4] = 0;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i-2][j+4] = 3;
                }
                return;
            }
        }

        if((i-2)>=0 && (j-4)>=1)
        {
            if(arr[i-2][j-4]==3)
            {
                arr[x][a] = 3;
                arr[i-2][j-4] = 0;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i-2][j-4] = 3;
                }
                return;
            }
        }

        if((i+1)<=7 && (j+8)<=29)
        {
            if(arr[i+1][j+8]==3)
            {
                arr[x][a] = 3;
                arr[i+1][j+8] = 0;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i+1][j+8] = 3;
                }
                return;
            }
        }

        if((i+1)<=7 && (j-8)>=1)
        {
            if(arr[i+1][j-8]==3)
            {
                arr[x][a] = 3;
                arr[i+1][j-8] = 0;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i+1][j-8] = 3;
                }
                return;
            }
        }

        if((i-1)>=0 && (j+8)<=29)
        {
            if(arr[i-1][j+8]==3)
            {
                arr[x][a] = 3;
                arr[i-1][j+8] = 0;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i-1][j+8] = 3;
                }
                return;
            }
        }

        if((i-1)>=0 && (j-8)>=1)
        {
            if(arr[i-1][j-8]==3)
            {
                arr[x][a] = 3;
                arr[i-1][j-8] = 0;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i-1][j-8] = 3;
                }
                return;
            }
        }
    }

    //Two Possible Moves
    if((m[1]>='a' && m[1]<='h') && (m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8'))
    {
        int b = file(m[1]);
        int a = file(m[2]);
        int x = Rank(m[3]);

        if(arr[a][x]==0)
        {
            int j = a;
        int i = x;

        if((i+2)<=7 && (j+4)<=29 && j+4==b)
        {
            if(arr[i+2][j+4]==3)
            {
                arr[x][a] = 3;
                arr[i+2][j+4] = 0;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i+2][j+4] = 3;
                }
                return;
            }
        }

        if((i+2)<=7 && (j-4)>=1 && j-4==b)
        {
            if(arr[i+2][j-4]==3)
            {
                arr[x][a] = 3;
                arr[i+2][j-4] = 0;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i+2][j-4] = 3;
                }
                return;
            }
        }

        if((i-2)>=0 && (j+4)<=29 && j+4==b)
        {
            if(arr[i-2][j+4]==3)
            {
                arr[x][a] = 3;
                arr[i-2][j+4] = 0;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i-2][j+4] = 3;
                }
                return;
            }
        }

        if((i-2)>=0 && (j-4)>=1 && j-4==b)
        {
            if(arr[i-2][j-4]==3)
            {
                arr[x][a] = 3;
                arr[i-2][j-4] = 0;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i-2][j-4] = 3;
                }
                return;
            }
        }

        if((i+1)<=7 && (j+8)<=29 && j+8==b)
        {
            if(arr[i+1][j+8]==3)
            {
                arr[x][a] = 3;
                arr[i+1][j+8] = 0;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i+1][j+8] = 3;
                }
                return;
            }
        }

        if((i+1)<=7 && (j-8)>=1 && j-8==b)
        {
            if(arr[i+1][j-8]==3)
            {
                arr[x][a] = 3;
                arr[i+1][j-8] = 0;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i+1][j-8] = 3;
                }
                return;
            }
        }

        if((i-1)>=0 && (j+8)<=29 && j+8==b)
        {
            if(arr[i-1][j+8]==3)
            {
                arr[x][a] = 3;
                arr[i-1][j+8] = 0;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i-1][j+8] = 3;
                }
                return;
            }
        }

        if((i-1)>=0 && (j-8)>=1 && j-8==b)
        {
            if(arr[i-1][j-8]==3)
            {
                arr[x][a] = 3;
                arr[i-1][j-8] = 0;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i-1][j-8] = 3;
                }
                return;
            }
        }
        }
    }

    //Two Possible Moves
    if((m[1]>='1' && m[1]<='8') && (m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8'))
    {
        int b = Rank(m[1]);
        int a = file(m[2]);
        int x = Rank(m[3]);

        if(arr[a][x]==0)
        {
            int j = a;
            int i = x;

        if((i+2)<=7 && (j+4)<=29 && i+2==b)
        {
            if(arr[i+2][j+4]==3)
            {
                arr[x][a] = 3;
                arr[i+2][j+4] = 0;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i+2][j+4] = 3;
                }
                return;
            }
        }

        if((i+2)<=7 && (j-4)>=1 && i+2==b)
        {
            if(arr[i+2][j-4]==3)
            {
                arr[x][a] = 3;
                arr[i+2][j-4] = 0;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i+2][j-4] = 3;
                }
                return;
            }
        }

        if((i-2)>=0 && (j+4)<=29 && i-2==b)
        {
            if(arr[i-2][j+4]==3)
            {
                arr[x][a] = 3;
                arr[i-2][j+4] = 0;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i-2][j+4] = 3;
                }
                return;
            }
        }

        if((i-2)>=0 && (j-4)>=1 && i-2==b)
        {
            if(arr[i-2][j-4]==3)
            {
                arr[x][a] = 3;
                arr[i-2][j-4] = 0;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i-2][j-4] = 3;
                }
                return;
            }
        }

        if((i+1)<=7 && (j+8)<=29 && i+1==b)
        {
            if(arr[i+1][j+8]==3)
            {
                arr[x][a] = 3;
                arr[i+1][j+8] = 0;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i+1][j+8] = 3;
                }
                return;
            }
        }

        if((i+1)<=7 && (j-8)>=1 && i+1==b)
        {
            if(arr[i+1][j-8]==3)
            {
                arr[x][a] = 3;
                arr[i+1][j-8] = 0;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i+1][j-8] = 3;
                }
                return;
            }
        }

        if((i-1)>=0 && (j+8)<=29 && i-1==b)
        {
            if(arr[i-1][j+8]==3)
            {
                arr[x][a] = 3;
                arr[i-1][j+8] = 0;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i-1][j+8] = 3;
                }
                return;
            }
        }

        if((i-1)>=0 && (j-8)>=1 && i-1==b)
        {
            if(arr[i-1][j-8]==3)
            {
                arr[x][a] = 3;
                arr[i-1][j-8] = 0;
                if(white_check())
                {
                    arr[x][a] = 0;
                    arr[i-1][j-8] = 3;
                }
                return;
            }
        }
        }
    }

    //Capture
    if((m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8') && m[1]=='x')
    {
        int a = file(m[2]);
        int x = Rank(m[3]);
        int c = arr[x][a];

        if(!(arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16))
        {
            return;
        }

        int j = a;
        int i = x;

        if((i+2)<=7 && (j+4)<=29)
        {
            if(arr[i+2][j+4]==3)
            {
                arr[x][a] = 3;
                arr[i+2][j+4] = 0;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i+2][j+4] = 3;
                }
                return;
            }
        }

        if((i+2)<=7 && (j-4)>=1)
        {
            if(arr[i+2][j-4]==3)
            {
                arr[x][a] = 3;
                arr[i+2][j-4] = 0;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i+2][j-4] = 3;
                }
                return;
            }
        }

        if((i-2)>=0 && (j+4)<=29)
        {
            if(arr[i-2][j+4]==3)
            {
                arr[x][a] = 3;
                arr[i-2][j+4] = 0;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i-2][j+4] = 3;
                }
                return;
            }
        }

        if((i-2)>=0 && (j-4)>=1)
        {
            if(arr[i-2][j-4]==3)
            {
                arr[x][a] = 3;
                arr[i-2][j-4] = 0;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i-2][j-4] = 3;
                }
                return;
            }
        }

        if((i+1)<=7 && (j+8)<=29)
        {
            if(arr[i+1][j+8]==3)
            {
                arr[x][a] = 3;
                arr[i+1][j+8] = 0;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i+1][j+8] = 3;
                }
                return;
            }
        }

        if((i+1)<=7 && (j-8)>=1)
        {
            if(arr[i+1][j-8]==3)
            {
                arr[x][a] = 3;
                arr[i+1][j-8] = 0;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i+1][j-8] = 3;
                }
                return;
            }
        }

        if((i-1)>=0 && (j+8)<=29)
        {
            if(arr[i-1][j+8]==3)
            {
                arr[x][a] = 3;
                arr[i-1][j+8] = 0;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i-1][j+8] = 3;
                }
                return;
            }
        }

        if((i-1)>=0 && (j-8)>=1)
        {
            if(arr[i-1][j-8]==3)
            {
                arr[x][a] = 3;
                arr[i-1][j-8] = 0;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i-1][j-8] = 3;
                }
                return;
            }
        }
    }

    //Two possible captures part 1
    if((m[1]>='a' && m[1]<='h') && (m[3]>='a' && m[3]<='h') && m[2]=='x' && (m[4]>='1' && m[4]<='8'))
    {
        int b = file(m[1]);
        int a = file(m[3]);
        int x = Rank(m[4]);
        int c = arr[x][a];

        if(!(arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16))
        {
            return;
        }

        int j = a;
        int i = x;

        if((i+2)<=7 && (j+4)<=29 && j+4==b)
        {
            if(arr[i+2][j+4]==3)
            {
                arr[x][a] = 3;
                arr[i+2][j+4] = 0;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i+2][j+4] = 3;
                }
                return;
            }
        }

        if((i+2)<=7 && (j-4)>=1  && j-4==b)
        {
            if(arr[i+2][j-4]==3)
            {
                arr[x][a] = 3;
                arr[i+2][j-4] = 0;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i+2][j-4] = 3;
                }
                return;
            }
        }

        if((i-2)>=0 && (j+4)<=29 && j+4==b)
        {
            if(arr[i-2][j+4]==3)
            {
                arr[x][a] = 3;
                arr[i-2][j+4] = 0;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i-2][j+4] = 3;
                }
                return;
            }
        }

        if((i-2)>=0 && (j-4)>=1  && j-4==b)
        {
            if(arr[i-2][j-4]==3)
            {
                arr[x][a] = 3;
                arr[i-2][j-4] = 0;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i-2][j-4] = 3;
                }
                return;
            }
        }

        if((i+1)<=7 && (j+8)<=29  && j+8==b)
        {
            if(arr[i+1][j+8]==3)
            {
                arr[x][a] = 3;
                arr[i+1][j+8] = 0;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i+1][j+8] = 3;
                }
                return;
            }
        }

        if((i+1)<=7 && (j-8)>=1)
        {
            if(arr[i+1][j-8]==3 && j-8==b)
            {
                arr[x][a] = 3;
                arr[i+1][j-8] = 0;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i+1][j-8] = 3;
                }
                return;
            }
        }

        if((i-1)>=0 && (j+8)<=29  && j+8==b)
        {
            if(arr[i-1][j+8]==3)
            {
                arr[x][a] = 3;
                arr[i-1][j+8] = 0;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i-1][j+8] = 3;
                }
                return;
            }
        }

        if((i-1)>=0 && (j-8)>=1 && j-8==b)
        {
            if(arr[i-1][j-8]==3)
            {
                arr[x][a] = 3;
                arr[i-1][j-8] = 0;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i-1][j-8] = 3;
                }
                return;
            }
        }
    }


    //Two possible captures part 2
    if((m[1]>='1' && m[1]<='8') && (m[3]>='a' && m[3]<='h') && m[2]=='x' && (m[4]>='1' && m[4]<='8'))
    {
        int b = Rank(m[1]);
        int a = file(m[3]);
        int x = Rank(m[4]);
        int c = arr[x][a];

        if(!(arr[x][a]==11 || arr[x][a]==12 || arr[x][a]==13 || arr[x][a]==14 || arr[x][a]==15 || arr[x][a]==16))
        {
            return;
        }

        int j = a;
        int i = x;

        if((i+2)<=7 && (j+4)<=29 && i+2==b)
        {
            if(arr[i+2][j+4]==3)
            {
                arr[x][a] = 3;
                arr[i+2][j+4] = 0;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i+2][j+4] = 3;
                }
                return;
            }
        }

        if((i+2)<=7 && (j-4)>=1  && i+2==b)
        {
            if(arr[i+2][j-4]==3)
            {
                arr[x][a] = 3;
                arr[i+2][j-4] = 0;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i+2][j-4] = 3;
                }
                return;
            }
        }

        if((i-2)>=0 && (j+4)<=29 && i-2==b)
        {
            if(arr[i-2][j+4]==3)
            {
                arr[x][a] = 3;
                arr[i-2][j+4] = 0;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i-2][j+4] = 3;
                }
                return;
            }
        }

        if((i-2)>=0 && (j-4)>=1  && i-2==b)
        {
            if(arr[i-2][j-4]==3)
            {
                arr[x][a] = 3;
                arr[i-2][j-4] = 0;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i-2][j-4] = 3;
                }
                return;
            }
        }

        if((i+1)<=7 && (j+8)<=29  && i+1==b)
        {
            if(arr[i+1][j+8]==3)
            {
                arr[x][a] = 3;
                arr[i+1][j+8] = 0;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i+1][j+8] = 3;
                }
                return;
            }
        }

        if((i+1)<=7 && (j-8)>=1)
        {
            if(arr[i+1][j-8]==3 && i+1==b)
            {
                arr[x][a] = 3;
                arr[i+1][j-8] = 0;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i+1][j-8] = 3;
                }
                return;
            }
        }

        if((i-1)>=0 && (j+8)<=29  && i-1==b)
        {
            if(arr[i-1][j+8]==3)
            {
                arr[x][a] = 3;
                arr[i-1][j+8] = 0;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i-1][j+8] = 3;
                }
                return;
            }
        }

        if((i-1)>=0 && (j-8)>=1 && i-1==b)
        {
            if(arr[i-1][j-8]==3)
            {
                arr[x][a] = 3;
                arr[i-1][j-8] = 0;
                if(white_check())
                {
                    arr[x][a] = c;
                    arr[i-1][j-8] = 3;
                }
                return;
            }
        }
    }

}

void bknight(string m)
{
    //move
    if((m[1]>='a' && m[1]<='h') && (m[2]>='1' && m[2]<='8'))
    {
        int a = file(m[1]);
        int x = Rank(m[2]);

        if(arr[x][a] != 0)
        {
            return;
        }

        int j = a;
        int i = x;

        if((i+2)<=7 && (j+4)<=29)
        {
            if(arr[i+2][j+4]==13)
            {
                arr[x][a] = 13;
                arr[i+2][j+4] = 0;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i+2][j+4] = 13;
                }
                return;
            }
        }

        if((i+2)<=7 && (j-4)>=1)
        {
            if(arr[i+2][j-4]==13)
            {
                arr[x][a] = 13;
                arr[i+2][j-4] = 0;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i+2][j-4] = 13;
                }
                return;
            }
        }

        if((i-2)>=0 && (j+4)<=29)
        {
            if(arr[i-2][j+4]==13)
            {
                arr[x][a] = 13;
                arr[i-2][j+4] = 0;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i-2][j+4] = 13;
                }
                return;
            }
        }

        if((i-2)>=0 && (j-4)>=1)
        {
            if(arr[i-2][j-4]==13)
            {
                arr[x][a] = 13;
                arr[i-2][j-4] = 0;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i-2][j-4] = 13;
                }
                return;
            }
        }

        if((i+1)<=7 && (j+8)<=29)
        {
            if(arr[i+1][j+8]==13)
            {
                arr[x][a] = 13;
                arr[i+1][j+8] = 0;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i+1][j+8] = 13;
                }
                return;
            }
        }

        if((i+1)<=7 && (j-8)>=1)
        {
            if(arr[i+1][j-8]==13)
            {
                arr[x][a] = 13;
                arr[i+1][j-8] = 0;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i+1][j-8] = 13;
                }
                return;
            }
        }

        if((i-1)>=0 && (j+8)<=29)
        {
            if(arr[i-1][j+8]==13)
            {
                arr[x][a] = 13;
                arr[i-1][j+8] = 0;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i-1][j+8] = 13;
                }
                return;
            }
        }

        if((i-1)>=0 && (j-8)>=1)
        {
            if(arr[i-1][j-8]==13)
            {
                arr[x][a] = 13;
                arr[i-1][j-8] = 0;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i-1][j-8] = 13;
                }
                return;
            }
        }
    }

    //Two Possible Moves part 1
    if((m[1]>='a' && m[1]<='h') && (m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8'))
    {
        int b = file(m[1]);
        int a = file(m[2]);
        int x = Rank(m[3]);

        if(arr[a][x]==0)
        {
            int j = a;
        int i = x;

        if((i+2)<=7 && (j+4)<=29 && j+4==b)
        {
            if(arr[i+2][j+4]==13)
            {
                arr[x][a] = 13;
                arr[i+2][j+4] = 0;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i+2][j+4] = 13;
                }
                return;
            }
        }

        if((i+2)<=7 && (j-4)>=1 && j-4==b)
        {
            if(arr[i+2][j-4]==13)
            {
                arr[x][a] = 13;
                arr[i+2][j-4] = 0;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i+2][j-4] = 13;
                }
                return;
            }
        }

        if((i-2)>=0 && (j+4)<=29 && j+4==b)
        {
            if(arr[i-2][j+4]==13)
            {
                arr[x][a] = 13;
                arr[i-2][j+4] = 0;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i-2][j+4] = 13;
                }
                return;
            }
        }

        if((i-2)>=0 && (j-4)>=1 && j-4==b)
        {
            if(arr[i-2][j-4]==13)
            {
                arr[x][a] = 13;
                arr[i-2][j-4] = 0;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i-2][j-4] = 13;
                }
                return;
            }
        }

        if((i+1)<=7 && (j+8)<=29 && j+8==b)
        {
            if(arr[i+1][j+8]==13)
            {
                arr[x][a] = 13;
                arr[i+1][j+8] = 0;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i+1][j+8] = 13;
                }
                return;
            }
        }

        if((i+1)<=7 && (j-8)>=1 && j-8==b)
        {
            if(arr[i+1][j-8]==13)
            {
                arr[x][a] = 13;
                arr[i+1][j-8] = 0;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i+1][j-8] = 13;
                }
                return;
            }
        }

        if((i-1)>=0 && (j+8)<=29 && j+8==b)
        {
            if(arr[i-1][j+8]==13)
            {
                arr[x][a] = 13;
                arr[i-1][j+8] = 0;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i-1][j+8] = 13;
                }
                return;
            }
        }

        if((i-1)>=0 && (j-8)>=1 && j-8==b)
        {
            if(arr[i-1][j-8]==13)
            {
                arr[x][a] = 13;
                arr[i-1][j-8] = 0;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i-1][j-8] = 13;
                }
                return;
            }
        }
        }
    }

    //Two Possible Moves part 2
    if((m[1]>='1' && m[1]<='8') && (m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8'))
    {
        int b = Rank(m[1]);
        int a = file(m[2]);
        int x = Rank(m[3]);

        if(arr[a][x]==0)
        {
            int j = a;
        int i = x;

        if((i+2)<=7 && (j+4)<=29 && i+2==b)
        {
            if(arr[i+2][j+4]==13)
            {
                arr[x][a] = 13;
                arr[i+2][j+4] = 0;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i+2][j+4] = 13;
                }
                return;
            }
        }

        if((i+2)<=7 && (j-4)>=1 && i+2==b)
        {
            if(arr[i+2][j-4]==13)
            {
                arr[x][a] = 13;
                arr[i+2][j-4] = 0;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i+2][j-4] = 13;
                }
                return;
            }
        }

        if((i-2)>=0 && (j+4)<=29 && i-2==b)
        {
            if(arr[i-2][j+4]==13)
            {
                arr[x][a] = 13;
                arr[i-2][j+4] = 0;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i-2][j+4] = 13;
                }
                return;
            }
        }

        if((i-2)>=0 && (j-4)>=1 && i-2==b)
        {
            if(arr[i-2][j-4]==13)
            {
                arr[x][a] = 13;
                arr[i-2][j-4] = 0;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i-2][j-4] = 13;
                }
                return;
            }
        }

        if((i+1)<=7 && (j+8)<=29 && i+1==b)
        {
            if(arr[i+1][j+8]==13)
            {
                arr[x][a] = 13;
                arr[i+1][j+8] = 0;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i+1][j+8] = 13;
                }
                return;
            }
        }

        if((i+1)<=7 && (j-8)>=1 && i+1==b)
        {
            if(arr[i+1][j-8]==13)
            {
                arr[x][a] = 13;
                arr[i+1][j-8] = 0;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i+1][j-8] = 13;
                }
                return;
            }
        }

        if((i-1)>=0 && (j+8)<=29 && i-1==b)
        {
            if(arr[i-1][j+8]==13)
            {
                arr[x][a] = 13;
                arr[i-1][j+8] = 0;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i-1][j+8] = 13;
                }
                return;
            }
        }

        if((i-1)>=0 && (j-8)>=1 && i-1==b)
        {
            if(arr[i-1][j-8]==13)
            {
                arr[x][a] = 13;
                arr[i-1][j-8] = 0;
                if(black_check())
                {
                    arr[x][a] = 0;
                    arr[i-1][j-8] = 13;
                }
                return;
            }
        }
        }
    }

    //Capture
    if((m[2]>='a' && m[2]<='h') && (m[3]>='1' && m[3]<='8') && m[1]=='x')
    {
        int a = file(m[2]);
        int x = Rank(m[3]);
        int c = arr[x][a];

        if(!(arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6))
        {
            return;
        }

        int j = a;
        int i = x;

        if((i+2)<=7 && (j+4)<=29)
        {
            if(arr[i+2][j+4]==13)
            {
                arr[x][a] = 13;
                arr[i+2][j+4] = 0;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i+2][j+4] = 13;
                }
                return;
            }
        }

        if((i+2)<=7 && (j-4)>=1)
        {
            if(arr[i+2][j-4]==13)
            {
                arr[x][a] = 13;
                arr[i+2][j-4] = 0;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i+2][j-4] = 13;
                }
                return;
            }
        }

        if((i-2)>=0 && (j+4)<=29)
        {
            if(arr[i-2][j+4]==13)
            {
                arr[x][a] = 13;
                arr[i-2][j+4] = 0;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i-2][j+4] = 13;
                }
                return;
            }
        }

        if((i-2)>=0 && (j-4)>=1)
        {
            if(arr[i-2][j-4]==13)
            {
                arr[x][a] = 13;
                arr[i-2][j-4] = 0;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i-2][j-4] = 13;
                }
                return;
            }
        }

        if((i+1)<=7 && (j+8)<=29)
        {
            if(arr[i+1][j+8]==13)
            {
                arr[x][a] = 13;
                arr[i+1][j+8] = 0;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i+1][j+8] = 13;
                }
                return;
            }
        }

        if((i+1)<=7 && (j-8)>=1)
        {
            if(arr[i+1][j-8]==13)
            {
                arr[x][a] = 13;
                arr[i+1][j-8] = 0;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i+1][j-8] = 13;
                }
                return;
            }
        }

        if((i-1)>=0 && (j+8)<=29)
        {
            if(arr[i-1][j+8]==13)
            {
                arr[x][a] = 13;
                arr[i-1][j+8] = 0;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i+1][j-8] = 13;
                }
                return;
            }
        }

        if((i-1)>=0 && (j-8)>=1)
        {
            if(arr[i-1][j-8]==13)
            {
                arr[x][a] = 13;
                arr[i-1][j-8] = 0;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i-1][j-8] = 13;
                }
                return;
            }
        }
    }

    //Two possible captures
    if((m[1]>='a' && m[1]<='h') && (m[3]>='a' && m[3]<='h') && m[2]=='x' && (m[4]>='1' && m[4]<='8'))
    {
        int b = file(m[1]);
        int a = file(m[3]);
        int x = Rank(m[4]);
        int c = arr[x][a];


        if(!(arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6))
        {
            return;
        }

        int j = a;
        int i = x;

        if((i+2)<=7 && (j+4)<=29 && j+4==b)
        {
            if(arr[i+2][j+4]==13)
            {
                arr[x][a] = 13;
                arr[i+2][j+4] = 0;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i+2][j+4] = 13;
                }
                return;
            }
        }

        if((i+2)<=7 && (j-4)>=1  && j-4==b)
        {
            if(arr[i+2][j-4]==13)
            {
                arr[x][a] = 13;
                arr[i+2][j-4] = 0;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i+2][j-4] = 13;
                }
                return;
            }
        }

        if((i-2)>=0 && (j+4)<=29 && j+4==b)
        {
            if(arr[i-2][j+4]==13)
            {
                arr[x][a] = 13;
                arr[i-2][j+4] = 0;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i-2][j+4] = 13;
                }
                return;
            }
        }

        if((i-2)>=0 && (j-4)>=1  && j-4==b)
        {
            if(arr[i-2][j-4]==13)
            {
                arr[x][a] = 13;
                arr[i-2][j-4] = 0;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i-2][j-4] = 13;
                }
                return;
            }
        }

        if((i+1)<=7 && (j+8)<=29  && j+8==b)
        {
            if(arr[i+1][j+8]==13)
            {
                arr[x][a] = 13;
                arr[i+1][j+8] = 0;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i+1][j+8] = 13;
                }
                return;
            }
        }

        if((i+1)<=7 && (j-8)>=1)
        {
            if(arr[i+1][j-8]==13 && j-8==b)
            {
                arr[x][a] = 13;
                arr[i+1][j-8] = 0;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i+1][j-8] = 13;
                }
                return;
            }
        }

        if((i-1)>=0 && (j+8)<=29  && j+8==b)
        {
            if(arr[i-1][j+8]==13)
            {
                arr[x][a] = 13;
                arr[i-1][j+8] = 0;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i-1][j+8] = 13;
                }
                return;
            }
        }

        if((i-1)>=0 && (j-8)>=1 && j-8==b)
        {
            if(arr[i-1][j-8]==13)
            {
                arr[x][a] = 13;
                arr[i-1][j-8] = 0;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i-1][j-8] = 13;
                }
                return;
            }
        }
    }

    //Two possible captures part 2
    if((m[1]>='1' && m[1]<='8') && (m[3]>='a' && m[3]<='h') && m[2]=='x' && (m[4]>='1' && m[4]<='8'))
    {
        int b = Rank(m[1]);
        int a = file(m[3]);
        int x = Rank(m[4]);
        int c = arr[x][a];


        if(!(arr[x][a]==1 || arr[x][a]==2 || arr[x][a]==3 || arr[x][a]==4 || arr[x][a]==5 || arr[x][a]==6))
        {
            return;
        }

        int j = a;
        int i = x;


        if((i+2)<=7 && (j+4)<=29 && i+2==b)
        {
            if(arr[i+2][j+4]==13)
            {
                arr[x][a] = 13;
                arr[i+2][j+4] = 0;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i+2][j+4] = 13;
                }
                return;
            }
        }

        if((i+2)<=7 && (j-4)>=1  && i+2==b)
        {
            if(arr[i+2][j-4]==13)
            {
                arr[x][a] = 13;
                arr[i+2][j-4] = 0;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i+2][j-4] = 13;
                }
                return;
            }
        }

        if((i-2)>=0 && (j+4)<=29 && i-2==b)
        {
            if(arr[i-2][j+4]==13)
            {
                arr[x][a] = 13;
                arr[i-2][j+4] = 0;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i-2][j+4] = 13;
                }
                return;
            }
        }

        if((i-2)>=0 && (j-4)>=1  && i-2==b)
        {
            if(arr[i-2][j-4]==13)
            {
                arr[x][a] = 13;
                arr[i-2][j-4] = 0;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i-2][j-4] = 13;
                }
                return;
            }
        }


        if((i+1)<=7 && (j+8)<=29  && i+1==b)
        {
            if(arr[i+1][j+8]==13)
            {
                arr[x][a] = 13;
                arr[i+1][j+8] = 0;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i+1][j+8] = 13;
                }
                return;
            }
        }

        if((i+1)<=7 && (j-8)>=1)
        {
            if(arr[i+1][j-8]==13 && i+1==b)
            {
                arr[x][a] = 13;
                arr[i+1][j-8] = 0;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i+1][j-8] = 13;
                }
                return;
            }
        }

        if((i-1)>=0 && (j+8)<=29  && i-1==b)
        {
            if(arr[i-1][j+8]==13)
            {
                arr[x][a] = 13;
                arr[i-1][j+8] = 0;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i-1][j+8] = 13;
                }
                return;
            }
        }

        if((i-1)>=0 && (j-8)>=1 && i-1==b)
        {
            if(arr[i-1][j-8]==13)
            {
                arr[x][a] = 13;
                arr[i-1][j-8] = 0;
                if(black_check())
                {
                    arr[x][a] = c;
                    arr[i-1][j-8] = 13;
                }
                return;
            }
        }
    }

}

void castling(string m)
{
    //simple castle
    if(white_check())
    {
        return;
    }

    if(castle && m.size()==3 && m[1]=='-' && m[2]=='O')
    {
        if(arr[7][17]==6 && arr[7][21]==0 && arr[7][25]==0 && arr[7][29]==2)
        {
            arr[7][17] = 0;
            arr[7][21] = 2;
            arr[7][25] = 6;
            arr[7][29] = 0;
            white_king_j = 25;
            if(white_check())
            {
                arr[7][17] = 6;
                arr[7][21] = 0;
                arr[7][25] = 0;
                arr[7][29] = 2;
                white_king_j = 17;
            }
        }
        return;
    }

    //long castle
    if(long_castle && m[1]=='-' && m[2]=='O' && m[3]=='-' && m[4]=='O')
    {
        if(arr[7][1]==2 && arr[7][5]==0 && arr[7][9]==0 && arr[7][13]==0 && arr[7][17]==6)
        {
            arr[7][1] = 0;
            arr[7][5] = 0;
            arr[7][9] = 6;
            arr[7][13] = 2;
            arr[7][17] = 0;
            white_king_j = 9;
            if(white_check())
            {
                arr[7][1] = 2;
                arr[7][5] = 0;
                arr[7][9] = 0;
                arr[7][13] = 0;
                arr[7][17] = 6;
                white_king_j = 17;
            }
        }
    }
}

void bcastling(string m)
{
    if(black_check())
    {
        return;
    }
    //simple castle
    if(bcastle && m.size()==3 && m[1]=='-' && m[2]=='o')
    {
        if(arr[0][17]==16 && arr[0][21]==0 && arr[0][25]==0 && arr[0][29]==12)
        {
            arr[0][17] = 0;
            arr[0][21] = 12;
            arr[0][25] = 16;
            arr[0][29] = 0;
            black_king_j = 25;
            if(black_check())
            {
                arr[0][17] = 16;
                arr[0][21] = 0;
                arr[0][25] = 0;
                arr[0][29] = 12;
                black_king_j = 17;
            }
        }
        return;
    }

    //long castle
    if(blong_castle && m[1]=='-' && m[2]=='o' && m[3]=='-' && m[4]=='o')
    {
        if(arr[0][1]==12 && arr[0][5]==0 && arr[0][9]==0 && arr[0][13]==0 && arr[0][17]==16)
        {
            arr[0][1] = 0;
            arr[0][5] = 0;
            arr[0][9] = 16;
            arr[0][13] = 12;
            arr[0][17] = 0;
            black_king_j = 9;
            if(white_check())
            {
                arr[0][1] = 12;
                arr[0][5] = 0;
                arr[0][9] = 0;
                arr[0][13] = 0;
                arr[0][17] = 16;
                black_king_j = 17;
            }
        }
    }
}

void white_checkmate()
{
    bool up = false,down = false,right = false,left = false;
    bool up_right = false,up_left = false,down_right = false,down_left = false;

    bool knight_1 = false,knight_2 = false,knight_3 = false,knight_4 = false;
    bool knight_5 = false,knight_6 = false,knight_7 = false,knight_8 = false;

    bool pawn_left = false,pawn_right = false;

    int check_count = 0;

    int i = white_king_i;
    int j = white_king_j;

    //diagonal attack
    while(i>=1 && j<=25)
    {
        if(arr[i-1][j+4]==15 || arr[i-1][j+4]==14)
        {
            up_right = true;
            check_count++;
            break;
        }
        if(arr[i-1][j+4] != 0)
            break;

        i--;
        j += 4;
    }

    i = white_king_i;
    j = white_king_j;

    while(i>=1 && j>=5)
    {
        if(arr[i-1][j-4]==15 || arr[i-1][j-4]==14)
        {
            up_left = true;
            check_count++;
            break;
        }
        if(arr[i-1][j-4] != 0)
            break;

        i--;
        j -= 4;
    }

    i = white_king_i;
    j = white_king_j;

    while(i<=6 && j>=5)
    {
        if(arr[i+1][j-4]==15 || arr[i+1][j-4]==14)
        {
            down_left = true;
            check_count++;
            break;
        }
        if(arr[i+1][j-4] != 0)
            break;

        i++;
        j -= 4;
    }

    i = white_king_i;
    j = white_king_j;

    while(i<=6 && j<=25)
    {
        if(arr[i+1][j+4]==15 || arr[i+1][j+4]==14)
        {
            down_right = true;
            check_count++;
            break;
        }
        if(arr[i+1][j+4] != 0)
            break;

        i++;
        j += 4;
    }


    //attack in lines and files
    i = white_king_i;
    j = white_king_j;
    while(i>=1)
    {
        if(arr[i-1][j]==12 || arr[i-1][j]==15)
        {
            up = true;
            check_count++;
            break;
        }
        if(arr[i-1][j] != 0)
            break;

        i--;
    }

    i = white_king_i;
    j = white_king_j;
    while(i<=6)
    {
        if(arr[i+1][j]==12 || arr[i+1][j]==15)
        {
            down = true;
            check_count++;
            break;
        }
        if(arr[i+1][j] != 0)
            break;

        i++;
    }

    i = white_king_i;
    j = white_king_j;
    while(j>=5)
    {
        if(arr[i][j-4]==12 || arr[i][j-4]==15)
        {
            left = true;
            check_count++;
            break;
        }
        if(arr[i][j-4] != 0)
            break;

        j -= 4;
    }

    i = white_king_i;
    j = white_king_j;
    while(j<=25)
    {
        if(arr[i][j+4]==12 || arr[i][j+4]==15)
        {
            right = true;
            check_count++;
            break;
        }
        if(arr[i][j+4] != 0)
            break;

        j += 4;
    }

    //attack by knight
    i = white_king_i;
    j = white_king_j;
    if((i+2)<=7 && (j+4)<=29)
    {
        if(arr[i+2][j+4]==13)
        {
            knight_1 = true;
            check_count++;
        }
    }

    if((i+2)<=7 && (j-4)>=1)
    {
        if(arr[i+2][j-4]==13)
        {
            knight_2 = true;
            check_count++;
        }
    }

    if((i-2)>=0 && (j+4)<=29)
    {
        if(arr[i-2][j+4]==13)
        {
            knight_3 = true;
            check_count++;
        }
    }

    if((i-2)>=0 && (j-4)>=1)
    {
        if(arr[i-2][j-4]==13)
        {
            knight_4 = true;
            check_count++;
        }
    }

    if((i+1)<=7 && (j+8)<=29)
    {
        if(arr[i+1][j+8]==13)
        {
            knight_5 = true;
            check_count++;
        }
    }

    if((i+1)<=7 && (j-8)>=1)
    {
        if(arr[i+1][j-8]==13)
        {
            knight_6 = true;
            check_count++;
        }
    }

    if((i-1)>=0 && (j+8)<=29)
    {
        if(arr[i-1][j+8]==13)
        {
            knight_7 = true;
            check_count++;
        }
    }

    if((i-1)>=0 && (j-8)>=1)
    {
        if(arr[i-1][j-8]==13)
        {
            knight_8 = true;
            check_count++;
        }
    }

    //Attack by pawn
    if(i>=1 && j<=25)
    {
        if(arr[i-1][j+4]==11)
        {
            pawn_right = true;
            check_count++;
        }
    }
    if(i>=1 && j>=5)
    {
        if(arr[i-1][j-4]==11)
        {
            pawn_left = true;
            check_count++;
        }
    }

    //checking king's escape
    i = white_king_i;
    j = white_king_j;

        if((j+4)<=29 && (arr[i][j+4]==11 || arr[i][j+4]==12 || arr[i][j+4]==13 || arr[i][j+4]==14 || arr[i][j+4]==15 || arr[i][j+4]==16 || arr[i][j+4]==0))
        {
            int c = arr[i][j+4];
            arr[i][j] = 0;
            arr[i][j+4] = 6;
            white_king_i = i;
            white_king_j = j+4;
            if(!white_check())
            {
                arr[i][j] = 6;
                arr[i][j+4] = c;
                white_king_i = i;
                white_king_j = j;
                return;
            }
            arr[i][j] = 6;
            arr[i][j+4] = c;
            white_king_i = i;
            white_king_j = j;
        }

        if((j-4)>=1 && (arr[i][j-4]==11 || arr[i][j-4]==12 || arr[i][j-4]==13 || arr[i][j-4]==14 || arr[i][j-4]==15 || arr[i][j-4]==16 || arr[i][j-4]==0))
        {
            int c = arr[i][j-4];
            arr[i][j] = 0;
            arr[i][j-4] = 6;
            white_king_i = i;
            white_king_j = j-4;
            if(!white_check())
            {
                arr[i][j] = 6;
                arr[i][j-4] = c;
                white_king_i = i;
                white_king_j = j;
                return;
            }
            arr[i][j] = 6;
            arr[i][j-4] = c;
            white_king_i = i;
            white_king_j = j;
        }

        if((i+1)<=7 && (arr[i+1][j]==11 || arr[i+1][j]==12 || arr[i+1][j]==13 || arr[i+1][j]==14 || arr[i+1][j]==15 || arr[i+1][j]==16 || arr[i+1][j]==0))
        {
            int c = arr[i+1][j];
            arr[i][j] = 0;
            arr[i+1][j] = 6;
            white_king_i = i+1;
            white_king_j = j;
            if(!white_check())
            {
                arr[i][j] = 6;
                arr[i+1][j] = c;
                white_king_i = i;
                white_king_j = j;
                return;
            }
            arr[i][j] = 6;
            arr[i+1][j] = c;
            white_king_i = i;
            white_king_j = j;
        }

        if((i-1)>=0 && (arr[i-1][j]==11 || arr[i-1][j]==12 || arr[i-1][j]==13 || arr[i-1][j]==14 || arr[i-1][j]==15 || arr[i-1][j]==16 || arr[i-1][j]==0))
        {
            int c = arr[i-1][j];
            arr[i][j] = 0;
            arr[i-1][j] = 6;
            white_king_i = i-1;
            white_king_j = j;
            if(!white_check())
            {
                arr[i][j] = 6;
                arr[i-1][j] = c;
                white_king_i = i;
                white_king_j = j;
                return;
            }
            arr[i][j] = 6;
            arr[i-1][j] = c;
            white_king_i = i;
            white_king_j = j;
        }

        if((i+1)<=7 && (j+4)<=29 && (arr[i+1][j+4]==11 || arr[i+1][j+4]==12 || arr[i+1][j+4]==13 || arr[i+1][j+4]==14 || arr[i+1][j+4]==15 || arr[i+1][j+4]==16 || arr[i+1][j+4]==0))
        {
            int c = arr[i+1][j+4];
            arr[i][j] = 0;
            arr[i+1][j+4] = 6;
            white_king_i = i+1;
            white_king_j = j+4;
            if(!white_check())
            {
                arr[i][j] = 6;
                arr[i+1][j+4] = c;
                white_king_i = i;
                white_king_j = j;
                return;
            }
            arr[i][j] = 6;
            arr[i+1][j+4] = c;
            white_king_i = i;
            white_king_j = j;
        }

        if((i+1)<=7 && (j-4)>=1 && (arr[i+1][j-4]==11 || arr[i+1][j-4]==12 || arr[i+1][j-4]==13 || arr[i+1][j-4]==14 || arr[i+1][j-4]==15 || arr[i+1][j-4]==16 || arr[i+1][j-4]==0))
        {
            int c = arr[i+1][j-4];
            arr[i][j] = 0;
            arr[i+1][j-4] = 6;
            white_king_i = i+1;
            white_king_j = j-4;
            if(!white_check())
            {
                arr[i][j] = 6;
                arr[i+1][j-4] = c;
                white_king_i = i;
                white_king_j = j;
                return;
            }
            arr[i][j] = 6;
            arr[i+1][j-4] = c;
            white_king_i = i;
            white_king_j = j;
        }

        if((i-1)>=0 && (j+4)<=29 && (arr[i-1][j+4]==11 || arr[i-1][j+4]==12 || arr[i-1][j+4]==13 || arr[i-1][j+4]==14 || arr[i-1][j+4]==15 || arr[i-1][j+4]==16 || arr[i-1][j+4]==0))
        {
            int c = arr[i-1][j+4];
            arr[i][j] = 0;
            arr[i-1][j+4] = 6;
            white_king_i = i-1;
            white_king_j = j+4;
            if(!white_check())
            {
                arr[i][j] = 6;
                arr[i-1][j+4] = c;
                white_king_i = i;
                white_king_j = j;
                return;
            }
            arr[i][j] = 6;
            arr[i-1][j+4] = c;
            white_king_i = i;
            white_king_j = j;
        }

        if((i-1)>=0 && (j-4)>=1 && (arr[i-1][j-4]==11 || arr[i-1][j-4]==12 || arr[i-1][j-4]==13 || arr[i-1][j-4]==14 || arr[i-1][j-4]==15 || arr[i-1][j-4]==16 || arr[i-1][j-4]==0))
        {
            int c = arr[i-1][j-4];
            arr[i][j] = 0;
            arr[i-1][j-4] = 6;
            white_king_i = i-1;
            white_king_j = j-4;
            if(!white_check())
            {
                arr[i][j] = 6;
                arr[i-1][j-4] = c;
                white_king_i = i;
                white_king_j = j;
                return;
            }
            arr[i][j] = 6;
            arr[i-1][j-4] = c;
            white_king_i = i;
            white_king_j = j;
        }

        if(check_count>1) //checkmate if double check and not possible to movee
        {
            cout<<"Checkmate!!Black won !!";
            game = false;
            return;
        }

        bool check = false;
    //checking upwards
        if(up)
        {
            while(arr[i-1][j] != 12 && arr[i-1][j] != 15)
            {
                check = attack_on_black(i-1,j);
                if(check)
                {
                    return;
                }
                i--;
            }
            check = attack_on_black(i-1,j);
            if(check)
            {
                return;
            }
        }
        i = white_king_i;
        j = white_king_j;

        //checking downwards
        if(down)
        {
            while(arr[i+1][j] != 12 && arr[i+1][j] != 15)
            {
                check = attack_on_black(i+1,j);
                if(check)
                {
                    return;
                }
                i++;
            }
            check = attack_on_black(i+1,j);
            if(check)
            {
                return;
            }
        }
        i = white_king_i;
        j = white_king_j;

        //checking left
        if(left)
        {
            while(arr[i][j-4] != 12 && arr[i][j-4] != 15)
            {
                check = attack_on_black(i,j-4);
                if(check)
                {
                    return;
                }
                j -= 4;
            }
            check = attack_on_black(i,j-4);
            if(check)
            {
                return;
            }
        }
        i = white_king_i;
        j = white_king_j;

        //checking right
        if(right)
        {
            while(arr[i][j+4] != 12 && arr[i][j+4] != 15)
            {
                check = attack_on_black(i,j+4);
                if(check)
                {
                    return;
                }
                j += 4;
            }
            check = attack_on_black(i,j+4);
            if(check)
            {
                return;
            }
        }
        i = white_king_i;
        j = white_king_j;

        //diagonals check
        if(up_right)
        {
            while(arr[i-1][j+4] != 14 && arr[i-1][j+4] != 15)
            {
                check = attack_on_black(i-1,j+4);
                if(check)
                {
                    return;
                }
                i--;
                j += 4;
            }
            check = attack_on_black(i-1,j+4);
            if(check)
            {
                return;
            }
        }
        i = white_king_i;
        j = white_king_j;

        if(up_left)
        {
            while(arr[i-1][j-4] != 14 && arr[i-1][j-4] != 15)
            {
                check = attack_on_black(i-1,j-4);
                if(check)
                {
                    return;
                }
                i--;
                j -= 4;
            }
            check = attack_on_black(i-1,j-4);
            if(check)
            {
                return;
            }
        }
        i = white_king_i;
        j = white_king_j;

        if(down_right)
        {
            while(arr[i+1][j+4] != 14 && arr[i+1][j+4] != 15)
            {
                check = attack_on_black(i+1,j+4);
                if(check)
                {
                    return;
                }
                i++;
                j += 4;
            }
            check = attack_on_black(i+1,j+4);
            if(check)
            {
                return;
            }
        }
        i = white_king_i;
        j = white_king_j;

        if(down_left)
        {
            while(arr[i+1][j-4] != 14 && arr[i+1][j-4] != 15)
            {
                check = attack_on_black(i+1,j-4);
                if(check)
                {
                    return;
                }
                i++;
                j -= 4;
            }
            check = attack_on_black(i+1,j-4);
            if(check)
            {
                return;
            }
        }
        i = white_king_i;
        j = white_king_j;

        //knights check
        if(knight_1)
        {
            check = attack_on_black(i+2,j+4);
            if(check)
            {
                return;
            }
        }

        if(knight_2)
        {
            check = attack_on_black(i+2,j-4);
            if(check)
            {
                return;
            }
        }

        if(knight_3)
        {
            check = attack_on_black(i-2,j+4);
            if(check)
            {
                return;
            }
        }

        if(knight_4)
        {
            check = attack_on_black(i-2,j-4);
            if(check)
            {
                return;
            }
        }

        if(knight_5)
        {
            check = attack_on_black(i+1,j+8);
            if(check)
            {
                return;
            }
        }

        if(knight_6)
        {
            check = attack_on_black(i+1,j-8);
            if(check)
            {
                return;
            }
        }

        if(knight_7)
        {
            check = attack_on_black(i-1,j+8);
            if(check)
            {
                return;
            }
        }

        if(knight_8)
        {
            check = attack_on_black(i-1,j-8);
            if(check)
            {
                return;
            }
        }

        board();
        cout<<"\n\nCHECKMATE ! BLACK WON !!";
        game = false;
}

void black_checkmate()
{
    bool up = false,down = false,right = false,left = false;
    bool up_right = false,up_left = false,down_right = false,down_left = false;

    bool knight_1 = false,knight_2 = false,knight_3 = false,knight_4 = false;
    bool knight_5 = false,knight_6 = false,knight_7 = false,knight_8 = false;

    bool pawn_left = false,pawn_right = false;

    int check_count = 0;

    int i = black_king_i;
    int j = black_king_j;

    //diagonal attack
    while(i>=1 && j<=25)
    {
        if(arr[i-1][j+4]==5 || arr[i-1][j+4]==4)
        {
            up_right = true;
            check_count++;
            break;
        }
        if(arr[i-1][j+4] != 0)
            break;

        i--;
        j += 4;
    }

    i = black_king_i;
    j = black_king_j;

    while(i>=1 && j>=5)
    {
        if(arr[i-1][j-4]==5 || arr[i-1][j-4]==4)
        {
            up_left = true;
            check_count++;
            break;
        }
        if(arr[i-1][j-4] != 0)
            break;

        i--;
        j -= 4;
    }

    i = black_king_i;
    j = black_king_j;

    while(i<=6 && j>=5)
    {
        if(arr[i+1][j-4]==5 || arr[i+1][j-4]==4)
        {
            down_left = true;
            check_count++;
            break;
        }
        if(arr[i+1][j-4] != 0)
            break;

        i++;
        j -= 4;
    }

    i = black_king_i;
    j = black_king_j;

    while(i<=6 && j<=25)
    {
        if(arr[i+1][j+4]==5 || arr[i+1][j+4]==4)
        {
            down_right = true;
            check_count++;
            break;
        }
        if(arr[i+1][j+4] != 0)
            break;

        i++;
        j += 4;
    }


    //attack in lines and files
    i = black_king_i;
    j = black_king_j;
    while(i>=1)
    {
        if(arr[i-1][j]==2 || arr[i-1][j]==5)
        {
            up = true;
            check_count++;
            break;
        }
        if(arr[i-1][j] != 0)
            break;

        i--;
    }

    i = black_king_i;
    j = black_king_j;
    while(i<=6)
    {
        if(arr[i+1][j]==2 || arr[i+1][j]==5)
        {
            down = true;
            check_count++;
            break;
        }
        if(arr[i+1][j] != 0)
            break;

        i++;
    }

    i = black_king_i;
    j = black_king_j;
    while(j>=5)
    {
        if(arr[i][j-4]==2 || arr[i][j-4]==5)
        {
            left = true;
            check_count++;
            break;
        }
        if(arr[i][j-4] != 0)
            break;

        j -= 4;
    }

    i = black_king_i;
    j = black_king_j;
    while(j<=25)
    {
        if(arr[i][j+4]==2 || arr[i][j+4]==5)
        {
            right = true;
            check_count++;
            break;
        }
        if(arr[i][j+4] != 0)
            break;

        j += 4;
    }

    //attack by knight
    i = black_king_i;
    j = black_king_j;
    if((i+2)<=7 && (j+4)<=29)
    {
        if(arr[i+2][j+4]==3)
        {
            knight_1 = true;
            check_count++;
        }
    }

    if((i+2)<=7 && (j-4)>=1)
    {
        if(arr[i+2][j-4]==3)
        {
            knight_2 = true;
            check_count++;
        }
    }

    if((i-2)>=0 && (j+4)<=29)
    {
        if(arr[i-2][j+4]==3)
        {
            knight_3 = true;
            check_count++;
        }
    }

    if((i-2)>=0 && (j-4)>=1)
    {
        if(arr[i-2][j-4]==3)
        {
            knight_4 = true;
            check_count++;
        }
    }

    if((i+1)<=7 && (j+8)<=29)
    {
        if(arr[i+1][j+8]==3)
        {
            knight_5 = true;
            check_count++;
        }
    }

    if((i+1)<=7 && (j-8)>=1)
    {
        if(arr[i+1][j-8]==3)
        {
            knight_6 = true;
            check_count++;
        }
    }

    if((i-1)>=0 && (j+8)<=29)
    {
        if(arr[i-1][j+8]==3)
        {
            knight_7 = true;
            check_count++;
        }
    }

    if((i-1)>=0 && (j-8)>=1)
    {
        if(arr[i-1][j-8]==3)
        {
            knight_8 = true;
            check_count++;
        }
    }

    //Attack by pawn
    if(i>=1 && j<=25)
    {
        if(arr[i-1][j+4]==1)
        {
            pawn_right = true;
            check_count++;
        }
    }
    if(i>=1 && j>=5)
    {
        if(arr[i-1][j-4]==1)
        {
            pawn_left = true;
            check_count++;
        }
    }

    //checking king's escape
    i = black_king_i;
    j = black_king_j;

        if((j+4)<=29 && (arr[i][j+4]==1 || arr[i][j+4]==2 || arr[i][j+4]==3 || arr[i][j+4]==4 || arr[i][j+4]==5 || arr[i][j+4]==6 || arr[i][j+4]==0))
        {
            int c = arr[i][j+4];
            arr[i][j] = 0;
            arr[i][j+4] = 16;
            black_king_i = i;
            black_king_j = j+4;
            if(!black_check())
            {
                arr[i][j] = 16;
                arr[i][j+4] = c;
                black_king_i = i;
                black_king_j = j;
                return;
            }
            arr[i][j] = 16;
            arr[i][j+4] = c;
            black_king_i = i;
            black_king_j = j;
        }

        if((j-4)>=1 && (arr[i][j-4]==1 || arr[i][j-4]==2 || arr[i][j-4]==3 || arr[i][j-4]==4 || arr[i][j-4]==5 || arr[i][j-4]==6 || arr[i][j-4]==0))
        {
            int c = arr[i][j-4];
            arr[i][j] = 0;
            arr[i][j-4] = 16;
            black_king_i = i;
            black_king_j = j-4;
            if(!black_check())
            {
                arr[i][j] = 16;
                arr[i][j-4] = c;
                black_king_i = i;
                black_king_j = j;
                return;
            }
            arr[i][j] = 16;
            arr[i][j-4] = c;
            black_king_i = i;
            black_king_j = j;
        }

        if((i+1)<=7 && (arr[i+1][j]==1 || arr[i+1][j]==2 || arr[i+1][j]==3 || arr[i+1][j]==4 || arr[i+1][j]==5 || arr[i+1][j]==6 || arr[i+1][j]==0))
        {
            int c = arr[i+1][j];
            arr[i][j] = 0;
            arr[i+1][j] = 16;
            black_king_i = i+1;
            black_king_j = j;
            if(!black_check())
            {
                arr[i][j] = 16;
                arr[i+1][j] = c;
                black_king_i = i;
                black_king_j = j;
                return;
            }
            arr[i][j] = 16;
            arr[i+1][j] = c;
            black_king_i = i;
            black_king_j = j;
        }

        if((i-1)>=0 && (arr[i-1][j]==1 || arr[i-1][j]==2 || arr[i-1][j]==3 || arr[i-1][j]==4 || arr[i-1][j]==5 || arr[i-1][j]==6 || arr[i-1][j]==0))
        {
            int c = arr[i-1][j];
            arr[i][j] = 0;
            arr[i-1][j] = 16;
            black_king_i = i-1;
            black_king_j = j;
            if(!black_check())
            {
                arr[i][j] = 16;
                arr[i-1][j] = c;
                black_king_i = i;
                black_king_j = j;
                return;
            }
            arr[i][j] = 16;
            arr[i-1][j] = c;
            black_king_i = i;
            black_king_j = j;
        }

        if((i+1)<=7 && (j+4)<=29 && (arr[i+1][j+4]==1 || arr[i+1][j+4]==2 || arr[i+1][j+4]==3 || arr[i+1][j+4]==4 || arr[i+1][j+4]==5 || arr[i+1][j+4]==6 || arr[i+1][j+4]==0))
        {
            int c = arr[i+1][j+4];
            arr[i][j] = 0;
            arr[i+1][j+4] = 16;
            black_king_i = i+1;
            black_king_j = j+4;
            if(!black_check())
            {
                arr[i][j] = 16;
                arr[i+1][j+4] = c;
                black_king_i = i;
                black_king_j = j;
                return;
            }
            arr[i][j] = 16;
            arr[i+1][j+4] = c;
            black_king_i = i;
            black_king_j = j;
        }

        if((i+1)<=7 && (j-4)>=1 && (arr[i+1][j-4]==1 || arr[i+1][j-4]==2 || arr[i+1][j-4]==3 || arr[i+1][j-4]==4 || arr[i+1][j-4]==5 || arr[i+1][j-4]==6 || arr[i+1][j-4]==0))
        {
            int c = arr[i+1][j-4];
            arr[i][j] = 0;
            arr[i+1][j-4] = 16;
            black_king_i = i+1;
            black_king_j = j-4;
            if(!black_check())
            {
                arr[i][j] = 16;
                arr[i+1][j-4] = c;
                black_king_i = i;
                black_king_j = j;
                return;
            }
            arr[i][j] = 16;
            arr[i+1][j-4] = c;
            black_king_i = i;
            black_king_j = j;
        }

        if((i-1)>=0 && (j+4)<=29 && (arr[i-1][j+4]==1 || arr[i-1][j+4]==2 || arr[i-1][j+4]==3 || arr[i-1][j+4]==4 || arr[i-1][j+4]==5 || arr[i-1][j+4]==6 || arr[i-1][j+4]==0))
        {
            int c = arr[i-1][j+4];
            arr[i][j] = 0;
            arr[i-1][j+4] = 16;
            black_king_i = i-1;
            black_king_j = j+4;
            if(!black_check())
            {
                arr[i][j] = 16;
                arr[i-1][j+4] = c;
                black_king_i = i;
                black_king_j = j;
                return;
            }
            arr[i][j] = 16;
            arr[i-1][j+4] = c;
            black_king_i = i;
            black_king_j = j;
        }

        if((i-1)>=0 && (j-4)>=1 && (arr[i-1][j-4]==1 || arr[i-1][j-4]==2 || arr[i-1][j-4]==3 || arr[i-1][j-4]==4 || arr[i-1][j-4]==5 || arr[i-1][j-4]==6 || arr[i-1][j-4]==0))
        {
            int c = arr[i-1][j-4];
            arr[i][j] = 0;
            arr[i-1][j-4] = 16;
            black_king_i = i-1;
            black_king_j = j-4;
            if(!black_check())
            {
                arr[i][j] = 16;
                arr[i-1][j-4] = c;
                black_king_i = i;
                black_king_j = j;
                return;
            }
            arr[i][j] = 16;
            arr[i-1][j-4] = c;
            black_king_i = i;
            black_king_j = j;
        }

        if(check_count>1) //checkmate if double check and not possible to movee
        {
            cout<<"Checkmate!!Black won !!";
            game = false;
            return;
        }

        bool check = false;
    //checking upwards
        if(up)
        {
            while(arr[i-1][j] != 2 && arr[i-1][j] != 5)
            {
                check = attack_on_white(i-1,j);
                if(check)
                {
                    return;
                }
                i--;
            }
            check = attack_on_white(i-1,j);
            if(check)
            {
                return;
            }
        }
        i = black_king_i;
        j = black_king_j;

        //checking downwards
        if(down)
        {
            while(arr[i+1][j] != 2 && arr[i+1][j] != 5)
            {
                check = attack_on_white(i+1,j);
                if(check)
                {
                    return;
                }
                i++;
            }
            check = attack_on_white(i+1,j);
            if(check)
            {
                return;
            }
        }
        i = black_king_i;
        j = black_king_j;

        //checking left
        if(left)
        {
            while(arr[i][j-4] != 2 && arr[i][j-4] != 5)
            {
                check = attack_on_white(i,j-4);
                if(check)
                {
                    return;
                }
                j -= 4;
            }
            check = attack_on_white(i,j-4);
            if(check)
            {
                return;
            }
        }
        i = black_king_i;
        j = black_king_j;

        //checking right
        if(right)
        {
            while(arr[i][j+4] != 2 && arr[i][j+4] != 5)
            {
                check = attack_on_white(i,j+4);
                if(check)
                {
                    return;
                }
                j += 4;
            }
            check = attack_on_white(i,j+4);
            if(check)
            {
                return;
            }
        }
        i = black_king_i;
        j = black_king_j;

        //diagonals check
        if(up_right)
        {
            while(arr[i-1][j+4] != 4 && arr[i-1][j+4] != 5)
            {
                check = attack_on_white(i-1,j+4);
                if(check)
                {
                    return;
                }
                i--;
                j += 4;
            }
            check = attack_on_white(i-1,j+4);
            if(check)
            {
                return;
            }
        }
        i = black_king_i;
        j = black_king_j;

        if(up_left)
        {
            while(arr[i-1][j-4] != 4 && arr[i-1][j-4] != 5)
            {
                check = attack_on_white(i-1,j-4);
                if(check)
                {
                    return;
                }
                i--;
                j -= 4;
            }
            check = attack_on_white(i-1,j-4);
            if(check)
            {
                return;
            }
        }
        i = black_king_i;
        j = black_king_j;

        if(down_right)
        {
            while(arr[i+1][j+4] != 4 && arr[i+1][j+4] != 5)
            {
                check = attack_on_white(i+1,j+4);
                if(check)
                {
                    return;
                }
                i++;
                j += 4;
            }
            check = attack_on_white(i+1,j+4);
            if(check)
            {
                return;
            }
        }
        i = black_king_i;
        j = black_king_j;

        if(down_left)
        {
            while(arr[i+1][j-4] != 4 && arr[i+1][j-4] != 5)
            {
                check = attack_on_white(i+1,j-4);
                if(check)
                {
                    return;
                }
                i++;
                j -= 4;
            }
            check = attack_on_white(i+1,j-4);
            if(check)
            {
                return;
            }
        }
        i = black_king_i;
        j = black_king_j;

        //knights check
        if(knight_1)
        {
            check = attack_on_white(i+2,j+4);
            if(check)
            {
                return;
            }
        }

        if(knight_2)
        {
            check = attack_on_white(i+2,j-4);
            if(check)
            {
                return;
            }
        }

        if(knight_3)
        {
            check = attack_on_white(i-2,j+4);
            if(check)
            {
                return;
            }
        }

        if(knight_4)
        {
            check = attack_on_white(i-2,j-4);
            if(check)
            {
                return;
            }
        }

        if(knight_5)
        {
            check = attack_on_white(i+1,j+8);
            if(check)
            {
                return;
            }
        }

        if(knight_6)
        {
            check = attack_on_white(i+1,j-8);
            if(check)
            {
                return;
            }
        }

        if(knight_7)
        {
            check = attack_on_white(i-1,j+8);
            if(check)
            {
                return;
            }
        }

        if(knight_8)
        {
            check = attack_on_white(i-1,j-8);
            if(check)
            {
                return;
            }
        }

        board();
        cout<<"\n\nCHECKMATE ! WHITE WON !!";
        game = false;
}

int main()
{
    start();
    white_king_i = 7;
    white_king_j = 17;
    black_king_i = 0;
    black_king_j = 17;
    bool MOVE = true;

    cout<<"<------RULES------>";
    cout<<"\nEnter 'P','R','N','B','Q' and 'K' for white's pawn,rook,knight,bishop,queen and king respectively.";
    cout<<"\nEnter 'p','r','n','b','q' and 'k' for black's pawn,rook,knight,bishop,queen and king respectively.";
    cout<<"\nExample of a pawn capture - Pexd5(white) pdxe4(black)";
    cout<<"\nNo need to Mention '+' for check,the computer will understand on its own.";
    cout<<"\n\nPress any key to continue";
    getch();

    while(game)
    {
        system("cls");
        board();
        string m;

        if(MOVE)
        {
            cout<<"\n\nWhite to Play !";
        }
        else
        {
            cout<<"\n\nBlack to Play !";
        }
        cout<<"\n\nEnter your move : ";
        cin>>m;

        int move_check;
        int i,j;
        if(m.size()==3)
        {
            i = Rank(m[m.size()-1]);
            j = file(m[m.size()-2]);
            move_check = arr[i][j];
        }
        else if(m.size()>3)
        {
            if(m[1]>='a' && m[1]<='h' && m[2]>='1' && m[2]<='8')
            {
               i = Rank(m[2]);
               j = file(m[1]);
               move_check = arr[i][j];
            }
            else if(m[m.size()-1]>='1' && m[m.size()-1]<='8' && m[m.size()-2]>='a' && m[m.size()-2]<='h')
            {
                i = Rank(m[m.size()-1]);
                j = file(m[m.size()-2]);
                move_check = arr[i][j];
            }
            else
            {
            cout<<"Invalid Move...press any key to continue";
            getch();
            continue;
            }
        }
        else
        {
            cout<<"Invalid Move...press any key to continue";
            getch();
            continue;
        }

        if(MOVE)
        {
            switch(m[0])
        {
        case 'P':
            pawn(m);
            break;
        case 'R':
            rook(m);
            break;
        case 'B':
            bishop(m);
            break;
        case 'Q':
            queen(m);
            break;
        case 'K':
            king(m);
            break;
        case 'k':
            bking(m);
            break;
        case 'N':
            knight(m);
            break;
        case 'O':
            castling(m);
            break;
        default:
            cout<<"Invalid Move...press any key to continue";
            getch();
            continue;
        }

            if(move_check==arr[i][j] && m[0] != 'O' && m[1] != '-' && m[2] != 'O')
            {
                cout<<"Invalid Move...press any key to continue";
                getch();
                continue;
            }
            MOVE = false;
            white_enpassant();

            if(black_check())
            {
                black_checkmate();
            }
        }
        else
        {
            switch(m[0])
        {
        case 'p':
            bpawn(m);
            break;
        case 'r':
            brook(m);
            break;
        case 'b':
            bbishop(m);
            break;
        case 'q':
            bqueen(m);
            break;
        case 'k':
            bking(m);
            break;
        case 'n':
            bknight(m);
            break;
        case 'o':
            bcastling(m);
            break;
        default:
            cout<<"Invalid Move..press any key to continue";
            getch();
            continue;
        }

             if(move_check==arr[i][j] && m[0] != 'o' && m[1] != '-' && m[2] != 'o')
            {
                cout<<"Invalid Move...press any key to continue";
                getch();
                continue;
            }

            MOVE = true;
            black_enpassant();

            if(white_check())
            {
                white_checkmate();
            }
        }
    }
    return 0;
}
