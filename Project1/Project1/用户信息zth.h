#include<string>
using namespace std;
class Userzth {
public:
	
	Userzth(){
		qqflag = 0;
		wxflag = 0;
		wbflag = 0;
	}
	
	int wxID=-1;//wx//1-100
	int qqID=-1;//qq//1-100;
	bool qqflag, wxflag, wbflag;//1开通，0未开通
	
	
};

class wxUserzth :virtual public Userzth {
public:
	void addfriend(wxUserzth&);
	void deletefriend(wxUserzth&);
	void findfriend(wxUserzth&);
	int creategroup(wxUserzth&);
	void findjoinin(wxUserzth&);
	void findgroup(wxUserzth&);
	void groupmanage(wxUserzth&, int);
	void addotherfriend(wxUserzth&);
	void menu(wxUserzth&);
	string wxnickname;//wx昵称 
	int wxage;
	int wxbirthday;
	int wxyear;//wei龄
	string wxlocal;//wx所在地
};

class qqUserzth :virtual public Userzth {
public:
	void addfriend(qqUserzth&);
	void deletefriend(qqUserzth&);
	void findfriend(qqUserzth&);
	int creategroup(qqUserzth&);
	void findjoinin(qqUserzth&);
	void findgroup(qqUserzth&);
	void groupmanage(qqUserzth&, int);
	void addotherfriend(qqUserzth&);
	void menu(qqUserzth&);
	string qqnickname;//qq昵称
	int qqage;//年龄
	int qqbirthday;//qq出生日期
	int qqyear;//q龄//注册时间
	string qqlocal;//qq所在地
};