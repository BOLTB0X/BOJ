#include <iostream>
using namespace std;
long long s; //������ 1 �� S �� 4,294,967,295�̹Ƿ�

int solution(long long s) {
    int num = 1; //1���� ���ؼ� n�� �ִ��� ���ؾ� �ϹǷ� 1�� �ʱ�ȭ
    int n = 0; //����
    long long sum = 0; //������ ���� long long����  
    while (1) {
        sum += num;
        n+=1;
        //���� ��ǲ s�� �ѱ�� �������� ���� ���ڸ� ���� �����ϸ� ��
        if (sum > s) {
            n-=1; //n�� �ִ��� -1 
            break;
        }
        num++;
    }
    return n;
}
int main(void) {
    cin >> s;
    cout << solution(s) << '\n';
    return 0;
}