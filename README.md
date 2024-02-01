# STM32U5xx_USB_ECM
 NUCLEO-U575ZI-Q wnd NUCLEO-U5A5ZJ-Q with USB ECM, without SD Card

## USB ECM
This project is converted and modified from the STM32U575-EV board, to run it on a NUCLEO-U575ZI-Q board, meanwhile also on a NUCLEO-U5A5ZJ-Q board.
These NUCLEO boards do not have a SD Card (even you could connect a SD Card adapter).
Therefore, the project is changed to read the Web Pages from the MCU internal flash memory.

## Network via USB
USB ECM is the connection of the MCU via USB (the USB-C is used).
It makes it possible to access the MCU just via a USB cable like a network device (with TCP/IP, HTTP, ...).

## see fileXS.c, fileXS.h
In order to read the files from MCU Flash memory, a simple set of functions used by the web server are implemented.
These functions "bypass" the FileX, FAT file system and read the "file content" from a character array (directly from MCU Flash memory).

It is much faster and it does not need a SD Card (no adapter and neither to store the web pages on SD Card).

## How to use?
At best you try with Android (it works well there) or a Linux, MacOS system.
For a Windows OS - there is not a related driver for USB ECM (just RNDIS, but this project is not RNDIS based).

Enable the "Ethernet Tethering", see the UART Console (baudrate 115200) for the IP address assigned to MCU board.
Open Web Browser and enter as URL: http://IPADDR/index.html

## About the project
It is a STM32 IDE project only. All not needed files are removed (e.g. for IAR, AC6).

It is a port from the STM32U575-EV board demo project and it works now on NUCLEO-U575 as well as NUCLEO-U5A5:
Just set the macros STM32U575xx vs. STRM32U5A5xx accordingly. ATTENTION: for C-compiler as well as Assembler!

## USB on 575 vs. U5A5
It demonstates also the differences for the USB configuration, on a STM32U575 (with an USB OTG FS PHY only) and a STM32U5A5 (with an integrated USB OTG HS PHY!).

For USB EMC I had to set the speed, even U5A5 is HS PHY, to FS speed (but still using HS PHY on U5A5).

