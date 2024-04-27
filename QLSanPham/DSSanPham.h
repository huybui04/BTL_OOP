#ifndef DSSANPHAM_H
#define DSSANPHAM_H

#include "SanPham.h"
#include <vector>

class DSSanPham
{
private:
    std::vector<SanPham> danhSachSanPham;

public:
    std::vector<SanPham> getDSSP() const;
    void themSanPham(SanPham &sp);
    void docDuLieuTuFile(const std::string &tenTep);
    void hienThiDanhSach() const;
    void suaSanPham(const std::string &maSP, const SanPham &sp);
    void xoaSanPham(const std::string &maSP);
    void luuVaoFile(const std::string &tenTep) const;
    SanPham *timKiemSanPham(const std::string &maSP);
};

#endif /* DSSANPHAM_H */
