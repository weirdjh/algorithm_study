#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 16

using namespace std;

int N, M;

vector<pair<int, int>> adj[40001];
int parent[40001][MAX+1];
int dist[40001][MAX+1];
int depth[40001];
int isvisit[40001];

void initLCA(int vertex, int d);
int findLCA(int x, int y);

int main(void) {

	// 트리 입력.
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
	}

	isvisit[1] = 1;
	initLCA(1,1);

	// parent 및 distance 계산
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= MAX; j++) {
			parent[i][j] = parent[parent[i][j-1]][j-1];
			dist[i][j] = dist[i][j - 1] + dist[parent[i][j-1]][j-1];
		}
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= MAX; j++) {
			cout << parent[i][j] << ' ' ;
		}cout << endl;
	}
	cout << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= MAX; j++) {
			cout << dist[i][j] << ' ';
		}cout << endl;
	}
	

	cin >> M;
	vector<int> answer;

	// 쿼리 입력 및 lca 계산.
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		int lca = findLCA(x, y);
		answer.push_back(lca);
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << ' ';
	}cout << endl;
	
	return 0;
}

// 바로 윗 parent,distance 계산, depth 초기화.
void initLCA(int vertex, int d) {
	for (int i = 0; i < adj[vertex].size(); i++) {
		pair<int,int> next = adj[vertex][i];
		if (!isvisit[next.first]) {
			isvisit[next.first] = 1;

			parent[next.first][0] = vertex;
			dist[next.first][0] = next.second;
			depth[next.first] = d;

			initLCA(next.first, d + 1);
		}
	}
}

// lca계산.
int findLCA(int x, int y) {
	
	if (depth[x] < depth[y]) swap(x, y);

	int ret = 0;

	
	for (int len = MAX; len >= 0; len--) {
		if (depth[x] - (1 << len) >= depth[y]) {
			ret += dist[x][len];
			x = parent[x][len];
		}
	}

	if (x == y) return ret;

	for(int len = MAX; len >=0; len--){
		if (parent[x][len] != parent[y][len]) {
			ret += (dist[x][len] + dist[y][len]);
			x = parent[x][len];
			y = parent[y][len];
		}
	}
	ret += (dist[x][0] + dist[y][0]);

	return ret;
}
