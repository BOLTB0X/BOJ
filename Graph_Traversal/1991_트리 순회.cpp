#include <iostream>
using namespace std;

int tree[50][2];

//������ȸ
void preorder(int cur) {
	if (cur == -1) 
		return;
	//���
	cout << (char)(cur + 'A');
	preorder(tree[cur][0]);
	preorder(tree[cur][1]);
	return;
}

//������ȸ
void inorder(int cur) {
	if (cur == -1) 
		return;

	inorder(tree[cur][0]);
	//���
	cout << (char)(cur + 'A');
	inorder(tree[cur][1]);
	return;
}

//������ȸ
void postorder(int cur) {
	if (cur == -1) 
		return;

	postorder(tree[cur][0]);
	postorder(tree[cur][1]);
	//���
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
	//Ʈ�� ����
	for (int i = 0; i < n; i++) {
		char x, y, z;
		// ���ĺ� �Է�
		cin >> x >> y >> z;		
		x = x - 'A'; //  ���� ��ȯ

		if (y == '.') // -1
			tree[x][0] = -1;
		
		else 
			tree[x][0] = y - 'A'; //���� ��ȯ
		
		if (z == '.') 
			tree[x][1] = -1;
		
		else 
			tree[x][1] = z - 'A';
	}
	
	solution();

	return 0;
}