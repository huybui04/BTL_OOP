#ifndef HOADONNHAP_H
#define HOADONNHAP_H

#include <iostream>
#include <vector>
#include "../QLNhanVien/NhanVien.h"
#include "../QLNhaCungCap/NhaCungCap.h"
#include "../QLNguyenLieu/NguyenLieu.h"
#include "../QLNguyenLieu/DSNguyenLieu.h"
#include "../QLChiTietHoaDonNhap/ChiTietHoaDonNhap.h"
#include "../QLChiTietHoaDonNhap/DSChiTietHoaDonNhap.h"

class HoaDonNhap : public HoaDon
{
private:
    std::string MaNV, MaNCC; 
    std::vector<ChiTietHoaDonNhap> dsCTHDN;

public:
    HoaDonNhap();
    HoaDonNhap(const std::string &maHDN,const std::string &ngayNhap, const std::string &maNV, const std::string &maNCC);
	HoaDonNhap(const std::string &maHDN,const std::string &ngayNhap, const std::string &maNV, const std::string &maNCC, const std::vector<ChiTietHoaDonNhap> &dscthdn);
	
    void setMaHDN(std::string maHDN);
    std::string getMaHDN() const;
    void setNgayNhap(std::string ngayNhap);
    std::string getNgayNhap() const;
    void setMaNV(const std::string &maNV); 
    std::string getMaNV() const;
    void setMaNCC(const std::string &maNCC); 
    std::string getMaNCC() const;
    void setDsCTHDN(const std::vector<ChiTietHoaDonNhap> &ds);
    std::vector<ChiTietHoaDonNhap> getDsCTHDN() const;

    void themChiTietHoaDon(const ChiTietHoaDonNhap &chiTiet);
    
    void nhap() const;
	void xuat() const;
    void hienThi() const;
    void luuVaoFile(const std::string &tenFile) const;
    
    double tinhTongTien() const;
    
};

#endif /* HOADONNHAP_H */
