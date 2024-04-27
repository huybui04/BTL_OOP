#include "DSHoaDonNhap.h"
#include <fstream>

std::vector<HoaDonNhap> DSHoaDonNhap::getDSHDN() const
{
    return danhSachHoaDon;
}

void DSHoaDonNhap::themHoaDon(const HoaDonNhap &hoaDon)
{
    danhSachHoaDon.push_back(hoaDon);
}


void DSHoaDonNhap::xoaHoaDon(const std::string &maHDN)
{
    for (auto it = danhSachHoaDon.begin(); it != danhSachHoaDon.end(); ++it)
    {
        if (it->getMaHDN() == maHDN)
        {
            danhSachHoaDon.erase(it);
            break;
        }
    }
}

void DSHoaDonNhap::suaHoaDon(const std::string &maHDN, const HoaDonNhap &hoaDonMoi)
{
    for (auto &hoaDon : danhSachHoaDon)
    {
        if (hoaDon.getMaHDN() == maHDN)
        {
            hoaDon = hoaDonMoi;
            break;
        }
    }
}

HoaDonNhap DSHoaDonNhap::timKiemHoaDon(const std::string &maHDN)
{
    for (auto hoaDon : danhSachHoaDon)
    {
        if (hoaDon.getMaHDN() == maHDN)
        {
            return hoaDon;
        }
    }
    return HoaDonNhap();
}

void DSHoaDonNhap::hienThiDanhSach() const
{
    std::cout << "\n\n\tDanh sach hoa don nhap\n\n";
    for (const auto &hdn : danhSachHoaDon)
    {
        hdn.xuat();
        std::cout << std::endl;
    }
}

void DSHoaDonNhap::docDuLieuTuFile(const std::string &tenFile)
{
    std::ifstream file(tenFile);

    if (!file.is_open())
    {
        std::cout << "Khong mo duoc file " << tenFile << " de doc!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string mahdn, ngaynhap, manv, mancc;

        std::getline(ss, mahdn, ',');
        std::getline(ss, ngaynhap, ',');
        std::getline(ss, manv, ',');
        std::getline(ss, mancc);
        
        HoaDonNhap hdn(mahdn, ngaynhap, manv, mancc);
        themHoaDon(hdn);
    }

    file.close();
}

void DSHoaDonNhap::ghiDuLieuVaoFile(const std::string &tenFile)
{
    std::ofstream file(tenFile);
    if (file.is_open())
    {
        for (auto hdn : danhSachHoaDon)
        {
            hdn.luuVaoFile(tenFile);
        }
        file.close();
    }
    else
    {
        std::cout << "Khong mo duoc file " << tenFile << "de ghi" << std::endl;
    }
}

HoaDonNhap *DSHoaDonNhap::timKiemHoaDonTheoMa(const string &maHDN)
{
    for (auto &hdn : danhSachHoaDon)
    {
        if (hdn.getMaHDN() == maHDN)
        {
            return &hdn;
        }
    }
    return nullptr;
}
