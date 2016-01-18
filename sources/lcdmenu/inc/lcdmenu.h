#ifndef LCDMENU
#define LCDMENU


 
// Количество строк доступных на вывод
#define NUM_STRING  4
#define MENU_CLEAR_LINE(a) pClear_Line = a

extern void (*pClear_Line)(uint8_t line);



struct menu_item {
    // Текст меню
    const char *pName;
    // Подменю ->
    struct menu_sub *pSubMenu;
    // Вывод на дисплей
    void (*pMenu_Display)(const char *pData, uint8_t len);
    // Обработчик клавиши Enter
    void (*pMenu_Button)(void);
};

struct menu_sub {
    // Количество элементов (строк) в текущем подменю
    uint8_t length;
    // Значение счетчика перед входом в подменю
    uint8_t CursorDisplay;
    uint8_t GeneralCounterCursor;
    // Указатель на предыдущие подменю (родитель)
    struct menu_sub *pParentMenu;
    // Указатель на массив элементов меню
    struct menu_item **pItems;
};

struct menu_main {
    // Во всем подменю верхняя строка постоянна
    enum BOOL AllTopConstant;
    // Во всем подменю нижняя строка постоянна
    enum BOOL AllBottomConstant;
    // Количество строк доступных на вывод
    uint8_t length;
    // Диапазон курсора StartCursor и EndCursor
    uint8_t StartCursor;
    uint8_t EndCursor;
    // Курсор дисплея
    uint8_t CursorDisplay;
    // Общий курсор для всех элементов
    uint8_t GeneralCounterCursor;
    // Символ курсора для визуализации
    char AddCharCursor;
    // Указатель на меню
    struct menu_sub *pCurrentMenu;
};



// Menu Drawing
//------------------------------------------------------
void Menu_Drawing(struct menu_main *pMenu_Main);
// Menu Up
//------------------------------------------------------
void Menu_Up(struct menu_main *pMenu_Main);
// Menu Down
//------------------------------------------------------
void Menu_Down(struct menu_main *pMenu_Main);
// Menu Left
//------------------------------------------------------
void Menu_Left(struct menu_main *pMenu_Main);
// Menu Right
//------------------------------------------------------
void Menu_Right(struct menu_main *pMenu_Main);
// Menu Enter
//------------------------------------------------------
void Menu_Enter(struct menu_main *pMenu_Main);



#endif // LCDMENU

