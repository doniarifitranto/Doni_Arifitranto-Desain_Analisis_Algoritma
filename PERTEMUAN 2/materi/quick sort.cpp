#include <iostream>
using namespace std;

void swap (int arr[], int pos1, int pos2) { // void menunjukan fungsi swap tidak mengembalikan nilai apapun
	int temp; // sebagai tempat penyimpanan sementara, agar nilai pertama tidak hilang ketika ditimpa nilai kedua
	temp = arr[pos1];  // menyimpan nilai dari pos1 ke dalam variabel temp
	arr[pos1] = arr [pos2]; // // mengganti nilai dari pos1 dengan nilai dari pos2
	arr[pos2] = temp; // mengganti nilai pos2 dengan nilai yang sebelumnya disimpan di variabel temp
}

int partition (int arr[], int low, int high, int pivot) { // Daftar parameter dari fungsi 
	int i = low; // Mendeklarasi integer i dan menyebut parameter nya sebagai low. int i akan digunakan sebagai penunjuk yang bergerak melalui sub array
	int j = low; // Mendeklarasi interger j dan menyebut parameter nya sebagai low. int j akan digunakan sebagai penunjuk untuk menandai akhir sub array
	while (i <= high) { // loop akan terus berjalan selama i kurang dari nilai high, berarti loop memproses semua elemen subarray dari indeks low hingga high 
		if (arr[i] > pivot) { // Pernyataan kondisi apakah elemen arr pada indeks i lebih besar dari nilai pivot
			i++; // Jika benar maka baris ini dieksekusi, lanjutkan perulangan 
		}
		else { // Jika kondisi salah maka menjalankan pernyataan else
			swap (arr, i, j); // Memanggil sebuah fungsi bernama swap, fungsinya menukar nilai arr pada indeks i dengan nilai arr pada indeks j 
			i++; // Meningkatkan nilai i sebesar 1
			j++; // Meningkatkan nilai j sebesar 1
		}
	}
	return j-1; // Setelah loop while selesai, baris ini mengembalikan nilai dari j-1
}

void quicksort(int arr[], int low, int high) { // Mendeklarasi fungsi quick sort tidak mengembalikan nilai apapun int 
	if (low < high) { // Kondisi dasar untuk rekursi jika low kurang dari high, berarti ada lebih dari 1 elemen subarray yang perlu diurut
		int pivot = arr[high]; // Mengambil high (elemen terakhir dari subarray) dan menjadikannya nilai pivot
		int pos = partition(arr, low, high, pivot); // Memanggil fungsi partisi untuk membagi subarray
		
		quicksort(arr, low, pos-1); // Memanggil fungsi quicksort, dan mengurutkan subarray dari sebelah kiri hingga indeks akhir kiri sebelum pivot
		quicksort(arr, pos+1, high); // Memanggil fungsi quicksort, dan mengurutkan subarray dari sebelah kanan hingga indeks akhir dari kanan
	}
}

int main () 
{
	int n; // Mendeklarasi integer variabel nya n
	cout << "Tentukan panjang array = "; // Output dari nilai n
	cin>> n; // Input dari n yang akan dimasukan user
	
	int arr[n]; // Mendeklarasi integer variabel arr dan indeks n nya ditentukan dari nilai yang dimasukan user
	for (int i = 0; i < n; i++) { 
		cin >> arr[i]; // Dalam loop, baris ini membaca input dan menyimpan nilai yang dimasukan user ke dalam arr pada indeks i.
	}
	quicksort(arr, 0, n-1); // pemanggilan fungsi quicksort, arr adalah arr yang akan diurut, 0 adalah indeks awal, n-1 adalah indeks akhir (karena indeks dimulai dari 0)
	cout << "Berikutnya adalah array yang telah di sortir = ";
	for (int i = 0; i < n; i++) { // loop kedua ini akan digunakan untuk mencetak elemen array yang sudah terurut
		cout << "["<< arr[i] << "]" << ;// output array pada indeks i
	}
}
