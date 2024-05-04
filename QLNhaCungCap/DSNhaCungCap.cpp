#include "DSNhaCungCap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

std::vector<NhaCungCap> DSNhaCungCap::getDSNCC() const
{
    return danhSachNhaCungCap;
}

void DSNhaCungCap::themNhaCungCap(const NhaCungCap &ncc)
{
    danhSachNhaCungCap.push_back(ncc);
}

void DSNhaCungCap::docDuLieuTuFile(const std::string &tenTep)
{
    std::ifstream file(tenTep);

    if (!file.is_open())
    {
        std::cout << "Khong mo duoc file " << tenTep << " de doc!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string maNCC, tenNCC, diaChi, sdt;

        std::getline(ss, maNCC, ',');
        std::getline(ss, tenNCC, ',');
        std::getline(ss, diaChi, ',');
        std::getline(ss, sdt);

        NhaCungCap ncc(maNCC, tenNCC, diaChi, sdt);
        themNhaCungCap(ncc);
    }

    file.close();
}

void DSNhaCungCap::hienThiDanhSach() const
{
    std::cout << "\n\n\t Danh sach nha cung cap\n\n";
    for (const auto &ncc : danhSachNhaCungCap)
    {
        std::cout << "MaNCC: " << ncc.getMaNCC() << std::endl;
        std::cout << "TenNCC: " << ncc.getTenNCC() << std::endl;
        std::cout << "DiaChi: " << ncc.getDiaChi() << std::endl;
        std::cout << "SDT: " << ncc.getSDT() << std::endl;
        std::cout << std::endl;
    }
}

void DSNhaCungCap::suaNhaCungCap(const std::string &maNCC, const NhaCungCap &ncc)
{
    bool timThay = false;
    for (auto &nhacungcap : danhSachNhaCungCap)
    {
        if (nhacungcap.getMaNCC() == maNCC)
        {
            nhacungcap = ncc;
            timThay = true;
            break;
        }
    }

    if (!timThay)
    {
        std::cerr << "Khong tim thay nha cung cap co MaNCC: " << maNCC << std::endl;
    }
}

void DSNhaCungCap::xoaNhaCungCap(const std::string &maNCC)
{
    auto it = find_if(danhSachNhaCungCap.begin(), danhSachNhaCungCap.end(),
                      [maNCC](const NhaCungCap &ncc)
                      { return ncc.getMaNCC() == maNCC; });

    if (it != danhSachNhaCungCap.end())
    {
        danhSachNhaCungCap.erase(it);
        std::cout << "Da xoa nha cung cap co MaNCC: " << maNCC << std::endl;
    }
    else
    {
        std::cerr << "Khong tim thay nha cung cap co MaNCC: " << maNCC << std::endl;
    }
}

void DSNhaCungCap::luuVaoFile(const std::string &tenTep) const
{
    std::ofstream file(tenTep, std::ios_base::app);
    if (!file.is_open())
    {
        std::cout << "Khong mo duoc file " << tenTep << "de ghi" << std::endl;
        return;
    }

    for (const auto &ncc : danhSachNhaCungCap)
    {
        ncc.luuVaoFile(tenTep);
    }

    file.close();
}

NhaCungCap *DSNhaCungCap::timKiemNhaCungCap(const std::string &maNCC)
{
    for (auto &ncc : danhSachNhaCungCap)
    {
        if (ncc.getMaNCC() == maNCC)
        {
            return &ncc;
        }
    }
    return nullptr;
}
