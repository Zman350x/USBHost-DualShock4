#include "JoystickController.h"

extern "C" {
void __joystickControllerEmptyCallback(uint16_t __) { }
}

void buttonPressed(uint16_t buttons)  __attribute__ ((weak, alias("__joystickControllerEmptyCallback")));
void buttonReleased(uint16_t buttons)  __attribute__ ((weak, alias("__joystickControllerEmptyCallback")));

void printBuffer(uint32_t len, uint8_t *buf)
{
  for (uint8_t i = 0; i < 10; i++) {
    if (buf[i] < 16) {Serial.print("0");}
    Serial.print(buf[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
}

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

uint16_t isolateButtons(uint8_t * buf)
{
  return ((buf[5] & 0b11110000) << 6) + (buf[6] << 2) + (buf[7] & 0b00000011);
}

void JoystickController::Parse(HID *hid, bool is_rpt_id, uint32_t len, uint8_t *buf)
{
  TRACE_USBHOST(printf("CUSTOM PRINT (section 9) - Parsed\r\n");)
  //printBuffer(len, buf);
  memcpy(&state, buf, sizeof(state));
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
  //printBits(sizeof(buttons), &buttons);
  //Serial.println(buttons);

  previousButtonState = buttonState;
};
