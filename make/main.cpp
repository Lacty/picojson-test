
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../picojson.h"


int main() {
  {
    picojson::object obj;
    obj.insert(std::make_pair("hoge", picojson::value(10.0)));

    picojson::value json(obj);
    std::cout << json.serialize().c_str() << std::endl;
  }
  
  {
    picojson::object obj;
    picojson::array  arr;
    arr.push_back(picojson::value(10.0));
    arr.push_back(picojson::value(20.0));
    arr.push_back(picojson::value(30.0));

    obj.insert(std::make_pair("vector", arr));

    picojson::value json(obj);
    std::cout << json.serialize().c_str() << std::endl;
  }

  {
    picojson::object obj;
    picojson::array  arr;
    
    obj.insert(std::make_pair("hp", picojson::value(10.0)));
    arr.push_back(picojson::value(obj));
    obj.clear();
    
    obj.insert(std::make_pair("atk", picojson::value(20.0)));
    arr.push_back(picojson::value(obj));
    obj.clear();

    // parent
    obj.insert(std::make_pair("player", arr));

    picojson::value json(obj);
    std::cout << json.serialize().c_str() << std::endl;

    std::ofstream ofs("test.json");
    ofs << json.serialize().c_str();
  }
}
