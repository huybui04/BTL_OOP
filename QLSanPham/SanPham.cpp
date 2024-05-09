#include "SanPham.h"
#include "../QLDanhMucSanPham/DanhMucSanPham.h"

SanPham::SanPham() : DoiTuong() {}

SanPham::SanPham(const string &MaSP, const string &TenSP, double Gia, const string &MaDanhMuc) : DoiTuong(MaSP, TenSP), Gia(Gia), MaDanhMuc(MaDanhMuc) {}

string SanPham::getMaSP() const
{
    return DoiTuong::getMa();
}

void SanPham::setMaSP(const string &maSP)
{
    DoiTuong::setMa(maSP);
}

string SanPham::getTenSP() const
{
    return DoiTuong::getTen();
}

void SanPham::setTenSP(const string &tenSP)
{
    DoiTuong::setTen(tenSP);
}

double SanPham::getGia() const
{
    return Gia;
}

void SanPham::setGia(double gia)
{
    Gia = gia;
}

string SanPham::getMaDanhMuc() const
{
    return MaDanhMuc;
}

void SanPham::setMaDanhMuc(const string &maDanhMuc)
{
    MaDanhMuc = maDanhMuc;
}

void SanPham::nhap()
{
    DoiTuong::nhap();
    cout << "Nhap gia: ";
    cin >> Gia;
    cin.ignore();
    cout << "Nhap ma danh muc: ";
    getline(cin, MaDanhMuc);
}

void SanPham::xuat() const
{
    DoiTuong::xuat();
    cout << "Gia: " << Gia << " VND" << endl;
    cout << "Ma danh muc: " << MaDanhMuc << endl;
}

void SanPham::luuVaoFile(const string &tenFile) const
{
    ofstream file(tenFile, ios_base::app);
    if (!file.is_open())
    {
        cout << "Khong mo duoc file " << tenFile << "de ghi" << endl;
        return;
    }

    file << getMa() << "," << getTen() << "," << Gia << "," << MaDanhMuc << endl;
    file.close();
}
