#include <iostream>
#include <string>
using namespace std; 

class NhanVien{
	protected:
		string hoten;
		int namsinh;
		string gioitinh;
		string diachi;
	public:
		NhanVien(){}
		NhanVien(string hoten, int namsinh, string gioitinh, string diachi):hoten(hoten),namsinh(namsinh),gioitinh(gioitinh),diachi(diachi){}
		friend istream& operator >>(istream &is, NhanVien& nv){
			cout<<"Nhap ho ten: ";
			is.ignore();
			getline(is, nv.hoten);
			cout<<"Nhap nam sinh: ";
			is>>nv.namsinh;
			cin.ignore();
			cout<<"Nhap gioi tinh: ";
			getline(is,nv.gioitinh);
			cout<<"Nhap dia chi: ";
			getline(is,nv.diachi);	
			return is;
		}
		
		friend ostream& operator<<(ostream &os, NhanVien& nv){
			os<<"Ho ten: "<<nv.hoten<<endl;
			os<<"Nam sinh: "<<nv.namsinh<<endl;
			os<<"Gioi tinh: "<<nv.gioitinh<<endl;
			os<<"Dia chi: "<<nv.diachi<<endl;	
			return os;
		}	
		
		string getHoTen(){
			return this->hoten;
		}	
};

class CongNhan:public NhanVien{
	private:
		double tienluong;
		string congviec;
	public:
		CongNhan(){}
		CongNhan(string hoten, int namsinh, string gioitinh, string diachi, double tienluong, string congviec):NhanVien(hoten,namsinh,gioitinh,diachi), tienluong(tienluong), congviec(congviec){}
		friend istream& operator >>(istream &is, CongNhan& cn){
			is>> (NhanVien&)(cn);
			cout<<"Nhap tien luong: ";
			is>>cn.tienluong;
			cin.ignore();
			cout<<"Nhap cong viec: ";
			getline(is, cn.congviec);
			return is;
		}
		
		friend ostream& operator <<(ostream &os, CongNhan& cn){
			os<<(NhanVien&)(cn);
			cout<<"Tien luong: "<<cn.tienluong<<endl;
			cout<<"Cong viec: "<<cn.congviec<<endl;
			return os;
		}
};

int main(){
	int n;
	cout<<"Nhap so cong nhan: "; cin>>n;
	CongNhan cn[n];
	for(int i=0; i<n; i++){
		cout<<"Thong tin cong nhan thu "<<i+1<<endl;
		cin>>cn[i];
		cout<<endl;
	}
	
	cout<<"Thong tin cong nhan vua nhap\n";
	for(int i=0; i<n; i++){
		cout<<"Cong nhan thu "<<i+1<<endl;
		cout<<cn[i];
		cout<<endl;
	}
	cout<<"Thong tin tim kiem:\n";
	string timkiem;
	getline(cin,timkiem);
	for(int i=0; i<n; i++){
		if(timkiem==cn[i].getHoTen()){
			cout<<cn[i];
		}
	}
	
	
	
}
