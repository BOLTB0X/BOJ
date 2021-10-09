#include <iostream>
#include <algorithm>  
#include <vector>     
using namespace std;

void solution(void) {
    int n;
    cin >> n;
    //nũ��� ���� ����
    vector <int> per(n, 0);

    for (int i = 0; i < n; i++)
        cin >> per[i];

    if (prev_permutation(per.begin(), per.end())) {
        for (int i = 0; i < n; i++)
            cout << per[i] << " ";
    }
    //���� ���� ����X�� ��� 
    else        
        cout << "-1\n";
    return;
}

int main() {
    //�ʱ�ȭ
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //�ذ�
    solution();
    return 0;
}