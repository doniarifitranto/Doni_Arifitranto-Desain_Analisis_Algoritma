#include<iostream>
using namespace std;

class karyawan{
	private :
		int gaji;
		
	public :
		void setgaji(int s){
			gaji = s;
		}
		int setgaji(){
			return gaji;
		}
};

int main (){
	karyawan obj;
	
	obj.setgaji(50000);
	cout << obj.setgaji();
	
	return 0;
}
