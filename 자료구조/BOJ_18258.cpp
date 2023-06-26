#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, x;
	string op;
	cin >> n;

	deque<int> dq;

	while (n--) {
		//입력
		cin >> op;

		//연산 & 출력
		if (op == "push") {
			cin >> x;
			dq.push_back(x);
		}
		else if (op == "pop") {
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (op == "size") {
			cout << dq.size() << "\n";
		}
		else if (op == "empty") {
			if (dq.empty()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (op == "front") {
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.front() << "\n";
			}
		}
		else if (op == "back") {
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.back() << "\n";
			}
		}
	}

	return 0;
}