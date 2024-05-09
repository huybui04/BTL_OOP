#include "HoaDon.h"

HoaDon::HoaDon() {}

HoaDon::HoaDon(const std::string &ma, const std::string &ngay)
    : MaHoaDon(ma), Ngay(ngay) {}

std::string HoaDon::getMa() const
{
    return MaHoaDon;
}

void HoaDon::setMa(const std::string &ma)
{
    MaHoaDon = ma;
}

std::string HoaDon::getNgay() const
{
    return Ngay;
}

void HoaDon::setNgay(const std::string &ngay)
{
    Ngay = ngay;
}

void HoaDon::nhap()
{
    std::cout << "Nhap Ma hoa don: ";
    std::getline(std::cin, MaHoaDon);
    std::cout << "Nhap ngay: ";
    std::getline(std::cin, Ngay);
}

void HoaDon::xuat() const
{
    std::cout << "Ma hoa don: " << MaHoaDon << std::endl;
    std::cout << "Ngay: " << Ngay << std::endl;
}

void HoaDon::luuVaoFile(const std::string &tenFile) const
{
    std::ofstream file(tenFile, std::ios_base::app);
    if (!file.is_open())
    {
        std::cout << "Khong mo duoc file " << tenFile << "de ghi" << std::endl;
        return;
    }

    file << MaHoaDon << "," << Ngay << std::endl;
    file.close();
}
