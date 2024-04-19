#include "ChiTietHoaDonNhap.h"

ChiTietHoaDonNhap::ChiTietHoaDonNhap() {}

ChiTietHoaDonNhap::ChiTietHoaDonNhap(const std::string &maHDN, const std::string &maNL, const int &soLuongNhap)
    : MaHDN(maHDN), MaNL(maNL), SoLuongNhap(soLuongNhap) 
{
} 
    
ChiTietHoaDonNhap::ChiTietHoaDonNhap(const std::string &maHDN, const std::string &maNL, const int &soLuongNhap, const NguyenLieu &nl)
    : MaHDN(maHDN), MaNL(maNL), SoLuongNhap(soLuongNhap), NL(nl) 
{
}     

std::string ChiTietHoaDonNhap::getMaHDN() const 
{
    return MaHDN;
}

void ChiTietHoaDonNhap::setMaHDN(const std::string &maHDN) 
{
    this->MaHDN = maHDN;
}

std::string ChiTietHoaDonNhap::getMaNL() const 
{
    return MaNL;
}

void ChiTietHoaDonNhap::setMaNL(const std::string &maNL) 
{
    this->MaNL = maNL;
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
    std::cout << "Ma HDN: " << MaHDN << std::endl;
    std::cout << "Ma NL: " << MaNL << std::endl;
    std::cout << "So Luong nhap: " << SoLuongNhap << std::endl;
}

void ChiTietHoaDonNhap::luuVaoFile(const std::string &tenFile) const {
	std::ofstream file(tenFile, std::ios_base::app);
    if (!file.is_open()) {
        std::cout << "Khong mo duoc file " << tenFile << "de ghi" << std::endl;
        return;
    }

    file << MaHDN << ", " << MaNL << ", " << SoLuongNhap << std::endl;
    file.close();
}

double ChiTietHoaDonNhap::tinhThanhTien() const {
    return SoLuongNhap * NL.getGia();
}

