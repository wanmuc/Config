#include <string>

#include "config.hpp"

class MysvrCfg {
 public:
  bool Load(std::string file_name) {
    Config::Ini ini;
    if (not ini.Load(file_name)) {
      return false;
    }
    ini.GetStrValue("server", "ip", ip_, "");
    ini.GetIntValue("server", "port", port_, 0);
    ini.GetIntValue("pool", "conn_pool_size", conn_pool_size_, 0);
  }
  int64_t port() { return port_; }
  std::string ip() { return ip_; }
  int64_t conn_pool_size() { return conn_pool_size_; }

 public:
  int64_t port_;
  std::string ip_;
  int64_t conn_pool_size_;
};