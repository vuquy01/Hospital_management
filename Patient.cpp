#include "Patient.h"
/*khoi ham khoi tao*/
Patient::Patient() :Person()
{
    ngaynhapvien = "";
    maSoBHYT = "";
    ngayHetHanBHYT = "";
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
    do {
        cout << "Nhap so BHYT: ";
        cin >> maSoBHYT;
        if (!kiemTraBHYTHopLe())
            cout << "\nSo BHYT khong hop le.";
    } while (!kiemTraBHYTHopLe());
    do {
        cout << "\nNhap ngay het han bao hiem y te(dd/mm/yyyy): ";
        cin >> ngayHetHanBHYT;
        if (!kiemTraDinhDangNgaySinh(ngayHetHanBHYT))
            cout << "\nNgay nhap vien khong hop le.";
    } while (!kiemTraDinhDangNgaySinh(ngayHetHanBHYT));
    cout << "\nNhap vao cac chi so suc khoe: ";
    cout << "\nChieu cao: ";
    cin >> chieuCao;
    cout << "\nCan nang: ";
    cin >> canNang;
    cout << "\nNhom mau(A,B,AB,O): ";
    cin >> nhomMau;
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
void Patient::ganBHYT(string bhyt)
{
    maSoBHYT = bhyt;
}
void Patient::ganhsdBYHT(string hsd)
{

}
void Patient::ganDateNhapVien(string date)
{

}
void Patient::ganChisoSucKhoeMau(string Mau)
{

}
void Patient::ganChisoSucKhoeCao(float h)
{

}
void Patient::ganChisoSucKhoeNang(float w)
{

}

/*khoi ham lay gia tri*/
string Patient::layBHYT() const
{
    return maSoBHYT;
}
string Patient::layhsdBYHT() const
{

}
string Patient::layDateNhapVien() const
{

}
string Patient::layChisoSucKhoeMau() const
{

}
float Patient::layChisoSucKhoeCao() const
{

}
float Patient::layChisoSucKhoeNang() const
{

}

/*khoi ham kiem tra*/
bool Patient::kiemTraBHYTHopLe() const
{
    size_t a = maSoBHYT.length();
    if ( a != 12 )
        return 0;
    else
        return 1;
    for (int i = 0; i < maSoBHYT.length(); i++)
    {
        if (!ktra(maSoBHYT[i]))
            return 0;
    }
}
bool Patient::kiemTraNgayNhapVienHopLe(string ngay) const
{
    Person::kiemTraDinhDangNgaySinh(ngay);
}
bool Patient::kiemTraNhomMau() const
{

}
bool Patient::kiemTraCanNang() const
{

}
bool Patient::kiemTraChieuCao() const
{

}
