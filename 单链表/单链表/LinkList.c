#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkList.h"

//基本操作
//初始化链表
Status InitList(LinkList L)
{
	L = (LinkList)malloc(sizeof(Lnode));//生成头结点，并且使头指针指向头结点
	L->next = NULL; //使头结点指向为空，即形成了空链表
	return OK;
}

//判断是否为空表
int IsEmpty(LinkList L)
{
	if (L->next) // 如果为空表
		return 0;
	else
		return 1;
}

//销毁一个链表
Status DestoryList(LinkList L)
{
	//从头指针开始依次释放所有的结点(包括头指针和头结点，即内存中没有这个链表了)
	Lnode* P;    //生成一个结点指针
	while (L)
	{
		P = L; //结点指针指向要释放的结点,从头节点开始
		L = L->next; //头指针指向 要释放的结点 的下一个 结点
		free(P); // 释放P指向的结点
	}
	P = L; //置空P，防止出现野指针
	return OK; 
}

//清空链表（头指针和头结点没有被释放）
Status ClearList(LinkList L)
{
	Lnode* p, *q;
	p = L->next; //从首元结点开始
	while (p)
	{
		q = p->next; //q保存的删除结点的下一个结点地址
		free(p); //释放结点
		p = q; //最后一次循环时p和q都被置为了NILL
	}
	L->next = NULL;//头结点的指针域置空
	return OK;
}

//求单链表的长度
int LengthList_L(LinkList L)
{
	int count = 0; //计数器
	Lnode* p;
	p = L->next; // 让结点指针指向首元结点
	while (p)
	{
		count++;
		p = p->next; //让结点指针指向下一个结点
	}
	return 0;
}

//取值
Status GetElem(LinkList L, int i, ElemType* e)
{
	//初始化
	int count = 1;
	Lnode* p;
	p = L->next; //指向首元结点
	while (p && count < i)  //跳出循环会有两种情况：1.找到元素 2.查找元素大于链表长度
	{
		p = p->next;  //指向下一结点
		count++;
	}
	if (!p || i < count)  //如果p为NULL说明已经找完了链表，没有此元素;查找元素不能小于1
		return ERROR;
	*e = p->data;
	return OK;

}

//按值查找（返回地址）
Lnode* LocateElemA(LinkList L, ElemType e)
{
	//初始化
	Lnode* p;
	p = L->next;

	//循环跳出：1.p == NULL，即链表遍历完 2.已经找到该值
	while (p && p->data == e)
	{
		p = p->next; //指针后移
	}
		return p;  

}

//按值查找（返回位置序号）
int LocateElemB(LinkList L, ElemType e)
{
	//初始化
	Lnode* p;
	p = L->next;
	int count = 1;  //计数器

	while (p && p->data != e)
	{
		p = p->next;
		count++;
	}
	if (p)
		return count;
	else
		return 0;
}

//在i个元素之前插入数据元素e
Status ListInsert(LinkList L, int i, ElemType e)
{
	//找到i-1个结点
	  //初始化
	Lnode* p;
	p = L->next;
	int count = 1;
	while (p && count < i-1) // 跳出循环：1.p为NULL 2.已经找到i-1个元素
	{
		p = p->next;
		count++;
	}
	if (!p && i < count)
		return ERROR;
	//建立一个结点(结点指针)
	Lnode* s = (LinkList)malloc(sizeof(Lnode));
	s->data = e;  // 放入数据元素
	//插入结点
	s->next = p->next;
	p->next = s;
	return OK;
}

//删除第i个函数
Status DeleList(LinkList L, int i, ElemType* e)
{
	//初始化
	Lnode* p,*q;
	p = L->next;
	int count = 1;
	//查到i-1结点
	while (p && count < i-1)
	{
		p = p->next; //指向下一个结点
		count++;
	}
	if (!p && i < count)
		return ERROR;
	//将删除结点从链表上去掉
	q = p->next;  //第n个结点
	p = q->next; //将第 n+1 个结点的地址赋给 n-1结点的指针域
	//释放删除结点的空间
	free(q);
	return OK;
}

//创建链表（头插法:倒位序插入，从最后一个元素开始向前插入）
void CreatList_H(LinkList L, int n)
{
	//创建一个带有头结点的空表
	L = (Lnode*)malloc(sizeof(Lnode));
	L->next = NULL;
	//头插法插入结点
	for (int i = n; i > 0; --i)
	{
		//创建结点
		Lnode* p;
		p = (Lnode*)malloc(sizeof(Lnode));
		//输入数据
		scanf("%d", &p->data);
		//插入结点
		p->next = L->next;
		L->next = p;
	}
}
//创建链表（尾插法）
void CreatList_R(LinkList L, int n)
{
	//初始化
	Lnode* p;
	Lnode* r; //尾指针
	//创建一个带头结点的空表
	L = (Lnode*)malloc(sizeof(Lnode));
	L->next = NULL;
	r = L; //尾指针指向头结点
	//头插法插入结点
	for (int i = 0; i < n; i++)
	{
		//生成结点
		 p = (Lnode*)mallco(sizeof(Lnode));
		//输入数据
		scanf("%d", &p->data);
		//插入结点
		p->next = NULL; //插入结点变成尾结点
		r->next = p;  //插入结点接在前一个结点后面
		r = p;  //尾指针移动到新的伪结点
	}
}