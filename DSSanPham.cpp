#include "DSSanPham.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::vector<SanPham> DSSanPham::getDSSP() const {
    return danhSachSanPham;
}

void DSSanPham::themSanPham() {
    SanPham sp;
    sp.nhap();
    danhSachSanPham.push_back(sp);
}

void DSSanPham::docDuLieuTuFile(const std::string &tenTep) {
    std::ifstream file(tenTep);

    if (!file.is_open()) {
        std::cerr << "Khong mo duoc file" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string maSP, tenSP;
        double gia;

        std::getline(ss, maSP, ',');
        std::getline(ss, tenSP, ',');
        ss >> gia;

        SanPham sp(maSP, tenSP, gia);
        danhSachSanPham.push_back(sp);
    }

    file.close();
}

void DSSanPham::hienThiDanhSach() const {
    for (const auto &sp : danhSachSanPham) {
        sp.xuat();
        std::cout << std::endl;
    }
}

void DSSanPham::suaSanPham(const std::string &maSP, const SanPham &sp) {
    bool timThay = false;
    for (auto &sanpham : danhSachSanPham) {
        if (sanpham.getMaSP() == maSP) {
            sanpham = sp;
            timThay = true;
            break;
        }
    }

    if (!timThay) {
        std::cerr << "Khong tim thay san pham co MaSP: " << maSP << std::endl;
    }
}

void DSSanPham::xoaSanPham(const std::string &maSP) {
    auto it = std::find_if(danhSachSanPham.begin(), danhSachSanPham.end(),
                           [maSP](const SanPham &sp) { return sp.getMaSP() == maSP; });

    if (it != danhSachSanPham.end()) {
        danhSachSanPham.erase(it);
        std::cout << "Da xoa san pham co MaSP: " << maSP << std::endl;
    } else {
        std::cerr << "Khong tim thay san pham co MaSP: " << maSP << std::endl;
    }
}

void DSSanPham::luuVaoFile(const std::string &tenTep) const {
    std::ofstream file(tenTep);
    if (!file.is_open()) {
        std::cerr << "Khong mo duoc file" << std::endl;
        return;
    }

    for (const auto &sp : danhSachSanPham) {
        sp.luuVaoFile(file);
    }

    file.close();
}

