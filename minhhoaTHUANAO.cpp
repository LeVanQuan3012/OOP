#include <iostream>
#include <string>
using namespace std;

class DongVat{
	public:
		virtual void amthanh()=0;
};

class Meo:public DongVat{
	public:
		void amthanh(){
			cout<<"Meo meo";
		}
};

class Cho:public DongVat{
	public:
		void amthanh(){
			cout<<"Gau gau";
		}
};
int main() {
	DongVat *a = new Cho();
	a->amthanh();
}
