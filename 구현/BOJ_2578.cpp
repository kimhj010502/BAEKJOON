#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 5;

vector<vector<int>> board(SIZE, vector<int>(SIZE)); //빙고판
vector<bool> row(SIZE, false); //row[i]: i 열이 선이 그어졌는지의 여부
vector<bool> column(SIZE, false); //column[i]: i 행이 선이 그어졌는지의 여부
vector<bool> diagonal(2, false); //diagonal[i]: i 방향의 대각선이 선이 그어졌는지의 여부
int line = 0; //지워진 줄의 개수
bool check; //하나의 줄이 지워졌는지의 여부

//행 방향 확인
bool checkRow() {
	for (int i = 0; i < SIZE; i++) {
		//이미 지워져서 확인할 필요가 없는 행의 경우 넘어감
		if (row[i]) {
			continue;
		}

		check = true; 

		for (int j = 0; j < SIZE; j++) {
			//지워지지 않은 수가 있는 경우
			if (board[i][j] != -1) {
				check = false;
				break;
			}
		}

		//한 행이 다 지워진 경우
		if (check) {
			row[i] = true;
			line++;
		}

		//3개 이상 그어지면 빙고
		if (line >= 3) {
			return true;
		}
	}
	return false;
}

//열 방향 확인
bool checkColumn() {
	for (int i = 0; i < SIZE; i++) {
		//이미 지워져서 확인할 필요가 없는 열의 경우 넘어감
		if (column[i]) {
			continue;
		}

		check = true;

		for (int j = 0; j < SIZE; j++) {
			//지워지지 않은 수가 있는 경우
			if (board[j][i] != -1) {
				check = false;
				break;
			}
		}

		//한 열이 다 지워진 경우
		if (check) {
			column[i] = true;
			line++;
		}

		//3개 이상 그어지면 빙고
		if (line >= 3) {
			return true;
		}
	}
	return false;
}

//대각선 방향 확인
bool checkDiagonal() {
	//왼쪽 위 -> 오른쪽 아래 방향
	if (!diagonal[0]) { //이미 지워져서 확인할 필요가 없는 대각선의 경우 넘어감
		check = true;
		for (int i = 0; i < SIZE; i++) {
			//지워지지 않은 수가 있는 경우
			if (board[i][i] != -1) {
				check = false;
				break;
			}
		}

		//대각선이 다 지워진 경우
		if (check) {
			diagonal[0] = true;
			line++;
		}

		//3개 이상 그어지면 빙고
		if (line >= 3) {
			return true;
		}
	}

	//왼쪽 아래 -> 오른쪽 위 방향
	if (!diagonal[1]) { //이미 지워져서 확인할 필요가 없는 대각선의 경우 넘어감
		check = true;
		for (int i = 0; i < SIZE; i++) {
			//지워지지 않은 수가 있는 경우
			if (board[SIZE - 1 - i][i] != -1) {
				check = false;
				break;
			}
		}

		//대각선이 다 지워진 경우
		if (check) {
			diagonal[1] = true;
			line++;
		}

		//3개 이상 그어지면 빙고
		if (line >= 3) {
			return true;
		}
	}
	
	return false;
}

//빙고가 되었는지의 여부 반환
bool isBingo() {
	//행 방향 확인
	if (checkRow()) {
		return true;
	}

	//열 방향 확인
	if (checkColumn()) {
		return true;
	}

	//대각선 방향 확인
	if (checkDiagonal()) {
		return true;
	}

	return false;
}

//사회자가 부르는 숫자 빙고판에서 지움
void deleteNumber(int n) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == n) {
				board[i][j] = -1;
				return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	//빙고판 입력
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cin >> board[i][j];
		}
	}

	//숫자 입력
	vector<int> number(SIZE * SIZE + 1);
	for (int i = 1; i <= SIZE * SIZE; i++) {
		cin >> number[i];
	}
	
	//연산 & 출력
	for (int i = 1; i <= SIZE * SIZE; i++) {
		//해당 숫자 지우기
		deleteNumber(number[i]);

		//빙고인 경우 몇번째 수인지 출력
		if (isBingo()) {
			cout << i;
			break;
		}
	}

	return 0;
}