#ifndef DSCHITIETHOADONBAN_H
#define DSCHITIETHOADONBAN_H

//#include <iostream>
#include <vector>
#include "ChiTietHoaDonBan.h"

class DSChiTietHoaDonBan {
private:
    std::vector<ChiTietHoaDonBan> danhSachChiTietHoaDonBan;

public:
    std::vector<ChiTietHoaDonBan> getDSCTHDB() const;
    void themChiTiet(const ChiTietHoaDonBan &chiTiet);
//    void suaChiTiet(const HoaDonBan &hdb, const ChiTietHoaDonBan &chiTietMoi);
//    void xoaChiTiet(const HoaDonBan &hdb);
    void suaChiTiet(const std::string &MaHDB, const ChiTietHoaDonBan &chiTietMoi);
    void xoaChiTiet(const std::string &MaHDB);
    void hienThiDanhSach() const;
//    ChiTietHoaDonBan timKiemChiTiet(const HoaDonBan &hdb);
	ChiTietHoaDonBan timKiemChiTiet(const std::string &MaHDB);
	
    void docDuLieuTuFile(const std::string &tenFile);
    void ghiDuLieuVaoFile(const std::string &tenFile);
};

#endif /* DSCHITIETHOADONBAN_H */

