#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SANPHAM {
private:
    string ten;
    string nhasanxuat;

public:
    SANPHAM() {}

    SANPHAM(string ten, string nhasanxuat) : ten(ten), nhasanxuat(nhasanxuat) {}

    string getTen() {
        return ten;
    }

    string getNhasanxuat() {
        return nhasanxuat;
    }

    void setTen(string ten) {
        this->ten = ten;
    }

    void setNhasanxuat(string nhasanxuat) {
        this->nhasanxuat = nhasanxuat;
    }

    virtual void nhap() {
        cout << "Nhap ten: ";
        cin.ignore();
        getline(cin, ten);
        cout << "Nhap nha san xuat: ";
        getline(cin, nhasanxuat);
    }

    virtual void xuat() {
        cout << "Ten: " << ten << endl;
        cout << "Nha san xuat: " << nhasanxuat << endl;
    }

    virtual double thanhtoan() {
        return 0;
    }
};

class BANLE : public SANPHAM {
private:
    int giabanle;
    int soluong;

public:
    BANLE(string ten, string nhasanxuat, int giabanle, int soluong) : SANPHAM(ten, nhasanxuat), giabanle(giabanle), soluong(soluong) {}

    void nhap() {
        SANPHAM::nhap();
        cout << "Nhap gia ban le: ";
        cin >> giabanle;
        do {
            cout << "Nhap so luong (<10): ";
            cin >> soluong;
        } while (soluong >= 10);
    }

    double thanhtoan() override {
        return giabanle * soluong;
    }

    void xuat() override {
        SANPHAM::xuat();
        cout << "Gia ban le: " << giabanle << endl;
        cout << "So luong: " << soluong << endl;
        cout << "Thanh toan: " << thanhtoan() << endl;
    }
};

class BANSI : public SANPHAM {
private:
    int giasi;
    int soluong;

public:
    BANSI(string ten, string nhasanxuat, int giasi, int soluong) : SANPHAM(ten, nhasanxuat), giasi(giasi), soluong(soluong) {}

    void nhap() {
        SANPHAM::nhap();
        cout << "Nhap gia si: ";
        cin >> giasi;
        do {
            cout << "Nhap so luong (>100): ";
            cin >> soluong;
        } while (soluong <= 100);
    }

    double thanhtoan() override {
        return giasi * soluong;
    }

    void xuat() override {
        SANPHAM::xuat();
        cout << "Gia si: " << giasi << endl;
        cout << "So luong: " << soluong << endl;
        cout << "Thanh toan: " << thanhtoan() << endl;
    }
};

int main() {
    int n;
    cout << "Nhap so luong san pham: ";
    cin >> n;

    vector<SANPHAM*> sp;

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin san pham thu " << i + 1 << endl;
        int k;
        do {
            cout << "Nhap 1 de nhap thong tin cho ban le\nNhap 2 de nhap thong tin cho ban si\n";
            cin >> k;
        } while (k != 1 && k != 2);

        if (k == 1) {
            BANLE* banle = new BANLE("", "", 0, 0);
            banle->nhap();
            sp.push_back(banle);
        } else if (k == 2) {
            BANSI* bansi = new BANSI("", "", 0, 0);
            bansi->nhap();
            sp.push_back(bansi);
        }
    }

    cout << "Thong tin cac san pham:\n";
    for (int i = 0; i < n; i++) {
        sp[i]->xuat();
        cout << endl;
    }

    cout << "Thong tin san pham thanh toan it nhat: \n";
    SANPHAM* a = sp[0];
    for (int i = 1; i < n; i++) {
        if (a->thanhtoan() > sp[i]->thanhtoan()) {
            a = sp[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (a->thanhtoan() == sp[i]->thanhtoan()) {
            sp[i]->xuat();
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        delete sp[i];
    }

    return 0;
}

