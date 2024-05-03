#ifndef BAN_H
#define BAN_H

#include <iostream>
#include <fstream>

class Ban : public DoiTuong {
private:
    std::string TrangThai;

public:
    Ban();
    Ban(const std::string &maBan, const std::string &tenBan, const std::string &trangThai);

    std::string getMaBan() const;
    void setMaBan(const std::string &maBan);
    std::string getTenBan() const;
    void setTenBan(const std::string &tenBan);
    std::string getTrangThai() const;
    void setTrangThai(const std::string &trangThai);

    void nhap();
    void xuat() const;
    void luuVaoFile(const std::string &tenFile) const;
};

#endif /* BAN_H */

