#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

#define VI vector<int>
#define VII vector<vector<int> >

VII dNext = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

class KV {
public:
    int i, j, val;
    bool operator<(const KV& other) const {
        return val > other.val;
    }
};

int getShortestPath(VII &M, int n){
	if (n == 0) 
		return 0;
	priority_queue<KV> q;
    map<pair<int, int>, int> visited;
    q.push({0, 0, M[0][0]});
    while (!q.empty()) {
        KV top = q.top();
        q.pop();
        int i = top.i, j = top.j;
        int val = top.val;
        if (visited.count({i, j})) 
        	continue;
        visited[{i, j}] = val;
        if (i == n - 1 && j == n - 1) {
            return val;
        }
        for (VI &d : dNext){
            if (i + d[0] >= 0 && i + d[0] < n && 
                j + d[1] >= 0 && j + d[1] < n &&
                visited.count({i + d[0], j + d[1]}) == 0) {
                    q.push({i+d[0], j+d[1], val + M[i+d[0]][j+d[1]]});
            } 
        }
        
    }
	return 0;
}

// command line:  g++ 83.cpp
// 
int main(int argc, char *argv[]){
	int n = atoi(argv[1]);
	VII M (n, VI(n));
	for (auto &row : M) 
		for (int &x : row) 
			cin >> x;

	int dist = getShortestPath(M, n);
	cout << dist << endl;
	return 0;
}
