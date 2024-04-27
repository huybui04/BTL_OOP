#include "DSChiTietHoaDonBan.h"
#include <fstream>

std::vector<ChiTietHoaDonBan> DSChiTietHoaDonBan::getDSCTHDB() const
{
    return danhSachChiTietHoaDonBan;
}

void DSChiTietHoaDonBan::themChiTiet(const ChiTietHoaDonBan &chiTiet)
{
    danhSachChiTietHoaDonBan.push_back(chiTiet);
}

void DSChiTietHoaDonBan::suaChiTiet(const std::string &MaHDB, const ChiTietHoaDonBan &chiTietMoi)
{
    for (auto &chiTiet : danhSachChiTietHoaDonBan)
    {
        if (chiTiet.getMaHDB() == MaHDB)
        {
            chiTiet = chiTietMoi;
            break;
        }
    }
}

void DSChiTietHoaDonBan::xoaChiTiet(const std::string &MaHDB)
{
    for (auto it = danhSachChiTietHoaDonBan.begin(); it != danhSachChiTietHoaDonBan.end(); ++it)
    {
        if (it->getMaHDB() == MaHDB)
        {
            danhSachChiTietHoaDonBan.erase(it);
            break;
        }
    }
}

ChiTietHoaDonBan DSChiTietHoaDonBan::timKiemChiTiet(const std::string &MaHDB)
{
    for (auto chiTiet : danhSachChiTietHoaDonBan)
    {
        if (chiTiet.getMaHDB() == MaHDB)
        {
            return chiTiet;
        }
    }
    return ChiTietHoaDonBan();
}

void DSChiTietHoaDonBan::hienThiDanhSach() const
{
    cout << "\n\n\tDanh sach chi tiet hoa don ban\n\n";
    for (const auto &cthdb : danhSachChiTietHoaDonBan)
    {
        cthdb.xuat();
        std::cout << std::endl;
    }
}

void DSChiTietHoaDonBan::docDuLieuTuFile(const std::string &tenFile)
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
        std::string mahdb, masp, SoLuong;

        std::getline(ss, mahdb, ',');
        std::getline(ss, masp, ',');
        std::getline(ss, SoLuong);
        int SL = std::stoi(SoLuong);

        ChiTietHoaDonBan cthdb(mahdb, masp, SL);
        themChiTiet(cthdb);
    }

    file.close();
}

void DSChiTietHoaDonBan::ghiDuLieuVaoFile(const std::string &tenFile)
{
    std::ofstream file(tenFile, std::ios_base::app);
    if (file.is_open())
    {
        for (auto cthdb : danhSachChiTietHoaDonBan)
        {
            cthdb.luuVaoFile(tenFile);
        }
        file.close();
    }
    else
    {
        std::cout << "Khong mo duoc file " << tenFile << "de ghi" << std::endl;
    }
}

ChiTietHoaDonBan *DSChiTietHoaDonBan::timKiemChiTietHoaDonTheoMa(const string &maHDB)
{
    for (auto &cthdb : danhSachChiTietHoaDonBan)
    {
        if (cthdb.getMaHDB() == maHDB)
        {
            return &cthdb;
        }
    }
    return nullptr;
}
