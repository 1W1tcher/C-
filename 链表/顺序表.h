#pragma once
#include<iostream>
using namespace std;
const int MAXSIZE = 1000;
template<class T>
class SeqList
{
public:
	SeqList()
	{
		s_length = 0;
	}

	SeqList(const T a[],int n);

	int GetLength()
	{
		return s_length;
	}

	void PrintList();

	void Insert(int i, T x);

	T Delete(int i);

	T Get(int i);

	int Locate(T x);

private:
	T s_data[MAXSIZE];
	int s_length;
};

template<class T>
SeqList<T>::SeqList(const T a[], int n)
{
	if (n > MAXSIZE)
	{
		throw"���鳤�ȳ�������";
	}
	else
	{
		for (int i = 0;i < n;i++)
		{
			s_data[i] = a[i];
			s_length = n;
		}
	}
}

template<class T>
void SeqList<T>::PrintList()
{
	cout << "��������α������Ա��еĸ�������Ԫ��" << endl;
	for (int i = 0;i < s_length;i++)
	{
		cout << s_data[i] << " ";
	}
	cout << endl;
}

template<class T>
void SeqList<T>::Insert(int i, T x)
{
	if (s_length >= MAXSIZE)
	{
		throw"�����쳣";
	}
	if (i<1 || i>s_length)
	{
		throw"����λ���쳣";
	}
	for (int j = s_length;j >=i;j--)
	{
		s_data[j] = s_data[j - 1];
	}
	s_length++;
	s_data[i - 1] = x;
}

template<class T>
T SeqList<T>::Delete(int i)
{
	if (i < 1 || i >= s_length)
	{
		throw"ɾ��λ���쳣";
	}
	if (0==s_length)
	{
		throw"�����쳣";
	}
	T x = s_data[i-1];
	for (int j = i;j < s_length;j++)
	{
		s_data[j-1] = s_data[j];
	}
	s_length--;
	return x;
}

template<class T>
T SeqList<T>::Get(int i)
{
	if (i<1 || i>s_length)
	{
		throw"����λ�÷Ƿ�";
	}
	return s_data[i - 1];
}

template<class T>
int SeqList<T>::Locate(const T x)
{
	for (int i = 0;i < s_length;i++)
	{
		if (x==s_data[i])
		{
			return i + 1;	
		}
	}
}