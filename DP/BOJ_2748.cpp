#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

//n번째 피보나치 수 반환
ll fibonacci(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}

	vector<ll> v(n + 1, 0);
	v[0] = 0; v[1] = 1;
	for (int i = 2; i <= n; i++) {
		v[i] = v[i - 1] + v[i - 2];
	}
	return v[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	//연산 & 출력
	cout << fibonacci(n);

	return 0;
}