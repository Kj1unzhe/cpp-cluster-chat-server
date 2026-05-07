# cpp-cluster-chat-server
基于 C++ muduo 网络库实现的高并发集群聊天服务器，集成 Nginx TCP 负载均衡、Redis 发布 - 订阅消息队列、MySQL 数据持久化，支持注册登录、好友 / 群聊、离线消息、跨服务器通信，采用 Reactor 多线程模型与 CMake 构建。（服务器和客户端源码）
