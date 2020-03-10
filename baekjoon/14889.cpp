#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 987654321
using namespace std;
int personS[20][20];
int personN;
int teamSide[20]; // 0:��ŸƮ��. 1:��ũ��
/*teaming �Լ� �����ϰ� ���������غ��δ�.
���߿� ����.*/
/*Ǯ��
�⺻���� Ǯ�� ���
teamSide �迭 : teamSide[k]�� k��° ����� ���� ��Ÿ����. 
	teamSide[8] == 0�� ���, 8��° ����� ��ŸƮ��
	teamSide[9] == 1�� ���, 9��° ����� ��ũ��
personS �迭 : �������� �ִ� S_ij
personN ���� : ��� ��

teaming �Լ� : k��° ����� ���� �ְ� ��ŸƮ���� ��ũ���� �ɷ�ġ ���� �� ��ȯ.
��� �̷��� ��������� "��� ����� �� ���� ��ŸƮ���� ��ũ���� ���� �� ���� �ʳ�"��� ������ �� �ִµ� DFS�� ����Ʈ �� �ϳ��� �̷� �κ�
return�ϴ� ���� �� �������ָ� �ȴ�. �Ʒ� �Լ��� �帧�� ���� ���� ����.
teaming(��ŸƮ���ο���, ��ũ�� �ο���, k��° ���)
	��� ����� �� ���� �־��� ��
		RETURN |��ŸƮ��-��ũ��|
	��ŸƮ���� �� á�� �� //���� == �ο���
		��ũ���� k��° ����� �ִ´�.
		teaming(��ŸƮ���ο���, ��ũ���ο���+1, """k+1""")�� ���� ���(result)
		��ũ���� k��° ����� �ٽ� ����.
		RETURN result
	��ũ���� �� á�� ��
		ViceVersa
	�Ѵ� ��á�� ��
		��ũ���� k��° ����� �ִ´�.
		teaming()�� ����Ѵ�. (result_1)
		��ũ������ k��° ����� ���� ���� ��ŸƮ���� �ִ´�.
		teaming()�� ����Ѵ�. (result_2)
		result = MIN(result_1, result_2)
		RETURN result.

*/
int teaming(int teamStartN, int teamLinkN, int personK) {//��ŸƮ���� �ο����� ��ũ���� �ο����� ���� ���������� �̿��ؼ� ���� ���.
	if (personK == personN) { //baseCase ������ ������� �� ��.
		//��ŸƮ���� ��ũ���� �ɷ�ġ ����ϴ� �κ�
		int teamStats[2] = { 0,0 };
		for (int i = 0; i < personN; i++) {
			for (int j = 0; j < personN; j++) {
				if (teamSide[i] == -1 || teamSide[j] == -1){
					cout << "ERROR\n"; //�̺κ� ������ ����. 
					break;//���ÿ����÷ο� ����
				}
				if (teamSide[i] == teamSide[j])
					teamStats[teamSide[i]] += personS[i][j];
			}
		}
		//���� ���� ��ȯ.
		return abs(teamStats[0] - teamStats[1]);
	}
	int res = INF;
	if(teamStartN == personN/2 || teamLinkN == personN/2){ //���� �� ���� ������ ��.
		if (teamStartN == personN/2) { //��ŸƮ�� ����
			teamSide[personK] = 1;
			res = teaming(teamStartN, teamLinkN + 1, personK + 1);
		}
		if (teamLinkN== personN / 2) { //��ũ�� ����
			teamSide[personK] = 0;
			res = teaming(teamStartN+1, teamLinkN, personK + 1);
		}
		teamSide[personK] = -1;
		return res;
	}
	else { //�Ѵ� ������ ��
		teamSide[personK] = 0;
		res = teaming(teamStartN + 1, teamLinkN, personK + 1);
		teamSide[personK] = 1;
		res = min(res, teaming(teamStartN, teamLinkN + 1, personK + 1));
		return res;
	}
}

int main() {
	cin >> personN;
	for (int i = 0; i < personN; i++) {
		for (int j = 0; j < personN; j++) {
			cin >> personS[i][j];
		}
	}
	cout << "RESULT: " << teaming(0, 0, 0) << endl;
	return 0;
}