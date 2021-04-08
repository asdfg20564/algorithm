#include <iostream>
#include<cstdlib> //rand(), srand()
#include<ctime> //time(), clock()
using namespace std;

void selection_sort(int arr[], int n) 
{
	for (int i = 0; i < n; i++) {
		int min = i;		//최솟값
		int temp;
		for (int j = i; j < n; j++) {
			//i ~ n까지 정렬되지 않은 배열 중 가장 최솟값이 어디있는지 탐색
			if (arr[j] < arr[min])
				min = j;
		}
		//i번째 값과 최솟값을 swap
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}


void insertion_sort(int arr[], int n)
{
	for (int i = 1; i < n; i++) {		//0번째 index는 이미 정렬됐기 때문에 1부터 시작
		int key = arr[i];				//삽입할 원소
		int j;							//현재 위치 저장

		//삽입할 원소 앞에서부터 배열의 맨 앞까지 차례대로 검사
		for (j = i - 1; j >= 0; j--) {
			//key값보다 크다면 하나씩 뒤로 밀어준다.
			if (arr[j] > key)
				arr[j + 1] = arr[j];

			//key값보다 작거나 같아지면 탈출
			else
				break;
		}

		//현재 위치에 key값을 넣는다. (반복문 돌며 --가 됐기 때문에 다시 +1을 해준다)
		arr[j + 1] = key;
	}
}


void quick_sort(int arr[], int start, int end)
{
	if (start >= end)			//재귀함수 종료 조건
		return;

	int pivot = start;			//pivot 설정
	int left = start + 1;
	int right = end;

	while (left <= right) {
		//left에서 arr[pivot]보다 큰 값 찾기 
		while (left < end && arr[left] < arr[pivot])
			left++;
		//right에서 arr[pivot]보다 작은 값 찾기
		while (right > start && arr[right] >= arr[pivot])
			right--;

		if (left < right) {
			//left와 right의 두 값 swqp
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
		else {
			//pivot과 더 작은 값인 right를 swap
			int temp = arr[pivot];
			arr[pivot] = arr[right];
			arr[right] = temp;
		}
	}

	//right를 기준으로 양 옆의 array를 재귀적으로 quick sort 진행
	quick_sort(arr, start, right - 1);
	quick_sort(arr, right + 1, end);
}


void merge_sort(int arr[], int n)
{
	//크기가 큰 배열이면 두 개의 작은 배열로 나누기
	if (n > 2) {
		merge_sort(arr, n / 2);
		merge_sort(arr + (n / 2), n - (n / 2));

		//merge
		int left = 0, right = n / 2, i = 0;
		int *buff = new int[n];
		
		while (left < n / 2 && right < n) {
			//더 작은 값을 버퍼에 넣으며 다음 값을 계속 비교한다.
			if (arr[left] < arr[right])
				buff[i++] = arr[left++];
			else
				buff[i++] = arr[right++];
		}

		//while문이 종료되어도 아직 배열에 남아있는 큰 값들을 전부 그 뒤에 넣는다.
		//left와 right에 있는 작은 두 배열들은 각각 정렬되어있기 때문에 순서대로 집어넣어도 된다.
		while (left < n / 2)
			buff[i++] = arr[left++];
		while (right < n)
			buff[i++] = arr[right++];

		//임시배열에 저장된 정렬된 배열을 원래 배열에 다시 저장
		memcpy(arr, buff, sizeof(int) * n);
	}
	//n이 2보다 작으면 아무 동작하지 않고 종료.
	//n이 2일 때
	else if (n == 2) {
		//두 값을 비교하여 swap으로 정렬
		//n = 2일 때는 swap으로 정렬하는 것이 더 빠르다.
		if (arr[0] > arr[1]) {
			int temp = arr[0];
			arr[0] = arr[1];
			arr[1] = temp;
		}
	}
}

/*
int main(void)
{

	int arr[10] = { 5, 7, 1, 2, 6, 3, 9, 4, 0, 4  };
	int n = 10;


	cout << "정렬 전 : ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	
	merge_sort(arr, n);			//정렬 함수

	cout << "정렬 후 : ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	
	return 0;
}
*/

//random 값으로 만든 배열 시간 측정
int main(void)
{
	srand((unsigned int)time(NULL)); //seed값으로 현재시간 부여
	int arr[50000] = { 0, };
	int n = 50000;
	clock_t start, end, res;

	//arr에 random한 난수로 초기화
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 50000;
	int selection_arr[50000];
	int insertion_arr[50000];
	int quick_arr[50000];
	int merge_arr[50000];

	memcpy(selection_arr, arr, sizeof(arr));
	memcpy(insertion_arr, arr, sizeof(arr));
	memcpy(quick_arr, arr, sizeof(arr));
	memcpy(merge_arr, arr, sizeof(arr));

	for (int i = 0; i < 200; i++) {
		if (i % 20 == 19)
			cout << selection_arr[i] << endl;
		else
			cout << selection_arr[i] << " ";
	}
	cout << endl << endl;

	start = clock();			//시간 측정 시작

	selection_sort(selection_arr, n);				//정렬 함수

	end = clock();				//시간 측정 종료

	//정렬하는데 걸린 시간 출력 (단위 : ms)
	cout << "selection : " << (double)(end - start) << "ms" << endl;

	start = clock();
	insertion_sort(insertion_arr, n);
	end = clock();

	cout << "insertion : " << (double)(end - start) << "ms" << endl;

	start = clock();
	quick_sort(quick_arr, 0, n-1);
	end = clock();

	cout << "quick : " << (double)(end - start) << "ms" << endl;

	start = clock();
	merge_sort(merge_arr, n);
	end = clock();

	cout << "merge : " << (double)(end - start) << "ms" << endl << endl;

	for (int i = 0; i < 200; i++) {
		if (i % 20 == 19)
			cout << selection_arr[i] << endl;
		else
			cout << selection_arr[i] << " ";
	}
	cout << endl << endl;

	for (int i = 0; i < 200; i++) {
		if (i % 20 == 19)
			cout << insertion_arr[i] << endl;
		else
			cout << insertion_arr[i] << " ";
	}
	cout << endl << endl;

	for (int i = 0; i < 200; i++) {
		if (i % 20 == 19)
			cout << quick_arr[i] << endl;
		else
			cout << quick_arr[i] << " ";
	}
	cout << endl << endl;

	for (int i = 0; i < 200; i++) {
		if (i % 20 == 19)
			cout << merge_arr[i] << endl;
		else
			cout << merge_arr[i] << " ";
	}
	cout << endl << endl;

	return 0;
}