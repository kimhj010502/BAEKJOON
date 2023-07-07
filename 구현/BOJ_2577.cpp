#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

//A x B x C의 결과에 0~9가 각각 몇 번 쓰였는지를 담은 벡터 반환
vector<int> cntNumber(ll a, ll b, ll c) {
	ll result = a * b * c;
	string s = to_string(result);

	vector<int> cnt(10, 0);
	for (int i = 0; i < s.size(); i++) {
		cnt[s[i] - '0']++;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	ll a, b, c;
	cin >> a >> b >> c;

	//연산
	vector<int> cnt = cntNumber(a, b, c);

	//출력
	for (int i = 0; i < 10; i++) {
		cout << cnt[i] << "\n";
	}

	return 0;
}