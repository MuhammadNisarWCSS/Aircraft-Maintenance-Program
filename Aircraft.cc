#include "Aircraft.h"

Aircraft::Aircraft(const string& type, const string& registration) {

  this->type = type;
  this->registration = registration;
  this->arrSize = 0;
  this->flightHours = 0;
}

Aircraft::~Aircraft() {}

const string& Aircraft::getRegistration() {

  return this->registration;
}

const string& Aircraft::getType() {

  return this->type;
}

void Aircraft::install(Part* p, Date& d) {

  this->parts[this->arrSize] = p;
  this->arrSize += 1;
  p->install(d);
}

void Aircraft::takeFlight(int hours) {

  this->flightHours += hours;

  for (int i = 0; i < this->arrSize; i++) {

    this->parts[i]->addFlightHours(hours);
  }
}

void Aircraft::inspectionReport(Date& d, Array<Part*> *p) {

  for (int i = 0; i < this->arrSize; i++) {

    if (this->parts[i]->inspection(d)) {

      p->add(this->parts[i]);
    }
  }
}

ostream& operator<<(ostream& out, Aircraft& t) {

  return out << "Aircraft : " << t.getType() << endl << "Registration : " << t.getRegistration() << endl;
}
