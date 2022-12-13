#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/value.h>
#include <string>

#include <iostream>
#include "leftmotorcycle.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
#include "middlecar.h"
#include <jsonrpccpp/client/connectors/httpclient.h>
#include <stdio.h>

#include <time.h>
#include "JvTime.h"

// File includes
#include "vehicle.h"
#include "car.h"
#include "motorcycle.h"
#include "gps.h"
#include "person.h"
#include "thing.h"
#include "decision.h"

using namespace jsonrpc;
using namespace std;

Car carInEmergency {};
Motorcycle LMotor {};
Motorcycle RMotor {};
Decision decision {};
Motorcycle incomingMotor {}; // Will need to copy this into LMotor or RMotor before bringing in the second incomingMotor


class MotorCycleServer : public leftMotorcycle
{
public:
  MotorCycleServer(AbstractServerConnector &connector, serverVersion_t type);
  virtual Json::Value move(const std::string& action,
                           const std::string& class_id,
                           const Json::Value& json_object,
                           const std::string& object_id);
};

MotorCycleServer::MotorCycleServer(AbstractServerConnector &connector, serverVersion_t type): leftMotorcycle(connector, type)
{
  std::cout << "CarReturnServer created" << "\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

Json::Value MotorCycleServer::move (const std::string& action, 
                               const std::string& class_id,
                               const Json::Value& json_object,
                               const std::string& object_id)
{
  Json::Value result;
  std::string strJson;

  std::cout << "Moving Object...\n";
  if (class_id != "Car" && class_id != "Decision")
    {
      result["status"] = "failed";
    }

  if (object_id.empty())
    {
      result["status"] = "failed";
    }

  if ((json_object.isNull() == true) || (json_object.isObject() == false)) {
      result["status"] = "failed";
  }
    

  if(class_id == "Car") {
    Car * lv_car_ptr;
    lv_car_ptr = new Car {};
    lv_car_ptr->JSON2Object(json_object);

    cout << "\n \n" << lv_car_ptr->dump2JSON().toStyledString() << "\n \n";
    
    carInEmergency = *lv_car_ptr;

  }

  if(class_id == "Decision") {
    Decision * lv_decision_ptr;
    lv_decision_ptr = new Decision {};
    lv_decision_ptr->JSON2Object(json_object);

    cout << "\n \n" << lv_decision_ptr->dump2JSON().toStyledString() << "\n \n";
    
    decision = *lv_decision_ptr;

  }

  if(class_id == "Motorcycle") {
    Motorcycle * lv_motorcycle_ptr;
    lv_motorcycle_ptr = new Motorcycle {};
    lv_motorcycle_ptr->JSON2Object(json_object);

    cout << "\n \n" << lv_motorcycle_ptr->dump2JSON().toStyledString() << "\n \n";
    
    incomingMotor = *lv_motorcycle_ptr;

  }

    result["status"] = "successful";
  

  return result;
}


int main()
{
  // Server part of the Forest ----------------------------------------------------
  HttpServer httpserver3(0003);
  MotorCycleServer s(httpserver3, JSONRPC_SERVER_V2);
  s.StartListening();
  std::cout << "Awaiting information from ./rightMotorcycle and ./leftMotorcycle...\n";
  std::cout << "Enter = Kill Server" << "\n";
  getchar();
  s.StopListening();
  // End Server -------------------------------------------------------------------



  // Client starts __________________________________________________________________________

  HttpClient httpclient4("http://127.0.0.1:0004");
  middleCar mycar4(httpclient4, JSONRPC_CLIENT_V2);
  Json::Value jsonV4;

//these two try statements send info to middlecar
  try {
    jsonV4 = mycar4.move("move", "Motorcycle", RMotor.dump2JSON(), "52185080"); // Will need to send two of these to middleCar
    // I know the order of parameters is unusual, but RPC does things in alphabetical order
  }
  catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << jsonV4.toStyledString() << "\n";


  try {
    jsonV4 = mycar4.move("move", "Motorcycle", LMotor.dump2JSON(), "914204990"); // Will need to send two of these to middleCar
    // I know the order of parameters is unusual, but RPC does things in alphabetical order
  }
  catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << jsonV4.toStyledString() << "\n";
  // Client ends ____________________________________________________________________________
  return 0;
}
