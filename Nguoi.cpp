#include "Nguoi.h"

Nguoi::Nguoi() : DoiTuong() {}

Nguoi::Nguoi(const std::string &ma, const std::string &ten, const std::string &sdt)
    : DoiTuong(ma, ten), SDT(sdt) {}
    
std::string Nguoi::getSDT() const {
    return SDT;
}

void Nguoi::setSDT(const std::string &sdt) {
    SDT = sdt;
}
    
void Nguoi::nhap() {
    DoiTuong::nhap(); 
    std::cout << "Nhap SDT: ";
    std::getline(std::cin, SDT);
}

void Nguoi::xuat() const {
    DoiTuong::xuat();
    std::cout << "SDT: " << SDT << std::endl;
}

void Nguoi::luuVaoFile(const std::string &tenFile) const {
    std::ofstream file(tenFile, std::ios_base::app);
    if (!file.is_open()) {
        std::cout << "Khong mo duoc file " << tenFile << " de ghi" << std::endl;
        return;
    }

    file << DoiTuong::getMa() << ", " << DoiTuong::getTen() << ", " << SDT << std::endl;
    file.close();   
}



