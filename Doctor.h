#pragma once
#include"Employee.h"
#include"Schedule.h"
#include"Person.h"
class Doctor :public Person, Employee
{
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

	/*khoi ham gan gia tri*/
	void ganMaSoThue(const string& ma);
	void ganMaBacSi(const string& id);
	void ganChuyenKhoa(const string& khoa);

	/*khoi ham lay gia tri*/
	string layMaSoThue() const;
	string layMaBacSi() const;
	string layChuyenKhoa() const;

	/*khoi ham quan ly benh nhan*/
	void themBenhNhanDieuTri(const string& maBN, const string& chanDoan);
	void xoaBenhNhanDieuTri(const string& maBN);
	void capNhatTinhTrangBenhNhan(const string& maBN, const string& tinhTrang);
	void timKiemBenhNhan(const string& maBN) const;

	/*khoi ham quan ly lich lam viec*/
	void themLichLamViec(const string& ngay, const string& ca);
	void huyLichLamViec(const string& ngay);
	bool kiemTraLichTrong(const string& ngay, const string& ca) const;
	void huyLichTaiKham(int index);
	void danhDauDaTaiKham(int index);
	void themLichHen(const string& maLichHen, const string& ngay, const string& gio);
	bool kiemTraLichTrung(const string& ngay, const string& gio) const;
	void hienThiLichLamViec() const;

	/*khoi ham thong ke va bcao*/
	float tinhDoanhThuThang(int thang, int nam) const;//thong ke
	void thongKeBenhNhanTheoKhoa() const;
	void inBaoCaoThang() const; //bc
	void inDanhSachBenhNhan() const;
};
