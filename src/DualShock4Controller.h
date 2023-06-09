#ifndef DUALSHOCK_CONTROLLER_H
#define DUALSHOCK_CONTROLLER_H

#include "hidboot.h"

enum Buttons {
	PS = 1,
	TPAD = 2,
	L1 = 4,
	R1 = 8,
	L2 = 16,
	R2 = 32,
	SHARE = 64,
	OPTIONS = 128,
    L3 = 256,
    R3 = 512,
    SQUARE = 1024,
    X = 2048,
    CIRCLE = 4096,
    TIRANGLE = 8192
};

struct JOYSTICKINFO
{
  uint8_t id;

  union
  {
    struct
    {
      int8_t leftStickX;
      int8_t leftStickY;
      int8_t rightStickX;
      int8_t rightStickY;
    };;
    int8_t axes[4];
  };

  uint8_t dPad : 4;
  uint8_t square : 1;
  uint8_t x : 1;
  uint8_t circle : 1;
  uint8_t triangle : 1;

  uint8_t l1 : 1;
  uint8_t r1 : 1;
  uint8_t l2 : 1;
  uint8_t r2 : 1;
  uint8_t share : 1;
  uint8_t options : 1;
  uint8_t l3 : 1;
  uint8_t r3 : 1;

  uint8_t ps : 1;
  uint8_t tPad : 1;
  uint8_t _dummy : 6;

  uint8_t analogL2;
  uint8_t analogR2;
};

class DualShock4Controller : public HIDReportParser
{
public:
  DualShock4Controller(USBHost &usb) : hostJoystick(&usb), previousButtonState(0), deadzone(0) {
    hostJoystick.SetReportParser(0, this);
  }
  virtual void Parse(HID *hid, bool is_rpt_id, uint32_t len, uint8_t *buf);
  void setAxisDeadzone(int8_t new_deadzone);

  JOYSTICKINFO state;
  int8_t dPadAxes[2];
  
private:
  HIDBoot<0x00, HID_PROTOCOL_NONE> hostJoystick;

  uint16_t isolateButtons(uint8_t * buf);
  void alignAxes();
  void formatDPad();

  uint16_t previousButtonState;
  int8_t deadzone;
};

#endif
