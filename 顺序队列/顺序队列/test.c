#define _CRT_SECURE_NO_WARNINGS 1

//顺序循环队列
 
 
//头文件
#include <stdio.h>
#include <stdlib.h>

//宏
typedef int ElemType;
typedef int Status;

//常量
#define OK 1
#define ERROR 0
#define MAXSIZE 100

//定义一个循环队列
typedef struct
{
	ElemType* base;  //数据空间
	int front;  //头指针
	int rear;  //尾指针


}SqQueue;
int InitQueue(SqQueue* Q)
{
	Q->base = (SqQueue*)malloc(MAXSIZE * sizeof(ElemType)); //分配空间
	if (!Q->base) return ERROR;
	Q->front = 0; //头指针
	Q->rear = 0; //尾指针
	return OK;
}

//计算队长
int LengthSq(SqQueue Q)
{
	return ((Q.rear - Q.front + MAXSIZE) % MAXSIZE);
}

//入队
int InQueue(SqQueue* Q,ElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front) return ERROR; //判断队满
	Q->base[Q->rear] = e;//数据输入
	Q->rear = (Q->rear + 1) % MAXSIZE; //尾指针后移
	return OK;
}

//出队
int OutSqueue(SqQueue* Q,ElemType* e)
{
	if (Q->front == Q->rear) return ERROR; //判断队空
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE; //头指针后移
	return OK;
	
}

//获得队头元素
int GetHead(SqQueue Q)
{
	if (Q.front == Q.rear) return ERROR; //判断队空
	return Q.base[Q.front];
}
int main()
{
	return 0;
}