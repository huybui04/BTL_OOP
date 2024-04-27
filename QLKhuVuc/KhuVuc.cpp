#include "KhuVuc.h"

KhuVuc::KhuVuc() {}

KhuVuc::KhuVuc(const std::string &MaKV, const std::string &TenKV)
    : MaKV(MaKV), TenKV(TenKV) {}

std::string KhuVuc::getMaKV() const {
    return MaKV;
}

void KhuVuc::setMaKV(const std::string &MaKV) {
    this->MaKV = MaKV;
}

std::string KhuVuc::getTenKV() const {
    return TenKV;
}

void KhuVuc::setTenKV(const std::string &TenKV) {
    this->TenKV = TenKV;
}

void KhuVuc::nhap() {
    std::cout << "Nhap Ma khu vuc: ";
    std::cin >> MaKV;
    std::cout << "Nhap Ten khu vuc: ";
    std::cin >> TenKV;
}

void KhuVuc::xuat() const {
    std::cout << "Ma khu vuc: " << MaKV << std::endl;
    std::cout << "Ten khu vuc: " << TenKV << std::endl;
}

void KhuVuc::luuVaoFile(const std::string &tenTep) const {
    std::ofstream file(tenTep, std::ios::app);
    if (!file.is_open()) {
        std::cout << "Khong mo duoc file " << tenTep << " de ghi" << std::endl;
        return;
    }

    file << MaKV << ", " << TenKV << std::endl;
    file.close();
}

