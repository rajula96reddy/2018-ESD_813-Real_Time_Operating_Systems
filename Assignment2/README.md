# Assignment 2
Demonstrate push & async data input on Raspberry Pi. Async basically runs an infite loop & after a given delay checks the values of all the four configured pins. If any one of the value changes, it reads & prints   values of all the four variables. WHile push has a configure interrupt pin, which triggers an interrupt service routine when there's a change in the value.

To compile ```gcc <file> -lpwiringPi```

The data is given to the Raspberry Pi by simualating a sensor on arduino. So basically arduino & Raspberry Pi are connected and one sends the data to the other by either of the two modes.    
