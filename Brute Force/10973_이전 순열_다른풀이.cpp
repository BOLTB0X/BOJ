#include <iostream>
#include <algorithm>  
#include <vector>     
using namespace std;

void solution(void) {
    int n;
    cin >> n;
    //n크기로 벡터 설정
    vector <int> per(n, 0);

    for (int i = 0; i < n; i++)
        cin >> per[i];

    if (prev_permutation(per.begin(), per.end())) {
        for (int i = 0; i < n; i++)
            cout << per[i] << " ";
    }
    //이전 순열 존재X일 경우 
    else        
        cout << "-1\n";
    return;
}

int main() {
    //초기화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //해결
    solution();
    return 0;
}