#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//=================
void TotalUser(int x)
{
	ofstream count;
	string path="D:/Code/User/count";
	count.open(path.c_str(),std::ios::trunc);
	if (count.fail())
	{
		cout<<"can't file"<<endl;
	}
	else
	{
		count<<x;
		cout<<"OK";
	}
	count.close();
	
}
//==============
long power(int x,int y)
{
	if (x==0)
	{return 0;
	}
	long result=1;
	for (int i=0;i<y;i++)
	{
		result=result*x;
	}
	return result;
}

//====================
long string2int(string x)
{
	long result=0;
	long n=x.length();
	for (int i=0;i<n;i++)
	{
		if (x[i]<48&&x[i]>57)
		{
			return 0;
		}
		else
		{
		result=result+(x[i]-48)*power(10,n-1-i);	
		}
	}
	return result;
	
}
//============
int getCount()
{
	string path="D:/Code/User/count";
	ifstream fileCount;
	fileCount.open(path.c_str());
	string data;
	getline(fileCount,data);
	int x=string2int(data);
	return x;
}




//====================
void addUser(string name, string pass)
{
	
string path="D:/Code/User/"+name;
std::ofstream filedata(path.c_str(),std::ios::app);
if (filedata.fail())
{
	cout<<"can't write file";
}
else
{
	filedata<<name;
	filedata<<";";
	filedata<<pass;
	
	cout<<"successfull!";
}
filedata.close();

}
//====================================

void addList(string name)
{
string path_list="D:/Code/User/List";
std::ofstream file_list(path_list.c_str(),std::ios::app);
if(file_list.fail())
{
	cout<<"can't open file List";
}
else
{
	int tt=getCount();
	file_list<<tt+1;
	file_list<<":";
	file_list<<name;
	file_list<<",";
	file_list<<"enable";
	file_list<<";";
	file_list<<endl;
	TotalUser(tt+1);
	cout<<"add user success!";
}
file_list.close();
}

//====================================

bool FindUser(string name)
{
	ifstream filedata;
	string path="D:/Code/User/List";
	filedata.open(path.c_str());
	
	if(filedata.fail())
	{
		cout<<"can't open file";
	}
	else
	{
	while (!filedata.eof())
	{
		string tt;
		string result;
		getline(filedata,tt,':');
		getline(filedata,result,',');
		if (result==name)
		{
		filedata.close();
		return true;	
		}

	}
	filedata.close();
	return false;
	}
	
	
	
	
}
void NewMember(string name,string pass)
{
	if (FindUser(name)==1)
	{
	cout<<"tai khoan da ton tai";
	cout<<endl;
	}
	else
	{
		addUser(name, pass);
		addList(name);
		
	}
	
}
bool Dangnhap(string name, string pass)
{
	ifstream filedata;
	string path="D:/Code/User/List";
	filedata.open(path.c_str());
	bool check=false;
	while (!filedata.eof())
	{
		string tt;
		string m_name;
		string status;
		getline(filedata,tt,':');
		getline(filedata,m_name,',');
		getline(filedata,status,';');
		if (name==m_name&&status=="enable") {
			check=true;
			break;
		}
	}
	filedata.close();
	if (check==false)
	{
		cout<<"tai khoan khong ton tai hoac khong con hoat dong";
		cout<<endl;
		return false;
	}
	else
	{
		ifstream fileuser;
		string pathUser="D:/Code/User/"+name;
		fileuser.open(pathUser.c_str());
		string taikhoan;
		string password;
		getline(fileuser,taikhoan,';');
		getline(fileuser,password);
		if (password!=pass)
		return false;
		
	}
	return true;
}


//==============

int main()
{
while(true)
{
	cout<<"1.Dang nhap"<<endl;
	cout<<"2.Dang ky"<<endl;
	cout<<"0.Thoat"<<endl;
	string x;
	getline(cin,x);
	cout<<endl;
	if (x=="1")
	{
		while(true)
		{
			string tendangnhap,pass;
		
			cout<<"Ten dang nhap:";
			getline(cin,tendangnhap);
			
			
			cout<<"mat khau:";
			getline(cin,pass);
			cout<<endl;
			bool check=Dangnhap(tendangnhap,pass);
			if (check==false)
					{
						cout<<"Dang nhap that bai"<<endl;
						cout<<"chon 0 de quay lai trang dang nhap";
						string exitt;
						while( true)
					{
						getline(cin,exitt);
						cout<<endl;
						if (exitt=="0")
						break;
						else  {
							continue;
						}
					}
					
					break;
						
						
					}
			else 
			{
				cout<<"Dang nhap thanh cong"<<endl;
				while (true)
				{
					cout<<"nhan 0 de quay lai"<<endl;
					string back;
					getline(cin,back);
					cout<<endl;
					if (back=="0")
					{
						break;
					}
					else
					{
						continue;
					}
				}
			}
			
			break;	
		}
	}
	if (x=="2")
	{
		string NameRes,passRes;
		cout<<"nhap ten nguoi dung:"<<endl;
		getline(cin,NameRes);
		cout<<endl;
		cout<<"nhap mat khau:"<<endl;
		getline(cin,passRes);
		cout<<endl;
		NewMember(NameRes,passRes);
		while (true)
		{
			string backRe;
			cout<<"nhan 0 de quay lai"<<endl;
			getline(cin,backRe);
			cout<<endl;
			if (backRe=="0")
			{
				break;
			}
			else 
			continue;
		}
		
	}
	if (x=="0")
	{
		break;
	}
	else {
		continue;
	}
}
cout<<"GoodBye!!";
exit(0);
	return 0;
}
