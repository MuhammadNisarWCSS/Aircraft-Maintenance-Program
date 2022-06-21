#ifndef PART_H
#define PART_H

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class Part {

  friend ostream& operator<<(ostream& ost, Part& t);

	public:
		//Constructor
		Part(const string& name);

		//Destructor
		virtual ~Part();

    //Getters
    const string& getName();

		//Other
    void addFlightHours(int);
    void install(Date&);
    virtual bool inspection(Date& d) = 0;
    virtual void print(ostream& os);


	protected:
		string name;
    Date installationDate;
		int flightHours;
};


class FH_Part: virtual public Part {

public:
  //Constructor
  FH_Part(const string& name, int hours);

  //Other
  virtual bool inspection(Date& d);
  virtual void print(ostream& os);

protected:
  int fh_inspect;
};


class IT_Part: virtual public Part {

public:
  //Constructor
  IT_Part(const string& name, int days);

  //Other
  virtual bool inspection(Date& d);
  virtual void print(ostream& os);

protected:
  int it_inspect;
};

class FHIT_Part: public FH_Part, public IT_Part {

public:
  //Constructor
  FHIT_Part(const string& name, int fh, int it);

  //Other
  virtual bool inspection(Date& d);
  virtual void print(ostream& os);
};
#endif
