#include<iostream>
#include <windows.h>
#include<stdio.h>
using namespace std;
class Elevator//������
{
public:
	void graphical();//��ʾ����ͼ��
	void direction();//�ж������еķ���
	void select();//ѡ��¥��
	void moveUp();//����
	void moveDown();//����
	int getfloor=1, getmove=1;//Ŀ��¥����ƶ�����
	int current_floor=1;//��ǰ����¥��
private:
	void up();//���ж���
	void down();//���ж���
	int cnt=0;//���д���
};
void Elevator::graphical()//��ʾͼ�β˵�
{
	cnt++;
	if (cnt > 1)
	{
		Sleep(500);
	}
	system("cls");
	cout << "           ��ӭʹ�ñ�����~" << endl;
	cout << "           --" << "1������" << "--    " << endl;
	cout << "           --" << "2������" << "--    " << endl;
	cout << "           --" << "3������" << "--    " << endl;
}
void Elevator::direction()//ѡ�������з���
{
	while (1)
	{
		cout << "��ѡ����" << endl;
		cin >> getmove;
		if (getmove >= 1 && getmove <= 3)
		{
			break;
		}
		else
			cout << "������������������~" << endl;
	}
}
void Elevator::select()//ѡ��¥��
{
	/*cout << "�����뵱ǰ¥��" << endl;
	cin >> getfloor;
	if (getfloor > current_floor)
	{
		moveUp();
	}
	else if (getfloor < current_floor)
	{
		moveDown();
	}
	else if (getfloor == current_floor);*/
	cout << "������Ŀ��¥�㣺" << endl;
	cin >> getfloor;
}

void Elevator::moveUp()//����
{
	if (getfloor > 100 || getfloor < 1)
	{
		cout << "�������󣬱���¥ֻ��100��" << endl;
	}
	else if (getfloor > current_floor)
	{
		up();
	}
	else if (getfloor <= current_floor)
	{
		cout << "������������������" << endl;
	}
} 
void Elevator::moveDown()//����
{
	if (getfloor > 100 || getfloor < 1)
	{
		cout<< "�������󣬱���¥ֻ��100��" << endl;
	}
	else if (getfloor < current_floor)
	{
		down();
	}
	else if (getfloor >= current_floor)
	{
		cout << "������������������" << endl;
	}
}
void Elevator::up()//���ж���
{
	int i;
	system("cls");
	for (i = 0;current_floor < getfloor;current_floor++)
	{
		cout << "        --��" << current_floor <<"��--" << endl;
		cout << "           / \\   " << endl;
		cout << "          / | \\  " << endl;
		cout << "            |     " << endl;
		cout << "            |     " << endl;
		Sleep(2000);
		i++;
		/*if (i % 2 == 0);
		{
			system("cls");
		}*/
	}
	system("cls");
	cout << "�����ѵ����" << current_floor << "��" << endl;
}
void Elevator::down()//���ж���
{
	int i;
	system("cls");
	for (i = 0;current_floor > getfloor;current_floor--)
	{
		cout << "        --��" << current_floor << "��--" << endl;
		cout << "            |     " << endl;
		cout << "            |     " << endl;
		cout << "          \\ | /    " << endl;
		cout << "           \\ /    " << endl;
		Sleep(2000);
		i++;
		if (i % 2 == 0);
		{
			system("cls");
		}
	}
	system("cls");
	cout << "�����ѵ����" << current_floor << "��" << endl;
}