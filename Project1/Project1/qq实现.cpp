#include"�û���Ϣzth.h";
#include"qq��Ϣzth.h";
#include<iostream>
#include<time.h>
#pragma warning(disable : 4996);
using namespace std;
qqUser qquserlist[100];	
int getmytime() {
	int a, b, c, longtime;
	time_t t;
	struct tm * lt;
	time(&t);//��ȡʱ�����
	lt = localtime(&t);//תΪʱ��ṹ
	a = lt->tm_hour, b = lt->tm_min, c = lt->tm_sec;
	cout << "ʱ��:" << a << ":" << b << ":" << c << endl;
	longtime = a * 10000 + b * 100 + c;
	return longtime;
}
qqUser createqq() {
	system("cls");
	qqUser exam;
	exam.qqID = qqinformation::getqqidnumber();//��һ��Ϊ0
	qqinformation::changeqqidnumber(1);//id+1
	cout << "ע����Ϣ" << endl;
	cout << "create qqnickname:" << endl;
	cin >> exam.qqnickname;
	cout << "qqnickname:" << exam.qqnickname << "  has been created" << endl;
	cout << "create birthday:year/month/day" << endl;
	cin >> exam.qqbirthday;
	cout << "birthday:" << exam.qqbirthday << endl;
	cout << "create age:" << endl;
	cin >> exam.qqage;
	cout << "����Ϊ" << exam.qqage << endl;
	cout << "create local:" << endl;
	cin >> exam.qqlocal;
	cout << "local:" << exam.qqlocal << endl;
	exam.qqflag=1;
	exam.qqyear = getmytime();
	cout << "qqyear:" << exam.qqyear << endl;
	cout << "ע������ɣ����ȡ��ĵ�¼���:";
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
	cout << "δ�ҵ����û����봴��" << endl;
	system("PAUSE");
}
void qqUser::addfriend(qqUser &exam) {//��Ӻ���
	system("cls");
	int i, number;
	cout << "��Ҫ��ӵĺ��ѱ�ţ�";
	cin >> number;//i<100
	i = number;
	if (qqinformation::getqqfriendlist(exam.qqID,i) != 1 && i <qqinformation::getqqidnumber()&&i!=exam.qqID) {
		qqinformation::change1qqfriendlist(exam.qqID,i);//���д���ǰ�˻�
		cout << "����" << number << "�ź��ѹ�ϵ�ѽ���" << endl;
		system("PAUSE");
	}
	else if (i == exam.qqID) {
		cout << "�㲻�ܼ��Լ�Ϊ����" << endl;
		system("PAUSE");
	}
	else if (qqinformation::getqqfriendlist(exam.qqID,i) == 1) {
		cout << "�ѽ������ѹ�ϵ�������ظ�����" << endl;
		system("PAUSE");
	}
	if (i >= qqinformation::getqqidnumber()) {
		cout << "���û�������" << endl;
		system("PAUSE");
	}
}
void qqUser::deletefriend(qqUser &exam) {//ɾ������
	system("cls");
	int i, number;
	cout << "������Ҫɾ���ĺ��ѱ��";
	cin >> number;
	i = number;
	if (qqinformation::getqqfriendlist(exam.qqID, i) == 1) {
		qqinformation::change0qqfriendlist(exam.qqID, i);
		cout << "����" << number << "�ź��ѹ�ϵ��ɾ��" << endl;
		system("PAUSE");
	}
	else if (qqinformation::getqqfriendlist(exam.qqID, i) == 0) {
		cout << "����ú�����δ�������ѹ�ϵ" << endl;
		system("PAUSE");
	}
}
void qqUser::findfriend(qqUser &exam) {//�ҵ����к���
	system("cls");
	int i, number = 0;
	for (i = 0;i < qqinformation::getqqidnumber();i++) {
		if ((qqinformation::getqqfriendlist(exam.qqID, i) == 1) && (qqinformation::getqqfriendlist(i,exam.qqID ) == 0)) {
			cout << "����" << i << "���ѽ������ߺ��ѹ�ϵ" << endl;
			number++;
		}
		else if ((qqinformation::getqqfriendlist(exam.qqID, i) == 1) && (qqinformation::getqqfriendlist(i, exam.qqID) == 1) && (i != exam.qqID)) {
			cout << "����" << i << "���ѽ���˫�ߺ��ѹ�ϵ" << endl;
			number++;
		}
	}
	if (number == 0) {
		cout << "��δ���κ��˽������ѹ�ϵ" << endl;
	}
	system("PAUSE");
}
int qqUser::creategroup(qqUser &exam) {//��Ⱥ
	int  number;
	
	cout << "���봴��һ����Ⱥ��" << endl;
	qqinformation::change1qqgrouplist(exam.qqID, qqinformation::getqqgroupnumber()) ;//����Ϊ�û�����ΪȺ��
	number = qqinformation::getqqgroupnumber() + 1001;
	cout << "Ⱥ��Ϊ" << number << "��Ⱥ�ѽ���" << endl;
	qqinformation::change3qqlevel(exam.qqID, qqinformation::getqqgroupnumber());
	qqinformation::changeqqgroupnumber(1);
	getchar();
	return number;
}
void qqUser::findjoinin(qqUser &exam) {//��Ⱥ
	int i, number;
	cout << "������뼸��Ⱥ����10XX��";
	cin >> number;
	i = number - 1 - 1000;
	if (i > qqinformation::getqqgroupnumber()-1) {
		cout << "��Ⱥ��δ����" << endl;
	}
	else if (i>=0 &&i <= qqinformation::getqqgroupnumber()-1&&qqinformation::getqqgrouplist(exam.qqID,i)!=1) {
		qqinformation::change1qqjoinin(exam.qqID, qqinformation::getqqgroupnumber()-1);
		cout << "�����������" << number << "��Ⱥ";
	}
	else if (i>=0 &&i < qqinformation::getqqgroupnumber()-1 && qqinformation::getqqgrouplist(exam.qqID, i) == 1) {
		cout << "���Ѿ��ڸ�Ⱥ�ڣ������ظ����" << endl;
	}
	else if (i < 0) {
		cout << "�����ڸ�Ⱥ" << endl;
	}
}

void qqUser::findgroup(qqUser &exam) {//��Ⱥ
	int i, number = 0;
	for (i = 0;i < qqinformation::getqqgroupnumber();i++) {
		if (qqinformation::getqqgrouplist(exam.qqID,i) == 1) {
			cout << "����" << i + 1001 << "��Ⱥ��" << endl;
			number++;
		}
	}
	if (number == 0) {
		cout << "��û�м����κ�Ⱥ" << endl;
	}
}
void findqqgroupmember(int i) {
	int f;
	int number = i - 1001;
	if (number < qqinformation::getqqgroupnumber() && number >= 0) {
		cout << i << "Ⱥ" << endl;
		for (f = 0;f < qqinformation::getqqidnumber();f++) {
			if (qqinformation::getqqgrouplist(f, number) == 1) {
				cout << f << "�ų�Ա��Ⱥ��" << ",��Ⱥ�ڵȼ�Ϊ";
				if (qqinformation::getqqlevel(f, number) == 1) {
					cout << "ȺԱ" << endl;
				}
				if (qqinformation::getqqlevel(f, number) == 3) {
					cout << "Ⱥ��" << endl;
				}
			}
		}
	}
	else if (1) {
		cout << "�����ڸ�Ⱥ��" << endl;
	}
}

void qqUser::groupmanage(qqUser &exam, int i) {//iΪȺ��//Ⱥ����
	int m, p, q, t;//m��¼����λ�ã�pΪ�߳���Ա��ţ�qΪѭ������,tΪ�����Ƿ�ͬ��
	m = i - 1001;
	int n;
	if (m > qqinformation::getqqgroupnumber()-1) {
		cout << "��Ⱥ��δ����" << endl;
		return;
	}
	if (qqinformation::getqqgrouplist(exam.qqID,m) == 0) {
		cout << "��δ�����Ⱥ" << endl;
		return;
	}
	if (m <= qqinformation::getqqgroupnumber()-1) {
		if (qqinformation::getqqlevel(exam.qqID,m) == 1) {
			cout << "��1�˳�Ⱥ����2�������˵�" << endl;
			cin >> n;
			if (n == 1) {
				qqinformation::change0qqgrouplist(exam.qqID,m);
				cout << "�����˳�" << i << "��Ⱥ" << endl;
				qqinformation::change0qqlevel(exam.qqID,m);
			}
			if (n == 2) {
				return;
			}
		}
		if (qqinformation::getqqlevel(exam.qqID,m) == 2) {
		qqlevelstart:
			int b = 0;//�������
			system("cls");
			cout << "��1������Ⱥ���룬��2�߳�Ⱥ��Ա����3�˳�Ⱥ����4�������˵�" << endl;
			cin >> n;
			if (n == 1) {
				for (q = 0;q < qqinformation::getqqidnumber();q++) {
					if (qqinformation::getqqjoinin(q,m) == 1) {
						cout << "���Ϊ" << q << "���û��������Ⱥ" << endl;
						cout << "ͬ�ⰴ1����ͬ�ⰴ0" << endl;
						cin >> t;
						if (t == 0) {
							qqinformation::change0qqjoinin(q,m);
							cout << "���Ϊ" << q << "���û��ѱ���ܾ���Ⱥ";
							b++;
						}
						if (t == 1) {
							qqinformation::change0qqjoinin(q, m);
							qqinformation::change1qqgrouplist(q,m);
							cout << "������Ϊ" << q << "���û�����Ⱥ";
							qqinformation::change1qqlevel(q,m);//��ʼ���ȼ�ΪȺԱ
							b++;
						}
					}
				}
				if (b == 0) {
					cout << "û�����������" << endl;
					system("PAUSE");
					goto qqlevelstart;
				}
				else if (b != 0) {
					system("PAUSE");
					goto qqlevelstart;
				}
			}
			if (n == 2) {
				cout << "��������Ҫ�߳��ĳ�Ա��ţ�";
				findqqgroupmember(i);
				cin >> p;
				if (qqinformation::getqqgrouplist(p,m) == 1 && p != exam.qqID&&qqinformation::getqqlevel(p,m) == 1) {
					qqinformation::change0qqgrouplist(p,m);
					cout << "��Ա" << p << "���߳�";
					system("PAUSE");
					goto qqlevelstart;
				}
				else if (qqinformation::getqqgrouplist(p,m) == 1 && p != exam.qqID&&qqinformation::getqqlevel(p,m) != 1) {
					cout << "���޷��߳�����Ա��Ⱥ��" << endl;
					system("PAUSE");
					goto qqlevelstart;
				}
				else if (qqinformation::getqqgrouplist(p,m) == 0) {
					cout << "���û�����Ⱥ��" << endl;
					system("PAUSE");
					goto qqlevelstart;
				}
				else if (p == exam.qqID) {
					cout << "�㲻���߳��Լ�" << endl;
					system("PAUSE");
					goto qqlevelstart;
				}
			}
			if (n == 3) {
				qqinformation::change0qqgrouplist(exam.qqID,m);
				cout << "�����˳�" << i << "��Ⱥ" << endl;
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
			cout << "��1������Ⱥ���룬��2����ȺԱ�ȼ�����3�߳�Ⱥ��Ա�����Ա����4�˳�Ⱥ����5�������˵�" << endl;
			cin >> n;
			if (n == 1) {
				for (q = 0;q < qqinformation::getqqidnumber();q++) {
					if (qqinformation::getqqjoinin(q,m) == 1) {
						cout << "���Ϊ" << q << "���û��������Ⱥ" << endl;
						cout << "ͬ�ⰴ1����ͬ�ⰴ0" << endl;
						cin >> t;
						if (t == 0) {
							qqinformation::change0qqjoinin(q,m);
							cout << "���Ϊ" << q << "���û��ѱ���ܾ���Ⱥ";
							b++;
						}
						if (t == 1) {
							qqinformation::change0qqjoinin(q,m);
							qqinformation::change1qqgrouplist(q,m);
							cout << "������Ϊ" << q << "���û�����Ⱥ";
							qqinformation::change1qqlevel(q,m);//��ʼ���ȼ�ΪȺԱ
							b++;
						}
					}
				}
				if (b == 0) {
					cout << "û�����������" << endl;
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
				cout << "�����ȺԱ���к��ֲ�����1-��Ϊ����Ա��2-��ΪȺԱ,3-��ΪȺ�����Լ�����Ϊ����Ա��4-����" << endl;
				cin >> n;
				if (n == 1) {
					cout << "���������ȺԱ����ǣ�" << endl;
					findqqgroupmember(i);
					cin >> n;
					if (qqinformation::getqqgrouplist(n,m) == 0) {
						cout << "���û���δ�����Ⱥ";
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (n == exam.qqID) {
						cout << "������Ⱥ��" << endl;
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (qqinformation::getqqgrouplist(n,m) == 1 && qqinformation::getqqlevel(n,m) == 2) {
						cout << "���û��Ѿ��Ǹ�Ⱥ�Ĺ���Ա" << endl;
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (qqinformation::getqqgrouplist(n,m) == 1 && qqinformation::getqqlevel(n,m) == 1) {
						cout << "���Ϊ" << n << "���û���Ϊ�˹���Ա" << endl;
						qqinformation::change2qqlevel(n,m);
						system("PAUSE");
						goto qqlevel3start;
					}
				}
				if (n == 2) {
					cout << "���뽵ΪȺԱ���û����Ϊ��";
					findqqgroupmember(i);
					cin >> n;
					if (qqinformation::getqqgrouplist(n,m) == 0) {
						cout << "���û���δ�����Ⱥ";
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (n == exam.qqID) {
						cout << "������Ⱥ��" << endl;
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (qqinformation::getqqgrouplist(n,m) == 1 && qqinformation::getqqlevel(n,m) == 1) {
						cout << "���û��Ѿ��Ǹ�Ⱥ��ȺԱ" << endl;
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (qqinformation::getqqgrouplist(n,m) == 1 && qqinformation::getqqlevel(n,m) == 2) {
						cout << "���Ϊ" << n << "���û���Ϊ��ȺԱ" << endl;
						qqinformation::change1qqlevel(n,m);
						system("PAUSE");
						goto qqlevel3start;
					}
				}
				if (n == 3) {
					cout << "�������ΪȺ�����û��ǣ����㽫��Ϊ����Ա����";
					findqqgroupmember(i);
					cin >> n;
					if (qqinformation::getqqgrouplist(n,m) == 0) {
						cout << "���û���δ�����Ⱥ";
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (qqinformation::getqqgrouplist(n,m) == 1 && qqinformation::getqqlevel(n,m) == 3) {
						cout << "���Ѿ��Ǹ�Ⱥ��Ⱥ��" << endl;
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (qqinformation::getqqgrouplist(n,m) == 1) {
						cout << "���Ϊ" << n << "���û���Ϊ��Ⱥ��" << endl;
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
				cout << "��������Ҫ�߳��ĳ�Ա��ţ�";
				findqqgroupmember(i);
				cin >> p;
				if (qqinformation::getqqgrouplist(p,m) == 1 && p != exam.qqID) {
					qqinformation::change0qqgrouplist(p,m);
					cout << "��Ա" << p << "���߳�";
					system("PAUSE");
					goto qqlevel2start;
				}
				else if (qqinformation::getqqgrouplist(p,m) == 0) {
					cout << "���û�����Ⱥ��" << endl;
					system("PAUSE");
					goto qqlevel2start;
				}
				else if (p == exam.qqID) {
					cout << "�㲻���߳��Լ�" << endl;
					system("PAUSE");
					goto qqlevel2start;
				}
			}
			if (n == 4) {
				qqinformation::change0qqgrouplist(exam.qqID, m);
				cout << "�����˳�" << i << "��Ⱥ" << endl;
				qqinformation::change0qqlevel(exam.qqID,m);
				for (q = 0;q < qqinformation::getqqidnumber();q++) {
					if (qqinformation::getqqlevel(q,m) == 2) {
						qqinformation::change3qqlevel(q,m) ;
						cout << "���Ϊ" << q << "���û��Ѵӹ���Ա��ΪȺ��";
						break;
					}
					if (qqinformation::getqqlevel(q,m) == 1) {
						qqinformation::change3qqlevel(q,m);
						cout << "����û�й���Ա�����Ϊ" << q << "���û��Ѵ�ȺԱ��ΪȺ��";
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

void qqdiscuss(qqUser &exam){//��ʱ������
	int j, p,n;
	cout << "���봴���ĸ�Ⱥ����ʱ�����飿" << endl;
	exam.findgroup(exam);
	cin >> n;
	j = exam.creategroup(exam);
	findqqgroupmember(n);
	cout << "����Ҫ������Щ��Ա���������飿����-1���������˳���" << endl;
	while (1) {
		cin >> p;
		 if (qqinformation::getqqgrouplist(p, n-1001) == 1 && qqinformation::getqqgrouplist(p, j-1001) != 1) {
			qqinformation::change1qqgrouplist(p, j-1001);
			cout << "��Ա" << p << "�Ѽ�������Ⱥ" << endl;
		}
		else if (qqinformation::getqqgrouplist(p, n-1001) == 1 && qqinformation::getqqgrouplist(p, j-1001) == 1) {
			cout << "��Ա" << p << "��������Ⱥ��" << endl;
		}
		else if (1) {
				 cout << "���û���δ����" << endl;
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
	cout << "1-�鿴���Ѳ����б�" << endl;
	cout << "2-�鿴Ⱥ�����б�" << endl;
	cout << "3-�޸ĸ�����Ϣ"<<endl;
	cout << "4-����qqƽ̨" << endl;
	cin >> n;
	if (n == 1) {
	friendstart:
		system("cls");

		cout << "����Ժ����б����ʲô������" << endl;
		cout << "1-��Ӻ���" << endl;
		cout << "2-ɾ������" << endl;
		cout << "3-�鿴�����б�" << endl;
		cout << "4-���ز˵�" << endl;
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
		cout << "1-���Ⱥ" << endl;
		cout << "2-������Ⱥ" << endl;
		cout << "3-����Ⱥ" << endl;
		cout << "4-�鿴Ⱥ" << endl;
		cout << "5-���ز˵�" << endl;
		cin >> n;
		if(n==1){
			system("cls");
			exam.findjoinin(exam);
			system("PAUSE");
			goto groupstart;
		}
		if (n == 2) {
			system("cls");
			cout << "1-����������Ⱥ" << endl;
			cout << "2-������������" << endl;
			cout << "3-����" << endl;
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
			cout << "Ŀǰ�Ѽ����Ⱥ�У�" << endl;
			exam.findgroup(exam);
			cout << "��������ĸ�Ⱥ�Ĺ���" << endl;
			cin >> n;
			system("cls");
			exam.groupmanage(exam,n);
			system("PAUSE");
			goto groupstart;
		}
		if (n == 4) {
		system("cls");
		cout << "Ŀǰ�Ѽ����Ⱥ�У�" << endl;
		exam.findgroup(exam);
		cout << "����鿴��Ա��ȺΪ��" << endl;
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
		cout << "��Ŀǰ������Ϊ��"<<endl;
		cout << "�ǳ�Ϊ" << exam.qqnickname << endl;
		cout << "����Ϊ" << exam.qqage << endl;
		cout << "����Ϊ" << exam.qqbirthday << endl;
		cout << "���ڵ�Ϊ" << exam.qqlocal << endl;
		cout << "�����޸ĵ������ǣ�(-1���أ�" << endl;
		cout << "1-�ǳ�" << endl;
		cout << "2-����" << endl;
		cout << "3-����ʱ��" << endl;
		cout << "4-���ڵ�" << endl;
		cin >> n;
		if (n == 1) {
			system("cls");
			cout << "���ڵ��ǳ�Ϊ" << exam.qqnickname << endl;
			cout << "�����޸�Ϊ:" << endl;
			cin >> kk;
			exam.qqnickname = kk;
			cout << "�޸���ɣ������ǳ�Ϊ:  " << exam.qqnickname << endl;
		}
		if (n == 2) {
			system("cls");
			cout << "���ڵ�����Ϊ" << exam.qqage << endl;
			cout << "�����޸�Ϊ:" << endl;
			cin >> ii;
			exam.qqage = ii;
			cout << "�޸���ɣ���������Ϊ:  " << exam.qqage<< endl;
		}
		if (n == 3) {
			system("cls");
			cout << "���ڵĳ�������Ϊ" << exam.qqbirthday << endl;
			cout << "�����޸�Ϊ:" << endl;
			cin >> ii;
			exam.qqbirthday = ii;
			cout << "�޸���ɣ����ڳ�������Ϊ:  " << exam.qqbirthday << endl;
		}
		if (n == 4) {
			system("cls");
			cout << "���ڵ����ڵ�Ϊ" << exam.qqlocal << endl;
			cout << "�����޸�Ϊ:" << endl;
			cin >> kk;
			exam.qqlocal = kk;
			cout << "�޸���ɣ��������ڵ�Ϊ:  " << exam.qqlocal << endl;
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
		cout << "1-��¼,2-�������˺�" << endl;
		cin >> n;
		system("cls");

		if (n == 1) {
			cout << "�����¼���" << endl;
			cin >> n;
			exam = qqidfind(n);
			cout << "�ҵ��û���׼����¼......" << endl;
			system("PAUSE");
			exam.menu(exam);
		}
		else if (n == 2) {
			cout << "׼���������û�" << endl;
			cout << "1-����" << endl;
			cout << "2-����" << endl;
			cin >> n;
			if (n == 1) {
				cout << "ǰ��ע�����..." << endl;
				system("PAUSE");
				qquserlist[qqinformation::getqqidnumber()-1] = createqq();
				cout << "׼��ǰ����¼����" << endl;
				system("PAUSE");
			}
		}
		else if (n != 1 && n != 2) {
			cout << "�������" << endl;
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