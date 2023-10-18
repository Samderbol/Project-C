#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define InitSize 10//Ĭ�ϵ���󳤶�
using namespace std;
typedef struct {
	int* data;     //ָʾ��̬���������ָ��
	int MaxSize;   //˳�����������
	int length;    //˳���ĵ�ǰ����
} SeqList;

void InitList(SeqList& L) {
	//�� malloc��������һƬ�����Ĵ洢�ռ�
	L.data = (int*)malloc(InitSize * sizeof(int));
	L.length = 0;
	L.MaxSize = InitSize;
}

bool ListInsert(SeqList& L, int i, int e) {
	if (i < 1 || i > L.MaxSize) {
		cout << "out of index before insert (length is: " << L.MaxSize << ")";
		return false;
	}
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	if (i < 1 || i > L.MaxSize) {
		cout << "out of index after insert (length is: " << L.MaxSize << ")";
		return false;
	}
	L.length++;
	if (L.length >= L.MaxSize) {
		cout << "out of index after insert (length is: " << L.MaxSize << ")";
		return false;
	}
	cout << L.length << endl;
	return true;
}

bool ListDelete(SeqList& L, int i, int& e) {
	if (i < 1 || i>L.length)
		return false;
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++)
		L.data[j - 1] = L.data[j];
	L.length--;
	return true;
}

void IncreaseSize(SeqList& L, int len) {
	int* p = L.data;
	L.data = (int*)malloc((L.MaxSize + len) * sizeof(int));
	if (L.data == NULL) {
		// ���Դ����ڴ����ʧ�ܵ����
		// ����ѡ�����������Ϣ���ȡ�����ʵ��Ĵ���ʽ
		return;
	}
	if (len <= 0) {
		// ���� len Ϊ�����������
		// ����ѡ�����������Ϣ���ȡ�����ʵ��Ĵ���ʽ
		return;
	}
	for (int i = 0; i < L.length; i++) {
		L.data[i] = p[i];  //�����ݸ��Ƶ�������
	}
	L.MaxSize = L.MaxSize + len; //˳�����󳤶����� len
	cout << L.MaxSize << endl;
	free(p);
}
int GetElem(SeqList L, int i) {
	return L.data[i - 1];
}
int LocateElem(SeqList L, int e) {
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return 0;
}

int main() {
	//����һ��˳���
	SeqList L;
	//��ʼ��˳���
	InitList(L);
	//...��˳����������뼸��Ԫ��...
	IncreaseSize(L, 5);
	bool insertResult = ListInsert(L, 5, 3);
	int e = -1;


	if (insertResult) {
		cout << "Insertion successful." << endl;
	}
	else {
		cout << "Insertion failed." << endl;
	}

	if (ListDelete(L, 1, e))
		printf("��ɾ��������Ԫ�أ�ɾ��Ԫ��ֵΪ=%d\n", e);
	else
		printf("λ�򲻺Ϸ�,ɾ��ʧЧ\n");

	return 0;
}