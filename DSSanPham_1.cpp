#include<iostream>
#include<vector>
using namespace std;

class SanPham {
private:
    string MaSP, TenSP;
    double Gia;
public:
    SanPham() {}
    SanPham(string MaSP, string TenSP, double Gia) : MaSP(MaSP), TenSP(TenSP), Gia(Gia) {}

    string getMaSP() {
        return MaSP;
    }
    void setMaSP(string maSP) {
        MaSP = maSP;
    }
    string getTenSP() {
        return TenSP;
    }
    void setTenSP(string tenSP) {
        TenSP = tenSP;
    }
    double getGia() {
        return Gia;
    }
    void setGia(double gia) {
        Gia = gia;
    }

    void nhap() {
        cout << "Nhap Ma SP: ";
        cin >> MaSP;
        cout << "Nhap Ten SP: ";
        cin.ignore();
        getline(cin, TenSP);
        cout << "Nhap Gia: ";
        cin >> Gia;
    }

    void xuat() {
        cout << "Ma SP: " << MaSP << endl;
        cout << "Ten SP: " << TenSP << endl;
        cout << "Gia: " << Gia << endl;
    }

    void luuVaoFile(ofstream file) {
        file << MaSP << "," << TenSP << "," << Gia << endl;
    }
};

class DSSanPham {
	private:
	    vector<SanPham> danhSachSanPham;
	public:
		vector<SanPham> getDSSP() {
			return danhSachSanPham
		}
	    void themSanPham() {
	        SanPham sp;
	        sp.nhap();
	        danhSachSanPham.push_back(sp);
	    }
	
	    void docDuLieuTuFile(string tenTep) {
	        ifstream file(tenTep);
	
	        if (!file.is_open()) {
	            cout << "Khong mo duoc file" << endl;
	            return;
	        }
	
	        string line;
	        while (getline(file, line)) {
	            stringstream ss(line);
	            string maSP, tenSP;
	            double gia;
	
	            getline(ss, maSP, ',');
	            getline(ss, tenSP, ',');
	            ss >> gia;
	
	            SanPham sp(maSP, tenSP, gia);
	            themSanPham(sp);
	        }
	
	        file.close();
	    }
	
	    void hienThiDanhSach() {
	        for (auto sp : danhSachSanPham) {
	            sp.xuat();
	            cout << endl;
	        }
	    }
	
	    void suaSanPham(string maSP, SanPham sp) {
	        bool timThay = false;
	        for (auto& sanpham : danhSachSanPham) {
	            if (sanpham.getMaSP() == maSP) {
	                sanpham = sp;
	                timThay = true;
	                break;
	            }
	        }
	
	        if (!timThay) {
	            cout << "Khong tim thay san pham co MaSP: " << maSP << endl;
	        }
	    }
	
	    void xoaSanPham(string maSP) {
	        bool timThay = false;
	        for (auto it = danhSachSanPham.begin(); it != danhSachSanPham.end(); ++it) {
	            if (it->getMaSP() == maSP) {
	                danhSachSanPham.erase(it);
	                timThay = true;
	                cout << "Da xoa san pham co MaSP: " << maSP << endl;
	                break;
	            }
	        }
	
	        if (!timThay) {
	            cout << "Khong tim thay san pham co MaSP: " << maSP << endl;
	        }
	    }
	
	    void luuVaoFile(string tenTep) {
	        ofstream file(tenTep);
	        if (!file.is_open()) {
	            cout << "Khong mo duoc file" << endl;
	            return;
	        }
	
	        for (auto sp : danhSachSanPham) {
	            sp.luuVaoFile(file);
	        }
	
	        file.close();
	    }
};


