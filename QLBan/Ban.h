#ifndef BAN_H
#define BAN_H

#include <iostream>
#include <fstream>
#include <string>
#include "../DoiTuong.h"

class Ban : public DoiTuong
{
private:
    std::string TrangThai, MaKV;

public:
    Ban();
    Ban(const std::string &maBan, const std::string &tenBan, const std::string &trangThai, const std::string &maKV);

    std::string getMaBan() const;
    void setMaBan(const std::string &maBan);
    std::string getTenBan() const;
    void setTenBan(const std::string &tenBan);
    std::string getTrangThai() const;
    void setTrangThai(const std::string &trangThai);
	std::string getMaKV() const;
	void setMaKV(const std::string &maKV);

    void nhap();
    void xuat() const;
    void luuVaoFile(const std::string &tenFile) const;
};

#endif /* BAN_H */

