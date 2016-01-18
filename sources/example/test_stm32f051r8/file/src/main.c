#include "globalincludefile.h"
#include "main.h"
#include "phisic.h"
#include "hd44780.h"
#include "hd44780_portmacro.h"
#include "lcdmenu.h"
#include "menu_test.h"



//------------------------------------------------------
// Hardware initialization
//------------------------------------------------------
void Hardware_Init(void)
{
    // Initialize oscillator
    Oscillator_Init();
    // Initialization GPIO
    Port_Init();
    // enable irq
    __enable_irq();
}

unsigned  char  lcd_codepage[]=
{
  0x41,0xa0,0x42,0xa1,0xe0,0x45,0xa3,0xa4,
  0xa5,0xa6,0x4b,0xa7,0x4d,0x48,0x4f,0xa8,
  0x50,0x43,0x54,0xa9,0xaa,0x58,0xe1,0xab,
  0xac,0xe2,0xad,0xae,0x62,0xaf,0xb0,0xb1,
  0x61,0xb2,0xb3,0xb4,0xe3,0x65,0xb6,0xb7,
  0xb8,0xb9,0xba,0xbb,0xbc,0xbd,0x6f,0xbe,
  0x70,0x63,0xbf,0x79,0xe4,0x78,0xe5,0xc0,
  0xc1,0xe6,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,
};

void lcd_putc(unsigned char c)
{
    if ( c == 0xA8) {
      c = 0xA2;
    }
    else if ( c ==0xB8) {
      c = 0xB5;
    }
    else if ( c >= 0xC0 ) {
      c = lcd_codepage[ c - 0xC0 ];
    }
    //lcd_write(c);
    HD44780_Write_Byte(c);
}



//------------------------------------------------------
// MAIN
//------------------------------------------------------
int main(void)
{
    // Hardware initialization
    Hardware_Init();
    UART_Init(SP_9600);
    xdev_out(lcd_putc);

    // Delay init
    HD44780_Delay(0xfff);
    HD44780_CMD(D_SET);
    HD44780_CMD(I_D_SET);
    HD44780_CMD(CLEAR);
    HD44780_CMD(RETURN);
    HD44780_CMD(DL_SET | N_SET);
    HD44780_Cursor_Position(0);

    GPIOA->ODR &= ~GPIO_ODR_3;
    xprintf("Test");

    Init_Menu();

    while(1) {
        uint8_t buttons = (GPIOB->IDR  >> 2) & 0x1f;
        Event_Menu(buttons);
        Menu_Drawing(&Menu_Main);
    }
}

