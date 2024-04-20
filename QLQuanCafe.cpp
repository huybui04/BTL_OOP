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

#include "CaLamViec.h"
#include "DSCaLamViec.h"
#include "CaLamViec.cpp"
#include "DSCaLamViec.cpp"

#include "ChiTietLuong.h"
#include "DSChiTietLuong.h"
#include "ChiTietLuong.cpp"
#include "DSChiTietLuong.cpp"

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

	DSChiTietLuong dsctl;

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

	void hienThiDSChiTietLuong()
	{
		dsctl.hienThiDanhSach();
	}

	void taoChiTietHoaDon(string billId, string date, string staffId, string customerId, string tableId)
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

	// qlcf.tao(); // Doc du lieu tu file
	// cout << "\n\t\tDanh sach nhan vien\n\n";
	// qlcf.hienThiDSNV();
	// cout << "\n\t\tDanh sach khach hang\n\n";
	// qlcf.hienThiDSKH();
	// cout << "\n\t\tDanh sach nha cung cap\n\n";
	// qlcf.hienThiDSNCC();
	// cout << "\n\t\tDanh sach san pham\n\n";
	// qlcf.hienThiDSSP();
	// cout << "\n\t\tDanh sach nguyen lieu\n\n";
	// qlcf.hienThiDSNL();
	// cout << "\n\t\tDanh sach ban\n\n";
	// qlcf.hienThiDSBan();
	// cout << "\n\t\tDanh sach chi tiet hoa don ban\n\n";
	// qlcf.hienThiDSChiTietHoaDonBan();
	// cout << "\n\t\tTao hoa don ban\n\n";
	// qlcf.taoHoaDonBan();

	cout << "\n\t\tDanh sach chi tiet luong\n\n";
	qlcf.hienThiDSChiTietLuong();

	string tenfile = "chitietluong.txt";
	DSChiTietLuong dsctl;
	ChiTietLuong ctl;
	ChiTietLuong ctl1("NV02", "Ca01", 10, 1);
	ChiTietLuong ctl2("NV03", "Ca02", 20, 2);

	// ChiTietLuong ctl4("NV04", "Ca02", 10, 1);
	// ChiTietLuong ctl5("NV05", "Ca03", 20, 2);

	dsctl.themChiTietLuong(ctl1);
	dsctl.themChiTietLuong(ctl2);

	// dsctl.themChiTietLuong(ctl4);
	// dsctl.themChiTietLuong(ctl5);
	dsctl.ghiDuLieuVaoFile(tenfile);
	// ctl.nhap();
	// dsctl.themChiTietLuong(ctl);
	// dsctl.ghiDuLieuVaoFile(tenfile);
}