# RGB-ControllerV2
RGB Led Controller Version 2



## Using the ESP8266-01 with PlatformIO

To use the ESP8266-01 in VSCode with PlatformIO two lines have to be added at the end of the _platormio.ini_ file:

* For the code to be uploaded correctly to the ESP:

```
board_build.flash_mode = dout
```

* To use the PlatformIO integrated terminal with a higher baud rate:

```
monitor_speed = 115200
```

---

## Flashing programs onto the ESP8266-01 

### Hardware:

For flashing programs onto the ESP, I made a little circuit board according to the following diagram:

![ESP8266-01 flash wiring](https://cdn.solarbotics.com/wp-content//uploads/ftdy-to-esp01-diagram-2-1023x768.jpg)

### Flashing:

To upload the code the buttons have to be pressed in the following order:

1. Hold down Reset & Flash button
2. Release Reset Button
3. When writing has started release Flash button
4. Wait for writing to finish
