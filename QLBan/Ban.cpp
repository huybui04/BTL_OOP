#include "Ban.h"

Ban::Ban() : DoiTuong() {}

Ban::Ban(const std::string &maBan, const std::string &tenBan, const std::string &trangThai)
    : DoiTuong(maBan, tenBan), TrangThai(trangThai) {}

std::string Ban::getMaBan() const
{
    return DoiTuong::getMa();
}

void Ban::setMaBan(const std::string &maBan)
{
    DoiTuong::setMa(maBan);
}

std::string Ban::getTenBan() const
{
    return DoiTuong::getTen();
}

void Ban::setTenBan(const std::string &tenBan)
{
    DoiTuong::setTen(tenBan);
}

std::string Ban::getTrangThai() const
{
    return TrangThai;
}

void Ban::setTrangThai(const std::string &trangThai)
{
    TrangThai = trangThai;
}

void Ban::nhap()
{
    DoiTuong::nhap();
    std::cout << "Nhap Trang Thai: ";
    std::getline(std::cin, TrangThai);
}

void Ban::xuat() const
{
    DoiTuong::xuat();
    std::cout << "Trang Thai: " << TrangThai << std::endl;
}

void Ban::luuVaoFile(const std::string &tenFile) const
{
    std::ofstream file(tenFile, std::ios_base::app);
    if (!file.is_open())
    {
        std::cout << "Khong mo duoc file " << tenFile << "de ghi" << std::endl;
        return;
    }

    file << getMa() << "," << getTen() << "," << TrangThai << std::endl;
    file.close();
}
