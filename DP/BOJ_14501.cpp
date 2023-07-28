#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

//얻을 수 있는 최대 이익 반환
int maxProfit(int n, vector<ii>& consult) {
	int max_profit = 0; //최대 이익
	vector<int> dp(n + 1, 0); //dp[i]: i일에 상담을 했을 때 최대 이익

	for (int i = 1; i <= n; i++) {
		//i일에 시작하는 상담이 n+1일이 넘어가는 경우에는 상담 못함
		if (i + consult[i].first > n + 1) {
			continue;
		}
		dp[i] = max(dp[i], consult[i].second);

		for (int j = i + consult[i].first; j <= n; j++) {
			//j일에 시작하는 상담이 n+1일이 넘어가는 경우에는 상담 못함
			if (j + consult[j].first > n + 1) {
				continue;
			}
			dp[j] = max(dp[j], dp[i] + consult[j].second);
			
		}
		max_profit = max(max_profit, dp[i]);
	}
	return max_profit;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	vector<ii> consult(n + 1); //consult[i]: {상담을 완료하는데 걸리는 기간, 상담을 했을 때 받을 수 있는 금액}
	for (int i = 1; i <= n; i++) {
		cin >> consult[i].first >> consult[i].second;
	}

	//연산 & 출력
	cout << maxProfit(n, consult);

	return 0;
}