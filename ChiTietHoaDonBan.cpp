#include "ChiTietHoaDonBan.h"

ChiTietHoaDonBan::ChiTietHoaDonBan() {}

ChiTietHoaDonBan::ChiTietHoaDonBan(const std::string &MaHDB, const std::string &MaSP, const int &soLuong)
    : MaHDB(MaHDB), MaSP(MaSP), SoLuong(soLuong) { 
}

ChiTietHoaDonBan::ChiTietHoaDonBan(const std::string &MaHDB, const std::string &MaSP, const int &soLuong, const SanPham &sp)
    : MaHDB(MaHDB), MaSP(MaSP), SoLuong(soLuong), SP(sp) { 
}

std::string ChiTietHoaDonBan::getMaHDB() const {
    return MaHDB;
}

void ChiTietHoaDonBan::setMaHDB(const std::string &MaHDB) {
    this->MaHDB = MaHDB;
}

std::string ChiTietHoaDonBan::getMaSP() const {
	return MaSP;
}
void ChiTietHoaDonBan::setMaSP(const std::string &MaSP) {
	this->MaSP = MaSP;
}

SanPham ChiTietHoaDonBan::getSP() const {
	return SP;
};
void ChiTietHoaDonBan::setSP(const SanPham &sp) {
	this->SP = sp;
};

int ChiTietHoaDonBan::getSoLuong() const {
    return SoLuong;
}

void ChiTietHoaDonBan::setSoLuong(int soLuong) {
    SoLuong = soLuong;
}

void ChiTietHoaDonBan::xuat() const {
    std::cout << "Ma HDB: " << MaHDB << std::endl;
    std::cout << "Ma SP: " << MaSP << std::endl;
    std::cout << "So Luong Ban: " << SoLuong << std::endl;
}

double ChiTietHoaDonBan::tinhThanhTien() const {
	return SoLuong * SP.getGia();
}

