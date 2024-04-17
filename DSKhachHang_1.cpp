#include<iostream>
#include<vector>
using namespace std;

class KhachHang {
	private:
		string MaKH, TenKH, SDT;
	public:
		KhachHang() {}
  		KhachHang(cstring maKH,string tenKH,string sdt)
        : MaKH(maKH), TenKH(tenKH), SDT(sdt) {}
		string getMaKH() {
	        return MaKH;
	    }
	    void setMaKH(string maKH) {
	        MaKH = maKH;
	    }
		string getTenKH() {
	        return TenKH;
	    }
	    void setTenKH(string tenKH) {
	        TenKH = tenKH;
	    }
	    string getSDT() {
	        return SDT;
	    }
	    void setSDT(string sdt) {
	        SDT = sdt;
	    }
	    
	    void nhap() {
	        cout << "Nhap Ma KH: ";
	        cin >> MaKH;
	        cout << "Nhap Ten KH: ";
	        cin.ignore();
	        getline(cin, TenKH);
	        cout << "Nhap SDT: ";
	        cin >> SDT;
	    }
	    void xuat() {
	        cout << "Ma KH: " << MaKH << std::endl;
	        cout << "Ten KH: " << TenKH << std::endl;
	        cout << "SDT: " << SDT << std::endl;
	    }
	    void luuVaoFile(ofstream file)  {
	        file << MaKH << "," << TenKH << "," << SDT << std::endl;
	    }
};

class DSKhachHang {
	private:
		vector<KhachHang> danhSachKhachHang;
	public:
		void themKhachHang(KhachHang khachHang) {
			khachHang.nhap();
	        danhSachKhachHang.push_back(khachHang);
	    }
	    void docTuFile(string tenFile) {
        	ifstream file(tenFile);
	        if (file.is_open()) {
	            string line;
	            while (getline(file, line)) {
	                stringstream ss(line);
	                string maKH, tenKH, sdt;
	                getline(ss, maKH, ',');
	                getline(ss, tenKH, ',');
	                getline(ss, sdt);
	
	                KhachHang kh;
	                kh.setMaKH(maKH);
	                kh.setTenKH(tenKH);
	                kh.setSDT(sdt);
	            }
	            file.close();
	        } else {
	            cout << "Khong mo duoc file " << tenFile << " de doc!" << endl;
	        }
	    }
	    void hienThiDanhSach() {
		    for (auto kh : danhSachKhachHang) {
		        cout << "MaKH: " << kh.getMaKH() << endl;
		        cout << "TenKH: " << kh.getTenKH() << endl;
		        cout << "SDT: " << kh.getSDT() << endl;
		        cout << endl;
		    }
		}
		void suaKhachHang(string maKH, KhachHang khachHang) {
	        bool timThay = false;
	        for (auto kh : danhSachKhachHang) {
	            if (kh.getMaKH() == maKH) {
	                kh = khachHang;
	                timThay = true;
	                break;
	            }
	        }
	
	        if (!timThay) {
	            cout << "Khong tim thay khach hang co MaKH: " << maKH << endl;
	        }
	    }
	    void xoaKhachHang(string maKH) {
	        bool timThay = false;
	        for (auto it = danhSachKhachHang.begin(); it != danhSachKhachHang.end(); ++it) {
	            if (it->getMaKH() == maKH) {
	                danhSachKhachHang.erase(it);
	                timThay = true;
	                cout << "Da xoa khach hang co MaKH: " << maKH << std::endl;
	                break;
	            }
	        }
	
	        if (!timThay) {
	            cout << "Khong tim thay khach hang co MaKH: " << maKH << endl;
	        }
	    }
	    void luuVaoFile(string tenTep) {
	        ofstream file(tenTep);
	        if (!file.is_open()) {
	            cout << "Khong mo duoc file" << endl;
	            return;
	        }
	
	        for (auto kh : danhSachKhachHang) {
	            kh.luuVaoFile(file);
	        }
	
	        file.close();
	    }
};

