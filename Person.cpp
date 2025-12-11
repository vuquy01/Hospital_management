#include "Person.h"
/*Khoi ham khoi tao*/
Person::Person()
{
	Name = "";
	date = "";
	CCCD_CMND = "";
	GioiTinh = "";
	DiaChi = "";
	SDT = "";
	mail = "";
}

Person::Person(string cccd, string n, string d, string sex, string diachii, string sdt, string m)
{
	Name = n;
	date = d;
	CCCD_CMND = cccd;
	GioiTinh = sex;
	DiaChi = diachii;
	SDT = sdt;
	mail = m;
}

/*khoi ham co ban(nhap xuat)*/
void Person::Input()
{
	cout << "\n--- NHAP THONG TIN ---\n";
	cout << "Nhap ten: ";
	cin.ignore();
	getline(cin, Name);
	do {
		cout << "Nhap số CCCD/CMND: ";
		cin.ignore();
		getline(cin, CCCD_CMND);
		if (!kiemTraCCCDHopLe())
		{
			cout << "Tuoi khong hop le! Vui long nhap lai.\n";
		}
	} while (!kiemTraCCCDHopLe());
	cin.ignore();
	do {
		cout << "\nNhap ngay thang nam sinh (dd/mm/yy): ";
		cin >> date;
		if (!kiemTraNgaySinhHopLe())
			cout << "\nNgay thang nam sinh khong hop le.";
	} while (!kiemTraNgaySinhHopLe());
	cout << "\nNhap dia chi: ";
	cin.ignore();
	getline(cin, DiaChi);
	cin.ignore();
	do {
		cout << "\nNhap gioi tinh(Nam/Nu): ";
		cin >> GioiTinh;
		if (!kiemTraGioiTinhHopLe())
		{
			cout << "Gioi tinh khong hop le!\n";
		}
	} while (!kiemTraGioiTinhHopLe());
	cin.ignore();
	do {
		cout << "\nNhap so dien thoai (10-11 so): ";
		getline(cin, SDT);
		if (!kiemTraSDTHopLe()) 
		{
			cout << "So dien thoai khong hop le!\n";
		}
	} while (!kiemTraSDTHopLe());
	cin.ignore();
	
void Person::Display()
{
	cout << "========Hien thi========";
	cout << "Ten: " << Name << endl;
	cout << "Tuoi: " << age << endl;
	cout << "Ngay sinh: " << date << endl;
	cout << "Gioi tinh: " << GioiTinh << endl;
	cout << "Dia chi: " << DiaChi << endl;
	cout << "So dien thoai: " << SDT << endl;
	cout << "Email: " << mail << endl;
}
void Person::hienThiThongTinCoBan() const
{

}

/*khoi ham lay gia tri*/
string Person::layName() const
{
	return Name;
}
string Person::layDate() const
{
	return date;
}
string Person::laySdt() const
{
	return SDT;
}
string Person::layDiachi() const
{
	return DiaChi;
}
string Person::layMail() const
{
	return mail;
}

/*khoi ham gan*/
void Person::ganDate(string d)
{
	date = d;
}
void Person::ganMail(string m)
{
	mail = m;
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

/*khoi ham tinh gia tri*/
int Person::tinhTuoi() const
{
	return age; //chx vt:))
}

/*khoi ham kiem tra*/
bool ktra(char c)
{
	return (c >= '0' && c <= '9');
}
bool Person::kiemTraSDTHopLe() const
{
	size_t dai = SDT.length();
	if (dai < 10 || dai> 11)
	{
		return 0;
	}
	if (SDT[0] != '0') {
		return 0;
	}
	for (int i = 0; i < dai; i++)
	{
		char c = SDT[i];
		if (!ktra(c))
		{
			return 0;
		}
	}
	return 1;
}
bool Person::kiemTraTuoiHopLe() const
{
	if (age >= 150 || age <= 0)
		return 0;
	else
		return 1;
}
bool Person::kiemTraCCCDHopLe() const
{
	size_t a = CCCD_CMND.length();
	if (a != 12)
		return 0;
	for (int i = 0; i < a; i++)
	{
		char c = CCCD_CMND[i];
		if (ktra(c))
			return 1;
		else
			return 0;
	}
	return 1;
}
bool Person::kiemTraGioiTinhHopLe() const
{
	return (GioiTinh == "Nam" || GioiTinh == "Nu");
}
bool Person::kiemTraEmailHopLe() const
{
	if (mail.length() < 5||mail.length()="")
		return 0;

	return 1;
}
bool Person::kiemTraNgaySinhHopLe() const
{
	//chx bt vt sao tiếp
	return 1;
}


/*khối hàm tương tác với file*/
void Person::luuVaoFile(ofstream& file) const
{
	file << Name << endl;
	file << age << endl;
	file << date << endl;
	file << GioiTinh << endl;
	file << DiaChi << endl;
	file << SDT << endl;
	file << mail << endl;
}

void Person::docTuFile(ifstream& file)
{
	getline(file, Name);
	file >> age;
	file.ignore();
	getline(file, date);
	getline(file, GioiTinh);
	getline(file, DiaChi);
	getline(file, SDT);
	getline(file, mail);
}

