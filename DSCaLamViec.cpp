#include "DSCaLamViec.h"
#include <fstream>

std::vector<CaLamViec> DSCaLamViec::getDSCaLamViec() const
{
    return danhSachCaLamViec;
}

void DSCaLamViec::themCaLamViec(const CaLamViec &caLamViec)
{
    danhSachCaLamViec.push_back(caLamViec);
}

void DSCaLamViec::xoaCaLamViec(const std::string &maCa)
{
    for (auto it = danhSachCaLamViec.begin(); it != danhSachCaLamViec.end(); ++it)
    {
        if (it->getMaCa() == maCa)
        {
            danhSachCaLamViec.erase(it);
            break;
        }
    }
}

void DSCaLamViec::suaCaLamViec(const std::string &maCa, const CaLamViec &caLamViecMoi)
{
    for (auto &caLamViec : danhSachCaLamViec)
    {
        if (caLamViec.getMaCa() == maCa)
        {
            caLamViec = caLamViecMoi;
            break;
        }
    }
}

void DSCaLamViec::hienThiDanhSach() const
{
    for (const auto &caLamViec : danhSachCaLamViec)
    {
        caLamViec.xuat();
        std::cout << std::endl;
    }
}

CaLamViec DSCaLamViec::timKiemCaLamViec(const std::string &maCa)
{
    for (const auto &caLamViec : danhSachCaLamViec)
    {
        if (caLamViec.getMaCa() == maCa)
        {
            return caLamViec;
        }
    }
    // Tr? v? m?t ca l�m vi?c r?ng n?u kh�ng t�m th?y
    return CaLamViec();
}

CaLamViec *DSCaLamViec::timKiemTheoMa(const string &maCa)
{
    for (auto &ca : danhSachCaLamViec)
    {
        if (ca.getMaCa() == maCa)
        {
            return &ca;
        }
    }
    return nullptr;
}

void DSCaLamViec::docDuLieuTuFile(const std::string &tenFile)
{
    std::ifstream file(tenFile);
    if (!file.is_open())
    {
        std::cout << "Khong mo duoc file " << tenFile << " de doc" << std::endl;
        return;
    }
    std::string maCa, tenCa, gioBatDau, gioKetThuc;
    double luong;
    std::string line;
    while (getline(file, line))
    {
        std::stringstream ss(line);
        getline(ss, maCa, ',');
        getline(ss, tenCa, ',');
        getline(ss, gioBatDau, ',');
        getline(ss, gioKetThuc, ',');
        ss >> luong;
        CaLamViec caLamViec(maCa, tenCa, gioBatDau, gioKetThuc, luong);
        themCaLamViec(caLamViec);
    }
    file.close();
}

void DSCaLamViec::ghiDuLieuVaoFile(const std::string &tenFile)
{
    std::ofstream file(tenFile);
    if (!file.is_open())
    {
        std::cout << "Khong mo duoc file " << tenFile << " de ghi" << std::endl;
        return;
    }

    for (const auto &caLamViec : danhSachCaLamViec)
    {
        caLamViec.luuVaoFile(tenFile);
        ;
    }
    file.close();
}
