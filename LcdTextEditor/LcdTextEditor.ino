/*  draw text's APP
 drawChar(INT8U ascii,INT16U poX, INT16U poY,INT16U size, INT16U fgcolor);
 drawString(char *string,INT16U poX, INT16U poY,INT16U size,INT16U fgcolor);
 */

#include <stdint.h>
#include <TFTv2.h>
#include <SPI.h>
#include "TextEditor.h"

TextEditor te(10, 10);

void setup()
{
  Serial.begin(9600);
  TFT_BL_ON;      // turn on the background light
  Tft.TFTinit();  // init TFT library
  te.init();
}

char *msg = "Hello \nworx\bx\bld\nwow!";
int i = 0;
int i2 = 0;
void loop()
{
  while(i2 > 2);
  if(msg[i] == '\0') {
    i = 0;
    i2++;
  }
  Serial.print(msg[i]);
  te.typeChar(msg[i]);
  i++;
  delay(100);
}




