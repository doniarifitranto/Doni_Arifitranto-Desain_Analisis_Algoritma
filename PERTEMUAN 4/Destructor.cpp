#include <iostream>
#include <string>
using namespace std;

class mahasiswa { 
	public : 
		mahasiswa(string nama, int umur) //fungsi mahasiswa
			: nama_(nama), umur_(umur){
				cout << "Constructor mahasiswa" << endl;
			}
			~mahasiswa () { //nama fungsi sama dengan class
				cout << "==Contoh destructor mahasiswa==" << endl; //membersihkan memory, untuk code yang memakan memory yg besar 
			}
			
			void tampilkanBiodata () { //fungsi tampilkanBiodata
				cout << "Nama : " << nama_ << endl;
				cout << "Umur : " << umur_ << endl;
			}
			
	private : 
		string nama_;
		int umur_;
};

int main ()
{
	{
		mahasiswa mhs("Dono", 22); //membuat objek mhs
		mhs.tampilkanBiodata(); //memanggil fungsi tampilkanBiodata
	}
	
	return 0;
}
