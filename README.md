# Introduction:

In the realm of digital-to-analog converters (DACs), one prevalent method involves the utilization of a resistive ladder network, commonly known as an R2R ladder. The schematic provided outlines such a configuration, presenting an 8-bit DAC with bits D7 through D0 that collectively produce an analog signal spanning the range of 0 to 3.3 volts. In the context of this project, the aim is to construct a waveform generator by interfacing this DAC with an ESP microcontroller.

The proposed waveform generator serves as a valuable tool in laboratory settings, enabling the generation of waveforms in various shapes—square, triangle, sawtooth, or sine—with user-selectable frequencies. The user interface incorporates a button for waveform selection and an adjustment mechanism for frequency control. The resulting waveform can be observed using an oscilloscope.

In this endeavor, the ESP microcontroller undertakes the responsibility of transmitting values to the output pins (connected to D7 through D0 of the DAC), thereby generating corresponding analog values to shape the desired waveform. Internally stored arrays represent the waveform data for different shapes, including square, sawtooth, triangular, and sinusoidal.

The ESP software functionality extends to monitoring the serial terminal, awaiting user input to determine the waveform type. Upon selection, the microcontroller cyclically fetches data from the respective waveform vector and transmits it to the output pins. The following menu options guide the user in choosing the desired waveform:

The software seamlessly adapts to user preferences, transforming digital data into analog signals through the DAC, offering a versatile and interactive waveform generation experience.

# R2R ladder:
![image](https://github.com/rodrigoguedes09/Wave-Generator/assets/61996985/b0f1a964-0596-4c9c-a07d-ee2346f99574)

# Circuit
![WhatsApp Image 2023-12-23 at 21 19 50](https://github.com/rodrigoguedes09/Wave-Generator/assets/61996985/5ee7b67e-612b-4e57-a897-5f6577197cdf)


# Observation!!!
The file uploaded is an .INO file, just because I used the Arduino interface to access the serial and communicate with the ESP. The code is written in C++, and it could be implemented without using the Arduino interface; I only used it to facilitate communication with the ESP8266.


