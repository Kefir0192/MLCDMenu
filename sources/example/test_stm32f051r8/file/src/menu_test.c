#include "globalincludefile.h"
#include "main.h"
#include "phisic.h"
#include "hd44780.h"
#include "lcdmenu.h"
#include "menu_test.h"



//------------------------------------------------------
struct menu_main Menu_Main;
//------------------------------------------------------
extern struct menu_sub Menu_Sub_1;
extern struct menu_sub Menu_Sub_1_2;
//------------------------------------------------+-----
struct menu_item Menu_Item_1 = {"%cMain menu      ", &Menu_Sub_1_2, DisplayString, Test_Led};
struct menu_item Menu_Item_2 = {"%cStroka 1 %d    ", &Menu_Sub_1_2, DisplayString, Test_Led};
struct menu_item Menu_Item_3 = {"%cStroka 2 %d    ", &Menu_Sub_1_2, DisplayString, NULL};
struct menu_item Menu_Item_4 = {"%cStroka 3 %d    ", &Menu_Sub_1_2, DisplayString, NULL};
struct menu_item Menu_Item_5 = {"%cStroka 4 %d    ", &Menu_Sub_1_2, DisplayString, NULL};
struct menu_item Menu_Item_6 = {"%cStroka 5 %d    ", &Menu_Sub_1_2, DisplayString, NULL};
struct menu_item Menu_Item_7 = {"%cStroka 6 %d    ", &Menu_Sub_1_2, DisplayString, NULL};
struct menu_item Menu_Item_8 = {"%cStroka end     ", &Menu_Sub_1_2, DisplayString, NULL};

struct menu_item *pMenu_Items_1[] = {&Menu_Item_1, &Menu_Item_2, &Menu_Item_3, &Menu_Item_4, &Menu_Item_5,
                                     &Menu_Item_6, &Menu_Item_7, &Menu_Item_8};
//------------------------------------------------------
struct menu_item Menu_Item_1_1 = {"%cStroka start", NULL, DisplayString, NULL};
struct menu_item Menu_Item_1_2 = {"%cStroka 1_1", &Menu_Sub_1, DisplayString, NULL};
struct menu_item Menu_Item_1_3 = {"%cStroka 1_2", NULL, DisplayString, NULL};
struct menu_item Menu_Item_1_4 = {"%cStroka 1_3", NULL, DisplayString, NULL};
struct menu_item Menu_Item_1_5 = {"%cStroka end", NULL, DisplayString, NULL};

struct menu_item *pMenu_Items_1_1[] = {&Menu_Item_1_1, &Menu_Item_1_2, &Menu_Item_1_3, &Menu_Item_1_4, &Menu_Item_1_5};
//------------------------------------------------------
struct menu_sub Menu_Sub_1 = {8, 0, 0, NULL, pMenu_Items_1};

struct menu_sub Menu_Sub_1_2 = {5, 0, 0, &Menu_Sub_1, pMenu_Items_1_1};
//------------------------------------------------------



//------------------------------------------------------
// Init Menu
//------------------------------------------------------
void Init_Menu(void)
{
    MENU_CLEAR_LINE(Display_Clear_Line);

    Menu_Main.AllTopConstant = FALSE;
    Menu_Main.AllBottomConstant = FALSE;
    Menu_Main.length = 4;

    Menu_Main.StartCursor = 0;
    Menu_Main.EndCursor = 3;

    Menu_Main.AddCharCursor = ' ';

    Menu_Main.GeneralCounterCursor = Menu_Main.StartCursor;
    Menu_Main.CursorDisplay = 0;

    Menu_Main.pCurrentMenu = &Menu_Sub_1;
}

//------------------------------------------------------
// Обработчик событий
//------------------------------------------------------
void Event_Menu(uint8_t value)
{
    switch(value) {
        case UP: {
            Menu_Up(&Menu_Main);
            break;
        }
        case DOWN: {
            Menu_Down(&Menu_Main);
            break;
        }
        case LEFT: {
            Menu_Left(&Menu_Main);
            break;
        }
        case RIGHT: {
            Menu_Right(&Menu_Main);
            break;
        }
        case ENTER: {
            Menu_Enter(&Menu_Main);
            break;
        }
    }
}

//------------------------------------------------------
// Display Clear Line
//------------------------------------------------------
void Display_Clear_Line(uint8_t line)
{
    HD44780_Line_Position(line);
    xprintf("%-16s");
}

//------------------------------------------------------
// Display D
//------------------------------------------------------
void DisplayD(const char *pData, uint8_t line)
{
    HD44780_Line_Position(line);
    xprintf(pData, Menu_Main.AddCharCursor);
}

//------------------------------------------------------
// Display String
//------------------------------------------------------
void DisplayString(const char *pData, uint8_t line)
{
    HD44780_Line_Position(line);
    xprintf(pData, Menu_Main.AddCharCursor, Menu_Main.CursorDisplay);
}


//------------------------------------------------------
// Test Led
//------------------------------------------------------
void Test_Led(void)
{
    GPIOC->ODR ^= GPIO_ODR_8;
}
