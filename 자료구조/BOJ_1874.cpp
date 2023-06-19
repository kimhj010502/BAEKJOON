#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

//입력된 수열을 만들기 위해 필요한 연산 벡터 반환
vector<char> getOperation(int n, queue<int>& q) {
	vector<char> op;
	stack<int> s;

	int i = 1;

	while(!q.empty()) {
		//큐의 front()가 s.top()보다 크거나 같은 경우 push 연산
		if (s.empty() || q.front() >= s.top()) {
			//cout << i << "push\n";
			s.push(i++);
			op.push_back('+');
		}

		//큐의 front() 숫자와 s의 top() 숫자가 같은 경우 pop 연산
		while (!q.empty() && !s.empty() && q.front() == s.top()) {
			//cout << s.top() << "pop\n";
			s.pop();
			q.pop();
			op.push_back('-');
		}

		//s.top()이 q.front()보다 큰 경우 입력된 수열이 만들어질 수 없으므로 NO 반환
		if (!q.empty() && !s.empty() && q.front() < s.top()) {
			return { 'N' };
		}
	}
	return op;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, number;
	cin >> n;

	queue<int> q;
	for (int i = 0; i < n; i++) {
		cin >> number;
		q.push(number);
	}

	//연산
	vector<char> op = getOperation(n, q);

	//출력
	if (op[0] == 'N') {
		cout << "NO";
	}
	else {
		for (int i = 0; i < op.size(); i++) {
			cout << op[i] << "\n";
		}
	}

	return 0;
}