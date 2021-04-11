#include <iostream>
using namespace std;

/*int binary_search(int arr[], int find, int n)
{
	int start = 0, end = n - 1;

	while (start <= end) {
		int mid = (start + end) / 2;	// �Ҽ��� ����
		//���� ������ �� �ε��� return
		if (arr[mid] == find) {
			return mid;			
		}
		else if(arr[mid] < find) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	return -1;					//���� �����Ѵٸ� �ش� ���� �ε�����, �ƴϸ� -1�� return
}*/

int binary_search(int arr[],int find,int start, int end)
{
	if (start > end)
		return -1;					//�������� ����
	int mid = (start + end) / 2;	// �Ҽ��� ����
	if (arr[mid] == find)
		return mid;
	else if (arr[mid] < find) {
		return binary_search(arr, find, mid + 1, end);
	}
	else
		return binary_search(arr, find, start, mid - 1);
}
int main(void)
{
	int arr[10] = { 0,1,3,4,5,6,7,9,13,15 };
	int find = 17, n = 10, res;
	cout << "�迭 ���� : ";
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " " ;
	}
	cout << endl << "ã�� ���� : " << find << endl;

	res = binary_search(arr, find, 0, n - 1);

	if (res == -1)
		cout << "�ش� ���Ҵ� �������� �ʽ��ϴ�." << endl;
	else
		cout << "�ش� ���Ҵ� �ε��� " << res << "�� �ֽ��ϴ�." << endl;

	return 0;
}