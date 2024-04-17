#include "NhanVien.h"

NhanVien::NhanVien() {}

NhanVien::NhanVien(std::string MaNV, std::string TenNV, std::string SDT, std::string GioiTinh, std::string DiaChi, std::string ChucVu, std::string NgaySinh)
    : MaNV(MaNV), TenNV(TenNV), SDT(SDT), GioiTinh(GioiTinh), DiaChi(DiaChi), ChucVu(ChucVu), NgaySinh(NgaySinh) {}

std::string NhanVien::getMaNV() const {
    return MaNV;
}

void NhanVien::setMaNV(std::string maNV) {
    MaNV = maNV;
}

std::string NhanVien::getTenNV() const {
    return TenNV;
}

void NhanVien::setTenNV(std::string tenNV) {
    TenNV = tenNV;
}

std::string NhanVien::getSDT() const {
    return SDT;
}

void NhanVien::setSDT(std::string sdt) {
    SDT = sdt;
}

std::string NhanVien::getGioiTinh() const {
    return GioiTinh;
}

void NhanVien::setGioiTinh(std::string gioiTinh) {
    GioiTinh = gioiTinh;
}

std::string NhanVien::getDiaChi() const {
    return DiaChi;
}

void NhanVien::setDiaChi(std::string diaChi) {
    DiaChi = diaChi;
}

std::string NhanVien::getChucVu() const {
    return ChucVu;
}

void NhanVien::setChucVu(std::string chucVu) {
    ChucVu = chucVu;
}

std::string NhanVien::getNgaySinh() const {
    return NgaySinh;
}

void NhanVien::setNgaySinh(std::string ngaySinh) {
    NgaySinh = ngaySinh;
}

void NhanVien::nhap() {
    std::cout << "Nhap Ma NV: ";
    std::getline(std::cin, MaNV);
    std::cout << "Nhap Ten NV: ";
    std::getline(std::cin, TenNV);
    std::cout << "Nhap SDT: ";
    std::getline(std::cin, SDT);
    std::cout << "Nhap Gioi Tinh: ";
    std::getline(std::cin, GioiTinh);
    std::cout << "Nhap Dia Chi: ";
    std::getline(std::cin, DiaChi);
    std::cout << "Nhap Chuc Vu: ";
    std::getline(std::cin, ChucVu);
    std::cout << "Nhap Ngay Sinh: ";
    std::getline(std::cin, NgaySinh);
}

void NhanVien::xuat() const {
    std::cout << "Ma NV: " << MaNV << std::endl;
    std::cout << "Ten NV: " << TenNV << std::endl;
    std::cout << "SDT: " << SDT << std::endl;
    std::cout << "Gioi Tinh: " << GioiTinh << std::endl;
    std::cout << "Dia Chi: " << DiaChi << std::endl;
    std::cout << "Chuc Vu: " << ChucVu << std::endl;
    std::cout << "Ngay Sinh: " << NgaySinh << std::endl;
}

void NhanVien::luuVaoFile(std::ofstream &file) const {
    file << MaNV << "," << TenNV << "," << SDT << "," << GioiTinh << "," << DiaChi << "," << ChucVu << "," << NgaySinh << std::endl;
}

