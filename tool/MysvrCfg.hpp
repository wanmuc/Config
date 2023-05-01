#include <string>

#include "config.hpp"

class MysvrCfg {
 public:
  bool Load(std::string file_name) {
    Config::Ini ini;
    if (not ini.Load(file_name)) {
      return false;
    }
    ini.GetIntValue("pool", "conn_pool_size", conn_pool_size_, 0);
    ini.GetIntValue("server", "port", port_, 0);
    ini.GetStrValue("server", "ip", ip_, "");
  }
  int64_t conn_pool_size() { return conn_pool_size_; }
  int64_t port() { return port_; }
  std::string ip() { return ip_; }

 public:
  int64_t conn_pool_size_;
  int64_t port_;
  std::string ip_;
};