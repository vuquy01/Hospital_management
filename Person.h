#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ifstream;
using std::ofstream;
using std::cout;

class Person {
private:
    string Name;
    string date;
    string CCCD_CMND;
    string GioiTinh;
    string DiaChi;
    string SDT;
    int age;
public:
    Person();
    Person(string cccd, string n, string d, string sex, string diachii, string sdt); 
    void Display();
    void hienThiThongTinCoBan();
    string layName();
    string layDate();
    string laySdt();
    string layDiachi();
    void ganDate(string d);
    void ganTen(string ten);
    void ganSDT(string sdt);
    void ganGioiTinh(string sex);
    int tinhTuoi();
    bool kiemTraSDTHopLe();
    bool kiemTraTuoiHopLe();
    bool kiemTraCCCDHopLe();
    bool kiemTraGioiTinhHopLe();
    bool kiemTraNgaySinhHopLe();
    void luuVaoFile(ofstream& file);
    void docTuFile(ifstream& file); 
};

