#ifndef DSHOADONNHAP_H
#define DSHOADONNHAP_H

#include <vector>
#include "HoaDonNhap.h"

class DSHoaDonNhap {
private:
    std::vector<std::string> danhSachHoaDon; 

public:
    std::vector<std::string> getDSHDN() const;
    void themHoaDon(const std::string &maHDN); 
    void xoaHoaDon(std::string maHDN);
    void suaHoaDon(std::string maHDN, const std::string &maHDNMoi);
    std::string timKiemHoaDon(std::string maHDN);
    void docDuLieuTuFile(std::string tenFile);
    void ghiDuLieuVaoFile(std::string tenFile);
};

#endif /* DSHOADONNHAP_H */

