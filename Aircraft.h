#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <iostream>
#include <string>
#include "defs.h"

#include "Array.h"
#include "Part.h"
using namespace std;

/*  Class purpose: Handles the Aircraft object.

            Class functions: Allows the user to install parts, or to request an inspection report.

            Variables:  string type, string registration, int flightHours, Part* parts[MAX_ARR], int arrSize
*/


class Aircraft {

  friend ostream& operator<<(ostream& out, Aircraft& aircraft);
  public:

    //Constructor
    Aircraft(const string& type, const string& registration);


    //Destructor
    ~Aircraft();

    //Getter
    const string& getRegistration();
    const string& getType();

    //Other
    void install(Part*, Date&);
    void takeFlight(int hours);
    void inspectionReport(Date& d, Array<Part*> *p);

  protected:
    string type;
    string registration;
    int flightHours;
    Part* parts[MAX_ARR];
    int arrSize;
};
#endif
