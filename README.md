# ArduinoSoilSensor

Working with an Arduino Nano to detect moisture levels in soil.

The sensors are similar to [these](https://learn.sparkfun.com/tutorials/soil-moisture-sensor-hookup-guide).

Concept is to reflect soil moisture level on two plants using two WS212B's, will probably use FastLED lib.

- [x] Normalize sensor values
- [x] Map raw sensor values to 0/100 
- [ ] Add LEDs
- [ ] Build some logic around how to display soil moisture level using an LED
- [ ] Add a button to trigger a reset (new read)
- [ ] Add deep sleep / delay logic

Not sure if I want this to be wireless, kind of nice not logging it and keeping it purely phsyical.  Could easily be adapted to an ESP8266 or Particle Photon.
