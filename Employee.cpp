#include "Employee.h"
/*khối hàm khởi tạo*/
Employee::Employee() : Person()
{
    TypeNV = "";
    trinhdo = "";
    Chucvu = "";
    PhongBan = "";
    firstdate = "";
    TypeHD = "";
    Heso = 0;
    Phucap = 0;
    status = "DangLamViec";
    soCaDaXep = 0;
    soLanVangMat = 0;
    Phepconlai = 12;  // 12 ngày phép/năm
}

/*khối hàm cơ bản*/
void Employee::Input()
{
    Person::Input();
    cout << "Nhap loai nhan vien (YTa/DieuDuong/LeTan/KeToan/BaoVe/LaoCong/KyThuatVien/ThuVien): ";
    cin >> TypeNV;
    cout << "Nhap chuc vu (TruongPhong/PhoPhong/NhanVien/ThucTap): ";
    cin >> Chucvu;
    cout << "Nhap phong ban (LeTan/TaiChinh/HanhChinh/KyThuat/VeSinh): ";
    cin >> PhongBan;
    cout << "Nhap ngay bat dau lam (dd/mm/yyyy): ";
    cin >> firstdate;
    cout << "Nhap loai hop dong (BienChe/HopDong/ThoiVu/ThucTap): ";
    cin >> TypeHD;
    cout << "Nhap he so luong: ";
    cin >> Heso;
    cout << "Nhap phu cap: ";
    cin >> Phucap;
    cout << "Nhap trang thai (DangLamViec/NghiPhep/NghiViec): ";
    cin >> status;
    soCaDaXep = 0;
    soLanVangMat = 0;
    Phepconlai = 0;
}
void Employee::Display()
{
    Person::Display();
    cout << "Ma nhan vien: " << IDPerson << endl;
    cout << "Loai nhan vien: " << TypeNV << endl;
    cout << "Chuc vu: " << Chucvu << endl;
    cout << "Phong ban: " << PhongBan << endl;
    cout << "Ngay bat dau lam: " << firstdate << endl;
    cout << "Loai hop dong: " << TypeHD << endl;
    cout << "Luong co ban: " << LUONGCOBAN << endl;
    cout << "He so luong: " << Heso << endl;
    cout << "Phu cap: " << Phucap << endl;
    cout << "Trang thai: " << status << endl;
}
void Employee::hienThiThongTinCoBan() const
{

}
