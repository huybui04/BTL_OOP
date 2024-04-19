#include "HoaDonNhap.h"

HoaDonNhap::HoaDonNhap() {}

HoaDonNhap::HoaDonNhap(const std::string &maHDN,const std::string &ngayNhap, const std::string &maNV, const std::string &maNCC)
    : MaHDN(maHDN), NgayNhap(ngayNhap), MaNV(maNV), MaNCC(maNCC) 
{
	
}

HoaDonNhap::HoaDonNhap(const std::string &maHDN,const std::string &ngayNhap, const std::string &maNV, const std::string &maNCC, const std::vector<ChiTietHoaDonNhap> &dscthdn)
    : MaHDN(maHDN), NgayNhap(ngayNhap), MaNV(maNV), MaNCC(maNCC) 
{
    for (auto ct : dscthdn)
    {
        if (ct.getMaHDN() == this->MaHDN)
            dsCTHDN.push_back(ct);
    }	
}


void HoaDonNhap::setMaHDN(std::string maHDN) {
    MaHDN = maHDN;
}

std::string HoaDonNhap::getMaHDN() const {
    return MaHDN;
}

void HoaDonNhap::setNgayNhap(std::string ngayNhap) {
    NgayNhap = ngayNhap;
}

std::string HoaDonNhap::getNgayNhap() const {
    return NgayNhap;
}

void HoaDonNhap::setMaNV(const std::string &maNV) {
    MaNV = maNV;
}

std::string HoaDonNhap::getMaNV() const {
    return MaNV;
}

void HoaDonNhap::setMaNCC(const std::string &maNCC) {
    MaNCC = maNCC;
}

std::string HoaDonNhap::getMaNCC() const {
    return MaNCC;
}

void HoaDonNhap::setDsCTHDN(const std::vector<ChiTietHoaDonNhap> &ds) {
    dsCTHDN = ds;
}

std::vector<ChiTietHoaDonNhap> HoaDonNhap::getDsCTHDN() const {
    return dsCTHDN;
}

void HoaDonNhap::xuat() const
{
    std::cout << "Ma HDN: " << MaHDN << std::endl;
    std::cout << "Ngay nhap: " << NgayNhap << std::endl;
    std::cout << "Ma NV: " << MaNV << std::endl;
    std::cout << "Ma NCC " << MaNCC << std::endl;
}

void HoaDonNhap::themChiTietHoaDon(const ChiTietHoaDonNhap &chiTiet) {
    dsCTHDN.push_back(chiTiet);
}

void HoaDonNhap::luuVaoFile(const std::string &tenFile) const {
	std::ofstream file(tenFile, std::ios_base::app);
    if (!file.is_open()) {
        std::cout << "Khong mo duoc file " << tenFile << "de ghi" << std::endl;
        return;
    }

    file << MaHDN << ", " << NgayNhap << ", " << MaNV << ", " << MaNCC  << std::endl;
    file.close();
}

double HoaDonNhap::tinhTongTien() const {
    double tongTien = 0.0;
    for (auto ct : dsCTHDN) 
	{
        if (ct.getMaHDN() == this->MaHDN)
            tongTien += ct.tinhThanhTien();
    }
    return tongTien;
}

void HoaDonNhap::hienThi() const {
    std::cout << "Ma Hoa Don: " << MaHDN << std::endl;
    std::cout << "Ngay Nhap: " << NgayNhap << std::endl;
    std::cout << "Ma Nhan Vien: " << MaNV << std::endl;
    std::cout << "Ma Nha Cung Cap: " << MaNCC << std::endl;
    std::cout << "Danh Sach Chi Tiet Hoa Don Nhap:" << std::endl;
    for (auto ct : dsCTHDN) {
        if (ct.getMaHDN() == this->MaHDN)
            std::cout << "   + " << ct.getMaHDN() << " - So Luong: " << ct.getSoLuongNhap() << " - Thanh Tien: " << ct.tinhThanhTien() << std::endl;
    }
    std::cout << "Tong Tien: " << tinhTongTien() << " VND" << std::endl;
}


