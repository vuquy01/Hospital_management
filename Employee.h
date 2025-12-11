#pragma once
#include<iostream>
#include"Person.h"
using namespace std;
#include<string.h>
class Employee :public Person
{
    /* khối 1 thông tin nhân viên */
    string TypeNV;            // Loại: "YTa", "DieuDuong", "LeTan", "KeToan", "BaoVe", "LaoCong", "KyThuatVien", "ThuVien"
    string Chucvu;             // Chức vụ: "TruongPhong", "PhoPhong", "NhanVien", "ThucTap"
    string PhongBan;           // Phòng ban: "LeTan", "TaiChinh", "HanhChinh", "KyThuat", "VeSinh"
    string trinhdo;
    string firstdate;            // Ngày vào làm: dd/mm/yyyy
    string TypeHD;         // "BienChe", "HopDong", "ThoiVu", "ThucTap"
    static const int LUONGCOBAN = 2345000;            // Lương cơ bản
    float Heso;     // Hệ số lương
    float Phucap;             // Phụ cấp
    string status;               // "DangLamViec", "NghiPhep", "NghiViec"

    /* khối 2 quản lý thời gian*/
    struct WorkShift
    {
        string date;             // Ngày làm việc: dd/mm/yyyy
        string shift;            // "Sang" (6-14h), "Chieu" (14-22h), "Toi" (22-6h)
        string DiaDiem;         // Địa điểm làm việc
        string Giamsat;       // Người giám sát
        string task;             // Nhiệm vụ
        bool TangCa;         // Có làm thêm giờ không
        float TimeTangca;     // Số giờ làm thêm
    };
    static const int MAX_SHIFTS = 31; // Tối đa 31 ngày/tháng
    WorkShift LichLamViec[MAX_SHIFTS];
    int soCaDaXep;

    /* khối 7 trạng thái*/
    struct NghiPhep
    {
        string Start;
        string End;
        string TypePhep;      // "PhepNam", "PhepOm", "NghiKhongPhep", "CongTac"
        string Lydo;
        string Trangthai;   // "ChoDuyet", "DaDuyet", "TuChoi"
    };
    static const int MAX_PHEP = 20;
    NghiPhep HSnghiphep[MAX_PHEP];
    int soLanVangMat;
    int Phepconlai;      // Số ngày phép còn lại
public:
    /*khối hàm khởi tạo*/
    Employee();

    /*khối hàm co bản(nhao xuat)*/
    void Input();
    void Display();
    void hienThiThongTinCoBan() const;
    string taoID();

    /*khoi ham gan gia tri*/
    void ganTypeNV(string type);
    void ganChucvu(string chuc);
    void ganPhongBan(string phong);
    void gantrinhdo(string trinh);
    void ganfirstdate(string ngay);
    void ganTypeHD(string HD);
    void ganstatus(string trangthai);
    void ganHesoluong(float hesoluong);
    void ganphucap(float phucapchucvu);

    /*khối hàm lấy giá trị*/
    string ganTypeNV() const;
    string ganChucvu() const;
    string ganPhongBan() const;
    string gantrinhdo() const;
    string ganfirstdate() const;
    string ganTypeHD() const;
    string ganstatus() const;
    float ganHesoluong() const;
    float ganphucap() const;

    /*khoi ham kiem tra*/
};
