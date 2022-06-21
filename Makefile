objects = main.o Control.o Airline.o Part.o Date.o Aircraft.o View.o

aircraftMaintenance: $(objects)
	g++ -o aircraftMaintenance $(objects)

main.o: main.cc Array.h
	g++ -c main.cc

Control.o: Control.h Control.cc Array.h
	g++ -c Control.cc

View.o: View.cc View.h Array.h
	g++ -c View.cc

Airline.o: Airline.cc Airline.h Array.h
	g++ -c Airline.cc

Aircraft.o: Aircraft.cc Aircraft.h Array.h
	g++ -c Aircraft.cc

Date.o: Date.cc Date.h Array.h
	g++ -c Date.cc

Part.o: Part.cc Part.h Array.h
	g++ -c Part.cc


clean:
	rm -f a4 *.o *.gch
