#include"用户信息zth.h";
#include"wx信息zth.h";
#include"qq信息zth.h";
#include<iostream>
#include<time.h>
#include<fstream>
#pragma warning(disable : 4996);
using namespace std;
wxUserzth wxUserzthlist[100];
qqUserzth qqUserzthlist[100];
int getmytime() {
	int a, b, c, longtime;
	time_t t;
	struct tm * lt;
	time(&t);//获取时间戳。
	lt = localtime(&t);//转为时间结构
	a = lt->tm_hour, b = lt->tm_min, c = lt->tm_sec;
	cout << "时间:" << a << ":" << b << ":" << c << endl;
	longtime = a * 10000 + b * 100 + c;
	return longtime;
}

wxUserzth createwx() {
	system("cls");
	wxUserzth exam;
	exam.wxID = wxinformationzth::getwxidnumber();//第一个为0
	wxinformationzth::changewxidnumber(1);//id+1
	cout << "注册信息" << endl;
	cout << "create wxnickname:" << endl;
	cin >> exam.wxnickname;
	cout << "wxnickname:" << exam.wxnickname << "  has been created" << endl;
	cout << "create birthday:year/month/day" << endl;
	cin >> exam.wxbirthday;
	cout << "birthday:" << exam.wxbirthday << endl;
	cout << "create age:" << endl;
	cin >> exam.wxage;
	cout << "年龄为" << exam.wxage << endl;
	cout << "create local:" << endl;
	cin >> exam.wxlocal;
	cout << "local:" << exam.wxlocal << endl;
	exam.wxflag = 1;
	exam.wxyear = getmytime();
	cout << "wxyear:" << exam.wxyear << endl;
	cout << "注册已完成，请获取你的登录编号:";
	cout << exam.wxID << endl;
	system("PAUSE");
	return exam;
}

qqUserzth createqq() {
	system("cls");
	qqUserzth exam;
	exam.qqID = qqinformationzth::getqqidnumber();//第一个为0
	qqinformationzth::changeqqidnumber(1);//id+1
	cout << "注册信息" << endl;
	cout << "create qqnickname:" << endl;
	cin >> exam.qqnickname;
	cout << "qqnickname:" << exam.qqnickname << "  has been created" << endl;
	cout << "create birthday:year/month/day" << endl;
	cin >> exam.qqbirthday;
	cout << "birthday:" << exam.qqbirthday << endl;
	cout << "create age:" << endl;
	cin >> exam.qqage;
	cout << "年龄为" << exam.qqage << endl;
	cout << "create local:" << endl;
	cin >> exam.qqlocal;
	cout << "local:" << exam.qqlocal << endl;
	exam.qqflag = 1;
	exam.qqyear = getmytime();
	cout << "qqyear:" << exam.qqyear << endl;
	cout << "注册已完成，请获取你的登录编号:";
	cout << exam.qqID << endl;
	system("PAUSE");
	return exam;
}

wxUserzth wxidfind(int i) {
	int p;
	for (p = 0;p < wxinformationzth::getwxidnumber();p++) {
		if (wxUserzthlist[p].wxID == i) {
			return wxUserzthlist[p];
		}
	}
	cout << "未找到" << i << "号微信用户" << endl;
	system("PAUSE");
}

qqUserzth qqidfind(int i) {
	int p;
	for (p = 0;p < qqinformationzth::getqqidnumber();p++) {
		if (qqUserzthlist[p].qqID == i) {
			return qqUserzthlist[p];
		}
	}
	cout << "未找到该用户，请创建" << endl;
	system("PAUSE");
}

void wxUserzth::addfriend(wxUserzth &exam) {//添加好友
	system("cls");
	int i, number;
	cout << "需要添加的好友编号：";
	cin >> number;//i<100
	i = number;
	if (wxinformationzth::getwxfriendlist(exam.wxID, i) != 1 && i < wxinformationzth::getwxidnumber() && i != exam.wxID) {
		wxinformationzth::change1wxfriendlist(exam.wxID, i);//竖行代表当前账户
		cout << "你与" << number << "号好友关系已建立" << endl;
		system("PAUSE");
	}
	else if (i == exam.wxID) {
		cout << "你不能加自己为好友" << endl;
		system("PAUSE");
	}
	else if (wxinformationzth::getwxfriendlist(exam.wxID, i) == 1) {
		cout << "已建立好友关系，请勿重复操作" << endl;
		system("PAUSE");
	}
	if (i >= wxinformationzth::getwxidnumber()) {
		cout << "该用户不存在" << endl;
		system("PAUSE");
	}
}

void qqUserzth::addfriend(qqUserzth &exam) {//添加好友
	system("cls");
	int i, number;
	cout << "需要添加的好友编号：";
	cin >> number;//i<100
	i = number;
	if (qqinformationzth::getqqfriendlist(exam.qqID, i) != 1 && i < qqinformationzth::getqqidnumber() && i != exam.qqID) {
		qqinformationzth::change1qqfriendlist(exam.qqID, i);//竖行代表当前账户
		cout << "你与" << number << "号好友关系已建立" << endl;
		system("PAUSE");
	}
	else if (i == exam.qqID) {
		cout << "你不能加自己为好友" << endl;
		system("PAUSE");
	}
	else if (qqinformationzth::getqqfriendlist(exam.qqID, i) == 1) {
		cout << "已建立好友关系，请勿重复操作" << endl;
		system("PAUSE");
	}
	if (i >= qqinformationzth::getqqidnumber()) {
		cout << "该用户不存在" << endl;
		system("PAUSE");
	}
}

void wxUserzth::deletefriend(wxUserzth &exam) {//删除好友
	system("cls");
	int i, number;
	cout << "输入需要删除的好友编号";
	cin >> number;
	i = number;
	if (wxinformationzth::getwxfriendlist(exam.wxID, i) == 1) {
		wxinformationzth::change0wxfriendlist(exam.wxID, i);
		cout << "你与" << number << "号好友关系已删除" << endl;
		system("PAUSE");
	}
	else if (wxinformationzth::getwxfriendlist(exam.wxID, i) == 0) {
		cout << "你与该好友尚未建立好友关系" << endl;
		system("PAUSE");
	}
}

void qqUserzth::deletefriend(qqUserzth &exam) {//删除好友
	system("cls");
	int i, number;
	cout << "输入需要删除的好友编号";
	cin >> number;
	i = number;
	if (qqinformationzth::getqqfriendlist(exam.qqID, i) == 1) {
		qqinformationzth::change0qqfriendlist(exam.qqID, i);
		cout << "你与" << number << "号好友关系已删除" << endl;
		system("PAUSE");
	}
	else if (qqinformationzth::getqqfriendlist(exam.qqID, i) == 0) {
		cout << "你与该好友尚未建立好友关系" << endl;
		system("PAUSE");
	}
}

void wxUserzth::findfriend(wxUserzth &exam) {//找到所有好友
	system("cls");
	int i, number = 0;
	for (i = 0;i < wxinformationzth::getwxidnumber();i++) {
		if ((wxinformationzth::getwxfriendlist(exam.wxID, i) == 1) && (wxinformationzth::getwxfriendlist(i, exam.wxID) == 0)) {
			cout << "你与" << i << "号已建立单边好友关系" << endl;
			number++;
		}
		else if ((wxinformationzth::getwxfriendlist(exam.wxID, i) == 1) && (wxinformationzth::getwxfriendlist(i, exam.wxID) == 1) && (i != exam.wxID)) {
			cout << "你与" << i << "号已建立双边好友关系" << endl;
			number++;
		}
	}
	if (number == 0) {
		cout << "你未与任何人建立好友关系" << endl;
	}
	system("PAUSE");
}

void qqUserzth::findfriend(qqUserzth &exam) {//找到所有好友
	system("cls");
	int i, number = 0;
	for (i = 0;i < qqinformationzth::getqqidnumber();i++) {
		if ((qqinformationzth::getqqfriendlist(exam.qqID, i) == 1) && (qqinformationzth::getqqfriendlist(i, exam.qqID) == 0)) {
			cout << "你与" << i << "号已建立单边好友关系" << endl;
			number++;
		}
		else if ((qqinformationzth::getqqfriendlist(exam.qqID, i) == 1) && (qqinformationzth::getqqfriendlist(i, exam.qqID) == 1) && (i != exam.qqID)) {
			cout << "你与" << i << "号已建立双边好友关系" << endl;
			number++;
		}
	}
	if (number == 0) {
		cout << "你未与任何人建立好友关系" << endl;
	}
	system("PAUSE");
}

int wxUserzth::creategroup(wxUserzth &exam) {//创群
	int  number;

	cout << "你想创建一个新群？" << endl;
	wxinformationzth::change1wxgrouplist(exam.wxID, wxinformationzth::getwxgroupnumber());//竖行为用户，行为群号
	number = wxinformationzth::getwxgroupnumber() + 1001;
	cout << "群号为" << number << "的群已建立" << endl;
	wxinformationzth::change3wxlevel(exam.wxID, wxinformationzth::getwxgroupnumber());
	wxinformationzth::changewxgroupnumber(1);
	getchar();
	return number;
}

int qqUserzth::creategroup(qqUserzth &exam) {//创群
	int  number;

	cout << "你想创建一个新群？" << endl;
	qqinformationzth::change1qqgrouplist(exam.qqID, qqinformationzth::getqqgroupnumber());//竖行为用户，行为群号
	number = qqinformationzth::getqqgroupnumber() + 1001;
	cout << "群号为" << number << "的群已建立" << endl;
	qqinformationzth::change3qqlevel(exam.qqID, qqinformationzth::getqqgroupnumber());
	qqinformationzth::changeqqgroupnumber(1);
	getchar();
	return number;
}

void wxUserzth::findjoinin(wxUserzth &exam) {
	int i, m, number = 0;
	for (i = 0;i < wxinformationzth::getwxgroupnumber();i++) {
		if (wxinformationzth::getwxjoinin(exam.wxID, i)) {
			cout << "你被邀请进入" << i + 1001 << "号群" << endl;
			cout << "是否进入该群？1-进入，2-不进入，保留进入资格3-不进入，放弃进入资格（-1退出)" << endl;
			cin >> m;
			if (m == 1) {
				wxinformationzth::change1wxgrouplist(exam.wxID, i);
				cout << "你已经进入了" << i + 1001 << "号群";
			}
			if (m == 2) {
				cout << "推荐保持现状" << endl;
			}
			if (m == 3) {
				wxinformationzth::change0wxjoinin(exam.wxID, i);
				cout << "你已放弃进入资格" << endl;
			}
			number++;
		}
	}
	if (number == 0) {
		cout << "你未被任何人邀请入群" << endl;
	}
}

void qqUserzth::findjoinin(qqUserzth &exam) {//加群
	int i, number;
	cout << "你想加入几号群？（10XX）";
	cin >> number;
	i = number - 1 - 1000;
	if (i > qqinformationzth::getqqgroupnumber() - 1) {
		cout << "该群还未建立" << endl;
	}
	else if (i >= 0 && i <= qqinformationzth::getqqgroupnumber() - 1 && qqinformationzth::getqqgrouplist(exam.qqID, i) != 1) {
		qqinformationzth::change1qqjoinin(exam.qqID, qqinformationzth::getqqgroupnumber() - 1);
		cout << "你已申请加入" << number << "号群";
	}
	else if (i >= 0 && i < qqinformationzth::getqqgroupnumber() - 1 && qqinformationzth::getqqgrouplist(exam.qqID, i) == 1) {
		cout << "你已经在该群内，请勿重复添加" << endl;
	}
	else if (i < 0) {
		cout << "不存在该群" << endl;
	}
}

void wxUserzth::findgroup(wxUserzth &exam) {//查群
	int i, number = 0;
	for (i = 0;i < wxinformationzth::getwxgroupnumber();i++) {
		if (wxinformationzth::getwxgrouplist(exam.wxID, i) == 1) {
			cout << "你在" << i + 1001 << "号群内" << endl;
			number++;
		}
	}
	if (number == 0) {
		cout << "你没有加入任何群" << endl;
	}
}

void qqUserzth::findgroup(qqUserzth &exam) {//查群
	int i, number = 0;
	for (i = 0;i < qqinformationzth::getqqgroupnumber();i++) {
		if (qqinformationzth::getqqgrouplist(exam.qqID, i) == 1) {
			cout << "你在" << i + 1001 << "号群内" << endl;
			number++;
		}
	}
	if (number == 0) {
		cout << "你没有加入任何群" << endl;
	}
}

void findwxgroupmember(int i) {
	int f;
	int number = i - 1001;
	if (number < wxinformationzth::getwxgroupnumber() && number >= 0) {
		cout << i << "群" << endl;
		for (f = 0;f < wxinformationzth::getwxidnumber();f++) {
			if (wxinformationzth::getwxgrouplist(f, number) == 1) {
				cout << f << "号成员在群内" << ",其群内等级为";
				if (wxinformationzth::getwxlevel(f, number) == 1) {
					cout << "群员" << endl;
				}
				if (wxinformationzth::getwxlevel(f, number) == 3) {
					cout << "群主" << endl;
				}
			}
		}
	}
	else if (1) {
		cout << "不存在该群号" << endl;
	}
}

void findqqgroupmember(int i) {
	int f;
	int number = i - 1001;
	if (number < qqinformationzth::getqqgroupnumber() && number >= 0) {
		cout << i << "群" << endl;
		for (f = 0;f < qqinformationzth::getqqidnumber();f++) {
			if (qqinformationzth::getqqgrouplist(f, number) == 1) {
				cout << f << "号成员在群内" << ",其群内等级为";
				if (qqinformationzth::getqqlevel(f, number) == 1) {
					cout << "群员" << endl;
				}
				if (qqinformationzth::getqqlevel(f, number) == 3) {
					cout << "群主" << endl;
				}
			}
		}
	}
	else if (1) {
		cout << "不存在该群号" << endl;
	}
}

void wxUserzth::groupmanage(wxUserzth &exam, int i) {//i为群号//群管理
	int m, p, q, t;//m记录数组位置，p为踢出成员编号，q为循环变量,t为加入是否同意
	m = i - 1001;
	int n;
	if (m > wxinformationzth::getwxgroupnumber() - 1) {
		cout << "该群还未建立" << endl;
		return;
	}
	if (wxinformationzth::getwxgrouplist(exam.wxID, m) == 0) {
		cout << "你未加入此群" << endl;
		return;
	}
	if (m <= wxinformationzth::getwxgroupnumber() - 1) {//-----------------------------------------------------------------------------1
		if (wxinformationzth::getwxlevel(exam.wxID, m) == 1) {//---------------------------------------------------------------------------2
		wxlevel1start:
			cout << "按1邀请用户进入，按2退出群，按3返回主菜单" << endl;
			cin >> n;
			if (n == 1) {
				cout << "你希望邀请的用户是：" << endl;
				cin >> n;
				if (wxinformationzth::getwxjoinin(n, m) == 0 && wxinformationzth::getwxgrouplist(n, m) != 1 && n >= 0 && n < wxinformationzth::getwxidnumber()) {
					wxinformationzth::change1wxjoinin(exam.wxID, m);
					cout << "你已邀请" << n << "号用户入群" << endl;
					system("PAUSE");
				}
				else if (wxinformationzth::getwxjoinin(n, m) == 1) {
					cout << "该用户已被人邀请进入该群" << endl;
					system("PAUSE");
				}
				else if (wxinformationzth::getwxgrouplist(n, m) == 1) {
					cout << "该用户已在群内" << endl;
					system("PAUSE");
				}
				else if (n < 0 && n >= wxinformationzth::getwxidnumber()) {
					cout << "该用户不存在" << endl;
					system("PAUSE");
				}
				goto wxlevel1start;
			}
			if (n == 2) {
				wxinformationzth::change0wxgrouplist(exam.wxID, m);
				cout << "你已退出" << i << "号群" << endl;
				wxinformationzth::change0wxlevel(exam.wxID, m);
			}
			if (n == 3) {
				return;
			}
		}
		if (wxinformationzth::getwxlevel(exam.wxID, m) == 3) {//--------------------------------------------------------------------2
		wxlevelstart:
			int b = 0;
			system("cls");
			cout << "按1换群主，按2邀请用户入群，按3踢出群成员，按4退出群，按5返回主菜单" << endl;
			cin >> n;
			if (n == 1) {//----------------------------------------------------------------------------------------------3
				cout << "你想晋升为群主的用户是：（你将降为管理员）：";
				findwxgroupmember(i);
				cin >> n;
				if (wxinformationzth::getwxgrouplist(n, m) == 0) {//-------------------------------------------------------------------4
					cout << "该用户尚未加入该群";
					system("PAUSE");
					goto wxlevelstart;
				}
				else if (wxinformationzth::getwxgrouplist(n, m) == 1 && wxinformationzth::getwxlevel(n, m) == 3) {
					cout << "你已经是该群的群主" << endl;
					system("PAUSE");
					goto wxlevelstart;
				}
				else if (wxinformationzth::getwxgrouplist(n, m) == 1) {
					cout << "编号为" << n << "的用户升为了群主" << endl;
					wxinformationzth::change3wxlevel(n, m);
					wxinformationzth::change1wxlevel(exam.wxID, m);
					system("PAUSE");
					goto wxlevelstart;
				}
			}
			if (n == 2) {
				cout << "你希望邀请的用户是：" << endl;
				cin >> n;
				if (wxinformationzth::getwxjoinin(n, m) == 0 && wxinformationzth::getwxgrouplist(n, m) != 1 && n >= 0 && n < wxinformationzth::getwxidnumber()) {
					wxinformationzth::change1wxjoinin(n, m);
					cout << "你已邀请" << n << "号用户入群" << endl;
					system("PAUSE");
				}
				else if (wxinformationzth::getwxjoinin(n, m) == 1) {
					cout << "该用户已被人邀请进入该群" << endl;
					system("PAUSE");
				}
				else if (wxinformationzth::getwxgrouplist(n, m) == 1) {
					cout << "该用户已在群内" << endl;
					system("PAUSE");
				}
				else if (n < 0 && n >= wxinformationzth::getwxidnumber()) {
					cout << "该用户不存在" << endl;
					system("PAUSE");
				}
				goto wxlevelstart;
			}
			if (n == 3) {
				cout << "请输入需要踢出的成员编号：";
				findwxgroupmember(i);
				cin >> p;
				if (wxinformationzth::getwxgrouplist(p, m) == 1 && p != exam.wxID) {
					wxinformationzth::change0wxgrouplist(p, m);
					cout << "成员" << p << "已踢出";
					system("PAUSE");
					goto wxlevelstart;
				}
				else if (wxinformationzth::getwxgrouplist(p, m) == 0) {
					cout << "该用户不在群内" << endl;
					system("PAUSE");
					goto wxlevelstart;
				}
				else if (p == exam.wxID) {
					cout << "你不能踢出自己" << endl;
					system("PAUSE");
					goto wxlevelstart;
				}
			}
			if (n == 4) {
				wxinformationzth::change0wxgrouplist(exam.wxID, m);
				cout << "你已退出" << i << "号群" << endl;
				wxinformationzth::change0wxlevel(exam.wxID, m);
				for (q = 0;q < wxinformationzth::getwxidnumber();q++) {
					if (wxinformationzth::getwxlevel(q, m) == 1) {
						wxinformationzth::change3wxlevel(q, m);
						cout << "编号为" << q << "的用户已从群员升为群主";
						break;
					}
				}
				system("PAUSE");
				return;
			}
			if (n == 5) {
				return;
			}

		}
	}
}

void qqUserzth::groupmanage(qqUserzth &exam, int i) {//i为群号//群管理
	int m, p, q, t;//m记录数组位置，p为踢出成员编号，q为循环变量,t为加入是否同意
	m = i - 1001;
	int n;
	if (m > qqinformationzth::getqqgroupnumber() - 1) {
		cout << "该群还未建立" << endl;
		return;
	}
	if (qqinformationzth::getqqgrouplist(exam.qqID, m) == 0) {
		cout << "你未加入此群" << endl;
		return;
	}
	if (m <= qqinformationzth::getqqgroupnumber() - 1) {
		if (qqinformationzth::getqqlevel(exam.qqID, m) == 1) {
			cout << "按1退出群，按2返回主菜单" << endl;
			cin >> n;
			if (n == 1) {
				qqinformationzth::change0qqgrouplist(exam.qqID, m);
				cout << "你已退出" << i << "号群" << endl;
				qqinformationzth::change0qqlevel(exam.qqID, m);
			}
			if (n == 2) {
				return;
			}
		}
		if (qqinformationzth::getqqlevel(exam.qqID, m) == 2) {
		qqlevelstart:
			int b = 0;//申请个数
			system("cls");
			cout << "按1处理入群申请，按2踢出群成员，按3退出群，按4返回主菜单" << endl;
			cin >> n;
			if (n == 1) {
				for (q = 0;q < qqinformationzth::getqqidnumber();q++) {
					if (qqinformationzth::getqqjoinin(q, m) == 1) {
						cout << "编号为" << q << "的用户申请加入群" << endl;
						cout << "同意按1，不同意按0" << endl;
						cin >> t;
						if (t == 0) {
							qqinformationzth::change0qqjoinin(q, m);
							cout << "编号为" << q << "的用户已被你拒绝入群";
							b++;
						}
						if (t == 1) {
							qqinformationzth::change0qqjoinin(q, m);
							qqinformationzth::change1qqgrouplist(q, m);
							cout << "允许编号为" << q << "的用户加入群";
							qqinformationzth::change1qqlevel(q, m);//初始化等级为群员
							b++;
						}
					}
				}
				if (b == 0) {
					cout << "没有人申请进入" << endl;
					system("PAUSE");
					goto qqlevelstart;
				}
				else if (b != 0) {
					system("PAUSE");
					goto qqlevelstart;
				}
			}
			if (n == 2) {
				cout << "请输入需要踢出的成员编号：";
				findqqgroupmember(i);
				cin >> p;
				if (qqinformationzth::getqqgrouplist(p, m) == 1 && p != exam.qqID&&qqinformationzth::getqqlevel(p, m) == 1) {
					qqinformationzth::change0qqgrouplist(p, m);
					cout << "成员" << p << "已踢出";
					system("PAUSE");
					goto qqlevelstart;
				}
				else if (qqinformationzth::getqqgrouplist(p, m) == 1 && p != exam.qqID&&qqinformationzth::getqqlevel(p, m) != 1) {
					cout << "你无法踢出管理员或群主" << endl;
					system("PAUSE");
					goto qqlevelstart;
				}
				else if (qqinformationzth::getqqgrouplist(p, m) == 0) {
					cout << "该用户不在群内" << endl;
					system("PAUSE");
					goto qqlevelstart;
				}
				else if (p == exam.qqID) {
					cout << "你不能踢出自己" << endl;
					system("PAUSE");
					goto qqlevelstart;
				}
			}
			if (n == 3) {
				qqinformationzth::change0qqgrouplist(exam.qqID, m);
				cout << "你已退出" << i << "号群" << endl;
				qqinformationzth::change0qqlevel(exam.qqID, m);
				system("PAUSE");
				return;
			}
			if (n == 4) {
				return;
			}
		}
		if (qqinformationzth::getqqlevel(exam.qqID, m) == 3) {
		qqlevel2start:
			int b = 0;
			system("cls");
			cout << "按1处理入群申请，按2管理群员等级，按3踢出群成员或管理员，按4退出群，按5返回主菜单" << endl;
			cin >> n;
			if (n == 1) {
				for (q = 0;q < qqinformationzth::getqqidnumber();q++) {
					if (qqinformationzth::getqqjoinin(q, m) == 1) {
						cout << "编号为" << q << "的用户申请加入群" << endl;
						cout << "同意按1，不同意按0" << endl;
						cin >> t;
						if (t == 0) {
							qqinformationzth::change0qqjoinin(q, m);
							cout << "编号为" << q << "的用户已被你拒绝入群";
							b++;
						}
						if (t == 1) {
							qqinformationzth::change0qqjoinin(q, m);
							qqinformationzth::change1qqgrouplist(q, m);
							cout << "允许编号为" << q << "的用户加入群";
							qqinformationzth::change1qqlevel(q, m);//初始化等级为群员
							b++;
						}
					}
				}
				if (b == 0) {
					cout << "没有人申请进入" << endl;
					system("PAUSE");
					goto qqlevel2start;
				}
				else if (b != 0) {
					system("PAUSE");
					goto qqlevel2start;
				}
			}
			if (n == 2) {
			qqlevel3start:
				system("cls");
				cout << "你想对群员进行何种操作？1-升为管理员，2-降为群员,3-升为群主，自己降级为管理员，4-返回" << endl;
				cin >> n;
				if (n == 1) {
					cout << "你想晋升的群员编号是：" << endl;
					findqqgroupmember(i);
					cin >> n;
					if (qqinformationzth::getqqgrouplist(n, m) == 0) {
						cout << "该用户尚未加入该群";
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (n == exam.qqID) {
						cout << "你已是群主" << endl;
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (qqinformationzth::getqqgrouplist(n, m) == 1 && qqinformationzth::getqqlevel(n, m) == 2) {
						cout << "该用户已经是该群的管理员" << endl;
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (qqinformationzth::getqqgrouplist(n, m) == 1 && qqinformationzth::getqqlevel(n, m) == 1) {
						cout << "编号为" << n << "的用户升为了管理员" << endl;
						qqinformationzth::change2qqlevel(n, m);
						system("PAUSE");
						goto qqlevel3start;
					}
				}
				if (n == 2) {
					cout << "你想降为群员的用户编号为：";
					findqqgroupmember(i);
					cin >> n;
					if (qqinformationzth::getqqgrouplist(n, m) == 0) {
						cout << "该用户尚未加入该群";
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (n == exam.qqID) {
						cout << "你已是群主" << endl;
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (qqinformationzth::getqqgrouplist(n, m) == 1 && qqinformationzth::getqqlevel(n, m) == 1) {
						cout << "该用户已经是该群的群员" << endl;
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (qqinformationzth::getqqgrouplist(n, m) == 1 && qqinformationzth::getqqlevel(n, m) == 2) {
						cout << "编号为" << n << "的用户降为了群员" << endl;
						qqinformationzth::change1qqlevel(n, m);
						system("PAUSE");
						goto qqlevel3start;
					}
				}
				if (n == 3) {
					cout << "你想晋升为群主的用户是：（你将降为管理员）：";
					findqqgroupmember(i);
					cin >> n;
					if (qqinformationzth::getqqgrouplist(n, m) == 0) {
						cout << "该用户尚未加入该群";
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (qqinformationzth::getqqgrouplist(n, m) == 1 && qqinformationzth::getqqlevel(n, m) == 3) {
						cout << "你已经是该群的群主" << endl;
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (qqinformationzth::getqqgrouplist(n, m) == 1) {
						cout << "编号为" << n << "的用户升为了群主" << endl;
						qqinformationzth::change3qqlevel(n, m);
						qqinformationzth::change2qqlevel(exam.qqID, m);
						system("PAUSE");
						goto qqlevelstart;
					}
				}
				if (n == 4) {
					return;
				}
			}
			if (n == 3) {
				cout << "请输入需要踢出的成员编号：";
				findqqgroupmember(i);
				cin >> p;
				if (qqinformationzth::getqqgrouplist(p, m) == 1 && p != exam.qqID) {
					qqinformationzth::change0qqgrouplist(p, m);
					cout << "成员" << p << "已踢出";
					system("PAUSE");
					goto qqlevel2start;
				}
				else if (qqinformationzth::getqqgrouplist(p, m) == 0) {
					cout << "该用户不在群内" << endl;
					system("PAUSE");
					goto qqlevel2start;
				}
				else if (p == exam.qqID) {
					cout << "你不能踢出自己" << endl;
					system("PAUSE");
					goto qqlevel2start;
				}
			}
			if (n == 4) {
				qqinformationzth::change0qqgrouplist(exam.qqID, m);
				cout << "你已退出" << i << "号群" << endl;
				qqinformationzth::change0qqlevel(exam.qqID, m);
				for (q = 0;q < qqinformationzth::getqqidnumber();q++) {
					if (qqinformationzth::getqqlevel(q, m) == 2) {
						qqinformationzth::change3qqlevel(q, m);
						cout << "编号为" << q << "的用户已从管理员升为群主";
						break;
					}
					if (qqinformationzth::getqqlevel(q, m) == 1) {
						qqinformationzth::change3qqlevel(q, m);
						cout << "由于没有管理员，编号为" << q << "的用户已从群员升为群主";
break;
					}
				}
				system("PAUSE");
				return;
			}
			if (n == 5) {
				return;
			}

		}
	}
}

int link[100][100] = { 0 };
void linkqq(wxUserzth exam) {//wx竖行
	int n, i,number=0;
	cout << "你想绑定哪个qq号(-1退出);" << endl;
	while (1) {
		cin >> n;
		if (n == -1) {
			return;
		}
		if (n < qqinformationzth::getqqidnumber()) {//判断是否已经有该号
			for (i = 0;i < wxinformationzth::getwxidnumber();i++) {
				if (link[n][i] == 1 && i != exam.wxID) {
					cout << "该账号已被绑定" << endl;
					number++;
					return;
				}
				else if (link[n][exam.wxID] == 1) {
					cout << "你已经绑定了该qq账号" << endl;
					system("PAUSE");
					return;
				}

			}
			for (i = 0;i < qqinformationzth::getqqidnumber();i++) {
				if (link[i][exam.wxID] == 1) {
					cout << "你已经绑定了一个账号" << endl;
					system("PAUSE");
					return;
				}
			}
			if (link[n][exam.wxID] == 0&&number==0) {
				link[n][exam.wxID] = 1;
				cout << "已绑定qq编号为" << n << "的用户" << endl;
				exam.qqID = n;
				system("PAUSE");
				return;
			}
		}
		else if (1) {
			cout << "你输入的qq用户不存在" << endl;
		}
	}
}
void linkwx(qqUserzth exam) {//wx竖行
	int n, i,number=0;
	cout << "你想绑定哪个微信号(-1退出);" << endl;
	while (1) {
		cin >> n;
		if (n == -1) {
			return;
		}
		if (n < wxinformationzth::getwxidnumber()) {//判断是否已经有该号
			for (i = 0;i < qqinformationzth::getqqidnumber();i++) {
				if (link[i][n] == 1 && i != exam.qqID) {
					cout << "该账号已被绑定" << endl;
					system("PAUSE");
					return;
				}
				else if (link[exam.qqID][n] == 1) {
					cout << "你已经绑定了该微信账号" << endl;
					system("PAUSE");
					return;
				}

			}
			for (i = 0;i < wxinformationzth::getwxidnumber();i++) {
				if (link[exam.qqID][i] == 1) {
					cout << "你已经绑定了一个账号" << endl;
					system("PAUSE");
					return;
				}
			}
			if (link[exam.qqID][n] == 0&&number==0) {
				link[exam.qqID][n] = 1;
				cout << "已绑定微信编号为" << n << "的用户" << endl;
				system("PAUSE");
				return;
			}
		}
		else if (1) {
			cout << "你输入的微信用户不存在" << endl;
		}
	}
}
void wxUserzth::addotherfriend(wxUserzth &exam) {//1
	int i, j, number=0,m,q;
	for (i = 0;i < qqinformationzth::getqqidnumber();i++) {//2
		if (link[i][exam.wxID] == 1) {//3
			q = i;
			number++;
		}//3
	}
	if (number>=0) {//4
		cout << "你列表里的微信好友已开通qq的有：" << endl;
		
		for (i = 0;i < wxinformationzth::getwxidnumber();i++) {//5
			if (wxinformationzth::getwxfriendlist(exam.wxID, i) == 1) {//6
				for (j = 0;j < qqinformationzth::getqqidnumber();j++) {//7
					if (link[j][i] == 1) {//8
                   cout << "你的" << i << "号微信好友已开通qq，其qq用户号为：" << j << endl;//
				   if (qqinformationzth::getqqfriendlist(q, j) == 0) {
					   cout << "是否添加？1-是，2-否" << endl;
					   cin >> m;
					   if (m == 1) {
						   qqinformationzth::change1qqfriendlist(q, j);
						   cout << "添加成功" << endl;
					   }
				   }
				   else if (qqinformationzth::getqqfriendlist(q, j) == 1) {
					   cout << "已添加" << endl;
				   }
					}//8
				}//7
			}//6
		}//5
	}//4
	else if (number==0) {//9
		cout << "你未开通qq" << endl;
	}//9
}

void qqUserzth::addotherfriend(qqUserzth &exam) {//1
	int i, j, number = 0,m,q;
	for (i = 0;i < wxinformationzth::getwxidnumber();i++) {//2
		if (link[exam.qqID][i] == 1) {//3
			q = i;
			number++;
		}//3
	}
	if (number >= 0) {//4
		cout << "你列表里的qq好友已开通微信的有：" << endl;

		for (i = 0;i <qqinformationzth::getqqidnumber();i++) {//5
			if (qqinformationzth::getqqfriendlist(exam.qqID, i) == 1) {//6
				for (j = 0;j < wxinformationzth::getwxidnumber();j++) {//7
					if (link[j][i] == 1) {//8
						cout << "你的" << i << "号qq好友已开通微信，其微信用户号为：" << j << endl;//
						if (wxinformationzth::getwxfriendlist(q, j) == 0) {
							cout << "是否添加？1-是，2-否" << endl;
							cin >> m;
							if (m == 1) {
								wxinformationzth::change1wxfriendlist(q, j);
								cout << "添加成功" << endl;
							}
						}
						else if (wxinformationzth::getwxfriendlist(q, j) == 1) {
							cout << "已添加" << endl;
						}
					}//8
				}//7
			}//6
		}//5
	}//4
	else if (number == 0) {//9
		cout << "你未开通微信" << endl;
	}//9
}


void qqdiscuss(qqUserzth &exam) {//临时讨论组
	int j, p, n;
	cout << "你想创建哪个群的临时讨论组？" << endl;
	exam.findgroup(exam);
	cin >> n;
	j = exam.creategroup(exam);
	findqqgroupmember(n);
	cout << "你需要加入哪些成员进入讨论组？（回-1结束输入退出）" << endl;
	while (1) {
		cin >> p;
		if (qqinformationzth::getqqgrouplist(p, n - 1001) == 1 && qqinformationzth::getqqgrouplist(p, j - 1001) != 1) {
			qqinformationzth::change1qqgrouplist(p, j - 1001);
			cout << "成员" << p << "已加入讨论群" << endl;
		}
		else if (qqinformationzth::getqqgrouplist(p, n - 1001) == 1 && qqinformationzth::getqqgrouplist(p, j - 1001) == 1) {
			cout << "成员" << p << "已在讨论群内" << endl;
		}
		else if (1) {
			cout << "该用户还未创建" << endl;
		}

		if (p == -1) {
			break;
		}
	}
}

void wxUserzth::menu(wxUserzth &exam) {
	int n;
wxstart:
	system("cls");
	cout << "1-查看好友操作列表" << endl;
	cout << "2-查看群操作列表" << endl;
	cout << "3-修改个人信息" << endl;
	cout << "4-绑定qq账号" << endl;
	cout << "5-返回wx平台" << endl;
	cin >> n;
	if (n == 1) {
	wxfriendstart:
		system("cls");
		cout << "你想对好友列表进行什么操作？" << endl;
		cout << "1-添加好友" << endl;
		cout << "2-删除好友" << endl;
		cout << "3-查看好友列表" << endl;
		cout << "4-添加好友其他平台的账号" << endl;
		cout << "5-返回菜单" << endl;
		cin >> n;
		if (n == 1) {
			exam.addfriend(exam);
			goto wxfriendstart;
		}
		if (n == 2) {
			exam.deletefriend(exam);
			goto wxfriendstart;
		}
		if (n == 3) {
			exam.findfriend(exam);
			goto wxfriendstart;
		}
		if (n == 4) {
			system("cls");
			exam.addotherfriend(exam);
			system("PAUSE");
			goto wxfriendstart;
		}
		if (n == 5) {
			goto wxstart;
		}
	}

	if (n == 2) {
	wxgroupstart:
		system("cls");
		cout << "1-添加群" << endl;
		cout << "2-创建新群" << endl;
		cout << "3-管理群" << endl;
		cout << "4-查看群" << endl;
		cout << "5-返回菜单" << endl;
		cin >> n;
		if (n == 1) {
			system("cls");
			exam.findjoinin(exam);
			system("PAUSE");
			goto wxgroupstart;
		}
		if (n == 2) {
			system("cls");
			exam.creategroup(exam);
			system("PAUSE");
			goto wxgroupstart;

		}
		if (n == 3) {
			system("cls");
			cout << "目前已加入的群有：" << endl;
			exam.findgroup(exam);
			cout << "你想进入哪个群的管理？" << endl;
			cin >> n;
			system("cls");
			exam.groupmanage(exam, n);
			system("PAUSE");
			goto wxgroupstart;
		}
		if (n == 4) {
			system("cls");
			cout << "目前已加入的群有：" << endl;
			exam.findgroup(exam);
			cout << "你想查看成员的群为：" << endl;
			cin >> n;
			system("cls");
			findwxgroupmember(n);
			system("PAUSE");
			goto wxgroupstart;
		}
		if (n == 5) {
			goto wxstart;
		}
	}
	if (n == 3) {
	wxchangestart:
		system("cls");
		string kk;
		int ii;
		cout << "你目前的资料为：" << endl;
		cout << "昵称为" << exam.wxnickname << endl;
		cout << "年龄为" << exam.wxage << endl;
		cout << "生日为" << exam.wxbirthday << endl;
		cout << "所在地为" << exam.wxlocal << endl;
		cout << "你想修改的资料是：(-1返回）" << endl;
		cout << "1-昵称" << endl;
		cout << "2-年龄" << endl;
		cout << "3-出生时间" << endl;
		cout << "4-所在地" << endl;
		cin >> n;
		if (n == 1) {
			system("cls");
			cout << "现在的昵称为" << exam.wxnickname << endl;
			cout << "你想修改为:" << endl;
			cin >> kk;
			exam.wxnickname = kk;
			cout << "修改完成，现在昵称为:  " << exam.wxnickname << endl;
		}
		if (n == 2) {
			system("cls");
			cout << "现在的年龄为" << exam.wxage << endl;
			cout << "你想修改为:" << endl;
			cin >> ii;
			exam.wxage = ii;
			cout << "修改完成，现在年龄为:  " << exam.wxage << endl;
		}
		if (n == 3) {
			system("cls");
			cout << "现在的出生日期为" << exam.wxbirthday << endl;
			cout << "你想修改为:" << endl;
			cin >> ii;
			exam.wxbirthday = ii;
			cout << "修改完成，现在出生日期为:  " << exam.wxbirthday << endl;
		}
		if (n == 4) {
			system("cls");
			cout << "现在的所在地为" << exam.wxlocal << endl;
			cout << "你想修改为:" << endl;
			cin >> kk;
			exam.wxlocal = kk;
			cout << "修改完成，现在所在地为:  " << exam.wxlocal << endl;
		}
		if (n == -1) {
			goto wxstart;
		}
		system("PAUSE");
		goto wxchangestart;
	}
	if (n == 4) {
		system("cls");
		linkqq(exam);
		goto wxstart;
	}
	if (n == 5) {
		return;
	}

}

void qqUserzth::menu(qqUserzth &exam) {
	int n;
    qqstart:
	system("cls");
	cout << "1-查看好友操作列表" << endl;
	cout << "2-查看群操作列表" << endl;
	cout << "3-修改个人信息" << endl;
	cout << "4-绑定微信账号" << endl;
	cout << "5-返回qq平台" << endl;
	cin >> n;
	if (n == 1) {
	qqfriendstart:
		system("cls");

		cout << "你想对好友列表进行什么操作？" << endl;
		cout << "1-添加好友" << endl;
		cout << "2-删除好友" << endl;
		cout << "3-查看好友列表" << endl;
		cout << "4-添加好友其他平台的账号" << endl;
		cout << "5-返回菜单" << endl;
		cin >> n;
		if (n == 1) {
			exam.addfriend(exam);
			goto qqfriendstart;
		}
		if (n == 2) {
			exam.deletefriend(exam);
			goto qqfriendstart;
		}
		if (n == 3) {
			exam.findfriend(exam);
			goto qqfriendstart;
		}
		if(n==4){
		system("cls");
		exam.addotherfriend(exam);
		system("PAUSE");
		goto qqfriendstart;
	}
		if (n == 5) {
			goto qqstart;
		}
	}

	if (n == 2) {
	qqgroupstart:
		system("cls");
		cout << "1-添加群" << endl;
		cout << "2-创建新群" << endl;
		cout << "3-管理群" << endl;
		cout << "4-查看群" << endl;
		cout << "5-返回菜单" << endl;
		cin >> n;
		if (n == 1) {
			system("cls");
			exam.findjoinin(exam);
			system("PAUSE");
			goto qqgroupstart;
		}
		if (n == 2) {
			system("cls");
			cout << "1-创建新永久群" << endl;
			cout << "2-创建新讨论组" << endl;
			cout << "3-返回" << endl;
			cin >> n;
			if (n == 1) {
				system("cls");
				exam.creategroup(exam);
				system("PAUSE");
				goto qqgroupstart;
			}
			if (n == 2) {
				system("cls");
				qqdiscuss(exam);
				goto qqgroupstart;
			}
			if (n == 3) {
				goto qqgroupstart;
			}
		}
		if (n == 3) {
			system("cls");
			cout << "目前已加入的群有：" << endl;
			exam.findgroup(exam);
			cout << "你想进入哪个群的管理？" << endl;
			cin >> n;
			system("cls");
			exam.groupmanage(exam, n);
			system("PAUSE");
			goto qqgroupstart;
		}
		if (n == 4) {
			system("cls");
			cout << "目前已加入的群有：" << endl;
			exam.findgroup(exam);
			cout << "你想查看成员的群为：" << endl;
			cin >> n;
			system("cls");
			findqqgroupmember(n);
			system("PAUSE");
			goto qqgroupstart;
		}
		if (n == 5) {
			goto qqstart;
		}
	}
	if (n == 3) {
	qqchangestart:
		system("cls");
		string kk;
		int ii;
		cout << "你目前的资料为：" << endl;
		cout << "昵称为" << exam.qqnickname << endl;
		cout << "年龄为" << exam.qqage << endl;
		cout << "生日为" << exam.qqbirthday << endl;
		cout << "所在地为" << exam.qqlocal << endl;
		cout << "你想修改的资料是：(-1返回）" << endl;
		cout << "1-昵称" << endl;
		cout << "2-年龄" << endl;
		cout << "3-出生时间" << endl;
		cout << "4-所在地" << endl;
		cin >> n;
		if (n == 1) {
			system("cls");
			cout << "现在的昵称为" << exam.qqnickname << endl;
			cout << "你想修改为:" << endl;
			cin >> kk;
			exam.qqnickname = kk;
			cout << "修改完成，现在昵称为:  " << exam.qqnickname << endl;
		}
		if (n == 2) {
			system("cls");
			cout << "现在的年龄为" << exam.qqage << endl;
			cout << "你想修改为:" << endl;
			cin >> ii;
			exam.qqage = ii;
			cout << "修改完成，现在年龄为:  " << exam.qqage << endl;
		}
		if (n == 3) {
			system("cls");
			cout << "现在的出生日期为" << exam.qqbirthday << endl;
			cout << "你想修改为:" << endl;
			cin >> ii;
			exam.qqbirthday = ii;
			cout << "修改完成，现在出生日期为:  " << exam.qqbirthday << endl;
		}
		if (n == 4) {
			system("cls");
			cout << "现在的所在地为" << exam.qqlocal << endl;
			cout << "你想修改为:" << endl;
			cin >> kk;
			exam.qqlocal = kk;
			cout << "修改完成，现在所在地为:  " << exam.qqlocal << endl;
		}
		if (n == -1) {
			goto qqstart;
		}
		system("PAUSE");
		goto qqchangestart;
	}
	if (n == 4) {
		if (n == 4) {
			system("cls");
			linkwx(exam);
			goto qqstart;
		}
	}
	if (n == 5) {
		return;
	}
}

void wxloading() {
	while (1) {
		system("cls");
		int pp,n;
		wxUserzth exam;
		cout << "1-登录,2-创建新账号,3-返回" << endl;
		cin >> pp;
		system("cls");

		if (pp == 1) {
			cout << "输入登录编号" << endl;
			cin >> n;
			exam = wxidfind(n);
			cout << "找到用户，准备登录......" << endl;
			system("PAUSE");
			exam.menu(exam);
		}
		else if (pp == 2) {
			cout << "准备创建新用户" << endl;
			cout << "1-创建" << endl;
			cout << "2-返回" << endl;
			cin >> n;
			if (n == 1) {
				cout << "前往注册界面..." << endl;
				system("PAUSE");
				wxUserzthlist[wxinformationzth::getwxidnumber() - 1] = createwx();
				cout << "准备前往登录界面" << endl;
				system("PAUSE");
			}
		}
		if (pp == 3) {
			return;
		}
		else if (pp != 1 && pp != 2&&pp!=3) {
			cout << "输入错误" << endl;
			system("PAUSE");
		}
	}
}

void qqloading() {
	while (1) {
		system("cls");
		int n,pp;
		qqUserzth exam;
		cout << "1-登录,2-创建新账号,3-返回" << endl;
		cin >> pp;
		system("cls");

		if (pp == 1) {
			cout << "输入登录编号" << endl;
			cin >> n;
			exam = qqidfind(n);
			cout << "找到用户，准备登录......" << endl;
			system("PAUSE");
			exam.menu(exam);
		}
		else if (pp == 2) {
			cout << "准备创建新用户" << endl;
			cout << "1-创建" << endl;
			cout << "2-返回" << endl;
			cin >> n;
			if (n == 1) {
				cout << "前往注册界面..." << endl;
				system("PAUSE");
				qqUserzthlist[qqinformationzth::getqqidnumber() - 1] = createqq();
				cout << "准备前往登录界面" << endl;
				system("PAUSE");
			}
		}
		if (pp == 3) {
			return;
		}
		else if (pp != 1 && pp != 2&&pp!=3) {
			cout << "输入错误" << endl;
			system("PAUSE");
		}
	}
}


void example() {
	qqUserzth aa, bb;
	wxUserzth cc, dd;
	qqinformationzth::changeqqidnumber(2);
	wxinformationzth::changewxidnumber(2);
	aa.qqID = 0;
	bb.qqID = 1;
	cc.wxID = 0;
	dd.wxID = 1;
	aa.qqnickname = "zthqq";
	aa.qqage = 19;
	aa.qqbirthday = 20010418;
	aa.qqflag = 1;
	aa.qqlocal = "广州";
	aa.qqyear = 231220;
	bb.qqnickname = "我是谁qq";
	bb.qqage = 222;
	bb.qqbirthday = 20130414;
	bb.qqflag = 1;
	bb.qqlocal = "杭州";
	bb.qqyear = 221134;
	cc.wxnickname = "zthwx";
	cc.wxage = 23;
	cc.wxbirthday = 20190807;
	cc.wxflag = 1;
	cc.wxlocal = "北京";
	cc.wxyear = 122222;
	dd.wxnickname = "我是谁wx";
	dd.wxage = 22;
	dd.wxbirthday = 20030403;
	dd.wxflag = 1;
	dd.wxlocal = "南京";
	dd.wxyear = 190824;
	qqUserzthlist[0] = aa;
	qqUserzthlist[1] = bb;
	wxUserzthlist[0] = cc;
	wxUserzthlist[1] = dd;
	
}
void platform() {
	int n;
	while (1) {
	cout << "软件平台，代码由软件八班zth原创" << endl;
	cout << "1-wx平台" << endl;
	cout << "2-qq平台" << endl;
	cout << "3-其他平台的开通情况" << endl;
		cin >> n;
		if (n == 1) {
			wxloading();
		}
		if (n == 2) {
			qqloading();
		}
		if (n == 3) {
			cout << "1-开通微博" << endl;
			cin >> n;
			if (n != 1) {
				cout << "输入错误" << endl;
				system("PAUSE");
			}
			if (n == 1) {
				cout << "微博 已开通" << endl;
				system("PAUSE");
				system("cls");
			}
		}
	}
}
int main() 
{
	example();
	platform();
	return 0;
}
