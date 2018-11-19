/*
  LCD_EL.h - Library for LCD_EL
  Created by Natsumi Yamamoto, 10/16/2018
*/
#ifndef LCD_EL_h
#define LCD_EL_h

#include "Arduino.h"

class LCD_EL
{
  public:
    LCD_EL(int rs, int rw, int enable, int db0, int db1, int db2,int db3, int db4, int db5, int db6, int db7);
    void LCD_test(int tosi);
    void LCD_cmd_set(int data7, int data6, int data5, int data4, int data3, int data2, int data1, int data0);
    void LCD_init();
    void LCD_clear();
    int LCD_check_busy();

  private:
    int _RS;
    int _RW;
    int _Enable;
    int _DB0;
    int _DB1;
    int _DB2;
    int _DB3;
    int _DB4;
    int _DB5;
    int _DB6;
    int _DB7;
};

#endif
