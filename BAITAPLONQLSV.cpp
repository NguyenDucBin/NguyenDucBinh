#include<iostream>
#include<string.h>
#include<conio.h>
#include<iomanip>
using namespace std;
class sinhvien
{
	
	public:
		char hoten[20], gioitinh[20];
		char namsinh[20], diachi[30];
		char masv[20], lop[10];
		float tin1, tin2, tin3, tin4, anh1, anh2, DTB;
		
			void nhap();
			void hienthi();
};

void sinhvien::nhap()
{
	cin.ignore(1); 
	cout<<"\n Nhap ho ten:";cin.getline(hoten,20);fflush(stdin);
	cout<<"\n Nhap gioi tinh:";cin.getline(gioitinh,20);fflush(stdin);
	cout<<"\n Nhap nam sinh:";cin.getline(namsinh,20);fflush(stdin);
	cout<<"\n Nhap dia chi:";cin.getline(diachi,30);fflush(stdin);
	cout<<"\n Nhap ma sinh vien:";cin.getline(masv,20);fflush(stdin);
	cout<<"\n Nhap lop:";cin.getline(lop,10);fflush(stdin);	
	cout<<"\n Nhap diem tin 1:";
	cin>>tin1;
	cout<<"\n Nhap diem tin 2:";
	cin>>tin2;
	cout<<"\n Nhap diem tin 3:";
	cin>>tin3;
	cout<<"\n Nhap diem tin 4:";
	cin>>tin4;
	cout<<"\n Nhap anh 1:";
	cin>>anh1;
	cout<<"\n Nhap anh 2:";
	cin>>anh2;
	cout<<endl;
}

void sinhvien::hienthi()
{
	cout<<""<<setw(20)<<hoten<<setw(20)<<gioitinh<<setw(20)<<namsinh;
	cout<<""<<setw(20)<<diachi<<setw(20)<<masv<<setw(20)<<lop;
	
	cout<<""<<setw(20)<<tin1<<setw(20)<<tin2<<setw(20)<<tin3<<setw(20)<<tin4;
	cout<<""<<setw(20)<<anh1<<setw(20)<<anh2;
	
	DTB=(tin1+tin2+tin3+tin4+anh1+anh2)/6;
	cout<<""<<setw(20)<<DTB;
	cout<<""<<setw(20)<<setprecision(2)<<DTB;
	
	if (DTB>=8)
	{
		cout<<"Xep loai gioi";
	}
	else if(DTB>=7)
	{
		cout<<"Xep loai kha";
	}
	else if(DTB>=5)
	{
		cout<<"Xep loai trung binh";
	}
	else if(DTB<5)
	{
		cout<<"Xep loai yeu";
	}
}

class quanlysv: public sinhvien
{
	public:
		
		sinhvien sv[100];
		int n;
		
			void nhap();
			void hienthi();
			void xeploaiHL();
			void dssvDTBtd();
			void dssvDTBgd();
			void timsvDTBMAX();
			void timkiemsv();
		
};

void quanlysv::nhap()
{
	cout<<"Nhap so luong sinh vien:";cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\n sinh vien thu:"<<i+1<<"";
		sv[i].nhap();
	}
}

void quanlysv::hienthi()
{
	cout<<"\n Ho Ten"<<setw(20)<<"Gioi Tinh"<<setw(20)<<"Nam Sinh"<<setw(20);
	cout<<"Dia Chi"<<setw(20)<<"Ma Sinh Vien"<<setw(20)<<"Lop"<<setw(20);
	
	cout<<"Tin1"<<setw(20)<<"Tin2"<<setw(20)<<"Tin3"<<setw(20)<<"Tin4"<<setw(20);
	cout<<"Anh1"<<setw(20)<<"Anh2"<<setw(20)<<"DTB"<<setw(20)<<"DTB Lam Tron"<<setw(20);
	for(int i=0;i<n;i++)
	{
		sv[i].hienthi();
	}
}

void quanlysv::xeploaiHL()
{
	cout<<"\n";
	cout<<"---\n Sinh vien xep loai hoc luc gioi---"<<endl;
	for(int i=0;i<n;i++)
	{
		if(sv[i].DTB>=8)
		{
			sv[i].hienthi();
		}
	}
	cout<<"\n";
	cout<<"\n---Sinh vien xep loai hoc luc yeu---"<<endl;
	for(int i=0;i<n;i++)
	{
		if(sv[i].DTB<5)
		{
			sv[i].hienthi();
		}
	}
}

void quanlysv::dssvDTBtd()
{
	int i,j;
	sinhvien tg;
	cout<<"\n";
	cout<<"\n---Danh sach sinh vien co diem trung binh tang dan---"<<endl;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(sv[i].DTB>sv[j].DTB)
			tg=sv[i];
			sv[i]=sv[j];
			sv[j]=tg;
				
		}
	}
	cout<<"Sau khi sap xep la:"<<endl;
	for(int i=0;i<n;i++)
	{
		sv[i].hienthi();
	}
}

void quanlysv::dssvDTBgd()
{
	int i,j;
	sinhvien tg;
	cout<<"\n";
	cout<<"\n---Danh sach sinh vien co diem trung binh giam dan---"<<endl;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(sv[i].DTB<sv[j].DTB)
			tg = sv[i];
			sv[i] = sv[j];
			sv[j] = tg;
		}
	}
	cout<<"Sau khi sap xep:"<<endl;
	for(int i=0;i<n;i++)
	{
		sv[i].hienthi();
	}
}

void quanlysv::timsvDTBMAX()
{
	cout<<"\n";
	cout<<"\n---Danh sach sinh vien co diem trung binh cao nhat---"<<endl;
	int max = 0;
	for(int i=0;i<n;i++)
	{
		if(sv[i].DTB>max)
		{
			max = sv[i].DTB;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(sv[i].DTB>max)
		{
			sv[i].hienthi();
		}
	}
}

void quanlysv::timkiemsv()
{
	string msv;
	int count=0;
	cout<<"\n Nhap ma sinh vien can tim:";fflush(stdin);getline(cin,msv);
	cout<<"n---Thong tin sinh vien khi nhap xong la---";
	cout<<"\n Ho Ten"<<setw(20)<<"Gioi tinh"<<setw(20)<<"Nam Sinh"<<setw(20);
	cout<<"Dia Chi"<<setw(20)<<"Ma Sinh Vien"<<setw(20)<<"Lop"<<setw(20);
	cout<<"Tin1"<<setw(20)<<"Tin2"<<setw(20)<<"Tin3"<<setw(20)<<"Tin4"<<setw(20);
	cout<<"Anh1"<<setw(20)<<"Anh2"<<setw(20)<<"DTB"<<setw(20)<<"DTB Lam Tron"<<setw(20);
	for(int i=0;i<n;i++)
	{
		if(sv[i].masv == msv)
		{
			sv[i].hienthi();
			count++;
		}
	}
	if(count == 0)
	{
		cout<<"\n Khong tim thay thong tin sinh vien";
	}
}
int main()
{
	quanlysv QLSV;
	int option,n;
	cout<<"---Day La Chuong Trinh Quan Ly Sinh Vien---\n";
	cout<<"Xin moi cac ban nhap mot so > 0 de tiep tuc:";cin>>n;
	while(n>0)
	{
		cout<<"\n==============MENU==============";
		cout<<"\n ==== Chuong Trinh Quan Ly Sinh Vien ====";
		cout<<"\n Moi ban nhap trong cac lua chon sau:";
		cout<<"\n 1.Nhap thong tin sinh vien.";
		cout<<"\n 2.Hien thi thong tin sinh vien.";
		cout<<"\n 3.Xep loai hoc luc sinh vien.";
		cout<<"\n 4.Sap xep sinh vien co diem trung binh tang dan.";
		cout<<"\n 5.Sap xep sinh vien co diem trung binh giam dan.";
		cout<<"\n 6.Tim sinh vien co diem trung binh cao nhat.";
		cout<<"\n 7.Tim kiem sinh vien theo ma sinh vien or hoten.";
		cout<<"\n *Xin moi nhap lua chon cua ban.";cin>>option;
		switch(option)
		{
			case 1:
				QLSV.nhap();
				cout<<"Bam mot phim bat ki de tiep tuc.\n";
				system("pause");
				break;
			case 2:
				QLSV.hienthi();
				cout<<"Bam mot phim bat ki de tiep tuc.\n";
				system("pause");
				break;
			case 3:
				QLSV.xeploaiHL();
				cout<<"Bam mot phim bat ki de tiep tuc.\n";
				system("pause");
				break;
			case 4:
				QLSV.dssvDTBtd();
				cout<<"Bam mot phim bat ki de tiep tuc.\n";
				system("pause");
				break;
			case 5:
				QLSV.dssvDTBgd();
				cout<<"Bam mot phim bat ki de tiep tuc.\n";
				system("pause");
				break;
			case 6:
				QLSV.timsvDTBMAX();
				cout<<"Bam mot phim bat ki de tiep tuc.\n";
				system("pause");
				break;
			case 7:
				QLSV.timkiemsv();
				cout<<"Bam mot phim bat ki de tiep tuc.\n";
				system("pause");
				break;
			default:
				cout<<"\n Khong tim thay du lieu ban nhap. Xin moi nhap lai.";
				cout<<"Bam mot phim bat ki de tiep tuc.\n";
				system("pause");
		}
	}
	getch();
	return 0;
}


