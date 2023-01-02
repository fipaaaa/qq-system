#include"用户信息zth.h";
#include"wx信息zth.h";
#include<iostream>
#include<time.h>
#include<fstream>
#pragma warning(disable : 4996);
using namespace std;
wxUser wxuserlist[100];
int getmytime();
wxUser createwx() {
	system("cls");
	wxUser exam;
	exam.wxID = wxinformation::getwxidnumber();//第一个为0
	wxinformation::changewxidnumber(1);//id+1
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
	exam.wxflag=1;
	exam.wxyear = getmytime();
	cout << "wxyear:" << exam.wxyear << endl;
	cout << "注册已完成，请获取你的登录编号:";
	cout << exam.wxID << endl;
	system("PAUSE");
	return exam;
}
wxUser wxidfind(int i) {
	int p;
	for (p = 0;p < wxinformation::getwxidnumber();p++) {
		if (wxuserlist[p].wxID == i) {
			return wxuserlist[p];
		}
	}
	cout << "未找到"<<i<<"号微信用户" << endl;
	system("PAUSE");
}
void wxUser::addfriend(wxUser &exam) {//添加好友
	system("cls");
	int i, number;
	cout << "需要添加的好友编号：";
	cin >> number;//i<100
	i = number;
	if (wxinformation::getwxfriendlist(exam.wxID, i) != 1 && i < wxinformation::getwxidnumber()&&i!=exam.wxID) {
		wxinformation::change1wxfriendlist(exam.wxID, i);//竖行代表当前账户
		cout << "你与" << number << "号好友关系已建立" << endl;
		system("PAUSE");
	}
	else if (i == exam.wxID) {
		cout << "你不能加自己为好友" << endl;
		system("PAUSE");
	}
	else if (wxinformation::getwxfriendlist(exam.wxID, i) == 1) {
		cout << "已建立好友关系，请勿重复操作" << endl;
		system("PAUSE");
	}
	if (i >= wxinformation::getwxidnumber()) {
		cout << "该用户不存在" << endl;
		system("PAUSE");
	}
}
void wxUser::deletefriend(wxUser &exam) {//删除好友
	system("cls");
	int i, number;
	cout << "输入需要删除的好友编号";
	cin >> number;
	i = number;
	if (wxinformation::getwxfriendlist(exam.wxID, i) == 1) {
		wxinformation::change0wxfriendlist(exam.wxID, i);
		cout << "你与" << number << "号好友关系已删除" << endl;
		system("PAUSE");
	}
	else if (wxinformation::getwxfriendlist(exam.wxID, i) == 0) {
		cout << "你与该好友尚未建立好友关系" << endl;
		system("PAUSE");
	}
}
void wxUser::findfriend(wxUser &exam) {//找到所有好友
	system("cls");
	int i, number = 0;
	for (i = 0;i < wxinformation::getwxidnumber();i++) {
		if ((wxinformation::getwxfriendlist(exam.wxID, i) == 1) && (wxinformation::getwxfriendlist(i, exam.wxID) == 0)) {
			cout << "你与" << i << "号已建立单边好友关系" << endl;
			number++;
		}
		else if ((wxinformation::getwxfriendlist(exam.wxID, i) == 1) && (wxinformation::getwxfriendlist(i, exam.wxID) == 1) && (i != exam.wxID)) {
			cout << "你与" << i << "号已建立双边好友关系" << endl;
			number++;
		}
	}
	if (number == 0) {
		cout << "你未与任何人建立好友关系" << endl;
	}
	system("PAUSE");
}
int wxUser::creategroup(wxUser &exam) {//创群
	int  number;

	cout << "你想创建一个新群？" << endl;
	wxinformation::change1wxgrouplist(exam.wxID, wxinformation::getwxgroupnumber());//竖行为用户，行为群号
	number = wxinformation::getwxgroupnumber() + 1001;
	cout << "群号为" << number << "的群已建立" << endl;
	wxinformation::change3wxlevel(exam.wxID, wxinformation::getwxgroupnumber());
	wxinformation::changewxgroupnumber(1);
	getchar();
	return number;
}
void wxUser::findjoinin(wxUser &exam){
	int i, m,number=0;
	for (i = 0;i < wxinformation::getwxgroupnumber();i++) {
		if (wxinformation::getwxjoinin(exam.wxID,i)) {
			cout << "你被邀请进入" << i+1001 << "号群" << endl;
			cout << "是否进入该群？1-进入，2-不进入，保留进入资格3-不进入，放弃进入资格（-1退出)" << endl;
			cin >> m;
			if (m == 1) {
				wxinformation::change1wxgrouplist(exam.wxID, i);
				cout << "你已经进入了" << i + 1001 << "号群";
			}
			if (m == 2) {
				cout << "推荐保持现状" << endl;
			}
			if (m == 3) {
				wxinformation::change0wxjoinin(exam.wxID, i);
				cout << "你已放弃进入资格" << endl;
			}
			number++;
		}
	}
	if (number == 0) {
		cout << "你未被任何人邀请入群" << endl;
	}
}
void wxUser::findgroup(wxUser &exam) {//查群
	int i, number = 0;
	for (i = 0;i < wxinformation::getwxgroupnumber();i++) {
		if (wxinformation::getwxgrouplist(exam.wxID, i) == 1) {
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
	if (number<wxinformation::getwxgroupnumber()&&number>=0) {
		cout << i << "群" << endl;
		for (f = 0;f < wxinformation::getwxidnumber();f++) {
			if (wxinformation::getwxgrouplist(f, number) == 1) {
				cout << f << "号成员在群内" << ",其群内等级为";
				if (wxinformation::getwxlevel(f, number) == 1) {
					cout << "群员" << endl;
				}
				if (wxinformation::getwxlevel(f, number) == 3) {
					cout << "群主" << endl;
				}
			}
		}
	}
	else if (1) {
		cout << "不存在该群号" << endl;
	}
}

void wxUser::groupmanage(wxUser &exam, int i) {//i为群号//群管理
	int m, p, q, t;//m记录数组位置，p为踢出成员编号，q为循环变量,t为加入是否同意
	m = i - 1001;
	int n;
	if (m > wxinformation::getwxgroupnumber() - 1) {
		cout << "该群还未建立" << endl;
		return;
	}
	if (wxinformation::getwxgrouplist(exam.wxID, m) == 0) {
		cout << "你未加入此群" << endl;
		return;
	}
	if (m <= wxinformation::getwxgroupnumber() - 1) {//-----------------------------------------------------------------------------1
		if (wxinformation::getwxlevel(exam.wxID, m) == 1) {//---------------------------------------------------------------------------2
			wxlevel1start:
			cout << "按1邀请用户进入，按2退出群，按3返回主菜单" << endl;
			cin >> n;
			if (n == 1) {
				cout << "你希望邀请的用户是：" << endl;
				cin >> n;
				if (wxinformation::getwxjoinin(n, m) == 0 && wxinformation::getwxgrouplist(n, m) != 1&&n>=0&&n<wxinformation::getwxidnumber()) {
					wxinformation::change1wxjoinin(exam.wxID, m);
					cout << "你已邀请" << n << "号用户入群"<<endl;
					system("PAUSE");
				}
				else if (wxinformation::getwxjoinin(n, m) == 1) {
					cout << "该用户已被人邀请进入该群" << endl;
					system("PAUSE");
				}
				else if (wxinformation::getwxgrouplist(n, m) == 1) {
					cout << "该用户已在群内" << endl;
					system("PAUSE");
				}
				else if (n < 0 && n >= wxinformation::getwxidnumber()) {
					cout << "该用户不存在" << endl;
					system("PAUSE");
				}
				goto wxlevel1start;
			}
			if (n == 2) {
				wxinformation::change0wxgrouplist(exam.wxID, m);
				cout << "你已退出" << i << "号群" << endl;
				wxinformation::change0wxlevel(exam.wxID, m);
			}
			if (n == 3) {
				return;
			}
		}
		if (wxinformation::getwxlevel(exam.wxID, m) == 3) {//--------------------------------------------------------------------2
		wxlevelstart:
			int b = 0;
			system("cls");
			cout << "按1换群主，按2邀请用户入群，按3踢出群成员，按4退出群，按5返回主菜单" << endl;
			cin >> n;
			if (n == 1) {//----------------------------------------------------------------------------------------------3
				cout << "你想晋升为群主的用户是：（你将降为管理员）：";
				findwxgroupmember(i);
				cin >> n;
				if (wxinformation::getwxgrouplist(n, m) == 0) {//-------------------------------------------------------------------4
					cout << "该用户尚未加入该群";
					system("PAUSE");
					goto wxlevelstart;
				}
				else if (wxinformation::getwxgrouplist(n, m) == 1 && wxinformation::getwxlevel(n, m) == 3) {
					cout << "你已经是该群的群主" << endl;
					system("PAUSE");
					goto wxlevelstart;
				}
				else if (wxinformation::getwxgrouplist(n, m) == 1) {
					cout << "编号为" << n << "的用户升为了群主" << endl;
					wxinformation::change3wxlevel(n, m);
					wxinformation::change1wxlevel(exam.wxID, m);
					system("PAUSE");
					goto wxlevelstart;
				}
			}
			if (n == 2) {
				cout << "你希望邀请的用户是：" << endl;
				cin >> n;
				if (wxinformation::getwxjoinin(n, m) == 0 && wxinformation::getwxgrouplist(n, m) != 1 && n >= 0 && n < wxinformation::getwxidnumber()) {
					wxinformation::change1wxjoinin(n, m);
					cout << "你已邀请" << n << "号用户入群" << endl;
					system("PAUSE");
				}
				else if (wxinformation::getwxjoinin(n, m) == 1) {
					cout << "该用户已被人邀请进入该群" << endl;
					system("PAUSE");
				}
				else if (wxinformation::getwxgrouplist(n, m) == 1) {
					cout << "该用户已在群内" << endl;
					system("PAUSE");
				}
				else if (n < 0 && n >= wxinformation::getwxidnumber()) {
					cout << "该用户不存在" << endl;
					system("PAUSE");
				}
				goto wxlevelstart;
			}
			if (n == 3) {
				findwxgroupmember(i);
				cout << "请输入需要踢出的成员编号：";
				findwxgroupmember(i);
				cin >> p;
				if (wxinformation::getwxgrouplist(p, m) == 1 && p != exam.wxID) {
					wxinformation::change0wxgrouplist(p, m);
					cout << "成员" << p << "已踢出";
					system("PAUSE");
					goto wxlevelstart;
				}
				else if (wxinformation::getwxgrouplist(p, m) == 0) {
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
				wxinformation::change0wxgrouplist(exam.wxID, m);
				cout << "你已退出" << i << "号群" << endl;
				wxinformation::change0wxlevel(exam.wxID, m);
				for (q = 0;q < wxinformation::getwxidnumber();q++) {
					if (wxinformation::getwxlevel(q, m) == 1) {
						wxinformation::change3wxlevel(q, m);
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
void wxUser::addotherfriend(wxUser &exam) {
	cout << "你列表里的微信好友已开通qq的有：" << endl;
	int i, m, number;
	wxUser examwx;
	for (i = 0;i < wxinformation::getwxidnumber();i++) {
		if (wxinformation::getwxfriendlist(exam.wxID, i) == 1) {
			examwx = wxidfind(i);
			if (examwx.qqflag == 0) {
				cout << "你的" << i << "号微信好友未开通qq"<<endl;
			}
			if (examwx.qqflag == 1) {
				cout << "你的" << i << "号微信好友已开通qq，其qq用户号为：" << examwx.qqID << endl;;//注意修改
			}
		}
	}
}
void wxUser::menu(wxUser &exam) {
	int n;
wxstart:
	system("cls");
	cout << "1-查看好友操作列表" << endl;
	cout << "2-查看群操作列表" << endl;
	cout << "3-修改个人信息" << endl;
	cout << "4-返回wx平台" << endl;
	cin >> n;
	if (n == 1) {
	friendstart:
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
			goto friendstart;
		}
		if (n == 2) {
			exam.deletefriend(exam);
			goto friendstart;
		}
		if (n == 3) {
			exam.findfriend(exam);
			goto friendstart;
		}
		if (n == 4) {
			system("cls");
			exam.addotherfriend(exam);
			system("PAUSE");
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
	changestart:
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
		goto changestart;
	}
	if (n == 4) {
		return;
	}

}
void wxloading() {
	while (1) {
		system("cls");
		int n;
		wxUser exam;
		cout << "1-登录,2-创建新账号" << endl;
		cin >> n;
		system("cls");

		if (n == 1) {
			cout << "输入登录编号" << endl;
			cin >> n;
			exam = wxidfind(n);
			cout << "找到用户，准备登录......" << endl;
			system("PAUSE");
			exam.menu(exam);
		}
		else if (n == 2) {
			cout << "准备创建新用户" << endl;
			cout << "1-创建" << endl;
			cout << "2-返回" << endl;
			cin >> n;
			if (n == 1) {
				cout << "前往注册界面..." << endl;
				system("PAUSE");
				wxuserlist[wxinformation::getwxidnumber() - 1] = createwx();
				cout << "准备前往登录界面" << endl;
				system("PAUSE");
			}

		}
		else if (n != 1 && n != 2) {
			cout << "输入错误" << endl;
			system("PAUSE");
		}
	}
}

int main() {
	wxUser aa, bb;
	aa.wxID = 0;
	bb.wxID = 1;	
	bb.qqflag = 1;
	bb.qqID = 2;
	wxuserlist[0] = aa;
	wxuserlist[1] = bb;
	wxinformation::changewxidnumber(2);
	wxloading();
	/*ofstream out("zth.txt",ios::app);
	if (out.is_open()) {
		out << i;
		out << aa;
			out.close();
	}*/
	/*int i;
	string aa;
	ifstream in("zth.txt");
	if (in.is_open()) {
		in >> aa;
		cout << aa;
		in >> aa;
		cout << aa;
	}*/

	return 0;
}