#include "HoaDonNhap.h"

HoaDonNhap::HoaDonNhap() : HoaDon() {}

HoaDonNhap::HoaDonNhap(const std::string &maHDN, const std::string &ngayNhap, const std::string &maNV, const std::string &maNCC)
    : HoaDon(maHDN, ngayNhap), MaNV(maNV), MaNCC(maNCC)
{
}

HoaDonNhap::HoaDonNhap(const std::string &maHDN, const std::string &ngayNhap, const std::string &maNV, const std::string &maNCC, const std::vector<ChiTietHoaDonNhap> &dscthdn)
    : HoaDon(maHDN, ngayNhap), MaNV(maNV), MaNCC(maNCC)
{
    for (auto ct : dscthdn)
    {
        if (ct.getMaHDN() == this->getMaHDN())
            dsCTHDN.push_back(ct);
    }
}

void HoaDonNhap::setMaHDN(std::string maHDN)
{
    HoaDon::setMa(maHDN);
}

std::string HoaDonNhap::getMaHDN() const
{
    return HoaDon::getMa();
}

void HoaDonNhap::setNgayNhap(std::string ngayNhap)
{
    HoaDon::setNgay(ngayNhap);
}

std::string HoaDonNhap::getNgayNhap() const
{
    return HoaDon::getNgay();
}

void HoaDonNhap::setMaNV(const std::string &maNV)
{
    MaNV = maNV;
}

std::string HoaDonNhap::getMaNV() const
{
    return MaNV;
}

void HoaDonNhap::setMaNCC(const std::string &maNCC)
{
    MaNCC = maNCC;
}

std::string HoaDonNhap::getMaNCC() const
{
    return MaNCC;
}

void HoaDonNhap::setDsCTHDN(const std::vector<ChiTietHoaDonNhap> &ds)
{
    dsCTHDN = ds;
}

std::vector<ChiTietHoaDonNhap> HoaDonNhap::getDsCTHDN() const
{
    return dsCTHDN;
}

void HoaDonNhap::xuat() const
{
    HoaDon::xuat();
    std::cout << "Ma NV: " << MaNV << std::endl;
    std::cout << "Ma NCC " << MaNCC << std::endl;
}

void HoaDonNhap::themChiTietHoaDon(const ChiTietHoaDonNhap &chiTiet)
{
    dsCTHDN.push_back(chiTiet);
}

void HoaDonNhap::luuVaoFile(const std::string &tenFile) const
{
    std::ofstream file(tenFile, std::ios_base::app);
    if (!file.is_open())
    {
        std::cout << "Khong mo duoc file " << tenFile << "de ghi" << std::endl;
        return;
    }

    file << HoaDon::getMa() << "," << HoaDon::getNgay() << "," << MaNV << "," << MaNCC << std::endl;
    file.close();
}

double HoaDonNhap::tinhTongTien() const
{
    double tongTien = 0.0;

    DSNguyenLieu dsnl;
    dsnl.docDuLieuTuFile("QLNguyenLieu/nguyenlieu.txt");

    DSChiTietHoaDonNhap dscthdn;
    dscthdn.docDuLieuTuFile("QLChiTietHoaDonNhap/chitiethoadonnhap.txt");

    for (auto nl : dsnl.getDSNL())
    {
        for (auto ct : dscthdn.getDSCTHDN())
        {
            if (trim_(nl.getMaNL()) == trim_(ct.getMaNL()))
            {
                ct.setNL(nl);
            }
            if (ct.getMaHDN() == this->getMaHDN())
                tongTien += ct.tinhThanhTien();
        }
    }
    return tongTien;
}

void HoaDonNhap::hienThi() const
{
    HoaDon::xuat();
    std::cout << "Ma Nhan Vien: " << MaNV << std::endl;
    std::cout << "Ma Nha Cung Cap: " << MaNCC << std::endl;
    std::cout << "Danh Sach Chi Tiet Hoa Don Nhap:" << std::endl;
    for (auto ct : dsCTHDN)
    {
        if (ct.getMaHDN() == this->getMaHDN())
            std::cout << "   + " << ct.getMaHDN() << " - So Luong: " << ct.getSoLuongNhap() << " - Thanh Tien: " << ct.tinhThanhTien() << std::endl;
    }
    std::cout << "Tong Tien: " << tinhTongTien() << " VND" << std::endl;
}
