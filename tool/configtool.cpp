#include <iostream>
#include <regex>
#include <string>

#include "../config.hpp"

using namespace std;

int genCfgReadFile(Config::Ini &ini, string file_name) {
  string prefix = "";
  for (size_t i = 0; i < file_name.size(); i++) {
    if (file_name[i] == '.') break;
    if (prefix == "") {
      prefix = toupper(file_name[i]);
    } else {
      prefix += file_name[i];
    }
  }
  string class_name = prefix + "Cfg";
  string output_file_name = prefix + "Cfg.hpp";
  ofstream out;
  out.open(output_file_name);
  if (not out.is_open()) {
    cout << "open " << output_file_name << " failed." << endl;
    return -1;
  }
  string cfg_read_content;
  string class_func_content;
  string class_member_content;
  ini.Dump([&cfg_read_content, &class_func_content, &class_member_content](const string &section, const string &key,
                                                                           const string &value) {
    regex integer_regex("[+-]?[0-9]+");
    if (regex_match(value, integer_regex)) {  // 整数
      cfg_read_content += "    ini.GetIntValue(\"" + section + "\", \"" + key + "\", " + key + "_, 0);\n";
      class_func_content += "  int64_t " + key + "() { return " + key + "_; }\n";
      class_member_content += "  int64_t " + key + "_;\n";
    } else {
      cfg_read_content += "    ini.GetStrValue(\"" + section + "\", \"" + key + "\", " + key + "_, \"\");\n";
      class_func_content += "  std::string " + key + "() { return " + key + "_; }\n";
      class_member_content += "  std::string " + key + "_;\n";
    }
  });
  //
  string content = R"(#include <string>

#include "config.hpp"

class )" + class_name +
                   R"( {
 public:
  bool Load(std::string file_name) {
    Config::Ini ini;
    if (not ini.Load(file_name)) {
      return false;
    }
)" + cfg_read_content +
                   R"(
  }
)" + class_func_content +
                   R"(
 public:
)" + class_member_content +
                   "};";
  out << content;
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "usage: configtool mysvr.cfg" << endl;
    return -1;
  }
  Config::Ini ini;
  string file_name = argv[1];
  if (not ini.Load(file_name)) {
    cout << "load " << file_name << " failed." << endl;
    return -1;
  }
  return genCfgReadFile(ini, file_name);
}