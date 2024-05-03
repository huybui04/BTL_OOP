#ifndef NGUOI_H
#define NGUOI_H

#include "DoiTuong.h"
#include <iostream>
#include <fstream>

class Nguoi: public DoiTuong {
protected:
    std::string SDT;

public:
    Nguoi();
    Nguoi(const std::string &ma, const std::string &ten, const std::string &sdt);

    std::string getSDT() const;
    void setSDT(const std::string &sdt);

    void nhap();
    void xuat() const;
    void luuVaoFile(const std::string &tenFile) const;
};

#endif /* DOITUONG_H */

