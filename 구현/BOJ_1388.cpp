#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int dx[2] = { 0,1 };
int dy[2] = { 1,0 };

//필요한 나무 판자의 개수 반환
int cntTiles(int n, int m, vector<vector<char>>& tiles) {
	vector<vector<int>> number(n, vector<int>(m, 0)); //number[i][j]: (i,j)번째 타일의 나무 판자 번호
	vector<vector<bool>> visited(n, vector<bool>(m, false)); //visited[i][j]: (i,j)번째 타일의 방문 여부

	//큐 초기화
	queue<ii> q;
	q.push({ 0,0 });
	number[0][0] = 1;

	int x, y, nx, ny, d, max_num = 1;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		//이미 탐색한 칸인 경우 넘어감
		if (visited[x][y]) {
			continue;
		}
		visited[x][y] = true;

		//0인 경우 (아직 채워지지 않은 경우)
		if (!number[x][y]) {
			number[x][y] = ++max_num;
		}

		d = 0; //- 모양의 타일인 경우
		//| 모양의 타일인 경우
		if (tiles[x][y] == '|') {
			d = 1;
		}

		//오른쪽, 아래 방향 탐색
		for (int i = 0; i < 2; i++) {
			nx = x + dx[i];
			ny = y + dy[i];

			//범위를 벗어나거나 이미 방문한 경우 넘어감
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) {
				continue;
			}

			//같은 방향으로 이웃한 타일인 경우
			if (i == d) {
				//모양이 같은 경우 같은 나무 판자 사용
				if (tiles[nx][ny] == tiles[x][y]) {
					number[nx][ny] = number[x][y];
				}
			}

			q.push({ nx,ny });
		}
	}
	return max_num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m;
	cin >> n >> m;

	vector<vector<char>> tiles(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tiles[i][j];
		}
	}

	//연산 & 출력
	cout << cntTiles(n, m, tiles);

	return 0;
}