#include "HoaDonBan.h"

HoaDonBan::HoaDonBan() {};

HoaDonBan::HoaDonBan(const std::vector<ChiTietHoaDonBan> &dscthdb)  {
	for(auto ct : dscthdb) {
		if(ct.getMaHDB() == this->MaHDB)
		dsCTHDB.push_back(ct);
	}
}

HoaDonBan::HoaDonBan(const std::string &maHDB, const std::string &ngayBan, const std::string &manv, const std::string &makh, const std::string &maban, const std::vector<ChiTietHoaDonBan> &dscthdb)
    : MaHDB(maHDB), NgayBan(ngayBan), MaNV(manv), MaKH(makh), MaBan(maban) {
		for(auto ct : dscthdb) {
			if(ct.getMaHDB() == this->MaHDB)
			dsCTHDB.push_back(ct);
		}
	}

void HoaDonBan::setMaHDB(const std::string &maHDB) {
    MaHDB = maHDB;
}

std::string HoaDonBan::getMaHDB() const {
    return MaHDB;
}

void HoaDonBan::setNgayBan(const std::string &ngayBan) {
    NgayBan = ngayBan;
}

std::string HoaDonBan::getNgayBan() const {
    return NgayBan;
}

void HoaDonBan::setMaNV(const std::string manv) {
    MaNV = manv;
}

std::string HoaDonBan::getMaNV() const {
    return MaNV;
}

void HoaDonBan::setMaKH(const std::string makh) {
    MaKH = makh;
}

std::string HoaDonBan::getMaKH() const {
    return MaKH;
}

void HoaDonBan::setMaBan(const std::string maban) {
    this->MaBan = maban;
}

std::string HoaDonBan::getMaBan() const {
    return MaBan;
}

void HoaDonBan::setDsCTHDB(const std::vector<ChiTietHoaDonBan> &ds) {
    dsCTHDB = ds;
}

std::vector<ChiTietHoaDonBan> HoaDonBan::getDsCTHDB() const {
    return dsCTHDB;
}

void HoaDonBan::themChiTietHoaDon(const ChiTietHoaDonBan &chiTiet) {
    dsCTHDB.push_back(chiTiet);
}

void HoaDonBan::luuVaoFile(std::ofstream &file) const {
    file << MaHDB << "," << NgayBan << "," << MaNV << "," << MaKH  << "," << MaBan << std::endl;
}

double HoaDonBan::tinhTongTien() const {
    double tongTien = 0.0;
    for (auto ct : dsCTHDB) {
		if(ct.getMaHDB() == this->MaHDB)
            tongTien += ct.tinhThanhTien();
    }
    return tongTien;
}

void HoaDonBan::hienThi() const {
    std::cout << "Ma Hoa Don: " << MaHDB << std::endl;
    std::cout << "Ngay Ban: " << NgayBan << std::endl;
    std::cout << "Nhan Vien: " << MaNV << std::endl;
    std::cout << "Khach Hang: " << MaKH << std::endl;
    std::cout << "Ban: " << MaBan << std::endl;
    std::cout << "Danh Sach Chi Tiet Hoa Don Ban:" << std::endl;
    for (auto ct : dsCTHDB) {
            std::cout << "   + " << ct.getMaSP() << " - So Luong: " << ct.getSoLuong() << " - Thanh Tien: " << ct.tinhThanhTien() << std::endl;
    }
    std::cout << "Tong Tien: " << tinhTongTien() << std::endl;
}





