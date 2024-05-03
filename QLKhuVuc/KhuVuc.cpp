#include "KhuVuc.h"

KhuVuc::KhuVuc() : DoiTuong() {}

KhuVuc::KhuVuc(const std::string &MaKV, const std::string &TenKV)
    : DoiTuong(MaKV, TenKV) {}

std::string KhuVuc::getMaKV() const {
    return DoiTuong::getMa();
}

void KhuVuc::setMaKV(const std::string &MaKV) {
    DoiTuong::setMa(MaKV);
}


std::string KhuVuc::getTenKV() const {
    return DoiTuong::getTen();
}

void KhuVuc::setTenKV(const std::string &TenKV) {
    DoiTuong::setTen(TenKV);
}

void KhuVuc::nhap() {
    DoiTuong::nhap();
}

void KhuVuc::xuat() const {
    DoiTuong::xuat();
}

void KhuVuc::luuVaoFile(const std::string &tenTep) const {
    DoiTuong::luuVaoFile(tenTep);
}
