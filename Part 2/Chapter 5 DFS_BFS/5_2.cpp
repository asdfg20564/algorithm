/*
n*m ũ���� �̷ο��� ������ (1,1) ���� (n,m) ��ġ�� �ְ� �� ���� �� ĭ�� �̵��� �� �ִ�.
�̶� ������ ������ 0, ������ 1�� ������ ���ؼ� Ż���ϱ� ���� �������� �� �ּ� ĭ�� ������ ���Ͻÿ�.
(ù ĭ�� ������ ĭ ����) (Ż��δ� �ݵ�� ����) (ù ĭ�� �׻� 1)
*/
#include <iostream>
#include <queue>
#include <utility>		//pair ���
using namespace std;

int main(void)
{
	//�Է�
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

	//���� ���� bfs queue�� ����
	int x = 0, y = 0;
	queue<pair<int,int>> bfs_q;
	bfs_q.push(make_pair(0,0));		

	//bfs ����� ����Ͽ� �� �� �������� �ּ� �Ÿ��� ����Ѵ�.
	while (!bfs_q.empty()) {
		x = bfs_q.front().first;
		y = bfs_q.front().second;
		bfs_q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1)	//0 ~ n-1���� ����
				continue;
			if (graph[nx][ny] == 0)
				continue;
			if (graph[nx][ny] == 1) {					//�ش� ��带 ó�� �湮�ϴ� ���
				graph[nx][ny] = graph[x][y] + 1;		//(0,0)���� �ش� ĭ���� �����ϴµ� �ɸ��� �ּ� ĭ ��
				bfs_q.push(make_pair(nx, ny));			//bfs �ݺ�
			}
		}
	}

	cout << graph[n - 1][m - 1];

	//����
	for (int i = 0; i < n; i++)
		delete[] graph[i];
	delete[] graph;

	return 0;
}