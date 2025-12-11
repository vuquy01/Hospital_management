#include "Doctor.h"
/*khoi ham khoi tao*/
Doctor::Doctor() :Employee()
{
    chungChiHanhNghe = "";
    Chuyenkhoa = "";
    namexp = 0;
}

/*khoi ham co ban(nhap xuat)*/
void Doctor::Input()
{
    Employee::Input();
    cout << "Nhap chuyen khoa: ";
    cin.ignore();
    getline(cin, Chuyenkhoa);
    cout << "Nhap so nam kinh nghiem: ";
    cin >> namexp;
}
void Doctor::Display()
{
    Employee::Display();
    cout << "Chuyen khoa: " << Chuyenkhoa << endl;
    cout << "So nam kinh nghiem: " << namexp << endl;
}
void Doctor::hienThiThongTinCoBan() const
{

}

/*khoi ham gan gia tri*/
void Doctor::ganChuyenKhoa(const string& khoa)
{
    Chuyenkhoa = khoa;
}

/*khoi ham lay gia tri*/
string Doctor::layChuyenKhoa() const
{
    return Chuyenkhoa;
}
