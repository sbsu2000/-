#define _CRT_SECURE_NO_WARNINGS 1
#include "sq_list.h"

//��������

// ��ʼ��һ��������һ���յı�
Status initlist_sq(SqList* L)
{
	L->elem = (ElemType*)malloc(sizeof(ElemType) * MAXSIZ); //Ϊ˳���̬�����ڴ�
	if (!L->elem)    // �쳣�жϡ��������ڴ�ʧ��
		exit(OVERFLOW);
	L->Length = 0;  // �˱�Ϊ�ձ�û���κ�Ԫ��
	return OK;
}

//����һ����
void DestoryList(SqList* L)
{
	if (L->elem)
		free(L->elem);
}

//������Ա�
void ClearList(SqList* L)
{
	L->Length = 0;
}

//�����Ա�ĳ���
int GetLength(SqList L)
{
	return (L.Length);
}

//�ж������Ա��Ƿ�Ϊ��
 int IsEmpty(SqList L)
{
	if (L.Length == 0)return 1;
	else return 0;
}

//˳����ȡֵ
 Status GetElem(SqList L, int i, ElemType* e)
 {
	 if (i < 1 || i > L.Length)return ERROR; //�쳣�ж�
	 else
		 *e = L.elem[i-1];
	 return OK;
 }

 //˳���Ĳ��� ��˳����ң�
 int LocateElem(SqList L, ElemType e)
 {
	 for (int i = 0; i < L.Length; i++)
	 {
		 if (L.elem[i] == e)
			 return i + 1;
		 return 0;
	 }
 }

 //���뺯��  
  //�㷨˼�룺�жϲ���λ���Ƿ�Ϸ����쳣1.����λ��С��0���ߴ���L.length �쳣2.���Ѿ����ˣ�����ERROR��
 Status ListInsert_Sq(SqList* L, int i, ElemType e)
 {
	 if (i < 1 || i > L->Length) return ERROR; //�쳣1
	 if (L->Length > MAXSIZ) return ERROR; //�쳣2
	 for (int j = L->Length; j > i-1; j--)
	 {
		 L->elem[j] = L->elem[j-1];
	 }
	 L->elem[i - 1] = e;
	 L->Length++;
	 return OK;
 }

 //ɾ������
 Status ListDlete_Sq(SqList* L, int i, ElemType* e)
 {
	 if (i < 1 || i > L->Length) return ERROR;//�쳣�ж�
	 *e = L->elem[i - 1];
	 for (int j = i; j > L->Length; j--)
	 {
		 L->elem[i - 1] = L->elem[i];
	 }
	 L->Length--; // ���ȼ�һ
	 return OK;

 }