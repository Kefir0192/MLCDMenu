#ifndef LCDMENU
#define LCDMENU



// ���������� ����� ��������� �� �����
#define NUM_STRING  4
// ������� ��������
#define NUM_DOWN_AND_DOWN 4

#define MENU_CLEAR_LINE(a) pClear_Line = a

extern void (*pClear_Line)(uint8_t line);



struct menu_item {
    // ����� ����
    const char *pName;
    // ������� ->
    struct menu_sub *pSubMenu;
    // ����� �� �������
    void (*pMenu_Display)(const char *pData, uint8_t len);
    // ���������� ������� Enter
    void (*pMenu_Button)(void);
};

struct menu_sub {
    // ���������� ��������� (�����) � ������� �������
    uint8_t length;
    // �������� �������� ����� ������ � �������
    uint8_t CursorDisplay;
    uint8_t GeneralCounterCursor;
    // ��������� �� ���������� ������� (��������)
    struct menu_sub *pParentMenu;
    // ��������� �� ������ ��������� ����
    struct menu_item **pItems;
};

struct menu_main {
    // �� ���� ������� ������� ������ ���������
    enum BOOL AllTopConstant;
    // �� ���� ������� ������ ������ ���������
    enum BOOL AllBottomConstant;
    // ���������� ����� ��������� �� �����
    uint8_t length;
    // �������� ������� StartCursor � EndCursor
    uint8_t StartCursor;
    uint8_t EndCursor;
    // ������ �������
    uint8_t CursorDisplay;
    // ����� ������ ��� ���� ���������
    uint8_t GeneralCounterCursor;
    // ������ ������� ��� ������������
    char AddCharCursor;
    // ��������� �� ����
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

//// Элемент меню (строка)
//struct menu_item {
//    // Текст меню
//    const char *pName;
//    // вверх
//    struct menu_item *pUp;
//    // вниз
//    struct menu_item *pDown;
//    // вправо
//    struct menu_item *pRight;
//    // Указатель на функцию обработчик клавиш
//    void (*pFunButton)(struct menu_drawing *pMenu_drawing);
//    void (*pFunDisplay)(struct menu_drawing *pMenu_drawing, uint8_t line);
//    //
//    void *pVoid;
//};



//// Прорисовка дисплея
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

