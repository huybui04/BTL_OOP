#include "ChiTietHoaDonNhap.h"

ChiTietHoaDonNhap::ChiTietHoaDonNhap() {}

ChiTietHoaDonNhap::ChiTietHoaDonNhap(const std::string &maHDN, const std::string &maNL, int SoLuongNhap)
    : MaHDN(maHDN), MaNL(maNL), SoLuongNhap(SoLuongNhap) {} 
std::string ChiTietHoaDonNhap::getMaHDN() const {
    return MaHDN;
}

void ChiTietHoaDonNhap::setMaHDN(const std::string &maHDN) {
    this->MaHDN = maHDN;
}

std::string ChiTietHoaDonNhap::getMaNL() const {
    return MaNL;
}

void ChiTietHoaDonNhap::setMaNL(const std::string &maNL) {
    this->MaNL = maNL;
}

int ChiTietHoaDonNhap::getSoLuongNhap() const {
    return SoLuongNhap;
}

void ChiTietHoaDonNhap::setSoLuongNhap(int soluong) {
    this->SoLuongNhap = soluong;
}

double ChiTietHoaDonNhap::tinhThanhTien() const {
    return SoLuongNhap * 1;
}

