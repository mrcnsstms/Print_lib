#include "Print_lib.h"
#include "SoftwareSerial.h"

SoftwareSerial sSerial(7,8);
Print_lib m_print_sw(&sSerial);
Print_lib m_print_hw(&Serial); // use Serial1, 2, or 3 on Mega

void setup()
{
  m_print_sw.Begin(19200);
  m_print_hw.Begin(19200);
}

void loop()
{
  m_print_sw.Print("abc");
  m_print_sw.Println(7);
  m_print_sw.Println("abc ", 7);
  delay(1000);
  m_print_hw.Print("abc");
  m_print_hw.Println(7);
  m_print_hw.Println("abc ", 7);
  delay(1000);
}
