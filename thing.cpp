#include <string>
#include <iostream>
#include "thing.h"

Thing::Thing(std::string newDescription, GPS newLocation) {
  this->description = newDescription;
  this->location = newLocation;
}

Thing::Thing() {
  this->description = "No description";
  this->location = GPS {};
}

///////////////////////////////////////////////////////// begin set definitions

void Thing::setDescription(std::string argDescription) {
    this->description = argDescription;
}

void Thing::setLocation(GPS argLocation) {
    this->location = argLocation;
}

/////////////////////////////////////////////////////////// end set definitions

/////////////////////////////////////////////////////////// begin get definitions

std::string Thing::getDescription() {
    return this->description;
}

GPS Thing::getLocation() {
    return this->location;
}

/////////////////////////////////////////////////////////// end get definitions

/////////////////////////////////////////////////////////// dumpToJson goes here

Json::Value Thing::dump2JSON()
{
    Json::Value result;
    if(this->description != "No description") {
            result["Description"] = this->description;
        
        if((this->location).getYCoord() != 0) {
            Json::Value GPS_result;
            GPS_result = (this->location).dump2JSON();
            result["Location"] = GPS_result;
        }
    }
    else {
            result["Description"] = "No Thing Object";
    }
    return result;
}

bool Thing::JSON2Object(Json::Value argJV) {
    //std::cout << argJV.toStyledString() << "\n \n";

    if((argJV.isNull() == true) || (argJV.isObject() != true)) {
        return false;
    }

    if(((argJV["Description"]).isNull()) == true || ((argJV["Description"]).isString() != true)) {
        
        return false;
    }

    this->description = (argJV["Description"]).asString();

    Json::Value locationJV = argJV["Location"];
    this->location.JSON2Object(locationJV);
    
    return true;

}