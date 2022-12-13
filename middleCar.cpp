#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/value.h>
#include <string>
#include <cstring>

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

// So we don't have to type jsonrpc:: or std:: for some standard functions
using namespace jsonrpc;
using namespace std;
//-------------------------------------------------------------------------------------------//

//---------------------------------------------------------------------------------------------------//
Car carInEmergency {};
Motorcycle LMotor {};
Motorcycle incomingMotor {};
Decision decisionL {};
Decision decisionR {};
Decision decision {};



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
Car MCar {};
Car MCar2{};
//--------------------------------------------------------------------------------------------------//
//----------------------------- this is creating person object--------------------------------------//
  int Age_1;
  int Age_2;
  string pers_height1;
  string pers_height2;
  string pers_gender1;
  string pers_gender2;
  string pers_name;
  string pers_name2;
  int pers_longitude;
  int pers_latitude;
  int pers_longitude2;
  int pers_latitude2;
 

  string pers_felix;
  GPS* pers_location[4];
  MCar.numPassengers = 4;
  
  Person person[4];
  for(int i = 0; i < 1; i++)
  {
      pers_location[0] = new GPS();
      // Person person[i];
      cout << "Define driver1 " << endl;
      cout << "age" <<endl;
      cin >> Age_1;
      cout << "gender (M or F): " << endl;
      cin>>pers_gender1;
      cin.clear();
      cout << "Pers height (in feet): "<<endl;
      cin >> pers_height1;
      cin.clear();
      cout << "name"<<endl;
      cin >> pers_name;
      cin.clear();
      cout << "long , latitude"<<endl;
      cin >> pers_longitude;
      cin.clear();
      cin >> pers_latitude;
      pers_location[i]->setYCoord(pers_longitude);
      pers_location[i]->setXCoord(pers_latitude);
      MCar.persarray[i].setLocation(*(pers_location[i]));
      
      cin.clear();
      
      /*cout << "is it Felix (true or false): "<<endl;
      cin >> pers_felix;
      cin.clear();
      */

      person[i].setAge(Age_1);
      cout << person[i].getAge() << endl;
      person[i].setHeight(pers_height1);
      cout << person[i].getHeight() << endl;
      person[i].setGender(pers_gender1);
      cout << person[i].getGender() << endl;
      person[i].setName(pers_name);
      cout << person[i].getName() << endl;
      
      
      cout << "Print: " <<  MCar.persarray[i].getLocation().getXCoord() << endl;
      MCar.persarray[i] = person[i];
      


}

//------------------------------END OF PERSON OBJ----------------------------------//

//------------------------------CREATING CAR OBJECT----------------------------------//
 
  string description_1;
  double weight_1;
  double height_1;
  double integrity_1;
  double airbag_1;
  string description_2;
  double weight_2;
  double height_2;
  double integrity_2;
  double airbag_2;

  int numPassengers;
  bool emergency_1;
  int longitude;
  int latitude;
  GPS location{};


cout << "Enter type of Motorcycle (right)" << endl;
cin >> description_1;
cin.clear();
cout << "Enter weight of Motorcycle (number)" << endl;
cin >> weight_1;
cin.clear();
cout << "Enter height of Motorcycle (number)" << endl;
cin >> height_1;
cin.clear();
cout << "Structural Integrity (1-10)" << endl;
cin >> integrity_1;
cin.clear();
cout << "Airbag quality (1-10)" << endl;
cin >> airbag_1;
cin.clear();

  for(int i = 0; i < 1; i++)
  {
      pers_location[0] = new GPS();
      // Person person[i];
      cout << "Define driver2 " << endl;
      cout << "age" <<endl;
      cin >> Age_2;
      cout << "gender (M or F): " << endl;
      cin>>pers_gender2;
      cin.clear();
      cout << "Pers height (in feet): "<<endl;
      cin >> pers_height2;
      cin.clear();
      cout << "name"<<endl;
      cin >> pers_name2;
      cin.clear();
      cout << "long , latitude"<<endl;
      cin >> pers_longitude2;
      cin.clear();
      cin >> pers_latitude2;
      pers_location[i]->setYCoord(pers_longitude2);
      pers_location[i]->setXCoord(pers_latitude2);
      MCar2.persarray[i].setLocation(*(pers_location[i]));
      
      cin.clear();
      
      /*cout << "is it Felix (true or false): "<<endl;
      cin >> pers_felix;
      cin.clear();
      */

      person[i].setAge(Age_2);
      cout << person[i].getAge() << endl;
      person[i].setHeight(pers_height2);
      cout << person[i].getHeight() << endl;
      person[i].setGender(pers_gender2);
      cout << person[i].getGender() << endl;
      person[i].setName(pers_name2);
      cout << person[i].getName() << endl;
      
      
      cout << "Print: " <<  MCar2.persarray[i].getLocation().getXCoord() << endl;
      MCar2.persarray[i] = person[i];
      


}

cout << "Enter type of Motorcycle (left)" << endl;
cin >> description_2;
cin.clear();
cout << "Enter weight of Motorcycle (number)" << endl;
cin >> weight_2;
cin.clear();
cout << "Enter height of Motorcycle (number)" << endl;
cin >> height_2;
cin.clear();
cout << "Structural Integrity (1-10)" << endl;
cin >> integrity_2;
cin.clear();
cout << "Airbag quality (1-10)" << endl;
cin >> airbag_2;
cin.clear();



//-------------------CAR location--------------------------//

cout << "longitude, latitude" << endl;
cin >> longitude;
cin.clear();
cin >> latitude;
cin.clear();


//--------------------------------UPDATING CAR1 VARIABLES------------------------------------------//
MCar.description = description_1;
cout<<MCar.description<<endl;

MCar.weight = weight_1;
cout<<MCar.weight<<endl;

MCar.height = height_1;
cout<<MCar.height<<endl;

MCar.structuralIntegrity = integrity_1;
cout<<MCar.structuralIntegrity<<endl;

MCar.airBagQuality = airbag_1;
cout<<MCar.airBagQuality<<endl;

location.setYCoord(longitude);
cout << location.getYCoord() << endl;
location.setXCoord(latitude);
cout << location.getXCoord() << endl;
MCar.location = location;

//-------------------------------- END CAR1 VARIABLES------------------------------------------//

//--------------------------------UPDATING CAR2 VARIABLES------------------------------------------//
MCar2.description = description_2;
cout<<MCar2.description<<endl;

MCar2.weight = weight_2;
cout<<MCar2.weight<<endl;

MCar.height = height_2;
cout<<MCar2.height<<endl;

MCar2.structuralIntegrity = integrity_2;
cout<<MCar2.structuralIntegrity<<endl;

MCar2.airBagQuality = airbag_2;
cout<<MCar2.airBagQuality<<endl;

location.setYCoord(longitude);
cout << location.getYCoord() << endl;
location.setXCoord(latitude);
cout << location.getXCoord() << endl;
MCar2.location = location;

//-------------------------------- END CAR1 VARIABLES------------------------------------------//

//--------------------------------UPDATING leftMotorcycle Variables-----------------------------//



//--------------------------------START MOTORCYCLE OBJECT------------------------------------------//

//   Motorcycle lM{};

//   int Age_1;
//   string pers_height1;
//   string pers_gender1;
//   string pers_name;
//   int pers_longitude;
//   int pers_latitude;
 


//   string pers_felix;
//   GPS pers_location;
//   Person lmoto_person[2];
//   for(int i = 0; i < 2; i++)
//   {
//       // Person person[i];
//       cout << "define driver " << endl;
//       cout << "age" <<endl;
//       cin >> Age_1;
//       cout << "gender (M or F): " << endl;
//       cin>>pers_gender1;
//       cin.clear();
//       cout << "Pers height (in feet): "<<endl;
//       cin >> pers_height1;
//       cin.clear();
//       cout << "name"<<endl;
//       cin >> pers_name;
//       cin.clear();
//       cout << "long , latitude"<<endl;
//       cin >> pers_longitude;
//       cin.clear();
//       cin >> pers_latitude;
//       cin.clear();
//       cout << "is it Felix (true or false): "<<endl;
//       cin >> pers_felix;
//       cin.clear();

//       lmoto_person[i].setAge(Age_1);
//       cout << lmoto_person[i].getAge() << endl;
//       lmoto_person[i].setHeight(pers_height1);
//       cout << lmoto_person[i].getHeight() << endl;
//       lmoto_person[i].setGender(pers_gender1);
//       cout << lmoto_person[i].getGender() << endl;
//       lmoto_person[i].setName(pers_name);
//       cout << lmoto_person[i].getName() << endl;

//       pers_location.setYCoord(pers_longitude);
//       pers_location.setXCoord(pers_latitude);
//       // lM.persarray[i] = person[i];
//       lM.persarray[i] = lmoto_person[i];
 
//   string description_1;
//   double weight_1;
//   double height_1;
//   double integrity_1;
//   double airbag_1;

//   int numPassengers;
//   bool emergency_1;
//   int longitude;
//   int latitude;
//   GPS location{};


// cout << "Enter type of Motorcycle" << endl;
// cin >> description_1;
// cin.clear();
// cout << "Enter weight of Motorcycle (number)" << endl;
// cin >> weight_1;
// cin.clear();
// cout << "Enter height of Motorcycle (number)" << endl;
// cin >> height_1;
// cin.clear();
// cout << "Structural Integrity (1-10)" << endl;
// cin >> integrity_1;
// cin.clear();
// cout << "Airbag quality (1-10)" << endl;
// cin >> airbag_1;
// cin.clear();


// cout << "longitude, latitude" << endl;
// cin >> longitude;
// cin.clear();
// cin >> latitude;
// cin.clear();

// lM.description = description_1;
// cout<<lM.description<<endl;

// lM.weight = weight_1;
// cout<<lM.weight<<endl;

// lM.height = height_1;
// cout<<lM.height<<endl;

// lM.structuralIntegrity = integrity_1;
// cout<<lM.structuralIntegrity<<endl;

// lM.airBagQuality = airbag_1;
// cout<<lM.airBagQuality<<endl;

// location.setYCoord(longitude);
// cout << location.getYCoord() << endl;
// location.setXCoord(latitude);
// cout << location.getXCoord() << endl;
// //cout << location << endl;
//--------------------------------END MOTORCYCLE OBJECT------------------------------------------//





//--------------------------------DECISION MAKING CODE------------------------------------------//
int tally1 = 0;
 if(Age_1 > 65){
  tally1++;
 }
 if(pers_gender1 == "M"){
  tally1++; 
}
//if(pers_felix == "false"){
  //tally1++;

//}
//else if(pers_felix == "true"){
  //break;
  //cout<<"I'll hit other car";
//}

if(weight_1 > 200){
  tally1++;
}
if(height_1 > 8){
  tally1++;

}
if(integrity_1>7){
  tally1++;

}
if(airbag_1>7){
  tally1++;
}
cout<<"Motorcycle 1 Tally is: "<<tally1<<endl;

int tally2 = 0;
 if(Age_2 > 65){
  tally2++;
 }
 if(pers_gender2 == "M"){
  tally2++; 
}
//if(pers_felix == "true"){
  //break;
  //cout<<"I'll hit the other car."<<endl;

//}
//else if(pers_felix == "false"){
    //tally2++;
//}
if(weight_2 > 200){
  tally2++;
}
if(height_2 > 8){
  tally2++;

}
if(integrity_2>7){
  tally2++;

}
if(airbag_2>7){
  tally2++;
}
cout<<"Motorcycle 2 Tally is: "<<tally2<<endl;

//comparing tallies for final decision
if(tally1>tally2){
  cout<<"I'll hit Motorcycle1"<<endl;
}
else if(tally1<tally2){
  cout<<"I'll hit Motorcycle2"<<endl;
}
else if(tally1=tally2){
  cout<<"I'll sacrifice myself."<<endl;
}

//--------------------------------DECISION MAKING CODE END------------------------------------------//












  // Now it's time to do RPC (CLIENT) stuff *************************************************************************************************


  HttpClient httpclient1("http://127.0.0.1:0001");
  middleCar mycar1(httpclient1, JSONRPC_CLIENT_V2);
  Json::Value jsonV1;

  HttpClient httpclient2("http://127.0.0.1:0002");
  middleCar mycar2(httpclient2, JSONRPC_CLIENT_V2);
  Json::Value jsonV2;

 
  try {
    jsonV1 = mycar1.move("move", "Car", MCar.dump2JSON(), "00000342");
    // I know the order of parameters is unusual, but RPC does things in alphabetical order
    //moves copy of the car you create from cin and cout and moves over to 
  }
  catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << jsonV1.toStyledString() << "\n";

  try {
    jsonV2 = mycar2.move("move", "Car", MCar2.dump2JSON(), "00000343");
    // I know the order of parameters is unusual, but RPC does things in alphabetical order
  }
  catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << jsonV2.toStyledString() << "\n";
  // End of RPC (CLIENT) stuff *****************************************************************************************************

  // Begin Server -------------------------------------------------------------------------------------------------

  HttpServer httpserver4(0004);
  MotorCycleServer s(httpserver4, JSONRPC_SERVER_V2);
  s.StartListening();
  std::cout << "Awaiting information from ./middleCarReturn...\n";
  std::cout << "Enter = Kill Server" << "\n";
  getchar();
  s.StopListening();

  // End Server ---------------------------------------------------------------------------------------------------

  // One more client phase to send the directions to the motorcycles ______________________________

  try {
    jsonV1 = mycar1.move("move", "Decision", decisionL.dump2JSON(), "82305823");
    // I know the order of parameters is unusual, but RPC does things in alphabetical order
  }
  catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << jsonV1.toStyledString() << "\n";

  try {
    jsonV2 = mycar2.move("move", "Decision", decisionR.dump2JSON(), "359276196");
    // I know the order of parameters is unusual, but RPC does things in alphabetical order
  }
  catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << jsonV2.toStyledString() << "\n";

  // ______________________________________________________________________________________________

  return 0;
}