#include "src/USBHost/JoystickController.h"

USBHost usb;

JoystickController dualshock(usb);

void buttonPressed(uint16_t buttons)
{
  if (buttons & X)
  {
    Serial.println("X button pressed");
  }
  if (buttons & R2)
  {
    Serial.println("Right trigger pressed");
  }
  if (buttons & L3)
  {
    Serial.println("Left stick pressed");
  }
  if (buttons & PS)
  {
    Serial.println("PlayStation button pressed");
  }
}

void buttonReleased(uint16_t buttons)
{
  if (buttons & X)
  {
    Serial.println("X button released");
  }
  if (buttons & R2)
  {
    Serial.println("Right trigger released");
  }
  if (buttons & L3)
  {
    Serial.println("Left stick released");
  }
  if (buttons & PS)
  {
    Serial.println("PlayStation button released");
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.println("Program started");
  delay(200);
}

void loop()
{
  usb.Task();

  /*Serial.print("ID: ");
  Serial.print((uint8_t) dualshock.state.id);
  Serial.print(" | X: ");
  Serial.print((uint8_t) dualshock.state.x);
  Serial.print(" | Circle: ");
  Serial.print((uint8_t) dualshock.state.circle);
  Serial.print(" | Triangle: ");
  Serial.print((uint8_t) dualshock.state.triangle);
  Serial.print(" | Square: ");
  Serial.print((uint8_t) dualshock.state.square);
  Serial.print(" | D Pad: ");
  Serial.print((uint8_t) dualshock.state.dPad);
  Serial.print(" | L1: ");
  Serial.print((uint8_t) dualshock.state.l1);
  Serial.print(" | R1: ");
  Serial.print((uint8_t) dualshock.state.r1);
  Serial.print(" | L2: ");
  Serial.print((uint8_t) dualshock.state.l2);
  Serial.print(" | R2: ");
  Serial.print((uint8_t) dualshock.state.r2);
  Serial.print(" | L3: ");
  Serial.print((uint8_t) dualshock.state.l3);
  Serial.print(" | R3: ");
  Serial.print((uint8_t) dualshock.state.r3);
  Serial.print(" | Share: ");
  Serial.print((uint8_t) dualshock.state.share);
  Serial.print(" | Options: ");
  Serial.print((uint8_t) dualshock.state.options);
  Serial.print(" | PS: ");
  Serial.print((uint8_t) dualshock.state.ps);
  Serial.print(" | T Pad: ");
  Serial.print((uint8_t) dualshock.state.tPad);
  Serial.print(" | Left X: ");
  Serial.print((uint8_t) dualshock.state.leftStickX);
  Serial.print(" | Left Y: ");
  Serial.print((uint8_t) dualshock.state.leftStickY);
  Serial.print(" | Right X: ");
  Serial.print((uint8_t) dualshock.state.rightStickX);
  Serial.print(" | Right Y: ");
  Serial.print((uint8_t) dualshock.state.rightStickY);
  Serial.print(" | Analog L2: ");
  Serial.print((uint8_t) dualshock.state.analogL2);
  Serial.print(" | Analog R2: ");
  Serial.print((uint8_t) dualshock.state.analogR2);
  Serial.println(" |");*/
}
