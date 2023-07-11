#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//새로운 수의 자릿수 반환
int getNumber(int n) {
	//10보다 작은 숫자의 경우 n 반환
	if (n < 10) {
		return n;
	}

	int m = to_string(n).size(); //n의 자릿수
	int ans = 0; //새로운 수의 자릿수
	for (int i = 1; i < m; i++) {
		//i자리 숫자의 개수는 9 * 10^(i-1)개
		ans += i * (9 * pow(10, i - 1));
	}
	//m자리 숫자의 개수는 n - pow(10, m - 1) + 1개
	ans += m * (n - pow(10, m - 1) + 1);
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	//연산 & 출력
	cout << getNumber(n);

	return 0;
}