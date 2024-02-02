pinMode(pin, mode);

digitalRead(pin);
digitalWrite(pin, state);

millis(); //time from the beggining
delay(time); //delay "time" seconds

Serial.begin(9600);
Serial.print();


val = map(val, min, max, newMin, newMax); //returns new min max for val
val = constrain(val, min, max); //returns min max for val

analogRead(pin); //returns value from 0 to 1023, pin - analog pin
analogWrite(pin, val); // 

int val = random(max, min);
randomSeed(seedVal); //randomize

attachInterrupt(pin, function, mode); //Modes: LOW, RISING(low -> high), FALLING(hing -> low), CHANGE. Pins: 1 - 1st interruptable pin
//must be in setup function, works whole time
deattachInterrupt(pin);
noInterrupts(); //full off interrupts
interrupts();
volotile varTypr var; //make var interruptable

