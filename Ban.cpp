#include "Ban.h"

Ban::Ban() {}

Ban::Ban(const std::string &maBan, const std::string &tenBan, const std::string &trangThai)
    : MaBan(maBan), TenBan(tenBan), TrangThai(trangThai) {}

std::string Ban::getMaBan() const {
    return MaBan;
}

void Ban::setMaBan(const std::string &maBan) {
    MaBan = maBan;
}

std::string Ban::getTenBan() const {
    return TenBan;
}

void Ban::setTenBan(const std::string &tenBan) {
    TenBan = tenBan;
}

std::string Ban::getTrangThai() const {
    return TrangThai;
}

void Ban::setTrangThai(const std::string &trangThai) {
    TrangThai = trangThai;
}

void Ban::nhap() {
    std::cout << "Nhap Ma Ban: ";
    std::getline(std::cin, MaBan);
    std::cout << "Nhap Ten Ban: ";
    std::getline(std::cin, TenBan);
    std::cout << "Nhap Trang Thai: ";
    std::getline(std::cin, TrangThai);
}

void Ban::xuat() const {
    std::cout << "Ma Ban: " << MaBan << std::endl;
    std::cout << "Ten Ban: " << TenBan << std::endl;
    std::cout << "Trang Thai: " << TrangThai << std::endl;
}

void Ban::luuVaoFile(std::ofstream &file) const {
    file << MaBan << "," << TenBan << "," << TrangThai << std::endl;
}

