#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define ORIGINX 0
#define ORIGINY 24
#define X(x) x-ORIGINX
#define Y(x) ORIGINY-x
int main()
{
    HANDLE in;
    HANDLE out;
    INPUT_RECORD input;
    COORD pos;
    DWORD info;
    CONSOLE_SCREEN_BUFFER_INFO screenInfo;
    in=GetStdHandle(STD_INPUT_HANDLE);
    out=GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(out, &screenInfo);
    SetConsoleMode(in, ENABLE_PROCESSED_INPUT);
    int i,j=22,T;
    float temp,v,u=0,G=10,t=0;
    system("color 37");
    pos.X=30;
    pos.Y=10;
    SetConsoleCursorPosition(out,pos);
    printf("gravity simulation");
    pos.Y=11;
    SetConsoleCursorPosition(out,pos);
    printf("press any key to continue........");
    getch();
    system("cls");
    system("color 07");
    pos.Y=Y(-1);
    for(i=0;i<80;i++)
    {
        pos.X=i;
        SetConsoleCursorPosition(out,pos);
        printf("-");
    }
    SetConsoleTextAttribute(out,FOREGROUND_RED|FOREGROUND_INTENSITY);
    pos.X=X(20);
    pos.Y=Y(22);
    SetConsoleCursorPosition(out,pos);
    printf("o");
    SetConsoleCursorPosition(out,pos);
    printf(" ");
    for(;;)
    {
    u=0;
    for(i=j;0<=i;i--)
    {
        t=0;
        pos.Y=Y(i);
        SetConsoleCursorPosition(out,pos);
        printf("o");
        for(;;)
        {
            if(u*t + (G*t*t)/2 > 0.1)
                {printf("     %f",t);
                break;}
            else
                t=t+0.001;
        }
        temp=u;
        u=v;
        v = temp + G*t;
        T=t*1000;
        delay(T);
        SetConsoleCursorPosition(out,pos);
        printf(" ");
    }
    u=v;
    /*j=(j/4)*3;
    if(j<1)
        break;*/
    for(i=0;i<=j;i++)
    {
        t=0;
        pos.Y=Y(i);
        SetConsoleCursorPosition(out,pos);
        printf("o");
        for(;;)
        {
            if(u*t - (G*t*t)/2 > 0.1)
                {printf("     %f",t);
                break;}
            else
                t=t+0.001;
        }
        temp=u;
        u=v;
        v = temp - G*t;
        T=t*1000;
        delay(T);
        SetConsoleCursorPosition(out,pos);
        printf(" ");
    }
    }
    getch();
    return 0;
}
void delay(int);
void delay(int a)
{
    clock_t start;
    start=clock();
    while(clock()-start < a)
    {

    }
}



