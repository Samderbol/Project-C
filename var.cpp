#include <iostream>

using namespace std;

int main()
{
	int  var1;
	char var2[10];
	int* ip;    /* һ�����͵�ָ�� */
	double* dp;    /* һ�� double �͵�ָ�� */
	float* fp;    /* һ�������͵�ָ�� */
	char* ch;    /* һ���ַ��͵�ָ�� */
	ip = &var1; /* var1�ĵ�ַ���ݸ�ip */

	cout << "var1 id�� ";
	cout << &var1 << endl;

	cout << "var2 id�� ";
	cout << &var2 << endl;
	cout << "var3 id�� ";
	cout << &ip << endl;
	cout << "var4 id�� ";
	cout << ip << endl;
	cout << "var5 id�� ";
	cout << *ip << endl;

	return 0;
}