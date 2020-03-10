#include <cstdio>
#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int N; //������ ���� ��
int DP[15];
int T[15];
int P[15];
int consult(int kDay) { //k��°���� �����ؼ� ������� �� �ִ� ���� ��ȯ
	if (kDay > N) {
		return -INF;
	}
	else if (kDay == N)
		return 0;
	else { //kDay < N
		if (DP[kDay] != -1)
			return DP[kDay];
		DP[kDay] = -1;
		DP[kDay] = max(consult(kDay + 1), consult(kDay + T[kDay]) + P[kDay]);
		return DP[kDay];
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < 15; i++) {
		DP[i] = -1;
	}
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}
	cout << "RESULT: " << consult(0) << endl;
}