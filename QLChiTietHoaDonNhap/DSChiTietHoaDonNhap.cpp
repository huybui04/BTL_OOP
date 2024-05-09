#include "DSChiTietHoaDonNhap.h"
#include <fstream>
#include <sstream>

std::vector<ChiTietHoaDonNhap> DSChiTietHoaDonNhap::getDSCTHDN() const
{
    return danhSachChiTietHoaDonNhap;
}

void DSChiTietHoaDonNhap::themChiTiet(const ChiTietHoaDonNhap &chiTiet)
{
    danhSachChiTietHoaDonNhap.push_back(chiTiet);
}

void DSChiTietHoaDonNhap::suaChiTiet(const std::string &maHDN, const ChiTietHoaDonNhap &chiTietMoi)
{
    for (auto &chiTiet : danhSachChiTietHoaDonNhap)
    {
        if (chiTiet.getMaHDN() == maHDN)
        {
            chiTiet = chiTietMoi;
            break;
        }
    }
}

void DSChiTietHoaDonNhap::xoaChiTiet(const std::string &maHDN)
{
    for (auto it = danhSachChiTietHoaDonNhap.begin(); it != danhSachChiTietHoaDonNhap.end(); ++it)
    {
        if (it->getMaHDN() == maHDN)
        {
            danhSachChiTietHoaDonNhap.erase(it);
            break;
        }
    }
}

ChiTietHoaDonNhap DSChiTietHoaDonNhap::timKiemChiTiet(const std::string &maHDN)
{
    for (auto chiTiet : danhSachChiTietHoaDonNhap)
    {
        if (chiTiet.getMaHDN() == maHDN)
        {
            return chiTiet;
        }
    }
    return ChiTietHoaDonNhap();
}

void DSChiTietHoaDonNhap::hienThiDanhSach() const
{
    std::cout << "\n\n\tDanh sach chi tiet hoa don nhap\n\n";
    for (const auto &cthdn : danhSachChiTietHoaDonNhap)
    {
        cthdn.xuat();
        std::cout << std::endl;
    }
}

void DSChiTietHoaDonNhap::docDuLieuTuFile(const std::string &tenFile)
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
        std::string mahdn, manl, SoLuongNhap;

        std::getline(ss, mahdn, ',');
        std::getline(ss, manl, ',');
        std::getline(ss, SoLuongNhap);
        int SL = std::stoi(SoLuongNhap);

        ChiTietHoaDonNhap cthdn(mahdn, manl, SL);
        themChiTiet(cthdn);
    }

    file.close();
}

void DSChiTietHoaDonNhap::ghiDuLieuVaoFile(const std::string &tenFile)
{
    std::ofstream file(tenFile);
    if (file.is_open())
    {
        for (auto cthdn : danhSachChiTietHoaDonNhap)
        {
            cthdn.luuVaoFile(tenFile);
        }
        file.close();
    }
    else
    {
        std::cout << "Khong mo duoc file " << tenFile << " de ghi!" << std::endl;
    }
}

ChiTietHoaDonNhap *DSChiTietHoaDonNhap::timKiemChiTietHoaDonTheoMa(const std::string &maHDN)
{
    for (auto &cthdn : danhSachChiTietHoaDonNhap)
    {
        if (cthdn.getMaHDN() == maHDN)
        {
            return &cthdn;
        }
    }
    return nullptr;
}
