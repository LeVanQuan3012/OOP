#include <iostream>
using namespace std;

class TLU{
	private:
		void nhapKhoa(){
			cout<<"Day la private";
		}
	protected:
		void nhapToaNha(){
			cout<<"Day la protected";
		}
	public:
		void nhapTLU(){
			cout<<"Day la public";
		}
};

class CNTT:protected TLU{
	/*protected:
			void nhapTLU(){
				cout<<"Day la public";
			}
			void nhapToaNha(){
			cout<<"Day la protected";
		}*/
	public:
		void giatri(){
			nhapToaNha();
			nhapTLU();
		}
};
int main(){
	CNTT a;
	a.giatri();
	
}
