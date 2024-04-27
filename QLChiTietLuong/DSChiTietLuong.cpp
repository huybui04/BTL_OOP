#include "DSChiTietLuong.h"

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

void DSChiTietLuong::hienThiDanhSach() const
{
    cout << "\n\n\tDanh sach chi tiet luong\n\n";
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
    cout << "\n\n\tDanh sach chi tiet luong theo thang\n\n";
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

    map<int, vector<ChiTietLuong>> mapCTL;
    map<string, double> mapLuong;
    // chia cac chi tiet luong theo thang
    for (auto &ctl : DSChiTietLuong)
    {
        mapCTL[ctl.getThangLamViec()].push_back(ctl);
    }
    // tinh tong luong cua moi nhan vien trong thang
    for (auto &ctl : mapCTL)
    {
        for (auto &ct : ctl.second)
        {
            mapLuong[ct.getMaNV()] += ct.tinhLuong();
        }
    }
    // in ra tong luong cua moi nhan vien rieng biet trong thang
    cout << "\n\n\tThong ke luong cua tung nhan vien theo thang\n\n";
    for (auto &ctl : mapCTL)
    {
        cout << "Thang " << ctl.first << ":" << endl;
        set<string> maUnique;
        for (auto &ct : ctl.second)
        {
            if (maUnique.find(ct.getMaNV()) == maUnique.end())
            {
                cout << "Ma nhan vien: " << ct.getMaNV() << " tong luong: " << mapLuong[ct.getMaNV()] << " VND\n\n";
                maUnique.insert(ct.getMaNV());
            }
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
        DSCaLamViec dsCaLamViec;
        dsCaLamViec.docDuLieuTuFile("QLCaLamViec/calamviec.txt");

        stringstream ss(line);
        string MaNV, MaCa;
        int tongSoCa, thangLamViec;

        getline(ss, MaNV, ',');
        getline(ss, MaCa, ',');
        ss >> tongSoCa;
        ss.ignore();
        ss >> thangLamViec;
        ChiTietLuong ctl(MaNV, MaCa, tongSoCa, thangLamViec);
        for (auto &ca : dsCaLamViec.getDSCaLamViec())
        {
            if (ca.getMaCa() == MaCa)
            {
                ctl.setCa(ca);
            }
        }
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
