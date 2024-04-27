#include "ChiTietLuong.h"

#include <fstream>

ChiTietLuong::ChiTietLuong() {}

ChiTietLuong::ChiTietLuong(const string &MaNV, const string &MaCa, const int &tongSoCa, const int &thangLamViec) : MaNV(MaNV), MaCa(MaCa), tongSoCa(tongSoCa), thangLamViec(thangLamViec) {}

ChiTietLuong::ChiTietLuong(const string &MaNV, const string &MaCa, const int &tongSoCa, const int &thangLamViec, const CaLamViec &ca) : MaNV(MaNV), MaCa(MaCa), tongSoCa(tongSoCa), thangLamViec(thangLamViec), ca(ca) {}

string ChiTietLuong::getMaNV() const { return MaNV; }
string ChiTietLuong::getMaCa() const { return MaCa; }
int ChiTietLuong::getTongSoCa() const { return tongSoCa; }
int ChiTietLuong::getThangLamViec() const { return thangLamViec; }
CaLamViec ChiTietLuong::getCa() const { return ca; }

void ChiTietLuong::setMaNV(const string &MaNV) { this->MaNV = MaNV; }
void ChiTietLuong::setMaCa(const string &MaCa) { this->MaCa = MaCa; }
void ChiTietLuong::setTongSoCa(const int &tongSoCa) { this->tongSoCa = tongSoCa; }
void ChiTietLuong::setThangLamViec(const int &thangLamViec) { this->thangLamViec = thangLamViec; }
void ChiTietLuong::setCa(const CaLamViec &ca) { this->ca = ca; }

double ChiTietLuong::tinhLuong() const
{
    return ca.getLuong() * getTongSoCa();
}

void ChiTietLuong::nhap()
{
    cout << "Nhap ma nhan vien: ";
    cin >> MaNV;
    cout << "Nhap ma ca: ";
    cin >> MaCa;
    cout << "Nhap tong so ca: ";
    cin >> tongSoCa;
    cout << "Nhap thang lam viec: ";
    cin >> thangLamViec;
    // ca.nhap();
}

void ChiTietLuong::xuat() const
{
    cout << "Ma nhan vien: " << MaNV << endl;
    cout << "Ma ca: " << MaCa << endl;
    cout << "Tong so ca: " << tongSoCa << endl;
    cout << "Thang lam viec: " << thangLamViec << endl;
    // ca.xuat();
}
void ChiTietLuong::luuDuLieuVaoFile(const string &tenFile)
{
    ofstream file(tenFile, ios_base::app);
    if (!file.is_open())
    {
        std::cout << "Khong mo duoc file " << tenFile << " de ghi" << std::endl;
        return;
    }

    file << MaNV << ", " << MaCa << ", " << tongSoCa << ", " << thangLamViec << endl;
    file.close();
}
