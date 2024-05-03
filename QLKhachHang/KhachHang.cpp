#include "KhachHang.h"

KhachHang::KhachHang() : Nguoi() {}

KhachHang::KhachHang(const std::string &MaKH, const std::string &TenKH, const std::string &SDT)
    : Nguoi(MaKH, TenKH, SDT) {}

std::string KhachHang::getMaKH() const {
    return Nguoi::getMa();
}

void KhachHang::setMaKH(std::string maKH) {
    Nguoi::setMa(maKH);
}

std::string KhachHang::getTenKH() const {
    return DoiTuong::getTen();
}

void KhachHang::setTenKH(std::string tenKH) {
    Nguoi::setTen(tenKH);
}

std::string KhachHang::getSDT() const {
    return Nguoi::getSDT();
}

void KhachHang::setSDT(std::string sdt) {
    Nguoi::setSDT(sdt);
}

void KhachHang::nhap() {
    Nguoi::nhap();
}

void KhachHang::xuat() const {
    Nguoi::xuat();
}

void KhachHang::luuVaoFile(const std::string &tenFile) const {
	Nguoi::luuVaoFile(tenFile);	
}

