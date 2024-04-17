#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream> 

#include "NhanVien.cpp"
#include "NhaCungCap.cpp" 
#include "Ban.cpp"
#include "ChiTietHoaDonNhap.cpp" 

using namespace std;

class HoaDonNhap {
	private:
		string MaHDN, NgayNhap;
		NhanVien nv;
		NhaCungCap ncc;
		vector<ChiTietHoaDonNhap> dsCTHDN;
	public:
	 	HoaDonNhap() {}
    	HoaDonNhap(string maHDN, string ngayNhap, NhanVien nhanVien, NhaCungCap nhaCungCap)
        :MaHDN(maHDN), NgayNhap(ngayNhap), nv(nhanVien), ncc(nhaCungCap) {}
        
        void setMaHDN(string maHDN) { MaHDN = maHDN; }
	    string getMaHDN() { return MaHDN; }
	
	    void setNgayNhap(string ngayNhap) { NgayNhap = ngayNhap; }
	    string getNgayNhap() { return NgayNhap; }
	
	    void setNhanVien(NhanVien nhanVien) { nv = nhanVien; }
	    NhanVien getNhanVien() { return nv; }
	
	    void setNhaCungCap(NhaCungCap nhaCungCap) { ncc = nhaCungCap; }
	    NhaCungCap getNhaCungCap() { return ncc; }
	
	    void setDsCTHDN(vector<ChiTietHoaDonNhap> ds) { dsCTHDN = ds; }
	    vector<ChiTietHoaDonNhap> getDsCTHDN() { return dsCTHDN; }
        
	    void themChiTietHoaDon(ChiTietHoaDonNhap chiTiet) {
	        dsCTHDN.push_back(chiTiet);
	    }
	    double tinhTongTien() {
	        double tongTien = 0.0;
	        for (auto ct : dsCTHDN) {
	        	if (ct.getHDN().MaHDN == this->MaHDN)
	            tongTien += ct.tinhThanhTien();
	        }
	        return tongTien;
	    }
	    void hienThi() {
	        cout << "Ma Hoa Don: " << MaHDN << endl;
	        cout << "Ngay Nhap: " << NgayNhap << endl;
	        cout << "Nhan Vien: " << nv.getTenNV() << endl;
	        cout << "Nha Cung Cap: " << ncc.getTenNCC() << endl;
	        cout << "Danh Sach Chi Tiet Hoa Don Nhap:" << endl;
	        for (auto ct : dsCTHDN) {
	        	if(ct.getHDN().MaHDN == this->MaHDN)
	            cout << "   + " << ct.sp.getTenSP() << " - So Luong: " << ct.SoLuong << " - Thanh Tien: " << ct.tinhThanhTien() << std::endl;
	        }
	        cout << "Tong Tien: " << tinhTongTien() << std::endl;
	    }
    
};

class DSHoaDonNhap {
	private:
	    vector<HoaDonNhap> danhSachHoaDon;
	public:
		vector<HoaDonNhap> getDSHDN() {
			return danhSachHoaDon;
		}
	    void themHoaDon(HoaDonNhap hoaDon) {
	        danhSachHoaDon.push_back(hoaDon);
	    }
	
	    void xoaHoaDon(string maHDN) {
	        for (auto it = danhSachHoaDon.begin(); it != danhSachHoaDon.end(); ++it) {
	            if (it->getMaHDN() == maHDN) {
	                danhSachHoaDon.erase(it);
	                break;
	            }
	        }
	    }
	
	    void suaHoaDon(string maHDN, HoaDonNhap hoaDonMoi) {
	        for (auto &hoaDon : danhSachHoaDon) {
	            if (hoaDon.getMaHDN() == maHDN) {
	                hoaDon = hoaDonMoi;
	                break;
	            }
	        }
	    }
	
	    HoaDonNhap timKiemHoaDon(string maHDN) {
	        for (auto hoaDon : danhSachHoaDon) {
	            if (hoaDon.getMaHDN() == maHDN) {
	                return hoaDon;
	            }
	        }
	        return HoaDonNhap();
	    }
	
	    void docDuLieuTuFile(string tenFile) {
	        ifstream file(tenFile);
	        if (file.is_open()) {
	            while (!file.eof()) {
	                // Ð?c d? li?u t? file và t?o các d?i tu?ng HoaDonNhap, thêm vào danhSachHoaDon
	            }
	            file.close();
	        } else {
	            cout << "Khong mo duoc file!" << endl;
	        }
	    }
	
	    void ghiDuLieuVaoFile(string tenFile) {
	        ofstream file(tenFile);
	        if (file.is_open()) {
	            for (auto hoaDon : danhSachHoaDon) {
	                // Ghi d? li?u c?a các d?i tu?ng HoaDonNhap vào file
	            }
	            file.close();
	        } else {
	            cout << "Khong mo duoc file!" << endl;
	        }
	    }
};

