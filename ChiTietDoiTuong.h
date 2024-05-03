#ifndef CHITIETDOITUONG_H
#define CHITIETDOITUONG_H

#include <iostream>
#include <fstream>

class ChiTietDoiTuong {
protected:
    std::string Ma1;
    std::string Ma2;

public:
    ChiTietDoiTuong();
	ChiTietDoiTuong(const std::string &ma1, const std::string &ma2);

    std::string getMa1() const;
    void setMa1(const std::string &ma1);
    std::string getMa2() const;
    void setMa2(const std::string &ma2);

    void nhap();
    void xuat() const;
    void luuVaoFile(const std::string &tenFile) const;
};

#endif /* CHITIETDOITUONG_H */

