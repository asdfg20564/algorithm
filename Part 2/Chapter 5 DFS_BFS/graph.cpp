#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

/* BFS Queue 사용
void bfs(int start, vector<vector<int>> graph, bool check[]) 
{
	queue<int> bfs_q;

	bfs_q.push(start);			//시작 노드 queue에 삽입
	check[start] = true;		//시작 노드 방문

	while (!bfs_q.empty()) {
		int current = bfs_q.front();
		bfs_q.pop();
		cout << current << " ";

		for (int i = 0; i < graph[current].size(); i++) {
			//현재 노드에서 방문하지 않은 모든 인접한 노드를 queue에 넣고 방문한다.
			if (check[graph[current][i]] == false) {
				bfs_q.push(graph[current][i]);
				check[graph[current][i]] = true;
			}
		}
	}
}*/

/* DFS stack 사용
void dfs(int start, vector<vector<int>> graph, bool check[]) 
{
	stack<int> dfs_s;
	dfs_s.push(start);		//시작 노드 stack에 삽입
	check[start] = true;	//시작 노드 방문
	cout << start << " ";

	while (!dfs_s.empty()) {
		int current = dfs_s.top();		//현재 위치의 노드
		dfs_s.pop();

		for (int i = 0; i < graph[current].size(); i++) {

			int next = graph[current][i];

			//DFS의 동작 : 인접노드에서 방문하지 않는 노드일 경우 stack에 넣어준다..
			if (check[next] == false) {
				cout << next << " ";
				check[next] = true;
				//pop()을 했었기 때문에 현재 current도 다시 넣어줘야한다.
				dfs_s.push(current);
				dfs_s.push(next);
				break;		//다음 current가 stack의 최상단 노드, 즉 이번에 방문한 노드가 된다.
			}
		}
	}
}
*/

/* DFS 재귀함수 사용
void dfs(int start, vector<vector<int>> graph, bool check[]) 
{
	check[start] = true;	//시작 노드 방문
	cout << start << " ";
	
	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];		//인접한 노드 탐색
		if (check[next] == false) {
			//방문하지 않았다면 재귀함수 호출
			dfs(next, graph, check);
		}
	}
}*/

/*
int main(void)
{
	int n, m, start;
	cin >> n >> m; // node edge의 개수를 입력받음

	//graph 생성
	vector<vector<int>> graph;
	vector<int> edge;
	for (int i = 0; i < n + 1; i++)	//index 0은 사용 안함. node 번호 1부터 시작.
		graph.push_back(edge);

	bool* check = new bool[n + 1];		//탐색 여부를 나타내는 배열
	for (int i = 0; i < n + 1; i++)
		check[i] = false;

	//edge 입력
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);    //양방향
	}

	//탐색을 node 순서대로 할 경우 사용. algorithm 헤더의 sort or 정렬함수 만들어서 사용
	for (int i = 1; i < n + 1; i++)
		sort(graph[i].begin(), graph[i].end());

	//start
	cout << endl << "start node : ";
	cin >> start;
	bfs(start, graph, check);

	return 0;
}*/

/* 그래프 선언 입력 */
int main(void)
{
	int n, m;
	cin >> n >> m; // node edge의 개수를 입력받음

	//graph 생성
	vector<vector<int>> graph;
	vector<int> edge;
	for (int i = 0; i < n + 1; i++)	//index 0은 사용 안함. node 번호 1부터 시작.
		graph.push_back(edge);

	//edge 입력
	for (int i = 0; i < m; i++) {
		int u, v;
		//scanf("%d %d", &u, &v);
		cin >> u >> v;
		graph[u].push_back(v);
		//graph[v].push_back(u);    //이 경우는 양방향일 때
	}

	 for(int i = 1; i < 6; i++){
    	cout << i << " - ";
    	for (auto iter = graph[i].begin(); iter != graph[i].end(); iter++)
			cout << *iter << " ";	//ex node 1의 결과 3 5
		cout << endl;
    }

	return 0;
}
