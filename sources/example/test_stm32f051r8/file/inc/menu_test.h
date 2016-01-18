#ifndef MENU_TEST
#define MENU_TEST



#define UP      8
#define DOWN    2
#define LEFT    1
#define RIGHT   16
#define ENTER   4


extern struct menu_main Menu_Main;



// Init Menu
//------------------------------------------------------
void Init_Menu(void);
// Обработчик событий
//------------------------------------------------------
void Event_Menu(uint8_t value);

// Display Clear Line
//------------------------------------------------------
void Display_Clear_Line(uint8_t line);
// Display D
//------------------------------------------------------
void DisplayD(const char *pData, uint8_t line);
// Display String
//------------------------------------------------------
void DisplayString(const char *pData, uint8_t line);

// Test Led
//------------------------------------------------------
void Test_Led(void);

#endif // MENU_TEST

