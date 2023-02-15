#pragma once
/* 定义了与服务器直接的信息协议 比如 0开头代表我这条信息是要画圆形
*/
#define ADDRESS "127.0.0.1" // 服务器ip地址
#define PORT 8080   // 链接端口
#define MSGEND "\n" // 信息末端分隔符

#define CMD_QUIT "quit"
#define CMD_CIRCLE "0"
#define CMD_POLYGONE "1"
#define CMD_LINE "2"
#define CMD_LOAD "3"
#define CMD_SAVE "4"
#define CMD_CLEAR "5"

#define ID_CIRCLE 0
#define ID_POLYGONE 1
#define ID_LINE 2