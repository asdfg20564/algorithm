/*
n(��) * m(��) ���·� ������ ���� ī�忡�� � �࿡�� ���� ���� ���� �̴µ� �� �� ���� ���� ���� ���� ���̵��� �ض�. .
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