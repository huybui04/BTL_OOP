#include "DSChiTietLuong.h"
#include "ChiTietLuong.h"
#include "DSCaLamViec.h"

vector<ChiTietLuong> DSChiTietLuong::getDSChiTietLuong() const { return DSChiTietLuong; }

void DSChiTietLuong::themChiTietLuong(const ChiTietLuong &ChiTietLuong)
{
    DSChiTietLuong.push_back(ChiTietLuong);
}

// sua chi tiet luong cua 1 nv theo ma nv va ma ca
void DSChiTietLuong::suaChiTietLuong(const string &MaNV, const string &MaCa)
{
    for (auto &ctl : DSChiTietLuong)
    {
        if (ctl.getMaNV() == MaNV && ctl.getMaCa() == MaCa)
        {
            cout << "Nhap thong tin moi cho chi tiet luong cua nhan vien " << MaNV << " ca " << MaCa << ":" << endl;
            ChiTietLuong newCTL;
            newCTL.nhap();
            ctl = newCTL;

            cout << "Thong tin chi tiet luong cua nhan vien " << MaNV << " ca " << MaCa << " sau khi sua la: " << endl;
            ctl.xuat();
            break;
        }
    }
}

void DSChiTietLuong::xoaChiTietLuongTheoMa(const string &MaNV, const string &MaCa)
{
    for (auto it = DSChiTietLuong.begin(); it != DSChiTietLuong.end(); it++)
    {
        bool deleted = false;
        if (it->getMaNV() == MaNV && it->getMaCa() == MaCa)
        {
            DSChiTietLuong.erase(it);
            deleted = true;
        }
        if (deleted)
        {
            cout << "Xoa thanh cong chi tiet luong cua nhan vien " << MaNV << " ca " << MaCa << endl;
            break;
        }
        else
            cout << "Khong tim thay chi tiet luong cua nhan vien " << MaNV << " ca " << MaCa << endl;
    }
}

void DSChiTietLuong::xoaChiTietLuong(const ChiTietLuong &ctl)
{
    auto new_end = remove(DSChiTietLuong.begin(), DSChiTietLuong.end(), ctl);
    DSChiTietLuong.erase(new_end, DSChiTietLuong.end());
}

void DSChiTietLuong::hienThiDanhSach() const
{
    for (const auto &ctl : DSChiTietLuong)
    {
        ctl.xuat();
        cout << endl;
    }
}

ChiTietLuong *DSChiTietLuong::timChiTietLuongTheoMa(const string &MaNV, const string &MaCa)
{
    for (auto &ctl : DSChiTietLuong)
    {
        if (ctl.getMaNV() == MaNV && ctl.getMaCa() == MaCa)
        {
            return &ctl;
        }
    }
    return nullptr;
}

double DSChiTietLuong::tinhLuongTheoMaNVVaThang(const string &MaNV, const int &thangLamViec) const
{
    double tongLuong = 0;
    for (auto &ctl : DSChiTietLuong)
    {
        if (ctl.getMaNV() == MaNV && ctl.getThangLamViec() == thangLamViec)
        {
            tongLuong += ctl.tinhLuong();
        }
    }
    return tongLuong;
}

void DSChiTietLuong::hienThiDanhSachLuongTheoThang() const
{

    map<int, vector<ChiTietLuong>> countCTL;
    for (auto &ctl : DSChiTietLuong)
    {
        countCTL[ctl.getThangLamViec()].push_back(ctl); // them chi tiet luong vao vector cua thang do
    }
    for (auto &thang : countCTL)
    {
        cout << "Thang " << thang.first << ":" << endl;
        for (auto &ctl : thang.second)
        {
            ctl.xuat();
            cout << endl;
        }
    }
}

void DSChiTietLuong::tinhLuongTungThangCuaMoiNhanVien() const
{
    // double tongLuong = 0;
    map<int, vector<ChiTietLuong>> mapCTL;
    for (auto &ctl : DSChiTietLuong)
    {
        mapCTL[ctl.getThangLamViec()].push_back(ctl);
    }
    for (auto &ctl : mapCTL)
    {
        cout << "Thang " << ctl.first << ":" << endl;
        for (auto &ct : ctl.second)
        {
            cout << "Nhan vien " << ct.getMaNV() << " co tong luong trong thang = " << ct.tinhLuong() << " VND" << endl;
        }
    }
}

void DSChiTietLuong::docDuLieuTuFile(const string &tenFile)
{
    ifstream fileIn(tenFile);
    if (!fileIn.is_open())
    {
        cout << "Khong mo duoc file " << tenFile << " de doc" << endl;
        return;
    }
    string line;
    while (getline(fileIn, line))
    {
        stringstream ss(line);
        string MaNV, MaCa;
        int tongSoCa, thangLamViec;

        getline(ss, MaNV, ',');
        getline(ss, MaCa, ',');
        ss >> tongSoCa;
        ss.ignore();
        ss >> thangLamViec;
        ChiTietLuong ctl(MaNV, MaCa, tongSoCa, thangLamViec);
        // themChiTietLuong(ctl);
        DSChiTietLuong.push_back(ctl);
    }
    fileIn.close();
}

void DSChiTietLuong::ghiDuLieuVaoFile(const string &tenFile)
{
    ofstream fileOut(tenFile, ios_base::app);
    if (!fileOut.is_open())
    {
        cout << "Khong mo duoc file " << tenFile << " de ghi" << endl;
        return;
    }
    for (auto &ctl : DSChiTietLuong)
    {
        ctl.luuDuLieuVaoFile(tenFile);
    }
}