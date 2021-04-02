/*
n*m 공간에서 각각의 칸은 육지 또는 바다이고, 캐릭터는 동서남북 중 한 곳을 바라본다. 칸은 (A,B)로 나타내며 캐릭터는 상하좌우로 움직이며 바다는 갈 수 없다.
현재 방향을 기준으로 반시계 방향으로 90도 회전한 방향부터 갈 곳을 정하는데 아직 가보지 않는 칸이 존재한다면 회전하고 전진하고 
아니면 회전만 한 뒤 다시 탐색한다. 네 방향 모두 가보거나 바다이면 바라보는 방향을 유지한 채 뒤로 한 칸 간 뒤 다시 탐색한다. 뒤가 바다라면 움직임을 정지한다.
*/
#include <iostream>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	int a, b, d, res = 0;

	int** arr = new int*[n];
	int** visited = new int* [n];
	for (int i = 0; i < n; i++){
		arr[i] = new int[m];
		visited[i] = new int[m];
	}
	
	cin >> a >> b >> d;

	//1은 바다 0은 육지 외곽은 항상 바다
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
			cin >> arr[i][j];
			visited[i][j] = 0;
		}
	}
	visited[b][a] = 1;

	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { -1,0,1,0 };

	while (1){
		int move_try = 0;
		int new_d, after_a, after_b;

		for (move_try; move_try < 4; move_try++) {
			new_d = (d + move_try + 1) % 4;
			after_a = a + dy[new_d];
			after_b = b + dx[new_d];

			//맵 외곽이 항상 바다이기 때문에 이 조건은 필요없을 거 같음
			//if (after_a < 0 || after_a > m || after_b < 0 || after_b > n)
			//	continue;

			if (arr[after_a][after_b] == 1)
				continue;
			else if (visited[after_a][after_b] == 1)
				continue;
			else
				break;
		}

		if (move_try == 4) {
			after_a = a - dy[d];
			after_b = a - dx[d];
			if (arr[after_a][after_b] == 1)
				break;
		}

		a = after_a;
		b = after_b;
		d = new_d;
		visited[a][b] = 1;
		res++;
	}

	cout << res;

	return 0;
}