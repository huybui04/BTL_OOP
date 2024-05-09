#include "Ban.h"
#include "../QLKhuVuc/KhuVuc.h"

Ban::Ban() : DoiTuong() {}

Ban::Ban(const std::string &maBan, const std::string &tenBan, const std::string &trangThai, const std::string &maKV)
    : DoiTuong(maBan, tenBan), TrangThai(trangThai), MaKV(maKV) {}

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

std::string Ban::getMaKV() const
{
    return MaKV;
}

void Ban::setMaKV(const std::string &maKV)
{
    MaKV = maKV;
}

void Ban::nhap()
{
    DoiTuong::nhap();
    std::cout << "Nhap Trang Thai: ";
    std::getline(std::cin, TrangThai);
    std::cout << "Nhap Ma khu vuc: ";
    std::getline(std::cin, MaKV);
}

void Ban::xuat() const
{
    DoiTuong::xuat();
    std::cout << "Trang Thai: " << TrangThai << std::endl;
    std::cout << "Ma khu vuc: " << MaKV << std::endl;
}

void Ban::luuVaoFile(const std::string &tenFile) const
{
    std::ofstream file(tenFile, std::ios_base::app);
    if (!file.is_open())
    {
        std::cout << "Khong mo duoc file " << tenFile << "de ghi" << std::endl;
        return;
    }

    file << getMa() << "," << getTen() << "," << TrangThai << "," << MaKV << std::endl;
    file.close();
}
