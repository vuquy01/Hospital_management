#pragma once
#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
/*Lớp cơ sỏ trìu tượng*/
class Person
{
protected:
	/*khoi thong tin co ban*/
	string IDPerson;
	string CCCD_CMND;      // Số căn cước công dân/chứng minh nhân dân
	string Name;
	string date;/*viet ham tinh tuoi*/
	int age;
	string GioiTinh; /*gioi han gioi tinh lai xong ktra*/
	string DiaChi;
	string SDT; /*Hàm ktra*/
	string mail; /*Hàm ktra*/
public:
	/*khoi ham khoi tao*/
	Person();
	Person(string cccd, string n, string d, int tuoi, string sex, string diachii, string sdt, string m);

	/*khối các phương thức thuần ảo*/
	virtual void Input();
	virtual void Display();
	virtual void hienThiThongTinCoBan() const;
	virtual string taoID();

	/*khối hàm lấy dữ liệu an toàn(const để không thay đổi đối tượng)*/
	string layName() const;
	string layDate() const;
	int layAge() const;
	string laySdt() const;
	string layDiachi() const;
	string layMail() const;
	string layCCCD_CMND() const;
	string layDiaChi() const;

	/*khối hàm gán giá trị*/
	void ganMail(string m);
	void ganTen(string ten);
	void ganSDT(string sdt);
	void ganDate(string d);
	void ganGioiTinh(string sex);
	void ganCCCD_CMND(string cccd);
	void ganDiaChi(string adress);

	/*khoi ham tinh gia tri*/
	int tinhTuoi() const;              // Tính tuổi từ ngày sinh

	/*khối hàm ktra*/
	bool kiemTraSDTHopLe() const;     // Kiểm tra định dạng số điện thoại
	bool kiemTraTuoiHopLe() const;    // Kiểm tra tuổi hợp lý (1-150)
	bool kiemTraEmailHopLe() const;    // Kiểm tra định dạng email
	bool kiemTraNgaySinhHopLe() const; // Kiểm tra ngày sinh hợp lệ
	bool kiemTraGioiTinhHopLe() const; // Kiểm tra giới tính (Nam/Nu)
	bool kiemTraCCCDHopLe() const;
	bool kiemTraDinhDangNgaySinh(string ngay) const;
	bool ktra(char c) const;

	/*khối hàm thao tác với file*/
	void luuVaoFile(ofstream& file) const;    // Lưu vào file
	void docTuFile(ifstream& file);           // Đọc từ file
};

