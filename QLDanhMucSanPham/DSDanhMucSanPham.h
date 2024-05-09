#ifndef DSDANHMUCSANPHAM_H
#define DSDANHMUCSANPHAM_H

#include "DanhMucSanPham.h"
#include <vector>
#include <map>
using namespace std;
class DSDanhMucSanPham
{
private:
    vector<DanhMucSanPham> danhSachDanhMuc;
    map<string, vector<SanPham>> mapSanPham;

public:
    vector<DanhMucSanPham> getDSDM() const;
    void themDanhMuc(const DanhMucSanPham &danhMucSanPham);
    void xoaDanhMuc(const string &maDM);
    void suaDanhMuc(const string &maDM, const DanhMucSanPham &dm);
    void hienThiDanhSach();
    DanhMucSanPham timKiemDanhMuc(const string &maDM);
    DanhMucSanPham *timKiemTheoMa(const string &maDM);
    // map<string, DanhMucSanPham> getMapDanhMuc();
    // void xuatMapSanPham();
    void getData();

    void docDuLieuTuFile(const string &tenFile);
    void luuVaoFile(const string &tenTep) const;
};

#endif
