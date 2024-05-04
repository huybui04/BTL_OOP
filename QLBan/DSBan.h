#ifndef DSBAN_H
#define DSBAN_H

#include "Ban.h"
#include <iostream>
#include <vector>
#include <sstream>

class DSBan
{
private:
    std::vector<Ban> danhSachBan;

public:
    std::vector<Ban> getDSBan() const;
    void themBan(const Ban &ban);
    void hienThiDanhSach() const;
    void docDuLieuTuFile(const std::string &tenTep);
    void suaBan(const std::string &maBan, const Ban &ban);
    void xoaBan(const std::string &maBan);
    void luuVaoFile(const std::string &tenTep);
    Ban *timKiemTheoMa(const std::string &maBan);
};

#endif /* DSBAN_H */
