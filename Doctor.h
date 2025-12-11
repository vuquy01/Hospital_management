#pragma once
#include"Employee.h"
#include"Person.h"
class Doctor :public Person, Employee
{
	static const int BENH_NHAN_TOI_DA = 10;
	/*Khối 1 thuộc tính chuyên môn*/
	string chungChiHanhNghe;      // Số chứng chỉ hành nghề
	string Chuyenkhoa;
	int namexp;
public:
	/*khoi ham khoi tao*/
	Doctor();
	/*khối hàm cơ bản*/
	void Input();
	void Display();
	void hienThiThongTinCoBan() const;
	string taoID();

	/*khoi ham gan gia tri*/
	void ganChuyenKhoa(const string& khoa);

	/*khoi ham lay gia tri*/
	string layChuyenKhoa() const;

	/*khoi ham thong ke va bcao*/
	float tinhDoanhThuThang(int thang, int nam) const;//thong ke
	void thongKeBenhNhanTheoKhoa() const;
	void inBaoCaoThang() const; //bc
	void inDanhSachBenhNhan() const;
};
