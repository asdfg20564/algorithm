/*
n*m �������� ������ ĭ�� ���� �Ǵ� �ٴ��̰�, ĳ���ʹ� �������� �� �� ���� �ٶ󺻴�. ĭ�� (A,B)�� ��Ÿ���� ĳ���ʹ� �����¿�� �����̸� �ٴٴ� �� �� ����.
���� ������ �������� �ݽð� �������� 90�� ȸ���� ������� �� ���� ���ϴµ� ���� ������ �ʴ� ĭ�� �����Ѵٸ� ȸ���ϰ� �����ϰ� 
�ƴϸ� ȸ���� �� �� �ٽ� Ž���Ѵ�. �� ���� ��� �����ų� �ٴ��̸� �ٶ󺸴� ������ ������ ä �ڷ� �� ĭ �� �� �ٽ� Ž���Ѵ�. �ڰ� �ٴٶ�� �������� �����Ѵ�.
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

	//1�� �ٴ� 0�� ���� �ܰ��� �׻� �ٴ�
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

			//�� �ܰ��� �׻� �ٴ��̱� ������ �� ������ �ʿ���� �� ����
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