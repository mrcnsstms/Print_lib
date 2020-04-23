#include "Print_lib.h"
#include "SoftwareSerial.h"

SoftwareSerial sSerial(7,8);
Print_lib m_print_sw(&sSerial);

void setup()
{
  m_print_sw.Begin(19200);
}

void loop()
{
  m_print_sw.Print("abc");
  m_print_sw.Println(7);
  m_print_sw.Println("abc ", 7);
  delay(1000);
}
