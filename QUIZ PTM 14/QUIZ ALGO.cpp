#include <iostream>
using namespace std;

int binarySearch(int data[], int ukuran, int target) {
    int kiri = 0;
    int kanan = ukuran - 1;

    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;

        if (data[tengah] == target) {
            return tengah; // Data ditemukan, kembalikan index
        } else if (data[tengah] < target) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }

    return -1; // Data tidak ditemukan
}

int main() {
    int data[] = {11, 22, 33, 44, 55, 66, 77};
    int ukuran = sizeof(data) / sizeof(data[0]);
    int angkaDicari;

    cout << "Masukkan angka yang ingin dicari: ";
    cin >> angkaDicari;

    int posisi = binarySearch(data, ukuran, angkaDicari);

    if (posisi != -1) {
        cout << "Data ditemukan pada index ke-" << posisi << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}

