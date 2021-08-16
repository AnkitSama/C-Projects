//tic tac toe
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

int check(char [],char);
int Move(char []);
int checkfor2waywin(char []);

int main()
{
    cout<<"1 | 2 | 3"<<endl
        <<"---------"<<endl
        <<"4 | 5 | 6"<<endl
        <<"---------"<<endl
        <<"7 | 8 | 9"<<endl
        <<"---------"<<endl;
    cout<<endl;
    cout<<"Enter the number where you want to play !"<<endl;
    cout<<"Ex :- If you want to play on the 2nd square enter '2'"<<endl;
    cout<<"Press any key to continue...";
    getch();
    system("cls");

    char m[9],m1[9];
    int a;

    for(int i=0;i<9;i++)
        m[i]=' ';

    do{
    cout<<"Enter your move:"; //first move
    cin>>a;

    if(a<1 || a>9){
        cout<<"Invalid move\n";
    }
    }while(a<1 || a>9);

    m[a-1]= 'x';

    if(a==5){
        m[0]='0';
        cout<<"Computer plays:1\n"; //second move
    }
    else{
        m[4]='0';
        cout<<"Computer plays:5\n"; //second move
    }

    for(int j=0;j<9;j++){
        m1[j] = m[j];
    }


    //third move and onwards
    for(int i=1;i<=4;i++){

    if(i==4)
    {
        cout<<"Enter your move:";   //last move
        cin>>a;
        cout<<"Game Draw"<<endl;
        break;

    }



    cout<<"Enter your move:";   //third move,fifth move and so on
    cin>>a;

    m[a-1]='x';

    for(int j=0;j<9;j++){
        m1[j] = m[j];
    }

    if(i==1){
    a=check(m1,'x');

    if(a != 9){
    cout<<"Computer plays:"<<a+1<<endl;
    m[a]='0';
    }
     else{
        a=Move(m1);
        cout<<"Computer plays:"<<a+1<<endl;
        m[a]='0';
    }

    }
    else{
        a=check(m1,'0');
        if(a != 9){
        cout<<"Computer plays:"<<a+1<<" and WINS"<<endl; //COMPUTER WINS
        break;
        }
        else{

         a=check(m1,'x');
        if(a != 9){
        cout<<"Computer plays:"<<a+1<<endl;
        m[a]='0';
        }
        else{
        a=Move(m1);
        cout<<"Computer plays:"<<a+1<<endl;
        m[a]='0';
        }
        }
    }
    }

    return 0;
}

int check(char m[],char c)
{
    if(m[0]==' ' && m[1]==c && m[2]==c)
        return 0;
    else if(m[0]==c && m[1]==' ' && m[2]==c)
        return 1;
    else if(m[0]==c && m[1]==c && m[2]==' ')
        return 2;
    else if(m[3]==' ' && m[4]==c && m[5]==c)
        return 3;
    else if(m[3]==c && m[4]==' ' && m[5]==c)
        return 4;
    else if(m[3]==c && m[4]==c && m[5]==' ')
        return 5;
    else if(m[6]==' ' && m[7]==c && m[8]==c)
        return 6;
    else if(m[6]==c && m[7]==' ' && m[8]==c)
        return 7;
    else if(m[6]==c && m[7]==c && m[8]==' ')
        return 8;
    else if(m[0]==' ' && m[4]==c && m[8]==c)
        return 0;
    else if(m[0]==c && m[4]==' ' && m[8]==c)
        return 4;
    else if(m[0]==c && m[4]==c && m[8]==' ')
        return 8;
    else if(m[2]==' ' && m[4]==c && m[6]==c)
        return 2;
    else if(m[2]==c && m[4]==' ' && m[6]==c)
        return 4;
    else if(m[2]==c && m[4]==c && m[6]==' ')
        return 6;
    else if(m[0]==' ' && m[3]==c && m[6]==c)
        return 0;
    else if(m[0]==c && m[3]==' ' && m[6]==c)
        return 3;
    else if(m[0]==c && m[3]==c && m[6]==' ')
        return 6;
    else if(m[1]==' ' && m[4]==c && m[7]==c)
        return 1;
    else if(m[1]==c && m[4]==' ' && m[7]==c)
        return 4;
    else if(m[1]==c && m[4]==c && m[7]==' ')
        return 7;
    else if(m[2]==' ' && m[5]==c && m[8]==c)
        return 2;
    else if(m[2]==c && m[5]==' ' && m[8]==c)
        return 5;
    else if(m[2]==c && m[5]==c && m[8]==' ')
        return 8;
    else
        return 9;

}

int Move(char m[])
{
    char m1[9];
    for(int j=0;j<9;j++)
        m1[j]=m[j];

    int a,i=0;
    while(true){
    for(;i<9;i++){
        if(m1[i]==' '){
            m1[i]='0';
            break;
        }
    }
    a=checkfor2waywin(m1);
    if(a==2){
        for(int j=0;j<9;j++)
        m1[j]=m[j];
        i++;
        continue;
    }
    else{
        break;
    }
    }
    return i;
}

int checkfor2waywin(char m[])
{
    int counter=0;
    char c='x';
    for(int i=0;i<9;i++){


    if(m[i]==' ')
    {
        m[i] = c;

    if(m[0]==' ' && m[1]==c && m[2]==c)
        counter++;
    if(m[0]==c && m[1]==' ' && m[2]==c)
        counter++;
    if(m[0]==c && m[1]==c && m[2]==' ')
        counter++;
    if(m[3]==' ' && m[4]==c && m[5]==c)
        counter++;
    if(m[3]==c && m[4]==' ' && m[5]==c)
        counter++;
    if(m[3]==c && m[4]==c && m[5]==' ')
        counter++;
    if(m[6]==' ' && m[7]==c && m[8]==c)
        counter++;
    if(m[6]==c && m[7]==' ' && m[8]==c)
        counter++;
    if(m[6]==c && m[7]==c && m[8]==' ')
        counter++;
    if(m[0]==' ' && m[4]==c && m[8]==c)
        counter++;
    if(m[0]==c && m[4]==' ' && m[8]==c)
        counter++;
    if(m[0]==c && m[4]==c && m[8]==' ')
        counter++;
    if(m[2]==' ' && m[4]==c && m[6]==c)
        counter++;
    if(m[2]==c && m[4]==' ' && m[6]==c)
        counter++;
    if(m[2]==c && m[4]==c && m[6]==' ')
        counter++;
    if(m[0]==' ' && m[3]==c && m[6]==c)
        counter++;
    if(m[0]==c && m[3]==' ' && m[6]==c)
        counter++;
    if(m[0]==c && m[3]==c && m[6]==' ')
        counter++;
    if(m[1]==' ' && m[4]==c && m[7]==c)
        counter++;
    if(m[1]==c && m[4]==' ' && m[7]==c)
        counter++;
    if(m[1]==c && m[4]==c && m[7]==' ')
        counter++;
    if(m[2]==' ' && m[5]==c && m[8]==c)
        counter++;
    if(m[2]==c && m[5]==' ' && m[8]==c)
        counter++;
    if(m[2]==c && m[5]==c && m[8]==' ')
        counter++;

    if(counter==2){
        int x; //to check for computer win
        x=check(m,'0');
        if(x==9){

        return 2;
        }
        else{
            return 1;
        }
    }
    else{
        counter = 0;
        m[i]=' ';
    }
    }
    }
    return 1;

}
