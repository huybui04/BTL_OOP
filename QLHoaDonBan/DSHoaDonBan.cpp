#include "DSHoaDonBan.h"
#include <fstream>
#include <sstream>

std::vector<HoaDonBan> DSHoaDonBan::getDSHDB() const
{
    return danhSachHoaDon;
}

void DSHoaDonBan::themHoaDon(const HoaDonBan &hoaDon)
{
    danhSachHoaDon.push_back(hoaDon);
}

void DSHoaDonBan::xoaHoaDon(const std::string &maHDB)
{
    for (auto it = danhSachHoaDon.begin(); it != danhSachHoaDon.end(); ++it)
    {
        if (it->getMaHDB() == maHDB)
        {
            danhSachHoaDon.erase(it);
            break;
        }
    }
}

void DSHoaDonBan::suaHoaDon(const std::string &maHDB, const HoaDonBan &hoaDonMoi)
{
    for (auto &hoaDon : danhSachHoaDon)
    {
        if (hoaDon.getMaHDB() == maHDB)
        {
            hoaDon = hoaDonMoi;
            break;
        }
    }
}

HoaDonBan DSHoaDonBan::timKiemHoaDon(const std::string &maHDB)
{
    for (auto hoaDon : danhSachHoaDon)
    {
        if (hoaDon.getMaHDB() == maHDB)
        {
            return hoaDon;
        }
    }
    return HoaDonBan();
}

void DSHoaDonBan::hienThiDanhSach() const
{
    std::cout << "\n\n\tDanh sach hoa don ban\n\n";
    for (const auto &hdb : danhSachHoaDon)
    {
        hdb.xuat();
        std::cout << std::endl;
    }
}

void DSHoaDonBan::docDuLieuTuFile(const std::string &tenFile)
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
        std::string mahdb, ngayban, manv, makh, maban;

        std::getline(ss, mahdb, ',');
        std::getline(ss, ngayban, ',');
        std::getline(ss, manv, ',');
        std::getline(ss, makh, ',');
        std::getline(ss, maban);

        HoaDonBan hdb(mahdb, ngayban, manv, makh, maban);
        themHoaDon(hdb);
    }

    file.close();
}

void DSHoaDonBan::ghiDuLieuVaoFile(const std::string &tenFile)
{
    std::ofstream file(tenFile);
    if (file.is_open())
    {
        for (auto hdb : danhSachHoaDon)
        {
            hdb.luuVaoFile(tenFile);
        }
        file.close();
    }
    else
    {
        std::cout << "Khong mo duoc file " << tenFile << "de ghi" << std::endl;
    }
}

HoaDonBan *DSHoaDonBan::timKiemHoaDonTheoMa(const std::string &maHDB)
{
    for (auto &hdb : danhSachHoaDon)
    {
        if (hdb.getMaHDB() == maHDB)
        {
            return &hdb;
        }
    }
    return nullptr;
}
