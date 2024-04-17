#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class NhanVien {
private:
    std::string MaNV, TenNV, SDT, GioiTinh, DiaChi, ChucVu, NgaySinh;

public:
    NhanVien();
    NhanVien(std::string MaNV, std::string TenNV, std::string SDT, std::string GioiTinh, std::string DiaChi, std::string ChucVu, std::string NgaySinh);
    std::string getMaNV() const;
    void setMaNV(std::string maNV);
    std::string getTenNV() const;
    void setTenNV(std::string tenNV);
    std::string getSDT() const;
    void setSDT(std::string sdt);
    std::string getGioiTinh() const;
    void setGioiTinh(std::string gioiTinh);
    std::string getDiaChi() const;
    void setDiaChi(std::string diaChi);
    std::string getChucVu() const;
    void setChucVu(std::string chucVu);
    std::string getNgaySinh() const;
    void setNgaySinh(std::string ngaySinh);
    void nhap();
    void xuat() const;
    void luuVaoFile(std::ofstream &file) const;
};

#endif /* NHANVIEN_H */

