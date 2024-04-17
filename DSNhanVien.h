#ifndef DSNHANVIEN_H
#define DSNHANVIEN_H

//#include <iostream>
//#include <fstream>
//#include <sstream>
#include <vector>
#include "NhanVien.h"

class DSNhanVien {
private:
    std::vector<NhanVien> danhSachNhanVien;

public:
    std::vector<NhanVien> getDSNV() const;
    void themNhanVien(const NhanVien &nv);
    void docDuLieuTuFile(const std::string &tenTep);
    void hienThiDanhSach() const;
    void suaNhanVien(const std::string &maNV, const NhanVien &nv);
    void xoaNhanVien(const std::string &maNV);
    NhanVien timKiemNhanVien(const std::string &maNV) const;
    void luuVaoFile(const std::string &tenTep) const;
};

#endif /* DSNHANVIEN_H */

