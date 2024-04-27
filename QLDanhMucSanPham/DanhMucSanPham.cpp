#include "DanhMucSanPham.h"

DanhMucSanPham::DanhMucSanPham(){}

DanhMucSanPham::DanhMucSanPham(const std::string &MaDM, const std::string &TenDM)
		: MaDM(MaDM), TenDM(TenDM) {}
		
std::string DanhMucSanPham::getMaDM() const {
	return MaDM;
}

void DanhMucSanPham::setMaDM(const std::string &maDM) {
    MaDM = maDM;
}

std::string DanhMucSanPham::getTenDM() const {
    return TenDM;
}

void DanhMucSanPham::setTenDM(const std::string &tenDM) {
    TenDM = tenDM;
}

void DanhMucSanPham::nhap() {
    std::cout << "Nhap Ma DM: ";
    std::cin >> MaDM;
    std::cout << "Nhap Ten DM: ";
    std::cin.ignore();
    std::getline(std::cin, TenDM);
    std::cin.clear();
}

void DanhMucSanPham::xuat() const {
    std::cout << "Ma DM: " << MaDM << std::endl;
    std::cout << "Ten DM: " << TenDM << std::endl;
}

void DanhMucSanPham::luuVaoFile(const std::string &tenTep) const {
    std::ofstream file(tenTep, std::ios_base::app);
    if (!file.is_open()) {
        std::cout << "Khong mo duoc file " << tenTep << " de ghi" << std::endl;
        return;
    }

    file << MaDM << ", " << TenDM << std::endl;
    file.close();
}

