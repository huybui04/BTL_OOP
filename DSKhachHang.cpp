#include "DSKhachHang.h"
#include <algorithm>

void DSKhachHang::themKhachHang(const KhachHang &khachHang) {
    danhSachKhachHang.push_back(khachHang);
}

void DSKhachHang::docTuFile(const std::string &tenFile) {
    std::ifstream file(tenFile);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string maKH, tenKH, sdt;
            std::getline(ss, maKH, ',');
            std::getline(ss, tenKH, ',');
            std::getline(ss, sdt);

            KhachHang kh(maKH, tenKH, sdt);
            themKhachHang(kh);
        }
        file.close();
    } else {
        std::cout << "Khong mo duoc file " << tenFile << " de doc!" << std::endl;
    }
}

void DSKhachHang::hienThiDanhSach() const {
    for (const auto &kh : danhSachKhachHang) {
        kh.xuat();
        std::cout << std::endl;
    }
}

void DSKhachHang::suaKhachHang(const std::string &maKH, const KhachHang &khachHang) {
    bool timThay = false;
    for (auto &kh : danhSachKhachHang) {
        if (kh.getMaKH() == maKH) {
            kh = khachHang;
            timThay = true;
            break;
        }
    }

    if (!timThay) {
        std::cout << "Khong tim thay khach hang co MaKH: " << maKH << std::endl;
    }
}

void DSKhachHang::xoaKhachHang(const std::string &maKH) {
    auto it = std::find_if(danhSachKhachHang.begin(), danhSachKhachHang.end(), [&maKH](const KhachHang &kh) {
        return kh.getMaKH() == maKH;
    });

    if (it != danhSachKhachHang.end()) {
        danhSachKhachHang.erase(it);
        std::cout << "Da xoa khach hang co MaKH: " << maKH << std::endl;
    } else {
        std::cout << "Khong tim thay khach hang co MaKH: " << maKH << std::endl;
    }
}

void DSKhachHang::luuVaoFile(const std::string &tenTep) const {
    std::ofstream file(tenTep);
    if (!file.is_open()) {
        std::cout << "Khong mo duoc file" << std::endl;
        return;
    }

    for (const auto &kh : danhSachKhachHang) {
        kh.luuVaoFile(file);
    }

    file.close();
}

