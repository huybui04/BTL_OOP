#include "DoiTuong.h"
#include "DoiTuong.cpp"
#include "Nguoi.h"
#include "Nguoi.cpp"
#include "HoaDon.h"
#include "HoaDon.cpp"
#include "ChiTietDoiTuong.h"
#include "ChiTietDoiTuong.cpp"

#include "QLNhanVien/NhanVien.h"
#include "QLNhanVien/DSNhanVien.h"
#include "QLNhanVien/NhanVien.cpp"
#include "QLNhanVien/DSNhanVien.cpp"

#include "QLKhachHang/KhachHang.h"
#include "QLKhachHang/DSKhachHang.h"
#include "QLKhachHang/KhachHang.cpp"
#include "QLKhachHang/DSKhachHang.cpp"

#include "QLNhaCungCap/NhaCungCap.h"
#include "QLNhaCungCap/DSNhaCungCap.h"
#include "QLNhaCungCap/NhaCungCap.cpp"
#include "QLNhaCungCap/DSNhaCungCap.cpp"

#include "QLSanPham/SanPham.h"
#include "QLSanPham/DSSanPham.h"
#include "QLSanPham/SanPham.cpp"
#include "QLSanPham/DSSanPham.cpp"

#include "QLNguyenLieu/NguyenLieu.h"
#include "QLNguyenLieu/DSNguyenLieu.h"
#include "QLNguyenLieu/NguyenLieu.cpp"
#include "QlNguyenLieu/DSNguyenLieu.cpp"

#include "QLBan/Ban.h"
#include "QLBan/DSBan.h"
#include "QLBan/Ban.cpp"
#include "QLBan/DSBan.cpp"

#include "QLCaLamViec/CaLamViec.h"
#include "QLCaLamViec/DSCaLamViec.h"
#include "QLCaLamViec/CaLamViec.cpp"
#include "QLCaLamViec/DSCaLamViec.cpp"

#include "QLDanhMucSanPham/DanhMucSanPham.h"
#include "QLDanhMucSanPham/DSDanhMucSanPham.h"
#include "QLDanhMucSanPham/DanhMucSanPham.cpp"
#include "QLDanhMucSanPham/DSDanhMucSanPham.cpp"

#include "QLKhuVuc/KhuVuc.h"
#include "QLKhuVuc/DSKhuVuc.h"
#include "QLKhuVuc/KhuVuc.cpp"
#include "QLKhuVuc/DSKhuVuc.cpp"

#include "QLHoaDonBan/HoaDonBan.h"
#include "QLHoaDonBan/DSHoaDonBan.h"
#include "QLHoaDonBan/HoaDonBan.cpp"
#include "QLHoaDonBan/DSHoaDonBan.cpp"

#include "QLChiTietHoaDonBan/ChiTietHoaDonBan.h"
#include "QLChiTietHoaDonBan/DSChiTietHoaDonBan.h"
#include "QLChiTietHoaDonBan/ChiTietHoaDonBan.cpp"
#include "QLChiTietHoaDonBan/DSChiTietHoaDonBan.cpp"

#include "QLHoaDonNhap/HoaDonNhap.h"
#include "QLHoaDonNhap/DSHoaDonNhap.h"
#include "QLHoaDonNhap/HoaDonNhap.cpp"
#include "QLHoaDonNhap/DSHoaDonNhap.cpp"

#include "QLChiTietHoaDonNhap/ChiTietHoaDonNhap.h"
#include "QLChiTietHoaDonNhap/DSChiTietHoaDonNhap.h"
#include "QLChiTietHoaDonNhap/ChiTietHoaDonNhap.cpp"
#include "QLChiTietHoaDonNhap/DSChiTietHoaDonNhap.cpp"

#include "QLChiTietSanPham/ChiTietSanPham.h"
#include "QLChiTietSanPham/DSChiTietSanPham.h"
#include "QLChiTietSanPham/ChiTietSanPham.cpp"
#include "QLChiTietSanPham/DSChiTietSanPham.cpp"

#include "QLChiTietLuong/ChiTietLuong.h"
#include "QLChiTietLuong/DSChiTietLuong.h"
#include "QLChiTietLuong/ChiTietLuong.cpp"
#include "QLChiTietLuong/DSChiTietLuong.cpp"

<<<<<<< HEAD
//#include <bits/stdc++.h>
=======
>>>>>>> 2d530b792eb4b5fef622417ea41f38a1a9fe785f
using namespace std;

string trim(const string &str)
{
	size_t first = str.find_first_not_of(" \t\n\r");
	size_t last = str.find_last_not_of(" \t\n\r");
	if (first == string::npos || last == string::npos)
		return "";
	return str.substr(first, last - first + 1);
}

std::pair<int, int> extractMonthAndYear(const std::string &date)
{
	int day, month, year;
	char slash;
	std::stringstream ss(date);
	ss >> day >> slash >> month >> slash >> year;
	return std::make_pair(month, year);
}

class QLQuanCafe
{
private:
	DSNhanVien dsnv;
	DSKhachHang dskh;
	DSNhaCungCap dsncc;
	DSSanPham dssp;
	DSNguyenLieu dsnl;
	DSBan dsban;
	DSCaLamViec dsclv;
	DSDanhMucSanPham dsdmsp;
	DSKhuVuc dskv;

	DSHoaDonBan dshdb;
	DSChiTietHoaDonBan dscthdb;
	DSHoaDonNhap dshdn;
	DSChiTietHoaDonNhap dscthdn;
	DSChiTietSanPham dsctsp;
	DSChiTietLuong dsctl;

	const string tenFileDSNhanVien = "QLNhanVien/nhanvien.txt";
	const string tenFileDSKhachHang = "QLKhachHang/khachhang.txt";
	const string tenFileDSNhaCungCap = "QLNhaCungCap/nhacungcap.txt";
	const string tenFileDSSanPham = "QLSanPham/sanpham.txt";
	const string tenFileDSNguyenLieu = "QLNguyenLieu/nguyenlieu.txt";
	const string tenFileDSBan = "QLBan/ban.txt";
	const string tenFileDSCaLamViec = "QLCaLamViec/calamviec.txt";
	const string tenFileDSDanhMucSanPham = "QLDanhMucSanPham/danhmucsanpham.txt";
	const string tenFileDSKhuVuc = "QLKhuVuc/khuvuc.txt";

	const string tenFileDSHoaDonBan = "QLHoaDonBan/hoadonban.txt";
	const string tenFileDSChiTietHoaDonBan = "QLChiTietHoaDonBan/chitiethoadonban.txt";
	const string tenFileDSHoaDonNhap = "QLHoaDonNhap/hoadonnhap.txt";
	const string tenFileDSChiTietHoaDonNhap = "QLChiTietHoaDonNhap/chitiethoadonnhap.txt";
	const string tenFileDSChiTietSanPham = "QLChiTietSanPham/chitietsanpham.txt";
	const string tenFileDSChiTietLuong = "QLChiTietLuong/chitietluong.txt";

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
		dsclv.docDuLieuTuFile(tenFileDSCaLamViec);
		dsdmsp.docDuLieuTuFile(tenFileDSDanhMucSanPham);
		dskv.docDuLieuTuFile(tenFileDSKhuVuc);

		dscthdb.docDuLieuTuFile(tenFileDSChiTietHoaDonBan);
		dshdb.docDuLieuTuFile(tenFileDSHoaDonBan);
		dscthdn.docDuLieuTuFile(tenFileDSChiTietHoaDonNhap);
		dshdn.docDuLieuTuFile(tenFileDSHoaDonNhap);
		dsctsp.docDuLieuTuFile(tenFileDSChiTietSanPham);
		dsctl.docDuLieuTuFile(tenFileDSChiTietLuong);
	}

	void taoHoaDonNhap()
	{
		int soLuongNhap;
		std::string mhdn;
		std::string mnv;
		std::string mncc;
		std::string ngaynhap;
		std::string mnl;
		std::string tnl;
		std::string ngsx;
		std::string hsd;
		double gia;
		int soluong;
		vector<ChiTietHoaDonNhap> ds;
		int ok_1 = 0;
		int ok_2 = 0;
		int ok_3 = 0;

		std::cout << "Nhap so loai nguyen lieu muon nhap: ";
		std::cin >> soLuongNhap;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Nhap ma hoa don nhap: ";
		std::getline(std::cin, mhdn);
		std::cout << "Nhap ma ma nhan vien: ";
		std::getline(std::cin, mnv);
		std::cout << "Nhap ma nha cung cap: ";
		std::getline(std::cin, mncc);
		std::cout << "Nhap ngay nhap: ";
		std::getline(std::cin, ngaynhap);
		for (int i = 0; i < soLuongNhap; i++)
		{
			std::cout << "Nhap ma nguyen lieu thu " << i + 1 << ": ";
			std::getline(std::cin, mnl);
			std::cout << "Nhap ten nguyen lieu thu " << i + 1 << ": ";
			std::getline(std::cin, tnl);
			std::cout << "Nhap ngay san xuat nguyen lieu thu " << i + 1 << ": ";
			std::getline(std::cin, ngsx);
			std::cout << "Nhap han su dung nguyen lieu thu " << i + 1 << ": ";
			std::getline(std::cin, hsd);
			std::cout << "Nhap gia nguyen lieu thu " << i + 1 << ": ";
			std::cin >> gia;
			std::cout << "Nhap so luong thu " << i + 1 << ": ";
			std::cin >> soluong;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			for (auto nv : this->dsnv.getDSNV())
			{
				if (mnv == trim(nv.getMaNV()))
				{
					ok_1 = 1;
					break;
				}
			}

			for (auto ncc : this->dsncc.getDSNCC())
			{
				if (mncc == trim(ncc.getMaNCC()))
				{
					ok_2 = 1;
					break;
				}
			}

			if (ok_1 == 0)
			{
				cout << "Khong co nhan vien nay trong danh sach!\n";
				return;
			}

			if (ok_2 == 0)
			{
				cout << "Khong co nha cung cap nay trong danh sach!\n";
				return;
			}

			for (auto nl : this->dsnl.getDSNL())
			{
				if (mnl == trim(nl.getMaNL()))
				{
					ok_3 = 1;
					break;
				}
			}

			NguyenLieu cthdn_nl(mnl, tnl, ngsx, hsd, gia);
			if (ok_3 == 0)
			{

				cthdn_nl.luuVaoFile(tenFileDSNguyenLieu);
				dsnl.themNguyenLieu(cthdn_nl);
			}

			ChiTietHoaDonNhap cthd(mhdn, mnl, soluong, cthdn_nl);
			cthd.luuVaoFile(tenFileDSChiTietHoaDonNhap);
			dscthdn.themChiTiet(cthd);
			ds.push_back(cthd);
		}

		HoaDonNhap hdn(mhdn, ngaynhap, mnv, mncc, ds);
		hdn.luuVaoFile(tenFileDSHoaDonNhap);
		dshdn.themHoaDon(hdn);
		hdn.hienThi();
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
			cthd.luuVaoFile(tenFileDSChiTietHoaDonBan);
			ds.push_back(cthd);
		}

		cout << "\n======================================================\n";
		cout << "Chi tiet hoa don mua hang:\n";
		HoaDonBan hdb(billId, date, staffId, customerId, tableId, ds);
		hdb.luuVaoFile(tenFileDSHoaDonBan);
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
		}
		taoChiTietHoaDon(billId, date, staffId, customerId, tableId);
	}

	void themThongTinDSChiTietLuong()
	{
		int soLuong;
		cout << "Nhap vao so thong tin chi tiet luong muon them: ";
		cin >> soLuong;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		int tmp = soLuong + 1;

		while (soLuong--)
		{
			cout << "Nhap thong tin chi tiet luong:\n";
			bool check = false;

			string maNV, maCa;
			int tongCa, thang;
			CaLamViec ca;

			do
			{
				cout << "Nhap ma nhan vien: ";
				getline(cin, maNV);
				if (!dsnv.timKiemTheoMa(maNV))
				{
					cout << "Khong tim thay nhan vien co ma " << maNV << endl;
				}
				else
				{
					check = true;
					cout << "tim thay nhan vien\n";
				}
			} while (!check);

			check = false;

			// nhap ma ca
			do
			{
				cout << "Nhap ma ca lam viec: ";
				getline(cin, maCa);
				if (!dsclv.timKiemTheoMa(maCa))
				{
					cout << "Khong tim thay ca lam viec co ma " << maCa << endl;
				}
				else
				{
					check = true;
				}
			} while (!check);
			check = false;

			// nhap thang
			do
			{
				cout << "Nhap thang lam viec: ";
				cin >> thang;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if (thang < 1 || thang > 12)
				{
					cout << thang << " khong phai la thang hop le.\nNhap lai: ";
					cin >> thang;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else
				{
					check = true;
				}
			} while (!check);
			cout << "Nhap tong so ca co ma " << maCa << " nhan vien " << maNV << " da lam trong thang " << thang << ": ";
			cin >> tongCa;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			for (auto &clv : dsclv.getDSCaLamViec())
			{
				if (clv.getMaCa() == maCa)
				{
					ca = clv;
				}
			}
			ChiTietLuong ctl(maNV, maCa, tongCa, thang, ca);
			
			dsctl.themChiTietLuong(ctl);
			dsctl.ghiDuLieuVaoFile(tenFileDSChiTietLuong);
		}
	}

	// chuc nang nhan vien
	void hienthiDSNhanVien()
	{
		dsnv.hienThiDanhSach();
	}

	void themNhanVien()
	{
		NhanVien nv;
		cout << "Nhap thong tin nhan vien can them: \n";
		nv.nhap();
		NhanVien *n_v = dsnv.timKiemTheoMa(nv.getMaNV());
		if (!n_v)
		{
			dsnv.themNhanVien(nv);
			cout << "Them thanh cong" << endl;
			dsnv.luuVaoFile(tenFileDSNhanVien);
		}
		else
		{
			cout << "Da co nhan vien nay trong danh sach" << endl;
		}
	}

	void suaNhanVien()
	{
		string id;
		cout << "Nhap ma nhan vien can sua: ";
		getline(cin, id);
		NhanVien *nv = dsnv.timKiemTheoMa(id);
		if (nv)
		{
			NhanVien nv;
			cout << "Nhap thong tin moi: \n";
			nv.nhap();
			dsnv.suaNhanVien(id, nv);
<<<<<<< HEAD
			cout << "Da sua thanh cong"<< endl;
			dsnv.luuVaoFile(tenFileDSNhanVien);
=======
			cout << "Da sua thanh cong" << endl;
>>>>>>> 2d530b792eb4b5fef622417ea41f38a1a9fe785f
		}
		else
		{
			cout << "Khong tim thay nhan vien co ma " << id << endl;
		}
	}

	void xoaNhanVien()
	{
		string id;
		cout << "Nhap ma nhan vien can xoa: ";
		getline(cin, id);
		NhanVien *nv = dsnv.timKiemTheoMa(id);
		if (nv)
		{
			dsnv.xoaNhanVien(id);
			cout << "Nhan vien co ma " << id << "da bi xoa ra khoi danh sach" << endl;
			dsnv.luuVaoFile(tenFileDSNhanVien);
		}
		else
		{
			cout << "Khong tim thay nhan vien co ma " << id << endl;
		}
	}

	void timKiemNhanVienTheoMa()
	{
		string id;
		cout << "Nhap ma nhan vien can tim: ";
		getline(cin, id);
		NhanVien *nv = dsnv.timKiemTheoMa(id);
		if (nv)
		{
			cout << "\nThong tin nhan vien can tim: \n";
			nv->xuat();
		}
		else
		{
			cout << "Khong tim thay nhan vien co ma " << id << endl;
		}
	}

	// chuc nang ca lam viec
	void hienthiDSCaLamViec()
	{
		dsclv.hienThiDanhSach();
	}

	void themCaLamViec()
	{
		CaLamViec clv;
		cout << "Nhap thong tin ca lam viec can them: \n";
		clv.nhap();
		CaLamViec *c_l_v = dsclv.timKiemTheoMa(clv.getMaCa());
		if (!c_l_v)
		{
			dsclv.themCaLamViec(clv);
			cout << "Them thanh cong" << endl;
			dsclv.ghiDuLieuVaoFile(tenFileDSCaLamViec);
		}
		else
		{
			cout << "Da co ca lam viec nay trong danh sach" << endl;
		}
	}

	void suaCaLamViec()
	{
		string id;
		cout << "Nhap ma ca lam viec can sua: ";
		getline(cin, id);
		CaLamViec *clv = dsclv.timKiemTheoMa(id);
		if (clv)
		{
			CaLamViec clv;
			clv.nhap();
			dsclv.suaCaLamViec(id, clv);
			cout << "Da sua thanh cong" << endl;
			dsclv.ghiDuLieuVaoFile(tenFileDSCaLamViec);
		}
		else
		{
			cout << "Khong tim thay ca lam viec co ma " << id << endl;
		}
	}

	void xoaCaLamViec()
	{
		string id;
		cout << "Nhap ma ca lam viec can xoa: ";
		getline(cin, id);
		NhanVien *nv = dsnv.timKiemTheoMa(id);
		if (nv)
		{
			dsclv.xoaCaLamViec(id);
			cout << "Ca lam viec co ma" << id << "da bi xoa ra khoi danh sach" << endl;
			dsclv.ghiDuLieuVaoFile(tenFileDSCaLamViec);
		}
		else
		{
			cout << "Khong tim thay ca lam viec co ma " << id << endl;
		}
	}

	void timCaLamViec()
	{
		string id;
		cout << "Nhap ma ca lam viec can tim: ";
		getline(cin, id);
		CaLamViec *clv = dsclv.timKiemTheoMa(id);
		if (clv)
		{
			cout << "\nThong tin ca lam viec can tim: \n";
			clv->xuat();
		}
		else
		{
			cout << "Khong tim thay ca lam viec co ma " << id << endl;
		}
	}

	// chuc nang luong
	void hienThiDSChiTietLuong()
	{
		dsctl.hienThiDanhSach();
	}

	void themChiTietLuong()
	{
		ChiTietLuong ctl;
		cout << "Nhap thong tin chi tiet luong can them: \n";
		ctl.nhap();
		dsctl.themChiTietLuong(ctl);
		dsctl.ghiDuLieuVaoFile(tenFileDSChiTietLuong);
	}

	void suaChiTietLuong()
	{
		string maNV, maCa;
		cout << "Nhap ma nhan vien: ";
		getline(cin, maNV);
		cout << "Nhap ma ca lam viec: ";
		getline(cin, maCa);
		ChiTietLuong *ctl = dsctl.timChiTietLuongTheoMa(maNV, maCa);
		if (ctl)
		{
			dsctl.suaChiTietLuong(maNV, maCa);
<<<<<<< HEAD
			cout << "Chi tiet luong cua nhan vien co ma " << maNV << " va co ma ca la " << maCa << " da bi xoa khoi danh sach"<< endl;
			dsctl.ghiDuLieuVaoFile(tenFileDSChiTietLuong);
=======
			cout << "Chi tiet luong cua nhan vien co ma " << maNV << " va co ma ca la " << maCa << " da bi xoa khoi danh sach" << endl;
>>>>>>> 2d530b792eb4b5fef622417ea41f38a1a9fe785f
		}
		else
		{
			cout << "Khong tim thay chi tiet luong cua nhan vien " << maNV << " ca " << maCa << endl;
		}
	}

	void xoaChiTietLuong()
	{
		string maNV, maCa;
		cout << "Nhap ma nhan vien: ";
		getline(cin, maNV);
		cout << "Nhap ma ca lam viec: ";
		getline(cin, maCa);
		dsctl.xoaChiTietLuongTheoMa(maNV, maCa);
		dsctl.ghiDuLieuVaoFile(tenFileDSChiTietLuong);
	}

	void timKiemChiTietLuong()
	{
		string maNV, maCa;
		cout << "Nhap ma nhan vien: ";
		getline(cin, maNV);
		cout << "Nhap ma ca lam viec: ";
		getline(cin, maCa);
		ChiTietLuong *ctl = dsctl.timChiTietLuongTheoMa(maNV, maCa);
		if (ctl)
		{
			cout << "\nThong tin chi tiet luong can tim: \n";
			ctl->xuat();
		}
		else
		{
			cout << "Khong tim thay chi tiet luong cua nhan vien " << maNV << " ca " << maCa << endl;
		}
	}

	// thong ke luong tung nhan vien theo thang
	void hienThiLuongTungNVTheoThang()
	{
		dsctl.tinhLuongTungThangCuaMoiNhanVien();
	}

	void hienThiChiTietLuongTheoThang()
	{
		dsctl.hienThiDanhSachLuongTheoThang();
	}

	// chuc nang khach hang
	void hienThiDSKH()
	{
		dskh.hienThiDanhSach();
	}

	void themKhachHang()
	{
		KhachHang kh;
		cout << "Nhap thong tin khach hang can them: \n";
		kh.nhap();
		KhachHang *k_h = dskh.timKiemTheoMa(kh.getMaKH());
		if (k_h == nullptr)
		{
			dskh.themKhachHang(kh);
			cout << "Them thanh cong" << endl;
			dskh.luuVaoFile(tenFileDSKhachHang);
		}
		else
		{
			cout << "Da co khach hang nay trong danh sach" << endl;
		}
	}

	void suaKhachHang()
	{
		string id;
		cout << "Nhap ma khach hang can sua: ";
		getline(cin, id);

		KhachHang *kh = dskh.timKiemTheoMa(id);
		if (kh != nullptr)
		{
			KhachHang kh;
			cout << "Nhap thong tin moi: \n";
			kh.nhap();
			dskh.suaKhachHang(id, kh);
			cout << "Sua thanh cong" << endl;
			dskh.luuVaoFile(tenFileDSKhachHang);
		}
		else
		{
			cout << "Khong tim thay khach hang co ma " << id << endl;
		}
	}

	void xoaKhachHang()
	{
		string id;
		cout << "Nhap ma khach hang can xoa: ";
		getline(cin, id);

		KhachHang *kh = dskh.timKiemTheoMa(id);
		if (kh != nullptr)
		{
			dskh.xoaKhachHang(id);
			cout << "Xoa thanh cong" << endl;
			dskh.luuVaoFile(tenFileDSKhachHang);
		}
		else
		{
			cout << "Khong tim thay khach hang co ma " << id << endl;
		}
	}

	void timKiemKhachHangTheoMa()
	{
		string id;
		cout << "Nhap ma khach hang can tim: ";
		getline(cin, id);

		KhachHang *kh = dskh.timKiemTheoMa(id);
		if (kh != nullptr)
		{
			cout << "\nThong tin khach hang can tim: \n";
			kh->xuat();
		}
		else
		{
			cout << "Khong tim thay khach hang co ma " << id << endl;
		}
	}

	// chuc nang ban
	void hienThiDSBan()
	{
		dsban.hienThiDanhSach();
	}

	void themBan()
	{
		Ban ban;
		cout << "Nhap thong tin ban can them:\n";
		ban.nhap();
		Ban *ban_ = dsban.timKiemTheoMa(ban.getMaBan());
		if (!ban_)
		{
			dsban.themBan(ban);
			cout << "Them thanh cong" << endl;
			dsban.luuVaoFile(tenFileDSBan);
		}
		else
		{
			cout << "Da co ban nay trong danh sach" << endl;
		}
	}

	void suaBan()
	{
		string id;
		cout << "Nhap ma ban can sua: ";
		getline(cin, id);
		Ban *ban = dsban.timKiemTheoMa(id);
		if (ban != nullptr)
		{
			cout << "Nhap thong tin moi: \n";
			Ban ban;
			ban.nhap();
			dsban.suaBan(id, ban);
			cout << "Sua thanh cong" << endl;
			dsban.luuVaoFile(tenFileDSBan);
		}
		else
		{
			cout << "Khong tim thay ban co ma " << id << endl;
		}
	}

	void xoaBan()
	{
		string id;
		cout << "Nhap ma ban can xoa: ";
		getline(cin, id);
		Ban *ban = dsban.timKiemTheoMa(id);
		if (ban != nullptr)
		{
			dsban.xoaBan(id);
			cout << "Xoa thanh cong" << endl;
			dsban.luuVaoFile(tenFileDSBan);
		}
		else
		{
			cout << "Khong tim thay ban co ma " << id << endl;
		}
	}

	void timKiemBanTheoMa()
	{
		string id;
		cout << "Nhap ma ban can tim: ";
		getline(cin, id);
		Ban *ban = dsban.timKiemTheoMa(id);
		if (ban != nullptr)
		{
			cout << "\nThong tin ban can tim: \n";
			ban->xuat();
		}
		else
		{
			cout << "Khong tim thay ban co ma " << id << endl;
		}
	}

	// chuc nang san pham
	void hienThiDanhsachSanPham()
	{
		dssp.hienThiDanhSach();
	}

	void themSanPham()
	{
		SanPham sp;
		cout << "Nhap thong tin san pham can them: \n";
		sp.nhap();
		SanPham *s_p = dssp.timKiemSanPham(sp.getMaSP());
		if (s_p == nullptr)
		{
			dssp.themSanPham(sp);
			cout << "Them thanh cong" << endl;
			dssp.luuVaoFile(tenFileDSSanPham);
		}
		else
		{
			cout << "Da co san pham nay trong danh sach" << endl;
		}
	}

	void suaSanPham()
	{
		string id;
		cout << "Nhap ma san pham can sua thong tin:";
		getline(cin, id);
		SanPham *sp = dssp.timKiemSanPham(id);
		if (sp)
		{
			SanPham sp;
			cout << "Nhap thong tin moi cho san pham:\n";
			sp.nhap();
			dssp.suaSanPham(id, sp);
			cout << "Sua thanh cong" << endl;
<<<<<<< HEAD
			dssp.luuVaoFile(tenFileDSSanPham);
=======
>>>>>>> 2d530b792eb4b5fef622417ea41f38a1a9fe785f
		}
		else
		{
			cout << "Khong tim thay san pham co ma " << id << endl;
		}
	}

	void xoaSanPham()
	{
		string id;
		cout << "Nhap ma san pham can xoa: ";
		getline(cin, id);
		SanPham *sp = dssp.timKiemSanPham(id);
		if (sp)
		{
			dssp.xoaSanPham(id);
			cout << "Xoa thanh cong" << endl;
			dssp.luuVaoFile(tenFileDSSanPham);
		}
		else
		{
			cout << "Khong tim thay san pham co ma " << id << endl;
		}
	}

	void timSanPham()
	{
		string id;
		cout << "Nhap vao ma san pham can tim: ";
		getline(cin, id);
		SanPham *sp = dssp.timKiemSanPham(id);
		if (sp)
		{
			cout << "\nThong tin san pham can tim: \n";
			sp->xuat();
		}
		else
		{
			cout << "Khong tim thay san pham co ma " << id << endl;
		}
	}

	// chi tiet san pham
	void hienThiDSChiTietSanPham()
	{
		dsctsp.hienThiDanhSach();
	}

	void themChiTietSanPham()
	{
		ChiTietSanPham ctsp;
		cout << "Nhap thong tin chi tiet san pham can them: \n";
		ctsp.nhap();
		ChiTietSanPham *ctsp_ = dsctsp.timKiemChiTietTheoMa(ctsp.getMaNL(), ctsp.getMaSP());
		if (ctsp_ == nullptr)
		{
			dsctsp.themChiTiet(ctsp);
			cout << "Them thanh cong" << endl;
			dsctsp.ghiDuLieuVaoFile(tenFileDSChiTietSanPham);
		}
		else
		{
			cout << "Da co chi tiet san pham nay trong danh sach" << endl;
		}
	}

	void suaChiTietSanPham()
	{
		string maSP, maNL;
		cout << "Nhap ma san pham can sua: ";
		getline(cin, maSP);
		cout << "Nhap ma nguyen lieu cua san pham can sua: ";
		getline(cin, maNL);
		ChiTietSanPham *ctsp = dsctsp.timKiemChiTietTheoMa(maNL, maSP);
		if (ctsp)
		{
			ChiTietSanPham ctsp;
			cout << "Nhap thong tin moi: \n";
			ctsp.nhap();
			dsctsp.suaChiTiet(maNL, maSP, ctsp);
			cout << "Sua thanh cong" << endl;
			dsctsp.ghiDuLieuVaoFile(tenFileDSChiTietSanPham);
		}
		else
		{
			cout << "Khong tim thay chi tiet san pham co ma san pham " << maSP << " va ma nguyen lieu " << maNL << endl;
		}
	}

	void xoaChiTietSanPham()
	{
		string maSP, maNL;
		cout << "Nhap ma san pham can xoa: ";
		getline(cin, maSP);
		cout << "Nhap ma nguyen lieu cua san pham can xoa: ";
		getline(cin, maNL);
		ChiTietSanPham *ctsp = dsctsp.timKiemChiTietTheoMa(maNL, maSP);
		if (ctsp)
		{
			dsctsp.xoaChiTiet(maNL, maSP);
			cout << "Xoa thanh cong" << endl;
			dsctsp.ghiDuLieuVaoFile(tenFileDSChiTietSanPham);
		}
		else
		{
			cout << "Khong tim thay chi tiet san pham co ma san pham " << maSP << " va ma nguyen lieu " << maNL << endl;
		}
	}

	void timKiemChiTietSanPham()
	{
		string maSP, maNL;
		cout << "Nhap ma san pham can tim: ";
		getline(cin, maSP);
		cout << "Nhap ma nguyen lieu cua san pham can tim: ";
		getline(cin, maNL);
		ChiTietSanPham *ctsp = dsctsp.timKiemChiTietTheoMa(maNL, maSP);
		if (ctsp)
		{
			cout << "\nThong tin chi tiet san pham can tim: \n";
			ctsp->xuat();
		}
		else
		{
			cout << "Khong tim thay chi tiet san pham co ma san pham " << maSP << " va ma nguyen lieu " << maNL << endl;
		}
	}

	// chuc nang nguyen lieu
	void hienThiDSNguyenLieu()
	{
		dsnl.hienThiDanhSach();
	}

	void themNguyenLieu()
	{
		NguyenLieu nl;
		cout << "Nhap thong tin nguyen lieu can them: \n";
		nl.nhap();
		NguyenLieu *n_l = dsnl.timKiemNguyenLieu(nl.getMaNL());
		if (n_l == nullptr)
		{
			dsnl.themNguyenLieu(nl);
			cout << "Them thanh cong" << endl;
			dsnl.luuVaoFile(tenFileDSNguyenLieu);
		}
		else
		{
			cout << "Da co nguyen lieu nay trong danh sach" << endl;
		}
	}

	void suaNguyenLieu()
	{
		string id;
		cout << "Nhap ma nguyen lieu can sua: ";
		getline(cin, id);
		NguyenLieu *nl = dsnl.timKiemNguyenLieu(id);
		if (nl)
		{
			NguyenLieu nl;
			cout << "Nhap thong tin moi: \n";
			nl.nhap();
			dsnl.suaNguyenLieu(id, nl);
			cout << "Sua thanh cong" << endl;
			dsnl.luuVaoFile(tenFileDSNguyenLieu);
		}
		else
		{
			cout << "Khong tim thay nguyen lieu co ma " << id << endl;
		}
	}

	void xoaNguyenLieu()
	{
		string id;
		cout << "Nhap ma nguyen lieu can xoa: ";
		getline(cin, id);
		NguyenLieu *nl = dsnl.timKiemNguyenLieu(id);
		if (nl)
		{
			dsnl.xoaNguyenLieu(id);
			cout << "Xoa thanh cong" << endl;
			dsnl.luuVaoFile(tenFileDSNguyenLieu);
		}
		else
		{
			cout << "Khong tim thay nguyen lieu co ma " << id << endl;
		}
	}

	void timKiemNguyenLieu()
	{
		string id;
		cout << "Nhap ma nguyen lieu can tim: ";
		getline(cin, id);
		NguyenLieu *nl = dsnl.timKiemNguyenLieu(id);
		if (nl)
		{
			cout << "\nThong tin nguyen lieu can tim: \n";
			nl->xuat();
		}
		else
		{
			cout << "Khong tim thay nguyen lieu co ma " << id << endl;
		}
	}

	int tinhTongSoNguyenLieuNhap(string manl)
	{
		int tongSLBD = 0;

		for (auto cthdn : this->dscthdn.getDSCTHDN())
		{
			if (manl == trim(cthdn.getMaNL()))
			{
				tongSLBD += cthdn.getSoLuongNhap();
			}
		}
		return tongSLBD;
	}

	int tinhTongSoNguyenLieuSuDung(string manl)
	{

		vector<pair<string, int>> ds_masp_soluong_lienquan;

		int tongSLSD = 0;

		for (auto ctsp : this->dsctsp.getDSCTSP())
		{
			if (trim(ctsp.getMaNL()) == manl)
			{
				ds_masp_soluong_lienquan.push_back({ctsp.getMaSP(), ctsp.getSoLuongSuDung()});
			}
		}

		for (auto cthdb : this->dscthdb.getDSCTHDB())
		{
			for (auto masp_soluong : ds_masp_soluong_lienquan)
				if (cthdb.getMaSP() == masp_soluong.first)
				{
					tongSLSD += cthdb.getSoLuong() * masp_soluong.second;
				}
		}

		return tongSLSD;
	}

	int tinhTongSoNguyenLieuTonKho()
	{
		cout << "Nhap ma nguyen lieu muon kiem tra ton kho:";
		string manl;
		cin >> manl;
		int ok = 0;

		for (auto nl : dsnl.getDSNL())
		{
			if (trim(nl.getMaNL()) == manl)
			{
				int TongNLBD = tinhTongSoNguyenLieuNhap(manl);
				int TongNLSD = tinhTongSoNguyenLieuSuDung(manl);
				ok = 1;
				return TongNLBD - TongNLSD;
			}
		}
		if (ok == 0)
			cout << "Khong co ma nguyen lieu nay trong kho!\n";
		return 0;
	}

	// chuc nang nha cung cap
	void hienThiDSNhaCungCap()
	{
		dsncc.hienThiDanhSach();
	}

	void themNhaCungCap()
	{
		NhaCungCap ncc;
		cout << "Nhap thong tin nha cung cap can them: \n";
		ncc.nhap();
		NhaCungCap *ncc_ = dsncc.timKiemNhaCungCap(ncc.getMaNCC());
		if (ncc_ == nullptr)
		{
			dsncc.themNhaCungCap(ncc);
			cout << "Them thanh cong" << endl;
			dsncc.luuVaoFile(tenFileDSNhaCungCap);
		}
		else
		{
			cout << "Da co nha cung cap nay trong danh sach" << endl;
		}
	}

	void suaNhaCungCap()
	{
		string id;
		cout << "Nhap ma nha cung cap can sua: ";
		getline(cin, id);
		NhaCungCap *ncc = dsncc.timKiemNhaCungCap(id);
		if (ncc)
		{
			NhaCungCap ncc;
			cout << "Nhap thong tin moi: \n";
			ncc.nhap();
			dsncc.suaNhaCungCap(id, ncc);
			cout <<"Sua thanh cong\n";
			dsncc.luuVaoFile(tenFileDSNhaCungCap);
		}
		else
		{
			cout << "Khong tim thay nha cung cap co ma " << id << endl;
		}
	}

	void xoaNhaCungCap()
	{
		string id;
		cout << "Nhap ma nha cung cap can xoa: ";
		getline(cin, id);
		NhaCungCap *ncc = dsncc.timKiemNhaCungCap(id);
		if (ncc)
		{
			dsncc.xoaNhaCungCap(id);
			cout << "Xoa thanh cong" << endl;
			dsncc.luuVaoFile(tenFileDSNhaCungCap);
		}
		else
		{
			cout << "Khong tim thay nha cung cap co ma " << id << endl;
		}
	}
	void timKiemNhaCungCap()
	{
		string id;
		cout << "Nhap ma nha cung cap can tim: ";
		getline(cin, id);
		NhaCungCap *ncc = dsncc.timKiemNhaCungCap(id);
		if (ncc)
		{
			cout << "\nThong tin nha cung cap can tim: \n";
			ncc->xuat();
		}
		else
		{
			cout << "Khong tim thay nha cung cap co ma " << id << endl;
		}
	}

	// chuc nang dmsap
	void hienThiDSDanhMucSanPham()
	{
		dsdmsp.hienThiDanhSach();
	}

	void themDanhMucSanPham()
	{
		DanhMucSanPham dmsp;
		cout << "Nhap thong tin danh muc san pham can them: \n";
		dmsp.nhap();
		DanhMucSanPham *dmsp_ = dsdmsp.timKiemTheoMa(dmsp.getMaDM());
		if (dmsp_ == nullptr)
		{
			dsdmsp.themDanhMuc(dmsp);
			cout << "Them thanh cong" << endl;
			dsdmsp.luuVaoFile(tenFileDSDanhMucSanPham);
		}
		else
		{
			cout << "Da co danh muc nay trong danh sach" << endl;
		}
	}

	void suaDanhMucSanPham()
	{
		string id;
		cout << "Nhap ma danh muc can sua: ";
		getline(cin, id);
		DanhMucSanPham *dmsp = dsdmsp.timKiemTheoMa(id);
		if (dmsp)
		{
			DanhMucSanPham dmsp;
			cout << "Nhap thong tin moi: \n";
			dmsp.nhap();
			dsdmsp.suaDanhMuc(id, dmsp);
			cout << "Sua thanh cong\n";
			dsdmsp.luuVaoFile(tenFileDSDanhMucSanPham);
		}
		else
		{
			cout << "Khong tim thay danh muc co ma " << id << endl;
		}
	}

	void xoaDanhMucSanPham()
	{
		string id;
		cout << "Nhap ma danh muc can xoa: ";
		getline(cin, id);
		DanhMucSanPham *dmsp = dsdmsp.timKiemTheoMa(id);
		if (dmsp)
		{
			dsdmsp.xoaDanhMuc(id);
			cout << "Xoa thanh cong" << endl;
			dsdmsp.luuVaoFile(tenFileDSDanhMucSanPham);
		}
		else
		{
			cout << "Khong tim thay danh muc co ma " << id << endl;
		}
	}
	void timKiemDanhMuc()
	{
		string id;
		cout << "Nhap ma danh muc can tim: ";
		getline(cin, id);
		DanhMucSanPham *dmsp = dsdmsp.timKiemTheoMa(id);
		if (dmsp)
		{
			cout << "\nThong tin dnha muc can tim: \n";
			dmsp->xuat();
		}
		else
		{
			cout << "Khong tim thay danh muc co ma " << id << endl;
		}
	}

	// chuc nang khu vuc
	void hienThiDSKhuVuc()
	{
		dskv.hienThiDanhSach();
	}

	void themKhuVuc()
	{
		KhuVuc kv;
		cout << "Nhap thong tin khu vuc can them: \n";
		kv.nhap();
		KhuVuc *k_v = dskv.timKiemTheoMa(kv.getMaKV());
		if (k_v == nullptr)
		{
			dskv.themKhuVuc(kv);
			cout << "Them thanh cong" << endl;
			dskv.luuVaoFile(tenFileDSKhuVuc);
		}
		else
		{
			cout << "Da co khu vuc nay trong danh sach" << endl;
		}
	}

	void suaKhuVuc()
	{
		string id;
		cout << "Nhap ma khu vuc can sua: ";
		getline(cin, id);
		KhuVuc *kv = dskv.timKiemTheoMa(id);
		if (kv)
		{
			KhuVuc kv;
			cout << "Nhap thong tin moi: \n";
			kv.nhap();
			dskv.suaKhuVuc(id, kv);
			cout << "Sua thanh cong\n";
			dskv.luuVaoFile(tenFileDSKhuVuc);
		}
		else
		{
			cout << "Khong tim thay khu vuc co ma " << id << endl;
		}
	}

	void xoaKhuVuc()
	{
		string id;
		cout << "Nhap ma khu vuc can xoa: ";
		getline(cin, id);
		KhuVuc *kv = dskv.timKiemTheoMa(id);
		if (kv)
		{
			dskv.xoaKhuVuc(id);
			cout << "Xoa thanh cong" << endl;
			dskv.luuVaoFile(tenFileDSKhuVuc);
		}
		else
		{
			cout << "Khong tim thay khu vuc co ma " << id << endl;
		}
	}
	void timKiemKhuVuc()
	{
		string id;
		cout << "Nhap ma khu vuc can tim: ";
		getline(cin, id);
		KhuVuc *kv = dskv.timKiemTheoMa(id);
		if (kv)
		{
			cout << "\nThong tin khu vuc can tim: \n";
			kv->xuat();
		}
		else
		{
			cout << "Khong tim thay khu vuc co ma " << id << endl;
		}
	}

	// chuc nang hoa don ban
	void hienThiDSHoaDonBan()
	{
		dshdb.hienThiDanhSach();
	}

	void themHoaDonBan()
	{
		taoHoaDonBan();
	}

	void xoaHoaDonBan()
	{
		string id;
		cout << "Nhap ma hoa don ban can xoa: ";
		getline(cin, id);
		dshdb.xoaHoaDon(id);
		dshdb.ghiDuLieuVaoFile(tenFileDSHoaDonBan);
	}

	void timKiemHoaDonBan()
	{
		string id;
		cout << "Nhap ma hoa don ban can tim: ";
		getline(cin, id);
		HoaDonBan *hdb = dshdb.timKiemHoaDonTheoMa(id);
		if (hdb)
		{
			cout << "\nThong tin hoa don ban can tim: \n";
			hdb->xuat();
		}
		else
		{
			cout << "Khong tim thay hoa don ban co ma " << id << endl;
		}
	}

	void tinhTongTienHoaDonBan()
	{
		for (auto hd : dshdb.getDSHDB())
		{
			cout << "HDB " << hd.getMaHDB() << ": " << hd.tinhTongTien() << endl;
		}
	}
<<<<<<< HEAD
	
	map<pair<int, int>, double> calculateMonthlyRevenue(const DSHoaDonBan& dshdb, int year) {
	    map<pair<int, int>, double> monthlyRevenue; 
	    
	    for (const auto& hoadon : dshdb.getDSHDB()) {
	        int month, hoaDonYear; 
	        tie(month, hoaDonYear) = extractMonthAndYear(hoadon.getNgayBan()); 
	        if (hoaDonYear == year) {
	            double totalRevenue = hoadon.tinhTongTien();
	            monthlyRevenue[make_pair(month, year)] += totalRevenue;
	        }
	    }
	    
	    return monthlyRevenue;
	}
	
	void printMonthlyRevenue(const map<pair<int, int>, double>& monthlyRevenue) {
	    cout << "Doanh thu theo tung thang cua nam:" << endl;
	    for (const auto& entry : monthlyRevenue) {
	        int month, year; 
	        tie(month, year) = entry.first; 
	        double revenue = entry.second;
	        cout << "Thang " << setw(2) << setfill('0') << month << "/" << year << ": " << fixed << setprecision(2) << revenue << endl;
	    }
	}

	
	void thongKeHoaDonBanTheoThang() {
	    int year;
	    cout << "Nhap nam muon thong ke:"; 
	    cin >> year;
	    
	    map<pair<int, int>, double> monthlyRevenue = calculateMonthlyRevenue(dshdb, year);
	    printMonthlyRevenue(monthlyRevenue);
	}
	
=======

	map<pair<int, int>, double> calculateYearlyRevenue(const DSHoaDonBan &dshdb, int year)
	{
		map<pair<int, int>, double> monthlyRevenue;

		for (const auto &hoadon : dshdb.getDSHDB())
		{
			int month, hoaDonYear;
			tie(month, hoaDonYear) = extractMonthAndYear(hoadon.getNgayBan());

			if (hoaDonYear == year)
			{
				cout << month << "," << hoaDonYear << endl;
				double totalRevenue = hoadon.tinhTongTien();
				monthlyRevenue[make_pair(month, year)] += totalRevenue;
			}
		}

		return monthlyRevenue;
	}

	void printMonthlyRevenue(const map<pair<int, int>, double> &monthlyRevenue)
	{
		cout << "\nDoanh thu theo tung thang cua nam:" << endl;
		for (const auto &entry : monthlyRevenue)
		{
			int month, year;
			tie(month, year) = entry.first;
			double revenue = entry.second;
			cout << "Thang " << setw(2) << setfill('0') << month << "/" << year << ": " << fixed << setprecision(2) << revenue << endl;
		}
	}

	void thongKeHoaDonBanTheoThang()
	{
		int year;
		cout << "Nhap nam muon thong ke:";
		cin >> year;

		map<pair<int, int>, double> monthlyRevenue = calculateYearlyRevenue(dshdb, year);
		printMonthlyRevenue(monthlyRevenue);
	}

>>>>>>> 2d530b792eb4b5fef622417ea41f38a1a9fe785f
	// chuc nang chi tiet hoa don ban
	void hienThiDSChiTietHoaDonBan()
	{
		dscthdb.hienThiDanhSach();
	}

	void xoaChiTietHoaDonBan()
	{
		string id;
		cout << "Nhap ma hoa don ban can xoa: ";
		getline(cin, id);
		dscthdb.xoaChiTiet(id);
		dscthdb.ghiDuLieuVaoFile(tenFileDSChiTietHoaDonBan);
	}

	void timKiemChiTietHoaDonBan()
	{
		string id;
		cout << "Nhap ma chi tiet hoa don ban can tim: ";
		getline(cin, id);
		ChiTietHoaDonBan *cthdb = dscthdb.timKiemChiTietHoaDonTheoMa(id);
		if (cthdb)
		{
			cout << "\nThong tin chi tiet hoa don ban can tim: \n";
			cthdb->xuat();
		}
		else
		{
			cout << "Khong tim thay chi tiet hoa don ban co ma " << id << endl;
		}
	}

	// chuc nang hoa don nhap
	void hienThiDSHoaDonNhap()
	{
		dshdn.hienThiDanhSach();
	}

	void themHoaDonNhap()
	{
		taoHoaDonNhap();
		dshdn.ghiDuLieuVaoFile(tenFileDSHoaDonNhap);
	}

	void xoaHoaDonNhap()
	{
		string id;
		cout << "Nhap ma hoa don nhap can xoa: ";
		getline(cin, id);
		dshdn.xoaHoaDon(id);
		dshdn.ghiDuLieuVaoFile(tenFileDSHoaDonNhap);
	}

	void timKiemHoaDonNhap()
	{
		string id;
		cout << "Nhap ma hoa don nhap can tim: ";
		getline(cin, id);
		HoaDonNhap *hdn = dshdn.timKiemHoaDonTheoMa(id);
		if (hdn)
		{
			cout << "\nThong tin hoa don ban can tim: \n";
			hdn->xuat();
		}
		else
		{
			cout << "Khong tim thay hoa don ban co ma " << id << endl;
		}
	}
<<<<<<< HEAD
	
	map<pair<int, int>, double> calculateMonthlyRevenue_HDN(const DSHoaDonNhap& dshdn, int year) {
	    map<pair<int, int>, double> monthlyRevenue; 
	    
	    for (const auto& hoadon : dshdn.getDSHDN()) {
	        int month, hoaDonYear; 
	        tie(month, hoaDonYear) = extractMonthAndYear(hoadon.getNgayNhap()); 
	        if (hoaDonYear == year) {
	            double totalRevenue = hoadon.tinhTongTien();
	            monthlyRevenue[make_pair(month, year)] += totalRevenue;
	        }
	    }
	    
	    return monthlyRevenue;
	}
	
	void printMonthlyRevenue_HDN(const map<pair<int, int>, double>& monthlyRevenue) {
	    cout << "So tien nhap theo tung thang cua nam:" << endl;
	    for (const auto& entry : monthlyRevenue) {
	        int month, year; 
	        tie(month, year) = entry.first; 
	        double revenue = entry.second;
	        cout << "Thang " << setw(2) << setfill('0') << month << "/" << year << ": " << fixed << setprecision(2) << revenue << endl;
	    }
	}

	
	void thongKeHoaDonNhapTheoThang() {
	    int year;
	    cout << "Nhap nam muon thong ke:"; 
	    cin >> year;
	    
	    map<pair<int, int>, double> monthlyRevenue = calculateMonthlyRevenue_HDN(dshdn, year);
	    printMonthlyRevenue_HDN(monthlyRevenue);
	}
	
	//chuc nang chi tiet hoa don nhap
=======

	map<pair<int, int>, double> calculateMonthlyRevenue_HDN(const DSHoaDonNhap &dshdn, int year)
	{
		map<pair<int, int>, double> monthlyRevenue;

		for (const auto &hoadon : dshdn.getDSHDN())
		{
			int month, hoaDonYear;
			tie(month, hoaDonYear) = extractMonthAndYear(hoadon.getNgayNhap());
			if (hoaDonYear == year)
			{
				double totalRevenue = hoadon.tinhTongTien();
				monthlyRevenue[make_pair(month, year)] += totalRevenue;
			}
		}

		return monthlyRevenue;
	}

	void printMonthlyRevenue_HDN(const map<pair<int, int>, double> &monthlyRevenue)
	{
		cout << "So tien nhap theo tung thang cua nam:" << endl;
		for (const auto &entry : monthlyRevenue)
		{
			int month, year;
			tie(month, year) = entry.first;
			double revenue = entry.second;
			cout << "Thang " << setw(2) << setfill('0') << month << "/" << year << ": " << fixed << setprecision(2) << revenue << endl;
		}
	}

	void thongKeHoaDonNhapTheoThang()
	{
		int year;
		cout << "Nhap nam muon thong ke:";
		cin >> year;

		map<pair<int, int>, double> monthlyRevenue = calculateMonthlyRevenue_HDN(dshdn, year);
		printMonthlyRevenue_HDN(monthlyRevenue);
	}
	// chuc nang chi tiet hoa don nhap
>>>>>>> 2d530b792eb4b5fef622417ea41f38a1a9fe785f
	void hienThiDSChiTietHoaDonNhap()
	{
		dscthdn.hienThiDanhSach();
	}

	void xoaChiTietHoaDonNhap()
	{
		string id;
		cout << "Nhap ma hoa don nhap can xoa: ";
		getline(cin, id);
		dscthdn.xoaChiTiet(id);
		dscthdn.ghiDuLieuVaoFile(tenFileDSChiTietHoaDonNhap);
	}

	void timKiemChiTietHoaDonNhap()
	{
		string id;
		cout << "Nhap ma hoa don nhap can tim: ";
		getline(cin, id);
		ChiTietHoaDonNhap *cthdn = dscthdn.timKiemChiTietHoaDonTheoMa(id);
		if (cthdn)
		{
			cout << "\nThong tin hoa don ban can tim: \n";
			cthdn->xuat();
		}
		else
		{
			cout << "Khong tim thay hoa don ban co ma " << id << endl;
		}
	}
};

int main()
{

	cout << fixed << setprecision(2);
	QLQuanCafe qlcf;
	qlcf.tao(); // Doc du lieu tu file

	int lc;
	do
	{
		cout << "\n==========================MENU==========================\n";
		cout << "1. Thong tin Nhan vien\n";
		cout << "2. Thong tin khach hang\n";
		cout << "3. Thong tin hoa don ban\n";
		cout << "4. Thong tin chi tiet hoa don ban\n";
		cout << "5. Thong tin hoa don nhap\n";
		cout << "6. Thong tin chi tiet hoa don nhap\n";
		cout << "7. Thong tin ban\n";
		cout << "8. Thong tin san pham\n";
		cout << "9. Thong tin chi tiet san pham\n";
		cout << "10. Thong tin danh sach nguyen lieu\n";
		cout << "11. Thong tin nha cung cap nguyen lieu\n";
		cout << "12. Thong tin ca lam viec\n";
		cout << "13. Thong tin chi tiet luong nhan vien\n";
		cout << "14. Thong tin danh muc san pham\n";
		cout << "15. Thong tin khu vuc\n";
		cout << "0. Thoat";
		cout << "\n==========================END===========================\n";

		cout << "\nNhap lua chon: ";
		cin >> lc;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (lc)
		{
		case 1:
			// thong tin nhan vien:
			int choice1;
			do
			{
				cout << "\n==========================MENU==========================\n";
				cout << "1. Hien thi danh sach nhan vien\n";
				cout << "2. Them nhan vien vao danh sach\n";
				cout << "3. Xoa nhan vien khoi danh sach\n";
				cout << "4. Sua thong tin nhan vien\n";
				cout << "5. Tim kiem nhan vien theo ma nhan vien\n";
				cout << "0. Tro lai Menu";
				cout << "\n==========================END===========================\n";

				cout << "\nNhap lua chon: ";
				cin >> choice1;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				switch (choice1)
				{
				case 1:
					qlcf.hienthiDSNhanVien();
					break;
				case 2:
					qlcf.themNhanVien();
					break;
				case 3:
					qlcf.xoaNhanVien();
					break;
				case 4:
					qlcf.suaNhanVien();
					break;
				case 5:
					qlcf.timKiemNhanVienTheoMa();
					break;
				case 0:
					break;
				}
			} while (choice1);
			break;

		// menu2
		case 2:
			// thong tin khach hang:
			int choice2;
			do
			{
				cout << "\n==========================MENU==========================\n";
				cout << "1. Hien thi danh sach khach hang\n";
				cout << "2. Them khach hang vao danh sach\n";
				cout << "3. Xoa khach hang khoi danh sach\n";
				cout << "4. Sua thong tin khach hang\n";
				cout << "5. Tim kiem khach hang theo ma khach hang\n";
				cout << "0. Tro lai Menu";
				cout << "\n==========================END===========================\n";

				cout << "\nNhap lua chon: ";
				cin >> choice2;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				switch (choice2)
				{
				case 1:
					qlcf.hienThiDSKH();
					break;
				case 2:
					qlcf.themKhachHang();
					break;
				case 3:
					qlcf.xoaKhachHang();
					break;
				case 4:
					qlcf.suaKhachHang();
					break;
				case 5:
					qlcf.timKiemKhachHangTheoMa();
					break;
				case 0:
					break;
				}
			} while (choice2);
			break;
		case 3:
			int choice3;
			do
			{
				cout << "\n==========================MENU==========================\n";
				cout << "1. Hien thi danh sach hoa don ban\n";
				cout << "2. Them hoa don ban vao danh sach\n";
				cout << "3. Xoa hoa don ban khoi danh sach\n";
				cout << "4. Tinh tien hoa don ban\n";
				cout << "5. Tim kiem hoa don ban theo ma hoa don ban\n";
				cout << "6. Thong ke hoa don ban theo nam\n";
				cout << "0. Tro lai Menu";
				cout << "\n==========================END===========================\n";

				cout << "\nNhap lua chon: ";
				cin >> choice3;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				switch (choice3)
				{
				case 1:
					qlcf.hienThiDSHoaDonBan();
					break;
				case 2:
					qlcf.themHoaDonBan();
					break;
				case 3:
					qlcf.xoaHoaDonBan();
					break;
				case 4:
					qlcf.tinhTongTienHoaDonBan();
					break;
				case 5:
					qlcf.timKiemHoaDonBan();
					break;
				case 6:
					qlcf.thongKeHoaDonBanTheoThang();
					break;
				case 0:
					break;
				}
			} while (choice3);
			break;
		case 4:
			int choice4;
			do
			{
				cout << "\n==========================MENU==========================\n";
				cout << "1. Hien thi danh sach chi tiet hoa don ban\n";
				cout << "2. Xoa chi tiet hoa don ban khoi danh sach\n";
				cout << "3. Tim kiem chi tiet hoa don ban\n";
				cout << "0. Tro lai Menu";
				cout << "\n==========================END===========================\n";

				cout << "\nNhap lua chon: ";
				cin >> choice4;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				switch (choice4)
				{
				case 1:
					qlcf.hienThiDSChiTietHoaDonBan();
					break;
				case 2:
					qlcf.xoaChiTietHoaDonBan();
					break;
				case 3:
					qlcf.timKiemChiTietHoaDonBan();
					break;
				case 0:
					break;
				}
			} while (choice4);
			break;
		case 5:
			int choice5;
			do
			{
				cout << "\n==========================MENU==========================\n";
				cout << "1. Hien thi danh sach hoa don nhap\n";
				cout << "2. Xoa hoa don nhap khoi danh sach\n";
				cout << "3. Tim kiem hoa don nhap\n";
				cout << "4. Tao hoa don nhap\n";
				cout << "5. Thong ke hoa don nhap theo thang\n";
				cout << "0. Tro lai Menu";
				cout << "\n==========================END===========================\n";

				cout << "\nNhap lua chon: ";
				cin >> choice5;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				switch (choice5)
				{
				case 1:
					qlcf.hienThiDSHoaDonNhap();
					break;
				case 2:
					qlcf.xoaHoaDonNhap();
					break;
				case 3:
					qlcf.timKiemHoaDonNhap();
					break;
				case 4:
					qlcf.themHoaDonNhap();
					break;
				case 5:
					qlcf.thongKeHoaDonNhapTheoThang();
<<<<<<< HEAD
					break;
=======
>>>>>>> 2d530b792eb4b5fef622417ea41f38a1a9fe785f
				case 0:
					break;
				}
			} while (choice5);
			break;
		case 6:
			int choice6;
			do
			{
				cout << "\n==========================MENU==========================\n";
				cout << "1. Hien thi danh sach chi tiet hoa don nhap\n";
				cout << "2. Xoa chi tiet hoa don nhap khoi danh sach\n";
				cout << "3. Tim kiem chi tiet hoa don nhap\n";
				cout << "0. Tro lai Menu";
				cout << "\n==========================END===========================\n";

				cout << "\nNhap lua chon: ";
				cin >> choice6;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				switch (choice6)
				{
				case 1:
					qlcf.hienThiDSChiTietHoaDonNhap();
					break;
				case 2:
					qlcf.xoaChiTietHoaDonNhap();
					break;
				case 3:
					qlcf.timKiemChiTietHoaDonNhap();
					break;
				case 0:
					break;
				}
			} while (choice6);
			break;

		case 7:
			int choice7;
			do
			{
				cout << "\n==========================MENU==========================\n";
				cout << "1. Hien thi danh sach ban\n";
				cout << "2. Them ban vao danh sach\n";
				cout << "3. Xoa ban khoi danh sach\n";
				cout << "4. Sua thong tin ban\n";
				cout << "5. Tim kiem ban theo ma ban\n";
				cout << "0. Tro lai Menu";
				cout << "\n==========================END===========================\n";

				cout << "\nNhap lua chon: ";
				cin >> choice7;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				switch (choice7)
				{
				case 1:
					qlcf.hienThiDSBan();
					break;
				case 2:
					qlcf.themBan();
					break;
				case 3:
					qlcf.xoaBan();
					break;
				case 4:
					qlcf.suaBan();
					break;
				case 5:
					qlcf.timKiemBanTheoMa();
					break;
				case 0:
					break;
				}
			} while (choice7);
			break;

		case 8:
			int choice8;
			do
			{
				cout << "\n==========================MENU==========================\n";
				cout << "1. Hien thi danh sach san pham\n";
				cout << "2. Them san pham vao danh sach\n";
				cout << "3. Xoa san pham khoi danh sach\n";
				cout << "4. Sua thong tin san pham\n";
				cout << "5. Tim kiem san pham theo ma san pham\n";
				cout << "0. Tro lai Menu";
				cout << "\n==========================END===========================\n";

				cout << "\nNhap lua chon: ";
				cin >> choice8;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				switch (choice8)
				{
				case 1:
					qlcf.hienThiDanhsachSanPham();
					break;
				case 2:
					qlcf.themSanPham();
					break;
				case 3:
					qlcf.xoaSanPham();
					break;
				case 4:
					qlcf.suaSanPham();
					break;
				case 5:
					qlcf.timSanPham();
					break;
				case 0:
					break;
				}
			} while (choice8);
			break;
		case 9:
			int choice9;
			do
			{
				cout << "\n==========================MENU==========================\n";
				cout << "1. Hien thi danh sach chi tiet san pham\n";
				cout << "2. Them chi tiet san pham vao danh sach\n";
				cout << "3. Xoa chi tiet san pham khoi danh sach\n";
				cout << "4. Sua thong tin chi tiet san pham\n";
				cout << "5. Tim kiem chi tiet san pham theo ma chi tiet san pham\n";
				cout << "0. Tro lai Menu";
				cout << "\n==========================END===========================\n";

				cout << "\nNhap lua chon: ";
				cin >> choice9;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				switch (choice9)
				{
				case 1:
					qlcf.hienThiDSChiTietSanPham();
					break;
				case 2:
					// qlcf.themChiTietSanPham();
					break;
				case 3:
					qlcf.xoaChiTietSanPham();
					break;
				case 4:
					// qlcf.suaChiTietSanPham();
					break;
				case 5:
					qlcf.timKiemChiTietSanPham();
					break;
				case 0:
					break;
				}
			} while (choice9);
			break;
		case 10:
			int choice10;
			do
			{
				cout << "\n==========================MENU==========================\n";
				cout << "1. Hien thi danh sach nguyen lieu\n";
				cout << "2. Them nguyen lieu vao danh sach\n";
				cout << "3. Xoa nguyen lieu khoi danh sach\n";
				cout << "4. Sua thong tin nguyen lieu\n";
				cout << "5. Tim kiem nguyen lieu theo ma nguyen lieu\n";
				cout << "6. Tinh so nguyen lieu ton kho theo ma\n";
				cout << "0. Tro lai Menu";
				cout << "\n==========================END===========================\n";

				cout << "\nNhap lua chon: ";
				cin >> choice10;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				switch (choice10)
				{
				case 1:
					qlcf.hienThiDSNguyenLieu();
					break;
				case 2:
					qlcf.themNguyenLieu();
					break;
				case 3:
					qlcf.xoaNguyenLieu();
					break;
				case 4:
					qlcf.suaNguyenLieu();
					break;
				case 5:
					qlcf.timKiemNguyenLieu();
					break;
				case 6:
					cout << qlcf.tinhTongSoNguyenLieuTonKho() << endl;
					break;
				case 0:
					break;
				}
			} while (choice10);
			break;
		case 11:
			int choice11;
			do
			{
				cout << "\n==========================MENU==========================\n";
				cout << "1. Hien thi danh sach nha cung cap\n";
				cout << "2. Them nha cung cap vao danh sach\n";
				cout << "3. Xoa nha cung cap khoi danh sach\n";
				cout << "4. Sua thong tin nha cung cap\n";
				cout << "5. Tim kiem nha cung cap theo ma nha cung cap\n";
				cout << "0. Tro lai Menu";
				cout << "\n==========================END===========================\n";

				cout << "\nNhap lua chon: ";
				cin >> choice11;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				switch (choice11)
				{
				case 1:
					qlcf.hienThiDSNhaCungCap();
					break;
				case 2:
					qlcf.themNhaCungCap();
					break;
				case 3:
					qlcf.xoaNhaCungCap();
					break;
				case 4:
					qlcf.suaNhaCungCap();
					break;
				case 5:
					qlcf.timKiemNhaCungCap();
					break;
				case 0:
					break;
				}
			} while (choice11);
			break;
		case 12:
			int choice12;
			do
			{
				cout << "\n==========================MENU==========================\n";
				cout << "1. Hien thi danh sach ca lam viec\n";
				cout << "2. Them ca lam viec vao danh sach\n";
				cout << "3. Xoa ca lam viec khoi danh sach\n";
				cout << "4. Sua thong tin ca lam viec\n";
				cout << "5. Tim kiem ca lam viec theo ma ca lam viec\n";
				cout << "0. Tro lai Menu";
				cout << "\n==========================END===========================\n";

				cout << "\nNhap lua chon: ";
				cin >> choice12;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				switch (choice12)
				{
				case 1:
					qlcf.hienthiDSCaLamViec();
					break;
				case 2:
					qlcf.themCaLamViec();
					break;
				case 3:
					qlcf.xoaCaLamViec();
					break;
				case 4:
					qlcf.suaCaLamViec();
					break;
				case 5:
					qlcf.timCaLamViec();
					break;
				case 0:
					break;
				}
			} while (choice12);
			break;
		case 13:
			int choice13;
			do
			{
				cout << "\n==========================MENU==========================\n";
				cout << "1. Hien thi danh sach chi tiet luong\n";
				cout << "2. Hien thi danh sach chi tiet luong theo thang\n";
				cout << "3. Thong ke luong tung nhan vien theo thang\n";
				cout << "4. Them chi tiet luong vao danh sach\n";
				cout << "5. Xoa chi tiet luong khoi danh sach\n";
				cout << "6. Sua thong tin chi tiet luong\n";
				cout << "7. Tim kiem chi tiet luong theo ma chi tiet luong\n";
				cout << "0. Tro lai Menu";
				cout << "\n==========================END===========================\n";

				cout << "\nNhap lua chon: ";
				cin >> choice13;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				switch (choice13)
				{
				case 1:
					qlcf.hienThiDSChiTietLuong();
					break;
				case 2:
					qlcf.hienThiChiTietLuongTheoThang();
					break;
				case 3:
					qlcf.hienThiLuongTungNVTheoThang();
					break;
				case 4:
					qlcf.themChiTietLuong();
					break;
				case 5:
					qlcf.xoaChiTietLuong();
					break;
				case 6:
					qlcf.suaChiTietLuong();
					break;
				case 7:
					qlcf.timKiemChiTietLuong();
					break;
				case 0:
					break;
				}
			} while (choice13);
			break;
		case 14:
			int choice14;
			do
			{
				cout << "\n==========================MENU==========================\n";
				cout << "1. Hien thi danh sach danh muc san pham\n";
				cout << "2. Them danh muc san pham vao danh sach\n";
				cout << "3. Xoa danh muc san pham khoi danh sach\n";
				cout << "4. Sua thong tin danh muc san pham\n";
				cout << "5. Tim kiem danh muc\n";
				cout << "0. Tro lai Menu";
				cout << "\n==========================END===========================\n";

				cout << "\nNhap lua chon: ";
				cin >> choice14;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				switch (choice14)
				{
				case 1:
					qlcf.hienThiDSDanhMucSanPham();
					break;
				case 2:
					qlcf.themDanhMucSanPham();
					break;
				case 3:
					qlcf.xoaDanhMucSanPham();
					break;
				case 4:
					qlcf.suaDanhMucSanPham();
					break;
				case 5:
					qlcf.timKiemDanhMuc();
					break;
				case 0:
					break;
				}
			} while (choice14);
			break;
		case 15:
			int choice15;
			do
			{
				cout << "\n==========================MENU==========================\n";
				cout << "1. Hien thi danh sach khu vuc\n";
				cout << "2. Them khu vuc vao danh sach\n";
				cout << "3. Xoa khu vuc khoi danh sach\n";
				cout << "4. Sua thong tin khu vuc\n";
				cout << "5. Tim kiem khu vuc\n";
				cout << "0. Tro lai Menu";
				cout << "\n==========================END===========================\n";

				cout << "\nNhap lua chon: ";
				cin >> choice15;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				switch (choice15)
				{
				case 1:
					qlcf.hienThiDSKhuVuc();
					break;
				case 2:
					qlcf.themKhuVuc();
					break;
				case 3:
					qlcf.xoaKhuVuc();
					break;
				case 4:
					qlcf.suaKhuVuc();
					break;
				case 5:
					qlcf.timKiemKhuVuc();
					break;
				case 0:
					break;
				}
			} while (choice15);
			break;
		case 16:
			cout << "\nTong doanh thu:";
			break;
		case 0:
			cout << "\nCam on ban da su dung chuong trinh.\n";
			break;
		default:
			cout << "Nhap sai, vui long nhap lai\n";
			break;
		}
	} while (lc);
	return 0;
}
