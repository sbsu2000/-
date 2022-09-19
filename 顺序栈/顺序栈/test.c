#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//ʵ��һ��˳��ջ


//����
#define  MAXSIZ 10  //ջ��С
#define ERROR -1
#define OK 1
#define FALSE 0

//Status ����״̬
typedef int ElemType; //�洢��������
typedef int Status;  //��������

//����˳��ջ
typedef struct SqStack
{
	ElemType* top;  //ͷָ��
	ElemType* base;//����ָ��
	int StackSize; //ջ��С
}SqStack;

//��ʼ��
Status InitStack(SqStack* S)
{
	//����ռ�
	ElemType* p = (ElemType*)malloc(MAXSIZ * sizeof(ElemType));
	if (!p)
		return ERROR;
	S->base = p;
	S->top = S->base;
	S->StackSize = MAXSIZ;
	return OK;
	
}

//�ж��Ƿ�Ϊ��
Status IsEmpty(SqStack* S)  //Ϊ�շ���1����Ϊ�շ��� 0
{
	if (S->top == S->base) return OK;
	else return FALSE;
}

//���˳��ջ
Status ClearStack(SqStack* S)
{
	if (S->base)  //������ջ����
	{
		S->top = S->base;
		return OK;
	}
	else
		FALSE;
}

//��ջ����
Status Push(SqStack* S,ElemType e)
{
	//�ж�ջ�Ƿ������Ƿ��������磩
	if (S->base && S->top - S->base == MAXSIZ)
	{
		*S->top++ = e; //д�����ݣ�ָ������
		return OK;
	}
	else
		ERROR; 
}
//����ջ
Status DestoryStack(SqStack* S)
{
	if (S->base)
	{
		free(S->base);
		S->base = S->top = NULL; //ָ���ÿ�
	}
	return OK;
}

//��ջ
Status Pop(SqStack* S,ElemType* e)
{
	//�ж��Ƿ�ջ�գ��ж��Ƿ���������
	if (S->top == S->base) return ERROR;
	//��ջ
	*e = *--S->top;
	return OK;
}
int main()
{
	SqStack S;
	InitStack(&S);
	return 0;
}