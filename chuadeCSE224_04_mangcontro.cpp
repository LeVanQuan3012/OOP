#include <iostream>
#include <string>
using namespace std;

class Vehicles {
private:
    int tocdotieuchuan;

public:
    int getTocdotieuchuan() {
        return tocdotieuchuan;
    }
    Vehicles() {}
    Vehicles(int tocdotieuchuan) : tocdotieuchuan(tocdotieuchuan) {}

    virtual const double maxSpeed() = 0;

    void nhap() {
        cout << "Nhap toc do tieu chuan: ";
        cin >> tocdotieuchuan;
    }

    void xuat() {
        cout << "Toc do tieu chuan: " << tocdotieuchuan << endl;
    }
};

class Ferrari : public Vehicles {
private:
    string mausac;
    double hesotocdo;

public:
    Ferrari() {}
    Ferrari(int tocdotieuchuan, string mausac, double hesotocdo) : Vehicles(tocdotieuchuan), mausac(mausac), hesotocdo(hesotocdo) {}

    const double maxSpeed() {
        return hesotocdo * getTocdotieuchuan();
    }

    void input() {
        Vehicles::nhap();
        cout << "Nhap mau sac: ";
        cin >> mausac;
        cout << "Nhap he so toc do: ";
        cin >> hesotocdo;
    }

    void output() {
        Vehicles::xuat();
        cout << "Mau sac: " << mausac << endl;
        cout << "He so toc do: " << hesotocdo << endl;
        cout << "Toc do toi da: " << maxSpeed() << endl;
    }

    bool operator>(Ferrari& another) {
        return maxSpeed() > another.maxSpeed();
    }
};

int main() {
    int n;
    cout << "Nhap so luong: ";
    cin >> n;
    Ferrari* fa[n];

    for (int i = 0; i < n; i++) {
        fa[i] = new Ferrari;
        fa[i]->input();
        cout << endl;
    }

    cout << "Thong tin ban vua nhap\n";
    for (int i = 0; i < n; i++) {
        fa[i]->output();
        cout << endl;
    }

    Ferrari* a = fa[0];
    for (int i = 1; i < n; i++) {
        if (*fa[i] > *a) {
            a = fa[i];
        }
    }

    cout << "Doi tuong co toc do lon nhat: \n";
    for(int i=0; i<n; i++){
    	if(a->maxSpeed() == fa[i]->maxSpeed()){
    		fa[i]->output();
    		cout<<endl; 
		}
	}

    for (int i = 0; i < n; i++) {
        delete fa[i];
    }

    return 0;
}

