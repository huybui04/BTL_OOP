#include "DoiTuong.h"

DoiTuong::DoiTuong() {}

DoiTuong::DoiTuong(const std::string &ma, const std::string &ten)
    : Ma(ma), Ten(ten) {}

std::string DoiTuong::getMa() const {
    return Ma;
}

void DoiTuong::setMa(const std::string &ma) {
    Ma = ma;
}

std::string DoiTuong::getTen() const {
    return Ten;
}

void DoiTuong::setTen(const std::string &ten) {
    Ten = ten;
}

void DoiTuong::nhap() {
    std::cout << "Nhap Ma: ";
    std::getline(std::cin, Ma);
    std::cout << "Nhap Ten: ";
    std::getline(std::cin, Ten);
}

void DoiTuong::xuat() const {
    std::cout << "Ma: " << Ma << std::endl;
    std::cout << "Ten: " << Ten << std::endl;
}

void DoiTuong::luuVaoFile(const std::string &tenFile) const {
	std::ofstream file(tenFile, std::ios_base::app);
    if (!file.is_open()) {
        std::cout << "Khong mo duoc file " << tenFile << "de ghi" << std::endl;
        return;
    }

    file << Ma << ", " << Ten << std::endl;
    file.close();   
}

