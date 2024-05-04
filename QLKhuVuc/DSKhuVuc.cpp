#include "DSKhuVuc.h"
#include <sstream>

std::vector<KhuVuc> DSKhuVuc::getDSKV() const
{
    return danhSachKhuVuc;
}

void DSKhuVuc::themKhuVuc(const KhuVuc &khuVuc)
{
    danhSachKhuVuc.push_back(khuVuc);
}

void DSKhuVuc::xoaKhuVuc(const std::string &maKV)
{
    for (auto it = danhSachKhuVuc.begin(); it != danhSachKhuVuc.end(); ++it)
    {
        if (it->getMaKV() == maKV)
        {
            danhSachKhuVuc.erase(it);
            break;
        }
    }
}

void DSKhuVuc::suaKhuVuc(const std::string &maKV, const KhuVuc &kv)
{
    for (auto &khuVuc : danhSachKhuVuc)
    {
        if (khuVuc.getMaKV() == maKV)
        {
            khuVuc = kv;
            break;
        }
    }
}

void DSKhuVuc::hienThiDanhSach() const
{
    std::cout << "\n\n\tDanh sach khu vuc\n\n";
    for (const auto &kv : danhSachKhuVuc)
    {
        kv.xuat();
        std::cout << std::endl;
    }
}

KhuVuc *DSKhuVuc::timKiemTheoMa(const std::string &maKV)
{
    for (auto &kv : danhSachKhuVuc)
    {
        if (kv.getMaKV() == maKV)
        {
            return &kv;
        }
    }
    return nullptr;
}

void DSKhuVuc::docDuLieuTuFile(const std::string &tenTep)
{
    std::ifstream file(tenTep);

    if (!file.is_open())
    {
        std::cout << "Khong mo duoc file " << tenTep << " de doc!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string maKV, tenKV;

        std::getline(ss, maKV, ',');
        std::getline(ss, tenKV, ',');

        KhuVuc kv(maKV, tenKV);
        danhSachKhuVuc.push_back(kv);
    }

    file.close();
}

void DSKhuVuc::luuVaoFile(const std::string &tenTep) const
{
    std::ofstream file(tenTep);
    if (!file.is_open())
    {
        std::cout << "Khong mo duoc file " << tenTep << " de ghi" << std::endl;
        return;
    }

    for (const auto &kv : danhSachKhuVuc)
    {
        kv.luuVaoFile(tenTep);
    }

    file.close();
}
