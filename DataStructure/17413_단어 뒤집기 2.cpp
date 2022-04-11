#include <iostream>
#include <string>
#include <stack>

using namespace std;

string solution(string str) {
    string answer = "";
    stack<char> st;
    int size = str.length(), flag = 0;

    for (int i = 0; i < size; ++i) {
        if (str[i] == '<') {
            while (!st.empty()) {
                answer += st.top();
                st.pop();
            }
            flag = 1; // 정방향
            answer += '<';
        }

        else if (flag == 1) {
            answer += str[i];

            // 정방향 해제 기호이면
            if (str[i] == '>')
                flag = 0;
            while (!st.empty()) {
                answer += st.top();
                st.pop();
            }
        }

        else {
            if (str[i] == ' ') {
                while (!st.empty()) {
                    answer += st.top();
                    st.pop();
                }

                answer += ' '; // 뛰어쓰기 삽입
            }
            else 
                st.push(str[i]);
        }
    }

    // 스택이 비어있지 않다면
    while (!st.empty()) {
        answer += st.top();
        st.pop();
    }

    return answer;
}

int main(void) {
    string str;

    getline(cin, str);

    string ret = solution(str);
    cout << ret;
    return 0;
}
