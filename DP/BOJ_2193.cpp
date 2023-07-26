#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;

//n자리 이친수의 개수 반환
ll cntPrinaryNumber(int n) {
	if (n <= 2) {
		return 1;
	}
	if (n == 3) {
		return 2;
	}

	vector<pl> dp(n + 1); //dp[i]: i자리 이친수의 개수 {0으로 끝나는 이천수의 개수, 1으로 끝나는 이천수의 개수}
	dp[1] = { 0,1 };
	dp[2] = { 0,1 };
	dp[3] = { 1,1 };

	for (int i = 4; i <= n; i++) {
		dp[i] = { dp[i - 1].first + dp[i - 1].second, dp[i - 1].first };
	}
	return dp[n].first + dp[n].second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	//연산 & 출력
	cout << cntPrinaryNumber(n);

	return 0;
}