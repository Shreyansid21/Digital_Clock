# Digital_Clock

Overview:
This code demonstrates how to interface with a DS1307 Real-Time Clock (RTC) module using the I2C protocol. The program:
1. Initializes I2C communication.
2. Sets a predefined time (11:59:50 PM) on the RTC.
3. Continuously reads and displays the current time (hours, minutes, seconds) via UART serial communication.

Hardware Components:
Microcontroller with I2C and UART support
DS1307 RTC module (I2C address: 0xD0 for write, 0xD1 for read)
Serial terminal (UART at 9600 baud) to monitor time updates

Functionality:
1. Initialization
i2c_init() → Initializes I2C communication.
uart1_init(9600) → Sets up UART1 at 9600 baud for serial output.
uart1_tx_string("DS1307 RTC\r\n") → Prints a startup message.

2. Setting Initial Time
The code sets the RTC time to 11:59:50 PM:
Hours: 0x23 (11 PM in 24-hour format)
Minutes: 0x59
Seconds: 0x50

3. Continuous Time Reading & Display
In an infinite loop (while(1)), the program:

a. Reads hours, minutes, seconds from the RTC registers:
h = i2c_byte_read_frame(0xD0, 0x2) → Hours
m = i2c_byte_read_frame(0xD0, 0x1) → Minutes
s = i2c_byte_read_frame(0xD0, 0x0) → Seconds

b. Converts binary-coded decimal (BCD) values to ASCII characters.
c. Displays the time in HH:MM:SS format via UART.

Usage:
Connect the DS1307 RTC to the microcontroller via I2C.
Open a serial terminal (e.g., PuTTY, Tera Term) at 9600 baud.
Observe the real-time clock updating every second.

