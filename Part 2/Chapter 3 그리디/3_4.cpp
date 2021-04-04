/*
자연수 n(2이상) 이 1이 될 떄까지 n에서 1을 빼거나 나뉘어질 때 k로 나누어 n을 1로 만들자.
*/
#include <iostream>
using namespace std;

int main(void)
{
	int n, k, res = 0;
	cin >> n >> k;

	while (n != 1)
	{
		if (n == 1)
			break;
		if (n == 0){
			n += 1;
			res -= 1;
			break;
		}
		if (n % k == 0){
			n /= k;
			res += 1;
		}
		else {
			int temp = n % k;
			n -= temp;
			res += temp;
		}
	}
	cout << res;
	return 0;
}