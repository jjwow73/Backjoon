#include <stdio.h>
#include <queue>
#include <memory.h>
using namespace std;
int N, M;
int map[1111][1111];
int res[1111][1111];
int visited[1111][1111];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int tX, tY;
struct Vertex {
	int x, y, d;
};
bool safe(int x, int y) {
	return (x >= 0 && y >= 0 && x < N && y < M);//�̺κп��� M�� N�� �ٲ��ִ�
	//100�ۼ�Ʈ���� Ʋ�Ƚ��ϴ� �ߴ� ���� �ذ�
}
void solve() {
	int depth = 0;
	queue<Vertex> Q;
	Vertex st;
	st.x = tX;
	st.y = tY;
	st.d = depth;
	Q.push(st);
	visited[tX][tY] = 1;
	while (!Q.empty()) {
		Vertex cur = Q.front();
		Q.pop();
		res[cur.x][cur.y] = cur.d;
		for (int i = 0; i < 4; i++) {
			int nX = cur.x + dx[i];
			int nY = cur.y + dy[i];
			if (safe(nX, nY) && visited[nX][nY] < 0 && map[nX][nY] == 1) {
				visited[nX][nY] = 1;
				Q.push(Vertex{nX, nY, cur.d + 1 });
			}
		}
	}
}
int main() {
	memset(visited, -1, sizeof(visited));
	memset(res, -1, sizeof(res));
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2)
				tX = i, tY = j;
		}
	}
	solve();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (res[i][j] < 0 && map[i][j] == 0)
				res[i][j] = 0;
			if(j != M-1)
				printf("%d ", res[i][j]);
			else
				printf("%d\n", res[i][j]);
		}
	}
	return 0;

}