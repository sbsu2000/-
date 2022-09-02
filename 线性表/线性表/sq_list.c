#define _CRT_SECURE_NO_WARNINGS 1
#include "sq_list.h"

//函数定义

// 初始化一个表（构造一个空的表）
Status initlist_sq(SqList* L)
{
	L->elem = (ElemType*)malloc(sizeof(ElemType) * MAXSIZ); //为顺序表动态分配内存
	if (!L->elem)    // 异常判断——分配内存失败
		exit(OVERFLOW);
	L->Length = 0;  // 此表为空表没有任何元素
	return OK;
}

//销毁一个表
void DestoryList(SqList* L)
{
	if (L->elem)
		free(L->elem);
}

//清空线性表
void ClearList(SqList* L)
{
	L->Length = 0;
}

//求线性表的长度
int GetLength(SqList L)
{
	return (L.Length);
}

//判断先线性表是否为空
 int IsEmpty(SqList L)
{
	if (L.Length == 0)return 1;
	else return 0;
}

//顺序表的取值
 Status GetElem(SqList L, int i, ElemType* e)
 {
	 if (i < 1 || i > L.Length)return ERROR; //异常判断
	 else
		 *e = L.elem[i-1];
	 return OK;
 }

 //顺序表的查找 （顺序查找）
 int LocateElem(SqList L, ElemType e)
 {
	 for (int i = 0; i < L.Length; i++)
	 {
		 if (L.elem[i] == e)
			 return i + 1;
		 return 0;
	 }
 }

 //插入函数  
  //算法思想：判断插入位置是否合法（异常1.插入位置小于0或者大于L.length 异常2.表已经满了，返回ERROR）
 Status ListInsert_Sq(SqList* L, int i, ElemType e)
 {
	 if (i < 1 || i > L->Length) return ERROR; //异常1
	 if (L->Length > MAXSIZ) return ERROR; //异常2
	 for (int j = L->Length; j > i-1; j--)
	 {
		 L->elem[j] = L->elem[j-1];
	 }
	 L->elem[i - 1] = e;
	 L->Length++;
	 return OK;
 }

 //删除函数
 Status ListDlete_Sq(SqList* L, int i, ElemType* e)
 {
	 if (i < 1 || i > L->Length) return ERROR;//异常判断
	 *e = L->elem[i - 1];
	 for (int j = i; j > L->Length; j--)
	 {
		 L->elem[i - 1] = L->elem[i];
	 }
	 L->Length--; // 长度减一
	 return OK;

 }