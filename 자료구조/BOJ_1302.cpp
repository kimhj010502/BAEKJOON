#include <iostream>
#include <map>

using namespace std;

//맵 정렬
bool cmp(const pair<string, int>& b1, const pair<string, int>& b2) {
	//책이 많이 팔린 순서대로 정렬
	if (b1.second != b2.second) {
		return b1.second > b2.second;
	}
	//책 이름 사전 순으로 정렬
	return b1.first < b2.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	string s;
	cin >> n;

	map<string, int> book; //{책 이름, 팔린 권수}
	pair<string, int> ans = { "-1", 0 }; //가장 많이 팔린 책 초기화

	while (n--) {
		//입력
		cin >> s;

		//연산
		//처음 팔린 책
		if (book.find(s) == book.end()) {
			book[s] = 1;

			//처음 책을 가장 많이 팔린 책으로 초기화
			if (ans.first == "-1") {
				ans = { s, book[s] };
			}
		}
		//팔린적이 있는 책
		else {
			book[s]++;
		}

		//가장 많이 팔린 책을 사전순으로 갱신
		if (book[s] > ans.second || (book[s] == ans.second && s < ans.first)) {
			ans = { s, book[s] };
		}
	}

	//출력
	cout << ans.first;

	return 0;
}