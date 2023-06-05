#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1e6;

int getMin(string n) {
	vector<int> num_cnt(10, 0); //num_cnt[i]: 숫자 i가 사용된 횟수
	for (int i = 0; i < n.size(); i++) {
		num_cnt[n[i] - '0']++;
	}

	//6과 9를 뒤집어서 사용할 수 있음
	int cnt69 = ceil((num_cnt[6] + num_cnt[9]) / 2.0);
	num_cnt[6] = cnt69, num_cnt[9] = cnt69;

	int ans = 0; //필요한 세트의 개수의 최솟값
	for (int i = 0; i < 10; i++) {
		ans = max(ans, num_cnt[i]);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	string n;
	cin >> n;

	//연산 & 출력
	cout << getMin(n);

	return 0;
}