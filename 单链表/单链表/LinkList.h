#define _CRT_SECURE_NO_WARNINGS 1

//头文件
#include <stdio.h>
#include <stdlib.h>

//宏
typedef int ElemType;
typedef int Status;

//常量
#define OK 1
#define ERROR 0


//定义一个结点
typedef struct Lnode
{
	ElemType data;  // 数据域
	struct Lnode* next;//指针域
}Lnode,*LinkList;  // 结构体别名

LinkList L; // 生成头指针，头指针名字叫L，即链表名字也就是L，只有通过该指针才能找到整个链表

//函数定义
Status InitList(LinkList L); //链表初始化，生成一个空链表
int IsEmpty(LinkList L); //判断L链表是否为空表
Status DestoryList(LinkList L); //销毁一个链表
Status ClearList(LinkList L); //清空一个链表
int LengthList_L(LinkList L); //求单链表的长度
Status GetElem(LinkList L, int i, ElemType* e);//取值
Lnode* LocateElemA(LinkList L, ElemType e);//按值查找（返回地址）
int LocateElemB(LinkList L, ElemType e);//按值查找（返回位置序号）
Status ListInsert(LinkList L, int i, ElemType e);//第i个元素之前插入数据元素
Status DeleList(LinkList L, int i, ElemType* e); // 删除第i个数据元素
void CreatList_H(LinkList L, int n); //头插法创建链表
void CreatList_R(LinkList L, int n); //尾插法创建链表
