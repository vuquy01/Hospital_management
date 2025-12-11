#include "Patient.h"
/*khoi ham khoi tao*/
Patient::Patient() :Person()
{
    ngaynhapvien = "";
    maSoBHYT = "";
    ngayHetHanBHYT = "";
    trangThaiDieuTri = "DangDieuTri";
    ngayXuatVien = "";
    lyDoXuatVien = "";
    nhomMau = "";       // Nhóm máu
    chieuCao = 0.0;   // Chiều cao (cm)
    canNang = 0.0;        // Cân nặng (kg)
}

/*khoi ham co ban(nhap xuat)*/
void Patient::Input()
{
    Person::Input();
    do {
        cout << "Nhap ngay nhap vien (dd/mm/yyyy): ";
        cin >> ngaynhapvien;
        if (!kiemTraNgayNhapVienHopLe(ngaynhapvien))
            cout << "\nNgay nhap vien khong hop le.";
    } while (!kiemTraNgayNhapVienHopLe(ngaynhapvien));
    cout << "Nhap so BHYT: ";
    cin >> maSoBHYT;
    do {
        cout << "\nNhap ngay het han bao hiem y te(dd/mm/yyyy): ";
        cin >> ngayHetHanBHYT;
        if (!kiemTraDinhDangNgaySinh(ngayHetHanBHYT))
            cout << "\nNgay nhap vien khong hop le.";
    } while (!kiemTraDinhDangNgaySinh(ngayHetHanBHYT));
}
void Patient::Display()
{
    Person::Display();
    cout << "Ngay nhap vien: " << ngaynhapvien << endl;
    cout << "BHYT: " << maSoBHYT << endl;
}
void Patient::hienThiThongTinCoBan() const
{

}

/*khoi ham gan gia tri*/
void Patient::ganBHYT(const string& bhyt)
{
    maSoBHYT = bhyt;
}

/*khoi ham lay gia tri*/
string Patient::layBHYT() const
{
    return maSoBHYT;
}

/*khoi ham kiem tra*/
bool Patient::kiemTraNgayNhapVienHopLe(string ngay) const
{
    Person::kiemTraDinhDangNgaySinh(ngay);
}
