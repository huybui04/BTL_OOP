#ifndef DSSANPHAM_H
#define DSSANPHAM_H

#include "SanPham.h"
#include <algorithm>
#include <vector>

using namespace std;
class DSSanPham
{
private:
    vector<SanPham> danhSachSanPham;

public:
    vector<SanPham> getDSSP() const;
    void themSanPham(SanPham &sp);
    void docDuLieuTuFile(const string &tenTep);
    void hienThiDanhSach() const;
    void suaSanPham(const string &maSP, const SanPham &sp);
    void xoaSanPham(const string &maSP);
    void luuVaoFile(const string &tenTep) const;
    SanPham *timKiemSanPham(const string &maSP);

    void capNhatFile(const string &tenFile);
};

#endif /* DSSANPHAM_H */
