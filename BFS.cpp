#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int s, e;
vector<vector<int>> adjArray;
vector<int> visited;
queue<int> a;

void BFS(int g) {
	for (int v = 1; v <= n; v++)
		visited[v] = 0;

	visited[g] = 1;
	a.push(g);
	while (!a.empty()) {
		int u = a.front();
		cout << u << " ";
		a.pop();

		for (int i = 0; i < adjArray[u].size(); i++) {
			int x = adjArray[u][i];
			if(visited[x] == 0) {
				visited[x] = 1;
				a.push(x);
			}
		}
	}
}

void AddEdge(int start, int end) {
	adjArray[start].push_back(end);
	adjArray[end].push_back(start);
}

void printGraph() {
	for (int i = 1; i <= n; i++) {
		cout << i << ": ";
		for (int j = 0; j < adjArray[i].size(); j++)
			cout << adjArray[i][j] << " ";

		cout << endl;
	}
}

int main() {
	cin >> n >> m;
	adjArray.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		AddEdge(s, e);
	}

	printGraph();
	BFS(1);
}