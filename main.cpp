#include <iostream>
using namespace std;
/*
0000 �� �� ����
0001 ALL
0010 ¦��
#0011 ¦��+ALL => Ȧ��
0100 Ȧ��
#0101 Ȧ��+ALL => ¦��
#0110 Ȧ��+¦�� => ALL
#0111 Ȧ��+¦��+ALL => �� ��
1000 3k_1 (Ư�����)
1001 3k_1+ALL
1010 3k_1+¦��
#1011 3k_1+ALL+¦�� => 3k_1+Ȧ��
1100 3k_1+Ȧ��
#1101 3k_1+Ȧ��+ALL => 3k_1+¦��
#1110 3k_1+Ȧ��+¦�� => 3k_1+ALL
#1111 3k_1+Ȧ��+¦��+ALL => 3k_1

*/
int main() {
	int act[4]; //����[k]�� �ϴµ� �ɸ��� �ð� :  act[k]
	int status[8]; //���� �� �ִ� ��� ����� ���� �ش��ϴ� �ɸ��� �ð�.
	int n, m;
	int res = 0;
	cin >> n >> m;
	act[0] = n;
	act[1] = int(n / 2);
	act[2] = n - act[1];
	act[3] = (n + 2) / 3;
	status[0] = 0;
	status[1] = act[0];
	status[2] = act[1];
	status[3] = act[2];
	status[4] = act[3];
	status[5] = act[3] + act[0];
	status[6] = act[3] + act[1];
	status[7] = act[3] + act[2];

	if (m == 0)
		res = 1;
	else {
		if (n < 3) {
			if (n == 1)	
				if (m >= 1)
					res = 2;
			if (n == 2)
				if (m >= 2)
					res = 4;
				else if (m == 1)
					res = 3;
		}
		else {
			for (int i = 0; i < 8; i++) {
				if (m >= status[i])
					res++;
			}
		}
	}
	cout << res << endl;
	return 0;
}