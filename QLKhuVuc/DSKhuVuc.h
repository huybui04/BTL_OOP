#ifndef DSKHUVUC_H
#define DSKHUVUC_H

#include "KhuVuc.h"
#include <vector>

class DSKhuVuc {
private:
    std::vector<KhuVuc> danhSachKhuVuc;

public:
    std::vector<KhuVuc> getDSKV() const;
    void themKhuVuc(const KhuVuc &khuVuc);
    void xoaKhuVuc(const std::string &maKV);
    void suaKhuVuc(const std::string &maKV, const KhuVuc &kv);
    void hienThiDanhSach() const;
    KhuVuc timKiemKhuVuc(const std::string &maKV);
    KhuVuc *timKiemTheoMa(const std::string &maKV);

    void docDuLieuTuFile(const std::string &tenFile);
    void luuVaoFile(const std::string &tenTep) const;
};

#endif

