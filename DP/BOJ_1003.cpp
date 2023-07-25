#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

const int NUM = 41;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int t, n;
    cin >> t;

    //연산
    vector<ii> cnt(NUM, { 0,0 });
    cnt[0] = { 1,0 };
    cnt[1] = { 0,1 };

    for (int i = 2; i < NUM; i++) {
        cnt[i] = { cnt[i - 1].first + cnt[i - 2].first, cnt[i - 1].second + cnt[i - 2].second };
    }

    while (t--) {
        //입력
        cin >> n;

        //출력
        cout << cnt[n].first << " " << cnt[n].second << "\n";
    }

	return 0;
}