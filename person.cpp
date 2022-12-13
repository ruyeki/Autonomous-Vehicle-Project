#include <string>
#include <iostream>
#include "person.h"

Person::Person(int newAge, std::string newHeight, std::string newGender, std::string newName, GPS newLocation, bool argIsFelix) {
  this->age = newAge;
  this->height = newHeight;
  this->gender = newGender;
  this->name = newName;
  this->location = newLocation;
  this->isFelix = argIsFelix;
}

Person::Person() {
  this->age = 0;
  this->height = "unknown";
  this->gender = "unknown";
  this->name = "unknown";
  this->location = GPS {};
  this->isFelix = false;
}

///////////////////////////////////////////////////////// begin set definitions

void Person::setAge(int argAge) {
    this->age = argAge;
}

void Person::setHeight(std::string argHeight) {
    this->height = argHeight;
}

void Person::setGender(std::string argGender) {
    this->gender = argGender;
}

void Person::setName(std::string argName) {
    this->name = argName;
}

void Person::setLocation (GPS argLocation) {
    std::cout << "Person class's setLocation command called: " << this->name << " traveled to " << argLocation.getName() << ".\n";
    this->location = argLocation;
}

/////////////////////////////////////////////////////////// end set definitions

/////////////////////////////////////////////////////////// begin get definitions

int Person::getAge() {
    return this->age;
}

std::string Person::getHeight() {
    return this->height;
}

std::string Person::getGender() {
    return this->gender;
}

std::string Person::getName() {
    return this->name;
}

GPS Person::getLocation() {
    return this->location;
}

/////////////////////////////////////////////////////////// end get definitions

/////////////////////////////////////////////////////////// dumpToJson goes here

Json::Value Person::dump2JSON()
{
    Json::Value result;
    if(this->age != 0) {
        result["Age"] = this->age;
        result["Height"] = this->height;
        result["Gender"] = this->gender;
        result["Name"] = this->name;
        result["Is Felix"] = this->isFelix;

    Json::Value GPS_result;
        GPS_result = (this->location).dump2JSON();
        result["Location"] = GPS_result;

    }
    else {
            result["Name"] = "No Person Object";
    }
    return result;
}

bool Person::JSON2Object(Json::Value argJV) {

    if((argJV.isNull() == true) || (argJV.isObject() != true)) {
        return false;
    }

    if(((argJV["Age"]).isNull()) == true || ((argJV["Age"]).isInt() != true) ||
        ((argJV["Height"]).isNull() == true) || ((argJV["Height"]).isString() != true) ||
        ((argJV["Gender"]).isNull() == true) || ((argJV["Gender"]).isString() != true) ||
        ((argJV["Name"]).isNull() == true) || ((argJV["Name"]).isString() != true)) {
        
        return false;
    }

    this->age = (argJV["Age"]).asInt();
    this->height = (argJV["Height"]).asString();
    this->gender = (argJV["Gender"]).asString();
    this->name = (argJV["Name"]).asString();
    this->isFelix = (argJV["Is Felix"]).asBool();

    Json::Value GPS_JV;
        GPS_JV = argJV["Location"];
        this->location.JSON2Object(GPS_JV);
    
    return true;

}
        