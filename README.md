# STM32U5xx_USB_ECM
 NUCLEO-U575ZI-Q with USB ECM, without SD Card

## USB ECM
This project is converted and modified from the STM32U575-EV board, to run it on a NUCLEO-U575ZI-Q board.
This NUCLEO board does not have a SD Card (even you could connect a SD Card adapter).
Therefore, the project is changed to read the Web Pages from the MCU internal flash memory.

## Network via USB
USB ECM is the connection of the MCU via USB (the USB-C is used).
It makes it possible to access the MCU just via a USB cable like a network device (with TCP/IP, HTTP, ...).

## see fileXS.c, fileXS.h
In order to read the files from MCUI Flash memory, a simple set of functions used by the web server are implemented.
These functions "bypass" the FileX, FAT file system and read the "file content" from a character array.

It is much faster and it does not need an SD Card (adapter and neither to store the web pages on SD Card).

## How to use?
At best you try with Android (it works well there) or a Linux, MacOS system.
For a Windows OS - there is not a related driver for USB ECM (just RNDIS, but this project is not RNDIS based).

Enable the "Ethernet Teathering", see the UART Console (baudrate 115200) for the IP address assigned to MCU board.
Open Web Browser and enter as URL: http://IPADDR/index.html

