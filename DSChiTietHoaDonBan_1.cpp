#include<iostream>
#include<vector>
#include<algorithm>

#include "HoaDonBan.cpp"

#include "SanPham.cpp"
using namespace std;

class ChiTietHoaDonBan {
	private:
	    HoaDonBan HDB;
	    SanPham SP;
	    int SoLuong;
	public:
	    ChiTietHoaDonBan() {}
	    ChiTietHoaDonBan(HoaDonBan HDB, SanPham SP, int SoLuong)
	    :HDB(HDB), SP(SP), SoLuong(SoLuong) {}
	    HoaDonBan getHDB() {
	    	return HDB;
		}
		void setHDB(HDB hdb) {
			this->HDB=hdb;
		}
		SanPham getSP() {
			return SP;
		}
		void setSP(SanPham sp) {
			this->SP=sp;
		}
		int getSoLuong() {
			return SoLuong;
		}
		void setSoLuong() {
			return SoLuong;
		}
		
    	double tinhThanhTien() {
	        return SoLuong SP.getGia();
	    }
	    
};

class DSChiTietHoaDonBan {
	private:
		vector<ChiTietHoaDonBan> danhSachChiTietHoaDonBan;
	public:
		vector<ChiTietHoaDonBan> getCTHDB() {
			return danhSachChiTietHoaDonBan;
		}
		
		void themChiTiet(ChiTietHoaDonBan chiTiet) {
	        danhSachChiTiet.push_back(chiTiet);
	    }
	    
		void suaChiTiet(HoaDonBan hdb, ChiTietHoaDonBan chiTietMoi) {
	        for (chiTiet : danhSachChiTiet) {
	            if (chiTiet.getHDB().getMaHDB() == hdb.getMaHDB()) {
	                chiTiet = chiTietMoi;
	                break;
	            }
	        }
	    }
	    void xoaChiTiet(HoaDonBan hdb) {
	        for (auto it = danhSachChiTiet.begin(); it != danhSachChiTiet.end(); ++it) {
	            if (it->getHDB().getMaHDB() == hdb.getMaHDB()) {
	                danhSachChiTiet.erase(it);
	                break;
	            }
	        }
	    }
	    ChiTietHoaDonBan timKiemChiTiet(HoaDonBan hdb) {
	        for (auto chiTiet : danhSachChiTiet) {
	            if (chiTiet.getHDB().getMaHDB() == hdb.getMaHDB()) {
	                return chiTiet;
	            }
	        }
	        return ChiTietHoaDonBan(); 
	    }
	    void ghiDuLieuVaoFile(string tenFile) {
	        ofstream file(tenFile);
	        if (file.is_open()) {
	            for (auto chiTiet : danhSachChiTiet) {
	                file << chiTiet.getHDB().getMaHDB() << " " << chiTiet.getHDB().getMaSP() << " " << chiTiet.SoLuong << " " << endl;
	            }
	            file.close();
	        } else {
	            cout << "Khong mo duoc file!" << endl;
	        }
	    }
};
