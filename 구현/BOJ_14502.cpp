#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n, m;
vector<vector<int>> map;
queue<ii> q_virus; //바이러스가 있는 위치 저장
int max_size = 0; //안전 영역 크기의 최댓값

//바이러스가 퍼질 수 없는 안전 영역의 크기 반환
int cntSafezone() {
	vector<vector<int>> virus_map = map; //바이러스가 퍼졌을 때의 지도
	queue<ii> q = q_virus; //바이러스가 있는 위치

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//상하좌우 4개 방향으로 바이러스 퍼짐
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			//이웃한 칸에 바이러스가 없다면 바이러스 퍼뜨림
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && virus_map[nx][ny] == 0) {
				virus_map[nx][ny] = 2;
				q.push({ nx,ny });
			}
		}
	}

	int cnt = 0; //바이러스가 퍼지지 않은 안전 영역의 크기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (virus_map[i][j] == 0) {
				cnt++;
			}
		}
	}
	return cnt;
}

//백트래킹으로 안전 영역 크기의 최댓값 구하기
//wall: 지금까지 설치한 벽의 개수, index: 이전에 설치한 벽의 위치
void backtrack(int wall, int index) {
	//종료 조건: 벽을 3개 설치한 경우
	if (wall == 3) {
		int size = cntSafezone();
		max_size = max(max_size, size);
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//이전에 설치한 벽의 위치의 좌표보다 큰 부분만 탐색
			if (i * n + j < index) {
				continue;
			}

			//비어있는 곳이 아니면 벽 설치할 수가 없으므로 넘어감
			if (map[i][j] != 0) {
				continue;
			}

			//사용
			map[i][j] = 1;

			//다음 벽 설치
			backtrack(wall + 1, i * n + j);

			//반환
			map[i][j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	cin >> n >> m;

	map.assign(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] == 2) {
				q_virus.push({ i,j });
			}
		}
	}

	//연산
	backtrack(0, 0);

	//출력
	cout << max_size;

	return 0;
}