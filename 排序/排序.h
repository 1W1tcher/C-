#include<iostream>
using namespace std;
struct Node//���
{
	Node* next=NULL;
	Node* front = NULL;
	int data=0;
};
void swap(Node* a, Node* b)//��������
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}
void createLinkList(int a[],int n,Node* front)//��������
{
	Node* r = front;
	for (int i = 0;i < n;i++)
	{
		Node* p = new Node;
		p->data = a[i];
		p->front = r;
		r->next = p;
		r = p;
	}
}
void insertSort(Node* front)//��������
{
	Node* p = new Node;//��������ָ��
	if(front->next!=NULL)
		front->data = front->next->data;//ͷ��㴢�������е�һ��Ԫ��
	if(front->next->next!=NULL)
		p = front->next->next;//����ָ��ָ������ڶ���Ԫ��
	while (p != NULL)//������������
	{
		Node* r = new Node;//�����ڲ�����ָ��
		r = p;//ָ����ָ��p
		if (r->data < r->front->data)//�������Ԫ��С����ǰһ��Ԫ�أ���ʼѰ�Ҳ���λ��
		{
			front->data = r->data;//ͷ��㴢������Ԫ�ص�ֵ
			r->data = r->front->data;//�����������ڶ���Ԫ�غ���
			Node* t = new Node;//��������ָ��t
			t=r->front->front;//tָ����������Ԫ��
			while (t != front&& front->data<t->data)//r��ǰ������������,�������Ԫ���Խ�С����һֱ��ǰ������ֱ���ҵ�����λ��
			{
				t->next->data = t->data;//����Ԫ�غ���
				t = t->front;//��ǰ����
			}
			t->next->data = front->data;//���뵽����λ��
		}
		p = p->next;
		
	}
}
void bubbleSort(Node* front,int n)//ð������
{
	int i = n;
	while (i)
	{
		Node* p = new Node;
		p = front->next;//��������ָ��
		int bound = i;
		i = 0;//��������ѭ������
		for (int j = 1;j < bound;j++)
		{
			
			if (p!= NULL && p->next != NULL)
			{
				if (p->data > p->next->data)
				{
					int temp = p->data;
					p->data = p->next->data;
					p->next->data = temp;
					i = j;//���½����ļ�¼��λ��
				}
				p = p->next;
			}
		}
		
	}
}
Node* partition(Node* head, Node* tail)//����
{
	Node* q = head;
	Node* p = head;
	int pivot = head->data;
	while (q != tail)
	{
		if (q->data < pivot)
		{
			p = p->next;
			swap(p, q);
		}
		q = q->next;
	}
	swap(p, head);
	return p;
}
Node* quickSort(Node* head, Node*tail)//��������
{
	if (head == tail)	return head;
	Node* mid = partition(head, tail);//�ҵ��м�ֵ
	head = quickSort(head, mid);//���׵��м��������
	quickSort(mid->next, tail);//�м䵽��β��������
	return head;
}
Node* quickSortAll(Node* head)//��������
{
	if (!head || !head->next) return head;
	return quickSort(head, nullptr);
}

Node* selectSort(Node* front)//ѡ������
{
	Node* p = front->next;//����������
	Node* q;
	Node* min;
	while (p)
	{
		q = p->next;//δ��������
		min = p;
		while (q)//�ҵ�δ�������������Сֵ������������������
		{
			if (q->data < min->data)
				min = q;
			q = q->next;
		}
		if (min != p)
		{
			swap(min, p);//��Сֵ��������������
		}
		p = p->next;
	}
	return front;
}


void printList(Node* front)//��ӡ����
{
	Node* p = new Node;
	p = front->next;
	while (p != NULL)
	{
		cout << p->data<<" ";
		p = p->next;
	}
}
