#include "DSChiTietSanPham.h"
#include <fstream>
#include <sstream>

std::vector<ChiTietSanPham> DSChiTietSanPham::getDSCTSP() const
{
    return danhSachChiTietSanPham;
}

void DSChiTietSanPham::themChiTiet(const ChiTietSanPham &chiTiet)
{
    danhSachChiTietSanPham.push_back(chiTiet);
}

void DSChiTietSanPham::suaChiTiet(const std::string &MaNL, const std::string &MaSP, const ChiTietSanPham &chiTietMoi)
{
    for (auto &chiTiet : danhSachChiTietSanPham)
    {
        if (chiTiet.getMaNL() == MaNL && chiTiet.getMaSP() == MaSP)
        {
            chiTiet = chiTietMoi;
            break;
        }
    }
}

void DSChiTietSanPham::xoaChiTiet(const std::string &MaNL, const std::string &MaSP)
{
    for (auto it = danhSachChiTietSanPham.begin(); it != danhSachChiTietSanPham.end(); ++it)
    {
        if (it->getMaNL() == MaNL && it->getMaSP() == MaSP)
        {
            danhSachChiTietSanPham.erase(it);
            break;
        }
    }
}

ChiTietSanPham DSChiTietSanPham::timKiemChiTiet(const std::string &MaNL, const std::string &MaSP)
{
    for (auto chiTiet : danhSachChiTietSanPham)
    {
        if (chiTiet.getMaNL() == MaNL && chiTiet.getMaSP() == MaSP)
        {
            return chiTiet;
        }
    }
    return ChiTietSanPham();
}

void DSChiTietSanPham::hienThiDanhSach() const
{
    std::cout << "\n\n\tDanh sach chi tiet san pham\n\n";
    for (const auto &ctsp : danhSachChiTietSanPham)
    {
        ctsp.xuat();
        std::cout << std::endl;
    }
}

void DSChiTietSanPham::docDuLieuTuFile(const std::string &tenFile)
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
        std::string maNL, maSP, soLuong;

        std::getline(ss, maNL, ',');
        std::getline(ss, maSP, ',');
        std::getline(ss, soLuong);
        int SL = std::stoi(soLuong);

        ChiTietSanPham ctsp(maNL, maSP, SL);
        themChiTiet(ctsp);
    }

    file.close();
}

void DSChiTietSanPham::ghiDuLieuVaoFile(const std::string &tenFile)
{
    std::ofstream file(tenFile, std::ios_base::app);
    if (file.is_open())
    {
        for (auto ctsp : danhSachChiTietSanPham)
        {
            file << ctsp.getMaNL() << "," << ctsp.getMaSP() << "," << ctsp.getSoLuongSuDung() << std::endl;
        }
        file.close();
    }
    else
    {
        std::cout << "Khong mo duoc file " << tenFile << "de ghi" << std::endl;
    }
}

ChiTietSanPham *DSChiTietSanPham::timKiemChiTietTheoMa(const std::string &MaNL, const std::string &MaSP)
{
    for (auto &chiTiet : danhSachChiTietSanPham)
    {
        if (chiTiet.getMaNL() == MaNL && chiTiet.getMaSP() == MaSP)
        {
            return &chiTiet;
        }
    }
    return nullptr;
}
