#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;
const int MAXN = 505;

int dist[MAXN][MAXN];

void initialize(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }
}

void floydWarshall(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    initialize(n);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    floydWarshall(n);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == INF)
            cout << -1 << endl;
        else
            cout << dist[a][b] << endl;
    }

    return 0;
}
