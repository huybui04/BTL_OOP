#include "DSNguyenLieu.h"

std::vector<NguyenLieu> DSNguyenLieu::getDSNL() const {
    return danhSachNguyenLieu;
}

void DSNguyenLieu::themNguyenLieu(const NguyenLieu &nl) {
    danhSachNguyenLieu.push_back(nl);
}

void DSNguyenLieu::hienThiDanhSach() const {
    for (auto nl : danhSachNguyenLieu) {
        nl.xuat();
        std::cout << std::endl;
    }
}

void DSNguyenLieu::docDuLieuTuFile(const std::string &tenTep) {
    std::ifstream file(tenTep);

    if (!file.is_open()) {
        std::cout << "Khong mo duoc file " << tenTep << " de doc!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string maNL, tenNL, nsx, hsd;
        double gia;

        std::getline(ss, maNL, ',');
        std::getline(ss, tenNL, ',');
        std::getline(ss, nsx, ',');
        std::getline(ss, hsd, ',');
        ss >> gia;

        NguyenLieu nl(maNL, tenNL, nsx, hsd, gia);
        themNguyenLieu(nl);
    }

    file.close();
}

void DSNguyenLieu::suaNguyenLieu(const std::string &maNL, const NguyenLieu &nl) {
    bool timThay = false;
    for (auto &nguyenlieu : danhSachNguyenLieu) {
        if (nguyenlieu.getMaNL() == maNL) {
            nguyenlieu = nl;
            timThay = true;
            break;
        }
    }

    if (!timThay) {
        std::cout << "Khong tim thay nguyen lieu co Ma NL: " << maNL << std::endl;
    }
}

void DSNguyenLieu::xoaNguyenLieu(const std::string &maNL) {
    bool timThay = false;
    for (auto it = danhSachNguyenLieu.begin(); it != danhSachNguyenLieu.end(); ++it) {
        if (it->getMaNL() == maNL) {
            danhSachNguyenLieu.erase(it);
            timThay = true;
            std::cout << "Da xoa nguyen lieu co Ma NL: " << maNL << std::endl;
            break;
        }
    }

    if (!timThay) {
        std::cout << "Khong tim thay nguyen lieu co Ma NL: " << maNL << std::endl;
    }
}

void DSNguyenLieu::luuVaoFile(const std::string &tenTep) {
    std::ofstream file(tenTep);
    if (!file.is_open()) {
        std::cout << "Khong mo duoc file " << tenTep << "de ghi" << std::endl;
        return;
    }

    for (auto nl : danhSachNguyenLieu) {
        nl.luuVaoFile(file);
    }

    file.close();
}

