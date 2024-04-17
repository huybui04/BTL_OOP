#include<iostream>
#include<vector>
using namespace std;

class NguyenLieu {
private:
    string MaNL, TenNL, NSX, HSD;
    double Gia;
public:
    NguyenLieu() {}
    NguyenLieu(string MaNL, string TenNL, string NSX, string HSD, double Gia)
        : MaNL(MaNL), TenNL(TenNL), NSX(NSX), HSD(HSD), Gia(Gia) {}

    string getMaNL() {
        return MaNL;
    }
    void setMaNL(string maNL) {
        MaNL = maNL;
    }
    string getTenNL() {
        return TenNL;
    }
    void setTenNL(string tenNL) {
        TenNL = tenNL;
    }
    string getNSX() {
        return NSX;
    }
    void setNSX(string nsx) {
        NSX = nsx;
    }
    string getHSD() {
        return HSD;
    }
    void setHSD(string hsd) {
        HSD = hsd;
    }
    double getGia() {
        return Gia;
    }
    void setGia(double gia) {
        Gia = gia;
    }

    void nhap() {
        cout << "Nhap Ma NL: ";
        getline(cin, MaNL);
        cout << "Nhap Ten NL: ";
        getline(cin, TenNL);
        cout << "Nhap NSX: ";
        getline(cin, NSX);
        cout << "Nhap HSD: ";
        getline(cin, HSD);
        cout << "Nhap Gia: ";
        cin >> Gia;
        cin.ignore(); // clear input buffer
    }
    void xuat() {
        cout << "Ma NL: " << MaNL << endl;
        cout << "Ten NL: " << TenNL << endl;
        cout << "NSX: " << NSX << endl;
        cout << "HSD: " << HSD << endl;
        cout << "Gia: " << Gia << endl;
    }
    void luuVaoFile(ofstream file) {
        file << MaNL << "," << TenNL << "," << NSX << "," << HSD << "," << Gia << endl;
    }
};

class DSNguyenLieu {
	private:
	    vector<NguyenLieu> danhSachNguyenLieu;
	
	public:
		vector<NguyenLieu> getDSNL() {
			return danhSachNguyenLieu;
		}
	    void themNguyenLieu() {
	        NguyenLieu nl;
	        nl.nhap();
	        danhSachNguyenLieu.push_back(nl);
	    }
	
	    void hienThiDanhSach() {
	        for (auto nl : danhSachNguyenLieu) {
	            nl.xuat();
	            cout << endl;
	        }
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
		        string maNL, tenNL, nsx, hsd;
		
		        getline(ss, maNL, ',');
		        getline(ss, tenNL, ',');
		        getline(ss, nsx, ',');
		        getline(ss, hsd);
		        
		        NguyenLieu nl(maNL, tenNL, nsx, hsd);
		        themNguyenLieu(nl);
		    }
		
		    file.close();
		}
	
		
	    void suaNguyenLieu(string maNL, NguyenLieu nl) {
	        bool timThay = false;
	        for (auto& nguyenlieu : danhSachNguyenLieu) {
	            if (nguyenlieu.getMaNL() == maNL) {
	                nguyenlieu = nl;
	                timThay = true;
	                break;
	            }
	        }
	
	        if (!timThay) {
	            cout << "Khong tim thay nguyen lieu co Ma NL: " << maNL << endl;
	        }
	    }
	
	    void xoaNguyenLieu(string maNL) {
	        bool timThay = false;
	        for (auto it = danhSachNguyenLieu.begin(); it != danhSachNguyenLieu.end(); ++it) {
	            if (it->getMaNL() == maNL) {
	                danhSachNguyenLieu.erase(it);
	                timThay = true;
	                cout << "Da xoa nguyen lieu co Ma NL: " << maNL << endl;
	                break;
	            }
	        }
	
	        if (!timThay) {
	            cout << "Khong tim thay nguyen lieu co Ma NL: " << maNL << endl;
	        }
	    }
	
	    void luuVaoFile(string tenTep) {
	        ofstream file(tenTep);
	        if (!file.is_open()) {
	            cout << "Khong mo duoc file" << endl;
	            return;
	        }
	
	        for (auto nl : danhSachNguyenLieu) {
	            nl.luuVaoFile(file);
	        }
	
	        file.close();
	    }
};

