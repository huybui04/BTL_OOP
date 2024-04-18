#include "NhanVien.h"
#include "DSNhanVien.h"
#include "NhanVien.cpp"
#include "DSNhanVien.cpp"
 
#include "KhachHang.h"
#include "DSKhachHang.h"
#include "KhachHang.cpp"
#include "DSKhachHang.cpp"

#include "NhaCungCap.h"
#include "DSNhaCungCap.h"
#include "NhaCungCap.cpp"
#include "DSNhaCungCap.cpp"

#include "SanPham.h"
#include "DSSanPham.h"
#include "SanPham.cpp"
#include "DSSanPham.cpp"

#include "NguyenLieu.h"
#include "DSNguyenLieu.h"
#include "NguyenLieu.cpp"
#include "DSNguyenLieu.cpp"

#include "Ban.h"
#include "DSBan.h"
#include "Ban.cpp"
#include "DSBan.cpp"

#include "HoaDonBan.h"
#include "DSHoaDonBan.h"
#include "HoaDonBan.cpp"
#include "DSHoaDonBan.cpp"

#include "ChiTietHoaDonBan.h"
#include "DSChiTietHoaDonBan.h"
#include "ChiTietHoaDonBan.cpp"
#include "DSChiTietHoaDonBan.cpp"

#include "HoaDonNhap.h"
#include "DSHoaDonNhap.h"
#include "HoaDonNhap.cpp"
#include "DSHoaDonNhap.cpp"

#include "ChiTietHoaDonNhap.h"
#include "DSChiTietHoaDonNhap.h"
#include "ChiTietHoaDonNhap.cpp"
#include "DSChiTietHoaDonNhap.cpp"
using namespace std;

class QLQuanCafe {
	private:
		DSNhanVien dsnv;
		DSKhachHang dskh;
		DSNhaCungCap dsncc;
		DSSanPham dssp;
		DSNguyenLieu dsnl;
		DSBan dsban;
		DSHoaDonBan dshdb;
		DSChiTietHoaDonBan dscthdb;
		DSHoaDonNhap dshdn;
		DSChiTietHoaDonNhap dscthdn;
		
		const string tenFileDSNhanVien = "nhanvien.txt";
		const string tenFileDSKhachHang = "khachhang.txt";
		const string tenFileDSNhaCungCap = "nhacungcap.txt";
		const string tenFileDSSanPham = "sanpham.txt";
		const string tenFileDSNguyenLieu = "nguyenlieu.txt";
		const string tenFileDSBan = "ban.txt";
		const string tenFileDSHoaDonBan = "hoadonban.txt";
		const string tenFileDSChiTietHoaDonBan = "chitiethoadonban.txt";
		const string tenFileDSHoaDonNhap = "hoadonnhap.txt";
		const string tenFileDSChiTietHoaDonNhap = "chitiethoadonnhap.txt";
	public:
		QLQuanCafe() {}
		void tao() {
			dsnv.docDuLieuTuFile();
			dskh.docTuFile();
			dsncc.docDuLieuTuFile();
			dssp.docDuLieuTuFile();
			dsnl.docDuLieuTuFile();
			dsban.docDuLieuTuFile();
			dscthdb.docDuLieuTuFile();
			
		}
		void hienThiDSNV() {
			dsnv.hienThiDanhSach();	
		}
		void hienThiDSKH() {
			dskh.hienThiDanhSach();	
		}
		void hienThiDSNCC() {
			dsncc.hienThiDanhSach();	
		}
		void hienThiDSSP() {
			dssp.hienThiDanhSach();	
		}
		void hienThiDSNL() {
			dsnl.hienThiDanhSach();	
		}
		void hienThiDSBan() {
			dsban.hienThiDanhSach();	
		}
		void hienThiDSChiTietHoaDonBan() {
			dscthdb.hienThiDanhSach();
		}
		void taoHoaDonBan() {
			int soLuongMua ;
			std::string mhdb;
			std::string mnv;
			std::string mkh;
			std::string mban;
			std::string ngayban;
			std::string msp;
			int soluong;
			vector<ChiTietHoaDonBan> ds;
			
			std::cout << "Nhap so loai san pham muon mua: "; std::cin >> soLuongMua;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Nhap ma hoa don ban: ";
			std::getline(std::cin, mhdb);
			std::cout << "Nhap ma ma nhan vien: ";
			std::getline(std::cin, mnv);
			std::cout << "Nhap ma khach hang: ";
			std::getline(std::cin, mkh);
			std::cout << "Nhap ma ma ban: ";
			std::getline(std::cin, mban);
			std::cout << "Nhap ngay ban: ";
			std::getline(std::cin, ngayban);
			for(int i = 0; i < soLuongMua; i++) {
				std::cout << "Nhap ma san pham thu " << i + 1 << ": ";
				std::getline(std::cin, msp);
				std::cout << "Nhap so luong thu " << i + 1 << ": ";
				std::cin >> soluong;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				
				SanPham cthdb_sp;
				cthdb_sp.setMaSP(msp);
				
				for(auto sp : this->dssp.getDSSP()) {
					if(sp.getMaSP() == cthdb_sp.getMaSP()) {
						cthdb_sp.setTenSP(sp.getTenSP());
						cthdb_sp.setGia(sp.getGia());
					}
				}
				
				ChiTietHoaDonBan cthd(mhdb, msp, soluong, cthdb_sp);
				ds.push_back(cthd);
			}		
			
			HoaDonBan hdb(mhdb,mnv,mkh,mban,ngayban,ds);
			hdb.hienThi();
		}
		void hienThiDSHoaDonBan() {
			
		}
		
};

int main() {
	QLQuanCafe qlcf;
	qlcf.tao();
	qlcf.hienThiDSNV();
	qlcf.hienThiDSKH();
	qlcf.hienThiDSNCC();
	qlcf.hienThiDSSP();
	qlcf.hienThiDSNL();
	qlcf.hienThiDSBan();
	qlcf.hienThiDSChiTietHoaDonBan();
	qlcf.taoHoaDonBan();
}
