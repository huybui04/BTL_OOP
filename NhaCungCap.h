#ifndef NHACUNGCAP_H
#define NHACUNGCAP_H

#include <iostream>
#include <fstream>

class NhaCungCap {
private:
    std::string MaNCC, TenNCC, DiaChi, SDT;

public:
    NhaCungCap();
    NhaCungCap(const std::string &MaNCC, const std::string &TenNCC, const std::string &DiaChi, const std::string &SDT);

    std::string getMaNCC() const;
    void setMaNCC(const std::string &maNCC);

    std::string getTenNCC() const;
    void setTenNCC(const std::string &tenNCC);

    std::string getDiaChi() const;
    void setDiaChi(const std::string &diaChi);

    std::string getSDT() const;
    void setSDT(const std::string &sdt);

    void nhap();
    void xuat() const;
    void luuVaoFile(std::ofstream &file) const;
};

#endif /* NHACUNGCAP_H */

