#include "NhaCungCap.h"

NhaCungCap::NhaCungCap() {}

NhaCungCap::NhaCungCap(const std::string &MaNCC, const std::string &TenNCC, const std::string &DiaChi, const std::string &SDT)
    : MaNCC(MaNCC), TenNCC(TenNCC), DiaChi(DiaChi), SDT(SDT) {}

std::string NhaCungCap::getMaNCC() const {
    return MaNCC;
}

void NhaCungCap::setMaNCC(const std::string &maNCC) {
    MaNCC = maNCC;
}

std::string NhaCungCap::getTenNCC() const {
    return TenNCC;
}

void NhaCungCap::setTenNCC(const std::string &tenNCC) {
    TenNCC = tenNCC;
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
    std::cout << "Nhap Ma NCC: ";
    std::getline(std::cin, MaNCC);
    std::cout << "Nhap Ten NCC: ";
    std::getline(std::cin, TenNCC);
    std::cout << "Nhap Dia Chi: ";
    std::getline(std::cin, DiaChi);
    std::cout << "Nhap SDT: ";
    std::getline(std::cin, SDT);
}

void NhaCungCap::xuat() const {
    std::cout << "Ma NCC: " << MaNCC << std::endl;
    std::cout << "Ten NCC: " << TenNCC << std::endl;
    std::cout << "Dia Chi: " << DiaChi << std::endl;
    std::cout << "SDT: " << SDT << std::endl;
}

void NhaCungCap::luuVaoFile(const std::string &tenFile) const {
	std::ofstream file(tenFile, std::ios_base::app);
    if (!file.is_open()) {
        std::cout << "Khong mo duoc file " << tenFile << "de ghi" << std::endl;
        return;
    }

    file << MaNCC << ", " << TenNCC << ", " << DiaChi << ", " << SDT << std::endl;
    file.close();
    
}

