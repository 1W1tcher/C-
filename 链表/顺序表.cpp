#include<iostream>
#include"����.h"
using namespace std;

int main()
{
	double a[8] = { 15,354,64,21,0,496,54,31 };
	SeqList<double> list(a, 8);
	list.PrintList();

	list.Insert(5, 6.0);
	list.PrintList();

	int x = list.Delete(1);
	cout << "ɾ��Ԫ�أ�" << x << endl;
	list.PrintList();

	int p = list.Locate(0);
	cout << "Ԫ��0��λ�ã�" << p << endl;

	return 0;
}
