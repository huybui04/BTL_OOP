#include "ChiTietLuong.h"

#include <fstream>

ChiTietLuong::ChiTietLuong() : ChiTietDoiTuong() {}

ChiTietLuong::ChiTietLuong(const string &MaNV, const string &MaCa, const int &tongSoCa, const int &thangLamViec)
    : ChiTietDoiTuong(MaNV, MaCa), tongSoCa(tongSoCa), thangLamViec(thangLamViec) {}

ChiTietLuong::ChiTietLuong(const string &MaNV, const string &MaCa, const int &tongSoCa, const int &thangLamViec, const CaLamViec &ca)
    : ChiTietDoiTuong(MaNV, MaCa), tongSoCa(tongSoCa), thangLamViec(thangLamViec), ca(ca) {}

string ChiTietLuong::getMaNV() const { return ChiTietDoiTuong::getMa1(); }
string ChiTietLuong::getMaCa() const { return ChiTietDoiTuong::getMa2(); }
int ChiTietLuong::getTongSoCa() const { return tongSoCa; }
int ChiTietLuong::getThangLamViec() const { return thangLamViec; }
CaLamViec ChiTietLuong::getCa() const { return ca; }

void ChiTietLuong::setMaNV(const string &MaNV) { ChiTietDoiTuong::setMa1(MaNV); }
void ChiTietLuong::setMaCa(const string &MaCa) { ChiTietDoiTuong::setMa2(MaCa); }
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
    string MaNV;
    cin >> MaNV;
    setMa1(MaNV);
    cout << "Nhap ma ca: ";
    string MaCa;
    cin >> MaCa;
    setMa2(MaCa);
    cout << "Nhap tong so ca: ";
    cin >> tongSoCa;
    cout << "Nhap thang lam viec: ";
    cin >> thangLamViec;
}

void ChiTietLuong::xuat() const
{
    cout << "Ma nhan vien: " << ChiTietDoiTuong::getMa1() << endl;
    cout << "Ma ca: " << ChiTietDoiTuong::getMa2() << endl;
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

    file << ChiTietDoiTuong::getMa1() << "," << ChiTietDoiTuong::getMa2() << "," << tongSoCa << "," << thangLamViec << endl;
    file.close();
}
