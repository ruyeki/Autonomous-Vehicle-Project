#ifndef _MOTORCYCLE_H_
#define _MOTORCYCLE_H_

#include <string>

#include "gps.h"
#include "person.h"
#include "vehicle.h"

#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/value.h>

class Motorcycle: public Vehicle {
    public:
        Motorcycle(std::string, double, double, double, double, Person, Person, Person, Person, GPS, bool);
        Motorcycle(std::string, double, double, double, double, Person, Person, Person, GPS, bool);
        Motorcycle(std::string, double, double, double, double, Person, Person, GPS, bool);
        Motorcycle(std::string, double, double, double, double, Person, GPS, bool);
        Motorcycle();
        ~Motorcycle() {}
        
        bool hasHelmet;


        virtual Json::Value dump2JSON();
        virtual bool JSON2Object(Json::Value);
    protected:
    private:
        
};

#endif //_MOTORCYCLE_H_