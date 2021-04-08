#include <iostream>
#include<cstdlib> //rand(), srand()
#include<ctime> //time(), clock()
using namespace std;

void selection_sort(int arr[], int n) 
{
	for (int i = 0; i < n; i++) {
		int min = i;		//�ּڰ�
		int temp;
		for (int j = i; j < n; j++) {
			//i ~ n���� ���ĵ��� ���� �迭 �� ���� �ּڰ��� ����ִ��� Ž��
			if (arr[j] < arr[min])
				min = j;
		}
		//i��° ���� �ּڰ��� swap
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}


void insertion_sort(int arr[], int n)
{
	for (int i = 1; i < n; i++) {		//0��° index�� �̹� ���ĵƱ� ������ 1���� ����
		int key = arr[i];				//������ ����
		int j;							//���� ��ġ ����

		//������ ���� �տ������� �迭�� �� �ձ��� ���ʴ�� �˻�
		for (j = i - 1; j >= 0; j--) {
			//key������ ũ�ٸ� �ϳ��� �ڷ� �о��ش�.
			if (arr[j] > key)
				arr[j + 1] = arr[j];

			//key������ �۰ų� �������� Ż��
			else
				break;
		}

		//���� ��ġ�� key���� �ִ´�. (�ݺ��� ���� --�� �Ʊ� ������ �ٽ� +1�� ���ش�)
		arr[j + 1] = key;
	}
}


void quick_sort(int arr[], int start, int end)
{
	if (start >= end)			//����Լ� ���� ����
		return;

	int pivot = start;			//pivot ����
	int left = start + 1;
	int right = end;

	while (left <= right) {
		//left���� arr[pivot]���� ū �� ã�� 
		while (left < end && arr[left] < arr[pivot])
			left++;
		//right���� arr[pivot]���� ���� �� ã��
		while (right > start && arr[right] >= arr[pivot])
			right--;

		if (left < right) {
			//left�� right�� �� �� swqp
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
		else {
			//pivot�� �� ���� ���� right�� swap
			int temp = arr[pivot];
			arr[pivot] = arr[right];
			arr[right] = temp;
		}
	}

	//right�� �������� �� ���� array�� ��������� quick sort ����
	quick_sort(arr, start, right - 1);
	quick_sort(arr, right + 1, end);
}


void merge_sort(int arr[], int n)
{
	//ũ�Ⱑ ū �迭�̸� �� ���� ���� �迭�� ������
	if (n > 2) {
		merge_sort(arr, n / 2);
		merge_sort(arr + (n / 2), n - (n / 2));

		//merge
		int left = 0, right = n / 2, i = 0;
		int *buff = new int[n];
		
		while (left < n / 2 && right < n) {
			//�� ���� ���� ���ۿ� ������ ���� ���� ��� ���Ѵ�.
			if (arr[left] < arr[right])
				buff[i++] = arr[left++];
			else
				buff[i++] = arr[right++];
		}

		//while���� ����Ǿ ���� �迭�� �����ִ� ū ������ ���� �� �ڿ� �ִ´�.
		//left�� right�� �ִ� ���� �� �迭���� ���� ���ĵǾ��ֱ� ������ ������� ����־ �ȴ�.
		while (left < n / 2)
			buff[i++] = arr[left++];
		while (right < n)
			buff[i++] = arr[right++];

		//�ӽù迭�� ����� ���ĵ� �迭�� ���� �迭�� �ٽ� ����
		memcpy(arr, buff, sizeof(int) * n);
	}
	//n�� 2���� ������ �ƹ� �������� �ʰ� ����.
	//n�� 2�� ��
	else if (n == 2) {
		//�� ���� ���Ͽ� swap���� ����
		//n = 2�� ���� swap���� �����ϴ� ���� �� ������.
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


	cout << "���� �� : ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	
	merge_sort(arr, n);			//���� �Լ�

	cout << "���� �� : ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	
	return 0;
}
*/

//random ������ ���� �迭 �ð� ����
int main(void)
{
	srand((unsigned int)time(NULL)); //seed������ ����ð� �ο�
	int arr[50000] = { 0, };
	int n = 50000;
	clock_t start, end, res;

	//arr�� random�� ������ �ʱ�ȭ
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

	start = clock();			//�ð� ���� ����

	selection_sort(selection_arr, n);				//���� �Լ�

	end = clock();				//�ð� ���� ����

	//�����ϴµ� �ɸ� �ð� ��� (���� : ms)
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