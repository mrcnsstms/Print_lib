#ifndef Print_lib_h
#define Print_lib_h

#include "Xbee_lib_defs.h"
#include "SoftwareSerial.h"

class Print_lib
{
public:
  Print_lib(SoftwareSerial* ss);

  Print_lib(HardwareSerial* ss);

  void Begin(const uint32_t baud);

  template <typename T>
  void  Print(const T x)
  {
    m_port->print(x);
  }

  void Println()
  {
    m_port->println();
  }

  template <typename T>
  void  Println(const T x)
  {
    m_port->println(x);
  }

  template <typename T, typename U>
  void  Println(const T x, const U y)
  {
    m_port->print(x);
    m_port->println(y);
  }

  void Print_array(const char* string,
                   const uint8_t array[],
                   const uint8_t length,
                   const bool hex);

  void Print_array(const uint8_t array[],
                   const uint8_t length,
                   const bool hex = true);


  void Print_msg(const Msg_data msg, bool hex);

  void Print_msg(const char* string, const Msg_data msg, bool hex);

protected:

private:
  bool m_hw;
  Stream* m_port;
};

#endif
