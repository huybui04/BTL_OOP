#include "KhuVuc.h"

KhuVuc::KhuVuc() {}

KhuVuc::KhuVuc(const std::string &MaKV, const std::string &TenKV) : DoiTuong(MaKV, TenKV) 
{
	DSBan dsb;
	dsb.docDuLieuTuFile("QLBan/ban.txt");
	
	for (const auto &ban : dsb.getDSBan())
    {
        if (ban.getMaKV() == MaKV)
        {
            banTheoKhuVuc.push_back(ban);
        }
    }	
}

std::string KhuVuc::getMaKV() const {
    return DoiTuong::getMa();
}

void KhuVuc::setMaKV(const std::string &MaKV) {
    DoiTuong::setMa(MaKV);
}


std::string KhuVuc::getTenKV() const {
    return DoiTuong::getTen();
}

void KhuVuc::setTenKV(const std::string &TenKV) {
    DoiTuong::setTen(TenKV);
}

void KhuVuc::nhap() {
    DoiTuong::nhap();
}

void KhuVuc::xuat() const {
    DoiTuong::xuat();
    cout << "\n\tDanh sach ban thuoc khu vuc " << getTenKV() << endl;
    for (const auto &ban : banTheoKhuVuc)
    {
        ban.xuat();
        cout << endl;
    }
}

void KhuVuc::luuVaoFile(const std::string &tenTep) const {
    DoiTuong::luuVaoFile(tenTep);
}
