#include "DanhMucSanPham.h"

DanhMucSanPham::DanhMucSanPham() : DoiTuong() {}

DanhMucSanPham::DanhMucSanPham(const std::string &MaDM, const std::string &TenDM)
    : DoiTuong(MaDM, TenDM) {}
		
std::string DanhMucSanPham::getMaDM() const {
	return DoiTuong::getMa();
}

void DanhMucSanPham::setMaDM(const std::string &maDM) {
	DoiTuong::setMa(maDM);
}

std::string DanhMucSanPham::getTenDM() const {
    return DoiTuong::getTen();
}

void DanhMucSanPham::setTenDM(const std::string &tenDM) {
    DoiTuong::setTen(tenDM);
}

void DanhMucSanPham::nhap() {
    DoiTuong::nhap();
}

void DanhMucSanPham::xuat() const {
    DoiTuong::xuat();
}

void DanhMucSanPham::luuVaoFile(const std::string &tenTep) const {
    DoiTuong::luuVaoFile(tenTep);
}

