#include "DSChiTietLuong.h"
#include "ChiTietLuong.h"

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

void DSChiTietLuong::xoaChiTietLuong(const string &MaNV, const string &MaCa)
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

void DSChiTietLuong::docDuLieuTuFile(const string &tenFile)
{
    ifstream fileIn(tenFile);
    if (!fileIn.is_open())
    {
        cout << "Khong mo duoc file " << tenFile << " de doc" << endl;
        return;
    }
    while (!fileIn.eof())
    {
        string MaNV, MaCa;
        int tongSoCa, thangLamViec;
        fileIn >> MaNV >> MaCa >> tongSoCa >> thangLamViec;
        ChiTietLuong ctl(MaNV, MaCa, tongSoCa, thangLamViec);
        themChiTietLuong(ctl);
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