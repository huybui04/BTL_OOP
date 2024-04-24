#ifndef CHITIETLUONG_H
#define CHITIETLUONG_H

// #include <CaLamViec.h>
#include "CaLamViec.h"
#include "DSCaLamViec.h"
using namespace std;

class ChiTietLuong
{
private:
    string MaNV;
    string MaCa;

    int tongSoCa;
    int thangLamViec;
    CaLamViec ca;
    // DSCaLamViec dsCaLamViec;

public:
    ChiTietLuong();
    ChiTietLuong(const string &MaNV, const string &MaCa, const int &tongSoCa, const int &thangLamViec);
    ChiTietLuong(const string &MaNV, const string &MaCa, const int &tongSoCa, const int &thangLamViec, const CaLamViec &ca);

    string getMaNV() const;
    string getMaCa() const;
    int getTongSoCa() const;
    int getThangLamViec() const;
    CaLamViec getCa() const;

    void setMaNV(const string &MaNV);
    void setMaCa(const string &MaCa);
    void setTongSoCa(const int &tongSoCa);
    void setThangLamViec(const int &thangLamViec);
    void setCa(const CaLamViec &ca);

    double tinhLuong() const;

    void nhap();
    void xuat() const;
    void luuDuLieuVaoFile(const string &tenFile);

    void in() const;
};

#endif /* CHITIETLUONG_H */