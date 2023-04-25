#include "../config.hpp"

#include "unittestcore.hpp"

TEST_CASE(Config_All) {
  Config::Ini ini;
  ASSERT_TRUE(ini.Load("./test.cfg"));
  int64_t port;
  ini.GetIntValue("server", "port", port, 100);
  ASSERT_EQ(port, 1688);
  ini.GetIntValue("server", "port2", port, 100);
  ASSERT_EQ(port, 100);
  std::string ip;
  ini.GetStrValue("server", "ip", ip, "0.0.0.0");
  ASSERT_EQ(ip, "127.0.0.1");
  ini.GetStrValue("server", "ip2", ip, "0.0.0.0");
  ASSERT_EQ(ip, "0.0.0.0");
}

RUN_ALL_TESTS();