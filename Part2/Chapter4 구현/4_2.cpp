/*
0�ú��� N�� 59�� 59�ʱ��� �ð� ���̿��� 3�� �ϳ��� ���ԵǴ� ��� ����� ���� ���Ѵ�. 0<n<24
*/

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int n, res = 0;
	cin >> n;

	for (int i = 0; i < n+1; i++){
		for (int j = 0; j < 60; j++) {
			for (int k = 0; k < 60; k++) {
				string temp = to_string(i) + to_string(j) + to_string(k);
				if (temp.find("3") != string::npos)
					res++;
			}
		}
	}

	cout << res;

	return 0;
}
