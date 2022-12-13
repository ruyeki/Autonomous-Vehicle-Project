#include <string>
#include <iostream>
#include "vehicle.h"
#include "person.h"
#include "gps.h"

Vehicle::Vehicle(std::string argDescription, double argWeight, double argHeight, double argStructuralIntegrity, 
                 double argAirBagQuality, Person argPerson1, Person argPerson2, Person argPerson3, Person argPerson4, 
                 GPS argLocation) {
    this->description = argDescription;
    this->weight = argWeight;
    this->height = argHeight;
    this->structuralIntegrity = argStructuralIntegrity;
    this->airBagQuality = argAirBagQuality;
    this->persarray[0] = argPerson1;
    this->persarray[1] = argPerson2;
    this->persarray[2] = argPerson3;
    this->persarray[3] = argPerson4;
    this->location = argLocation;
}

Vehicle::Vehicle(std::string argDescription, double argWeight, double argHeight, double argStructuralIntegrity, 
                 double argAirBagQuality, Person argPerson1, Person argPerson2, Person argPerson3, 
                 GPS argLocation) {
    this->description = argDescription;
    this->weight = argWeight;
    this->height = argHeight;
    this->structuralIntegrity = argStructuralIntegrity;
    this->airBagQuality = argAirBagQuality;
    this->persarray[0] = argPerson1;
    this->persarray[1] = argPerson2;
    this->persarray[2] = argPerson3;
    this->persarray[3] = Person {};
    this->location = argLocation;
}

Vehicle::Vehicle(std::string argDescription, double argWeight, double argHeight, double argStructuralIntegrity, 
                 double argAirBagQuality, Person argPerson1, Person argPerson2, 
                 GPS argLocation) {
    this->description = argDescription;
    this->weight = argWeight;
    this->height = argHeight;
    this->structuralIntegrity = argStructuralIntegrity;
    this->airBagQuality = argAirBagQuality;
    this->persarray[0] = argPerson1;
    this->persarray[1] = argPerson2;
    this->persarray[2] = Person {};
    this->persarray[3] = Person {};
    this->location = argLocation;
}

Vehicle::Vehicle(std::string argDescription, double argWeight, double argHeight, double argStructuralIntegrity, 
                 double argAirBagQuality, Person argPerson1, 
                 GPS argLocation) {
    this->description = argDescription;
    this->weight = argWeight;
    this->height = argHeight;
    this->structuralIntegrity = argStructuralIntegrity;
    this->airBagQuality = argAirBagQuality;
    this->persarray[0] = argPerson1;
    this->persarray[1] = Person {};
    this->persarray[2] = Person {};
    this->persarray[3] = Person {};
    this->location = argLocation;
}

Vehicle::Vehicle() {
    this->description = "No description";
    this->weight = -1;
    this->height = -1;
    this->structuralIntegrity = -1;
    this->airBagQuality = -1;
    this->persarray[0] = Person {};
    this->persarray[1] = Person {};
    this->persarray[2] = Person {};
    this->persarray[3] = Person {};
    this->location = GPS {};
}

/////////////////////////////////////////////////////////// dumpToJson goes here

Json::Value Vehicle::dump2JSON()
{
    Json::Value result;
    if(this->description != "No description") {
            result["Description"] = this->description;
            result["Weight"] = this->weight;
            result["Height"] = this->height;
            result["Structural Integrity"] = this->structuralIntegrity;
            result["Air Bag Quality"] = this->airBagQuality;
        
            Json::Value person_result;
        if((this->persarray[0]).getAge() != 0) {
            person_result = (this->persarray[0]).dump2JSON();
            result["Passenger 1"] = person_result;
        }

        if((this->persarray[1]).getAge() != 0) {
            person_result = (this->persarray[1]).dump2JSON();
            result["Passenger 2"] = person_result;
        }

        if((this->persarray[2]).getAge() != 0) {
            person_result = (this->persarray[2]).dump2JSON();
            result["Passenger 3"] = person_result;
        }

        if((this->persarray[3]).getAge() != 0) {
            person_result = (this->persarray[3]).dump2JSON();
            result["Passenger 4"] = person_result;
        }

            Json::Value GPS_result;
            GPS_result = (this->location).dump2JSON();
            result["Location"] = GPS_result;

        
    }
    else {
            result["Description"] = "No Vehicle Object";
    }
    return result;
}

bool Vehicle::JSON2Object(Json::Value argJV) {
    //std::cout << argJV.toStyledString() << "\n \n";

    if((argJV.isNull() == true) || (argJV.isObject() != true)) {
        return false;
    }

    if(((argJV["Description"]).isNull()) == true || ((argJV["Description"]).isString() != true)) {
        
        return false;
    }

    this->description = (argJV["Description"]).asString();
    this->weight = (argJV["Weight"]).asDouble();
    this->height = (argJV["Height"]).asDouble();
    this->structuralIntegrity = (argJV["Structural Integrity"]).asDouble();
    this->airBagQuality = (argJV["Air Bag Quality"]).asDouble();
    
    Json::Value person1JV = argJV["Passenger 1"];
    this->persarray[0].JSON2Object(person1JV);

    Json::Value person2JV = argJV["Passenger 2"];
    this->persarray[1].JSON2Object(person2JV);

    Json::Value person3JV = argJV["Passenger 3"];
    this->persarray[2].JSON2Object(person3JV);

    Json::Value person4JV = argJV["Passenger 4"];
    this->persarray[3].JSON2Object(person4JV);

    Json::Value locationJV = argJV["Location"];
    this->location.JSON2Object(locationJV);
    
    return true;

}