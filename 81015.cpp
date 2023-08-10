#include<iostream>


using namespace std;

typedef struct TreeNode {
	char data;//������
	TreeNode* Lchild;//����
	TreeNode* Rchild;//�Һ���
}*Tree, TreeNode;

//ǰ�򴴽�������
void CreateTree(Tree& T) {
	char x;
	cin >> x;
	if (x == '*') {
		T = NULL; return;
	}
	else {
		T = new TreeNode;
		T->data = x;
		CreateTree(T->Lchild);
		CreateTree(T->Rchild);
	}
}
//�������
void Pre_Traversal(const Tree& T) {
	if (T) {
		cout << T->data << " ";
		Pre_Traversal(T->Lchild);
		Pre_Traversal(T->Rchild);
	}
}
//�������
void Ino_Traversal(const Tree& T) {
	if (T) {
		Ino_Traversal(T->Lchild);
		cout << T->data << " ";
		Ino_Traversal(T->Rchild);
	}
}
//�������
void Pos_Traversal(const Tree& T) {
	if (T) {
		Pos_Traversal(T->Lchild);
		Pos_Traversal(T->Rchild);
		cout << T->data << " ";

	}
}
//�������Ƿ�Ϊ��
bool TreeEmpty(const Tree& T) {
	if (T == NULL)
	{
		cout << "�ö�����Ϊ�գ�" << endl;
		return true;
	}
	else
	{
		cout << "�ö�����Ϊ��Ϊ�գ�" << endl;
		return false;
	}
}
//��������Ľڵ���
int TreeNodeCount(const Tree& T) {
	if (T == NULL)
		return 0;
	else if (T->Lchild == NULL && T->Rchild == NULL)
		return 1;
	else
		return TreeNodeCount(T->Lchild) + TreeNodeCount(T->Rchild) + 1;

}
//������������
int TreeDepth(const Tree& T) {
	if (T == NULL) return 0;
	else {
		int i = TreeDepth(T->Lchild);
		int j = TreeDepth(T->Rchild);
		return i > j ? i + 1 : j + 1;
	}

}

int main() {
	Tree T;
	cout << "�밴���������˳�򴴽�������������ڵ�����ӻ��Һ��Ӳ�������ʹ��*���棡�磺��ABD**E**CF**G**��" << endl;
	CreateTree(T);
	TreeEmpty(T);
	cout << "��������Ľ��Ϊ��";
	Pre_Traversal(T);
	cout << endl;
	cout << "��������Ľ��Ϊ��";
	Ino_Traversal(T);
	cout << endl;
	cout << "��������Ľ��Ϊ��";
	Pos_Traversal(T);
	cout << endl;
	cout << "���������Ϊ��" << TreeDepth(T) << endl;
	cout << "�����Ľڵ���Ϊ��" << TreeNodeCount(T) << endl;
	system("pause");
}
