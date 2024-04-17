//#include "DSNhanVien_1.cpp"
//#include "DSKhachHang_1.cpp"
//#include "DSNhaCungCap_1.cpp"
//#include "DSSanPham_1.cpp"
//#include "DSNguyenLieu_1.cpp"
//#include "DSBan_1.cpp"
//#include "DSHoaDonBan_1.cpp"
//#include "DSChiTietHoaDonBan_1.cpp"
//#include "DSHoaDonBan_1.cpp"
//#include "DSChiTietHoaDonNhap_1.cpp"

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
	public:
		QLQuanCafe() {}
		void tao() {
			dsnv.docDuLieuTuFile("nhanvien.txt");
			dskh.docTuFile("khachhang.txt");
			dsncc.docDuLieuTuFile("nhacungcap.txt");
			dssp.docDuLieuTuFile("sanpham.txt");
			dsnl.docDuLieuTuFile("nguyenlieu.txt");
			dsban.docDuLieuTuFile("ban.txt");
			dscthdb.docDuLieuTuFile("chitiethoadonban.txt");
			
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
			std::string mhdb = "HDB01";
			std::string mnv = "MaNV01";
			std::string mkh = "MaKH01";
			std::string mban = "MaBan01";
			std::string ngayban = "1/1/2020";
			vector<ChiTietHoaDonBan> ds_1 = dscthdb.getDSCTHDB();
			vector<SanPham> ds_2 = dssp.getDSSP();
			for (auto ct : ds_1) {
				ct.setDSSP(ds_2);
			}
			
			HoaDonBan hdb(mhdb,mnv,mkh,mban,ngayban,ds_1);
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
