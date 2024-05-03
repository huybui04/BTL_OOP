#include "NguyenLieu.h"

NguyenLieu::NguyenLieu() : DoiTuong() {}

NguyenLieu::NguyenLieu(const std::string &MaNL, const std::string &TenNL, const std::string &NSX, const std::string &HSD, double Gia)
    : DoiTuong(MaNL, TenNL), NSX(NSX), HSD(HSD), Gia(Gia) {}
    
std::string NguyenLieu::getMaNL() const
{
    return DoiTuong::getMa();
}

void NguyenLieu::setMaNL(const std::string &maNL)
{
    DoiTuong::setMa(maNL);
}

std::string NguyenLieu::getTenNL() const
{
    return DoiTuong::getTen();
}

void NguyenLieu::setTenNL(const std::string &tenNL)
{
    DoiTuong::setTen(tenNL);
}

std::string NguyenLieu::getNSX() const
{
    return NSX;
}

void NguyenLieu::setNSX(const std::string &nsx)
{
    NSX = nsx;
}

std::string NguyenLieu::getHSD() const
{
    return HSD;
}

void NguyenLieu::setHSD(const std::string &hsd)
{
    HSD = hsd;
}

double NguyenLieu::getGia() const
{
    return Gia;
}

void NguyenLieu::setGia(double gia)
{
    Gia = gia;
}

void NguyenLieu::nhap()
{
    DoiTuong::nhap();
    std::cout << "Nhap NSX: ";
    std::getline(std::cin, NSX);
    std::cout << "Nhap HSD: ";
    std::getline(std::cin, HSD);
    std::cout << "Nhap Gia: ";
    std::cin >> Gia;
    std::cin.ignore();
}

void NguyenLieu::xuat() const
{
    DoiTuong::xuat();
    std::cout << "NSX: " << NSX << std::endl;
    std::cout << "HSD: " << HSD << std::endl;
    std::cout << "Gia: " << Gia << " VND" << std::endl;
}

void NguyenLieu::luuVaoFile(const std::string &tenFile) const
{
	std::ofstream file(tenFile, std::ios_base::app);
    if (!file.is_open()) {
        std::cout << "Khong mo duoc file " << tenFile << "de ghi" << std::endl;
        return;
    }

    file << getMa() << ", " << getTen() << ", " << NSX << ", " << HSD << ", " << Gia << std::endl;
    file.close();
    
}
