#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>
#include "gps.h"

#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/value.h>

class Person {
    public:
        Person(int newAge, std::string newHeight, std::string newGender, std::string newName, GPS newLocation, bool newIsFelix);
        Person();
        ~Person() {}
        
        void setAge(int argAge);
        void setHeight(std::string argHeight);
        void setGender(std::string argGender);
        void setName(std::string argName);
        void setLocation(GPS argLocation);

        int getAge();
        std::string getHeight();
        std::string getGender();
        std::string getName();
        GPS getLocation();
        virtual Json::Value dump2JSON();
        virtual bool JSON2Object(Json::Value);

        bool isFelix; // So that we never hit Felix if he's on a motorcycle... unless he doesn't give us an A
    protected:
    private:
        int age;
        std::string height; //not numerical measurements. Instead it's descriptions like "tall", "average", or "short".
        std::string gender;
        std::string name;
        GPS location;
};

#endif //_PERSON_H_