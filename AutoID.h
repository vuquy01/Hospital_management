#pragma once
#include<iostream>
using namespace std;
#include<string.h>
/*Lớp tạo để sinh mã tự động*/
class AutoID
{
private:
    /*tạo 1 file để lưu stt*/
    static const char* COUNTER_FILE;
    /*khối 1 các biến đếm*/
    struct Counter
    {
        int benhNhan;
        int bacSi_TS;    // Tiến sĩ
        int bacSi_TH;    // Thạc sĩ
        int bacSi_CK;    // Chuyên khoa
        int bacSi_BS;    // Bác sĩ
        int bacSi_DT;    // Dược sĩ
        int phong_ICU;   // ICU
        int phong_PT;    // Phòng phẫu thuật
        int phong_CC;    // Cấp cứu
        int phong_TH;    // Phòng thường
        int benhAn;
    };
public:
    /*Khối 2 các hàm cơ bản*/
    // KHỞI TẠO - Đọc số đếm từ file
    static void khoiTao();
    // LƯU SỐ ĐẾM - Ghi vào file
    static void luuSoDem();

    /*khối 3 hàm sinh id*/
    // SINH ID BÁC SĨ
    static string sinhMaBacSi(const string& trinhDo);
    // SINH ID BỆNH NHÂN
    static string sinhMaBenhNhan();
    // SINH ID PHÒNG
    static string sinhMaPhong(int tang, const string& loaiPhong);
    // SINH ID HỒ SƠ BỆNH ÁN
    static string sinhMaBenhAn(const string& maBN, const string& maBS);
    // SINH ID CHO BẤT KỲ LOẠI NÀO
    static string sinhMaChuan(const string& tienTo, int doDaiSo);



    /*Khối 4 các phương thức với id*/
    // TÁCH THÔNG TIN TỪ ID
    static string layTrinhDoTuMaBS(const string& maBS);
    static int layTangTuMaPhong(const string& maPhong);
    static string layLoaiPhongTuMa(const string& maPhong);
    static string layMaBNTuMaBA(const string& maBA);
    static string layMaBSTuMaBA(const string& maBA);
    static string layNgayTuMaBA(const string& maBA);
    // KIỂM TRA ĐỊNH DẠNG ID
    static bool kiemTraMaBacSi(const string& ma);
    static bool kiemTraMaBenhNhan(const string& ma);
    static bool kiemTraMaPhong(const string& ma);
    static bool kiemTraMaBenhAn(const string& ma);
private:
    /*khối các hàm hỗ trợ*/   //tạo ra vì các mã hình thành theo ht vs như BSTH001(mã loại class+mã trình độ+stt)
    static string layNgayHienTai();
    static string chuanHoaTrinhDo(const string& trinhDo);
    static string chuanHoaLoaiPhong(const string& loaiPhong); //xếp các phòng để tạo mã như PICU0101(nghĩa là phòng ICU ở tầng 1 thứ 01)
    static int laySoThuTuTuMa(const string& ma, int viTriBatDau); //vd là BSTH001 thì phải lấy được đoạn mã 001
    static void tangDemBacSi(const string& trinhDo);  //các hàm tăng số mã 001,002...
    static void tangDemPhong(const string& loaiPhong);
};

