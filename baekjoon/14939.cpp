#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
char lights[10][10]; 
//���� ���� ������ �����ϰ� ���� ���� ���� ���� �����̶�� �����ϰ� ��ĭ �Ʒ��� ���� ��� ����Ʈ���� ������ �� ����� ���� �ϼ�(��� ����)�� ������ ��� cnt�� ��ȯ, �ƴ� ��� INF ��ȯ

//�� x,y�� ���� �� �ִ� ��ġ(���� �ȿ� ����)�ϴ��� Ȯ���ϴ� safe �Լ�
bool safe(int x, int y) {
	return (x >= 0 && x < 10) && (y >= 0 && y < 10);
}

//iX, iY�� ������ �� lights�� ���� �ٲ��ִ� �Լ�. //���������� ����, ���������� Ű��
void lightOff(int iX, int iY) {
	lights[iY][iX] = (lights[iY][iX] == 'O') ? '#' : 'O';
	for (int i = 0; i < 4; i++) {
		int nX = iX + dx[i], nY = iY + dy[i];
		if (safe(nX, nY)) {
			lights[nY][nX] = (lights[nY][nX] == 'O') ? '#' : 'O';
		}
	}
}
/*
����ĭ���� ����ĭ ���� �ϳ��ϳ� �˻��Ѵ�
���࿡ O�� ��� (�������� ���)
    ó�� ���̸� �ΰ��� ���� ������ ����Ѵ�.
		1) ����� ���
			�ش� ��ġ�� ������ ���� cnt�� ����Ѵ�.
			�ش� ��ġ�� �ٽ� �����ش�(���ش�)
		2) ������ ���
			�ش� ��ġ�� ������ ���� cnt�� ����Ѵ�.
			�ش� ��ġ�� �ٽ� �����ش�(���ش�)
		�� �� ���� ���� res�� �����ϰ� ��������� Ȯ���ؼ� �� ���� �ٽ� �����ش�.
	ó�� ���� �ƴϸ� �Ѱ����θ� ����Ѵ�.
		1) ������ ���
			�ش� ��ġ�� ������ ���� cnt�� ����Ѵ�.
����ĭ���� �� �˻�
ó��ĭ���� ����ĭ���� �ٽ� �˻��ϸ� �ϳ��� O�� ���� ��� res=INF ����.
res���� ��ȯ�Ѵ�.
*/
int pressBtn(int ii, int jj) {
	int cnt = INF;
	for (int i = ii; i < 10; i++) {
		for (int j = jj; j < 10; j++) {
			if (lights[i][j] == 'O') {
				if (i == 0) {
					int f = 0 , s = 0;
					lightOff(i, j);
					f = pressBtn(i, j+1);
					lightOff(i, j);
					lightOff(i + 1, j);
					s = pressBtn(i, j + 1);
					lightOff(i + 1, j);
					if (s > f) {
						cnt = min(cnt,f);
						lightOff(i, j);
					}
					else {
						cnt = min(cnt,s);
						lightOff(i + 1, j);
					}
				}
				else {
					lightOff(i + 1, j);
					cnt = min(cnt, pressBtn(i, j + 1));
				}
			}
		}
	}
	for (int i = ii; i < 10; i++) {
		for (int j = jj; j < 10; j++) {
			if (lights[i][j] == 'O') {
				if (i == 0) {
					int f = 0, s = 0;
					lightOff(i, j);
					f = pressBtn(i, j + 1);
					lightOff(i, j);
					lightOff(i + 1, j);
					s = pressBtn(i, j + 1);
					lightOff(i + 1, j);
					if (s > f) {
						cnt = min(cnt, f);
						lightOff(i, j);
					}
					else {
						cnt = min(cnt, s);
						lightOff(i + 1, j);
					}
				}
				else {
					lightOff(i + 1, j);
					cnt = min(cnt, pressBtn(i, j + 1));
				}
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (lights[i][j] == 'O')
				cnt = -1;
		}
	}
	//cout << "i,j = " << ii << ", " << jj << "//" << cnt << "\n";
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 10; i++)
		cin >> lights[i];
	cout << pressBtn(0, 0) << "\n";
}