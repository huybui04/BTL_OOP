#include "SanPham.h"

SanPham::SanPham() : DoiTuong() {}

SanPham::SanPham(const std::string &MaSP, const std::string &TenSP, double Gia)
    : DoiTuong(MaSP, TenSP), Gia(Gia) {}

std::string SanPham::getMaSP() const
{
    return DoiTuong::getMa();
}

void SanPham::setMaSP(const std::string &maSP)
{
    DoiTuong::setMa(maSP);
}

std::string SanPham::getTenSP() const
{
    return DoiTuong::getTen();
}

void SanPham::setTenSP(const std::string &tenSP)
{
    DoiTuong::setTen(tenSP);
}

double SanPham::getGia() const
{
    return Gia;
}

void SanPham::setGia(double gia)
{
    Gia = gia;
}

void SanPham::nhap()
{
    DoiTuong::nhap();
    std::cout << "Nhap Gia: ";
    std::cin >> Gia;
}

void SanPham::xuat() const
{
    DoiTuong::xuat();
    std::cout << "Gia: " << Gia << " VND" << std::endl;
}

void SanPham::luuVaoFile(const std::string &tenFile) const
{
	std::ofstream file(tenFile, std::ios_base::app);
    if (!file.is_open()) {
        std::cout << "Khong mo duoc file " << tenFile << "de ghi" << std::endl;
        return;
    }

    file << getMa() << ", " << getTen() << ", " << Gia << std::endl;
    file.close();
    
}
