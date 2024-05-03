#include "NhanVien.h"

NhanVien::NhanVien() : Nguoi() {}

NhanVien::NhanVien(std::string MaNV, std::string TenNV, std::string SDT, std::string GioiTinh, std::string DiaChi, std::string ChucVu, std::string NgaySinh)
    : Nguoi(MaNV, TenNV, SDT), GioiTinh(GioiTinh), DiaChi(DiaChi), ChucVu(ChucVu), NgaySinh(NgaySinh) {}

std::string NhanVien::getMaNV() const
{
    return Nguoi::getMa();
}

void NhanVien::setMaNV(std::string maNV)
{
    Nguoi::setMa(maNV);
}

std::string NhanVien::getTenNV() const
{
    return Nguoi::getTen();
}

void NhanVien::setTenNV(std::string tenNV)
{
    Nguoi::setTen(tenNV);
}

std::string NhanVien::getSDT() const
{
    return Nguoi::getSDT();
}

void NhanVien::setSDT(std::string sdt)
{
    Nguoi::setSDT(sdt);
}

std::string NhanVien::getGioiTinh() const
{
    return GioiTinh;
}

void NhanVien::setGioiTinh(std::string gioiTinh)
{
    GioiTinh = gioiTinh;
}

std::string NhanVien::getDiaChi() const
{
    return DiaChi;
}

void NhanVien::setDiaChi(std::string diaChi)
{
    DiaChi = diaChi;
}

std::string NhanVien::getChucVu() const
{
    return ChucVu;
}

void NhanVien::setChucVu(std::string chucVu)
{
    ChucVu = chucVu;
}

std::string NhanVien::getNgaySinh() const
{
    return NgaySinh;
}

void NhanVien::setNgaySinh(std::string ngaySinh)
{
    NgaySinh = ngaySinh;
}

void NhanVien::nhap()
{
    Nguoi::nhap();
    std::cout << "Nhap Gioi Tinh: ";
    std::getline(std::cin, GioiTinh);
    std::cout << "Nhap Dia Chi: ";
    std::getline(std::cin, DiaChi);
    std::cout << "Nhap Chuc Vu: ";
    std::getline(std::cin, ChucVu);
    std::cout << "Nhap Ngay Sinh: ";
    std::getline(std::cin, NgaySinh);
}

void NhanVien::xuat() const
{
    Nguoi::xuat();
    std::cout << "Gioi Tinh: " << GioiTinh << std::endl;
    std::cout << "Dia Chi: " << DiaChi << std::endl;
    std::cout << "Chuc Vu: " << ChucVu << std::endl;
    std::cout << "Ngay Sinh: " << NgaySinh << std::endl;
}

void NhanVien::luuVaoFile(const std::string &tenFile) const
{
    std::ofstream file(tenFile, std::ios_base::app);
    if (!file.is_open())
    {
        std::cout << "Khong mo duoc file " << tenFile << "de ghi" << std::endl;
        return;
    }

    file << Nguoi::getMa() << ", " << Nguoi::getTen() << ", " << Nguoi::getSDT() << ", " << GioiTinh << ", " << DiaChi << ", " << ChucVu << ", " << NgaySinh << std::endl;
    file.close();
}
