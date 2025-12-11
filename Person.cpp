#include "Person.h"
/*Khoi ham khoi tao*/
Person::Person()
{
	Name = "";
	date = "";
	age = 0;
	CCCD_CMND = "";
	GioiTinh = "";
	DiaChi = "";
	SDT = "";
	mail = "";
}

Person::Person(string cccd, string n, string d, int tuoi, string sex, string diachii, string sdt, string m)
{
	Name = n;
	date = d;
	age = tuoi;
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
		cout << "\nNhap ngay thang nam sinh (dd/mm/yyyy): ";
		cin >> date;
		if (!kiemTraNgaySinhHopLe())
			cout << "\nNgay thang nam sinh khong hop le.";
	} while (!kiemTraNgaySinhHopLe());
	age = tinhTuoi();
	cout << "\nTuoi: " << age;
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
	do{
		cout << "\nNhap mail: ";
		getline(cin, mail);
		if (!kiemTraEmailHopLe())
			cout << "\nEmail khong hop le.";
	} while (!kiemTraEmailHopLe());
}
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
void Person::ganCCCD_CMND(string cccd)
{

}
void Person::ganDiaChi(string adress)
{

}
void Person::ganID()
{

}

/*khoi ham tinh gia tri*/
int Person::tinhTuoi() const
{
	int tuoi;
	if (!kiemTraDinhDangNgaySinh(date))
		return -1;
	else
	{
		int namsinh = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
		tuoi = 2025 - namsinh;
		if (tuoi < 0 || tuoi > 150) 
		{
			return -1;
		}
		return tuoi;
	}
}

/*khoi ham kiem tra*/
bool ktra(char c)
{
	return (c >= '0' && c <= '9');
}
bool laNamNhuan(int nam) 
{
	if ((nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0))
		return 1;
	else
		return 0;
}

bool Person::kiemTraDinhDangNgaySinh(string ngay) const
{
	if (ngay.length() != 10)
	{
		cout << "\nNgay sinh phai co dang dd/mm/yyyy." << endl;
		return 0;
	}
	
	if (ngay[2] != '/' || ngay[5] != '/')
	{
		cout << "Dinh dang sai: phai co /" << endl;
		return 0;
	}
	for (int i = 0; i < 2; i++)
	{
		if (!ktra(ngay[i]))
		{
			cout << "\nKy tu thu " << (i + 1) << " phai la so (ngay)" << endl;
			return 0;
		}
	}
	for (int i = 3; i < 5; i++)
	{
		if (!ktra(ngay[i]))
		{
			cout << "\nKy tu thu " << (i + 1) << " phai la so (thang)" << endl;
			return 0;
		}
	}
	for (int i = 6; i < 10; i++)
	{
		if (!ktra(ngay[i]))
		{
			cout << "\nKy tu thu " << (i + 1) << " phai la so (nam)" << endl;
			return 0;
		}
	}
	int ngaysinh, thangsinh, namsinh;
	namsinh = (ngay[6] - '0') * 1000 + (ngay[7] - '0') * 100 + (ngay[8] - '0') * 10 + (ngay[9] - '0') * 1;
	ngaysinh = (ngay[0] - '0') * 10 + (ngay[1] - '0') * 1;
	thangsinh = (ngay[3] - '0') * 10 + (ngay[4] - '0') * 1;
	if (thangsinh < 1 || thangsinh>12)
		return 0;
	if (namsinh < 1900 || namsinh > 2025) 
		return 0;
	int soNgayTrongThang;
	if (thangsinh == 1 || thangsinh == 3 || thangsinh == 5 || thangsinh == 7 ||
		thangsinh == 8 || thangsinh == 10 || thangsinh == 12) 
	{
		soNgayTrongThang = 31;
	}
	else if (thangsinh == 4 || thangsinh == 6 || thangsinh == 9 || thangsinh == 11) 
	{
		soNgayTrongThang = 30;
	}
	else 
	{
		if (laNamNhuan(namsinh))
		{
			soNgayTrongThang = 29;
		}
		else 
		{
			soNgayTrongThang = 28;
		}
	}
	if (ngaysinh > soNgayTrongThang || ngaysinh < 1)
		return 0;
	return 1;
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
	if (mail.length() < 5)
		return 0;
	else
		return 1;
	int vtri1 = -1;
	for (int i = 0; i < mail.length(); i++)
	{
		if (mail[i] == '@')
		{
			vtri1 = i;
			break;
		}
	}
	if (vtri1 == -1)
	{
		cout << "\nEmail khong hop le.";
		return 0;
	}
	else
		return 1;
	int vtri2 = -1;
    for (int i = 0; i < mail.length(); i++) 
	{
        if (mail[i] == '.') 
		{
            vtri2 = i;
            break;
        }
    }
	if (vtri2 == -1) 
	{
		cout << "Domain phai co dau cham (VD: .com, .vn)" << endl;
		return 0;
	}
	else
		return 1;
}
bool Person::kiemTraNgaySinhHopLe() const
{
	if (!kiemTraDinhDangNgaySinh(date))
		return 1;
	else
		return 0;
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
