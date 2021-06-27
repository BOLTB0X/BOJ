#include <iostream>
using namespace std;
long long s; //범위가 1 ≤ S ≤ 4,294,967,295이므로

int solution(long long s) {
    int num = 1; //1부터 더해서 n의 최댓값을 구해야 하므로 1로 초기화
    int n = 0; //정답
    long long sum = 0; //범위에 맞쳐 long long으로  
    while (1) {
        sum += num;
        n+=1;
        //합이 인풋 s를 넘기면 마지막에 더한 숫자를 빼서 수정하면 됨
        if (sum > s) {
            n-=1; //n의 최댓값을 -1 
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