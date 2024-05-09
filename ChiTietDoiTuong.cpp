#include "ChiTietDoiTuong.h"

ChiTietDoiTuong::ChiTietDoiTuong(){};

ChiTietDoiTuong::ChiTietDoiTuong(const std::string &ma1, const std::string &ma2)
	:Ma1(ma1), Ma2(ma2) {};
	
std::string ChiTietDoiTuong::getMa1() const {
	return Ma1;
}

void ChiTietDoiTuong::setMa1(const std::string &ma1) {
	Ma1 = ma1;
}

std::string ChiTietDoiTuong::getMa2() const {
	return Ma2;
}

void ChiTietDoiTuong::setMa2(const std::string &ma2) {
	Ma2 = ma2;
}

void ChiTietDoiTuong::nhap() {
	std::cout << "Nhap Ma1: ";
    std::getline(std::cin, Ma1);
    std::cout << "Nhap Ma2: ";
    std::getline(std::cin, Ma2);	
}

void ChiTietDoiTuong::xuat() const {
	std::cout << "Ma1: " << Ma1 << std::endl;
    std::cout << "Ma2: " << Ma2 << std::endl;
}

void ChiTietDoiTuong::luuVaoFile(const std::string &tenFile) const {
	std::ofstream file(tenFile, std::ios_base::app);
    if (!file.is_open()) {
        std::cout << "Khong mo duoc file " << tenFile << "de ghi" << std::endl;
        return;
    }

    file << Ma1 << "," << Ma2 << std::endl;
    file.close(); 
}
