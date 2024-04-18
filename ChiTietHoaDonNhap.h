#ifndef CHITIETHOADONNHAP_H
#define CHITIETHOADONNHAP_H

#include "NguyenLieu.h"

class ChiTietHoaDonNhap {
private:
    std::string MaHDN; 
    std::string MaNL; 
    int SoLuongNhap;

public:
    ChiTietHoaDonNhap();
    ChiTietHoaDonNhap(const std::string &maHDN, const std::string &maNL, int SoLuongNhap); 

    std::string getMaHDN() const; 
    void setMaHDN(const std::string &maHDN); 
    
    std::string getMaNL() const; 
    void setMaNL(const std::string &maNL);

    int getSoLuongNhap() const;
    void setSoLuongNhap(int soluong);

    double tinhThanhTien() const;
};

#endif /* CHITIETHOADONNHAP_H */

