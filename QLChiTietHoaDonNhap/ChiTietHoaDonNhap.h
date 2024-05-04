#ifndef CHITIETHOADONNHAP_H
#define CHITIETHOADONNHAP_H

#include "../QLNguyenLieu/NguyenLieu.h"
#include "../ChiTietDoiTuong.h"

class ChiTietHoaDonNhap : public ChiTietDoiTuong
{
private:
    int SoLuongNhap;
    NguyenLieu NL;

public:
    ChiTietHoaDonNhap();
    ChiTietHoaDonNhap(const std::string &maHDN, const std::string &maNL, const int &soLuongNhap);
    ChiTietHoaDonNhap(const std::string &maHDN, const std::string &maNL, const int &soLuongNhap, const NguyenLieu &nl);

    std::string getMaHDN() const;
    void setMaHDN(const std::string &maHDN);

    std::string getMaNL() const;
    void setMaNL(const std::string &maNL);

    NguyenLieu getNL() const;
    void setNL(const NguyenLieu &nl);

    int getSoLuongNhap() const;
    void setSoLuongNhap(int soLuongNhap);

    void nhap() const;
    void xuat() const;
    void hienThi() const;
    void luuVaoFile(const std::string &tenFile) const;

    double tinhThanhTien() const;
};

#endif /* CHITIETHOADONNHAP_H */
