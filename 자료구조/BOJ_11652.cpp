#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;

const ll MAX = 1e20;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	ll num, ans = MAX;
	cin >> n;

	int max_cnt = 0;
	unordered_map<ll, int> card;
	for (int i = 0; i < n; i++) {
		cin >> num;

		//연산
		//num이 이미 map에 존재하는 경우
		if (card.count(num)) {
			card[num]++;
		}
		//존재하지 않는 경우
		else {
			card.insert({ num, 1 });
		}

		//최대 카드로 갱신
		if (card[num] > max_cnt) {
			max_cnt = card[num];
			ans = num;
		}
		//가장 많이 가지고 있는 정수가 여러개인 경우 작은 것 채택
		else if (card[num] == max_cnt) {
			ans = min(ans, num);
		}
	}

	//출력
	cout << ans;

	return 0;
}