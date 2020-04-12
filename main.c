#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
#include<conio.h>

#define mapheight 25
#define mapwidth 80
#define snakesize 100

struct
{
    int x;
    int y;
}food;
struct
{
    int x[snakesize];
    int y[snakesize];
    int length;
    int speed;
}snake;
int key='w';
int changement=0;

void gotoxy(int x,int y)
{
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(handle,coord);
}


void map()
{
    srand((unsigned int)time(NULL));
    int i=0;
    while(i<=mapheight)
    {
        gotoxy(0,i);
        printf("¨€");
        gotoxy(mapwidth,i);
        printf("¨€");
        i++;
    }
    i=0;
    while(i<=mapwidth)
    {
        gotoxy(i,0);
        printf("¨€");
        gotoxy(i,mapheight);
        printf("¨€");
        i+=2;
    }
    snake.length=3;
    snake.speed=200;
    snake.x[0]=mapwidth/2;
    snake.y[0]=mapheight/2;
    gotoxy(snake.x[0],snake.y[0]);
    printf("¨€");
    for(int k=1;k<snake.length;k++)
    {
        snake.x[k]=snake.x[k-1]+2;
        snake.y[k]=snake.y[k-1];
        gotoxy(snake.x[k],snake.y[k]);
        printf("¨€");
    }
    q:
    food.x=rand()%(mapwidth-4)+2;
    food.y=rand()%(mapheight-2)+1;
    if(food.x%2==0)
        {gotoxy(food.x,food.y);
        printf("¡Ñ");}
    else
        goto q;
    }


void createfood()
{
    if(snake.x[0]==food.x&&snake.y[0]==food.y)
    {
    srand((unsigned int)time(NULL));
    while(1)
    {
        int flag=1;
        food.x=rand()%(mapwidth-4)+2;
        food.y=rand()%(mapheight-2)+1;
        for(int k=0;k<snake.length;k++)
        {
            if(snake.x[k]==food.x&&snake.y[k]==food.y)
            {
            flag=0;
            break;
            }
        }
        if(flag&&food.x%2==0)
        break;

    }
    gotoxy(food.x,food.y);
    printf("¡Ñ");
    snake.length++;
    changement=1;
    }

}


void keydown()
{
    if(_kbhit())
    {
    fflush(stdin);
    key=_getch();
    }
    if(!changement)
    {
        gotoxy(snake.x[snake.length-1],snake.y[snake.length-1]);
        printf("  ");
    }
    for(int i=snake.length-1;i>0;i--)
    {
    snake.x[i]=snake.x[i-1];
    snake.y[i]=snake.y[i-1];
    }
    switch(key)
    {   case'w':snake.y[0]--;
        break;
        case's':snake.y[0]++;
        break;
        case'a':snake.x[0]-=2;
        break;
        case'd':snake.x[0]+=2;
        break;


    }gotoxy(snake.x[0],snake.y[0]);
        printf("¨€");
        changement=0;
    gotoxy(mapheight+2,0);
}
int snakestatus()
{
    if(snake.x[0]==2||snake.x[0]==mapwidth-2||snake.y[0]==1||snake.y[0]==mapheight-1)
    return 1;
    for(int k=1;k<snake.length;k++)
    {
        if(snake.x[0]==snake.x[k]&&snake.y[k]==snake.y[0])
            return 1;
    }
    return 0;
}

int main()
{
    map();
    while(1)
    {
    createfood();
    Sleep(snake.speed);
    keydown();
    if(snakestatus())
    {
        break;
    }




    }

    gotoxy(mapwidth/2,mapheight/2);
    printf("Gameover");


    return 0;
}
