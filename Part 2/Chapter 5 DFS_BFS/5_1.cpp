/*
빈 곳은 0, 찬 곳은 1로 표시되는 n*m의 공간에서 빈 곳을 총 몇 구역으로 나눌 수 있을까?
공간 전부 입력받음
*/
#include <iostream>
using namespace std;

void dfs(int* graph[], int i, int j, int n, int m)
{
	if (i < 0 || i > n - 1 || j < 0 || j > m - 1) {
		return;						//종료 조건. 주어진 구역을 벗어남.
	}

	if (graph[i][j] == 0) {
		graph[i][j] = 1;			//방문처리
		//상하좌우에 있는 모든 빈 구역을 채워야 한다.
		dfs(graph, i - 1, j, n, m);
		dfs(graph, i + 1, j, n, m);
		dfs(graph, i, j - 1, n, m);
		dfs(graph, i, j + 1, n, m);
	}
}

int main(void)
{
	int n, m, res = 0;
	cin >> n >> m;

	int** graph = new int* [n];
	for (int i = 0; i < n; i++)
		graph[i] = new int[m];

	int temp = cin.get();	//엔터무시
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			graph[i][j] = cin.get() - '0';
		temp = cin.get();
	}

	//dfs 사용 구역 탐색
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 0) {
				dfs(graph, i, j, n, m);
				res++;
			}
		}
	}

	cout << res;

	for (int i = 0; i < n; i++)
		delete[] graph[i];
	delete[] graph;

	return 0;
}