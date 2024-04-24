#ifndef DSCALAMVIEC_H
#define DSCALAMVIEC_H

#include "CaLamViec.h"
#include <vector>
#include <string>
#include <sstream>

class DSCaLamViec
{
private:
    std::vector<CaLamViec> danhSachCaLamViec;

public:
    std::vector<CaLamViec> getDSCaLamViec() const;
    void themCaLamViec(const CaLamViec &caLamViec);
    void xoaCaLamViec(const std::string &maCa);
    void suaCaLamViec(const std::string &maCa, const CaLamViec &caLamViecMoi);
    void hienThiDanhSach() const;
    CaLamViec timKiemCaLamViec(const std::string &maCa);
    CaLamViec *timKiemTheoMa(const std::string &maCa);

    void docDuLieuTuFile(const std::string &tenFile);
    void ghiDuLieuVaoFile(const std::string &tenFile);
};

#endif /* DSCALAMVIEC_H */
