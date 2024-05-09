#include "KhachHang.h"

KhachHang::KhachHang() : Nguoi() {}

KhachHang::KhachHang(const std::string &CCCD, const std::string &TenKH, const std::string &SDT, const std::string &DiaChi, const std::string &GioiTinh, const std::string &NgaySinh, const std::string &MaKH)
    : Nguoi(CCCD, TenKH, SDT, DiaChi, GioiTinh, NgaySinh), MaKH(MaKH) {}

std::string KhachHang::getCCCD() const {
    return Nguoi::getCCCD();
}

void KhachHang::setCCCD(const std::string &cccd) {
    Nguoi::setCCCD(cccd);
}

std::string KhachHang::getTenKH() const {
    return Nguoi::getTen();
}

void KhachHang::setTenKH(const std::string &tenKH) {
    Nguoi::setTen(tenKH);
}

std::string KhachHang::getSDT() const {
    return Nguoi::getSDT();
}

void KhachHang::setSDT(const std::string &sdt) {
    Nguoi::setSDT(sdt);
}

std::string KhachHang::getDiaChi() const {
	return Nguoi::getDiaChi();
}

void KhachHang::setDiaChi(const std::string &diaChi) {
	Nguoi::setDiaChi(diaChi);
}

std::string KhachHang::getGioiTinh() const {
	return Nguoi::getGioiTinh();
}

void KhachHang::setGioiTinh(const std::string &gioiTinh) {
	Nguoi::setGioiTinh(gioiTinh);
}

std::string KhachHang::getMaKH() const {
    return MaKH;
}

void KhachHang::setMaKH(const std::string &maKH) {
    MaKH = maKH;
}

void KhachHang::nhap() {
    Nguoi::nhap();
    std::cout << "Nhap ma khach hang: ";
    std::getline(std::cin, MaKH);
}

void KhachHang::xuat() const {
    Nguoi::xuat();
    std::cout << "Ma khach hang: " << MaKH << std::endl;
}

void KhachHang::luuVaoFile(const std::string &tenFile) const {
	std::ofstream file(tenFile, std::ios_base::app);
    if (!file.is_open())
    {
        std::cout << "Khong mo duoc file " << tenFile << " de ghi" << std::endl;
        return;
    }

    file << Nguoi::getCCCD() << "," << Nguoi::getTen() << "," << Nguoi::getSDT() << "," << Nguoi::getDiaChi() << "," << Nguoi::getGioiTinh() << "," << Nguoi::getNgaySinh() << "," << MaKH << std::endl;
    file.close();
}

