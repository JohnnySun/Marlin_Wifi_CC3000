/*
	Copyright 2007-2014 BMY-Soft.
	Copyright 2007-2014 PC GO Ld.

	This program is free software; you can redistribute it and/or modify it under the terms of the GNU LESSER GENERAL PUBLIC LICENSE as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU LESSER GENERAL PUBLIC LICENSE for more details.
*/

/*
Copyright 2011 Lex.V.Talionis at gmail
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*/
#include <PinChangeInt.h>

#define PIN 11  // the pin we are interested in
volatile byte burp=0;    // a counter to see how many times the pin has changed
volatile int status = LOW;
byte cmd=0;     // a place to put our serial data

void setup() {
  Serial.begin(9600);
  Serial.print("PinChangeInt test on pin ");
  Serial.print(PIN);
  Serial.println();
  pinMode(PIN, OUTPUT);     //set the pin to input
  digitalWrite(PIN, LOW); //use the internal pullup resistor
  PCintPort::attachInterrupt(PIN, burpcount,RISING); // attach a PinChange Interrupt to our pin on the rising edge
// (RISING, FALLING and CHANGE all work with this library)
// and execute the function burpcount when that pin changes
  }

void loop() {
  digitalWrite(PIN, LOW); //use the internal pullup resistor
  cmd=Serial.read();  
  if (cmd=='p')
  {
    Serial.print("burpcount:\t");
    Serial.println(burp, DEC);
  }
  cmd=0;
}

void burpcount()
{
  status = !status;
  burp++;
}
