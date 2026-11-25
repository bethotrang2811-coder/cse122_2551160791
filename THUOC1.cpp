#include <iostream>
using namespace std;

class THUOC{
	private:
		int maThuoc;
		string tenThuoc;
		string hangThuoc;
		double gia;
	public:
		THUOC():maThuoc(1),tenThuoc(""),hangThuoc(""),gia(1){
		}
		THUOC(int maThuoc,string tenThuoc,string hangThuoc,double gia):
		maThuoc(maThuoc),tenThuoc(tenThuoc),hangThuoc(hangThuoc),gia(gia){
		}
		int getmaThuoc()
		{
			return maThuoc;
		}
		string gettenThuoc()
		{
			return tenThuoc;
		}
		string gethangThuoc()
		{
			return hangThuoc;
		}
		double getgia()
		{
			return gia;
		}
		void setmaThuoc(int maThuoc)
		{
			this->maThuoc=maThuoc;
		}
		void settenThuoc(string tenThuoc)
		{
			this->tenThuoc=tenThuoc;
		}
		void sethangThuoc(string hangThuoc)
		{
			this->hangThuoc=hangThuoc;
		}
		void setgia(double gia)
		{
			this->gia=gia;
		}
		virtual void cinT()
		{
			cout<<"Nhap ma thuoc: ";cin>>maThuoc;
			cin.ignore();
			cout<<"Nhap ten thuoc: ";getline(cin,tenThuoc);
			cout<<"Nhap hang thuoc: ";getline(cin,hangThuoc);
			cout<<"Nhap gia: ";cin>>gia;
		}
		virtual void coutT() const
		{
			cout<<"Ma thuoc: "<<maThuoc<<endl;
			cout<<"Ten thuoc: "<<tenThuoc<<endl;
			cout<<"Hang thuoc: "<<hangThuoc<<endl;
			cout<<"Gia: "<<gia<<endl;
		}
		bool operator ==(THUOC&a)
		{
			return this->getmaThuoc()==a.getmaThuoc();
		}
};
class THUOCBO:public THUOC{
	string congDung;
	public:
	string getcongDung()
	{
		return congDung;
	}
	void setcongDung(string congDung)
	{
		this->congDung=congDung;
	}	
	void cinT()
	{
		THUOC::cinT();
		cin.ignore();
		cout<<"Nhap cong dung: ";getline(cin,congDung);
    }
	void coutT() const
	{
		THUOC::coutT();
		cout<<"Cong dung: "<<congDung<<endl;
    }
    ~THUOCBO()
    {
	}
};
class KHANGSINH:public THUOC{
	double hamLuongSuDung;
	public:
	double gethamLuongSuDung()
	{
		return hamLuongSuDung;
	}
	void sethamLuongSuDung(double hamLuongSuDung)
	{
		this->hamLuongSuDung=hamLuongSuDung;
	}	
	void cinT()
	{
		THUOC::cinT();
		cin.ignore();
		cout<<"Nhap ham luong su dung: ";cin>>hamLuongSuDung;
    }
	void coutT() const
	{
		THUOC::coutT();
		cout<<"Ham luong su dung: "<<hamLuongSuDung<<endl;
    }
    ~KHANGSINH()
    {
	}
};
int main()
{
	int n;
	do
	{
		cout<<"N: ";cin>>n;
	}
	while(n<=0||n>=10);
	THUOC *ds[n];
	for(int i=0;i<n;i++)
	{
		int choice;
		cout<<"Nhap 1 de chon thuoc bo hoac nhap 2 de chon khang sinh: ";
		cin>>choice;
		if(choice==1)
		{
			ds[i]=new THUOCBO();
		    ds[i]->cinT();
		}
		else 
		{
			ds[i]=new KHANGSINH();
		    ds[i]->cinT();
		}
	}
	for(int i=0;i<n;i++)
	{
		ds[i]->coutT();
    }
   
	int choice;
	cout<<"Nhap 1 de chon thuoc bo hoac nhap 2 de chon khang sinh: ";
	cin>>choice;
	if(choice==1)
	{
		ds[n]=new THUOCBO();
	    ds[n]->cinT();
	}
	else 
	{
		ds[n]=new KHANGSINH();
	    ds[n]->cinT();
	}

    int j=0;
    for(int i=0;i<n;i++)
    {
    	if(*ds[n]==*ds[i])
    	j++;
    	cout<<"Thuoc nay co trong danh sach!!!";
    	break;
	}
	if(j=0) cout<<"Thuoc nay khong co trong danh sach";
	return 0;
}
