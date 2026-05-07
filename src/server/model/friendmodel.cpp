#include "friendmodel.hpp"

#include <vector>

#include "db.h"
#include "user.hpp"

void FriendModel::insert(int userid, int friendid) {
  // 1.组装sql语句
  char sql[1024] = {0};
  sprintf(sql, "insert into Friend values(%d,%d)", userid, friendid);
  MySQL mysql;
  if (mysql.connect()) {
    mysql.update(sql);
  }
}

vector<User> FriendModel::query(int userid) {
  char sql[1024] = {0};
  sprintf(sql, "select a.id,a.name,a.state from User a inner join Friend b on b.friendid = a.id where b.userid = %d", userid);
  vector<User> vec;
  MySQL mysql;
  if (mysql.connect()) {
    MYSQL_RES* res = mysql.query(sql);
    if (res != nullptr) {
      MYSQL_ROW row;
      // 把userid用户的所有离线消息放入vec中返回
      while ((row = mysql_fetch_row(res)) != nullptr) {
        User user;
        user.setId(atoi(row[0]));
        user.setName(row[1]);
        user.setState(row[2]);
        vec.push_back(user);
      }
      mysql_free_result(res);
      return vec;
    }
  }
  return vec;
}
