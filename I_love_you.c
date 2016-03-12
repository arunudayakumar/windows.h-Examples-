/*Valentine's Day Special
"I love You"
Made By: Shivam Shekhar
*/
#include<stdio.h>
#include<windows.h>
#include<conio.h>
int main()
{
    int xyzknc[12][21]=
                    {
                        {0,0,3,3,3,3,0,0,0,0,00,0,0,0,0,3,3,3,3,0,0},
                        {0,3,3,3,3,3,3,3,0,0,00,0,0,3,3,3,3,3,3,3,0},
                        {3,3,3,3,3,3,3,3,3,0,00,0,3,3,3,3,3,3,3,3,3},
                        {3,3,3,3,3,3,3,3,3,3,03,3,3,3,3,3,3,3,3,3,3},
                        {0,3,3,3,3,3,3,3,3,3,03,3,3,3,3,3,3,3,3,3,0},
                        {0,0,3,3,3,3,3,3,3,3,03,3,3,3,3,3,3,3,3,0,0},
                        {0,0,0,3,3,3,3,3,3,3,03,3,3,3,3,3,3,3,0,0,0},
                        {0,0,0,0,0,3,3,3,3,3,03,3,3,3,3,3,0,0,0,0,0},
                        {0,0,0,0,0,0,3,3,3,3,03,3,3,3,3,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,3,3,03,3,3,3,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,3,03,3,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,03,0,0,0,0,0,0,0,0,0,0},
                    },e=0,i,j;
    COORD a={20,5},b={50,10},d,f={0,0};
    HANDLE in,out;
    DWORD info;
    CONSOLE_SCREEN_BUFFER_INFO scrinfo;
    INPUT_RECORD inp;
    GetConsoleScreenBufferInfo(out,&scrinfo);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
    in=GetStdHandle(STD_INPUT_HANDLE);
    out=GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(NULL));
    d.X=24;
    d.Y=8;
    SetConsoleCursorPosition(out,d);
    printf("%c",3);
    while(1)
    {
        SetConsoleMode(in,ENABLE_MOUSE_INPUT| ENABLE_PROCESSED_INPUT);
        ReadConsoleInput(in,&inp,1,&info);
        if(inp.EventType==MOUSE_EVENT)
        {
            if(inp.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                if(inp.Event.MouseEvent.dwMousePosition.X==d.X && inp.Event.MouseEvent.dwMousePosition.Y==d.Y)
                {
                    SetConsoleCursorPosition(out,d);
                    printf(" ");
                    d.X=rand()%80;
                    d.Y=rand()%24;
                    SetConsoleCursorPosition(out,d);
                    printf("%c",3);
                    e++;
                }
            }
        }
        if(e==5)
            break;
    }
    system("cls");
    for(i=0;i<12;i++)
    {
        SetConsoleCursorPosition(out,a);
        for(j=0;j<21;j++)
        {
            printf("%c",xyzknc[i][j]);
        }
        printf("\n");
        Sleep(150);
        a.Y++;
    }
    SetConsoleCursorPosition(out,b);
    printf("I love You!");
    getch();
    SetConsoleCursorPosition(out,f);
    return 0;
}
