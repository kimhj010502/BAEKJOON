#include <iostream>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int m, x;
	string op;
	cin >> m;

	set<int> s;
	set<int> s_all;
	for (int i = 1; i <= 20; i++) {
		s_all.insert(i);
	}

	while (m--) {
		//입력
		cin >> op;

		//연산
		if (op == "add") {
			cin >> x;
			s.insert(x);
		}
		else if (op == "remove") {
			cin >> x;
			s.erase(x);
		}
		else if (op == "check") {
			cin >> x;

			//출력
			cout << s.count(x) << "\n";
		}
		else if (op == "toggle") {
			cin >> x;

			//x가 있다면 x 제거
			if (s.count(x)) {
				s.erase(x);
			}
			//x가 없다면 x 추가
			else {
				s.insert(x);
			}
		}
		else if (op == "all") {
			s = s_all;
		}
		else if (op == "empty") {
			s.clear();
		}
	}

	return 0;
}