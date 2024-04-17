#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream> 
#include "HoaDonNhap.cpp"
#include "NguyenLieu.cpp"

using namespace std;

class ChiTietHoaDonNhap {
private:
    HoaDonNhap HDN;
    NguyenLieu NL;
    int SoLuongNhap;

public:
    ChiTietHoaDonNhap() {}
    ChiTietHoaDonNhap(HoaDonNhap HDN, NguyenLieu NL, int SoLuongNhap)
        : HDN(HDN), NL(NL), SoLuongNhap(SoLuongNhap) {}

    HoaDonNhap getHDN() {
        return HDN;
    }
    void setHDN(HoaDonNhap hdn) {
        this->HDN = hdn;
    }
    NguyenLieu getNL() {
        return NL;
    }
    void setNL(NguyenLieu nl) {
        this->NL = nl;
    }
    int getSoLuongNhap() {
        return SoLuongNhap;
    }
    void setSoLuongNhap(int soluong) {
        this->SoLuongNhap = soluong;
    }

    double tinhThanhTien() {
        return SoLuongNhap * NL.getGia();
    }
};

class DSChiTietHoaDonNhap {
private:
    vector<ChiTietHoaDonNhap> danhSachChiTietHoaDonNhap;

public:
    vector<ChiTietHoaDonNhap> getCTHDN() {
        return danhSachChiTietHoaDonNhap;
    }

    void themChiTiet(ChiTietHoaDonNhap chiTiet) {
        danhSachChiTietHoaDonNhap.push_back(chiTiet);
    }

    void suaChiTiet(HoaDonNhap hdn, ChiTietHoaDonNhap chiTietMoi) {
        for (auto &chiTiet : danhSachChiTietHoaDonNhap) {
            if (chiTiet.getHDN().getMaHDN() == hdn.getMaHDN()) {
                chiTiet = chiTietMoi;
                break;
            }
        }
    }

    void xoaChiTiet(HoaDonNhap hdn) {
        for (auto it = danhSachChiTietHoaDonNhap.begin(); it != danhSachChiTietHoaDonNhap.end(); ++it) {
            if (it->getHDN().getMaHDN() == hdn.getMaHDN()) {
                danhSachChiTietHoaDonNhap.erase(it);
                break;
            }
        }
    }

    ChiTietHoaDonNhap timKiemChiTiet(HoaDonNhap hdn) {
        for (auto chiTiet : danhSachChiTietHoaDonNhap) {
            if (chiTiet.getHDN().getMaHDN() == hdn.getMaHDN()) {
                return chiTiet;
            }
        }
        return ChiTietHoaDonNhap();
    }

    void ghiDuLieuVaoFile(string tenFile) {
        ofstream file(tenFile);
        if (file.is_open()) {
            for (auto chiTiet : danhSachChiTietHoaDonNhap) {
                file << chiTiet.getHDN().getMaHDN() << " " << chiTiet.getNL().getMaNL() << " " << chiTiet.getSoLuongNhap() << endl;
            }
            file.close();
        } else {
            cout << "Khong mo duoc file!" << endl;
        }
    }
};

