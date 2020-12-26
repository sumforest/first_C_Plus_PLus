#pragma once
#include <iostream>
using namespace std;
#include <string>

class Identity
{
public:
	// 操作菜单
	virtual void  operatorMenu() = 0;

	// 用户名
	string name;

	// 密码
	string password;
};
