#ifndef DSCHITIETLUONG_H
#define DSCHITIETLUONG_H

#include "ChiTietLuong.h"

#include <iostream>
#include <vector>
using namespace std;

class DSChiTietLuong
{
private:
    vector<ChiTietLuong> DSChiTietLuong;

public:
    vector<ChiTietLuong> getDSChiTietLuong() const;
    void themChiTietLuong(const ChiTietLuong &chitietluong);
    void suaChiTietLuong(const string &MaNV, const string &MaCa);
    void xoaChiTietLuong(const string &MaNV, const string &MaCa);
    void hienThiDanhSach() const;
    ChiTietLuong *timChiTietLuongTheoMa(const string &MaNV, const string &MaCa);

    void docDuLieuTuFile(const string &tenFile);
    void ghiDuLieuVaoFile(const string &tenFile);
};

#endif /* DSCHITIETLUONG_H */