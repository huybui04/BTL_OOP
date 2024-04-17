#include<iostream>
#include<vector>
using namespace std;

class Ban {
	private:
		string MaBan, TenBan, TrangThai;
	public:
		Ban() {}
		Ban(string maBan, string tenBan, string trangThai)
        :MaBan(maBan), TenBan(tenBan), TrangThai(trangThai) {}
		string getMaBan()  {
	        return MaBan;
	    }
	    void setMaBan(string maBan) {
	        MaBan = maBan;
	    }
	    string getTenBan()  {
	        return TenBan;
	    }
	    void setTenBan( string tenBan) {
	        TenBan = tenBan;
	    }
	    string getTrangThai()  {
	        return TrangThai;
	    }
	    void setTrangThai(string trangThai) {
	        TrangThai = trangThai;
	    }
	    void nhap() {
	        cout << "Nhap Ma Ban: ";
	        getline(cin, MaBan);
	        cout << "Nhap Ten Ban: ";
	        getline(cin, TenBan);
	        cout << "Nhap Trang Thai: ";
	        getline(cin, TrangThai);
	    }
	    void xuat() {
	        cout << "Ma Ban: " << MaBan << endl;
	        cout << "Ten Ban: " << TenBan << endl;
	        cout << "Trang Thai: " << TrangThai << endl;
	    }
	    void luuVaoFile(ofstream file) {
	        file << MaBan << "," << TenBan << "," << TrangThai << endl;
	    }
};

class DSBan {
	private:
	    vector<Ban> danhSachBan;
	
	public:
		vector<Ban> getDSBan() {
			return danhSachBan;
		}
	    void themBan() {
	    	Ban ban;
	    	ban.nhap();
	        danhSachBan.push_back(ban);
	    }
	    
	    void docDuLieuTuFile(string tenTep) {
	        ifstream file(tenTep);
	
	        if (!file.is_open()) {
	            cout << "Khong mo duoc file" << endl;
	            return;
	        }
	
	        string line;
	        while (getline(file, line)) {
	            stringstream ss(line);
	            string maBan, tenBan, trangThai;
	
	            getline(ss, maBan, ',');
	            getline(ss, tenBan, ',');
	            getline(ss, trangThai);
	
	            Ban ban(maBan, tenBan, trangThai);
	            themBan(ban);
	        }
	
	        file.close();
	    }

	    void hienThiDanhSach()  {
	        for (auto ban : danhSachBan) {
	            cout << "Ma Ban: " << ban.getMaBan() << endl;
	            cout << "Ten Ban: " << ban.getTenBan() << endl;
	            cout << "Trang Thai: " << ban.getTrangThai() << endl;
	            cout << endl;
	        }
	    }
		
		void suaBan(string maBan, Ban ban) {
		    bool timThay = false;
		    for (auto& b : danhSachBan) {
		        if (b.getMaBan() == maBan) {
		            b = ban;
		            timThay = true;
		            break;
		        }
		    }
		
		    if (!timThay) {
		        cout << "Khong tim thay ban co Ma Ban: " << maBan << endl;
		    }
		}
		
		void xoaBan(string maBan) {
		    bool timThay = false;
		    for (auto it = danhSachBan.begin(); it != danhSachBan.end(); ++it) {
		        if (it->getMaBan() == maBan) {
		            danhSachBan.erase(it);
		            timThay = true;
		            cout << "Da xoa ban co Ma Ban: " << maBan << endl;
		            break;
		        }
		    }
		
		    if (!timThay) {
		        cout << "Khong tim thay ban co Ma Ban: " << maBan << endl;
		    }
		}
		
		void luuVaoFile(string tenTep) {
	        ofstream file(tenTep);
	        if (!file.is_open()) {
	            cout << "Khong mo duoc file" << endl;
	            return;
	        }
	
	        for (auto ban : danhSachBan) {
	            ban.luuVaoFile(file);
	        }
	
		    file.close();
		}
};

