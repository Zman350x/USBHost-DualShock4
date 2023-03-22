#include <DualShock4Controller.h>

USBHost usb;
DualShock4Controller dualshock(usb);

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
  if (buttons & PS)
  {
    Serial.println("PlayStation button released");
  }
}

void setup()
{
  Serial.begin(9600);
  Serial.println("Program started");
  delay(200);
}

void loop()
{
  usb.Task();

  Serial.print("D Pad: ");
  Serial.print((uint8_t) dualshock.state.dPad);
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
  Serial.println(" |");
}
