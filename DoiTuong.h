#ifndef DOITUONG_H
#define DOITUONG_H

#include <iostream>
#include <fstream>

class DoiTuong {
protected:
    std::string Ma;
    std::string Ten;

public:
    DoiTuong();
    DoiTuong(const std::string &ma, const std::string &ten);

    std::string getMa() const;
    void setMa(const std::string &ma);
    std::string getTen() const;
    void setTen(const std::string &ten);

    void nhap();
    void xuat() const;
    void luuVaoFile(const std::string &tenFile) const;
};

#endif /* DOITUONG_H */

