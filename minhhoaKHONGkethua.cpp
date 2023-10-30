#include <iostream>
#include <string>
using namespace std;

struct date {
    int day;
    int month;
    int year;
};

class ConNguoi {
	private:
	    string hoten;
	    date ngaysinh;
	    string quequan;
	
	public:
	    void nhapNguoi() {
	        cout << "Nhap ho ten: ";
	        getline(cin, hoten);
	        cout << "Nhap ngay sinh: ";
	        cin >> ngaysinh.day;
	        cout << "Nhap thang sinh: ";
	        cin >> ngaysinh.month;
	        cout << "Nhap nam sinh: ";
	        cin >> ngaysinh.year;
	        cin.ignore(); 
	        cout << "Nhap que quan: ";
	        getline(cin, quequan);
	    }
};

class SinhVien {
	private:
		string hoten;
	    date ngaysinh;
	    string quequan;
	    string tentruong;
	    string chuyennganh;
	    string msv;
	public:
	    void nhapSV() {
	        cout << "Nhap ho ten: ";
	        getline(cin, hoten);
	        cout << "Nhap ngay sinh: ";
	        cin >> ngaysinh.day;
	        cout << "Nhap thang sinh: ";
	        cin >> ngaysinh.month;
	        cout << "Nhap nam sinh: ";
	        cin >> ngaysinh.year;
	        cin.ignore(); 
	        cout << "Nhap que quan: ";
	        getline(cin, quequan);
	        cout << "Nhap ten truong: ";
	        getline(cin, tentruong);
	        cout << "Nhap chuyen nganh: ";
	        getline(cin, chuyennganh);
	        cout << "Nhap ma sinh vien: ";
	        getline(cin, msv);
	    }
};

int main() {
    SinhVien a;
    a.nhapSV();
}

