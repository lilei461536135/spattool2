#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include <menu.h>
#include <sting>

struct menu_content
{
    string title;
    string choices[];
};

class Menu
{
private:
    menu_content mc;
public:
    Menu();
    ~Menu();

}


#endif // MENUS_H_INCLUDED
