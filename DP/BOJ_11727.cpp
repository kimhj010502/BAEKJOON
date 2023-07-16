#include <iostream>
#include <vector>

using namespace std;

const int MOD = 10007;

//2xn 크기의 직사각형을 채우는 방법 반환
int getMethod(int n) {
	vector<int> tile(n + 1); //tile[i]: 2xi 크기의 직사각형을 채우는 방법
	tile[1] = 1; tile[2] = 3; //초기화
	for (int i = 3; i <= n; i++) {
		tile[i] = (tile[i - 1] + 2 * tile[i - 2]) % MOD;
	}
	return tile[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	//연산 & 출력
	cout << getMethod(n);

	return 0;
}