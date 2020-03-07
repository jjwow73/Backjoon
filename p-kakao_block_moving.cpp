#include <iostream>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;


int N = 5;
vector<vector<int> > visited; // 0 ~ N**2-1���� ����. x,y => x+y*N�� ���� �ȴ�.

struct Pos {
	int x, y;
};

typedef pair<Pos, Pos> plane;
bool reached(plane p) {
	return (p.first.x == N - 1 && p.first.y == N - 1) || (p.second.x == N - 1 && p.second.y == N - 1);
}
int getScalarize(Pos p, int N) {
	return p.x + p.y * N;
}
bool isHorizon(plane p) {
	return p.first.x == p.second.x;
}
bool isVisited(plane a) {
	return visited[getScalarize(a.first, N)][getScalarize(a.second, N)];
}
bool isSafe(plane p, vector<vector<int> > board) {
	bool isInboundary = p.first.x >= 0 && p.first.x < N && p.first.y >= 0 && p.first.y < N && p.first.x >= 0 && p.second.x < N && p.second.y >= 0 && p.second.y < N;
	bool isAvailable = board[p.first.x][p.first.y] == 0 && board[p.second.x][p.second.y] == 0;
	return isInboundary && isAvailable;
}
void visiting(plane p) {
	visited[getScalarize(p.first, N)][getScalarize(p.second, N)] = visited[getScalarize(p.first, N)][getScalarize(p.second, N)] = true;
}
plane movePlane(plane p, int x1, int y1, int x2, int y2) {
	plane ret = make_pair(Pos{ p.first.x+x1, p.first.y+y1}, Pos{ p.second.x+x2,p.second.y+y2 });
	return ret;
}
int fdx[4] = { 0, 0, 1, -1};
int fdy[4] = { 1,-1,0, 0 };
int sdx[4] = { 0, 0, 1, -1 };
int sdy[4] = { 1,-1,0,0 };
int hfdx[4] = { 0,0,1,1 };
int hfdy[4] = { 0,0,1,-1 };
int hsdx[4] = { -1,-1,0,0 };
int hsdy[4] = { 1,-1,0,0 };
int hrfdx[4] = { 0,0,0,0 };
int hrfdy[4] = { 0,0,1,-1, };
int hrsdx[4] = { 0,0,0,0 };
int hrsdy[4] = { 1,-1,0,0 };

int vfdx[4] = { 0,0,-1,1 };
int vfdy[4] = { 0,0,1,1 };
int vsdx[4] = { -1,-1,0,0 };
int vsdy[4] = { 1,-1,0,0 };
int vrfdx[4] = { 0,0,-1,0 };
int vrfdy[4] = { 0,0,1,0, };
int vrsdx[4] = { -1,0,0,0 };
int vrsdy[4] = { 1,0,0,0 };
/*

0,0,-1,1	0,0,-1,0
0,0,1,1		0,0,1,0
-1,-1,0,0	-1,0,0,0
1,-1,0,0	1,0,0,0
*/
int solution(vector<vector<int>> board) {
	int answer = 0;
	queue<plane> Q;
	queue<int> depth;
	plane startPosition = make_pair(Pos{ 0,0 }, Pos{ 0,1 });
	Q.push(startPosition);
	depth.push(0);
	while (!Q.empty()) {
		plane cur = Q.front();
		int d = depth.front();
		depth.pop();
		Q.pop();
		if (reached(cur)) {
			answer = d;
			break;
		}
		for (int i = 0; i < 4; i++) {
			//���ɼ��ִ� ��ġ
			plane possibleNext = movePlane(cur, fdx[i], fdy[i], sdx[i], sdy[i]);
			if (isVisited(possibleNext) && isSafe(possibleNext, board)) {
				visiting(possibleNext);
				Q.push(possibleNext);
				depth.push(d + 1);
			}
		}
		if (isHorizon(cur)) {
			for (int i = 0; i < 4; i++) {
				plane pNext = movePlane(cur, hfdx[i], hfdy[i], hsdx[i], hsdy[i]);
				plane tNext = movePlane(cur, hrfdx[i], hrfdy[i], hrsdx[i], hrsdy[i]);
				if (isVisited(pNext) && isSafe(pNext, board) && isSafe(tNext, board)) {
					visiting(pNext);
					Q.push(pNext); depth.push(d + 1);
				}
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				plane pNext = movePlane(cur, vfdx[i], vfdy[i], vsdx[i], vsdy[i]);
				plane tNext = movePlane(cur, vrfdx[i], vrfdy[i], vrsdx[i], vrsdy[i]);
				if (isVisited(pNext) && isSafe(pNext, board) && isSafe(tNext, board)) {
					visiting(pNext);
					Q.push(pNext); depth.push(d + 1);
				}
			}
		}
	}
	return answer;
}
/*
(0,0) (-1, 1) 
0, 0, -1, 1,	0,0,0,1
0, 0, -1, -1,	0,0,0,-1
1,1,0,0,		0,1,0,0
1,-1,0,0,		0,-1,0,0

0,0,-1,1 0,0,-1,0
0,0,1,1 0,0,1,0
-1,-1,0,0	-1,0,0,0
1,-1,0,0	1,0,0,0
*/

/*
int hfdx[4] = { 0,0,1,1 };
int hfdy[4] = { 0,0,1,-1 };
int hsdx[4] = { -1,-1,0,0 };
int hsdy[4] = { 1,-1,0,0 };
int hrdx[4] = { 1,1,0,0 };
int hrdy[4] = { 1,-1,1,-1 };

int vfd
int verticalfdx[4] = {0}
//		x1,y1,x2,y2
//�»�:0,0,-1,1
//�ɸ�:1,1
//����:0,0,-1,-1
//�ɸ� 1,-1
//���:1,1,0,0
//�ɸ�:0,1
//����:1,-1,0,0
//�ɸ�: 0, -1
// vertical
//0,0,-1,1
//-1,-1
*/
//#include <string>
//#include <vector>
//#include <queue>
//#include <iostream>
//
//using namespace std;
//
//vector<vector<int>> sampleInput; // [[0, 0, 0, 1, 1], [0, 0, 0, 1, 0], [0, 1, 0, 1, 1], [1, 1, 0, 0, 1], [0, 0, 0, 0, 0]] ;
//struct Vertex {
//	int x, y;
//};
//
//struct POS {
//	Vertex left, right; // up, down
//	bool isHorizontal;
//} ;
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//
//Vertex getLeft(Vertex left, Vertex right) {
//	return left.x < right.x ? left : right;
//}
//Vertex getRight(Vertex left, Vertex right) {
//	return left.x < right.x ? right : left;
//}
//Vertex getUp(Vertex left, Vertex right) {
//	return left.y < right.y ? right : left;
//}
//Vertex getDown(Vertex left, Vertex right) {
//	return left.y < right.y ? left : right;
//}
//int solution(vector<vector<int>> board) {
//	int answer = 0;
//	int N = board.size();
//	vector<vector<bool>> visited(N, vector<bool>(false, N));
//	// BFS
//
//	/*
//	bfs(int k){
//	Q����
//	Q�� ù �� �� �ִ´�.
//	Visited = true
//	While Q�� ��������
//		Q.pop()�ؼ� ���� ��ġ��������
//			���� ��ġ���� �ֺ��� �ִ� �ֵ��� ��ġ�� Queue�� �־��ֱ�
//	*/
//
//	queue<POS> Q;
//	POS fir;
//	fir.left = Vertex{ 0,0 };
//	fir.right = Vertex{ 0,1 };
//	fir.isHorizontal = false;
//	Q.push(fir);
//	visited[fir.left.x][fir.left.y] = true;
//	visited[fir.right.x][fir.right.y] = true;
//	while (!Q.empty()) {
//		POS cur = Q.front();
//		Q.pop();
//		// �׳� �����¿�
//		// ���� isHorizontal�� ���
//		if (cur.isHorizontal) {
//			Vertex curLeft = getLeft(cur.left, cur.right);
//			Vertex curRight = getRight(cur.left, cur.right);
//			Vertex nextMove;
//			//����
//			nextMove.x = getLeft(cur.left, cur.right).x - 1;
//			nextMove.y = getLeft(cur.left, cur.right).y;
//			//������ �� �ִ��� Ȯ���ϱ� -> �湮���� & ��Ȯ��
//			if (!visited[nextMove.x][nextMove.y] && board[nextMove.x][nextMove.y]) {
//				visited[nextMove.x][nextMove.y] = true;
//					Q.push(POS{ nextMove, getLeft(cur.left, cur.right), cur.isHorizontal});
//			}
//			//������
//			nextMove.x = getRight(cur.left, cur.right).x + 1;
//			nextMove.y = getRight(cur.left, cur.right).y;
//			if (!visited[nextMove.x][nextMove.y] && board[nextMove.x][nextMove.y]) {
//				visited[nextMove.x][nextMove.y] = true;
//				Q.push(POS{ getRight(cur.left, cur.right), nextMove, cur.isHorizontal });
//			}
//			//����
//			Vertex nextLeft = Vertex{ curLeft.x, curLeft.y + 1 };
//			Vertex nextRight = Vertex{ curRight.x, curRight.y + 1 };
//			if (!visited[nextLeft.x][nextLeft.y] && !visited[nextRight.x][nextRight.y] && board[nextLeft.x][nextLeft.y] && board[nextRight.x][nextRight.y]) {
//				visited[nextLeft.x][nextLeft.y] = true;
//				visited[nextRight.x][nextRight.y] = true;
//				Q.push(POS{ nextLeft, nextRight, cur.isHorizontal });
//			}
//			//�Ʒ���
//			nextLeft = Vertex{ curLeft.x, curLeft.y - 1 };
//			nextRight = Vertex{ curRight.x, curRight.y - 1 };
//			if (!visited[nextLeft.x][nextLeft.y] && !visited[nextRight.x][nextRight.y] && board[nextLeft.x][nextLeft.y] && board[nextRight.x][nextRight.y]) {
//				visited[nextLeft.x][nextLeft.y] = true;
//				visited[nextRight.x][nextRight.y] = true;
//				Q.push(POS{ nextLeft, nextRight, cur.isHorizontal });
//			}
//
//			//�»�
//			nextLeft = Vertex{ curLeft.x, curLeft.y + 1 };
//			nextRight = Vertex{ curLeft.x, curLeft.y };
//			if (!visited[nextLeft.x][nextLeft.y] && board[nextLeft.x][nextLeft.y] && board[nextLeft.x+1][nextLeft.y]) {
//				visited[nextLeft.x][nextLeft.y] = true;
//				Q.push(POS{ nextLeft, nextRight, !cur.isHorizontal });
//			}
//			//����
//			nextLeft = Vertex{ curLeft.x, curLeft.y };
//			nextRight = Vertex{ curRight.x - 1, curRight.y - 1 };
//			if (!visited[nextRight.x][nextRight.y] && board[nextRight.x][nextRight.y] && board[nextRight.x+1][nextRight.y]) {
//				visited[nextRight.x][nextRight.y] = true;
//				Q.push(POS{ nextLeft, nextRight, !cur.isHorizontal });
//			}
//			//���
//			nextLeft = Vertex{ curLeft.x + 1, curLeft.y + 1 };
//			nextRight = Vertex{ curRight.x, curRight.y };
//			if (!visited[nextLeft.x][nextLeft.y] && board[nextLeft.x][nextLeft.y] && board[nextLeft.x-1][nextLeft.y]) {
//				visited[nextLeft.x][nextLeft.y] = true;
//				Q.push(POS{ nextLeft, nextRight, !cur.isHorizontal });
//			}
//			//����
//			nextLeft = Vertex{ curLeft.x, curLeft.y };
//			nextRight = Vertex{ curRight.x - 1, curRight.y - 1 };
//			if (!visited[nextRight.x][nextRight.y] && board[nextRight.x][nextRight.y] && board[nextRight.x + 1][nextRight.y]) {
//				visited[nextRight.x][nextRight.y] = true;
//				Q.push(POS{ nextLeft, nextRight, !cur.isHorizontal });
//			}
//		}
//		// ���� Not isHorizontal �� ���
//		else {
//			int dx[6];
//			int dy[6];
//
//			Vertex curLeft = getLeft(cur.left, cur.right);
//			Vertex curRight = getRight(cur.left, cur.right);
//			//����
//			dx[0] = -1;
//			dy[0] = 0;
//			//������
//			dx[1] = 1;
//			dy[1] = 0;
//			//����
//			dx[2] = 0;
//			dy[2] = 1;
//			//�Ʒ���
//			dx[3] = 0;
//			dy[3] = -1;
//			for (int i = 0; i < 4; i++) {
//				Vertex nextLeft = Vertex{ curLeft.x + dx[i], curLeft.y + dy[i] };
//				Vertex nextRight = Vertex{ curRight.x + dx[i], curRight.y + dy[i] };
//				if (i == 0) {// ����
//					if (!visited[nextLeft.x][nextLeft.y] && board[nextLeft.x][nextLeft.y]) {
//						visited[nextLeft.x][nextLeft.y] = true;
//						Q.push(POS{ nextLeft, nextRight, cur.isHorizontal });
//					}
//				}
//				else if (i == 1) {//������
//					if (!visited[nextRight.x][nextRight.y] && board[nextRight.x][nextRight.y]) {
//						visited[nextRight.x][nextRight.y] = true;
//						Q.push(POS{ nextLeft, nextRight, cur.isHorizontal });
//					}
//				}
//				else if (i == 2) { //����
//					//if(!visited[nextLeft.x][nextLeft.y] && !visited[nextRight.x][nextRight.y] && board)
//
//				}
//				else { //�Ʒ���
//
//				}
//			}
//			//�»�
//			//����
//			//���
//			//����
//		}
//
//	}
//	return answer;
//}
//int main() {
//
//	cout << "Hello World!" << endl;
//	return 0;
//}