#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <string>
#include "defs.h"
#include "Part.h"
#include "Aircraft.h"
using namespace std;

/*  Class purpose: Handles the Airline object.

            Class functions: Allows the user to add aircrafts or parts to the arrays, as well as print the aircrafts and parts in the arrays.

            Variables:  string name, Part* parts[MAX_ARR], int partsSize, Aircraft* aircrafts[MAX_ARR], int aircraftsSize
*/

class Airline {

  public:

    //Constructor
    Airline(const string& name);

    //Destructor
    ~Airline();

    //Other
    void addAircraft(const string& type, const string& registration);
    void addPart(const string& part, int fh_inspect, int it_inspect);
    void takeFlight(const string& reg, int hours);
    void printAircraft();
    void printParts();
    void inspectionReport(const string& reg, Date& d);
    bool install(const string& reg, const string& name, Date& d);


  private:
      bool getAircraft(const string& registration, Aircraft** aircraft);
      bool getPart(const string& name, Part** part);

  protected:
    string name;
    Part* parts[MAX_ARR];
    int partsSize;
    Aircraft* aircrafts[MAX_ARR];
    int aircraftsSize;
};
#endif
