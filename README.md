Home Automation Framework
===

This is my group's senior project for the EE/CS class of 2013 at Wichita State University.

The system allows for control of various home automation devices (electronic deadbolt, automatic window blinds, AC outlet switches) through a web application, accessible via smartphone or web browser.

It consists of a LAN-connected Raspberry Pi running a web server to act as a hub, connected via GPIO interface to an nRF24L01 module to wirelessly communicate with the connected devices.

We custom-built the automation devices, initially with Arduinos, and later switching to 8-pin ATTiny chips. These also used the nRF24L01 to communicate back to the hub.

This goal of this project was essentially to do what the company [SmartThings](http://www.smartthings.com/) has done -- facilitate an ecosystem of devices available to be controlled from a central interface. SmartThings began as a kickstarter the same month we started work on this project (August 2012).
