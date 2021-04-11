#include <iostream>
using namespace std;

/*int binary_search(int arr[], int find, int n)
{
	int start = 0, end = n - 1;

	while (start <= end) {
		int mid = (start + end) / 2;	// 소수점 버림
		//값이 존재할 때 인덱스 return
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

	return -1;					//값이 존재한다면 해당 값의 인덱스를, 아니면 -1을 return
}*/

int binary_search(int arr[],int find,int start, int end)
{
	if (start > end)
		return -1;					//존재하지 않음
	int mid = (start + end) / 2;	// 소수점 버림
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
	cout << "배열 원소 : ";
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " " ;
	}
	cout << endl << "찾을 원소 : " << find << endl;

	res = binary_search(arr, find, 0, n - 1);

	if (res == -1)
		cout << "해당 원소는 존재하지 않습니다." << endl;
	else
		cout << "해당 원소는 인덱스 " << res << "에 있습니다." << endl;

	return 0;
}