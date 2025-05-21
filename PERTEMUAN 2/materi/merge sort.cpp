#include <iostream>
using namespace std;

void merge (int arr[], int l, int m, int r){ // tipe data l adalah indeks awal, m indeks tengah, r indeks kanan
	int x, y, z;
	int n1 = m-l+1; // menentukan ukuran sub array kiri
	int n2 = r-m; // menentukan ukuran sub array kanan
	
	int L[n1], R[n2]; // Dua array sementara untuk menyimpan elemen sebelum digabung kembali
	for (x=0; x<n1; x++) // Looping untuk menyalin elemen dari bagian kiri array ke array sementara 
		L[x] = arr[l+x];
	for (y=0; y<n2; y++)
		R[y] = arr[m+l+y];
	
	x = 0;
	y = 0;
	z = l;
	
	while (x<n1 && y < n2){
		if (L[x] <= R[y]){
			arr[z] = L[x];
			x++;
		}
		else
		{
			arr[z] = R[y];
			y++;
		}
		z++;
	}
	
	while (x < n1){
		arr [z] = L[x];
		x++;
		z++;
	}
	
	while (y < n2){
		arr[z] = R[y];
		y++;
		z++;
	}
}

void mergeSort (int arr[], int l, int r){
	if (l<r){
		int m = l+ (r-l) / 2;
		mergeSort (arr, l, m);
		mergeSort (arr, m + l, r);
		
		merge (arr, l, m, r);
	}
}

void show (int A[], int size){
	int i;
	for (i=0; i<size; i++)
		cout << A[i] << " ";
}

int main ()
{
	int size;
	cout << "\nMasukan banyak data :";
	cin >> size;
	int arr[size];
	
	for (int i=0; i<size; i++){
		cout << "\nMasukan data array ke " <<i<<" :";
		cin >> arr[i];
	}
	
	mergeSort (arr, 0, size);
	cout << "Hasil\n";
	show (arr, size);
	return 0;
}
