#ifndef Print_lib_h
#define Print_lib_h

///#include "Arduino.h"
#include "Xbee_lib_defs.h"
#include "SoftwareSerial.h"

class Print_lib
{
public:
  Print_lib(SoftwareSerial* ss);
  Print_lib(HardwareSerial* ss);
  void Begin(uint32_t baud);

  template <typename T>
  void  Print(T x)
  {
    m_port->print(x);
  }

  template <typename T>
  void  Println(T x)
  {
    m_port->println(x);
  }

  template <typename T, typename U>
  void  Println(T x, U y)
  {
    m_port->print(x);
    m_port->println(y);
  }

protected:

private:
  bool m_hw;
  Stream* m_port;
};

#endif
