#include "Arduino.h"
#include "LCD_EL.h"

LCD_EL::LCD_EL(int rs, int rw, int enable,int db0, int db1, int db2,int db3, int db4, int db5, int db6, int db7)
{
  rs=_RS;
  rw=_RW;
  enable=_Enable;

  _DB0 = db0;
  _DB1 = db1;
  _DB2 = db2;
  _DB3 = db3;
  _DB4 = db4;
  _DB5 = db5;
  _DB6 = db6;
  _DB7 = db7;

}

void LCD_EL::LCD_test(int tosi){
  pinMode(13,OUTPUT);
  digitalWrite(13,tosi);
  delay(500);
  digitalWrite(13,LOW);
  delay(500);
  digitalWrite(13,tosi);
  }

void LCD_EL::LCD_cmd_set(int data7, int data6, int data5, int data4, int data3, int data2, int data1, int data0){
 digitalWrite(_DB0,data0);
 digitalWrite(_DB1,data1);
 digitalWrite(_DB2,data2);
 digitalWrite(_DB3,data3);
 digitalWrite(_DB4,data4);
 digitalWrite(_DB5,data5);
 digitalWrite(_DB6,data6);
 digitalWrite(_DB7,data7);

 delayMicroseconds(50);
 digitalWrite(_Enable, 1);
 delayMicroseconds(50);    // Timing Spec?
 digitalWrite(_Enable, 0);
 }

int LCD_EL::LCD_check_busy(){
  int val;
  digitalWrite(_RW,1);
  val=digitalRead(_DB7);
  return val;
}

void LCD_EL::LCD_init(){
  pinMode(_RS, OUTPUT);
  pinMode(_RW, OUTPUT);
  pinMode(_Enable, OUTPUT);

 digitalWrite(_RS,LOW);
 digitalWrite(_Enable,LOW);
 digitalWrite(_RW,LOW);

 delayMicroseconds(50000);

 pinMode(_DB0, OUTPUT);
 pinMode(_DB1, OUTPUT);
 pinMode(_DB2, OUTPUT);
 pinMode(_DB3, OUTPUT);
 pinMode(_DB4, OUTPUT);
 pinMode(_DB5, OUTPUT);
 pinMode(_DB6, OUTPUT);
 pinMode(_DB7, OUTPUT);

 digitalWrite(_DB4,0);
 digitalWrite(_DB5,0);
 digitalWrite(_DB6,0);
 digitalWrite(_DB7,0);

 Serial.println("Initialization");
   pinMode(_DB7,INPUT);
   int val;
   digitalWrite(_RW,1);
   val=digitalRead(_DB7);
   pinMode(_DB7,OUTPUT);
Serial.println(val);
 Serial.println("finish");

 LCD_cmd_set(0,0,0,0,0,0,0,0);
 LCD_cmd_set(0,0,1,1,1,0,0,0);

 Serial.println("Function set");
   pinMode(_DB7,INPUT);
   int val;
   digitalWrite(_RW,1);
   val=digitalRead(_DB7);
   pinMode(_DB7,OUTPUT);
Serial.println(val);
 Serial.println("finish");

//ここまでシリアルモニタでcheck_busyフラグが0になるのを確認した


 // delayMicroseconds(100);
 // LCD_cmd_set(0,0,1,1,1,0,0,0);
 // delayMicroseconds(100);
 // LCD_cmd_set(0,0,1,1,1,0,0,0);
 //ここまでで8bit 確定

 LCD_cmd_set(0,0,1,1,1,1,0,0); //DB3_1_2lines DB3_0_1line
 delayMicroseconds(100);
 LCD_cmd_set(0,0,0,0,1,1,0,1); //DB2_1_Display_on DB2_0_Display_off DB1_Cu
 delayMicroseconds(100);
 LCD_clear();
 LCD_cmd_set(0,0,0,0,0,0,1,0); //RETURN HOME
 delayMicroseconds(100);
 LCD_cmd_set(0,0,0,0,0,1,1,0);

}

void LCD_EL::LCD_clear(){
LCD_cmd_set(0,0,0,0,0,0,0,1);
}
