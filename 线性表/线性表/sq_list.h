#define _CRT_SECURE_NO_WARNINGS 1

// 头文件引入
#include <stdio.h>
#include <stdlib.h>

// 常量
#define MAXSIZ 100

//函数结果状态代码
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBALE 0
#define OVERFLOW 0

// Status   返回函数的类型
typedef int Status;
typedef char ElemType;

//线性表的定义
typedef struct  
{         
	ElemType * elem;
	int Length;
}SqList;


//函数声明 (函数基本操作)
Status initlist_sq(SqList*L); //初始化一个空表
void DestoryList(SqList* L); //销毁一个表  
void ClearList(SqList* L); // 清空一个线性表
int GetLength(SqList L); //求线性表的长度
int IsEmpty(SqList L);//判断一个线性表是否为空
Status GetElem(SqList L, int i, ElemType* e); // 顺序表的取值
int LocateElem(SqList L, ElemType e);//查找元素
Status ListInsert_Sq(SqList* L, int i, ElemType e);//插入函数
Status ListDlete_Sq(SqList* L, int i, ElemType e);//删除函数