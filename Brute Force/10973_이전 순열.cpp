#include <iostream>
#include <algorithm>  
#include <vector>     
using namespace std;
vector <int> per;

bool previous_permutation(vector<int>& per, int n) {
    int i = n - 1;
    while (i > 0 && per[i - 1] <= per[i]) i -= 1;
    if (i <= 0) return false;
    int j = n - 1;
    while (per[j] >= per[i - 1]) j -= 1;
    int temp = per[i - 1]; 
    per[i-1]=per[j];
    per[j] = temp;
    j = n - 1;
    while (i < j) {
        temp = per[i];
        per[i] = per[j];
        per[j] = temp;
        i += 1; 
        j-= 1;
    }
    return true;
}

int main()
{
    int n;

    cin >> n;
    per.resize(n); //n크기로 벡터 설정

    for (int i = 0; i < n; i++)
        cin >> per[i];

    //if (prev_permutation(per.begin(), per.end()))    // 헤더파일의 이전순열함수
    //{
    //    for (int i = 0; i < n; i++)
    //        cout << per[i] << " ";
    //}
    //else        //이전 순열 존재X일 경우 
    //    cout << "-1";

    if (previous_permutation(per,n)==true) {
        for (int i = 0; i < n; i++)
            cout << per[i] << " ";
    }
    else {
        cout << "-1";
    }
}