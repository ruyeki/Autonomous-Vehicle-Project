#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include <string>

#include "gps.h"
#include "person.h"

#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/value.h>

class Vehicle {
    public:
        Vehicle(std::string, double, double, double, double, Person, Person, Person, Person, GPS);
        Vehicle(std::string, double, double, double, double, Person, Person, Person, GPS);
        Vehicle(std::string, double, double, double, double, Person, Person, GPS);
        Vehicle(std::string, double, double, double, double, Person, GPS);
        Vehicle();
        ~Vehicle() {}
        
        std::string description;
        double weight;
        double height;
        double structuralIntegrity; // Think of this as the car's hp (hit points). NOTE: I'm defining this number to be from 1-1000.
        // If the car is fragile as heck, structuralIntegrity = 1. If the car is pretty much a WWII tank, structuralIntegrity = 1000.

        double airBagQuality; // From 1-100 (a percentage). Depends on the amount of impact the airbag of the car can absorb in a
                              // typical incident. The remaining impact will be absorbed by the passenger (injury).
        
        // Person Passenger1; // 1-4 Passengers (I could have put these in an array, but arrays lead to Segmentation Errors so...)
        // Person Passenger2; // If there are less than 4 passengers the remaining Person objects will be empty (I'll define an empty person).
        // Person Passenger3;
        // Person Passenger4;
        Person persarray[4];

        GPS location;


        virtual Json::Value dump2JSON();
        virtual bool JSON2Object(Json::Value);
    protected:
    private:
        
};

#endif //_VEHICLE_H_