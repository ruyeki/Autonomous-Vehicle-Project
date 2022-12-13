#ifndef _THING_H_
#define _THING_H_

#include <string>
#include "gps.h"

#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/value.h>

class Thing {
    public:
        Thing(std::string newDescription, GPS newLocation);
        Thing();
        ~Thing() {}
        
        void setDescription(std::string argDescription);
        void setLocation(GPS argLocation);

        std::string getDescription();
        GPS getLocation();
        virtual Json::Value dump2JSON();
        virtual bool JSON2Object(Json::Value);
    protected:
    private:
        std::string description;
        GPS location;
        
};

#endif //_THING_H_