#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;
int dp[301][2];
int Stairs[301];
int stairsHeight;
int stepping(int st, int status) { //status == 0 ������ �ȹ��� ==1 ����
	if (st == stairsHeight-1) //������ ��ܿ� �����ϸ�
		return Stairs[st];
	if (st > stairsHeight-1) //�������� �Ѿ�� 
		return -INF; //���� ū ���� ������ ��ȯ�ؼ� ������ �ȵǰ� ��.
	if (dp[st][status]!=0) //�̹� ����� �κй����� ���
		return dp[st][status]; //dp�� ��ȯ.
	if (status == 0) //������ ���� �ʾ����� 2��� or 1��� �Ѵ� ����
		dp[st][status] = max(stepping(st + 1, 1), stepping(st + 2, 0)) + Stairs[st];
	else //������ ������� 2��ܸ� ����
		dp[st][status] = stepping(st + 2, 0)+Stairs[st];
	return dp[st][status];
}

int main() {
	cin >> stairsHeight;
	for (int i = 0; i < stairsHeight; i++)
		cin >> Stairs[i];
	//ó���� 1����ϴ��� 2����ϴ��Ĵ� stepping���� ���� ���ϹǷ�
	//���� max�� ����.
	cout << max(stepping(0, 0),stepping(1,0)) << endl;
	return 0;
}