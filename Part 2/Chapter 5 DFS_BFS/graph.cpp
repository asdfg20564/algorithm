#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

/* BFS Queue ���
void bfs(int start, vector<vector<int>> graph, bool check[]) 
{
	queue<int> bfs_q;

	bfs_q.push(start);			//���� ��� queue�� ����
	check[start] = true;		//���� ��� �湮

	while (!bfs_q.empty()) {
		int current = bfs_q.front();
		bfs_q.pop();
		cout << current << " ";

		for (int i = 0; i < graph[current].size(); i++) {
			//���� ��忡�� �湮���� ���� ��� ������ ��带 queue�� �ְ� �湮�Ѵ�.
			if (check[graph[current][i]] == false) {
				bfs_q.push(graph[current][i]);
				check[graph[current][i]] = true;
			}
		}
	}
}*/

/* DFS stack ���
void dfs(int start, vector<vector<int>> graph, bool check[]) 
{
	stack<int> dfs_s;
	dfs_s.push(start);		//���� ��� stack�� ����
	check[start] = true;	//���� ��� �湮
	cout << start << " ";

	while (!dfs_s.empty()) {
		int current = dfs_s.top();		//���� ��ġ�� ���
		dfs_s.pop();

		for (int i = 0; i < graph[current].size(); i++) {

			int next = graph[current][i];

			//DFS�� ���� : ������忡�� �湮���� �ʴ� ����� ��� stack�� �־��ش�..
			if (check[next] == false) {
				cout << next << " ";
				check[next] = true;
				//pop()�� �߾��� ������ ���� current�� �ٽ� �־�����Ѵ�.
				dfs_s.push(current);
				dfs_s.push(next);
				break;		//���� current�� stack�� �ֻ�� ���, �� �̹��� �湮�� ��尡 �ȴ�.
			}
		}
	}
}
*/

/* DFS ����Լ� ���
void dfs(int start, vector<vector<int>> graph, bool check[]) 
{
	check[start] = true;	//���� ��� �湮
	cout << start << " ";
	
	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];		//������ ��� Ž��
		if (check[next] == false) {
			//�湮���� �ʾҴٸ� ����Լ� ȣ��
			dfs(next, graph, check);
		}
	}
}*/

/*
int main(void)
{
	int n, m, start;
	cin >> n >> m; // node edge�� ������ �Է¹���

	//graph ����
	vector<vector<int>> graph;
	vector<int> edge;
	for (int i = 0; i < n + 1; i++)	//index 0�� ��� ����. node ��ȣ 1���� ����.
		graph.push_back(edge);

	bool* check = new bool[n + 1];		//Ž�� ���θ� ��Ÿ���� �迭
	for (int i = 0; i < n + 1; i++)
		check[i] = false;

	//edge �Է�
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);    //�����
	}

	//Ž���� node ������� �� ��� ���. algorithm ����� sort or �����Լ� ���� ���
	for (int i = 1; i < n + 1; i++)
		sort(graph[i].begin(), graph[i].end());

	//start
	cout << endl << "start node : ";
	cin >> start;
	bfs(start, graph, check);

	return 0;
}*/

/* �׷��� ���� �Է� */
int main(void)
{
	int n, m;
	cin >> n >> m; // node edge�� ������ �Է¹���

	//graph ����
	vector<vector<int>> graph;
	vector<int> edge;
	for (int i = 0; i < n + 1; i++)	//index 0�� ��� ����. node ��ȣ 1���� ����.
		graph.push_back(edge);

	//edge �Է�
	for (int i = 0; i < m; i++) {
		int u, v;
		//scanf("%d %d", &u, &v);
		cin >> u >> v;
		graph[u].push_back(v);
		//graph[v].push_back(u);    //�� ���� ������� ��
	}

	 for(int i = 1; i < 6; i++){
    	cout << i << " - ";
    	for (auto iter = graph[i].begin(); iter != graph[i].end(); iter++)
			cout << *iter << " ";	//ex node 1�� ��� 3 5
		cout << endl;
    }

	return 0;
}
