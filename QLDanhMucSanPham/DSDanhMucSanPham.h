#ifndef DSDANHMUCSANPHAM_H
#define DSDANHMUCSANPHAM_H

#include "DanhMucSanPham.h"
#include <vector>

class DSDanhMucSanPham {
private:
    std::vector<DanhMucSanPham> danhSachDanhMuc;

public:
    std::vector<DanhMucSanPham> getDSDM() const;
    void themDanhMuc(const DanhMucSanPham &danhMucSanPham);
    void xoaDanhMuc(const std::string &maDM);
    void suaDanhMuc(const std::string &maDM, const DanhMucSanPham &dm);
    void hienThiDanhSach() const;
    DanhMucSanPham timKiemDanhMuc(const std::string &maDM);
    DanhMucSanPham *timKiemTheoMa(const std::string &maDM);

    void docDuLieuTuFile(const std::string &tenFile);
    void luuVaoFile(const std::string &tenTep) const;
};

#endif
