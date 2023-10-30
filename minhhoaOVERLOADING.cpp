#include <iostream>
#include <string>
using namespace std;

class DongVat{
	public:
		void nhap (string a){
			cout<<"Ban vua nhap string: "<<a<<endl;;
		} 
				
		void nhap (int a){
			cout<<"Ban vua nhap so nguyen: "<<a<<endl;;
		}
		
		void nhap (double a){
			cout<<"Ban vua nhap so thuc: "<<a<<endl;
		}
};

int main() {
	DongVat a;
	a.nhap("Xin chao");
	a.nhap(5);
	a.nhap(5.5);
}
