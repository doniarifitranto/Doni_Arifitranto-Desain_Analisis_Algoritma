#include <iostream>
#include <string>
using namespace std;

struct barang {
	string barang;
	int harga;
};

int search(const barang daftar[], string brg ) {
	for(int i=0; i<5; i++) {
		if (daftar[i].barang == brg) {
			return i;
		}
	}	
	return -1;
}


int main() {
	string brg;
	char ulang;

	// Daftar barang
	barang daftarbarang[5] = {
		{"Buku", 5000},
		{"Pensil", 1000},
		{"Pulpen", 2000},
		{"Penghapus", 500},
		{"Penggaris", 1500}
	};
	

	do {
	cout << "Masukan barang yang ingin dicari:";
	cin >> brg;
	
	int idx =search(daftarbarang, brg);
	if(idx != -1){
		cout << "Barang " << daftarbarang[idx].barang << "ditemukan dengan harga " << daftarbarang[idx].harga << endl;
	}
	else {
		cout << "Maaf, barang " << brg << " tidak ditemukan dalam daftar" << endl;
	}
	
	cout << "Apakah ingin mencari barang lain? (y/n)" ;
	cin >> ulang;

	
	} while (ulang == 'y' || ulang == 'Y');


	cout << "\nTerima kasih!\n";
	
	return 0;
}
