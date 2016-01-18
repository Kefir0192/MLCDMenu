#include "globalincludefile.h"
#include "lcdmenu.h"


// Clear Line
void (*pClear_Line)(uint8_t line);


//------------------------------------------------------
// Menu Drawing
//------------------------------------------------------
void Menu_Drawing(struct menu_main *pMenu_Main)
{
    if(!pMenu_Main) return;

    pMenu_Main->AddCharCursor = ' ';

    if(pMenu_Main->AllTopConstant) pMenu_Main->pCurrentMenu->pItems[0]->
        pMenu_Display(pMenu_Main->pCurrentMenu->pItems[0]->pName, 0);

    if(pMenu_Main->AllBottomConstant) pMenu_Main->pCurrentMenu->pItems[pMenu_Main->pCurrentMenu->length - 1]->
        pMenu_Display(pMenu_Main->pCurrentMenu->pItems[pMenu_Main->pCurrentMenu->length - 1]->pName, pMenu_Main->length - 1);


    for(uint8_t counter = 0; counter <= (pMenu_Main->EndCursor - pMenu_Main->StartCursor); counter++) {
        if(!pMenu_Main->pCurrentMenu->pItems[pMenu_Main->GeneralCounterCursor + counter] ||
           !pMenu_Main->pCurrentMenu->pItems[pMenu_Main->GeneralCounterCursor + counter]->pMenu_Display ||
           (pMenu_Main->pCurrentMenu->length == counter)) {
            pClear_Line(counter);
            return;
        }

        if(pMenu_Main->pCurrentMenu->pItems[pMenu_Main->GeneralCounterCursor + counter] ==
                pMenu_Main->pCurrentMenu->pItems[pMenu_Main->GeneralCounterCursor + pMenu_Main->CursorDisplay])
        {
            pMenu_Main->AddCharCursor = '>';
        } else pMenu_Main->AddCharCursor = ' ';

        pMenu_Main->pCurrentMenu->pItems[pMenu_Main->GeneralCounterCursor + counter]->
        pMenu_Display(pMenu_Main->pCurrentMenu->pItems[pMenu_Main->GeneralCounterCursor + counter]->pName, counter + pMenu_Main->StartCursor);
    }
}

//------------------------------------------------------
// Menu Up
//------------------------------------------------------
void Menu_Up(struct menu_main *pMenu_Main)
{
    if(!pMenu_Main) return;

    if(pMenu_Main->CursorDisplay != 0) {
        pMenu_Main->CursorDisplay--;
    } else {
        if(pMenu_Main->GeneralCounterCursor != pMenu_Main->StartCursor) pMenu_Main->GeneralCounterCursor--;
    }
}

//------------------------------------------------------
// Menu Down
//------------------------------------------------------
void Menu_Down(struct menu_main *pMenu_Main)
{
    if(!pMenu_Main) return;

    if(pMenu_Main->CursorDisplay < (pMenu_Main->EndCursor - pMenu_Main->StartCursor)) {
        if(pMenu_Main->CursorDisplay < pMenu_Main->pCurrentMenu->length - 1)
            pMenu_Main->CursorDisplay++;
    } else {
        if(pMenu_Main->AllBottomConstant) {
            if((pMenu_Main->GeneralCounterCursor + pMenu_Main->CursorDisplay + 2) < (pMenu_Main->pCurrentMenu->length))
                pMenu_Main->GeneralCounterCursor++;
        } else {
            if((pMenu_Main->GeneralCounterCursor + pMenu_Main->CursorDisplay + 1) < (pMenu_Main->pCurrentMenu->length))
                pMenu_Main->GeneralCounterCursor++;
        }
    }
}

//------------------------------------------------------
// Menu Left
//------------------------------------------------------
void Menu_Left(struct menu_main *pMenu_Main)
{
    if(!pMenu_Main) return;
    if(!pMenu_Main->pCurrentMenu->pParentMenu) return;

    pMenu_Main->pCurrentMenu = pMenu_Main->pCurrentMenu->pParentMenu;

    pMenu_Main->CursorDisplay = pMenu_Main->pCurrentMenu->CursorDisplay;
    pMenu_Main->GeneralCounterCursor = pMenu_Main->pCurrentMenu->GeneralCounterCursor;
}

//------------------------------------------------------
// Menu Right
//------------------------------------------------------
void Menu_Right(struct menu_main *pMenu_Main)
{
    if(!pMenu_Main) return;
    if(!pMenu_Main->pCurrentMenu->pItems[pMenu_Main->GeneralCounterCursor + pMenu_Main->CursorDisplay]) return;
    if(!pMenu_Main->pCurrentMenu->pItems[pMenu_Main->GeneralCounterCursor + pMenu_Main->CursorDisplay]->pSubMenu) return;


    pMenu_Main->pCurrentMenu->CursorDisplay = pMenu_Main->CursorDisplay;
    pMenu_Main->pCurrentMenu->GeneralCounterCursor = pMenu_Main->GeneralCounterCursor;

    pMenu_Main->pCurrentMenu = pMenu_Main->pCurrentMenu->pItems[pMenu_Main->GeneralCounterCursor + pMenu_Main->CursorDisplay]->pSubMenu;

    pMenu_Main->CursorDisplay = 0;
    pMenu_Main->GeneralCounterCursor = pMenu_Main->StartCursor;
}

//------------------------------------------------------
// Menu Enter
//------------------------------------------------------
void Menu_Enter(struct menu_main *pMenu_Main)
{
    if(!pMenu_Main) return;
    if(!pMenu_Main->pCurrentMenu->pItems[pMenu_Main->GeneralCounterCursor + pMenu_Main->CursorDisplay]->pMenu_Button) return;

    pMenu_Main->pCurrentMenu->pItems[pMenu_Main->GeneralCounterCursor + pMenu_Main->CursorDisplay]->pMenu_Button();
}
