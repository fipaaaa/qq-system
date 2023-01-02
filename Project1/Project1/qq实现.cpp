#include"用户信息zth.h";
#include"qq信息zth.h";
#include<iostream>
#include<time.h>
#pragma warning(disable : 4996);
using namespace std;
qqUser qquserlist[100];	
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
qqUser createqq() {
	system("cls");
	qqUser exam;
	exam.qqID = qqinformation::getqqidnumber();//第一个为0
	qqinformation::changeqqidnumber(1);//id+1
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
	exam.qqflag=1;
	exam.qqyear = getmytime();
	cout << "qqyear:" << exam.qqyear << endl;
	cout << "注册已完成，请获取你的登录编号:";
	cout << exam.qqID << endl;
	system("PAUSE");
	return exam;
}
qqUser qqidfind(int i) {
	int p;
	for (p = 0;p < qqinformation::getqqidnumber();p++) {
		if (qquserlist[p].qqID == i) {
			return qquserlist[p];
		}
	}
	cout << "未找到该用户，请创建" << endl;
	system("PAUSE");
}
void qqUser::addfriend(qqUser &exam) {//添加好友
	system("cls");
	int i, number;
	cout << "需要添加的好友编号：";
	cin >> number;//i<100
	i = number;
	if (qqinformation::getqqfriendlist(exam.qqID,i) != 1 && i <qqinformation::getqqidnumber()&&i!=exam.qqID) {
		qqinformation::change1qqfriendlist(exam.qqID,i);//竖行代表当前账户
		cout << "你与" << number << "号好友关系已建立" << endl;
		system("PAUSE");
	}
	else if (i == exam.qqID) {
		cout << "你不能加自己为好友" << endl;
		system("PAUSE");
	}
	else if (qqinformation::getqqfriendlist(exam.qqID,i) == 1) {
		cout << "已建立好友关系，请勿重复操作" << endl;
		system("PAUSE");
	}
	if (i >= qqinformation::getqqidnumber()) {
		cout << "该用户不存在" << endl;
		system("PAUSE");
	}
}
void qqUser::deletefriend(qqUser &exam) {//删除好友
	system("cls");
	int i, number;
	cout << "输入需要删除的好友编号";
	cin >> number;
	i = number;
	if (qqinformation::getqqfriendlist(exam.qqID, i) == 1) {
		qqinformation::change0qqfriendlist(exam.qqID, i);
		cout << "你与" << number << "号好友关系已删除" << endl;
		system("PAUSE");
	}
	else if (qqinformation::getqqfriendlist(exam.qqID, i) == 0) {
		cout << "你与该好友尚未建立好友关系" << endl;
		system("PAUSE");
	}
}
void qqUser::findfriend(qqUser &exam) {//找到所有好友
	system("cls");
	int i, number = 0;
	for (i = 0;i < qqinformation::getqqidnumber();i++) {
		if ((qqinformation::getqqfriendlist(exam.qqID, i) == 1) && (qqinformation::getqqfriendlist(i,exam.qqID ) == 0)) {
			cout << "你与" << i << "号已建立单边好友关系" << endl;
			number++;
		}
		else if ((qqinformation::getqqfriendlist(exam.qqID, i) == 1) && (qqinformation::getqqfriendlist(i, exam.qqID) == 1) && (i != exam.qqID)) {
			cout << "你与" << i << "号已建立双边好友关系" << endl;
			number++;
		}
	}
	if (number == 0) {
		cout << "你未与任何人建立好友关系" << endl;
	}
	system("PAUSE");
}
int qqUser::creategroup(qqUser &exam) {//创群
	int  number;
	
	cout << "你想创建一个新群？" << endl;
	qqinformation::change1qqgrouplist(exam.qqID, qqinformation::getqqgroupnumber()) ;//竖行为用户，行为群号
	number = qqinformation::getqqgroupnumber() + 1001;
	cout << "群号为" << number << "的群已建立" << endl;
	qqinformation::change3qqlevel(exam.qqID, qqinformation::getqqgroupnumber());
	qqinformation::changeqqgroupnumber(1);
	getchar();
	return number;
}
void qqUser::findjoinin(qqUser &exam) {//加群
	int i, number;
	cout << "你想加入几号群？（10XX）";
	cin >> number;
	i = number - 1 - 1000;
	if (i > qqinformation::getqqgroupnumber()-1) {
		cout << "该群还未建立" << endl;
	}
	else if (i>=0 &&i <= qqinformation::getqqgroupnumber()-1&&qqinformation::getqqgrouplist(exam.qqID,i)!=1) {
		qqinformation::change1qqjoinin(exam.qqID, qqinformation::getqqgroupnumber()-1);
		cout << "你已申请加入" << number << "号群";
	}
	else if (i>=0 &&i < qqinformation::getqqgroupnumber()-1 && qqinformation::getqqgrouplist(exam.qqID, i) == 1) {
		cout << "你已经在该群内，请勿重复添加" << endl;
	}
	else if (i < 0) {
		cout << "不存在该群" << endl;
	}
}

void qqUser::findgroup(qqUser &exam) {//查群
	int i, number = 0;
	for (i = 0;i < qqinformation::getqqgroupnumber();i++) {
		if (qqinformation::getqqgrouplist(exam.qqID,i) == 1) {
			cout << "你在" << i + 1001 << "号群内" << endl;
			number++;
		}
	}
	if (number == 0) {
		cout << "你没有加入任何群" << endl;
	}
}
void findqqgroupmember(int i) {
	int f;
	int number = i - 1001;
	if (number < qqinformation::getqqgroupnumber() && number >= 0) {
		cout << i << "群" << endl;
		for (f = 0;f < qqinformation::getqqidnumber();f++) {
			if (qqinformation::getqqgrouplist(f, number) == 1) {
				cout << f << "号成员在群内" << ",其群内等级为";
				if (qqinformation::getqqlevel(f, number) == 1) {
					cout << "群员" << endl;
				}
				if (qqinformation::getqqlevel(f, number) == 3) {
					cout << "群主" << endl;
				}
			}
		}
	}
	else if (1) {
		cout << "不存在该群号" << endl;
	}
}

void qqUser::groupmanage(qqUser &exam, int i) {//i为群号//群管理
	int m, p, q, t;//m记录数组位置，p为踢出成员编号，q为循环变量,t为加入是否同意
	m = i - 1001;
	int n;
	if (m > qqinformation::getqqgroupnumber()-1) {
		cout << "该群还未建立" << endl;
		return;
	}
	if (qqinformation::getqqgrouplist(exam.qqID,m) == 0) {
		cout << "你未加入此群" << endl;
		return;
	}
	if (m <= qqinformation::getqqgroupnumber()-1) {
		if (qqinformation::getqqlevel(exam.qqID,m) == 1) {
			cout << "按1退出群，按2返回主菜单" << endl;
			cin >> n;
			if (n == 1) {
				qqinformation::change0qqgrouplist(exam.qqID,m);
				cout << "你已退出" << i << "号群" << endl;
				qqinformation::change0qqlevel(exam.qqID,m);
			}
			if (n == 2) {
				return;
			}
		}
		if (qqinformation::getqqlevel(exam.qqID,m) == 2) {
		qqlevelstart:
			int b = 0;//申请个数
			system("cls");
			cout << "按1处理入群申请，按2踢出群成员，按3退出群，按4返回主菜单" << endl;
			cin >> n;
			if (n == 1) {
				for (q = 0;q < qqinformation::getqqidnumber();q++) {
					if (qqinformation::getqqjoinin(q,m) == 1) {
						cout << "编号为" << q << "的用户申请加入群" << endl;
						cout << "同意按1，不同意按0" << endl;
						cin >> t;
						if (t == 0) {
							qqinformation::change0qqjoinin(q,m);
							cout << "编号为" << q << "的用户已被你拒绝入群";
							b++;
						}
						if (t == 1) {
							qqinformation::change0qqjoinin(q, m);
							qqinformation::change1qqgrouplist(q,m);
							cout << "允许编号为" << q << "的用户加入群";
							qqinformation::change1qqlevel(q,m);//初始化等级为群员
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
				if (qqinformation::getqqgrouplist(p,m) == 1 && p != exam.qqID&&qqinformation::getqqlevel(p,m) == 1) {
					qqinformation::change0qqgrouplist(p,m);
					cout << "成员" << p << "已踢出";
					system("PAUSE");
					goto qqlevelstart;
				}
				else if (qqinformation::getqqgrouplist(p,m) == 1 && p != exam.qqID&&qqinformation::getqqlevel(p,m) != 1) {
					cout << "你无法踢出管理员或群主" << endl;
					system("PAUSE");
					goto qqlevelstart;
				}
				else if (qqinformation::getqqgrouplist(p,m) == 0) {
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
				qqinformation::change0qqgrouplist(exam.qqID,m);
				cout << "你已退出" << i << "号群" << endl;
				qqinformation::change0qqlevel(exam.qqID,m);
				system("PAUSE");
				return;
			}
			if (n == 4) {
				return;
			}
		}
		if (qqinformation::getqqlevel(exam.qqID,m) == 3) {
		qqlevel2start:
			int b = 0;
			system("cls");
			cout << "按1处理入群申请，按2管理群员等级，按3踢出群成员或管理员，按4退出群，按5返回主菜单" << endl;
			cin >> n;
			if (n == 1) {
				for (q = 0;q < qqinformation::getqqidnumber();q++) {
					if (qqinformation::getqqjoinin(q,m) == 1) {
						cout << "编号为" << q << "的用户申请加入群" << endl;
						cout << "同意按1，不同意按0" << endl;
						cin >> t;
						if (t == 0) {
							qqinformation::change0qqjoinin(q,m);
							cout << "编号为" << q << "的用户已被你拒绝入群";
							b++;
						}
						if (t == 1) {
							qqinformation::change0qqjoinin(q,m);
							qqinformation::change1qqgrouplist(q,m);
							cout << "允许编号为" << q << "的用户加入群";
							qqinformation::change1qqlevel(q,m);//初始化等级为群员
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
					if (qqinformation::getqqgrouplist(n,m) == 0) {
						cout << "该用户尚未加入该群";
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (n == exam.qqID) {
						cout << "你已是群主" << endl;
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (qqinformation::getqqgrouplist(n,m) == 1 && qqinformation::getqqlevel(n,m) == 2) {
						cout << "该用户已经是该群的管理员" << endl;
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (qqinformation::getqqgrouplist(n,m) == 1 && qqinformation::getqqlevel(n,m) == 1) {
						cout << "编号为" << n << "的用户升为了管理员" << endl;
						qqinformation::change2qqlevel(n,m);
						system("PAUSE");
						goto qqlevel3start;
					}
				}
				if (n == 2) {
					cout << "你想降为群员的用户编号为：";
					findqqgroupmember(i);
					cin >> n;
					if (qqinformation::getqqgrouplist(n,m) == 0) {
						cout << "该用户尚未加入该群";
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (n == exam.qqID) {
						cout << "你已是群主" << endl;
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (qqinformation::getqqgrouplist(n,m) == 1 && qqinformation::getqqlevel(n,m) == 1) {
						cout << "该用户已经是该群的群员" << endl;
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (qqinformation::getqqgrouplist(n,m) == 1 && qqinformation::getqqlevel(n,m) == 2) {
						cout << "编号为" << n << "的用户降为了群员" << endl;
						qqinformation::change1qqlevel(n,m);
						system("PAUSE");
						goto qqlevel3start;
					}
				}
				if (n == 3) {
					cout << "你想晋升为群主的用户是：（你将降为管理员）：";
					findqqgroupmember(i);
					cin >> n;
					if (qqinformation::getqqgrouplist(n,m) == 0) {
						cout << "该用户尚未加入该群";
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (qqinformation::getqqgrouplist(n,m) == 1 && qqinformation::getqqlevel(n,m) == 3) {
						cout << "你已经是该群的群主" << endl;
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (qqinformation::getqqgrouplist(n,m) == 1) {
						cout << "编号为" << n << "的用户升为了群主" << endl;
						qqinformation::change3qqlevel(n,m);
						qqinformation::change2qqlevel(exam.qqID,m);
						system("PAUSE");
						goto qqlevelstart;
					}
				}
				if (n == 4) {
					return;
				}
			}
			if (n == 3) {
				findqqgroupmember(i);
				cout << "请输入需要踢出的成员编号：";
				findqqgroupmember(i);
				cin >> p;
				if (qqinformation::getqqgrouplist(p,m) == 1 && p != exam.qqID) {
					qqinformation::change0qqgrouplist(p,m);
					cout << "成员" << p << "已踢出";
					system("PAUSE");
					goto qqlevel2start;
				}
				else if (qqinformation::getqqgrouplist(p,m) == 0) {
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
				qqinformation::change0qqgrouplist(exam.qqID, m);
				cout << "你已退出" << i << "号群" << endl;
				qqinformation::change0qqlevel(exam.qqID,m);
				for (q = 0;q < qqinformation::getqqidnumber();q++) {
					if (qqinformation::getqqlevel(q,m) == 2) {
						qqinformation::change3qqlevel(q,m) ;
						cout << "编号为" << q << "的用户已从管理员升为群主";
						break;
					}
					if (qqinformation::getqqlevel(q,m) == 1) {
						qqinformation::change3qqlevel(q,m);
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

void qqdiscuss(qqUser &exam){//临时讨论组
	int j, p,n;
	cout << "你想创建哪个群的临时讨论组？" << endl;
	exam.findgroup(exam);
	cin >> n;
	j = exam.creategroup(exam);
	findqqgroupmember(n);
	cout << "你需要加入哪些成员进入讨论组？（回-1结束输入退出）" << endl;
	while (1) {
		cin >> p;
		 if (qqinformation::getqqgrouplist(p, n-1001) == 1 && qqinformation::getqqgrouplist(p, j-1001) != 1) {
			qqinformation::change1qqgrouplist(p, j-1001);
			cout << "成员" << p << "已加入讨论群" << endl;
		}
		else if (qqinformation::getqqgrouplist(p, n-1001) == 1 && qqinformation::getqqgrouplist(p, j-1001) == 1) {
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
void qqUser::menu(qqUser &exam) {
	int n;
start:
	system("cls");
	cout << "1-查看好友操作列表" << endl;
	cout << "2-查看群操作列表" << endl;
	cout << "3-修改个人信息"<<endl;
	cout << "4-返回qq平台" << endl;
	cin >> n;
	if (n == 1) {
	friendstart:
		system("cls");

		cout << "你想对好友列表进行什么操作？" << endl;
		cout << "1-添加好友" << endl;
		cout << "2-删除好友" << endl;
		cout << "3-查看好友列表" << endl;
		cout << "4-返回菜单" << endl;
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
			goto start;
		}
	}

	if (n == 2) {
	groupstart:
		system("cls");
		cout << "1-添加群" << endl;
		cout << "2-创建新群" << endl;
		cout << "3-管理群" << endl;
		cout << "4-查看群" << endl;
		cout << "5-返回菜单" << endl;
		cin >> n;
		if(n==1){
			system("cls");
			exam.findjoinin(exam);
			system("PAUSE");
			goto groupstart;
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
				goto groupstart;
			}
			if (n == 2) {
				system("cls");
				qqdiscuss(exam);
			}
			if (n == 3) {
				goto groupstart;
			}
		}
		if (n == 3) {
			system("cls");
			cout << "目前已加入的群有：" << endl;
			exam.findgroup(exam);
			cout << "你想进入哪个群的管理？" << endl;
			cin >> n;
			system("cls");
			exam.groupmanage(exam,n);
			system("PAUSE");
			goto groupstart;
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
		goto groupstart;
	}
	if (n == 5) {
		goto start;
	}
	}
	if (n == 3) {
		changestart:
		system("cls");
		string kk;
		int ii;
		cout << "你目前的资料为："<<endl;
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
			cout << "修改完成，现在年龄为:  " << exam.qqage<< endl;
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
			goto start;
		}
		system("PAUSE");
		goto changestart;
	}
	if (n == 4) {
		return;
	}
}

void qqloading() {
	while (1) {
		system("cls");
		int n;
		qqUser exam;
		cout << "1-登录,2-创建新账号" << endl;
		cin >> n;
		system("cls");

		if (n == 1) {
			cout << "输入登录编号" << endl;
			cin >> n;
			exam = qqidfind(n);
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
				qquserlist[qqinformation::getqqidnumber()-1] = createqq();
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


/*int main() {
	qqUser aa,bb;
	qqinformation::changeqqidnumber(2);
   aa.qqID = 0;
	bb.qqID = 1;
	qquserlist[0] = aa;
	qquserlist[1] = bb;
	loading();
	return 0;
}*/