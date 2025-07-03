#include <iostream>
#include <iomanip>
#include <string>
#include <climits>
using namespace std;

const int INF = INT_MAX;
const int N = 18; // Jumlah total siswa

// Nama siswa dalam array
string siswa[N] = {
    "Kyanka", "Dava", "Doni", "Wildan", "Haikal", "Agus", "Abrar", "Azizah",
    "Annisa", "Jonathan", "Rofii", "Yunita", "Nanda", "Martin", "Sudrajat",
    "Ale", "Agung", "Steven"
};

// Matriks graf bobot
int graf[N][N];

// Fungsi untuk mendapatkan indeks nama siswa
int getIndex(string nama) {
    for (int i = 0; i < N; i++) {
        if (siswa[i] == nama) return i;
    }
    return -1;
}

// Fungsi untuk menambahkan edge
void addEdge(string a, string b, int w) {
    int u = getIndex(a);
    int v = getIndex(b);
    if (u != -1 && v != -1) {
        graf[u][v] = w;
        graf[v][u] = w;
    }
}

// Dijkstra
void dijkstra(int src, int dest) {
    int dist[N], prev[N];
    bool visited[N];
    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        prev[i] = -1;
        visited[i] = false;
    }
    dist[src] = 0;

    for (int i = 0; i < N; i++) {
        int u = -1;
        for (int j = 0; j < N; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (dist[u] == INF) break;
        visited[u] = true;

        for (int v = 0; v < N; v++) {
            if (graf[u][v] != INF && dist[u] + graf[u][v] < dist[v]) {
                dist[v] = dist[u] + graf[u][v];
                prev[v] = u;
            }
        }
    }

    if (dist[dest] == INF) {
        cout << "Tidak ada jalur yang tersedia." << endl;
        return;
    }

    // Cetak jalur
    int path[N], count = 0, at = dest;
    while (at != -1) {
        path[count++] = at;
        at = prev[at];
    }

    cout << "Jalur tercepat: ";
    for (int i = count - 1; i >= 0; i--) {
        cout << siswa[path[i]];
        if (i != 0) cout << " -> ";
    }
    cout << "\nTotal waktu: " << dist[dest] << endl;
}

// Floyd-Warshall
void floydWarshall() {
    int dist[N][N];
    int i, j, k;

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            dist[i][j] = graf[i][j];

    for (k = 0; k < N; k++)
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    // Cetak matriks
    cout << "\nMatriks Jarak Terpendek:\n\n";
    cout << setw(10) << " ";
    for (i = 0; i < N; i++) cout << setw(10) << siswa[i];
    cout << endl;

    for (i = 0; i < N; i++) {
        cout << setw(10) << siswa[i];
        for (j = 0; j < N; j++) {
            if (dist[i][j] == INF)
                cout << setw(10) << "8";
            else
                cout << setw(10) << dist[i][j];
        }
        cout << endl;
    }
}

int main() {
    int i, j;

    // Inisialisasi graf
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            graf[i][j] = (i == j ? 0 : INF);

    // Tambahkan edge sesuai denah
    addEdge("Kyanka", "Dava", 1);
    addEdge("Kyanka", "Abrar", 3);
    addEdge("Abrar", "Azizah", 1);
    addEdge("Abrar", "Steven", 2);
    addEdge("Steven", "Azizah", 1);
    addEdge("Azizah", "Dava", 2);
    addEdge("Dava", "Doni", 1);
    addEdge("Azizah", "Annisa", 1);
    addEdge("Doni", "Annisa", 4);
    addEdge("Annisa", "Yunita", 2);
    addEdge("Doni", "Wildan", 2);
    addEdge("Wildan", "Jonathan", 1);
    addEdge("Jonathan", "Annisa", 1);
    addEdge("Jonathan", "Rofii", 2);
    addEdge("Rofii", "Haikal", 4);
    addEdge("Rofii", "Agus", 2);
    addEdge("Wildan", "Haikal", 4);
    addEdge("Yunita", "Nanda", 2);
    addEdge("Martin", "Nanda", 1);
    addEdge("Martin", "Sudrajat", 3);
    addEdge("Sudrajat", "Nanda", 4);
    addEdge("Nanda", "Ale", 2);
    addEdge("Ale", "Rofii", 2);
    addEdge("Ale", "Agung", 1);

    string asal, tujuan;
    char cetak;

    cout << "Masukkan siswa asal: ";
    cin >> asal;
    cout << "Masukkan siswa tujuan: ";
    cin >> tujuan;
    cout << "Cetak Matriks Jarak Terpendek (Y/T)? ";
    cin >> cetak;

    int src = getIndex(asal);
    int dst = getIndex(tujuan);

    if (src == -1 || dst == -1) {
        cout << "Nama siswa tidak ditemukan.\n";
    } else {
        dijkstra(src, dst);
    }

    if (cetak == 'Y' || cetak == 'y') {
        floydWarshall();
    }

    return 0;
}
	
