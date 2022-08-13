#pragma once
#include <iostream>
#include<string>
using namespace std;

struct Node
{
	int data;
	Node* next;
	int cnt=1;
};

struct HNode
{
	int weight;
	char data;
	int lchild, rchild, parent;
};

struct HCode
{
	char data;
	char code[100];
};

void Reverse(char ch[])
{
	
	int n = strlen(ch);
	char temp;
	for(int i=0;i<n;i++)
	{
		temp = ch[i];
		ch[i] = ch[n - 1 - i];
		ch[n - 1 - i] = temp;
	}
}

void SelectMin(HNode* hTree, int n, int& i1, int& i2)
{
	int i;
	//��һ���Ƚϵ���ʼֵ
	for (i = 0;i < n;i++)//��i1
	{
		if (hTree[i].parent == -1)
		{
			i1 = i;
			break;
		}
	}
	for (i++;i < n;i++)//��i2
	{
		if (hTree[i].parent == -1)
		{
			i2 = i;
			break;
		}
	}
	if (hTree[i1].weight > hTree[i2].weight)
	{
		int j = i2;
		i2 = i1;
		i1 = j;
	}
	//����С������
	for (i++;i < n;i++)
	{
		if (hTree[i].parent == -1)
		{
			if (hTree[i].weight < hTree[i1].weight)
			{
				i2 = i1;
				i1 = i;
			}
			else if (hTree[i].weight < hTree[i2].weight)
			{
				i2 = i;
			}
		}
	}
}

class HuffmanTree
{
	
public:
	HNode* huffTree;//huffman��
	HCode* HcodeTable;//huffman�����
	int node;
	string code;
	void CreateHTree(char s[]);//����huffman��
	void CreateCodeTable(int n);//���������
	string Encode(string s);//����
	string Decode(string d);//����
	double Compress(char s[],string d);//ͳ��ѹ����
	~HuffmanTree()
	{
		delete huffTree;
	}
};


void HuffmanTree::CreateHTree(char s[])
{
	Node* front = new Node;
	Node* r = front;
	r->next = NULL;
	int n = 0;
	for(int i=0;s[i]!='\0';++i)
	{
		int count = 0;
		Node* p = new Node;
		p = front->next;
		while (p!= NULL)
		{
			if (s[i] == p->data)
			{
				p->cnt++;
				count++;
			}
			p = p->next;
		}
		if (count == 0)
		{
			Node *p1 = new Node;
			p1->data = s[i];
			r->next = p1;
			r = p1;
			r->next = NULL;
			n++;
		}
	}

	//����Ȩ������a[1->n]��ʼ��Huffman��
	huffTree = new HNode[2 * n - 1];
	Node* p = front->next;
	int i = 0;
	while(p)
	{
		huffTree[i].weight =p->cnt;
		huffTree[i].data =p->data;
		huffTree[i].lchild = -1;
		huffTree[i].rchild = -1;
		huffTree[i].parent = -1;
		p = p->next;
		i++;
	}
	int li=0, ri=0;
	for (int i = n;i < 2 * n - 1;i++)
	{
		//��0~i-1��ѡ������ȫֵ��С�Ľ��
		SelectMin(huffTree, i, li, ri);
		huffTree[li].parent = huffTree[ri].parent = i;
		huffTree[i].weight = huffTree[li].weight + huffTree[ri].weight;
		huffTree[i].lchild = li;
		huffTree[i].rchild = ri;
		huffTree[i].parent = -1;
	}
	node=n;
}

void HuffmanTree::CreateCodeTable(int n)
{
	HcodeTable = new HCode[n];//���ɱ����
	for (int i = 0;i < n;i++)
	{
		HcodeTable[i].data =huffTree[i].data;
		int ic = i;
		int ip = huffTree[i].parent;
		int k = 0;
		while (ip != -1)
		{
			if (ic ==huffTree[ip].lchild)
			{
				HcodeTable[i].code[k] = '0';//���ӱ�0
			}
			else
			{
				HcodeTable[i].code[k] = '1';//�Һ��ӱ�1
			}
			k++;
			ic = ip;
			ip = huffTree[ic].parent;
		}
		HcodeTable[i].code[k] = '\0';
		//�������ַ�����
		Reverse(HcodeTable[i].code);
		code += HcodeTable[i].code;
	}
}

string HuffmanTree :: Encode(string s)
{
	string d;
	for (int i = 0;s[i] != '\0';i++)
	{
		for (int j = 0;j<node;j++)
		{
			if (huffTree[j].data == s[i])
			{
				d += HcodeTable[j].code;
			}
		}
	}
	return d;
}

string HuffmanTree::Decode(string s)
{
	//sΪ���봮��dΪ�������ַ���
	string d="";
	int i = 0;
	while(s[i]!='\0')
	{
		int k = 2 *node - 2;//���ݽ����huffTree�е��±�
		while (huffTree[k].lchild != -1)
		{
			if (s[i] == '0')
			{
				k = huffTree[k].lchild;
			}
			else
			{
				k = huffTree[k].rchild;
			}
			i++;
		}
		d += HcodeTable[k].data;
	}
	return d;
}

double HuffmanTree::Compress(char s[], string d)
{
	double s1 = strlen(s);
	double d1 = d.size();
	return s1/d1;
}