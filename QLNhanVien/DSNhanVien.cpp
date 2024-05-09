#include "DSNhanVien.h"
#include <sstream>
#include <algorithm>

using namespace std;

std::vector<NhanVien> DSNhanVien::getDSNV() const
{
    return danhSachNhanVien;
}

void DSNhanVien::themNhanVien(const NhanVien &nv)
{
    danhSachNhanVien.push_back(nv);
}

void DSNhanVien::docDuLieuTuFile(const std::string &tenTep)
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
        std::string maNV, tenNV, sdt, gioiTinh, diaChi, chucVu, ngaySinh, cccd;

        std::getline(ss, cccd, ',');
        std::getline(ss, tenNV, ',');
        std::getline(ss, sdt, ',');
        std::getline(ss, diaChi, ',');
        std::getline(ss, gioiTinh, ',');
        std::getline(ss, ngaySinh, ',');
        std::getline(ss, maNV, ',');
        std::getline(ss, chucVu);

        NhanVien nv(cccd, tenNV, sdt, diaChi, gioiTinh, ngaySinh, maNV, chucVu);
        danhSachNhanVien.push_back(nv);
    }

    file.close();
}

void DSNhanVien::hienThiDanhSach() const
{
    cout << "\n\n\tDanh sach nhan vien\n\n";
    for (const auto &nv : danhSachNhanVien)
    {
        nv.xuat();
        std::cout << std::endl;
    }
}

void DSNhanVien::suaNhanVien(const std::string &maNV, const NhanVien &nv)
{
    bool timThay = false;
    for (auto &nhanVien : danhSachNhanVien)
    {
        if (nhanVien.getMaNV() == maNV)
        {
            nhanVien = nv;
            timThay = true;
            cout << "Thong tin nhan vien co maNV: " << maNV << " da duoc cap nhat" << endl;
            break;
        }
    }

    if (!timThay)
    {
        std::cout << "Khong tim thay nhan vien co MaNV: " << maNV << std::endl;
    }
}

void DSNhanVien::xoaNhanVien(const std::string &maNV)
{
    auto it = find_if(danhSachNhanVien.begin(), danhSachNhanVien.end(), [&maNV](const NhanVien &nv)
                      { return nv.getMaNV() == maNV; });

    if (it != danhSachNhanVien.end())
    {
        danhSachNhanVien.erase(it);
        std::cout << "Da xoa nhan vien co MaNV: " << maNV << std::endl;
    }
    else
    {
        std::cout << "Khong tim thay nhan vien co MaNV: " << maNV << std::endl;
    }
}

NhanVien DSNhanVien::timKiemNhanVien(const std::string &maNV) const
{
    for (const auto &nv : danhSachNhanVien)
    {
        if (nv.getMaNV() == maNV)
        {
            return nv;
        }
    }
    return NhanVien();
}

void DSNhanVien::luuVaoFile(const std::string &tenTep) const
{
    std::ofstream file(tenTep, std::ios_base::app);
    if (!file.is_open())
    {
        std::cout << "Khong mo duoc file " << tenTep << "de ghi" << std::endl;
        return;
    }

    for (const auto &nv : danhSachNhanVien)
    {
        nv.luuVaoFile(tenTep);
    }

    file.close();
}
// tim kiem nhan vien tra ve dia chi cua nhan vien tim duoc/ so sanh vowi nullptr
NhanVien *DSNhanVien::timKiemTheoMa(const string &maNV)
{
    for (auto &nv : danhSachNhanVien)
    {
        if (nv.getMaNV() == maNV)
        {
            return &nv;
        }
    }
    return nullptr;
}
