//#include "ChiTietHoaDonNhap.h"
//
//ChiTietHoaDonNhap::ChiTietHoaDonNhap() {}
//
//ChiTietHoaDonNhap::ChiTietHoaDonNhap(const HoaDonNhap &HDN, const NguyenLieu &NL, int SoLuongNhap)
//    : HDN(HDN), NL(NL), SoLuongNhap(SoLuongNhap) {}
//
//HoaDonNhap ChiTietHoaDonNhap::getHDN() const {
//    return HDN;
//}
//
//void ChiTietHoaDonNhap::setHDN(const HoaDonNhap &hdn) {
//    this->HDN = hdn;
//}
//
//NguyenLieu ChiTietHoaDonNhap::getNL() const {
//    return NL;
//}
//
//void ChiTietHoaDonNhap::setNL(const NguyenLieu &nl) {
//    this->NL = nl;
//}
//
//int ChiTietHoaDonNhap::getSoLuongNhap() const {
//    return SoLuongNhap;
//}
//
//void ChiTietHoaDonNhap::setSoLuongNhap(int soluong) {
//    this->SoLuongNhap = soluong;
//}
//
//double ChiTietHoaDonNhap::tinhThanhTien() const {
//    return SoLuongNhap * NL.getGia();
//}
#include "ChiTietHoaDonNhap.h"

ChiTietHoaDonNhap::ChiTietHoaDonNhap() {}

ChiTietHoaDonNhap::ChiTietHoaDonNhap(const std::string &maHDN, const std::string &maNL, int SoLuongNhap)
    : MaHDN(maHDN), MaNL(maNL), SoLuongNhap(SoLuongNhap) {} // S?a d?i constructor

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

