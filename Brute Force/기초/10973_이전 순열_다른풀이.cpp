#include <iostream>
#include <algorithm>  
#include <vector>     
using namespace std;
vector <int> per;

int main()
{
    int n;

    cin >> n;
    per.resize(n); //n크기로 벡터 설정

    for (int i = 0; i < n; i++)
        cin >> per[i];

    if (prev_permutation(per.begin(), per.end()))    // 헤더파일의 이전순열함수
    {
        for (int i = 0; i < n; i++)
            cout << per[i] << " ";
    }
    else        //이전 순열 존재X일 경우 
        cout << "-1";
}