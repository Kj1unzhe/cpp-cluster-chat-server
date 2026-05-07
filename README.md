# 🚀 C++ 集群聊天服务器

基于 C++ 实现的高并发集群聊天服务器，支持多用户同时在线、跨服务器消息同步与负载均衡，适合学习网络编程、分布式架构设计。

---

## ✨ 项目亮点
- **高并发网络模型**：基于 muduo 库的 Reactor 多线程模型，支持万级并发连接
- **集群与负载均衡**：Nginx TCP 负载均衡 + Redis 发布订阅实现跨服务器消息同步
- **完整聊天功能**：用户注册/登录、单聊/群聊、好友添加、离线消息存储
- **数据持久化**：MySQL 存储用户、好友、群组信息，数据不丢失
- **模块化设计**：业务逻辑分层清晰，易扩展、易维护

---

## 🛠️ 技术栈
| 模块         | 技术/工具                         |
|--------------|----------------------------------|
| 语言         | C++11/14                         |
| 网络库       | muduo                            |
| 负载均衡     | Nginx（TCP 反向代理）            |
| 消息队列     | Redis（发布/订阅）               |
| 数据库       | MySQL                            |
| 构建工具     | CMake                            |
| 并发模型     | 多线程 + 事件驱动（Epoll）       |

---

## 📁 项目结构
- cpp-cluster-chat-server/
- ├── bin/ # 可执行文件目录
- ├── build/ # 编译构建目录
- ├── include/ # 头文件目录
- │ ├── server/ # 服务器核心逻辑
- │ ├── model/ # 数据模型（用户 / 好友 / 群组）
- │ ├── db/ # 数据库操作封装
- │ └── common/ # 公共工具类
- ├── src/ # 源文件目录
- ├── test/ # 单元测试目录
- ├── thirdparty/ # 第三方依赖库
- └── CMakeLists.txt # CMake 构建配置

---

## 🚀 快速启动

### 1. 环境准备
- 操作系统：Linux（Ubuntu 推荐）
- 依赖安装：
```bash
# 安装基础依赖
sudo apt update && sudo apt install -y cmake gcc g++ make mysql-server redis-server

# 安装 muduo 网络库（示例）
git clone https://github.com/chenshuo/muduo.git
cd muduo && mkdir build && cd build
cmake .. && make && sudo make install
```

### 2. 编译项目
```bash
# 进入项目根目录
cd cpp-cluster-chat-server

# 创建构建目录
mkdir build && cd build

# 编译
cmake ..
make
```

### 3. 启动服务
```bash
# 启动 Redis
redis-server &

# 启动 MySQL（确保已创建对应数据库与表）
sudo service mysql start

# 启动聊天服务器
./bin/chat_server
```

---

## 📌 功能说明
### 用户系统
- 支持用户注册、登录、退出
- 在线状态实时更新
### 好友系统
- 添加好友、删除好友
- 好友列表查询
### 群聊系统
- 创建群组、加入群组、退出群组
- 群内消息广播
### 离线消息
- 用户离线时收到的消息会存储在数据库
- 上线后自动推送所有离线消息
### 集群通信
- 不同服务器上的用户可跨服务器聊天
- Redis 发布订阅实现消息同步

---

## 📝 后续优化方向
- 增加心跳检测，处理僵尸连接
- 实现断线重连机制
- 增加日志分级与持久化
- 支持私聊加密传输
- 前端客户端实现（Qt/WebSocket）
