#include <iostream> 
using namespace std; 

int main(void) { 
	int n, arr[4], max = 0; 
	cin >> n; 

	while (n--) { 
		int dice[7] = { 0, }, tmp=0; 
		for (int i = 0; i < 4; i++) { 
			cin >> arr[i]; //배열에 삽입
			dice[arr[i]]++; //주사위 눈 빈도수 카운트
		} 
		for (int i = 1; i <= 6; i++) { // 같은 눈이 4개인 경우
			if (dice[i] == 4) { 
				tmp = 50000 + i * 5000; 
				break; 
			} 
		} 
		if (tmp == 0) { // 같은 눈이 3개인 경우
			for (int i = 1; i <= 6; i++) { 
				if (dice[i] == 3) { 
					tmp = 10000 + i * 1000;
					break; 
				} 
			} 
		} 
		if (tmp == 0) {  //같은 눈이 2개인 경우 
			int cnt = 0; 
			for (int i = 1; i <= 6; i++) { 
				if (dice[i] == 2) { 
					cnt++; 
					tmp += i; 
				} 
			} 
			if (cnt == 2) //두 쌍이 나오는 경우
				tmp = 2000 + tmp * 500; 
			else if (cnt == 1) //같은 눈이 2개만 나오는 경우
				tmp = 1000 + tmp * 100; 
		} 
		if (tmp == 0) {  //모두 다른 눈이 나오는 경우
			for (int i = 6; i >= 1; i--) { 
				if (dice[i]) { 
					tmp = i * 100; 
					break; 
				} 
			} 
		} 
		if (max < tmp) //기존보다 더 큰 값이 나오면
			max = tmp; 
	} 
	cout << max;
	return 0;
}