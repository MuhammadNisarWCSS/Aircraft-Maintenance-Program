
Author : Muhammad Nisar 

C++ Code that inspects and replaces faulty aircraft parts.

An Airline runs a number of Aircraft. Spare Parts for the aircraft are stored in case a part must be changed.
The rules and regulations of the airline industry ensure that parts are inspected and changed at regular intervals.
As such, each Part is carefully tracked. Some parts must be inspected after a certain number of flight hours. Some
parts must be inspected after a certain amount of time being installed in an aircraft. And some parts require both
flight hours and time installed to be tracked. This behaviour is the perfect opportunity to use multiple inheritance!
Parts can be installed on an Aircraft on a given Date. Once installed, every time the aircraft flies the number
of flight hours are recorded on the Part. The airline may choose to do an inspectionReport on a particular aircraft
on a given Date, at which time all the parts that are due for inspection are reported.



Files :
        Aircraft.h Aircraft.cc (Handles the Aircraft class)
        Airline.h Airline.cc (Handles the Airline class)
        Array.h (Handles the Array class)
        Control.h Control.cc (Handles the Control class)
        Date.h Date.cc (Handles the Date class)
        defs.h (Contains standard definitions)
        main.cc (Main function is in here)
        Makefile (Used to compile and create the executable)
        Part.h Part.cc (Handles the Part base and derived classes)
        View.h View.cc (Handles the View class)



To compile : Open up the terminal. Type "make".
To launch executable : Type "./aircraftMaintenance" in terminal.
To launch executable with valgrind : Type "valgrind ./aircraftMaintenance" in terminal.
