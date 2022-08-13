#include<iostream>
#include"HuffmanTree.h"
int main()
{
	HuffmanTree h;
	cout << "������������������������" << endl;
	char s[] = "I love data Structure,I love Computer.I will try my best to study data Structure.";
	cout << "������ַ���Ϊ��" << s << endl;
	h.CreateHTree(s);
	int n = h.node;
	cout <<"����"<< n <<"���ַ�Ԫ��"<< endl;
	h.CreateCodeTable(n);
	cout << "�����Ϊ��" << endl;
	for (int i = 0;i < n;i++)
	{
		cout << h.HcodeTable[i].data << " " <<h.HcodeTable[i].code<< endl;
	}

	string d=h.Encode("I love data Structure,I love Computer.I will try my best to study data Structure.");
	cout << "�������ַ���Ϊ��" << d << endl;
	cout << "ѹ���ȣ�" << h.Compress(s, d)<< endl;
	return 0;
}