/*
배열 크기 n에 주어진 수를 m번 더하여 가장 큰 수를 만든다. 단 한 숫자는 연속 k번을 초과하여 더할 수 없다.
*/
#include <iostream>
using namespace std;

int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;
	if (n < 2 || n > 1000)
		return 0;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	//sort
	for (int i = 0; i < n; i++) {
		int max = i;
		for (int j = i+1; j < n; j++) {
			int temp = arr[j];
			if (arr[max] < arr[j])
				max = j;
		}
		int temp = arr[i];
		arr[i] = arr[max];
		arr[max] = temp;
	}

	//find maximum sum result
	int first = arr[0];
	int second = arr[1];
	int res = 0;
	int k_temp = k;
	for (int i = 0; i < m; i++)
	{
		if (k_temp != 0){
			res += first;
			k_temp--;
		}
		else {
			res += second;
			k_temp = k;
		}
	}

	cout << res << endl;
	delete[] arr;
	return 0;
}
/*
답안지 버전
-> 반복되어 더해지는 부분을 한 번에 계산할 수 있도록 한다!
반복되는 구간 : K + 1 (k는 가장 큰 수 1은 두번째로 큰 수)
count = k * (m / (k + 1)) + m % (k + 1);
result += count * first;
result = (m - count) * second;
*/