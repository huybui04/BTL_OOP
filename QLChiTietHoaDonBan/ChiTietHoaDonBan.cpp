#include "ChiTietHoaDonBan.h"

ChiTietHoaDonBan::ChiTietHoaDonBan() : ChiTietDoiTuong(){}

ChiTietHoaDonBan::ChiTietHoaDonBan(const std::string &MaHDB, const std::string &MaSP, const int &soLuong)
    : ChiTietDoiTuong(MaHDB, MaSP), SoLuong(soLuong)
{
}

ChiTietHoaDonBan::ChiTietHoaDonBan(const std::string &MaHDB, const std::string &MaSP, const int &soLuong, const SanPham &sp)
    : ChiTietDoiTuong(MaHDB, MaSP), SoLuong(soLuong), SP(sp)
{
}

std::string ChiTietHoaDonBan::getMaHDB() const
{
    return ChiTietDoiTuong::getMa1();
}

void ChiTietHoaDonBan::setMaHDB(const std::string &MaHDB)
{
    ChiTietDoiTuong::setMa1(MaHDB);
}

std::string ChiTietHoaDonBan::getMaSP() const
{
    return ChiTietDoiTuong::getMa2();
}
void ChiTietHoaDonBan::setMaSP(const std::string &MaSP)
{
    ChiTietDoiTuong::setMa2(MaSP);
}

SanPham ChiTietHoaDonBan::getSP() const
{
    return SP;
};
void ChiTietHoaDonBan::setSP(const SanPham &sp)
{
    this->SP = sp;
};

int ChiTietHoaDonBan::getSoLuong() const
{
    return SoLuong;
}

void ChiTietHoaDonBan::setSoLuong(int soLuong)
{
    SoLuong = soLuong;
}

void ChiTietHoaDonBan::xuat() const
{
    std::cout << "Ma HDB: " << ChiTietDoiTuong::getMa1() << std::endl;
    std::cout << "Ma SP: " << ChiTietDoiTuong::getMa2() << std::endl;
    std::cout << "So Luong Ban: " << SoLuong << std::endl;
}

void ChiTietHoaDonBan::luuVaoFile(const std::string &tenFile) const {
	std::ofstream file(tenFile, std::ios_base::app);
    if (!file.is_open()) {
        std::cout << "Khong mo duoc file " << tenFile << "de ghi" << std::endl;
        return;
    }

    file << ChiTietDoiTuong::getMa1() << ", " << ChiTietDoiTuong::getMa2() << ", " << SoLuong << std::endl;
    file.close();
}

double ChiTietHoaDonBan::tinhThanhTien() const
{
    return SoLuong * SP.getGia();
}
