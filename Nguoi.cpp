#include "Nguoi.h"

Nguoi::Nguoi() {}

Nguoi::Nguoi(const std::string &cccd, const std::string &ten, const std::string &sdt, const std::string &diachi, const std::string &gioitinh, const std::string &ngaysinh)
    : CCCD(cccd), Ten(ten), SDT(sdt), DiaChi(diachi), GioiTinh(gioitinh), NgaySinh(ngaysinh) {}
 
std::string Nguoi::getCCCD() const {
	return CCCD;
}
    
void Nguoi::setCCCD(const std::string &cccd) {
	CCCD = cccd;
}

std::string Nguoi::getTen() const {
	return Ten;
}

void Nguoi::setTen(const std::string &ten) {
	Ten = ten;
}
    
std::string Nguoi::getSDT() const {
    return SDT;
}

void Nguoi::setSDT(const std::string &sdt) {
    SDT = sdt;
}
 
std::string Nguoi::getDiaChi() const {
	return DiaChi;
}
    
void Nguoi::setDiaChi(const std::string &diachi) {
	DiaChi = diachi;
}   
    
std::string Nguoi::getGioiTinh()  const {
	return GioiTinh;
}   

void Nguoi::setGioiTinh(const std::string &gioitinh) {
	GioiTinh = gioitinh;
} 

std::string Nguoi::getNgaySinh() const {
	return NgaySinh;
}

void Nguoi::setNgaySinh(const std::string &ngaysinh) {
	NgaySinh = ngaysinh;
}
    
void Nguoi::nhap() {
    std::cout << "Nhap CCCD: ";
    std::getline(std::cin, CCCD);
    std::cout << "Nhap Ten: ";
    std::getline(std::cin, Ten);
    std::cout << "Nhap SDT: ";
    std::getline(std::cin, SDT);
    std::cout << "Nhap Dia Chi: ";
    std::getline(std::cin, DiaChi);
    std::cout << "Nhap Gioi tinh: ";
    std::getline(std::cin, GioiTinh);
    std::cout << "Nhap Ngay sinh: ";
    std::getline(std::cin, NgaySinh);
}

void Nguoi::xuat() const {
    std::cout << "CCCD: " << CCCD << std::endl;
    std::cout << "Ten: " << Ten << std::endl;
    std::cout << "SDT: " << SDT << std::endl;
    std::cout << "Dia Chi: " << DiaChi << std::endl;
    std::cout << "Gioi Tinh: " << GioiTinh << std::endl;
    std::cout << "Ngay Sinh: " << NgaySinh << std::endl;
}

void Nguoi::luuVaoFile(const std::string &tenFile) const {
    std::ofstream file(tenFile, std::ios_base::app);
    if (!file.is_open()) {
        std::cout << "Khong mo duoc file " << tenFile << " de ghi" << std::endl;
        return;
    }

    file << CCCD << "," << Ten << "," << SDT << "," << DiaChi << "," << GioiTinh << "," << NgaySinh << std::endl;
    file.close();   
}



