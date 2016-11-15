#include <iostream>
#include <ncurses.h>
#include <stdlib.h>

using namespace std;

WINDOW **create_main_win();

int main()
{
    create_main_win();
    getch();
    endwin();
}

WINDOW **create_main_win()
{
    WINDOW **items;
    items = new WINDOW* [4];
    int height, width, starty, startx;

    initscr();          /* Initialize standard screen */
    if(has_colors() == FALSE)
    {
        endwin();
        printf("Your terminal does not support color\n");
        exit(-1);
    }
    start_color();      /* start color */

    /* Initialize color pairs */
    init_pair(1, COLOR_BLACK, COLOR_BLUE);      /* blue  black */
    init_pair(2, COLOR_RED, COLOR_BLUE);        /* red   black */
    init_pair(3, COLOR_YELLOW, COLOR_WHITE);    /* white yellow */
    init_pair(4, COLOR_BLUE, COLOR_WHITE);      /* white blue */
    init_pair(5, COLOR_BLACK, COLOR_WHITE);     /* white black */
    init_pair(6, COLOR_BLACK, COLOR_RED);       /* red   black */
    init_pair(7, COLOR_YELLOW, COLOR_RED);      /* red   yellow */

    curs_set(0);    /* close curs */
    noecho();
    keypad(stdscr, TRUE);
    refresh();

    height = 20;
    width = 60;
    startx = (COLS - width) / 2;
    starty = (LINES - height) / 2;
    items[0] = newwin(height, width, starty, startx);
    wbkgd(items[0], COLOR_PAIR(1));    /* set background color */
    wrefresh(items[0]);



    return items;
}

