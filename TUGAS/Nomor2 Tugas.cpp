#include <iostream>
#include <string>

using namespace std;

void bubbleSort(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int jumlah_buku;
    cout << "Masukkan jumlah buku: ";
    cin >> jumlah_buku;
    cin.ignore(); 

    string judul_buku[jumlah_buku];

    cout << "Masukkan judul buku:" << endl;
    for (int i = 0; i < jumlah_buku; i++) {
        getline(cin, judul_buku[i]);
    }

    bubbleSort(judul_buku, jumlah_buku);
    cout << "\nJudul buku sesudah diurut (ascending) :" << endl;
    for (int i = 0; i < jumlah_buku; i++) {
        cout << judul_buku[i] << endl;
    }

    return 0;
}
