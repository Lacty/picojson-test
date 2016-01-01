
#include <iostream>
#include <fstream>
#include <sstream>
#include "picojson.h"


int main() {
  std::stringstream ss;
  std::ifstream      f;

  f.open("test.json", std::ios::binary);
  
  ss << f.rdbuf();
  f.close();

  picojson::value v;
  ss >> v;

  picojson::object& o
    = v.get<picojson::object>()["hoge"].get<picojson::object>();
  std::cout << "player = " << o["player"].get<double>() << std::endl;
  std::cout << "enemy  = " << o["enemy"].get<double>()  << std::endl;
}
