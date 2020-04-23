#include "Print_lib.h"

Print_lib::Print_lib(SoftwareSerial* serial)
{
  m_hw = false;
  m_port = serial;
};

Print_lib::Print_lib(HardwareSerial* serial)
{
  m_hw = true;
  m_port = serial;
};


void Print_lib::Begin(uint32_t baud)
{
  if(m_hw)
  {
    static_cast<HardwareSerial*>(m_port)->begin(baud);
  }
  else
  {
    static_cast<SoftwareSerial*>(m_port)->begin(baud);
  }
}
