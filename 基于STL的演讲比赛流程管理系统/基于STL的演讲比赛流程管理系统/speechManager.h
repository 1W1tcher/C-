#pragma once
#include<iostream>
#include"speaker.h"
#include<vector>
#include<map>
using namespace std;
class SpeechManager
{
public:
	SpeechManager();//���캯��
	void showMenu();//�˵�����
	void exitSystem();//�˳�ϵͳ
	~SpeechManager();//��������
	void initSpeech();//��ʼ�����������������
	vector<int> v1;//��һ�ֱ���ѡ�ֱ������
	vector<int> v2;//��һ�ֽ���ѡ�ֱ������
	vector<int> vVictory;//ʤ����ǰ������ѡ�ֱ������
	map<int,Speaker> m_Speaker;//�����������
	int m_Index;//��������

};