#include "NhanVien.h"

NhanVien::NhanVien() : Nguoi() {}

NhanVien::NhanVien(std::string CCCD, std::string TenNV, std::string SDT, std::string DiaChi, std::string GioiTinh, std::string NgaySinh, std::string MaNV, std::string ChucVu)
    : Nguoi(CCCD, TenNV, SDT, DiaChi, GioiTinh, NgaySinh), MaNV(MaNV), ChucVu(ChucVu) {}

std::string NhanVien::getCCCD() const
{
    return Nguoi::getCCCD();
}

void NhanVien::setCCCD(std::string cccd)
{
    Nguoi::setCCCD(cccd);
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
    return Nguoi::getGioiTinh();
}

void NhanVien::setGioiTinh(std::string gioiTinh)
{
    Nguoi::setGioiTinh(gioiTinh);
}

std::string NhanVien::getDiaChi() const
{
    return Nguoi::getDiaChi();
}

void NhanVien::setDiaChi(std::string diaChi)
{
    Nguoi::setDiaChi(diaChi);
}

std::string NhanVien::getNgaySinh() const
{
    return Nguoi::getNgaySinh();
}

void NhanVien::setNgaySinh(std::string ngaySinh)
{
    Nguoi::setNgaySinh(ngaySinh);
}

std::string NhanVien::getMaNV() const
{
    return MaNV;
}

void NhanVien::setMaNV(std::string maNV)
{
    MaNV = maNV;
}

std::string NhanVien::getChucVu() const
{
    return ChucVu;
}

void NhanVien::setChucVu(std::string chucVu)
{
    ChucVu = chucVu;
}

void NhanVien::nhap()
{
    Nguoi::nhap();
    std::cout << "Nhap MaNV: ";
    std::getline(std::cin, MaNV);
    std::cout << "Nhap Chuc Vu: ";
    std::getline(std::cin, ChucVu);
}

void NhanVien::xuat() const
{
    Nguoi::xuat();
    std::cout << "MaNV: " << MaNV << std::endl;
    std::cout << "Chuc Vu: " << ChucVu << std::endl;
}

void NhanVien::luuVaoFile(const std::string &tenFile) const {
	std::ofstream file(tenFile, std::ios_base::app);
    if (!file.is_open())
    {
        std::cout << "Khong mo duoc file " << tenFile << " de ghi" << std::endl;
        return;
    }

    file << Nguoi::getCCCD() << "," << Nguoi::getTen() << "," << Nguoi::getSDT() << "," << Nguoi::getDiaChi() << "," << Nguoi::getGioiTinh() << "," << Nguoi::getNgaySinh() << "," << MaNV << "," << ChucVu << std::endl;
    file.close();
}
