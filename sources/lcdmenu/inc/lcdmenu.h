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



#endif // LCDMENU

