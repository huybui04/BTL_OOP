#include<iostream>
#include<vector>
using namespace std;

class NhanVien {
	private:
		string MaNV, TenNV, SDT, GioiTinh, DiaChi, ChucVu, NgaySinh;
	public:
		NhanVien() {}
		NhanVien(string MaNV,string TenNV,string SDT,string GioiTinh,string DiaChi,string NgaySinh)
        :MaNV(MaNV), TenNV(TenNV), SDT(SDT), GioiTinh(GioiTinh), DiaChi(DiaChi), NgaySinh(NgaySinh) {}
		string getMaNV()  {
	        return MaNV;
	    }
	    void setMaNV(string maNV) {
	        MaNV = maNV;
	    }
	    string getTenNV()  {
	        return TenNV;
	    }
	    void setTenNV( string tenNV) {
	        TenNV = tenNV;
	    }
	    string getSDT()  {
	        return SDT;
	    }
	    void setSDT( string sdt) {
	        SDT = sdt;
	    }
	    string getGioiTinh()  {
	        return GioiTinh;
	    }	
	    void setGioiTinh(string gioiTinh) {
	        GioiTinh = gioiTinh;
	    }
		string getDiaChi()  {
	        return DiaChi
	    }
	    void setDiaChi(string diaChi) {
	        DiaChi = diaChi;
	    }
	    string getChucVu()  {
	        return ChucVu;
	    }
	    void setChucVu(string chucVu) {
	        ChucVu = chucVu;
	    }
	    string getNgaySinh() {
	        return NgaySinh;
	    }
	    void setNgaySinh(string ngaySinh) {
	        NgaySinh = ngaySinh;
	    }
	    void nhap() {
	        cout << "Nhap Ma NV: ";
	        getline(cin, MaNV);
	        cout << "Nhap Ten NV: ";
	        getline(cin, TenNV);
	        cout << "Nhap SDT: ";
	        getline(cin, SDT);
	        cout << "Nhap Gioi Tinh: ";
	        getline(cin, GioiTinh);
	        cout << "Nhap Dia Chi: ";
	        getline(cin, DiaChi);
	        cout << "Nhap Ngay Sinh: ";
	        getline(cin, NgaySinh);
	    }
	    void xuat() {
	        cout << "Ma NV: " << MaNV << endl;
	        cout << "Ten NV: " << TenNV << endl;
	        cout << "SDT: " << SDT << endl;
	        cout << "Gioi Tinh: " << GioiTinh << endl;
	        cout << "Dia Chi: " << DiaChi << endl;
	        cout << "Ngay Sinh: " << NgaySinh << endl;
	    }
	    void luuVaoFile(ofstream file) {
	        file << MaNV << "," << TenNV << "," << SDT << "," << GioiTinh << "," << DiaChi << "," << NgaySinh << endl;
	    }
};

class DSNhanVien {
	private:
	    vector<NhanVien> danhSachNhanVien;
	
	public:
		vector<NhanVien> getDSNV() {
			return danhSachNhanVien;
		}
	    void themNhanVien() {
	    	NhanVien nv;
	    	nv.nhap();
	        danhSachNhanVien.push_back(nv);
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
	            string maNV, tenNV, sdt, gioiTinh, diaChi, ngaySinh;
	
	            getline(ss, maNV, ',');
	            getline(ss, tenNV, ',');
	            getline(ss, sdt, ',');
	            getline(ss, gioiTinh, ',');
	            getline(ss, diaChi, ',');
	            getline(ss, ngaySinh);
	
	            NhanVien nv(maNV, tenNV, sdt, gioiTinh, diaChi, ngaySinh);
	            themNhanVien(nv);
	        }
	
	        file.close();
	    }

	    void hienThiDanhSach()  {
	        for (auto nv : danhSachNhanVien) {
	            cout << "MaNV: " << nv.getMaNV() << endl;
	            cout << "TenNV: " << nv.getTenNV() << endl;
	            cout << "SDT: " << nv.getSDT() << endl;
	            cout << "GioiTinh: " << nv.getGioiTinh() << endl;
	            cout << "DiaChi: " << nv.getDiaChi() << endl;
	            cout << "NgaySinh: " << nv.getNgaySinh() << endl;
	            cout << endl;
	        }
	    }
		
		void suaNhanVien(string maNV,NhanVien nv) {
		    bool timThay = false;
		    for (auto& nhanvien : danhSachNhanVien) {
		        if (nhanvien.getMaNV() == maNV) {
		            nhanvien = nv;
		            timThay = true;
		            break;
		        }
		    }
		
		    if (!timThay) {
		        cout << "Khong tim thay nhan vien co MaNV: " << maNV << endl;
		    }
		}
		void xoaNhanVien(string maNV) {
		    bool timThay = false;
		    for (auto it = danhSachNhanVien.begin(); it != danhSachNhanVien.end(); ++it) {
		        if (it->getMaNV() == maNV) {
		            danhSachNhanVien.erase(it);
		            timThay = true;
		            cout << "Da xoa nhan vien co MaNV: " << maNV << endl;
		            break;
		        }
		    }
		
		    if (!timThay) {
		        cout << "Khong tim thay nhan vien co MaNV: " << maNV << endl;
		    }
		}
		
		NhanVien timKiemNhanVien(string maNV) {
	        for (auto nv : danhSachNhanVien) {
	            if (nv.getMaNV() == maNV) {
	                return nv;
	            }
	        }
	
	        cout << "Khong tim thay nhan vien co MaNV: " + maNV; 
	    }
	    
		void luuVaoFile(string tenTep) {
	        ofstream file(tenTep);
	        if (!file.is_open()) {
	            cout << "Khong mo duoc file" << endl;
	            return;
	        }
	
	        for (auto nv : danhSachNhanVien) {
	            nv.luuVaoFile(file);
	        }
	
		    file.close();
		}
};


