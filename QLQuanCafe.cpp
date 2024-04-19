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

#include "ChiTietSanPham.h"
#include "DSChiTietSanPham.h"
#include "ChiTietSanPham.cpp"
#include "DSChiTietSanPham.cpp"

#include <bits/stdc++.h>

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    size_t last = str.find_last_not_of(" \t\n\r");
    if (first == std::string::npos || last == std::string::npos)
        return "";
    return str.substr(first, last - first + 1);
}

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
		DSChiTietSanPham dsctsp;
		
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
		const string tenFileDSChiTietSanPham = "chitietsanpham.txt";
	public:
		QLQuanCafe() {}
		void tao() {
			dsnv.docDuLieuTuFile(tenFileDSNhanVien);
			dskh.docTuFile(tenFileDSKhachHang);
			dsncc.docDuLieuTuFile(tenFileDSNhaCungCap);
			dssp.docDuLieuTuFile(tenFileDSSanPham);
			dsnl.docDuLieuTuFile(tenFileDSNguyenLieu);
			dsban.docDuLieuTuFile(tenFileDSBan);
			dscthdb.docDuLieuTuFile(tenFileDSChiTietHoaDonBan);
			dshdb.docDuLieuTuFile(tenFileDSHoaDonBan);
			dscthdn.docDuLieuTuFile(tenFileDSChiTietHoaDonNhap);
			dsctsp.docDuLieuTuFile(tenFileDSChiTietSanPham);
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
		void hienThiDSHoaDonBan() {
			dshdb.hienThiDanhSach();
		}
		void hienThiDSChiTietHoaDonNhap() {
			dscthdn.hienThiDanhSach();
		}
		void hienThiDSChiTietSanPham() {
			dsctsp.hienThiDanhSach();
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
				cthd.luuVaoFile(tenFileDSChiTietHoaDonBan);
				ds.push_back(cthd);	
			}		
			
			HoaDonBan hdb(mhdb,ngayban,mnv,mkh,mban,ds);
			hdb.luuVaoFile(tenFileDSHoaDonBan);
			hdb.hienThi();
		}
		
		void taoHoaDonNhap() {
			int soLuongNhap;
			std::string mhdn;
			std::string mnv;
			std::string mncc;
			std::string ngaynhap;
			std::string mnl;
			int soluong;
			vector<ChiTietHoaDonNhap> ds;
			
			std::cout << "Nhap so loai nguyen lieu muon nhap: "; std::cin >> soLuongNhap;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Nhap ma hoa don nhap: ";
			std::getline(std::cin, mhdn);
			std::cout << "Nhap ma ma nhan vien: ";
			std::getline(std::cin, mnv);
			std::cout << "Nhap ma nha cung cap: ";
			std::getline(std::cin, mncc);
			std::cout << "Nhap ngay nhap: ";
			std::getline(std::cin, ngaynhap);
			for(int i = 0; i < soLuongNhap; i++) {
				std::cout << "Nhap ma nguyen lieu thu " << i + 1 << ": ";
				std::getline(std::cin, mnl);
				std::cout << "Nhap so luong thu " << i + 1 << ": ";
				std::cin >> soluong;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				
				NguyenLieu cthdn_nl;
				cthdn_nl.setMaNL(mnl);
				
				for(auto nl : this->dsnl.getDSNL()) {
					if(nl.getMaNL() == cthdn_nl.getMaNL()) {
						cthdn_nl.setTenNL(nl.getTenNL());
						cthdn_nl.setGia(nl.getGia());
					}
				}
				
				
				ChiTietHoaDonNhap cthd(mhdn, mnl, soluong, cthdn_nl);
				cthd.luuVaoFile(tenFileDSChiTietHoaDonNhap);
				ds.push_back(cthd);	
			}		
			
			HoaDonNhap hdn(mhdn,ngaynhap,mnv,mncc,ds);
			hdn.luuVaoFile(tenFileDSHoaDonNhap);
			hdn.hienThi();
		}
		
		int tinhTongSoNguyenLieuNhap() {
			string manl;
			cout << "Nhap ma nguyen lieu muon tim tong so luong nhap: ";
			std::getline(std::cin, manl);
			
			int tongSLBD = 0;
		
			for(auto cthdn : this->dscthdn.getDSCTHDN())
			{	
				if(manl == trim(cthdn.getMaNL()))
				{
					tongSLBD +=	cthdn.getSoLuongNhap();
				}	
			}	
			return tongSLBD;
		}
		
		int tinhTongSoNguyenLieuSuDung() {
			string manl;
			cout << "Nhap ma nguyen lieu muon tim tong so luong su dung: "; 
			std::getline(std::cin, manl);
			vector<pair<string, int>> ds_masp_soluong_lienquan;
			
			int tongSLSD = 0;
			
			for(auto ctsp : this->dsctsp.getDSCTSP()) 
			{
				if(ctsp.getMaNL() == manl)
				{
					ds_masp_soluong_lienquan.push_back({ctsp.getMaSP(), ctsp.getSoLuongSuDung()}); 
				}
			}
			
			for(auto cthdb : this->dscthdb.getDSCTHDB())
			{
				for(auto masp_soluong : ds_masp_soluong_lienquan)
				if(cthdb.getMaSP() == masp_soluong.first)
				{
					tongSLSD += cthdb.getSoLuong()*masp_soluong.second;
				}
			}
			
			return tongSLSD;
		}
		
		int tinhTongSoNguyenLieuTonKho() {
			int TongNLBD = tinhTongSoNguyenLieuNhap();
			int TongNLSD = tinhTongSoNguyenLieuSuDung();
			return TongNLBD - TongNLSD;
		}
};

int main()
{
	QLQuanCafe qlcf;

	qlcf.tao(); // Doc du lieu tu file
	cout << "\n\t\tDanh sach nhan vien\n\n";
	qlcf.hienThiDSNV();
	cout << "\n\t\tDanh sach khach hang\n\n";
	qlcf.hienThiDSKH();
	cout << "\n\t\tDanh sach nha cung cap\n\n";
	qlcf.hienThiDSNCC();
	cout << "\n\t\tDanh sach san pham\n\n";
	qlcf.hienThiDSSP();
	cout << "\n\t\tDanh sach nguyen lieu\n\n";
	qlcf.hienThiDSNL();
	cout << "\n\t\tDanh sach ban\n\n";
	qlcf.hienThiDSBan();
	cout << "\n\t\tDanh sach chi tiet hoa don ban\n\n";
	qlcf.hienThiDSChiTietHoaDonBan();
	cout << "\n\t\tDanh sach chi tiet hoa don nhap\n\n";
	qlcf.hienThiDSChiTietHoaDonNhap();
	
	cout << "\n\t\tTao hoa don nhap\n\n";
	qlcf.taoHoaDonNhap();
	cout << "\n\t\tTao hoa don ban\n\n";
	qlcf.taoHoaDonBan();
	
	cout << qlcf.tinhTongSoNguyenLieuTonKho();

}
