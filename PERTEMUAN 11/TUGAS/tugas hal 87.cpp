#include <iostream>
#include <vector>
#include <queue>

#define M 1000 

using namespace std;

const int N = 6; 

void printPath(int R[], int node) {
    if (R[node] == -1) {
        cout << node + 1;
        return;
    }
    printPath(R, R[node]);
    cout << " -> " << node + 1;
}

void dijkstra(int graph[N][N], int source) {
    vector<pair<int, int> > adj[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (graph[i][j] != M && i != j) {
                adj[i].push_back(make_pair(j, graph[i][j]));
            }
        }
    }

    int Q[N], R[N];
    for (int i = 0; i < N; i++) {
        Q[i] = M;
        R[i] = -1;
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    Q[source] = 0;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            if (Q[v] > Q[u] + w) {
                Q[v] = Q[u] + w;
                R[v] = u;
                pq.push(make_pair(Q[v], v));
            }
        }
    }

    cout << "\nJarak dari simpul " << source + 1 << " ke semua simpul:\n";
    for (int i = 0; i < N; i++) {
        if (Q[i] == M) {
            cout << "Node " << source + 1 << " -> " << i + 1 << " = Tidak terjangkau\n";
        } else {
            cout << "Node " << source + 1 << " -> " << i + 1 << " = " << Q[i] << endl;
        }
    }

    cout << "\nRute terpendek:\n";
    for (int i = 0; i < N; i++) {
        cout << "Ke " << i + 1 << ": ";
        if (Q[i] == M) {
            cout << "Tidak ada jalur\n";
        } else {
            printPath(R, i);
            cout << endl;
        }
    }
}

int main() {
    
    int graph[N][N] = {
        {0, M, 9, M, 14, 8},
        {M, 0, M, M, 10, M},
        {M, M, 0, 11, M, M},
        {M, M, M, 0, M, 7},
        {M, M, M, 2, 0, M},
        {M, M, M, M, 9, 0}
    };

    int source;
    cout << "Masukkan simpul asal (1-6): ";
    cin >> source;

    dijkstra(graph, source - 1);

    return 0;
}

