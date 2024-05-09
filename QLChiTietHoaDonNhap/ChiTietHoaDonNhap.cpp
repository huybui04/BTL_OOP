#include "ChiTietHoaDonNhap.h"

ChiTietHoaDonNhap::ChiTietHoaDonNhap() : ChiTietDoiTuong() {}

ChiTietHoaDonNhap::ChiTietHoaDonNhap(const std::string &maHDN, const std::string &maNL, const int &soLuongNhap)
    : ChiTietDoiTuong(maHDN, maNL), SoLuongNhap(soLuongNhap)
{
}

ChiTietHoaDonNhap::ChiTietHoaDonNhap(const std::string &maHDN, const std::string &maNL, const int &soLuongNhap, const NguyenLieu &nl)
    : ChiTietDoiTuong(maHDN, maNL), SoLuongNhap(soLuongNhap), NL(nl)
{
}

std::string ChiTietHoaDonNhap::getMaHDN() const
{
    return ChiTietDoiTuong::getMa1();
}

void ChiTietHoaDonNhap::setMaHDN(const std::string &maHDN)
{
    ChiTietDoiTuong::setMa1(maHDN);
}

std::string ChiTietHoaDonNhap::getMaNL() const
{
    return ChiTietDoiTuong::getMa2();
}

void ChiTietHoaDonNhap::setMaNL(const std::string &maNL)
{
    ChiTietDoiTuong::setMa2(maNL);
}

int ChiTietHoaDonNhap::getSoLuongNhap() const
{
    return SoLuongNhap;
}

void ChiTietHoaDonNhap::setSoLuongNhap(int soLuong)
{
    SoLuongNhap = soLuong;
}

NguyenLieu ChiTietHoaDonNhap::getNL() const
{
    return NL;
};
void ChiTietHoaDonNhap::setNL(const NguyenLieu &nl)
{
    NL = nl;
};

void ChiTietHoaDonNhap::xuat() const
{
    ChiTietDoiTuong::xuat();
    std::cout << "So Luong nhap: " << SoLuongNhap << std::endl;
}

void ChiTietHoaDonNhap::luuVaoFile(const std::string &tenFile) const
{
    std::ofstream file(tenFile, std::ios_base::app);
    if (!file.is_open())
    {
        std::cout << "Khong mo duoc file " << tenFile << "de ghi" << std::endl;
        return;
    }

    file << ChiTietDoiTuong::getMa1() << "," << ChiTietDoiTuong::getMa2() << "," << SoLuongNhap << std::endl;
    file.close();
}

double ChiTietHoaDonNhap::tinhThanhTien() const
{
    return SoLuongNhap * NL.getGia();
}
