#define _CRT_SECURE_NO_WARNINGS 1

// ͷ�ļ�����
#include <stdio.h>
#include <stdlib.h>

// ����
#define MAXSIZ 100

//�������״̬����
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBALE 0
#define OVERFLOW 0

// Status   ���غ���������
typedef int Status;
typedef char ElemType;

//���Ա�Ķ���
typedef struct  
{         
	ElemType * elem;
	int Length;
}SqList;


//�������� (������������)
Status initlist_sq(SqList*L); //��ʼ��һ���ձ�
void DestoryList(SqList* L); //����һ����  
void ClearList(SqList* L); // ���һ�����Ա�
int GetLength(SqList L); //�����Ա�ĳ���
int IsEmpty(SqList L);//�ж�һ�����Ա��Ƿ�Ϊ��
Status GetElem(SqList L, int i, ElemType* e); // ˳����ȡֵ
int LocateElem(SqList L, ElemType e);//����Ԫ��
Status ListInsert_Sq(SqList* L, int i, ElemType e);//���뺯��
Status ListDlete_Sq(SqList* L, int i, ElemType e);//ɾ������