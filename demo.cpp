#include <iostream>

#include "config.hpp"

int main(int argc, char *argv[]) {
  Config::Ini ini;
  ini.Load("./demo.cfg");
  ini.Dump([](const std::string &section, const std::string &key, const std::string value) {
    std::cout << "section[" << section << "],key[" << key << "]->value[" << value << "]" << std::endl;
  });
  return 0;
}