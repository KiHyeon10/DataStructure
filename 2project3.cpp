#include <iostream>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

const int INSTALLED = 2;
const int DEFENDED = 1;
const int NOT_DEFENDED = 0;

int n, m;
int s, e;
vector<vector<int>> adjArray;
vector<int> visited;

int numTuret = 0;

void AddEdge(int start, int end) {
	adjArray[start].push_back(end);
	adjArray[end].push_back(start);
}

int aDFS(int v) {
	int a = 0;
	visited[v] = 1;
	for (int i = 0; i < adjArray[v].size(); i++) {
		int x = adjArray[v][i];
		if (visited[x] == 0) {
			a = aDFS(x);
		}
	}
	if (adjArray[v].size() != 0 && a == NOT_DEFENDED) {
		numTuret++;
		return INSTALLED;
	}
	else if (adjArray[v].size() != 0 && a == INSTALLED) {
		return DEFENDED;
	}
	else
		return NOT_DEFENDED;
}

void DFS() {
	int i = 0;
	for (int v = 1; v <= n; v++)
		visited[v] = 0;

	for (int v = 1; v <= n; v++) {
		if (visited[v] == 0) {
			i = aDFS(v);
		}
		if (i == NOT_DEFENDED)
			numTuret += 1;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		numTuret = 0;
		adjArray.clear();
		visited.clear();

		cin >> n >> m;

		adjArray.resize(n + 1);
		visited.resize(n + 1);

		for (int j = 0; j < m; j++) {
			cin >> s >> e;
			AddEdge(s, e);
		}

		DFS();

		cout << numTuret;
		cout << endl;
	}
}
	