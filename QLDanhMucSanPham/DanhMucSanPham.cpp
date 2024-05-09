#include "DanhMucSanPham.h"

DanhMucSanPham::DanhMucSanPham() {}

DanhMucSanPham::DanhMucSanPham(const string &MaDM, const string &TenDM) : DoiTuong(MaDM, TenDM)
{
    DSSanPham dssp;
    dssp.docDuLieuTuFile("QLSanPham/sanpham.txt");

    for (const auto &sp : dssp.getDSSP())
    {
        if (sp.getMaDanhMuc() == MaDM)
        {
            spTheoDanhMuc.push_back(sp);
        }
    }
}

string DanhMucSanPham::getMaDM() const
{
    return DoiTuong::getMa();
}

void DanhMucSanPham::setMaDM(const string &maDM)
{
    DoiTuong::setMa(maDM);
}

string DanhMucSanPham::getTenDM() const
{
    return DoiTuong::getTen();
}

void DanhMucSanPham::setTenDM(const string &tenDM)
{
    DoiTuong::setTen(tenDM);
}

void DanhMucSanPham::nhap()
{
    DoiTuong::nhap();
}

void DanhMucSanPham::xuat() const
{
    DoiTuong::xuat();
    cout << "\n\tDanh sach san pham thuoc danh muc " << getTenDM() << endl;
    for (const auto &sp : spTheoDanhMuc)
    {
        sp.xuat();
        cout << endl;
    }
}

void DanhMucSanPham::luuVaoFile(const string &tenTep) const
{
    DoiTuong::luuVaoFile(tenTep);
}
