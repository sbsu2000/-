#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkList.h"

//��������
//��ʼ������
Status InitList(LinkList L)
{
	L = (LinkList)malloc(sizeof(Lnode));//����ͷ��㣬����ʹͷָ��ָ��ͷ���
	L->next = NULL; //ʹͷ���ָ��Ϊ�գ����γ��˿�����
	return OK;
}

//�ж��Ƿ�Ϊ�ձ�
int IsEmpty(LinkList L)
{
	if (L->next) // ���Ϊ�ձ�
		return 0;
	else
		return 1;
}

//����һ������
Status DestoryList(LinkList L)
{
	//��ͷָ�뿪ʼ�����ͷ����еĽ��(����ͷָ���ͷ��㣬���ڴ���û�����������)
	Lnode* P;    //����һ�����ָ��
	while (L)
	{
		P = L; //���ָ��ָ��Ҫ�ͷŵĽ��,��ͷ�ڵ㿪ʼ
		L = L->next; //ͷָ��ָ�� Ҫ�ͷŵĽ�� ����һ�� ���
		free(P); // �ͷ�Pָ��Ľ��
	}
	P = L; //�ÿ�P����ֹ����Ұָ��
	return OK; 
}

//�������ͷָ���ͷ���û�б��ͷţ�
Status ClearList(LinkList L)
{
	Lnode* p, *q;
	p = L->next; //����Ԫ��㿪ʼ
	while (p)
	{
		q = p->next; //q�����ɾ��������һ������ַ
		free(p); //�ͷŽ��
		p = q; //���һ��ѭ��ʱp��q������Ϊ��NILL
	}
	L->next = NULL;//ͷ����ָ�����ÿ�
	return OK;
}

//������ĳ���
int LengthList_L(LinkList L)
{
	int count = 0; //������
	Lnode* p;
	p = L->next; // �ý��ָ��ָ����Ԫ���
	while (p)
	{
		count++;
		p = p->next; //�ý��ָ��ָ����һ�����
	}
	return 0;
}

//ȡֵ
Status GetElem(LinkList L, int i, ElemType* e)
{
	//��ʼ��
	int count = 1;
	Lnode* p;
	p = L->next; //ָ����Ԫ���
	while (p && count < i)  //����ѭ���������������1.�ҵ�Ԫ�� 2.����Ԫ�ش���������
	{
		p = p->next;  //ָ����һ���
		count++;
	}
	if (!p || i < count)  //���pΪNULL˵���Ѿ�����������û�д�Ԫ��;����Ԫ�ز���С��1
		return ERROR;
	*e = p->data;
	return OK;

}

//��ֵ���ң����ص�ַ��
Lnode* LocateElemA(LinkList L, ElemType e)
{
	//��ʼ��
	Lnode* p;
	p = L->next;

	//ѭ��������1.p == NULL������������� 2.�Ѿ��ҵ���ֵ
	while (p && p->data == e)
	{
		p = p->next; //ָ�����
	}
		return p;  

}

//��ֵ���ң�����λ����ţ�
int LocateElemB(LinkList L, ElemType e)
{
	//��ʼ��
	Lnode* p;
	p = L->next;
	int count = 1;  //������

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

//��i��Ԫ��֮ǰ��������Ԫ��e
Status ListInsert(LinkList L, int i, ElemType e)
{
	//�ҵ�i-1�����
	  //��ʼ��
	Lnode* p;
	p = L->next;
	int count = 1;
	while (p && count < i-1) // ����ѭ����1.pΪNULL 2.�Ѿ��ҵ�i-1��Ԫ��
	{
		p = p->next;
		count++;
	}
	if (!p && i < count)
		return ERROR;
	//����һ�����(���ָ��)
	Lnode* s = (LinkList)malloc(sizeof(Lnode));
	s->data = e;  // ��������Ԫ��
	//������
	s->next = p->next;
	p->next = s;
	return OK;
}

//ɾ����i������
Status DeleList(LinkList L, int i, ElemType* e)
{
	//��ʼ��
	Lnode* p,*q;
	p = L->next;
	int count = 1;
	//�鵽i-1���
	while (p && count < i-1)
	{
		p = p->next; //ָ����һ�����
		count++;
	}
	if (!p && i < count)
		return ERROR;
	//��ɾ������������ȥ��
	q = p->next;  //��n�����
	p = q->next; //���� n+1 �����ĵ�ַ���� n-1����ָ����
	//�ͷ�ɾ�����Ŀռ�
	free(q);
	return OK;
}

//��������ͷ�巨:��λ����룬�����һ��Ԫ�ؿ�ʼ��ǰ���룩
void CreatList_H(LinkList L, int n)
{
	//����һ������ͷ���Ŀձ�
	L = (Lnode*)malloc(sizeof(Lnode));
	L->next = NULL;
	//ͷ�巨������
	for (int i = n; i > 0; --i)
	{
		//�������
		Lnode* p;
		p = (Lnode*)malloc(sizeof(Lnode));
		//��������
		scanf("%d", &p->data);
		//������
		p->next = L->next;
		L->next = p;
	}
}
//��������β�巨��
void CreatList_R(LinkList L, int n)
{
	//��ʼ��
	Lnode* p;
	Lnode* r; //βָ��
	//����һ����ͷ���Ŀձ�
	L = (Lnode*)malloc(sizeof(Lnode));
	L->next = NULL;
	r = L; //βָ��ָ��ͷ���
	//ͷ�巨������
	for (int i = 0; i < n; i++)
	{
		//���ɽ��
		 p = (Lnode*)mallco(sizeof(Lnode));
		//��������
		scanf("%d", &p->data);
		//������
		p->next = NULL; //��������β���
		r->next = p;  //���������ǰһ��������
		r = p;  //βָ���ƶ����µ�α���
	}
}