#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int k, num;
	cin >> k;

	stack<int> s;

	while (k--) {
		cin >> num;

		//0인 경우 최근에 쓴 수 지움
		if (num == 0) {
			s.pop();
		}
		//0이 아닌 경우 해당 수 씀
		else {
			s.push(num);
		}
	}

	//연산
	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}

	//출력
	cout << sum;

	return 0;
}