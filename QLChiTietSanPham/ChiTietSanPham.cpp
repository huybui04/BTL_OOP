#include "ChiTietSanPham.h"

ChiTietSanPham::ChiTietSanPham() : ChiTietDoiTuong() {}

ChiTietSanPham::ChiTietSanPham(const std::string &MaNL, const std::string &MaSP, const int &SoLuongSuDung)
    : ChiTietDoiTuong(MaNL, MaSP), SoLuongSuDung(SoLuongSuDung)
{
}

ChiTietSanPham::ChiTietSanPham(const std::string &MaNL, const std::string &MaSP, const int &SoLuongSuDung, const NguyenLieu &NL, const SanPham &SP)
    : ChiTietDoiTuong(MaNL, MaSP), SoLuongSuDung(SoLuongSuDung), NL(NL), SP(SP)
{
}

std::string ChiTietSanPham::getMaNL() const
{
    return ChiTietDoiTuong::getMa1();
}

void ChiTietSanPham::setMaNL(const std::string &MaNL)
{
    ChiTietDoiTuong::setMa1(MaNL);
}

std::string ChiTietSanPham::getMaSP() const
{
    return ChiTietDoiTuong::getMa2();
}
void ChiTietSanPham::setMaSP(const std::string &MaSP)
{
    ChiTietDoiTuong::setMa2(MaSP);
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

void ChiTietSanPham::nhap()
{
    ChiTietDoiTuong::nhap();
    std::cout << "Nhap so luong su dung: ";
    std::cin >> SoLuongSuDung;
}

void ChiTietSanPham::xuat() const
{
    ChiTietDoiTuong::xuat();
    std::cout << "So Luong Su Dung: " << SoLuongSuDung << std::endl;
}


void ChiTietSanPham::luuVaoFile(const std::string &tenFile) const {
    std::ofstream file(tenFile, std::ios_base::app);
    if (!file.is_open()) {
        std::cout << "Khong mo duoc file " << tenFile << "de ghi" << std::endl;
        return;
    }

    file << ChiTietDoiTuong::getMa1() << "," << ChiTietDoiTuong::getMa2() << "," << SoLuongSuDung << std::endl;
    file.close();
}
