#include "Airline.h"
#include "Array.h"

Airline::Airline(const string& name) {

    this->name = name;
    this->partsSize = 0;
    this->aircraftsSize = 0;
}

Airline::~Airline() {

  for (int i = 0; i < this->aircraftsSize; i++) {

    delete this->aircrafts[i];
  }

  for (int i = 0; i < this->partsSize; i++) {

    delete this->parts[i];
  }
}

bool Airline::getAircraft(const string& registration, Aircraft** aircraft) {

  for (int i = 0; i < this->aircraftsSize; i++) {

    if (this->aircrafts[i]->getRegistration() == registration) {

      *aircraft = this->aircrafts[i];
      return true;
    }
  }
  return false;
}

bool Airline::getPart(const string& name, Part** part) {

  for (int i = 0; i < this->partsSize; i++) {

    if (this->parts[i]->getName() == name) {

      *part = this->parts[i];
      return true;
    }
  }

  return false;
}


  void Airline::addAircraft(const string& type, const string& registration) {

    this->aircrafts[this->aircraftsSize] = new Aircraft(type, registration);
    this->aircraftsSize += 1;

  }

  void Airline::addPart(const string& part, int fh_inspect, int it_inspect) {

    if (fh_inspect == 0) {

      this->parts[this->partsSize] = new IT_Part(part, it_inspect);
      this->partsSize += 1;

      return;
    }

    if (it_inspect == 0) {

      this->parts[this->partsSize] = new FH_Part(part, fh_inspect);
      this->partsSize += 1;
      return;
    }

    this->parts[this->partsSize] = new FHIT_Part(part, fh_inspect, it_inspect);
    this->partsSize += 1;
  }


  void Airline::takeFlight(const string& reg, int hours) {

    Aircraft* a;
    if (getAircraft(reg, &a)) {

      a->takeFlight(hours);
    }


    else {

      cout << "The aircraft with registration " << reg << " can not be found." << endl;
    }
  }


void Airline::printAircraft() {

  for (int i = 0; i < this->aircraftsSize; i++) {

    cout << *(this->aircrafts[i]) << endl;
  }
}

void Airline::printParts() {

  for (int i = 0; i < this->partsSize; i++) {

    cout << *(this->parts[i]) << endl;
  }
}

void Airline::inspectionReport(const string& reg, Date& d) {

  Aircraft* a;

  if (getAircraft(reg, &a)) {

    cout << "The following parts from " << a->getRegistration() << " require inspection:" << endl;
    Array<Part*> p;
    a->inspectionReport(d, &p);
    cout << p << endl;
  }

  else {

    cout << "The aircraft with registration " << reg << " can not be found." << endl;
  }

}

bool Airline::install(const string& reg, const string& name, Date& d) {

  Aircraft* a;
  Part* p;

  if (getAircraft(reg, &a) && getPart(name, &p)) {

    a->install(p, d);
    return true;
  }

  if (!getAircraft(reg, &a)) {

    cout << "The aircraft with registration " << reg << " can not be found." << endl;
    return false;
  }

  if (!getPart(name, &p)) {

    cout << "The part with name " << name << " can not be found." << endl;
    return false;
  }

  return false;
}
