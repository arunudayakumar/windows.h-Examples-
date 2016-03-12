#include<stdio.h>
#include<windows.h>
int main()
{
    char grid[24][80]={"                                                                               ",
                       "                                                                               ",
                       "                                                                               ",
                       "                                                                               ",
                       "                                                                               ",
                       "                                                                               ",
                       "                                                                               ",
                       "                                                                               ",
                       "                                                                               ",
                       "                                                                               ",
                       "                                                                               ",
                       "                                                                               ",
                       "                                                                               ",
                       "                                                                               ",
                       "                                                                               ",
                       "                                                                               ",
                       "                                                                               ",
                       "                                                                               ",
                       "                                                                               ",
                       "                                                                               ",
                       "                                                                               ",
                       "                                                                               ",
                       "                                                                               ",
                       "                X                                                              ",};
    int i,j;
    COORD pos={0,0};
    CHAR_INFO buffer[1896];
    SMALL_RECT rect={0,0,79,24};
    COORD sz={79,24},zerozero={0,0};
    SetConsoleTitle("Snowfall! ^_^");
    srand(time(NULL));
    while(1)
    {
        grid[23][rand()%79]='X';
        for(i=0;i<24;i++)
        {
            for(j=0;j<79;j++)
            {
                if(grid[i][j]=='X')
                {
                    buffer[1895 - j - 78*i].Char.AsciiChar='*';
                    buffer[1895 - j - 78*i].Attributes=15;
                }
                else
                {
                    buffer[1895 - j - 78*i].Char.AsciiChar=' ';
                    buffer[1895 - j - 78*i].Attributes=15;
                }
            }
        }
        WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE),buffer,sz,zerozero,&rect);
        Sleep(50);
        for(i=0;i<24;i++)
        {
            for(j=0;j<79;j++)
            {
                if(grid[i][j]=='X')
                {
                    grid[i][j]=' ';
                    grid[i-1][j]='X';
                }
            }
        }
    }
    return 0;
}
