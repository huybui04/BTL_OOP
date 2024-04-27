#ifndef DSCHITIETSANPHAM_H
#define DSCHITIETSANPHAM_H

#include <vector>
#include "ChiTietSanPham.h"

class DSChiTietSanPham
{
private:
    std::vector<ChiTietSanPham> danhSachChiTietSanPham;

public:
    std::vector<ChiTietSanPham> getDSCTSP() const;
    void themChiTiet(const ChiTietSanPham &chiTiet);
    void suaChiTiet(const std::string &MaNL, const std::string &MaSP, const ChiTietSanPham &chiTietMoi);
    void xoaChiTiet(const std::string &MaNL, const std::string &MaSP);
    void hienThiDanhSach() const;
    ChiTietSanPham timKiemChiTiet(const std::string &MaNL, const std::string &MaSP);
    ChiTietSanPham *timKiemChiTietTheoMa(const std::string &MaNL, const std::string &MaSP);
    void docDuLieuTuFile(const std::string &tenFile);
    void ghiDuLieuVaoFile(const std::string &tenFile);
};

#endif /* DSCHITIETSANPHAM_H */
