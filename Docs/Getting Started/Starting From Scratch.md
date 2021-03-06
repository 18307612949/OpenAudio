Starting From Scratch
====================

Are you looking to work with the open source hearing aid?  Have you never worked with Arduino before?  This document hopes to help you get started.

Arduino Basics
---------

If you really have no experience with Arduino, you should get a basic Arduino try a couple of the introductory tutorials.  If you can complete the first couple examples, you will know that the Arduino software environment is working correctly.

* **Hardware**: You could start with a bare [Arduino Uno](https://www.arduino.cc/en/Main/ArduinoBoardUno), but I recommend a starter pack like this one: https://www.adafruit.com/products/193

* **Software**: Download the latest Arduino software, also known as the Arduino IDE ("Integrated Development Environment").  Be sure to get it from Arduino.cc, not Arduino.org.  You can get the Arduino IDE from this link: https://www.arduino.cc/en/Main/Software

* **Installation**: After downloading, you can follow the installation instructions for your platform: https://www.arduino.cc/en/Guide/HomePage

* **Quick Start**:  Here's the Arduino Quick Start for the Arduino Uno.  It gets you to compile and upload the "Blink" program, which is always where you should start.  This is totally the key first step: https://www.arduino.cc/en/Guide/ArduinoUno

More Arduino Tutorials
------------

Once you got the Blink program to work, you can try a few more of the built-in examples.  The full list of examples are described on the Arduino site [here](https://www.arduino.cc/en/Tutorial/BuiltInExamples).  Unfortunately, this Arduino page isn't sorted into any sort of order.  I think that you should do the example programs in this order:

* **Blink**:  Turn an LED on and off.  https://www.arduino.cc/en/Tutorial/Blink
* **Digital Read Serial**: Read a switch, print the state out to the Arduino Serial Monitor  https://www.arduino.cc/en/Tutorial/DigitalReadSerial
* **Analog Read Serial**: Read a potentiometer, print its state out to the Arduino Serial Monitor. https://www.arduino.cc/en/Tutorial/AnalogReadSerial

Once you have completed these three tutorials using the basic Arduino Uno, you'll know that the Arduino IDE is working correctly and that you know how to use the IDE to compile and upload code.  You'll also know how to use the Serial Monitor to see text produced by the Arduino, which is the primary method for debugging programs.

Switching to the Teensy
-----------------

"Teensy" is a family of microcontroller boards, just as the Arduino is a family of microcontroller boards.  The Teensy 3 line of boards is much faster (and smaller) than the Arduino boards, which makes them useful for computationally-heavy tasks like processing audio.  A key feature of the Teensy boards is that they can be programmed using the Arduino IDE software, even though they are not "Arduino" boards.  That's great!

* **Hardware**: To get started, you should buy a [Teensy](https://www.pjrc.com/teensy/).  I recommend the [Teensy 3.6]( https://www.pjrc.com/store/teensy36.html) as it is the fastest, though it will be damaged if you mistakenly apply 5V signals to its pins.  If you desire 5V tolerance, you should get the [Teensy 3.5] (https://www.pjrc.com/store/teensy35.html).

* **Software**: To program the Teensy from the Arduino IDE, you need to download and install the Teensyduino add-on. The download and installation instructions are here: https://www.pjrc.com/teensy/td_download.html.  Note that the installation routine will offer to install many (dozens) additional libraries for you.  It's fine to install them all.  Or, you can choose to install just these libraries: Audio, Bounce2, FreqCount, FreqMeasure, i2c_t3, SerialFlash, Snooze, and SPIFlash (did I miss any?).

* **Quick Start**:  If you simply plug your Teensy into your computer, it's light should blink.  That's a good start.  But let's try reprogramming it to blink at a different rate.  So, after getting your Arduino IDE running, and after getting the Teensyduino software installed, let's reprogram the Teensy.  (Note, if you're BTNRH, you received a Teensy where the LED had been removed...so this won't work!  Skip to the next section...)

1. Plug your Teensy into your computer and start the Arduino IDE
2. Under the "Tools" menu, under the "Board" sub-menu, select your particular Teensy model (Teensy 3.6?)
3. Under the "File" menu, under the "Examples" sub-menu, under the "Teensy" sub-sub-menu, choose "Tutorial1", then "Blink".
4. Change the delay times from 1000 to 500.  This should make the Teensy blink twice as fast.
5. Press the Arduino IDE's "Upload" button.  It will compile the code and send it to the Teensy.  The light should blink!  Now change the `delay()` times to change the blink rate and upload again.  Success!

* **Troubleshooting**:  We've run across one user who, on Windows, could not get his Teensy to show up in Windows as a COM port. Eventually, he found an updated driver (http://www.pjrc.com/teensy/td_download.html) and that solved his problems.

Teensy Tutorials
-----------------

After you get the Teensy's light to blink (or if you got a board with no LED), you're ready to try some additional Teensy tutorials, so that you see a few more of the small differences between the Teensy and an Arduino.  Under the "Examples" / "Teensy" menu, I suggest the follwoing example:

* **HelloSerialMonitor**: Upload the code to the Teensy, start the Arduino Serial Monitor, and see the "Hello World" text.  Note that you'll have to change the Serial baud rate in the Serial Monitor to match the code.  The code is configured to 38400.  Did you see "Hello World"?  If you're successful, try changing the text.  Then try adding new messages.  Pretty easy.

Next Steps
-------------

Once you get the example programs for the Teensy working correctly, you're now ready to start with the Teensy Audio Library and the Open Audio examples.  Go to [this page](https://github.com/chipaudette/OpenAudio/blob/master/Docs/Getting%20Started/Starting%20with%20Audio.md).
