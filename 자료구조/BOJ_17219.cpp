#include <iostream>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	string site, pw;
	cin >> n >> m;

	map<string, string> pw_map;
	while (n--) {
		cin >> site >> pw;
		pw_map.insert({ site, pw });
	}

	while (m--) {
		//입력
		cin >> site;

		//출력
		cout << pw_map[site] << "\n";
	}

	return 0;
}