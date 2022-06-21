#include "Part.h"

Part::Part(const string& name) {

  this->name = name;
  this->flightHours = 0;
}

Part::~Part() {}

const string& Part::getName() {

  return this->name;
}


void Part::addFlightHours(int hours) {

  this->flightHours += hours;
}


void Part::install(Date& d) {

  this->installationDate = d;
}


void Part::print(ostream& os) {

        os <<"Part: " << this->getName() << endl << "Flight hours: " << this->flightHours << endl << "Installation Date: " << this->installationDate << endl;
}


ostream& operator<<(ostream& ost, Part& t){
    t.print(ost);
    return ost;
}


FH_Part::FH_Part(const string& name, int hours):Part(name){

  this->fh_inspect = hours;
}


bool FH_Part::inspection(Date& d) {

  return this->flightHours >= this->fh_inspect;
}


void FH_Part::print(ostream& os) {

        os <<"Part: " << this->getName() << endl << "Flight hours: " << this->flightHours << endl << "Installation Date: " << this->installationDate << "Inspect every: " << this->fh_inspect <<  " flight hours" << endl;
}



IT_Part::IT_Part(const string& name, int days):Part(name) {

  this->name = name;
  this->it_inspect = days;
}


bool IT_Part::inspection(Date& d) {

  int daysSinceInstallation = this->installationDate.toDays();
  int daysSinceInspection = d.toDays();
  return daysSinceInspection - daysSinceInstallation >= this->it_inspect;
}


void IT_Part::print(ostream& os) {

        os <<"Part: " << this->getName() << endl << "Flight hours: " << this->flightHours << endl << "Installation Date: " << this->installationDate <<  "Inspect every: " << this->it_inspect <<  " days installed" << endl;
}


FHIT_Part::FHIT_Part(const string& name, int fh, int it):Part(name), FH_Part(name, fh), IT_Part(name, it) {

  this->name = name;
  this->fh_inspect = fh;
  this->it_inspect = it;
}


bool FHIT_Part::inspection(Date& d) {

  return (FH_Part::inspection(d)||IT_Part::inspection(d));
}


void FHIT_Part::print(ostream& os) {

        os <<"Part: " << this->getName() << endl << "Flight hours: " << this->flightHours << endl << "Installation Date: " << this->installationDate << "Inspect every: " << this->fh_inspect << " flight hours" << endl << "Inspect every: " << this->it_inspect <<  " days installed" << endl;
}
