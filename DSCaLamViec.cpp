#include "DSCaLamViec.h"
#include <fstream>

std::vector<CaLamViec> DSCaLamViec::getDSCaLamViec() const {
    return danhSachCaLamViec;
}

void DSCaLamViec::themCaLamViec(const CaLamViec &caLamViec) {
    danhSachCaLamViec.push_back(caLamViec);
}

void DSCaLamViec::xoaCaLamViec(const std::string &maCa) {
    for (auto it = danhSachCaLamViec.begin(); it != danhSachCaLamViec.end(); ++it) {
        if (it->getMaCa() == maCa) {
            danhSachCaLamViec.erase(it);
            break;
        }
    }
}

void DSCaLamViec::suaCaLamViec(const std::string &maCa, const CaLamViec &caLamViecMoi) {
    for (auto &caLamViec : danhSachCaLamViec) {
        if (caLamViec.getMaCa() == maCa) {
            caLamViec = caLamViecMoi;
            break;
        }
    }
}

void DSCaLamViec::hienThiDanhSach() const {
    for (const auto &caLamViec : danhSachCaLamViec) {
        caLamViec.xuat();
        std::cout << std::endl;
    }
}

CaLamViec DSCaLamViec::timKiemCaLamViec(const std::string &maCa) {
    for (const auto &caLamViec : danhSachCaLamViec) {
        if (caLamViec.getMaCa() == maCa) {
            return caLamViec;
        }
    }
    // Tr? v? m?t ca làm vi?c r?ng n?u không tìm th?y
    return CaLamViec();
}

void DSCaLamViec::docDuLieuTuFile(const std::string &tenFile) {
    std::ifstream file(tenFile);
    if (!file.is_open()) {
        std::cout << "Khong mo duoc file " << tenFile << " de doc" << std::endl;
        return;
    }

    while (!file.eof()) {
        std::string maCa, tenCa, gioBatDau, gioKetThuc;
        double luong;
        file >> maCa >> tenCa >> gioBatDau >> gioKetThuc >> luong;
        CaLamViec caLamViec(maCa, tenCa, gioBatDau, gioKetThuc, luong);
        themCaLamViec(caLamViec);
    }
    file.close();
}

void DSCaLamViec::ghiDuLieuVaoFile(const std::string &tenFile) {
    std::ofstream file(tenFile);
    if (!file.is_open()) {
        std::cout << "Khong mo duoc file " << tenFile << " de ghi" << std::endl;
        return;
    }

    for (const auto &caLamViec : danhSachCaLamViec) {
        caLamViec.luuVaoFile(tenFile);;
    }
    file.close();
}

