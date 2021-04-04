/*
0시부터 N시 59분 59초까지 시각 사이에서 3이 하나라도 포함되는 모든 경우의 수를 구한다. 0<n<24
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
