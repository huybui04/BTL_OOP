#include "DSBan.h"

std::vector<Ban> DSBan::getDSBan() const {
    return danhSachBan;
}

void DSBan::themBan(const Ban &ban) {
    danhSachBan.push_back(ban);
}

void DSBan::hienThiDanhSach() const {
    for (auto ban : danhSachBan) {
        ban.xuat();
        std::cout << std::endl;
    }
}

void DSBan::docDuLieuTuFile(const std::string &tenTep) {
    std::ifstream file(tenTep);

    if (!file.is_open()) {
        std::cout << "Khong mo duoc file " << tenTep << " de doc!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string maBan, tenBan, trangThai;

        std::getline(ss, maBan, ',');
        std::getline(ss, tenBan, ',');
        std::getline(ss, trangThai);

        Ban ban(maBan, tenBan, trangThai);
        themBan(ban);
    }

    file.close();
}

void DSBan::suaBan(const std::string &maBan, const Ban &ban) {
    bool timThay = false;
    for (auto &b : danhSachBan) {
        if (b.getMaBan() == maBan) {
            b = ban;
            timThay = true;
            break;
        }
    }

    if (!timThay) {
        std::cout << "Khong tim thay ban co Ma Ban: " << maBan << std::endl;
    }
}

void DSBan::xoaBan(const std::string &maBan) {
    bool timThay = false;
    for (auto it = danhSachBan.begin(); it != danhSachBan.end(); ++it) {
        if (it->getMaBan() == maBan) {
            danhSachBan.erase(it);
            timThay = true;
            std::cout << "Da xoa ban co Ma Ban: " << maBan << std::endl;
            break;
        }
    }

    if (!timThay) {
        std::cout << "Khong tim thay ban co Ma Ban: " << maBan << std::endl;
    }
}

void DSBan::luuVaoFile(const std::string &tenTep) {
    std::ofstream file(tenTep);
    if (!file.is_open()) {
        std::cout << "Khong mo duoc file " << tenTep << "de ghi" << std::endl;
        return;
    }

    for (auto ban : danhSachBan) {
        ban.luuVaoFile(file);
    }

    file.close();
}

