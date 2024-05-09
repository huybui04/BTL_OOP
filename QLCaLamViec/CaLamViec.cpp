#include "CaLamViec.h"

CaLamViec::CaLamViec() : DoiTuong() {}

CaLamViec::CaLamViec(const std::string &maCa, const std::string &tenCa, const std::string &gioBatDau, const std::string &gioKetThuc, double luong)
    : DoiTuong(maCa, tenCa), GioBatDau(gioBatDau), GioKetThuc(gioKetThuc), Luong(luong) {}

std::string CaLamViec::getMaCa() const {
    return DoiTuong::getMa();
}

void CaLamViec::setMaCa(const std::string &maCa) {
    DoiTuong::setMa(maCa);
}

std::string CaLamViec::getTenCa() const {
    return DoiTuong::getTen();
}

void CaLamViec::setTenCa(const std::string &tenCa) {
    DoiTuong::setTen(tenCa);
}

std::string CaLamViec::getGioBatDau() const {
    return GioBatDau;
}

void CaLamViec::setGioBatDau(const std::string &gioBatDau) {
    GioBatDau = gioBatDau;
}

std::string CaLamViec::getGioKetThuc() const {
    return GioKetThuc;
}

void CaLamViec::setGioKetThuc(const std::string &gioKetThuc) {
    GioKetThuc = gioKetThuc;
}

double CaLamViec::getLuong() const
{
    return Luong;
}

void CaLamViec::setLuong(double luong) {
    Luong = luong;
}

void CaLamViec::nhap() {
    DoiTuong::nhap();
    std::cout << "Nhap Gio Bat Dau: ";
    std::getline(std::cin, GioBatDau);
    std::cout << "Nhap Gio Ket Thuc: ";
    std::getline(std::cin, GioKetThuc);
    std::cout << "Nhap Luong: ";
    std::cin >> Luong;
    std::cin.ignore();
}

void CaLamViec::xuat() const {
    DoiTuong::xuat();
    std::cout << "Gio Bat Dau: " << GioBatDau << std::endl;
    std::cout << "Gio Ket Thuc: " << GioKetThuc << std::endl;
    std::cout << "Luong: " << Luong << std::endl;
}

void CaLamViec::luuVaoFile(const std::string &tenFile) const {
    std::ofstream file(tenFile, std::ios_base::app);
    if (!file.is_open()) {
        std::cout << "Khong mo duoc file " << tenFile << " de ghi" << std::endl;
        return;
    }

    file << getMa() << "," << getTen() << "," << GioBatDau << "," << GioKetThuc << "," << Luong << std::endl;
    file.close();
}
