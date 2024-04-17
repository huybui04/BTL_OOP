#include<iostream>
#include<vector>
#include<algorithm>

#include "NhanVien.cpp"
#include "KhachHang.cpp"
#include "Ban.cpp"
#include "ChiTietHoaDonBan.cpp"

using namespace std;

class HoaDonBan {
	private:
		String MaHDB, NgayBan;
		NhanVien nv;
		KhachHang kh;
		Ban ban;
		vector<ChiTietHoaDonBan> dsCTHDB;
	public:
	 	HoaDonBan() {}
    	HoaDonBan(string maHDB, string ngayBan, NhanVien nhanVien, KhachHang khachHang, Ban ban)
        :MaHDB(maHDB), NgayBan(ngayBan), nv(nhanVien), kh(khachHang), ban(ban) {}
        
        void setMaHDB(string maHDB) { MaHDB = maHDB; }
	    string getMaHDB() { return MaHDB; }
	
	    void setNgayBan(string ngayBan) { NgayBan = ngayBan; }
	    string getNgayBan() { return NgayBan; }
	
	    void setNhanVien(NhanVien nhanVien) { nv = nhanVien; }
	    NhanVien getNhanVien() { return nv; }
	
	    void setKhachHang(KhachHang khachHang) { kh = khachHang; }
	    KhachHang getKhachHang() { return kh; }
	
	    void setBan(Ban ban) { this->ban = ban; }
	    Ban getBan() { return ban; }
	
	    void setDsCTHDB(vector<ChiTietHoaDonBan> ds) { dsCTHDB = ds; }
	    vector<ChiTietHoaDonBan> getDsCTHDB() { return dsCTHDB; }
        
	    void themChiTietHoaDon(ChiTietHoaDonBan chiTiet) {
	        dsCTHDB.push_back(chiTiet);
	    }
	    double tinhTongTien() {
	        double tongTien = 0.0;
	        for (auto ct : dsCTHDB) {
	        	if (ct.getHDB().MaHDB==this->MaHDB)
	            tongTien += ct.tinhThanhTien();
	        }
	        return tongTien;
	    }
	    void hienThi() {
	        cout << "Ma Hoa Don: " << MaHDB << endl;
	        cout << "Ngay Ban: " << NgayBan << endl;
	        cout << "Nhan Vien: " << nv->getTenNV() << endl;
	        cout << "Khach Hang: " << kh->getTenKH() << endl;
	        cout << "Ban: " << ban->getTenBan() << endl;
	        cout << "Danh Sach Chi Tiet Hoa Don Ban:" << endl;
	        for (auto ct : dsCTHDB) {
	        	if(ct.getHDB().MaHDB==this->MaHDB)
	            cout << "   + " << ct.sp->getTenSP() << " - So Luong: " << ct.SoLuong << " - Thanh Tien: " << ct.tinhThanhTien() << std::endl;
	        }
	        cout << "Tong Tien: " << tinhTongTien() << std::endl;
	    }
    
};

class DSHoaDonBan {
	private:
	    vector<HoaDonBan> danhSachHoaDon;
	public:
		vector<HoaDonBan> getDSHDB() {
			return danhSachHoaDon;
		}
	    void themHoaDon(HoaDonBan hoaDon) {
	        danhSachHoaDon.push_back(hoaDon);
	    }
	
	    void xoaHoaDon(string maHDB) {
	        for (auto it = danhSachHoaDon.begin(); it != danhSachHoaDon.end(); ++it) {
	            if (it->getMaHDB() == maHDB) {
	                danhSachHoaDon.erase(it);
	                break;
	            }
	        }
	    }
	
	    void suaHoaDon(string maHDB, HoaDonBan hoaDonMoi) {
	        for (auto hoaDon : danhSachHoaDon) {
	            if (hoaDon.getMaHDB() == maHDB) {
	                hoaDon = hoaDonMoi;
	                break;
	            }
	        }
	    }
	
	    HoaDonBan timKiemHoaDon(string maHDB) {
	        for (auto hoaDon : danhSachHoaDon) {
	            if (hoaDon.getMaHDB() == maHDB) {
	                return hoaDon;
	            }
	        }
	        return HoaDonBan();
	    }
	
	    void docDuLieuTuFile(string tenFile) {
	        ifstream file(tenFile);
	        if (file.is_open()) {
	            while (!file.eof()) {
	                
	            }
	            file.close();
	        } else {
	            cout << "Khong mo duoc file!" << endl;
	        }
	    }
	
	    void ghiDuLieuVaoFile(string tenFile) {
	        ofstream file(tenFile);
	        if (file.is_open()) {
	            for (hoaDon : danhSachHoaDon) {
	                
	            }
	            file.close();
	        } else {
	            cout << "Khong mo duoc file!" << endl;
	        }
	    }
};
