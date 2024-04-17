#include "NguyenLieu.h"

NguyenLieu::NguyenLieu() : Gia(0.0) {}

NguyenLieu::NguyenLieu(const std::string &MaNL, const std::string &TenNL, const std::string &NSX, const std::string &HSD, double Gia)
    : MaNL(MaNL), TenNL(TenNL), NSX(NSX), HSD(HSD), Gia(Gia) {}

std::string NguyenLieu::getMaNL() const {
    return MaNL;
}

void NguyenLieu::setMaNL(const std::string &maNL) {
    MaNL = maNL;
}

std::string NguyenLieu::getTenNL() const {
    return TenNL;
}

void NguyenLieu::setTenNL(const std::string &tenNL) {
    TenNL = tenNL;
}

std::string NguyenLieu::getNSX() const {
    return NSX;
}

void NguyenLieu::setNSX(const std::string &nsx) {
    NSX = nsx;
}

std::string NguyenLieu::getHSD() const {
    return HSD;
}

void NguyenLieu::setHSD(const std::string &hsd) {
    HSD = hsd;
}

double NguyenLieu::getGia() const {
    return Gia;
}

void NguyenLieu::setGia(double gia) {
    Gia = gia;
}

void NguyenLieu::nhap() {
    std::cout << "Nhap Ma NL: ";
    std::getline(std::cin, MaNL);
    std::cout << "Nhap Ten NL: ";
    std::getline(std::cin, TenNL);
    std::cout << "Nhap NSX: ";
    std::getline(std::cin, NSX);
    std::cout << "Nhap HSD: ";
    std::getline(std::cin, HSD);
    std::cout << "Nhap Gia: ";
    std::cin >> Gia;
    std::cin.ignore(); // clear input buffer
}

void NguyenLieu::xuat() const {
    std::cout << "Ma NL: " << MaNL << std::endl;
    std::cout << "Ten NL: " << TenNL << std::endl;
    std::cout << "NSX: " << NSX << std::endl;
    std::cout << "HSD: " << HSD << std::endl;
    std::cout << "Gia: " << Gia << std::endl;
}

void NguyenLieu::luuVaoFile(std::ofstream &file) const {
    file << MaNL << "," << TenNL << "," << NSX << "," << HSD << "," << Gia << std::endl;
}

