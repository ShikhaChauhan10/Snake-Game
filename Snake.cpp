#include<iostream>
#include<conio.h>
using namespace std;
bool gameover;
const int width=40;
const int height=20;
int x,y, foodx,foody, score;
int tailx[100], taily[100];
int ntail;
enum Edirection { Stop=0, Right, Left, Up, Down};
Edirection dir;
void Setup()
{
gameover=false;
dir=Stop;
x=width/2;
y=height/2;
foodx=rand()%width;
foody=rand()%height;
score=0;
}
int Draw()
{
system("cls");

for(int i=0;i<width+2;i++)
cout<<"#";

cout<<endl;

for(int i=0;i<height;i++)
{
    for(int j=0;j<width;j++)
    {
     if(j==0)
     cout<<"#";
    
    if(i==y && j==x)
    cout<<"0";
    else if(i==foody && j==foodx)
    cout<<"*";
    else
     {
          bool print=false;
          for(int k=0;k<ntail;k++)
         {
            
             if(tailx[k]==j && taily[k]==i)
            { cout<<"o";
            print=true;
            }
            
         }
         if(!print)
            cout<<" ";
         
     }
      
      if(j==width-1)
      cout<<"#";
    }
    cout<<endl;
}
for(int i=0;i<width+2;i++)
cout<<"#";

cout<<endl;

cout<<"SCORE:"<<score<<endl;
}

void Input()
{
if(_kbhit())
{
    switch(_getch())
    {
        case 'w':dir=Up;
                 break;
        case 's':dir=Down;
                 break;
        case 'a':dir=Left;
                 break;
        case 'd':dir=Right;
                 break; 
        case 'x':gameover=true;
                 break;                          
    }
}
}

void Logic()
{
    int prevx= tailx[0];
    int prevy= taily[0];
    int prevx2 ,prevy2;
    tailx[0]=x;
    taily[0]=y;
    for(int i=1;i<ntail;i++)
    {
        prevx2=tailx[i];
        prevy2=taily[i];
        tailx[i]=prevx;
        taily[i]=prevy;
        prevx=prevx2;
        prevy=prevy2;
    }
switch(dir)
{

case Up:y--;
    break;
case Down:y++;
    break;
case Left:x--;
    break;
case Right:x++;
    break;                
}
if(x>width || x<0 || y>height || y<0)
gameover=true;

if(x==foodx && y==foody)
{
    score++;
    foodx=rand()%width;
    foody=rand()%height;
    ntail++;
}
}
int main()
{
Setup();
while(!gameover)
{
    Draw();
    Input();
    Logic();
}
return 0;
}
