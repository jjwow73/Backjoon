#include <iostream>
#define mod 1000000000
#define INF 987654321
using namespace std;
int stairN[101][10]; //[a][b] : [���� �ڸ��� ���°����][���� �ڸ� ���� ��]
/*
stairN[0][0] : �Ұ��� (0��°�ڸ� ����)
stairN[0][1] : �Ұ��� (0��°�ڸ� �� ����
stairN[1][0] : �Ұ��� (1��°�ڸ��� ���������� 0�� �� ���� ����.
stairN[1][1] : ���� ( 1��° �ڸ��� 1�� ���� �� ������ ��� ��) = stairN[2][0] + stairN[2][2]
stairN[a][b] : (a��° �ڸ��� b�� ���� �� ��� ��) = stairN[a+1][b-1] + stairN[a+1][b+1]
	�̶� a == N (���� ����)���� ���� return 1, b�� ������ 0<=b<=9
*/

int N; // �ڸ� ��
int climb(int a, int b) {
	if (b < 0 || b > 9)//base case: beyond the scope.
		return 0;
	if (a == N) //base case : reached the end point
		return 1;
	if (stairN[a][b] != -1) //dp.
		return stairN[a][b];
	stairN[a][b] = climb(a + 1, b - 1) % mod + climb(a + 1, b + 1) % mod;
	stairN[a][b] %= mod;
	return stairN[a][b];
}

int climb2(int a, int b) {
	if (b < 0 || b > 9)
		return 0;
	if (a == 1)
		return 1;
	if (stairN[a][b] != -1)
		return stairN[a][b];
	stairN[a][b] = climb2(a - 1, b - 1) % mod + climb2(a - 1, b + 1) % mod;
	stairN[a][b] %= mod;
	return stairN[a][b];
}

int main() {
	cin >> N;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 101; j++)
			stairN[j][i] = -1;
	int res = 0;
	for (int i = 1; i < 10; i++){
		res += climb2(N, i);
		res %= mod;
	}
	cout << res << endl;
}