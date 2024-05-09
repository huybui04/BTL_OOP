#include "DSSanPham.h"
#include <iostream>
#include <fstream>
#include <sstream>

vector<SanPham> DSSanPham::getDSSP() const
{
    return danhSachSanPham;
}

void DSSanPham::themSanPham(SanPham &sp)
{
    danhSachSanPham.push_back(sp);
}

void DSSanPham::docDuLieuTuFile(const string &tenTep)
{
    ifstream file(tenTep);

    if (!file.is_open())
    {
        cout << "Khong mo duoc file " << tenTep << " de doc!" << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string maSP, tenSP;
        double gia;
        string maDanhMuc;

        getline(ss, maSP, ',');
        getline(ss, tenSP, ',');
        ss >> gia;
        ss.ignore();
        getline(ss, maDanhMuc, ' ');

        SanPham sp(maSP, tenSP, gia, maDanhMuc);
        danhSachSanPham.push_back(sp);
    }

    file.close();
}

void DSSanPham::hienThiDanhSach() const
{
    cout << "\n\n\tDanh sach san pham\n\n";
    for (const auto &sp : danhSachSanPham)
    {
        sp.xuat();
        cout << endl;
    }
}

void DSSanPham::suaSanPham(const string &maSP, const SanPham &sp)
{
    bool timThay = false;
    for (auto &sanpham : danhSachSanPham)
    {
        if (sanpham.getMaSP() == maSP)
        {
            sanpham = sp;
            timThay = true;
            break;
        }
    }

    if (!timThay)
    {
        cerr << "Khong tim thay san pham co MaSP: " << maSP << endl;
    }
}

void DSSanPham::xoaSanPham(const string &maSP)
{
    auto it = find_if(danhSachSanPham.begin(), danhSachSanPham.end(),
                      [maSP](const SanPham &sp)
                      { return sp.getMaSP() == maSP; });

    if (it != danhSachSanPham.end())
    {
        danhSachSanPham.erase(it);
        cout << "Da xoa san pham co MaSP: " << maSP << endl;
    }
    else
    {
        cerr << "Khong tim thay san pham co MaSP: " << maSP << endl;
    }
}

void DSSanPham::luuVaoFile(const string &tenTep) const
{
    ofstream file(tenTep, ios_base::app);
    if (!file.is_open())
    {
        cout << "Khong mo duoc file " << tenTep << "de ghi" << endl;
        return;
    }

    for (const auto &sp : danhSachSanPham)
    {
        sp.luuVaoFile(tenTep);
    }

    file.close();
}

SanPham *DSSanPham::timKiemSanPham(const string &maSP)
{
    for (auto &sp : danhSachSanPham)
    {
        if (sp.getMaSP() == maSP)
        {
            return &sp;
        }
    }
    return nullptr;
}

void DSSanPham::capNhatFile(const string &tenFile)
{
    ofstream file(tenFile);
    if (!file.is_open())
    {
        cout << "Khong mo duoc file " << tenFile << "de ghi" << endl;
        return;
    }
    for (const auto &sp : danhSachSanPham)
    {
        sp.luuVaoFile(tenFile);
    }
    file.close();
}