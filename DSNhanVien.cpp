#include "DSNhanVien.h"
#include <algorithm>

std::vector<NhanVien> DSNhanVien::getDSNV() const {
    return danhSachNhanVien;
}

void DSNhanVien::themNhanVien(const NhanVien &nv) {
    danhSachNhanVien.push_back(nv);
}

void DSNhanVien::docDuLieuTuFile(const std::string &tenTep) {
    std::ifstream file(tenTep);

    if (!file.is_open()) {
        std::cout << "Khong mo duoc file" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string maNV, tenNV, sdt, gioiTinh, diaChi, chucVu, ngaySinh;

        std::getline(ss, maNV, ',');
        std::getline(ss, tenNV, ',');
        std::getline(ss, sdt, ',');
        std::getline(ss, gioiTinh, ',');
        std::getline(ss, diaChi, ',');
        std::getline(ss, chucVu, ',');
        std::getline(ss, ngaySinh);

        NhanVien nv(maNV, tenNV, sdt, gioiTinh, diaChi, chucVu, ngaySinh);
        danhSachNhanVien.push_back(nv);
    }

    file.close();
}

void DSNhanVien::hienThiDanhSach() const {
    for (const auto &nv : danhSachNhanVien) {
        nv.xuat();
        std::cout << std::endl;
    }
}

void DSNhanVien::suaNhanVien(const std::string &maNV, const NhanVien &nv) {
    bool timThay = false;
    for (auto &nhanVien : danhSachNhanVien) {
        if (nhanVien.getMaNV() == maNV) {
            nhanVien = nv;
            timThay = true;
            break;
        }
    }

    if (!timThay) {
        std::cout << "Khong tim thay nhan vien co MaNV: " << maNV << std::endl;
    }
}

void DSNhanVien::xoaNhanVien(const std::string &maNV) {
    auto it = find_if(danhSachNhanVien.begin(), danhSachNhanVien.end(), [&maNV](const NhanVien &nv) {
        return nv.getMaNV() == maNV;
    });

    if (it != danhSachNhanVien.end()) {
        danhSachNhanVien.erase(it);
        std::cout << "Da xoa nhan vien co MaNV: " << maNV << std::endl;
    } else {
        std::cout << "Khong tim thay nhan vien co MaNV: " << maNV << std::endl;
    }
}

NhanVien DSNhanVien::timKiemNhanVien(const std::string &maNV) const {
    for (const auto &nv : danhSachNhanVien) {
        if (nv.getMaNV() == maNV) {
            return nv;
        }
    }

    std::cout << "Khong tim thay nhan vien co MaNV: " << maNV << std::endl;
    return NhanVien(); // Tr? v? d?i tu?ng r?ng n?u không tìm th?y
}

void DSNhanVien::luuVaoFile(const std::string &tenTep) const {
    std::ofstream file(tenTep);
    if (!file.is_open()) {
        std::cout << "Khong mo duoc file" << std::endl;
        return;
    }

    for (const auto &nv : danhSachNhanVien) {
        nv.luuVaoFile(file);
    }

    file.close();
}

