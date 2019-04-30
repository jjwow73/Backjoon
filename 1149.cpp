#include <iostream>
#include <algorithm>
using namespace std;
enum {RED, GREEN, BLUE};

int cache[3][1001]; // color, n
int costs[1001][3];
int NumberOfHouses;

int RGB(int color, int n) {
	if (n == 0)
		return 0;
	if (color != 4 && cache[color][n] != -1)
		return cache[color][n];
	if (color == 4) {
		int a, b, c;
		a = RGB(GREEN, n - 1) + costs[n][GREEN];
		b = RGB(RED, n - 1) + costs[n][RED];
		c = RGB(BLUE, n - 1) + costs[n][BLUE];
		int mini = min(a, b);
		mini = min(mini, c);
		cache[color][n] = mini;
		return cache[color][n];
	}
	else  if (color == RED) {
		cache[color][n] = min(RGB(GREEN, n-1) + costs[n][GREEN],
			RGB(BLUE, n - 1) + costs[n][BLUE]);
		return cache[color][n];
	}
	else if (color == GREEN) {
		cache[color][n] = min(RGB(RED, n - 1) + costs[n][RED],
			RGB(BLUE, n - 1) + costs[n][BLUE]);
		return cache[color][n];
	}
	else if (color == BLUE) {
		cache[color][n] = min(RGB(GREEN, n - 1) + costs[n][GREEN],
			RGB(RED, n - 1) + costs[n][RED]);
		return cache[color][n];
	}
	return cache[color][n];
	return 0;
}

int solve(int color, int N) {
	if (N == NumberOfHouses)
		return 0;
	if (cache[color][N] != -1)
		return cache[color][N];
	if (color == RED) {
		cache[color][N] = min(solve(GREEN, N + 1) + costs[N][GREEN],
							solve(BLUE, N + 1) + costs[N][BLUE]);
	}
	if (color == GREEN) {
		cache[color][N] = min(solve(RED, N + 1) + costs[N][RED],
							solve(BLUE, N + 1) + costs[N][BLUE]);
	}
	if (color == BLUE) {
		cache[color][N] = min(solve(GREEN, N + 1) + costs[N][GREEN],
							solve(RED, N + 1) + costs[N][RED]);
	}
	return cache[color][N];
}
int main() {
	cin >> NumberOfHouses;
	int cnt = 0;
	for (int i = 0; i < NumberOfHouses; i++) {
		cin >> costs[i][0] >> costs[i][1] >> costs[i][2]; //Red, Green, Blue.
	}
	for (int i = 0; i < NumberOfHouses; i++){
		cache[0][i] = -1;
		cache[1][i] = -1;
		cache[2][i] = -1;
	}
	int res = min(solve(RED, 1) + costs[0][RED], solve(GREEN, 1) + costs[0][GREEN]);
	res = min(res, solve(BLUE, 1) + costs[0][BLUE]);
	cout << res << endl;
	return 0;
}


/*
	solve(int color, int N) : N-1��°���� color�� ���� ��, N��° �ּ� ����� ����
	���� ���� ����� �������ִ°� ����Ʈ
	min(Green, Blue, Red)�� ���ֵ� �� �� ���� ���� ���� ���� ���� �����ϴ� ���� ������ ����.

	if(N == N) : ������ ���̸� �׳� return
	�ƴ� ��쿡 dp �κй������� Ȯ��.
	�ƴ� ��쿡 ���� min return


*/