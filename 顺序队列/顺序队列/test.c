#define _CRT_SECURE_NO_WARNINGS 1

//˳��ѭ������
 
 
//ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>

//��
typedef int ElemType;
typedef int Status;

//����
#define OK 1
#define ERROR 0
#define MAXSIZE 100

//����һ��ѭ������
typedef struct
{
	ElemType* base;  //���ݿռ�
	int front;  //ͷָ��
	int rear;  //βָ��


}SqQueue;
int InitQueue(SqQueue* Q)
{
	Q->base = (SqQueue*)malloc(MAXSIZE * sizeof(ElemType)); //����ռ�
	if (!Q->base) return ERROR;
	Q->front = 0; //ͷָ��
	Q->rear = 0; //βָ��
	return OK;
}

//����ӳ�
int LengthSq(SqQueue Q)
{
	return ((Q.rear - Q.front + MAXSIZE) % MAXSIZE);
}

//���
int InQueue(SqQueue* Q,ElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front) return ERROR; //�ж϶���
	Q->base[Q->rear] = e;//��������
	Q->rear = (Q->rear + 1) % MAXSIZE; //βָ�����
	return OK;
}

//����
int OutSqueue(SqQueue* Q,ElemType* e)
{
	if (Q->front == Q->rear) return ERROR; //�ж϶ӿ�
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE; //ͷָ�����
	return OK;
	
}

//��ö�ͷԪ��
int GetHead(SqQueue Q)
{
	if (Q.front == Q.rear) return ERROR; //�ж϶ӿ�
	return Q.base[Q.front];
}
int main()
{
	return 0;
}