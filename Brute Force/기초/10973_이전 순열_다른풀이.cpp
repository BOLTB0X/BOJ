#include <iostream>
#include <algorithm>  
#include <vector>     
using namespace std;
vector <int> per;

int main()
{
    int n;

    cin >> n;
    per.resize(n); //nũ��� ���� ����

    for (int i = 0; i < n; i++)
        cin >> per[i];

    if (prev_permutation(per.begin(), per.end()))    // ��������� ���������Լ�
    {
        for (int i = 0; i < n; i++)
            cout << per[i] << " ";
    }
    else        //���� ���� ����X�� ��� 
        cout << "-1";
}