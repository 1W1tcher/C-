#include<iostream>
#include"turn.h"
using namespace std;

int main()
{
    unsigned long long NUM = 0;
    unsigned int n;
    cout << "����������" << endl;
    cin >> NUM;
    cout << "������Ҫת���ɵĽ��ƣ�" << endl;
    cin >> n;
    Turn_n(NUM, n);
    return 0;
}