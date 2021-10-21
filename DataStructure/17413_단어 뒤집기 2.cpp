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

        //정방향 시작하는 기호
        if (s[i] == '<') {
            while (!st.empty()) {
                printf("%c", st.top());
                st.pop();
            }
            printf("<");
            flag = true;
        }

        //정방향 끝나는 기호
        else if (s[i] == '>') {
            printf(">");
            flag = false;
        }

        //정방향
        else if (flag) 
            printf("%c", s[i]); 

        //여백 또는 끝나는 
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