#include "DSKhachHang.h"
#include <bits/stdc++.h>
using namespace std;

void DSKhachHang::themKhachHang(const KhachHang &khachHang)
{
    danhSachKhachHang.push_back(khachHang);
}

void DSKhachHang::docTuFile(const std::string &tenFile)
{
    std::ifstream file(tenFile);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::stringstream ss(line);
            std::string maKH, cccd, tenKH, sdt, diachi, gioitinh, ngaysinh;
            std::getline(ss, cccd, ',');
            std::getline(ss, tenKH, ',');
            std::getline(ss, sdt, ',');
			std::getline(ss, diachi, ',');
			std::getline(ss, gioitinh, ',');	
			std::getline(ss, ngaysinh, ',');
			std::getline(ss, maKH);
			
            KhachHang kh(cccd, tenKH, sdt, diachi, gioitinh, ngaysinh, maKH);
            themKhachHang(kh);
        }
        file.close();
    }
    else
    {
        std::cout << "Khong mo duoc file " << tenFile << " de doc!" << std::endl;
    }
}

void DSKhachHang::hienThiDanhSach() const
{
    cout << "\n\n\tDanh sach khach hang\n\n";
    for (const auto &kh : danhSachKhachHang)
    {
        kh.xuat();
        std::cout << std::endl;
    }
}

void DSKhachHang::suaKhachHang(const std::string &maKH, const KhachHang &khachHang)
{
    bool timThay = false;
    for (auto &kh : danhSachKhachHang)
    {
        if (kh.getMaKH() == maKH)
        {
            kh = khachHang;
            timThay = true;
            break;
        }
    }

    if (!timThay)
    {
        std::cout << "Khong tim thay khach hang co MaKH: " << maKH << std::endl;
    }
}

void DSKhachHang::xoaKhachHang(const std::string &maKH)
{
    auto it = std::find_if(danhSachKhachHang.begin(), danhSachKhachHang.end(), [&maKH](const KhachHang &kh)
                           { return kh.getMaKH() == maKH; });

    if (it != danhSachKhachHang.end())
    {
        danhSachKhachHang.erase(it);
        std::cout << "Da xoa khach hang co MaKH: " << maKH << std::endl;
    }
    else
    {
        std::cout << "Khong tim thay khach hang co MaKH: " << maKH << std::endl;
    }
}

void DSKhachHang::luuVaoFile(const std::string &tenTep) const
{
    std::ofstream file(tenTep, std::ios_base::app);
    if (!file.is_open())
    {
        std::cout << "Khong mo duoc file " << tenTep << "de ghi" << std::endl;
        return;
    }

    for (const auto &kh : danhSachKhachHang)
    {
        kh.luuVaoFile(tenTep);
    }

    file.close();
}

std::vector<KhachHang> DSKhachHang::getDanhSachKhachHang() const
{
    return danhSachKhachHang;
}

KhachHang *DSKhachHang::timKiemTheoMa(const string &maKH)
{
    for (auto &kh : danhSachKhachHang)
    {
        if (kh.getMaKH() == maKH)
        {
            return &kh;
        }
    }
    return nullptr;
}
