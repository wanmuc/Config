# 1.Config
> 使用c++实现的ini格式配置文件读取类，可以直接在项目中使用，无任何其他依赖。
## 1.1 目录结构
- test子目录保存了单元测试相关代码和文件。
- tool子目录保存了自动生成配置类代码的脚手架代码。

# 2.提供的api
- Load函数用于加载配置文件。
- Dump函数用于导出配置文件内容。
- GetIntValue函数和GetStrValue函数用于获取配置中的具体的配置项。

# 3.实现原理
每次读取一行文件的内容进行解析。在解析每行数据时，先删除注释信息，然后再解析。
如果当前行是section，则更新section，如果当前行是kv配置项，则解析key和value。
最后所有的配置信息被存储在二维map的内存对象中。

# 4.如何使用
直接使用include的预编译指令包含config.hpp，然后调用相关的api接口，需要特别注意的是，至少需要使用c++11进行编译。

# 5.微信公众号
敬请扫码关注微信公众号「Linux后端研发工程实践 」，及时获得最新文章！
![img.png](https://github.com/wanmuc/Config/blob/main/mp_account.png#pic_center=660*180)
也欢迎大家加我个人微信号：wanmuc2018，我们来一起交流技术。