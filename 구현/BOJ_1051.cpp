#include <iostream>
#include <vector>

using namespace std;

//정사각형의 크기 반환
int getSize(int n, int m, vector<vector<int>>& square) {
	int square_size = min(n, m); //정사각형의 최대 크기
	int max_size = 1;

	//k: 정사각형의 크기
	//정사각형의 크기를 줄여가면서 탐색하므로 처음으로 찾아지는 정사각형이 최대 크기의 정사각형임
	for (int k = square_size - 1; k > 0; k--) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				//범위를 벗어난 경우 넘어감
				if ((i + k >= n) || (j + k >= m)) {
					continue;
				}
				
				int num = square[i][j];
				if (square[i + k][j] == num && square[i][j + k] == num && square[i + k][j + k] == num) {
					max_size = k + 1;
					return max_size * max_size;
				}
			}
		}
	}
	return max_size * max_size;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m;
	cin >> n >> m;

	string s;
	vector<vector<int>> square(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			square[i][j] = s[j] - '0';
		}
	}

	//연산 & 출력
	cout << getSize(n, m, square);

	return 0;
}