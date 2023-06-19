#include <iostream>
#include <vector>

using namespace std;

int increase(int n, vector<int>& number) {
	vector<int> dp(n); //dp[i]: 증가하는 수열의 최대 길이
	dp[0] = 1;

	int max_length = 1;
	for (int i = 1; i < n; i++) {
		if (number[i] >= number[i - 1]) {
			dp[i] = dp[i - 1] + 1;
		}
		else {
			dp[i] = 1;
		}
		max_length = max(max_length, dp[i]);
	}
	return max_length;
}

int decrease(int n, vector<int>& number) {
	vector<int> dp(n); //dp[i]: 감소하는 수열의 최대 길이
	dp[0] = 1;

	int max_length = 1;
	for (int i = 1; i < n; i++) {
		if (number[i]<= number[i - 1]) {
			dp[i] = dp[i - 1] + 1;
		}
		else {
			dp[i] = 1;
		}
		max_length = max(max_length, dp[i]);
	}
	return max_length;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n; 
	cin >> n;

	vector<int> number(n);
	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}

	//연산 & 출력
	cout << max(increase(n, number), decrease(n, number));

	return 0;
}