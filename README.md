# USBHost Library with DualShock 4 support

*Compatible with Arduino Due only*

This library is based on the Arduino USBHost library: https://github.com/arduino-libraries/USBHost

This version of the USBHost library allows an Arduino Due board to appear as a USB host, enabling it to communicate with peripherals like USB mice, keyboards, and DualShock 4 (PlayStation 4) controllers. USBHost does not support devices that are connected through USB hubs. This includes some keyboards that have an internal hub.

**NB:** The USBHost library and associated functions are experimental. While it is not likely the API will change in future releases, it is still under development.

**NB:** The USBHost library is distributed under the GNU Lesser General Public License, version 2.1 as published by the Free Software Foundation. Any sketch that uses the library needs to be open-sourced under this license or newer.

## USBHost Class

USBHost is the base class for all calls that rely on USB host communication. When invoked, it initializes a USB controller. To declare it, use:

```
USBHost usb;
```
