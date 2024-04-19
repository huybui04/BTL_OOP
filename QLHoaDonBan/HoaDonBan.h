#ifndef HOADONBAN_H
#define HOADONBAN_H

#include <iostream>
#include <vector>
#include "../QLNhanVien/NhanVien.h"
#include "../QLKhachHang/KhachHang.h"
#include "../QLBan/Ban.h"
#include "../QLChiTietHoaDonBan/ChiTietHoaDonBan.h"

class HoaDonBan
{
private:
    std::string MaHDB, MaNV, MaKH, MaBan;
    std::string NgayBan;
    std::vector<ChiTietHoaDonBan> dsCTHDB;

public:
    HoaDonBan();
    HoaDonBan(const std::vector<ChiTietHoaDonBan> &ds);
    HoaDonBan(const std::string &maHDB, const std::string &ngayBan, const std::string &manv, const std::string &makh, const std::string &maban);
    HoaDonBan(const std::string &maHDB, const std::string &ngayBan, const std::string &manv, const std::string &makh, const std::string &maban, const std::vector<ChiTietHoaDonBan> &dscthdb);

    void setMaHDB(const std::string &maHDB);
    std::string getMaHDB() const;
    void setNgayBan(const std::string &ngayBan);
    std::string getNgayBan() const;
    void setMaNV(const std::string manv);
    std::string getMaNV() const;
    void setMaKH(const std::string makh);
    std::string getMaKH() const;
    void setMaBan(const std::string maban);
    std::string getMaBan() const;
    void setDsCTHDB(const std::vector<ChiTietHoaDonBan> &ds);
    std::vector<ChiTietHoaDonBan> getDsCTHDB() const;

    void themChiTietHoaDon(const ChiTietHoaDonBan &chiTiet);
    
    void nhap() const;
	void xuat() const;
    void hienThi() const;
    void luuVaoFile(const std::string &tenFile) const;
    
    double tinhTongTien() const;
};

#endif /* HOADONBAN_H */
