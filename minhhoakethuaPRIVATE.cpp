#include <iostream>
using namespace std;

class TLU{
	private:
		void nhapKhoa(){
			cout<<"Day la private";
		};
	protected:
		void getKHoa(){
			nhapKhoa();
		}
		void nhaptoanha(){
			cout<<"Day la protected";
		};
	public:
		void nhapTLU(){
			cout<<"Day la public";
		};
}; 

class CNTT:private TLU{
	
	public:
		void giatri(){
			nhaptoanha();
			nhapTLU(); 
		}	
	
};

int main(){
	CNTT a;
	a.giatri();
	//a.nhapTLU();// loi 
}

