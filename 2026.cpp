#include <iostream>
#include <vector>
using namespace std;
bool friends[901][901];
int numFriends[900];
int K, N, F;
vector<int> ans;
bool endFunc;
void pushPairs(vector<int> pic, int picSize, int start, int depth) {
	//depth escape condition
	if (endFunc)
		return;
	if (depth == N || picSize == K) { //Ż������
		if (picSize == K) {
			ans = pic;
			endFunc = true;
		}
		return;
	}
	if (K > picSize + N - start) //����ġ��. ���� ģ���� ���ڷ� K�� ������ ��.
		return;
	for (int next = start; next < N; next++) {
		if (numFriends[next] < K - 1) //ģ��[next]�� ģ������ K���� ������ ��ǳ �ο� ��ä��.
			continue;
		bool flag = true;//nextģ���� ������ ģ����� �� ģ���������� Ȯ��.
		for (int prev = 0; prev < picSize; prev++) {
			if (!friends[next][pic[prev]]) {
				flag = false;
				break;
			}
		}
		if (flag) { //ģ�����
			pic.push_back(next); //next�� �ְ�
			pushPairs(pic, picSize + 1, next + 1, depth + 1); //����ϰ�
			pic.pop_back(); //next�� ����
		}
		else
			continue;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> K >> N >> F;
	int a, b;
	for (int i = 0; i < 901; i++)
		for (int j = 0; j < 901; j++)
			friends[i][j] = false;
	for (int i = 0; i < F; i++) {
		cin >> a >> b;
		friends[a - 1][b - 1] = friends[b - 1][a - 1] = true;
		numFriends[a - 1]++;
		numFriends[b - 1]++;
	}
	vector<int> pic;
	pushPairs(pic, 0, 0, 0);
	int ansSize = ans.size();
	if (ansSize < K)
		cout << "-1" << endl;
	else {
		for (int i = 0; i < ansSize; i++)
			if (i != ansSize - 1)
				cout << ans[i] + 1 << "\n";
			else
				cout << ans[i] + 1;
	}
	return 0;
}
/*#include <iostream>
#include <vector>
using namespace std;
bool friends[901][901] = { false };
vector<int> pic;
vector<int> ans;
bool visited[901];
bool endFunc;
int K, N, F;
void countPicnic(int start) {
	if (endFunc || start > N) {
		cout << "*";
		return;
	}
	pic.push_back(start);
	visited[start] = true;
	int picSize = pic.size();
	if (picSize == K) {
		endFunc = true;
		ans = pic;
		return;
	}
	else {
		for (int next = start + 1; next <= N; next++) {
			if (!visited[next]) {
				bool flag = true;
				for (int prev = 0; prev < picSize; prev++) {
					cout << "pic: " << prev << "\n";
					if (!friends[next][pic[prev]]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					countPicnic(next);
					if (!pic.empty())
						pic.pop_back();
					else
						return;
				}
			}
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> K >> N >> F;
	int a, b;
	for (int i = 0; i < F; i++) {
		cin >> a >> b;
		friends[a][b] = friends[b][a] = true;
	}
	for (int i = 1; i <= N; i++) {
		for (int i = 0; i < 901; i++)
			visited[i] = false;
		countPicnic(i);
		if (endFunc)
			break;
		endFunc = false;
		pic.clear();
	}
	if (ans.size() < K)
		cout << "-1" << endl;
	else {
		for (int i = 0; i < ans.size(); i++)
			if (i != ans.size() - 1)
				cout << ans[i] << "\n";
			else
				cout << ans[i];
	}
	return 0;
}

/*#include <iostream>
#include <vector>
using namespace std;
bool friends[901][901] = { false };
vector<int> pic;
vector<int> ans;
bool visited[901];
bool endFunc;
int K, N, F;
void countPicnic(int start) {
	if (endFunc || start > N) {
		return;
	}
	pic.push_back(start);
	visited[start] = true;
	int picSize = pic.size();
	if (picSize == K) {
		for (int i = 0; i < pic.size(); i++) {
			cout << pic[i] << " ";
		}
		cout << "\n=============\n";
		endFunc = true;
		ans = pic;
		return;
	}
	else {
		cout << "pic: " << picSize << "\n";

		for (int i = 0; i < picSize; i++) {
			cout << pic[i] << ",";
		}
		cout << "\n";
		for (int next = start + 1; next <= N; next++) {
			if (!visited[next]) {
				bool flag = true;
				for (int prev = 0; prev < picSize; prev++) {
					cout << "next,prev = " << next << ", " << prev << "\n";
					if (!friends[next][pic[prev]]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					cout << "(" << next << ")\n";
					cout << "[flag]pic: " << picSize << "\n";
					for (int i = 0; i < picSize; i++) {
						cout << pic[i] << ",";
					}
					cout << "\n";
					countPicnic(next);
					pic.pop_back();
				}
			}
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> K >> N >> F;
	int a, b;/*
	for (int i = 0; i < 901; i++)
		for (int j = 0; j < 901; j++)
			friends[i][j] = false;
	for (int i = 0; i < F; i++) {
		cin >> a >> b;
		friends[a][b] = friends[b][a] = true;
	}
	for (int i = 1; i <= N; i++) {
		for (int i = 0; i < 901; i++)
			visited[i] = false;
		countPicnic(i);
		if (endFunc)
			break;
		endFunc = false;
		pic.clear();
	}
	if (ans.size() < K)
		cout << "-1" << endl;
	else {
		for (int i = 0; i < ans.size(); i++)
			if(i != ans.size()-1)
				cout << ans[i] << "\n";
			else
				cout << ans[i];
	}
	return 0;
}
*/