# spaceConsoleEmulator
VSCode emulator of Future Turtles ceiling lights 2023

# What is this?

An emulator that runs completely inside VS Code for the ceiling light system of the Future Turtles theme camp, 2023.

# The hardware that is being emulated

The camp ceiling lights are made up of 60 meters of flex-neon LED strips with 60 addressible pixels per meter
(so, 3600 addressible pixels). Each pixel has three LEDS (R,G,B). The pixels are WS2815b.

There is a custom hardware controller based on an Arduino-type MCU (technically it is a Teensy 4.1). We use FastLED
as the library for programming the LEDs. 

Because the hardware for the ceiling lights is all in storage, if you want to work on cool patterns, you need this
emulator!

# How are the lights arranged?

(illustration will go here)

In order to make it easy for the pattern programmer to design light shows without worrying about the hardware
layout of the LEDs, there are a bunch of functions in roof.h/.cpp which provide a simplified abstraction of the
pixel layout.

# How can I write my own patterns?

To create your own patterns, you will create your own personalized .h/.cpp files. You can use jetpack.h/.cpp as 
a template which has Jetpack's patterns in it. On playa, we will incorporate those files into the real code
running on the controller.

# Installation

1. Get VS Code
2. Install the latest platform.io
3. Install [wokwi for VS Code](https://docs.wokwi.com/vscode/getting-started)
4. Clone this repo and open it
5. In the VSCode terminal window, type "pio run" to compile
6. Press F1 and run Wokwi: Start Simulator to start the simulator
7. Send pull requests when your code is ready.

Try not to edit anything other than your own .cpp/.h files unless you're submitting a pull request for a bug fix.
If you are confident you know what you are doing, you can submit pull requests to roof.h/roof.cpp but probably talk to me first.

If these instructions didn't work, figure out why (or ask me for help) and update this README.md file!
