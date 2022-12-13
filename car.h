#ifndef _CAR_H_
#define _CAR_H_

#include <string>

#include "gps.h"
#include "person.h"
#include "vehicle.h"

#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/value.h>

class Car: public Vehicle {
    public:
        Car(std::string, double, double, double, double, Person, Person, Person, Person, GPS, int, bool);
        Car(std::string, double, double, double, double, Person, Person, Person, GPS, int, bool);
        Car(std::string, double, double, double, double, Person, Person, GPS, int, bool);
        Car(std::string, double, double, double, double, Person, GPS, int, bool);
        Car();
        ~Car() {}
        
        int numPassengers;
        bool emergency;


        virtual Json::Value dump2JSON();
        virtual bool JSON2Object(Json::Value);
    protected:
    private:
        
};

#endif //_CAR_H_