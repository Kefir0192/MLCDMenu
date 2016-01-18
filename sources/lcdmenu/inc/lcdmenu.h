#ifndef LCDMENU
#define LCDMENU



// Количество строк доступных на вывод
#define NUM_STRING  4
// Глубина вложений
#define NUM_DOWN_AND_DOWN 4

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




//// History menu item
//struct menu_history_item {
//    uint8_t string_counter;
//    struct menu_item *pHistory_item;
//};

//// Drawing menu
//struct menu_drawing {
//    uint8_t string_position;
//    uint8_t menu_start;
//    uint8_t menu_end;
//    uint8_t add_char;
//    // History menu item
//    uint8_t history_counter;
//    struct menu_history_item history_item[NUM_DOWN_AND_DOWN];
//    struct menu_item *pLcd_string[NUM_STRING];
//};

//// Р­Р»РµРјРµРЅС‚ РјРµРЅСЋ (СЃС‚СЂРѕРєР°)
//struct menu_item {
//    // РўРµРєСЃС‚ РјРµРЅСЋ
//    const char *pName;
//    // РІРІРµСЂС…
//    struct menu_item *pUp;
//    // РІРЅРёР·
//    struct menu_item *pDown;
//    // РІРїСЂР°РІРѕ
//    struct menu_item *pRight;
//    // РЈРєР°Р·Р°С‚РµР»СЊ РЅР° С„СѓРЅРєС†РёСЋ РѕР±СЂР°Р±РѕС‚С‡РёРє РєР»Р°РІРёС€
//    void (*pFunButton)(struct menu_drawing *pMenu_drawing);
//    void (*pFunDisplay)(struct menu_drawing *pMenu_drawing, uint8_t line);
//    //
//    void *pVoid;
//};



//// РџСЂРѕСЂРёСЃРѕРІРєР° РґРёСЃРїР»РµСЏ
////------------------------------------------------------
//void Menu_Drawing(struct menu_drawing *pMenu_drawing);

//// Menu Up
////------------------------------------------------------
//void Menu_Up(struct menu_drawing *pMenu_drawing);
//// Menu Down
////------------------------------------------------------
//void Menu_Down(struct menu_drawing *pMenu_drawing);
//// Menu Left
////------------------------------------------------------
//void Menu_Left(struct menu_drawing *pMenu_drawing);
//// Menu Right
////------------------------------------------------------
//void Menu_Right(struct menu_drawing *pMenu_drawing);
//// Menu Enter
////------------------------------------------------------
//void Menu_Enter(struct menu_drawing *pMenu_drawing);

#endif // LCDMENU

