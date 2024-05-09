#include "NhaCungCap.h"

NhaCungCap::NhaCungCap() : DoiTuong() {}

NhaCungCap::NhaCungCap(const std::string &MaNCC, const std::string &TenNCC, const std::string &DiaChi, const std::string &SDT)
    : DoiTuong(MaNCC, TenNCC), DiaChi(DiaChi), SDT(SDT) {}

std::string NhaCungCap::getMaNCC() const {
    return DoiTuong::getMa();
}

void NhaCungCap::setMaNCC(const std::string &maNCC) {
    DoiTuong::setMa(maNCC);
}

std::string NhaCungCap::getTenNCC() const {
    return DoiTuong::getTen();
}

void NhaCungCap::setTenNCC(const std::string &tenNCC) {
    DoiTuong::setTen(tenNCC);
}

std::string NhaCungCap::getDiaChi() const {
    return DiaChi;
}

void NhaCungCap::setDiaChi(const std::string &diaChi) {
    DiaChi = diaChi;
}

std::string NhaCungCap::getSDT() const {
    return SDT;
}

void NhaCungCap::setSDT(const std::string &sdt) {
    SDT = sdt;
}

void NhaCungCap::nhap() {
    DoiTuong::nhap();
    std::cout << "Nhap Dia chi: ";
    std::getline(std::cin, DiaChi);
    std::cout << "Nhap SDT: ";
    std::getline(std::cin, SDT);
}

void NhaCungCap::xuat() const {
    DoiTuong::xuat();
    std::cout << "Dia Chi: " << DiaChi << std::endl;
	std::cout << "SDT: " << SDT << std::endl;
}

void NhaCungCap::luuVaoFile(const std::string &tenFile) const {
	std::ofstream file(tenFile, std::ios_base::app);
    if (!file.is_open()) {
        std::cout << "Khong mo duoc file " << tenFile << "de ghi" << std::endl;
        return;
    }

    file << DoiTuong::getMa() << ", " << DoiTuong::getTen() << ", " << DiaChi << ", " << SDT << ", " << std::endl;
    file.close();
}

