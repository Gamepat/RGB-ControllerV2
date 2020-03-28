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

### Programming the ESP8266-01 

![ESP8266-01 flash wiring](flash.jpg)


1. Hold down Reset & Flash button
2. Release Reset Button
3. When writing has started release Flash button
