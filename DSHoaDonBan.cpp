#include "DSHoaDonBan.h"
#include <fstream>

std::vector<HoaDonBan> DSHoaDonBan::getDSHDB() const {
    return danhSachHoaDon;
}

void DSHoaDonBan::themHoaDon(const HoaDonBan &hoaDon) {
    danhSachHoaDon.push_back(hoaDon);
}

void DSHoaDonBan::xoaHoaDon(const std::string &maHDB) {
    for (auto it = danhSachHoaDon.begin(); it != danhSachHoaDon.end(); ++it) {
        if (it->getMaHDB() == maHDB) {
            danhSachHoaDon.erase(it);
            break;
        }
    }
}

void DSHoaDonBan::suaHoaDon(const std::string &maHDB, const HoaDonBan &hoaDonMoi) {
    for (auto &hoaDon : danhSachHoaDon) {
        if (hoaDon.getMaHDB() == maHDB) {
            hoaDon = hoaDonMoi;
            break;
        }
    }
}

HoaDonBan DSHoaDonBan::timKiemHoaDon(const std::string &maHDB) {
    for (auto hoaDon : danhSachHoaDon) {
        if (hoaDon.getMaHDB() == maHDB) {
            return hoaDon;
        }
    }
    return HoaDonBan();
}

void DSHoaDonBan::docDuLieuTuFile(const std::string &tenFile) {
    std::ifstream file(tenFile);
    if (file.is_open()) {
        // Ð?c d? li?u t? file và thêm vào danh sách
        file.close();
    } else {
        std::cout << "Khong mo duoc file " << tenFile << " de doc!" << std::endl;
    }
}

void DSHoaDonBan::ghiDuLieuVaoFile(const std::string &tenFile) {
    std::ofstream file(tenFile);
    if (file.is_open()) {
        for (auto hdb : danhSachHoaDon) {
	        hdb.luuVaoFile(file);
	    }
        file.close();
    } else {
        std::cout << "Khong mo duoc file " << tenFile << "de ghi" << std::endl;
    }
    
}


