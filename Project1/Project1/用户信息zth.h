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
	bool qqflag, wxflag, wbflag;//1��ͨ��0δ��ͨ
	
	
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
	string wxnickname;//wx�ǳ� 
	int wxage;
	int wxbirthday;
	int wxyear;//wei��
	string wxlocal;//wx���ڵ�
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
	string qqnickname;//qq�ǳ�
	int qqage;//����
	int qqbirthday;//qq��������
	int qqyear;//q��//ע��ʱ��
	string qqlocal;//qq���ڵ�
};