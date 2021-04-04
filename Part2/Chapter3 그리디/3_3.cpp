/*
n(행) * m(열) 형태로 놓아진 숫자 카드에서 어떤 행에서 가장 작은 수를 뽑는데 그 때 뽑힌 수가 가장 높은 수이도록 해라. .
*/
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	
	int* arr = new int[m];
	
	int result = 0;

	for (int i = 0; i < n; i++) {
		int min = 10001;
		for (int j = 0; j < m; j++)
		{
			cin >> arr[j];
			if (min > arr[j])
				min = arr[j];
		}
		if (result < min)
			result = min;
	}
	
	cout << result;

	delete[] arr;

	return 0;
}