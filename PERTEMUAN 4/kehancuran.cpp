#include <iostream>
#include <String>

using namespace std;

class biodata{
	private :
		string nama;
		int umur;
		string alamat;
		
	public : 
		biodata (string name, int age, string add){
			cout << "\nConstructor dipanggil\n";
		}
		
	~biodata (){
		cout << "\nDestructor dipanggil\n";
	}
	
	void displayBiodata(){
		cout << "\nInformasi biodata" << endl;
		cout << "Nama : " << nama << endl;
		cout << "\nUmur : " << umur << endl;
		cout << "\nAlamat : " << alamat << endl;
	}	
};

int main (){
	int u;
	string n, a;
	
	cout << "Masukan nama anda :";
	getline (cin, n);
	cout << "Masukan usia anda :";
	cin.ignore();
	cout << "Masukan alamat anda :";
	getline (cin, a);
	
	biodata obj(n,u,a);
	obj.displayBiodata();
	
	return 0;
}
