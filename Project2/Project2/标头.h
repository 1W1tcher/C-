#pragma once
#include<iostream>
#include"����.h"
struct term
{
	float coef;//ϵ��
	int expn;//ָ��
	term* next;
};
class Polynomial
{
public:
	Polynomial()
	{
		front = new term;
		front->next = NULL;
	}
	Polynomial( int n,const double a[] );
	
private:
	term *front;
};


Polynomial::Polynomial(int n,const double a[])
{
	front = new term;

}