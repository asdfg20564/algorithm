/*
n*m 크기의 미로에서 시작은 (1,1) 끝은 (n,m) 위치에 있고 한 번에 한 칸씩 이동할 수 있다.
이때 괴물이 있으면 0, 없으면 1로 괴물을 피해서 탈출하기 위해 움직여야 할 최소 칸의 개수를 구하시오.
(첫 칸과 마지막 칸 포함) (탈출로는 반드시 있음) (첫 칸은 항상 1)
*/
#include <iostream>
#include <queue>
#include <utility>		//pair 사용
using namespace std;

int main(void)
{
	//입력
	int n, m;
	cin >> n >> m;

	int** graph = new int* [n];
	for (int i = 0; i < n; i++)
		graph[i] = new int[m];

	int temp = cin.get();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			graph[i][j] = cin.get() - '0';
		temp = cin.get();
	}

	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	//시작 점을 bfs queue에 삽입
	int x = 0, y = 0;
	queue<pair<int,int>> bfs_q;
	bfs_q.push(make_pair(0,0));		

	//bfs 방식을 사용하여 맨 끝 점까지의 최소 거리를 계산한다.
	while (!bfs_q.empty()) {
		x = bfs_q.front().first;
		y = bfs_q.front().second;
		bfs_q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1)	//0 ~ n-1까지 저장
				continue;
			if (graph[nx][ny] == 0)
				continue;
			if (graph[nx][ny] == 1) {					//해당 노드를 처음 방문하는 경우
				graph[nx][ny] = graph[x][y] + 1;		//(0,0)에서 해당 칸까지 도착하는데 걸리는 최소 칸 수
				bfs_q.push(make_pair(nx, ny));			//bfs 반복
			}
		}
	}

	cout << graph[n - 1][m - 1];

	//삭제
	for (int i = 0; i < n; i++)
		delete[] graph[i];
	delete[] graph;

	return 0;
}