#ifndef DSNHACUNGCAP_H
#define DSNHACUNGCAP_H

#include "NhaCungCap.h"
#include <vector>

class DSNhaCungCap {
private:
    std::vector<NhaCungCap> danhSachNhaCungCap;

public:
    void themNhaCungCap(const NhaCungCap &ncc);
    void docDuLieuTuFile(const std::string &tenTep);
    void hienThiDanhSach() const;
    void suaNhaCungCap(const std::string &maNCC, const NhaCungCap &ncc);
    void xoaNhaCungCap(const std::string &maNCC);
    void luuVaoFile(const std::string &tenTep) const;
};

#endif /* DSNHACUNGCAP_H */

