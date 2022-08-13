#include<iostream>
using namespace std;
#define MAXVEX 100

//�߱�
struct EdgeNode
{
	int adjvex;
	EdgeNode* next;
};

//����
struct VexNode
{
	int data;
	EdgeNode* first;
};

//�ڽӱ�
struct GraAdjList
{
	VexNode AdjList[MAXVEX];
	int vexnum;
	int edgenum;
};
//�����ڽӱ�
void Create(GraAdjList& g)
{
	int i, j, k;
	EdgeNode *e = NULL;
	EdgeNode *q = NULL;
	cout << "�����붥�����ͱ�����" << endl;
	cin >> g.vexnum >> g.edgenum;
	cout << "�����붥����Ϣ��" << endl;
	for (k = 0;k < g.vexnum;k++)
	{
		cin >> g.AdjList[k].data;
		g.AdjList[k].first = NULL;
	}
	//�����߱�
	for (k = 0;k < g.edgenum;k++)
	{
		cout << "�������(vi,vj)���±�vi,vj" << endl;
		cin >> i >> j;
		e = new EdgeNode;
		e->adjvex = j;
		e->next = g.AdjList[i].first;
		g.AdjList[i].first = e;
		//����ͼ
		q = new EdgeNode;
		q->adjvex = i;
		q->next = g.AdjList[j].first;
		g.AdjList[j].first = q;
	}
}
//����ڽӱ�
void Print(GraAdjList& g)
{
	cout << endl << "�ڽӱ�" << endl;
	EdgeNode* p;
	for (int i = 0;i < g.vexnum;i++)
	{
		cout << "����" << g.AdjList[i].data << ":";
		for (p = g.AdjList[i].first;p;p = p->next)
			cout << p->adjvex << " ";
		cout << endl;
	}
}
//ȫ�ֱ���
int Visited[MAXVEX];
//������ȵı����ķǵݹ��㷨
void DFS1(GraAdjList& g, int v)
{
	int s[MAXVEX];//ջ
	int top = -1;//ջ��λ��
	int j;
	EdgeNode* p;
	cout << g.AdjList[v].data << " ";//�����ǰ�������Ϣ
	Visited[v] = 1;//��ʾ�ѷ���
	s[++top] = v;//��ջ
	while (top != -1)//ջ��Ϊ�վ�һֱѭ��
	{
		v = s[top];//ȡջ��Ԫ��
		p = g.AdjList[v].first;//����������һ����
		while (p)//p��Ϊ�վ�һֱѭ��
		{
			j = p->adjvex;//��һ�������Ϣ
			if (Visited[j] == 0)//û���ʹ�
			{
				cout << g.AdjList[j].data << " ";
				Visited[j] = 1;//��ʾ�ѷ���
				s[++top] = j;//��ջ
				p = g.AdjList[j].first;//����������һ����
			}
			else
				p = p->next;//���ʹ��͵���һ����
		}
		top--;//��ջ
	}
}
int main()
{
	//����������9 10 0 1 2 3 4 5 6 7 8 0 1 0 2 1 3 1 4 2 5 2 6 5 6 3 7 4 7 7 8
	GraAdjList G;
	Create(G);
	Print(G);
	int i;
	//��ʼ��
	for (i = 0;i < G.vexnum;i++)
		Visited[i] = 0;
	cout << "������ȱ���(�ǵݹ�)��" << endl;
	DFS1(G,0);
	cout << endl;
	return 0;
}