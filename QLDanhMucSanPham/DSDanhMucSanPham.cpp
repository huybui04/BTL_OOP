#include "DSDanhMucSanPham.h"
#include <sstream>

vector<DanhMucSanPham> DSDanhMucSanPham::getDSDM() const
{
    return danhSachDanhMuc;
}

void DSDanhMucSanPham::themDanhMuc(const DanhMucSanPham &danhMucSanPham)
{
    danhSachDanhMuc.push_back(danhMucSanPham);
}

void DSDanhMucSanPham::xoaDanhMuc(const string &maDM)
{
    for (auto it = danhSachDanhMuc.begin(); it != danhSachDanhMuc.end(); ++it)
    {
        if (it->getMaDM() == maDM)
        {
            danhSachDanhMuc.erase(it);
            break;
        }
    }
}

void DSDanhMucSanPham::suaDanhMuc(const string &maDM, const DanhMucSanPham &dm)
{
    for (auto &danhmuc : danhSachDanhMuc)
    {
        if (danhmuc.getMaDM() == maDM)
        {
            danhmuc = dm;
            break;
        }
    }
}

void DSDanhMucSanPham::hienThiDanhSach()
{
    cout << "\n\n\tDanh sach danh muc san pham\n\n";
    getData();
    for (auto &m : mapSanPham)
    {
        cout << "\n\tDanh muc " << m.first << ":\n\n";
        for (auto &sp : m.second)
        {
            sp.xuat();
            cout << endl;
        }
    }
}

void DSDanhMucSanPham::getData()
{
    DSSanPham dssp;
    dssp.docDuLieuTuFile("QLSanPham/sanpham.txt");

    for (auto &dm : danhSachDanhMuc)
    {
        for (auto &sp : dssp.getDSSP())
        {
            if (sp.getMaDanhMuc() == dm.getMaDM())
            {
                mapSanPham[dm.getMaDM()].push_back(sp);
            }
        }
    }
}

DanhMucSanPham *DSDanhMucSanPham::timKiemTheoMa(const string &maDM)
{
    for (auto &dm : danhSachDanhMuc)
    {
        if (dm.getMaDM() == maDM)
        {
            return &dm;
        }
    }
    return nullptr;
}

void DSDanhMucSanPham::docDuLieuTuFile(const string &tenTep)
{
    ifstream file(tenTep);

    if (!file.is_open())
    {
        cout << "Khong mo duoc file " << tenTep << " de doc!" << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string maDM, tenDM;

        getline(ss, maDM, ',');
        getline(ss, tenDM, ',');

        DanhMucSanPham dm(maDM, tenDM);
        danhSachDanhMuc.push_back(dm);
    }

    file.close();
}

void DSDanhMucSanPham::luuVaoFile(const string &tenTep) const
{
    ofstream file(tenTep);
    if (!file.is_open())
    {
        cout << "Khong mo duoc file " << tenTep << "de ghi" << endl;
        return;
    }

    for (const auto &dm : danhSachDanhMuc)
    {
        dm.luuVaoFile(tenTep);
    }

    file.close();
}
