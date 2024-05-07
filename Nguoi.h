#ifndef NGUOI_H
#define NGUOI_H

#include <iostream>
#include <fstream>

class Nguoi {
protected:
    std::string CCCD, Ten, SDT, DiaChi, GioiTinh, NgaySinh;
	
public:
    Nguoi();
    Nguoi(const std::string &cccd, const std::string &ten, const std::string &sdt, const std::string &diachi, const std::string &gioitinh, const std::string &ngaysinh);

	std::string getCCCD() const;
	void setCCCD(const std::string &cccd);
	std::string getTen() const;
	void setTen(const std::string &ten);
    std::string getSDT() const;
    void setSDT(const std::string &sdt);
	std::string getDiaChi() const;
	void setDiaChi(const std::string &diachi);
	std::string getGioiTinh() const;
	void setGioiTinh(const std::string &gioitinh);
	std::string getNgaySinh() const;
	void setNgaySinh(const std::string &ngaysinh);

    void nhap();
    void xuat() const;
    void luuVaoFile(const std::string &tenFile) const;
};

#endif /* DOITUONG_H */

