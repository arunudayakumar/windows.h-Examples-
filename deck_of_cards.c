//macros and header files,
#include<stdio.h>
#include<windows.h>
#define TEN 12
#define JOKER 2079
#define ACE 65
#define KING 75
#define QUEEN 81
#define JACK 74
#define HEART 3
#define SPADE 6
#define DIAMOND 4
#define CLUB 5
#define _NUM(a) (a+48)
int main()
{
    int allcards[14]={65,50,51,52,53,54,55,56,57,12,74,81,75,2079};
    int themeanddesign[5][2]={{192,3}/*red&black hearts*/,{126,36}/*grey&yellow dollor*/,{159,247}/*white&blue waves*/,{160,15}/*green&black gears*/,{233,227}/*yellow&blue pi*/};
    int i,j,x=1,y=1,_decktheme;
    COORD textpos;
    //COORD bufferSize = {70, 35};
    //SMALL_RECT windowSize = {0, 0, 69, 34};
    HANDLE out;
    //HWND console;
    //console=GetConsoleWindow();
    out=GetStdHandle(STD_OUTPUT_HANDLE);
    //MoveWindow(console, 0, 0,2000,720, TRUE);
    SetConsoleTitle("Deck of cards!");
    //SetConsoleWindowInfo(out, TRUE, &windowSize);
    //SetConsoleScreenBufferSize(out, bufferSize);
    /*printf("please maximize this screen first, then press enter to continue.....");
    getch();
    system("cls");*/

    for(i=0;i<5;i++)
    {
        textpos.X=18+i*8;
        textpos.Y=5;
        SetConsoleCursorPosition(out,textpos);
        printf("%d",i+1);
        printcardback(20+i*8,5,themeanddesign[i][0],themeanddesign[i][1]);
    }
    textpos.X=25;
    textpos.Y=3;
    SetConsoleCursorPosition(out,textpos);
    printf("Select the deck's theme: ");
    _decktheme=getch();
    system("cls");
    printcardback(x,y,themeanddesign[_decktheme-49][0],themeanddesign[_decktheme-49][1]);
    getch();
    Sleep(500);
    for(j=3;j<7;j++)
    {
        for(i=0;i<13;i++)
        {
            printcard(allcards[i],j,x,y);
            x=x+6;
            Sleep(100);
        }
        x=1;
        y=y+6;
    }
    getch();
    x=1;
    y=1;
    for(j=3;j<7;j++)
    {
        for(i=0;i<13;i++)
        {
            clear(x,y);
            x=x+6;
            Sleep(100);
        }
        x=1;
        y=y+6;
    }
    x=73;
    y=y-6;
    printcard(JOKER,3,x,y);
    getch();
    printcardback(x,y,themeanddesign[_decktheme-49][0],themeanddesign[_decktheme-49][1]);
    getch();
    return 0;
}
//function declarations
void printcard(int,int,int,int);
void printcardback(int,int,int,int);
void clear(int,int);
//void mouseclickregion(int,int);
//function definitions
void printcard(int value,int symbol,int x,int y)
{
    CHAR_INFO _card[25];
    char _cardmap[5][6]={"X    ",
                         "     ",
                         "  S  ",
                         "     ",
                         "    X"};
    COORD _cardsz={5,5},zerozero={0,0};
    SMALL_RECT rect;
    int i,j;
    rect.Left=x;
    rect.Right=x+5;
    rect.Top=y;
    rect.Bottom=y+5;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(_cardmap[i][j]==' ')
            {
                _card[j+5*i].Char.AsciiChar=' ';
                _card[j+5*i].Attributes=255;
            }
            if(_cardmap[i][j]=='S')
            {
                _card[j+5*i].Char.AsciiChar=symbol;
                if(symbol==3 || symbol==4)
                    _card[j+5*i].Attributes=252;
                else
                    _card[j+5*i].Attributes=240;
            }
            if(_cardmap[i][j]=='X')
            {
                if(value!=TEN)
                {
                    _card[j+5*i].Char.AsciiChar=value;
                    if(symbol==3 || symbol==4)
                        _card[j+5*i].Attributes=252;
                    else
                        _card[j+5*i].Attributes=240;
                }
            }
        }
    }
    if(value==TEN)
    {
        _card[0].Char.AsciiChar='1';
        _card[1].Char.AsciiChar='0';
        _card[24].Char.AsciiChar='0';
        _card[23].Char.AsciiChar='1';
        //
        if(symbol==3 || symbol==4)
        {
            _card[0].Attributes=252;
            _card[1].Attributes=252;
            _card[24].Attributes=252;
            _card[23].Attributes=252;
        }
        else
        {
            _card[0].Attributes=240;
            _card[1].Attributes=240;
            _card[24].Attributes=240;
            _card[23].Attributes=240;
        }
    }
    if(value==JOKER)
    {
        _card[0].Char.AsciiChar='J';
        _card[5].Char.AsciiChar='o';
        _card[10].Char.AsciiChar='k';
        _card[15].Char.AsciiChar='e';
        _card[20].Char.AsciiChar='r';
        _card[24].Char.AsciiChar='J';
        _card[19].Char.AsciiChar='o';
        _card[14].Char.AsciiChar='k';
        _card[9].Char.AsciiChar='e';
        _card[4].Char.AsciiChar='r';
        _card[12].Char.AsciiChar=2;
        //
        if(symbol==3 || symbol==4)
        {
            _card[0].Attributes=252;
            _card[5].Attributes=252;
            _card[10].Attributes=252;
            _card[15].Attributes=252;
            _card[20].Attributes=252;
            _card[24].Attributes=252;
            _card[19].Attributes=252;
            _card[14].Attributes=252;
            _card[9].Attributes=252;
            _card[4].Attributes=252;
            _card[12].Attributes=252;
        }
        else
        {
            _card[0].Attributes=240;
            _card[5].Attributes=240;
            _card[10].Attributes=240;
            _card[15].Attributes=240;
            _card[20].Attributes=240;
            _card[24].Attributes=240;
            _card[19].Attributes=240;
            _card[14].Attributes=240;
            _card[9].Attributes=240;
            _card[4].Attributes=240;
            _card[12].Attributes=240;
        }
    }
    WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE),_card,_cardsz,zerozero,&rect);
}
//
void printcardback(int x,int y,int _theme,int _design)
{
    CHAR_INFO _cardback[25];
    SMALL_RECT rect;
    COORD _cardbacksz={5,5},zerozero={0,0};
    int i,j;
    char _cardbackmap[5][6]={"  X  ",
                             " X X ",
                             "X X X",
                             " X X ",
                             "  X  "};
    for(i=0;i<5;i++)
    {
       for(j=0;j<5;j++)
       {
           if(_cardbackmap[i][j]=='X')
           {
               _cardback[j+i*5].Char.AsciiChar=_design;
               _cardback[j+i*5].Attributes=_theme;
           }
           else
           {
               _cardback[j+i*5].Char.AsciiChar=' ';
               _cardback[j+i*5].Attributes=_theme;
           }
       }
    }
    rect.Left=x;
    rect.Right=x+5;
    rect.Top=y;
    rect.Bottom=y+5;
    WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE),_cardback,_cardbacksz,zerozero,&rect);
}
//
void clear(int x,int y)
{
    CHAR_INFO _clear[25];
    SMALL_RECT rect;
    COORD _clearsz={5,5},zerozero={0,0};
    int i;
    for(i=0;i<25;i++)
    {
       _clear[i].Char.AsciiChar=' ';
       _clear[i].Attributes=7;
    }
    rect.Left=x;
    rect.Right=x+5;
    rect.Top=y;
    rect.Bottom=y+5;
    WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE),_clear,_clearsz,zerozero,&rect);
}
//
/*void mouseclickregion(int width,int height)
{

}
*/
