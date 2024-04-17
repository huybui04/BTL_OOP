#include<iostream>
#include<vector>
using namespace std;

class NhaCungCap {
	private:
		string MaNCC, TenNCC, DiaChi, SDT;
	public:
		NhaCungCap() {}
		NhaCungCap(string MaNCC, string TenNCC, string DiaChi, string SDT)
        :MaNCC(MaNCC), TenNCC(TenNCC), DiaChi(DiaChi), SDT(SDT) {}
		string getMaNCC()  {
	        return MaNCC;
	    }
	    void setMaNCC(string maNCC) {
	        MaNCC = maNCC;
	    }
	    string getTenNCC()  {
	        return TenNCC;
	    }
	    void setTenNCC( string tenNCC) {
	        TenNCC = tenNCC;
	    }
	    string getDiaChi()  {
	        return DiaChi;
	    }
	    void setDiaChi(string diaChi) {
	        DiaChi = diaChi;
	    }
	    string getSDT()  {
	        return SDT;
	    }
	    void setSDT(string sdt) {
	        SDT = sdt;
	    }
	    void nhap() {
	        cout << "Nhap Ma NCC: ";
	        getline(cin, MaNCC);
	        cout << "Nhap Ten NCC: ";
	        getline(cin, TenNCC);
	        cout << "Nhap Dia Chi: ";
	        getline(cin, DiaChi);
	        cout << "Nhap SDT: ";
	        getline(cin, SDT);
	    }
	    void xuat() {
	        cout << "Ma NCC: " << MaNCC << endl;
	        cout << "Ten NCC: " << TenNCC << endl;
	        cout << "Dia Chi: " << DiaChi << endl;
	        cout << "SDT: " << SDT << endl;
	    }
	    void luuVaoFile(ofstream &file) {
	        file << MaNCC << "," << TenNCC << "," << DiaChi << "," << SDT << endl;
	    }
};

class DSNhaCungCap {
	private:
	    vector<NhaCungCap> danhSachNhaCungCap;
	
	public:
	    void themNhaCungCap() {
	    	NhaCungCap ncc;
	    	ncc.nhap();
	        danhSachNhaCungCap.push_back(ncc);
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
	            string maNCC, tenNCC, diaChi, sdt;
	
	            getline(ss, maNCC, ',');
	            getline(ss, tenNCC, ',');
	            getline(ss, diaChi, ',');
	            getline(ss, sdt);
	
	            NhaCungCap ncc(maNCC, tenNCC, diaChi, sdt);
	            themNhaCungCap(ncc);
	        }
	
	        file.close();
	    }

	    void hienThiDanhSach()  {
	        for (auto ncc : danhSachNhaCungCap) {
	            cout << "MaNCC: " << ncc.getMaNCC() << endl;
	            cout << "TenNCC: " << ncc.getTenNCC() << endl;
	            cout << "DiaChi: " << ncc.getDiaChi() << endl;
	            cout << "SDT: " << ncc.getSDT() << endl;
	            cout << endl;
	        }
	    }
		
		void suaNhaCungCap(string maNCC,NhaCungCap ncc) {
		    bool timThay = false;
		    for (auto& nhacungcap : danhSachNhaCungCap) {
		        if (nhacungcap.getMaNCC() == maNCC) {
		            nhacungcap = ncc;
		            timThay = true;
		            break;
		        }
		    }
		
		    if (!timThay) {
		        cout << "Khong tim thay nha cung cap co MaNCC: " << maNCC << endl;
		    }
		}
		void xoaNhaCungCap(string maNCC) {
		    bool timThay = false;
		    for (auto it = danhSachNhaCungCap.begin(); it != danhSachNhaCungCap.end(); ++it) {
		        if (it->getMaNCC() == maNCC) {
		            danhSachNhaCungCap.erase(it);
		            timThay = true;
		            cout << "Da xoa nha cung cap co MaNCC: " << maNCC << endl;
		            break;
		        }
		    }
		
		    if (!timThay) {
		        cout << "Khong tim thay nha cung cap co MaNCC: " << maNCC << endl;
		    }
		}
		void luuVaoFile(string tenTep) {
	        ofstream file(tenTep);
	        if (!file.is_open()) {
	            cerr << "Khong mo duoc file" << endl;
	            return;
	        }
	
	        for (auto ncc : danhSachNhaCungCap) {
	            ncc.luuVaoFile(file);
	        }
	
		    file.close();
		}
};

