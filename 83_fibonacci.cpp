/*
g++ -std=c++0x \
 -I /usr/local/Cellar/boost/1.55.0/include/ \
 -L /usr/local/Cellar/boost/1.55.0/lib/  \
 83_fibonacci.cpp \
 -o 83.out
 *
    ./83.out 80 < large.txt
 */
#include <iostream>
#include <vector>
#include <map>
#include <boost/heap/fibonacci_heap.hpp>
using namespace std;

#define VI vector<int>
#define VII vector<vector<int> >
const VII d_next = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

class KeyVal {
public:
    int i, j, val;
    bool operator<(const KeyVal& other) const {
        return val > other.val;
    }
};

typedef boost::heap::fibonacci_heap<KeyVal> PriQue;
typedef boost::heap::fibonacci_heap<KeyVal>::handle_type PriQue_handle;

int getShortestPath(VII &M){
	int m = (int) M.size();
	if (m == 0) return 0;
	int n = (int) M[0].size();
	if (n == 0) return 0;

	PriQue q;
    map<pair<int, int>, int> explored;
    map<pair<int, int>, PriQue_handle> frontier;
    q.push({0, 0, M[0][0]});
    while (!q.empty()) {
        const KeyVal &top = q.top();
        int i = top.i, j = top.j;
        int val = top.val;
        q.pop();
        // if (explored.count({i, j})) continue;
        frontier.erase({i, j});
        explored[{i, j}] = val;
        if (i == m - 1 && j == n - 1) {
            return val;
        }
        for (auto &dij : d_next) {
        	int i_next = i+dij[0];
        	int j_next = j+dij[1];
        	if (i_next<0 || i_next>=m ||
                j_next<0 || j_next>=n ||
                explored.count({i_next, j_next}) )
        		continue;

        	int val_next_candidate = val + M[i_next][j_next];
            
            if (frontier.count({i_next, j_next}) == 0) {
                frontier[{i_next, j_next}] = q.push({i_next, j_next, val_next_candidate});
            }
            else if (val_next_candidate < (*frontier[{i_next, j_next}]).val)  {
                q.update(frontier[{i_next, j_next}], {i_next, j_next, val_next_candidate});
            }
            
        }
    }
	return 0;
}

int main(int argc, char *argv[]){
	int n = atoi(argv[1]);
	VII M (n, VI(n));
	for (auto &row : M) {
		for (int &x : row) {
			cin >> x;
		}
	}
	int dist = getShortestPath(M);
	cout << dist << endl;
	return 0;
}
