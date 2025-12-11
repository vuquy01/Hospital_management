#pragma once
#include"Person.h"
class Patient :public Person
{
	/*Khối 1 thuộc tính riêng của bệnh nhân*/
	string ngaynhapvien;/*ktra ngày*/
	string maSoBHYT;            // Mã số BHYT
	string ngayHetHanBHYT;      // Ngày hết hạn BHYT

	/*khoi du lieu suc khoe*/
	string nhomMau;        // Nhóm máu
	float chieuCao;        // Chiều cao (cm)
	float canNang;        // Cân nặng (kg)
public:
	/*khoi ham khoi tao*/
	Patient();

	/*khối hàm cơ bản*/
	void Input();
	void Display();
	void hienThiThongTinCoBan() const;
	string taoID();

	/*khoi ham gan gia tri*/
	void ganBHYT(string bhyt);
	void ganhsdBYHT(string hsd);
	void ganDateNhapVien(string date);
	void ganChisoSucKhoeMau(string Mau);
	void ganChisoSucKhoeCao(float h);
	void ganChisoSucKhoeNang(float w);

	/*khoi ham lay gia tri*/
	string layBHYT() const;
	string layhsdBYHT() const;
	string layDateNhapVien() const;
	string layChisoSucKhoeMau() const;
	float layChisoSucKhoeCao() const;
	float layChisoSucKhoeNang() const;

	/*khoi ham ktra*/
	bool kiemTraNhomMau() const;
	bool kiemTraCanNang() const;
	bool kiemTraChieuCao() const;
	bool kiemTraBHYTHopLe() const;
	bool kiemTraNgayNhapVienHopLe(string ngay) const;
};

