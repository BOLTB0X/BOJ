#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//������ ���� Ŭ���� ����
class Student {
public:
    string name;
    int kor;
    int eng;
    int m;
    Student(string name, int kor, int eng, int m) {
        this->name = name;
        this->kor = kor;
        this->eng = eng;
        this->m = m;
    }
    bool operator <(Student& other) {
        if (this->kor == other.kor && this->eng == other.eng && this->m == other.m) {
            return this->name < other.name;
        }
        if (this->kor == other.kor && this->eng == other.eng) {
            return this->m > other.m;
        }
        if (this->kor == other.kor) {
            return this->eng < other.eng;
        }
        return this->kor > other.kor;
    }
};


void solution(void) {
    int n;
    vector<Student> inf;

    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        int kor;
        int eng;
        int m;
        cin >> name >> kor >> eng >> m;
        inf.push_back(Student(name, kor, eng, m));
    }

    //����
    sort(inf.begin(), inf.end());

    //���
    for (int i = 0; i < n; i++) 
        cout << inf[i].name << '\n';
    
    return;
}

int main(void) {
    //�ʱ�ȭ
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();
    return 0;
}
