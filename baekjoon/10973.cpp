#include <iostream>
#include <vector>
using namespace std;

/*
1.��������ã��
2.�ٲ� ���� ã��. (�������� ���� ����)�� (���������ȿ��� ó������ ���� ������  ����)
3.�����ϱ�
4.�Ųٷ������ϱ�*/
int main() {
	int N;
	int tmp;
	vector<int> perm;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		perm.push_back(tmp);
	}
	//�ڿ������� ���������� �κб��� ã�´�.(���Ҽ���ã��)
	int idx = -1;
	for (int i = N - 1; i > 0; i--) {
		if (perm[i] < perm[i - 1]) {
			idx = i - 1;
			break;
		}
	}
	if (idx != -1) {
		//�ٲ� ���� ã��.
		int j = idx + 1;
		for (; j < N; j++)
			if (perm[idx] < perm[j])
				break;
		j -= 1;
		for (int i = 0; i < N; i++)
			cout << perm[i] << " ";
		cout << endl;
		//swap�ϱ�
		cout << "j:" << j << endl;
		swap(perm[idx], perm[j]);
		for (int i = 0; i < N; i++)
			cout << perm[i] << " ";
		cout << endl;
		//���� �Ųٷ�
		for (int i = idx + 1; i <= (N + idx) / 2; i++) {
			swap(perm[i], perm[N - i + idx]);
		}
		for (int i = 0; i < N; i++)
			cout << perm[i] << " ";
		cout << endl;
	}
	else {
		cout << idx << endl;
	}
}