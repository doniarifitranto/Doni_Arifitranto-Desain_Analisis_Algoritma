#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int storage[1024] = {0};
int i = 0;
int hdt_boundary;

void tambah_linear_probing(int n) {
    bool inserted = false;
    int hash;
    i = 0;

    while ((!inserted) && (i < hdt_boundary)) {
        hash = (n % hdt_boundary + i) % hdt_boundary;
        if (storage[hash] == 0) {
            storage[hash] = n;
            inserted = true;
        } else {
            ++i;
            cout << "Terjadi tabrakan di " << hash << endl;
        }
    }

    if (i == 0) cout << "Langsung" << endl;
    cout << "Isi hash[" << hash << "] dengan " << n << endl;
    cout << "===============================================" << endl;
}

void tambah_quadric_probing(int n) {
    bool inserted = false;
    int hash;
    i = 0;

    while ((!inserted) && (i < hdt_boundary)) {
        hash = (n % hdt_boundary + i * i) % hdt_boundary;
        if (storage[hash] == 0) {
            storage[hash] = n;
            inserted = true;
        } else {
            ++i;
            cout << "Terjadi tabrakan di " << hash << endl;
        }
    }

    if (i == 0) cout << "Langsung" << endl;
    cout << "Isi hash[" << hash << "] dengan " << n << endl;
    cout << "===============================================" << endl;
}

int prima_atas(int n) {
    if (n % 2 == 0) n++;
    else n += 2;

    while (true) {
        bool prima = true;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                prima = false;
                break;
            }
        }
        if (prima) return n;
        n += 2;
    }
}

int prima_bawah() {
    int n = hdt_boundary - 1;
    if (n % 2 == 0) n--;

    while (n >= 2) {
        bool prima = true;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                prima = false;
                break;
            }
        }
        if (prima) return n;
        n -= 2;
    }
    return 3;
}

void tambah_double_hashing(int n) {
    cout << "=========================================================" << endl;
    int hash;
    int hash2 = prima_bawah();
    bool inserted = false;
    i = 0;

    while ((!inserted) && (i < hdt_boundary)) {
        hash = ((n % hdt_boundary) + i * ((n % hash2) + 1)) % hdt_boundary;
        if (storage[hash] == 0) {
            storage[hash] = n;
            inserted = true;
        } else {
            ++i;
            cout << "Terjadi tabrakan di " << hash << endl;
        }
    }

    if (i == 0) cout << "Langsung" << endl;
    cout << "Isi hash[" << hash << "] dengan " << n << endl;
    cout << "==================================================" << endl;
}

void cetak(int n) {
    cout << "\nOutput program:\n";
    for (int a = 0; a < hdt_boundary; a++) {
        cout << "hash[" << a << "] = " << storage[a] << endl;
    }
}

int getRandomNumberFromRange(int min, int max) {
    return min + (rand() % (max - min));
}

int main() {
    int n, random_number;
    char pilihan;
    string cara;

    srand((unsigned)time(0));

    cout << "Masukkan jumlah data: ";
    cin >> n;

    cout << "Kami menggunakan metode open addressing (pilih salah satu):" << endl;
    cout << "a. linear probing" << endl;
    cout << "b. quadratic probing" << endl;
    cout << "c. double hashing" << endl;
    cout << "Pilih a, b, atau c: ";
    cin >> pilihan;

    cout << "\n\nProses pemasukan data ke hashtable\n";

    hdt_boundary = prima_atas(n);

    for (int a = 0; a < n; a++) {
        random_number = getRandomNumberFromRange(0, n * 10);  // agar lebih variasi
        switch (pilihan) {
            case 'a':
                tambah_linear_probing(random_number);
                cara = "Linear probing";
                break;
            case 'b':
                tambah_quadric_probing(random_number);
                cara = "Quadratic probing";
                break;
            case 'c':
                tambah_double_hashing(random_number);
                cara = "Double hashing";
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                return 1;
        }
    }

    cetak(n);

    cout << "\nDi atas adalah hasil output Hashtable dengan metode \"" << cara << "\"" << endl;

    switch (pilihan) {
        case 'a':
            cout << "h(k) = (k mod " << hdt_boundary << ") + i" << endl;
            break;
        case 'b':
            cout << "h(k) = (k mod " << hdt_boundary << ") + i^2" << endl;
            break;
        case 'c':
            cout << "h1(k) = k mod " << hdt_boundary << endl;
            cout << "h2(k) = (h1(k) + i * (k mod " << prima_bawah() << " + 1)) mod " << hdt_boundary << endl;
            break;
    }

    return 0;
}

