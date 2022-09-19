#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//实现一个顺序栈


//常量
#define  MAXSIZ 10  //栈大小
#define ERROR -1
#define OK 1
#define FALSE 0

//Status 返回状态
typedef int ElemType; //存储数据类型
typedef int Status;  //函数返回

//定义顺序栈
typedef struct SqStack
{
	ElemType* top;  //头指针
	ElemType* base;//基底指针
	int StackSize; //栈大小
}SqStack;

//初始化
Status InitStack(SqStack* S)
{
	//分配空间
	ElemType* p = (ElemType*)malloc(MAXSIZ * sizeof(ElemType));
	if (!p)
		return ERROR;
	S->base = p;
	S->top = S->base;
	S->StackSize = MAXSIZ;
	return OK;
	
}

//判断是否为空
Status IsEmpty(SqStack* S)  //为空返回1，不为空返回 0
{
	if (S->top == S->base) return OK;
	else return FALSE;
}

//清空顺序栈
Status ClearStack(SqStack* S)
{
	if (S->base)  //如果这个栈存在
	{
		S->top = S->base;
		return OK;
	}
	else
		FALSE;
}

//入栈操作
Status Push(SqStack* S,ElemType e)
{
	//判断栈是否满（是否会出现上溢）
	if (S->base && S->top - S->base == MAXSIZ)
	{
		*S->top++ = e; //写入数据，指针上移
		return OK;
	}
	else
		ERROR; 
}
//销毁栈
Status DestoryStack(SqStack* S)
{
	if (S->base)
	{
		free(S->base);
		S->base = S->top = NULL; //指针置空
	}
	return OK;
}

//出栈
Status Pop(SqStack* S,ElemType* e)
{
	//判断是否栈空（判断是否会下溢出）
	if (S->top == S->base) return ERROR;
	//出栈
	*e = *--S->top;
	return OK;
}
int main()
{
	SqStack S;
	InitStack(&S);
	return 0;
}