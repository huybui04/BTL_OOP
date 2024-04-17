#include "ChiTietHoaDonBan.h"

ChiTietHoaDonBan::ChiTietHoaDonBan() {}

ChiTietHoaDonBan::ChiTietHoaDonBan(const std::vector<SanPham> &dssp) {
	this->dssp = dssp;
}

ChiTietHoaDonBan::ChiTietHoaDonBan(const std::string &MaHDB, const std::string &MaSP, int soLuong)
    : MaHDB(MaHDB), MaSP(MaSP), SoLuong(soLuong){ 	
}

ChiTietHoaDonBan::ChiTietHoaDonBan(const std::string &MaHDB, const std::string &MaSP, int soLuong, const std::vector<SanPham> &dssp)
    : MaHDB(MaHDB), MaSP(MaSP), SoLuong(soLuong){ 
	for(auto sp : dssp) {
		if(sp.getMaSP()==this->MaSP){
			this->dssp.push_back(sp);
		}
	}	
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

std::vector<SanPham> ChiTietHoaDonBan::getDSSP() const {
	return dssp;
};
void ChiTietHoaDonBan::setDSSP(const std::vector<SanPham> &dssp) {
	this->dssp = dssp;
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
	for(auto sp : dssp) {
		if(MaSP == sp.getMaSP())
		return SoLuong * sp.getGia();
	}
}

