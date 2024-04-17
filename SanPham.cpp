#include "SanPham.h"

SanPham::SanPham() : Gia(0.0) {}

SanPham::SanPham(const std::string &MaSP, const std::string &TenSP, double Gia)
    : MaSP(MaSP), TenSP(TenSP), Gia(Gia) {}

std::string SanPham::getMaSP() const {
    return MaSP;
}

void SanPham::setMaSP(const std::string &maSP) {
    MaSP = maSP;
}

std::string SanPham::getTenSP() const {
    return TenSP;
}

void SanPham::setTenSP(const std::string &tenSP) {
    TenSP = tenSP;
}

double SanPham::getGia() const {
    return Gia;
}

void SanPham::setGia(double gia) {
    Gia = gia;
}

void SanPham::nhap() {
    std::cout << "Nhap Ma SP: ";
    std::cin >> MaSP;
    std::cout << "Nhap Ten SP: ";
    std::cin.ignore();
    std::getline(std::cin, TenSP);
    std::cout << "Nhap Gia: ";
    std::cin >> Gia;
}

void SanPham::xuat() const {
    std::cout << "Ma SP: " << MaSP << std::endl;
    std::cout << "Ten SP: " << TenSP << std::endl;
    std::cout << "Gia: " << Gia << std::endl;
}

void SanPham::luuVaoFile(std::ofstream &file) const {
    file << MaSP << "," << TenSP << "," << Gia << std::endl;
}

