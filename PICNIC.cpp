#include <iostream>
#include <stdlib.h>
using namespace std;
bool friends[10][10];
int n, m;
int countPairing(bool taken[10]) {
	//taken[i] = i ��° �л��� ¦�� �̹� ã������ true, �ƴϸ� false.
	//base case: ��� �л��� ¦�� ã������ �� ���� ����� ã������ �����Ѵ�.
	bool finished = true;
	for (int i = 0; i < n; i++) if (!taken[i]) finished = false;
	if (finished) return 1;
	int ret = 0;
	//���� ģ���� �� �л��� ã�� ¦�� ���� �ش�.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!taken[i] && !taken[j] && friends[i][j]) {
				taken[i] = taken[j] = true;
				ret += countPairing(taken);
				taken[i] = taken[j] = false;
			}
		}
	}
	return ret;
}

int countPairing2(bool taken[10]) {
	int firstFree = -1;
	for(int i=0; i<n; i++)
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	//base case
	if (firstFree == -1) return 1;
	int ret = 0;
	for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
		if (!taken[pairWith] && friends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairing2(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}

/*
�����ڵ�� �����
countPairing( taken ) : ¦�� �ִ��� Ȯ���ϴ� �迭�� ���ڷ� �޾Ƽ� �Ѱ���. ¦�� ���� ���� ���� ��ȯ.
�������: ��� �л��� ¦�� �� ���� �� ¦���� ���� -> return 1
¦�� ���� �л��� ���� ��
	�� ¦���� �л��� ģ���� �л��� ã�´�. && �� �л�ģ���� ¦�� ����� �Ѵ�
		�� ¦���� �л��� ģ���л��� ¦�� �ξ��ش�.
		�׷��� ����� ¦���� ���ڸ� �����ش�.
		�� ¦���� �л��� ģ���л��� ¦�� ���´�.
		//���� �κ��� ��Ʈ��ŷ �κ�. �����ߴµ��� �򰥸��� ����.
	¦���� ���ڸ� ��ȯ�Ѵ�.
*/
int main() {
	freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;
	while (tc-- > 0) {
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				friends[i][j] = false;
		cin >> n >> m;
		int a, b;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			friends[a][b] = friends[b][a] = true;
		}
		bool counts[10];
		for (int i = 0; i < n; i++) counts[i] = false;
		cout << countPairing2(counts) << endl;
	}
	
	return 0;
}