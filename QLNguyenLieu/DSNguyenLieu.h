#ifndef DSNguyenLieu_H
#define DSNguyenLieu_H

#include "NguyenLieu.h"
#include <iostream>
#include <fstream>
#include <vector>

class DSNguyenLieu
{
private:
    std::vector<NguyenLieu> danhSachNguyenLieu;

public:
    std::vector<NguyenLieu> getDSNL() const;
    void themNguyenLieu(const NguyenLieu &nl);
    void hienThiDanhSach() const;
    void docDuLieuTuFile(const std::string &tenTep);
    void suaNguyenLieu(const std::string &maNL, const NguyenLieu &nl);
    void xoaNguyenLieu(const std::string &maNL);
    void luuVaoFile(const std::string &tenTep);
    NguyenLieu *timKiemNguyenLieu(const std::string &maNL);
};

#endif /* DSNguyenLieu_H */
