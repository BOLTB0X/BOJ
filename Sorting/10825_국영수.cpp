#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
	string name;
	int kor, eng, mat;

	bool operator < (const Student& s) const {
		if (kor == s.kor) {
			if (eng == s.eng) {
				if (mat == s.mat)
					return name < s.name;
				return mat > s.mat;
			}
			return eng < s.eng;
		}
		return kor > s.kor;
	}
};

void solution(int n, Student* arr) {
	sort(arr, arr + n); // Á¤·Ä

	for (int i = 0; i < n; ++i)
		cout << arr[i].name << '\n';
	return;
}

int main(void) {
	int n;
	Student* arr;

	cin >> n;
	arr = new Student[n];
	for (int i = 0; i < n; ++i) 
		cin >> arr[i].name >> arr[i].kor >> arr[i].eng >> arr[i].mat;
	
	solution(n, arr);
	delete[] arr;
	return 0;
}