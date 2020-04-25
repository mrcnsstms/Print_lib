#include "Print_lib.h"

//////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////

void Print_lib::Begin(const uint32_t baud)
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

//////////////////////////////////////////////////////////////////////
// function doesn't work properly
void Print_lib::Print_array(const char* string,
                            const uint8_t array[],
                            const uint8_t length,
                            const uint8_t format)
{
  // TODO: if last char is not space space println
  m_port->print(string);
  Print_array(array, length, format);
}

void Print_lib::Print_array(const uint8_t array[],
                            const uint8_t length,
                            const uint8_t format)
{
  for(uint8_t i = 0; i < length; i++)
  {
    if(i != 0)
    {
      m_port->print(", ");
    }
    m_port->print(array[i], format);
  }
  m_port->println();
}

//////////////////////////////////////////////////////////////////////

void Print_lib::Print_msg(const char* string,
                          const Msg_data msg,
                          const uint8_t format)
{
  m_port->println(string);
  Print_msg(msg, format);
}

void Print_lib::Print_msg(const Msg_data msg, const uint8_t format)
{
  m_port->print("Valid: ");
  m_port->println(msg.valid, format);
  m_port->print("Frame type: ");
  m_port->println(msg.frame_type, format);
  m_port->print("Address: ");
  m_port->println(msg.address, format);
  m_port->print("Count: ");
  m_port->println(msg.payload_cnt, format);
  m_port->print("Payload id: ");
  m_port->println(msg.payload_id, format);
  m_port->print("Payload length: ");
  m_port->println(msg.payload_len, format);
  m_port->print("Payload: ");
  Print_array(msg.payload, sizeof(msg.payload));
  m_port->println();
}
