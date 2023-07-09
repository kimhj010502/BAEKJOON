#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 101;

//네 개의 직사각형이 차지하는 면적 반환
int getArea(vector<vector<int>>& position) {
	int x1, x2, y1, y2;
	vector<vector<bool>> square(SIZE, vector<bool>(SIZE, false));

	//4개의 직사각형 위치 표시
	for (int k = 0; k < 4; k++) {
		x1 = position[k][0];
		y1 = position[k][1];
		x2 = position[k][2];
		y2 = position[k][3];

		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				square[i][j] = true;
			}
		}
	}

	int area = 0; //면적
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (square[i][j]) {
				area++;
			}
		}
	}
	return area;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int x1, x2, y1, y2;
	vector<vector<int>> position(4, vector<int>(4));
	for (int i = 0; i < 4; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		position[i] = { x1,y1,x2,y2 };
	}

	//연산 & 출력
	cout << getArea(position);

	return 0;
}