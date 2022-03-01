#include <iostream>
using namespace std;

int tree[50][2];

//전위순회
void preorder(int cur) {
	if (cur == -1) 
		return;
	//출력
	cout << (char)(cur + 'A');
	preorder(tree[cur][0]);
	preorder(tree[cur][1]);
	return;
}

//중위순회
void inorder(int cur) {
	if (cur == -1) 
		return;

	inorder(tree[cur][0]);
	//출력
	cout << (char)(cur + 'A');
	inorder(tree[cur][1]);
	return;
}

//후위순회
void postorder(int cur) {
	if (cur == -1) 
		return;

	postorder(tree[cur][0]);
	postorder(tree[cur][1]);
	//출력
	cout << (char)(cur + 'A');
	return;
}

void solution(void) {
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);

	return;
}

int main(void) {
	int n;
	cin >> n;
	//트리 생성
	for (int i = 0; i < n; i++) {
		char x, y, z;
		// 알파벳 입력
		cin >> x >> y >> z;		
		x = x - 'A'; //  정수 변환

		if (y == '.') // -1
			tree[x][0] = -1;
		
		else 
			tree[x][0] = y - 'A'; //정수 변환
		
		if (z == '.') 
			tree[x][1] = -1;
		
		else 
			tree[x][1] = z - 'A';
	}
	
	solution();

	return 0;
}