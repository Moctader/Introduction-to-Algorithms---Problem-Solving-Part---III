/*
Didn't understand the problem

*/




#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
bool visited[MAXN];
int parent[MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    queue<int> q;
    q.push(1);
    visited[1] = true;
    parent[1] = -1;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if (cur == n) {
            // We have found the destination node.
            // Now we can reconstruct the path.
            vector<int> path;
            int node = n;
            while (node != -1) {
                path.push_back(node);
                node = parent[node];
            }
            reverse(path.begin(), path.end());
            cout << path.size() << endl;
            for (int node : path) {
                cout << node << " ";
            }
            cout << endl;
            return 0;
        }
        
        for (int next : adj[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = cur;
                q.push(next);
            }
        }
    }
    
    // If we reach here, it means there is no path from the source node to the destination node.
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
