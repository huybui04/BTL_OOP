#include "ChiTietSanPham.h"

ChiTietSanPham::ChiTietSanPham() {}

ChiTietSanPham::ChiTietSanPham(const std::string &MaNL, const std::string &MaSP, const int &SoLuongSuDung)
    : MaNL(MaNL), MaSP(MaSP), SoLuongSuDung(SoLuongSuDung)
{
}

ChiTietSanPham::ChiTietSanPham(const std::string &MaNL, const std::string &MaSP, const int &SoLuongSuDung, const NguyenLieu &NL, const SanPham &SP)
    : MaNL(MaNL), MaSP(MaSP), SoLuongSuDung(SoLuongSuDung), NL(NL), SP(SP)
{
}

std::string ChiTietSanPham::getMaNL() const
{
    return MaNL;
}

void ChiTietSanPham::setMaNL(const std::string &MaNL)
{
    this->MaNL = MaNL;
}

std::string ChiTietSanPham::getMaSP() const
{
    return MaSP;
}
void ChiTietSanPham::setMaSP(const std::string &MaSP)
{
    this->MaSP = MaSP;
}

NguyenLieu ChiTietSanPham::getNL() const
{
    return NL;
};
void ChiTietSanPham::setNL(const NguyenLieu &NL)
{
    this->NL = NL;
};

SanPham ChiTietSanPham::getSP() const
{
    return SP;
};
void ChiTietSanPham::setSP(const SanPham &SP)
{
    this->SP = SP;
};

int ChiTietSanPham::getSoLuongSuDung() const
{
    return SoLuongSuDung;
}

void ChiTietSanPham::setSoLuongSuDung(int SoLuongSuDung)
{
    this->SoLuongSuDung = SoLuongSuDung;
}

void ChiTietSanPham::xuat() const
{
    std::cout << "Ma NL: " << MaNL << std::endl;
    std::cout << "Ma SP: " << MaSP << std::endl;
    std::cout << "So Luong Su Dung: " << SoLuongSuDung << std::endl;
}


void ChiTietSanPham::luuVaoFile(const std::string &tenFile) const {
    std::ofstream file(tenFile, std::ios_base::app);
    if (!file.is_open()) {
        std::cout << "Khong mo duoc file " << tenFile << "de ghi" << std::endl;
        return;
    }

    file << MaNL << ", " << MaSP << ", " << SoLuongSuDung << std::endl;
    file.close();
}
