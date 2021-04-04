/*
�� ���� 0, �� ���� 1�� ǥ�õǴ� n*m�� �������� �� ���� �� �� �������� ���� �� ������?
���� ���� �Է¹���
*/
#include <iostream>
using namespace std;

void dfs(int* graph[], int i, int j, int n, int m)
{
	if (i < 0 || i > n - 1 || j < 0 || j > m - 1) {
		return;						//���� ����. �־��� ������ ���.
	}

	if (graph[i][j] == 0) {
		graph[i][j] = 1;			//�湮ó��
		//�����¿쿡 �ִ� ��� �� ������ ä���� �Ѵ�.
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

	int temp = cin.get();	//���͹���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			graph[i][j] = cin.get() - '0';
		temp = cin.get();
	}

	//dfs ��� ���� Ž��
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