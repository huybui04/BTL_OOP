#include "KhachHang.h"

KhachHang::KhachHang() {}

KhachHang::KhachHang(std::string MaKH, std::string TenKH, std::string SDT)
    : MaKH(MaKH), TenKH(TenKH), SDT(SDT) {}

std::string KhachHang::getMaKH() const {
    return MaKH;
}

void KhachHang::setMaKH(std::string maKH) {
    MaKH = maKH;
}

std::string KhachHang::getTenKH() const {
    return TenKH;
}

void KhachHang::setTenKH(std::string tenKH) {
    TenKH = tenKH;
}

std::string KhachHang::getSDT() const {
    return SDT;
}

void KhachHang::setSDT(std::string sdt) {
    SDT = sdt;
}

void KhachHang::nhap() {
    std::cout << "Nhap Ma KH: ";
    std::cin >> MaKH;
    std::cout << "Nhap Ten KH: ";
    std::cin.ignore();
    std::getline(std::cin, TenKH);
    std::cout << "Nhap SDT: ";
    std::cin >> SDT;
}

void KhachHang::xuat() const {
    std::cout << "Ma KH: " << MaKH << std::endl;
    std::cout << "Ten KH: " << TenKH << std::endl;
    std::cout << "SDT: " << SDT << std::endl;
}

void KhachHang::luuVaoFile(std::ofstream &file) const {
    file << MaKH << "," << TenKH << "," << SDT << std::endl;
}

