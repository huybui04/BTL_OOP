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

#include <bits/stdc++.h>
using namespace std;

class QLQuanCafe
{
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
	void tao()
	{
		dsnv.docDuLieuTuFile(tenFileDSNhanVien);
		dskh.docTuFile(tenFileDSKhachHang);
		dsncc.docDuLieuTuFile(tenFileDSNhaCungCap);
		dssp.docDuLieuTuFile(tenFileDSSanPham);
		dsnl.docDuLieuTuFile(tenFileDSNguyenLieu);
		dsban.docDuLieuTuFile(tenFileDSBan);
		dscthdb.docDuLieuTuFile(tenFileDSChiTietHoaDonBan);
	}
	void hienThiDSNV()
	{
		dsnv.hienThiDanhSach();
	}
	void hienThiDSKH()
	{
		dskh.hienThiDanhSach();
	}
	void hienThiDSNCC()
	{
		dsncc.hienThiDanhSach();
	}
	void hienThiDSSP()
	{
		dssp.hienThiDanhSach();
	}
	void hienThiDSNL()
	{
		dsnl.hienThiDanhSach();
	}
	void hienThiDSBan()
	{
		dsban.hienThiDanhSach();
	}
	void hienThiDSChiTietHoaDonBan()
	{
		dscthdb.hienThiDanhSach();
	}
	// void taoHoaDonBan()
	// {
	// 	int soLuongMua;
	// 	string mhdb;
	// 	string mnv;
	// 	string mkh;
	// 	string mban;
	// 	string ngayban;

	// 	string msp;
	// 	int soluong;
	// 	vector<ChiTietHoaDonBan> ds;

	// 	cout << "Nhap so loai san pham muon mua: ";
	// 	cin >> soLuongMua;
	// 	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	// 	cout << "Nhap ma hoa don ban: ";
	// 	getline(cin, mhdb);
	// 	cout << "Nhap ma nhan vien: ";
	// 	getline(cin, mnv);
	// 	cout << "Nhap ma khach hang: ";
	// 	getline(cin, mkh);
	// 	cout << "Nhap ma ban: ";
	// 	getline(cin, mban);
	// 	cout << "Nhap ngay ban: ";
	// 	getline(cin, ngayban);
	// for (int i = 0; i < soLuongMua; i++)
	// {
	// 	cout << "Nhap ma san pham thu " << i + 1 << ": ";
	// 	getline(cin, msp);
	// 	cout << "Nhap so luong san pham thu " << i + 1 << ": ";
	// 	cin >> soluong;
	// 	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// 	SanPham cthdb_sp;
	// 	cthdb_sp.setMaSP(msp);

	// 	for (auto sp : this->dssp.getDSSP())
	// 	{
	// 		if (sp.getMaSP() == cthdb_sp.getMaSP())
	// 		{
	// 			cthdb_sp.setTenSP(sp.getTenSP());
	// 			cthdb_sp.setGia(sp.getGia());
	// 		}
	// 	}

	// 	ChiTietHoaDonBan cthd(mhdb, msp, soluong, cthdb_sp);
	// 	ds.push_back(cthd);
	// }

	// 	HoaDonBan hdb(mhdb, mnv, mkh, mban, ngayban, ds);
	// 	hdb.hienThi();
	// }

	void taoChiTietHoaDon(string billId, string staffId, string customerId, string tableId, string date)
	{
		int n_product;
		string productId;
		int quantity;
		vector<ChiTietHoaDonBan> ds;

		cout << "Nhap so loai san pham muon mua: ";
		cin >> n_product;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		for (int i = 0; i < n_product; i++)
		{
			SanPham p;
			cout << "Nhap ma san pham thu " << i + 1 << ": ";
			getline(cin, productId);
			p.setMaSP(productId);

			for (auto sp : dssp.getDSSP())
			{
				if (sp.getMaSP() == p.getMaSP())
				{
					p.setTenSP(sp.getTenSP());
					p.setGia(sp.getGia());
				}
			}
			cout << "Nhap so luong san pham '" << p.getTenSP() << "' muon mua: ";
			cin >> quantity;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			// them vao ds chi tiet hoa don ban
			ChiTietHoaDonBan cthd(billId, productId, quantity, p);
			ds.push_back(cthd);
		}
		cout << "\n======================================================\n";
		cout << "Chi tiet hoa don mua hang:\n";
		HoaDonBan hdb(billId, date, staffId, customerId, tableId, ds);
		hdb.hienThi();
		cout << "\n======================================================\n";
	}

	void taoHoaDonBan()
	{
		string billId;
		string staffId;
		string customerId;
		string tableId;
		string date;

		cout << "Nhap ngay ban: ";
		getline(cin, date);
		cout << "Nhap ma hoa don: ";
		getline(cin, billId);
		cout << "Nhap ma nhan vien: ";
		getline(cin, staffId);
		cout << "Nhap ma khach hang: ";
		getline(cin, customerId);
		cout << "Nhap ma ban: ";
		getline(cin, tableId);
		// check nv, kh, ban
		if (dsnv.timKiemTheoMa(staffId) == nullptr)
		{
			cout << "Nhan vien khong ton tai" << endl;
			return;
		}
		if (dskh.timKiemTheoMa(customerId) == nullptr)
		{
			KhachHang kh;
			string tenKhach;
			kh.setMaKH(customerId);
			cout << "Nhap ten khach hang: ";
			getline(cin, tenKhach);
			kh.setTenKH(tenKhach);
			dskh.themKhachHang(kh);

			//(check)
			for (auto kh : dskh.getDanhSachKhachHang())
			{
				if (kh.getMaKH() == customerId)
				{
					cout << "Khach hang da duoc them" << endl;
					kh.xuat();
				}
				else
					cout << "Khong tim thay khach hang" << endl;
			}
		}
		if (dsban.timKiemTheoMa(tableId) == nullptr)
		{
			cout << "Ban khong ton tai" << endl;
			return;
		}
		// check hoa don ban
		for (auto ct : dscthdb.getDSCTHDB())
		{
			if (ct.getMaHDB() == billId)
			{
				cout << "Hoa don da ton tai" << endl;
				return;
			}
			else
			{
				taoChiTietHoaDon(billId, date, staffId, customerId, tableId);
			}
		}
	}

	void hienThiDSHoaDonBan()
	{
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
	cout << "\n\t\tTao hoa don ban\n\n";
	qlcf.taoHoaDonBan();
}
