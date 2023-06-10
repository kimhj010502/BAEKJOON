#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

//누적합 2차 배열 반환
vector<vector<ll>> getSum(int n, int m, vector<vector<int>>& num) {
	vector<vector<ll>> sum_num(n + 1, vector<ll>(m + 1, 0));

	for (int i = 1; i <= n; i++) {
		sum_num[i][1] = num[i][1];
	}
	for (int j = 1; j <= m; j++) {
		sum_num[1][j] = num[1][j];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum_num[i][j] = sum_num[i - 1][j] + sum_num[i][j - 1] - sum_num[i - 1][j - 1] + num[i][j];
		}
	}
	return sum_num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, k, i, j, x, y;
	cin >> n >> m;

	vector<vector<int>> num(n + 1, vector<int>(m + 1));
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= m; c++) {
			cin >> num[r][c];
		}
	}

	//연산
	vector<vector<ll>> sum_num = getSum(n, m, num);

	cin >> k;
	while (k--) {
		//입력
		cin >> i >> j >> x >> y;

		//출력
		int ans = sum_num[x][y] - sum_num[i - 1][y] - sum_num[x][j - 1] + sum_num[i - 1][j - 1];
		cout << ans << "\n";
	}

	return 0;
}