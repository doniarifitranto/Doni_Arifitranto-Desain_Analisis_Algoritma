#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int jumlahNama;

    cout << "Masukkan jumlah nama: ";
    cin >> jumlahNama;
    cin.ignore(); // Membersihkan newline dari buffer

    vector<string> daftarNama(jumlahNama);
    for (int i = 0; i < jumlahNama; ++i) {
        cout << "Nama ke-" << i + 1 << ": ";
        getline(cin, daftarNama[i]);
    }

    cout << "\nSebelum diurutkan:\n";
    for (const string& nama : daftarNama) {
        cout << nama << " ";
    }
    cout << endl;

    // Insertion Sort berdasarkan panjang karakter
    for (int i = 1; i < jumlahNama; ++i) {
        string key = daftarNama[i];
        int j = i - 1;

        while (j >= 0 && daftarNama[j].length() > key.length()) {
            daftarNama[j + 1] = daftarNama[j];
            j--;
        }
        daftarNama[j + 1] = key;
    }

    cout << "\nSetelah diurutkan berdasarkan panjang karakter:\n";
    for (const string& nama : daftarNama) {
        cout << nama << " ";
    }
    cout << endl;

    return 0;
}
