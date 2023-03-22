#include "DualShock4Controller.h"

extern "C" {
void __joystickControllerEmptyCallback(uint16_t __) { }
}

void buttonPressed(uint16_t buttons)  __attribute__ ((weak, alias("__joystickControllerEmptyCallback")));
void buttonReleased(uint16_t buttons)  __attribute__ ((weak, alias("__joystickControllerEmptyCallback")));

uint16_t DualShock4Controller::isolateButtons(uint8_t * buf)
{
  return ((buf[5] & 0b11110000) << 6) + (buf[6] << 2) + (buf[7] & 0b00000011);
}

void DualShock4Controller::alignAxes()
{
  for (uint8_t i = 0; i < 4; i++)
  {
    state.axes[i] ^= 0b10000000;
  }
  state.leftStickY = ~state.leftStickY;
  state.rightStickY = ~state.rightStickY;

  for (uint8_t i = 0; i < 4; i++)
  {
    if (-deadzone < state.axes[i] && state.axes[i] < deadzone)
    {
      state.axes[i] = 0;
    }
  }
}

void DualShock4Controller::formatDPad()
{
  switch (state.dPad)
  {
    case 0:
      dPadAxes[0] = 0;
      dPadAxes[1] = 1;
      break;
    case 1:
      dPadAxes[0] = 1;
      dPadAxes[1] = 1;
      break;
    case 2:
      dPadAxes[0] = 1;
      dPadAxes[1] = 0;
      break;
    case 3:
      dPadAxes[0] = 1;
      dPadAxes[1] = -1;
      break;
    case 4:
      dPadAxes[0] = 0;
      dPadAxes[1] = -1;
      break;
    case 5:
      dPadAxes[0] = -1;
      dPadAxes[1] = -1;
      break;
    case 6:
      dPadAxes[0] = -1;
      dPadAxes[1] = 0;
      break;
    case 7:
      dPadAxes[0] = -1;
      dPadAxes[1] = 1;
      break;
    default:
      dPadAxes[0] = 0;
      dPadAxes[1] = 0;
      break;
  }
}

void DualShock4Controller::Parse(HID *hid, bool is_rpt_id, uint32_t len, uint8_t *buf)
{
  memcpy(&state, buf, sizeof(state));
  alignAxes();
  formatDPad();

  uint16_t buttonState = isolateButtons(buf);

  uint16_t pressed = buttonState & (~previousButtonState);
  uint16_t released = (~buttonState) & previousButtonState;

  if (pressed)
  {
    buttonPressed(pressed);
  }
  if (released)
  {
    buttonReleased(released);
  }

  previousButtonState = buttonState;
};

void DualShock4Controller::setAxisDeadzone(int8_t new_deadzone)
{
  if (new_deadzone >= 0)
  {
    deadzone = new_deadzone;
  }
}
