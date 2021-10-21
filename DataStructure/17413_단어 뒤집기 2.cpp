#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
    string s = "";
    stack<char> st;
    bool flag = false;

    getline(cin, s);
    s += '\n';
    
    for (int i = 0; i < s.size(); i++) {

        //������ �����ϴ� ��ȣ
        if (s[i] == '<') {
            while (!st.empty()) {
                printf("%c", st.top());
                st.pop();
            }
            printf("<");
            flag = true;
        }

        //������ ������ ��ȣ
        else if (s[i] == '>') {
            printf(">");
            flag = false;
        }

        //������
        else if (flag) 
            printf("%c", s[i]); 

        //���� �Ǵ� ������ 
        else if (s[i] == ' ' || s[i] == '\n') {
            while (!st.empty()) {
                printf("%c", st.top());
                st.pop();
            }
            printf(" ");
        }
        else 
            st.push(s[i]);
    }
    return 0;
}