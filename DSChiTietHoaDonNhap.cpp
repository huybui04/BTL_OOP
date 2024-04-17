//#include "DSChiTietHoaDonNhap.h"
//#include <fstream>
//
//std::vector<ChiTietHoaDonNhap> DSChiTietHoaDonNhap::getCTHDN() const {
//    return danhSachChiTietHoaDonNhap;
//}
//
//void DSChiTietHoaDonNhap::themChiTiet(const ChiTietHoaDonNhap &chiTiet) {
//    danhSachChiTietHoaDonNhap.push_back(chiTiet);
//}
//
//void DSChiTietHoaDonNhap::suaChiTiet(const HoaDonNhap &hdn, const ChiTietHoaDonNhap &chiTietMoi) {
//    for (auto &chiTiet : danhSachChiTietHoaDonNhap) {
//        if (chiTiet.getHDN().getMaHDN() == hdn.getMaHDN()) {
//            chiTiet = chiTietMoi;
//            break;
//        }
//    }
//}
//
//void DSChiTietHoaDonNhap::xoaChiTiet(const HoaDonNhap &hdn) {
//    for (auto it = danhSachChiTietHoaDonNhap.begin(); it != danhSachChiTietHoaDonNhap.end(); ++it) {
//        if (it->getHDN().getMaHDN() == hdn.getMaHDN()) {
//            danhSachChiTietHoaDonNhap.erase(it);
//            break;
//        }
//    }
//}
//
//ChiTietHoaDonNhap DSChiTietHoaDonNhap::timKiemChiTiet(const HoaDonNhap &hdn) {
//    for (auto chiTiet : danhSachChiTietHoaDonNhap) {
//        if (chiTiet.getHDN().getMaHDN() == hdn.getMaHDN()) {
//            return chiTiet;
//        }
//    }
//    return ChiTietHoaDonNhap();
//}
//
//void DSChiTietHoaDonNhap::ghiDuLieuVaoFile(std::string tenFile) {
//    std::ofstream file(tenFile);
//    if (file.is_open()) {
//        for (auto chiTiet : danhSachChiTietHoaDonNhap) {
//            file << chiTiet.getHDN().getMaHDN() << " " << chiTiet.getNL().getMaNL() << " " << chiTiet.getSoLuongNhap() << std::endl;
//        }
//        file.close();
//    } else {
//        std::cout << "Khong mo duoc file!" << std::endl;
//    }
//}
#include "DSChiTietHoaDonNhap.h"
#include <fstream>

std::vector<ChiTietHoaDonNhap> DSChiTietHoaDonNhap::getCTHDN() const {
    return danhSachChiTietHoaDonNhap;
}

void DSChiTietHoaDonNhap::themChiTiet(const ChiTietHoaDonNhap &chiTiet) {
    danhSachChiTietHoaDonNhap.push_back(chiTiet);
}

void DSChiTietHoaDonNhap::suaChiTiet(const std::string &maHDN, const ChiTietHoaDonNhap &chiTietMoi) {
    for (auto &chiTiet : danhSachChiTietHoaDonNhap) {
        if (chiTiet.getMaHDN() == maHDN) {
            chiTiet = chiTietMoi;
            break;
        }
    }
}

void DSChiTietHoaDonNhap::xoaChiTiet(const std::string &maHDN) {
    for (auto it = danhSachChiTietHoaDonNhap.begin(); it != danhSachChiTietHoaDonNhap.end(); ++it) {
        if (it->getMaHDN() == maHDN) {
            danhSachChiTietHoaDonNhap.erase(it);
            break;
        }
    }
}

ChiTietHoaDonNhap DSChiTietHoaDonNhap::timKiemChiTiet(const std::string &maHDN) {
    for (auto chiTiet : danhSachChiTietHoaDonNhap) {
        if (chiTiet.getMaHDN() == maHDN) {
            return chiTiet;
        }
    }
    return ChiTietHoaDonNhap();
}

void DSChiTietHoaDonNhap::ghiDuLieuVaoFile(std::string tenFile) {
    std::ofstream file(tenFile);
    if (file.is_open()) {
        for (auto chiTiet : danhSachChiTietHoaDonNhap) {
            file << chiTiet.getMaHDN() << " " << chiTiet.getMaNL() << " " << chiTiet.getSoLuongNhap() << std::endl;
        }
        file.close();
    } else {
        std::cout << "Khong mo duoc file!" << std::endl;
    }
}

