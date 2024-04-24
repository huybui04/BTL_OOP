#ifndef DSCHITIETLUONG_H
#define DSCHITIETLUONG_H

#include "ChiTietLuong.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

class DSChiTietLuong
{
private:
    vector<ChiTietLuong> DSChiTietLuong;

public:
    vector<ChiTietLuong> getDSChiTietLuong() const;
    void themChiTietLuong(const ChiTietLuong &chitietluong);
    void suaChiTietLuong(const string &MaNV, const string &MaCa);
    void xoaChiTietLuongTheoMa(const string &MaNV, const string &MaCa);
    void xoaChiTietLuong(const ChiTietLuong &ctl);
    void hienThiDanhSach() const;
    ChiTietLuong *timChiTietLuongTheoMa(const string &MaNV, const string &MaCa);

    double tinhLuongTheoMaNVVaThang(const string &MaNV, const int &thangLamViec) const;
    void hienThiDanhSachLuongTheoThang() const;
    void tinhLuongTungThangCuaMoiNhanVien() const;

    void docDuLieuTuFile(const string &tenFile);
    void ghiDuLieuVaoFile(const string &tenFile);
};

#endif /* DSCHITIETLUONG_H */