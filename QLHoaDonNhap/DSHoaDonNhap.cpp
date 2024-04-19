#include "DSHoaDonNhap.h"
#include <fstream>

std::vector<std::string> DSHoaDonNhap::getDSHDN() const {
    return danhSachHoaDon;
}

void DSHoaDonNhap::themHoaDon(const std::string &maHDN) {
    danhSachHoaDon.push_back(maHDN);
}

void DSHoaDonNhap::xoaHoaDon(std::string maHDN) {
    for (auto it = danhSachHoaDon.begin(); it != danhSachHoaDon.end(); ++it) {
        if (*it == maHDN) {
            danhSachHoaDon.erase(it);
            break;
        }
    }
}

void DSHoaDonNhap::suaHoaDon(std::string maHDN, const std::string &maHDNMoi) {
    for (auto &maHDN : danhSachHoaDon) {
        if (maHDN == maHDN) {
            maHDN = maHDNMoi;
            break;
        }
    }
}

std::string DSHoaDonNhap::timKiemHoaDon(std::string maHDN) {
    for (auto maHDN : danhSachHoaDon) {
        if (maHDN == maHDN) {
            return maHDN;
        }
    }
    return "";
}

void DSHoaDonNhap::docDuLieuTuFile(std::string tenFile) {
    std::ifstream file(tenFile);
    if (file.is_open()) {
        std::string maHDN;
        while (std::getline(file, maHDN)) {
            themHoaDon(maHDN);
        }
        file.close();
    } else {
        std::cout << "Khong mo duoc file " << tenFile << " de doc!" << std::endl;
    }
}

void DSHoaDonNhap::ghiDuLieuVaoFile(std::string tenFile) {
    std::ofstream file(tenFile);
    if (file.is_open()) {
        for (auto maHDN : danhSachHoaDon) {
            file << maHDN << std::endl;
        }
        file.close();
    } else {
        std::cout << "Khong mo duoc file " << tenFile << "de ghi" << std::endl;
    }
}

