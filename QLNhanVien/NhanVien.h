#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <fstream>
#include "../Nguoi.h"
class NhanVien : public Nguoi
{
private:
    std::string MaNV, ChucVu;

public:
    NhanVien();
    NhanVien(std::string CCCD, std::string TenNV, std::string SDT, std::string DiaChi, std::string GioiTinh, std::string NgaySinh, std::string MaNV, std::string ChucVu);
    
    std::string getCCCD() const;
    void setCCCD(std::string cccd);
    std::string getTenNV() const;
    void setTenNV(std::string tenNV);
    std::string getSDT() const;
    void setSDT(std::string sdt);
    std::string getDiaChi() const;
    void setDiaChi(std::string diaChi);
    std::string getGioiTinh() const;
    void setGioiTinh(std::string gioiTinh);    
    std::string getNgaySinh() const;
    void setNgaySinh(std::string ngaySinh);
    std::string getMaNV() const;
    void setMaNV(std::string maNV);
    std::string getChucVu() const;
    void setChucVu(std::string chucVu);

    void nhap();
    void xuat() const;
    void luuVaoFile(const std::string &tenFile) const;
};

#endif /* NHANVIEN_H */
