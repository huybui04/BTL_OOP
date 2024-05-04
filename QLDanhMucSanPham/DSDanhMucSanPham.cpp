#include "DSDanhMucSanPham.h"
#include <sstream>

std::vector<DanhMucSanPham> DSDanhMucSanPham::getDSDM() const
{
    return danhSachDanhMuc;
}

void DSDanhMucSanPham::themDanhMuc(const DanhMucSanPham &danhMucSanPham)
{
    danhSachDanhMuc.push_back(danhMucSanPham);
}

void DSDanhMucSanPham::xoaDanhMuc(const std::string &maDM)
{
    for (auto it = danhSachDanhMuc.begin(); it != danhSachDanhMuc.end(); ++it)
    {
        if (it->getMaDM() == maDM)
        {
            danhSachDanhMuc.erase(it);
            break;
        }
    }
}

void DSDanhMucSanPham::suaDanhMuc(const std::string &maDM, const DanhMucSanPham &dm)
{
    for (auto &danhmuc : danhSachDanhMuc)
    {
        if (danhmuc.getMaDM() == maDM)
        {
            danhmuc = dm;
            break;
        }
    }
}

void DSDanhMucSanPham::hienThiDanhSach() const
{
    std::cout << "\n\n\tDanh sach danh muc san pham\n\n";
    for (const auto &dm : danhSachDanhMuc)
    {
        dm.xuat();
        std::cout << std::endl;
    }
}

DanhMucSanPham *DSDanhMucSanPham::timKiemTheoMa(const std::string &maDM)
{
    for (auto &dm : danhSachDanhMuc)
    {
        if (dm.getMaDM() == maDM)
        {
            return &dm;
        }
    }
    return nullptr;
}

void DSDanhMucSanPham::docDuLieuTuFile(const std::string &tenTep)
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
        std::string maDM, tenDM;

        std::getline(ss, maDM, ',');
        std::getline(ss, tenDM, ',');

        DanhMucSanPham dm(maDM, tenDM);
        danhSachDanhMuc.push_back(dm);
    }

    file.close();
}

void DSDanhMucSanPham::luuVaoFile(const std::string &tenTep) const
{
    std::ofstream file(tenTep);
    if (!file.is_open())
    {
        std::cout << "Khong mo duoc file " << tenTep << "de ghi" << std::endl;
        return;
    }

    for (const auto &dm : danhSachDanhMuc)
    {
        dm.luuVaoFile(tenTep);
    }

    file.close();
}
