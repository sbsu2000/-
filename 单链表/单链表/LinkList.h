#define _CRT_SECURE_NO_WARNINGS 1

//ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>

//��
typedef int ElemType;
typedef int Status;

//����
#define OK 1
#define ERROR 0


//����һ�����
typedef struct Lnode
{
	ElemType data;  // ������
	struct Lnode* next;//ָ����
}Lnode,*LinkList;  // �ṹ�����

LinkList L; // ����ͷָ�룬ͷָ�����ֽ�L������������Ҳ����L��ֻ��ͨ����ָ������ҵ���������

//��������
Status InitList(LinkList L); //�����ʼ��������һ��������
int IsEmpty(LinkList L); //�ж�L�����Ƿ�Ϊ�ձ�
Status DestoryList(LinkList L); //����һ������
Status ClearList(LinkList L); //���һ������
int LengthList_L(LinkList L); //������ĳ���
Status GetElem(LinkList L, int i, ElemType* e);//ȡֵ
Lnode* LocateElemA(LinkList L, ElemType e);//��ֵ���ң����ص�ַ��
int LocateElemB(LinkList L, ElemType e);//��ֵ���ң�����λ����ţ�
Status ListInsert(LinkList L, int i, ElemType e);//��i��Ԫ��֮ǰ��������Ԫ��
Status DeleList(LinkList L, int i, ElemType* e); // ɾ����i������Ԫ��
void CreatList_H(LinkList L, int n); //ͷ�巨��������
void CreatList_R(LinkList L, int n); //β�巨��������
