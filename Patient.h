#pragma once
#include"Person.h"
#include"Schedule.h"
class Patient :public Person
{
	/*Khối 1 thuộc tính riêng của bệnh nhân*/
	string ChuanDoan;
	string ngaynhapvien;/*ktra ngày*/
	string maSoBHYT;            // Mã số BHYT
	string ngayHetHanBHYT;      // Ngày hết hạn BHYT

	/*khoi du lieu suc khoe*/
	string nhomMau;        // Nhóm máu
	float chieuCao;        // Chiều cao (cm)
	float canNang;        // Cân nặng (kg)

	/*khối 4 thông tin khác*/
	string trangThaiDieuTri;    // "DangDieuTri", "XuatVien", "ChuyenVien"
	string ngayXuatVien;        // Ngày xuất viện
	string lyDoXuatVien;        // Lý do xuất viện
public:
	/*khoi ham khoi tao*/
	Patient();
	/*khối hàm cơ bản*/
	void Input();
	void Display();
	void hienThiThongTinCoBan() const;

	/*khoi ham gan gia tri*/
	void ganMaBenhNhan(const string& id);
	void ganChuanDoan(const string& cd);
	void ganBHYT(const string& bhyt);

	/*khoi ham lay gia tri*/
	string layMaBenhNhan() const;
	string layChuanDoan() const;
	string layBHYT() const;

	/*khoi ham ktra*/
	bool kiemTraBHYTHopLe() const;
	bool kiemTraNgayNhapVienHopLe() const;
};

