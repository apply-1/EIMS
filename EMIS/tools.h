#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <cstring>
#include <getch.h>
#include <unistd.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

#define DATA_ID_PATH "./data/id.dat"
#define DATA_MGR_PATH "./data/managers.dat"
#define DATA_SRV_PATH "./data/services.dat"

//	从键盘获取字符串
char* get_str(char* str,size_t len);

//	从键盘输入密码
char* get_pass(char* pass,size_t len,bool is_show=false);

int get_cmd(char start,char end);
void anykey_continue(void);

//	初始化id.dat文件
void init_id(void);

//生成唯一的管理员id函数
int get_mgrid(void);
//生成唯一的货架id函数
int get_shelfid(void);
//生成唯一的快递id函数
int get_goodid(void);

#endif//TOOLS_H
