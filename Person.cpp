#include "Person.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

bool Person::ktra(char c)
{
	return (c >= '0' && c <= '9');
}

Person::Person()
{
	Name = "";
	date = "";
	CCCD_CMND = "";
	GioiTinh = "";
	DiaChi = "";
	SDT = "";
    age = 0;
}

Person::Person(string cccd, string n, string d, string sex, string diachii, string sdt)
{
	Name = n;
	date = d;
	CCCD_CMND = cccd;
	GioiTinh = sex;
	DiaChi = diachii;
	SDT = sdt;
    age = tinhTuoi();
}

void Person::Display()
{
	cout << "========Hien thi========" << endl;
	cout << "Ten: " << Name << endl;
	cout << "Tuoi: " << age << endl;
	cout << "Ngay sinh: " << date << endl;
	cout << "Gioi tinh: " << GioiTinh << endl;
	cout << "Dia chi: " << DiaChi << endl;
	cout << "So dien thoai: " << SDT << endl;
}

void Person::hienThiThongTinCoBan()
{
}

string Person::layName()
{
	return Name;
}
string Person::layDate()
{
	return date;
}
string Person::laySdt()
{
	return SDT;
}
string Person::layDiachi()
{
	return DiaChi;
}

void Person::ganDate(string d)
{
	date = d;
    age = tinhTuoi();
}
void Person::ganTen(string ten)
{
	Name = ten;
}
void Person::ganSDT(string sdt)
{
	SDT = sdt;
}
void Person::ganGioiTinh(string sex)
{
	GioiTinh = sex;
}

int Person::tinhTuoi()
{
    if (date.empty()) return 0;
    
    int day, month, year;
    stringstream ss(date);
    char delim;

    if (!(ss >> day >> delim && delim == '/' && ss >> month >> delim && delim == '/' && ss >> year)) {
        return 0;
    }

    if (year < 100) {
        year += (year > (std::time(0) % 100)) ? 1900 : 2000;
    }

    time_t t = time(0);
    tm* now = localtime(&t);
    
    int current_year = now->tm_year + 1900;
    int current_month = now->tm_mon + 1;
    int current_day = now->tm_mday;
    
    int calculated_age = current_year - year;

    if (current_month < month || (current_month == month && current_day < day)) {
        calculated_age--;
    }
    
    age = calculated_age;
	return age;
}

bool Person::kiemTraSDTHopLe()
{
	size_t dai = SDT.length();
	if (dai < 10 || dai> 11)
	{
		return false;
	}
	if (SDT[0] != '0') {
		return false;
	}
	for (int i = 0; i < dai; i++)
	{
		char c = SDT[i];
		if (!ktra(c))
		{
			return false;
		}
	}
	return true;
}

bool Person::kiemTraTuoiHopLe()
{
    if (age == 0) tinhTuoi(); 
    
	if (age >= 150 || age <= 0)
		return false;
	else
		return true;
}

bool Person::kiemTraCCCDHopLe()
{
	size_t a = CCCD_CMND.length();
	if (a != 12 && a != 9) 
		return false;
        
	for (int i = 0; i < a; i++)
	{
		char c = CCCD_CMND[i];
		if (!ktra(c))
			return false;
	}
	return true;
}

bool Person::kiemTraGioiTinhHopLe()
{
	return (GioiTinh == "Nam" || GioiTinh == "Nu");
}

bool Person::kiemTraNgaySinhHopLe()
{
    if (date.length() < 8 || date.length() > 10) return false;
    
    int day, month, year;
    stringstream ss(date);
    char delim1, delim2;

    if (!(ss >> day >> delim1 && delim1 == '/' && ss >> month >> delim2 && delim2 == '/' && ss >> year)) {
        return false;
    }

    if (day < 1 || day > 31 || month < 1 || month > 12) return false;
    if (year < 1900 || year > (std::time(0) % 100 + 2000)) return false;

    if (month == 2) {
        bool is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > 29 || (!is_leap && day > 28)) return false;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) return false;
    }
    
	return true;
}

void Person::luuVaoFile(ofstream& file)
{
	file << Name << ",";
    file << CCCD_CMND << ",";
	file << date << ",";
    file << GioiTinh << ",";
	file << DiaChi << ",";
	file << SDT << endl; 
}

void Person::docTuFile(ifstream& file)
{
    string line;
    if (std::getline(file, line)) 
    {
        std::stringstream ss(line); 
        
        std::getline(ss, Name, ',');
        std::getline(ss, CCCD_CMND, ',');
        std::getline(ss, date, ',');
        std::getline(ss, GioiTinh, ',');
        std::getline(ss, DiaChi, ',');
        std::getline(ss, SDT, ','); 
        
        age = tinhTuoi(); 
    }
}
