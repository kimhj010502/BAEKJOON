#include <iostream>
#include <vector>

using namespace std;

//행렬의 곱셈 반환
vector<vector<int>> multipleMatrix(int n, int m, int k, vector<vector<int>>& matrixA, vector<vector<int>>& matrixB) {
	vector<vector<int>> result(n, vector<int>(k));
	for (int t = 0; t < m; t++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				result[i][j] += (matrixA[i][t] * matrixB[t][j]);
			}
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m, k;

	//행렬 A 입력
	cin >> n >> m;
	vector<vector<int>> matrixA(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrixA[i][j];
		}
	}

	//행렬 B 입력
	cin >> m >> k;
	vector<vector<int>> matrixB(m, vector<int>(k));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> matrixB[i][j];
		}
	}

	//연산
	vector<vector<int>> result = multipleMatrix(n, m, k, matrixA, matrixB);

	//출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}