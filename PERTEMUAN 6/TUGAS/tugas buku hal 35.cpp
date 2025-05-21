#include <iostream>
using namespace std;

int main() {
    int data[] = {6, 8, 12, 18, 24};
    int jumlah = sizeof(data) / sizeof(data[0]);
    int dicari;
    
    cout << "Masukkan data yang dicari: ";
    cin >> dicari;

    bool ditemukan = false;

    for (int i = 0; i < jumlah; i++) {
        if (data[i] == dicari) {
            cout << "Bilangan ditemukan pada indeks ke-" << i << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Bilangan tidak ditemukan." << endl;
    }

    return 0;
}
