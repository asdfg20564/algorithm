/*
�迭 ũ�� n�� �־��� ���� m�� ���Ͽ� ���� ū ���� �����. �� �� ���ڴ� ���� k���� �ʰ��Ͽ� ���� �� ����.
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
����� ����
-> �ݺ��Ǿ� �������� �κ��� �� ���� ����� �� �ֵ��� �Ѵ�!
�ݺ��Ǵ� ���� : K + 1 (k�� ���� ū �� 1�� �ι�°�� ū ��)
count = k * (m / (k + 1)) + m % (k + 1);
result += count * first;
result = (m - count) * second;
*/