#include"�û���Ϣzth.h";
#include"wx��Ϣzth.h";
#include"qq��Ϣzth.h";
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
	time(&t);//��ȡʱ�����
	lt = localtime(&t);//תΪʱ��ṹ
	a = lt->tm_hour, b = lt->tm_min, c = lt->tm_sec;
	cout << "ʱ��:" << a << ":" << b << ":" << c << endl;
	longtime = a * 10000 + b * 100 + c;
	return longtime;
}

wxUserzth createwx() {
	system("cls");
	wxUserzth exam;
	exam.wxID = wxinformationzth::getwxidnumber();//��һ��Ϊ0
	wxinformationzth::changewxidnumber(1);//id+1
	cout << "ע����Ϣ" << endl;
	cout << "create wxnickname:" << endl;
	cin >> exam.wxnickname;
	cout << "wxnickname:" << exam.wxnickname << "  has been created" << endl;
	cout << "create birthday:year/month/day" << endl;
	cin >> exam.wxbirthday;
	cout << "birthday:" << exam.wxbirthday << endl;
	cout << "create age:" << endl;
	cin >> exam.wxage;
	cout << "����Ϊ" << exam.wxage << endl;
	cout << "create local:" << endl;
	cin >> exam.wxlocal;
	cout << "local:" << exam.wxlocal << endl;
	exam.wxflag = 1;
	exam.wxyear = getmytime();
	cout << "wxyear:" << exam.wxyear << endl;
	cout << "ע������ɣ����ȡ��ĵ�¼���:";
	cout << exam.wxID << endl;
	system("PAUSE");
	return exam;
}

qqUserzth createqq() {
	system("cls");
	qqUserzth exam;
	exam.qqID = qqinformationzth::getqqidnumber();//��һ��Ϊ0
	qqinformationzth::changeqqidnumber(1);//id+1
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
	exam.qqflag = 1;
	exam.qqyear = getmytime();
	cout << "qqyear:" << exam.qqyear << endl;
	cout << "ע������ɣ����ȡ��ĵ�¼���:";
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
	cout << "δ�ҵ�" << i << "��΢���û�" << endl;
	system("PAUSE");
}

qqUserzth qqidfind(int i) {
	int p;
	for (p = 0;p < qqinformationzth::getqqidnumber();p++) {
		if (qqUserzthlist[p].qqID == i) {
			return qqUserzthlist[p];
		}
	}
	cout << "δ�ҵ����û����봴��" << endl;
	system("PAUSE");
}

void wxUserzth::addfriend(wxUserzth &exam) {//��Ӻ���
	system("cls");
	int i, number;
	cout << "��Ҫ��ӵĺ��ѱ�ţ�";
	cin >> number;//i<100
	i = number;
	if (wxinformationzth::getwxfriendlist(exam.wxID, i) != 1 && i < wxinformationzth::getwxidnumber() && i != exam.wxID) {
		wxinformationzth::change1wxfriendlist(exam.wxID, i);//���д���ǰ�˻�
		cout << "����" << number << "�ź��ѹ�ϵ�ѽ���" << endl;
		system("PAUSE");
	}
	else if (i == exam.wxID) {
		cout << "�㲻�ܼ��Լ�Ϊ����" << endl;
		system("PAUSE");
	}
	else if (wxinformationzth::getwxfriendlist(exam.wxID, i) == 1) {
		cout << "�ѽ������ѹ�ϵ�������ظ�����" << endl;
		system("PAUSE");
	}
	if (i >= wxinformationzth::getwxidnumber()) {
		cout << "���û�������" << endl;
		system("PAUSE");
	}
}

void qqUserzth::addfriend(qqUserzth &exam) {//��Ӻ���
	system("cls");
	int i, number;
	cout << "��Ҫ��ӵĺ��ѱ�ţ�";
	cin >> number;//i<100
	i = number;
	if (qqinformationzth::getqqfriendlist(exam.qqID, i) != 1 && i < qqinformationzth::getqqidnumber() && i != exam.qqID) {
		qqinformationzth::change1qqfriendlist(exam.qqID, i);//���д���ǰ�˻�
		cout << "����" << number << "�ź��ѹ�ϵ�ѽ���" << endl;
		system("PAUSE");
	}
	else if (i == exam.qqID) {
		cout << "�㲻�ܼ��Լ�Ϊ����" << endl;
		system("PAUSE");
	}
	else if (qqinformationzth::getqqfriendlist(exam.qqID, i) == 1) {
		cout << "�ѽ������ѹ�ϵ�������ظ�����" << endl;
		system("PAUSE");
	}
	if (i >= qqinformationzth::getqqidnumber()) {
		cout << "���û�������" << endl;
		system("PAUSE");
	}
}

void wxUserzth::deletefriend(wxUserzth &exam) {//ɾ������
	system("cls");
	int i, number;
	cout << "������Ҫɾ���ĺ��ѱ��";
	cin >> number;
	i = number;
	if (wxinformationzth::getwxfriendlist(exam.wxID, i) == 1) {
		wxinformationzth::change0wxfriendlist(exam.wxID, i);
		cout << "����" << number << "�ź��ѹ�ϵ��ɾ��" << endl;
		system("PAUSE");
	}
	else if (wxinformationzth::getwxfriendlist(exam.wxID, i) == 0) {
		cout << "����ú�����δ�������ѹ�ϵ" << endl;
		system("PAUSE");
	}
}

void qqUserzth::deletefriend(qqUserzth &exam) {//ɾ������
	system("cls");
	int i, number;
	cout << "������Ҫɾ���ĺ��ѱ��";
	cin >> number;
	i = number;
	if (qqinformationzth::getqqfriendlist(exam.qqID, i) == 1) {
		qqinformationzth::change0qqfriendlist(exam.qqID, i);
		cout << "����" << number << "�ź��ѹ�ϵ��ɾ��" << endl;
		system("PAUSE");
	}
	else if (qqinformationzth::getqqfriendlist(exam.qqID, i) == 0) {
		cout << "����ú�����δ�������ѹ�ϵ" << endl;
		system("PAUSE");
	}
}

void wxUserzth::findfriend(wxUserzth &exam) {//�ҵ����к���
	system("cls");
	int i, number = 0;
	for (i = 0;i < wxinformationzth::getwxidnumber();i++) {
		if ((wxinformationzth::getwxfriendlist(exam.wxID, i) == 1) && (wxinformationzth::getwxfriendlist(i, exam.wxID) == 0)) {
			cout << "����" << i << "���ѽ������ߺ��ѹ�ϵ" << endl;
			number++;
		}
		else if ((wxinformationzth::getwxfriendlist(exam.wxID, i) == 1) && (wxinformationzth::getwxfriendlist(i, exam.wxID) == 1) && (i != exam.wxID)) {
			cout << "����" << i << "���ѽ���˫�ߺ��ѹ�ϵ" << endl;
			number++;
		}
	}
	if (number == 0) {
		cout << "��δ���κ��˽������ѹ�ϵ" << endl;
	}
	system("PAUSE");
}

void qqUserzth::findfriend(qqUserzth &exam) {//�ҵ����к���
	system("cls");
	int i, number = 0;
	for (i = 0;i < qqinformationzth::getqqidnumber();i++) {
		if ((qqinformationzth::getqqfriendlist(exam.qqID, i) == 1) && (qqinformationzth::getqqfriendlist(i, exam.qqID) == 0)) {
			cout << "����" << i << "���ѽ������ߺ��ѹ�ϵ" << endl;
			number++;
		}
		else if ((qqinformationzth::getqqfriendlist(exam.qqID, i) == 1) && (qqinformationzth::getqqfriendlist(i, exam.qqID) == 1) && (i != exam.qqID)) {
			cout << "����" << i << "���ѽ���˫�ߺ��ѹ�ϵ" << endl;
			number++;
		}
	}
	if (number == 0) {
		cout << "��δ���κ��˽������ѹ�ϵ" << endl;
	}
	system("PAUSE");
}

int wxUserzth::creategroup(wxUserzth &exam) {//��Ⱥ
	int  number;

	cout << "���봴��һ����Ⱥ��" << endl;
	wxinformationzth::change1wxgrouplist(exam.wxID, wxinformationzth::getwxgroupnumber());//����Ϊ�û�����ΪȺ��
	number = wxinformationzth::getwxgroupnumber() + 1001;
	cout << "Ⱥ��Ϊ" << number << "��Ⱥ�ѽ���" << endl;
	wxinformationzth::change3wxlevel(exam.wxID, wxinformationzth::getwxgroupnumber());
	wxinformationzth::changewxgroupnumber(1);
	getchar();
	return number;
}

int qqUserzth::creategroup(qqUserzth &exam) {//��Ⱥ
	int  number;

	cout << "���봴��һ����Ⱥ��" << endl;
	qqinformationzth::change1qqgrouplist(exam.qqID, qqinformationzth::getqqgroupnumber());//����Ϊ�û�����ΪȺ��
	number = qqinformationzth::getqqgroupnumber() + 1001;
	cout << "Ⱥ��Ϊ" << number << "��Ⱥ�ѽ���" << endl;
	qqinformationzth::change3qqlevel(exam.qqID, qqinformationzth::getqqgroupnumber());
	qqinformationzth::changeqqgroupnumber(1);
	getchar();
	return number;
}

void wxUserzth::findjoinin(wxUserzth &exam) {
	int i, m, number = 0;
	for (i = 0;i < wxinformationzth::getwxgroupnumber();i++) {
		if (wxinformationzth::getwxjoinin(exam.wxID, i)) {
			cout << "�㱻�������" << i + 1001 << "��Ⱥ" << endl;
			cout << "�Ƿ�����Ⱥ��1-���룬2-�����룬���������ʸ�3-�����룬���������ʸ�-1�˳�)" << endl;
			cin >> m;
			if (m == 1) {
				wxinformationzth::change1wxgrouplist(exam.wxID, i);
				cout << "���Ѿ�������" << i + 1001 << "��Ⱥ";
			}
			if (m == 2) {
				cout << "�Ƽ�������״" << endl;
			}
			if (m == 3) {
				wxinformationzth::change0wxjoinin(exam.wxID, i);
				cout << "���ѷ��������ʸ�" << endl;
			}
			number++;
		}
	}
	if (number == 0) {
		cout << "��δ���κ���������Ⱥ" << endl;
	}
}

void qqUserzth::findjoinin(qqUserzth &exam) {//��Ⱥ
	int i, number;
	cout << "������뼸��Ⱥ����10XX��";
	cin >> number;
	i = number - 1 - 1000;
	if (i > qqinformationzth::getqqgroupnumber() - 1) {
		cout << "��Ⱥ��δ����" << endl;
	}
	else if (i >= 0 && i <= qqinformationzth::getqqgroupnumber() - 1 && qqinformationzth::getqqgrouplist(exam.qqID, i) != 1) {
		qqinformationzth::change1qqjoinin(exam.qqID, qqinformationzth::getqqgroupnumber() - 1);
		cout << "�����������" << number << "��Ⱥ";
	}
	else if (i >= 0 && i < qqinformationzth::getqqgroupnumber() - 1 && qqinformationzth::getqqgrouplist(exam.qqID, i) == 1) {
		cout << "���Ѿ��ڸ�Ⱥ�ڣ������ظ����" << endl;
	}
	else if (i < 0) {
		cout << "�����ڸ�Ⱥ" << endl;
	}
}

void wxUserzth::findgroup(wxUserzth &exam) {//��Ⱥ
	int i, number = 0;
	for (i = 0;i < wxinformationzth::getwxgroupnumber();i++) {
		if (wxinformationzth::getwxgrouplist(exam.wxID, i) == 1) {
			cout << "����" << i + 1001 << "��Ⱥ��" << endl;
			number++;
		}
	}
	if (number == 0) {
		cout << "��û�м����κ�Ⱥ" << endl;
	}
}

void qqUserzth::findgroup(qqUserzth &exam) {//��Ⱥ
	int i, number = 0;
	for (i = 0;i < qqinformationzth::getqqgroupnumber();i++) {
		if (qqinformationzth::getqqgrouplist(exam.qqID, i) == 1) {
			cout << "����" << i + 1001 << "��Ⱥ��" << endl;
			number++;
		}
	}
	if (number == 0) {
		cout << "��û�м����κ�Ⱥ" << endl;
	}
}

void findwxgroupmember(int i) {
	int f;
	int number = i - 1001;
	if (number < wxinformationzth::getwxgroupnumber() && number >= 0) {
		cout << i << "Ⱥ" << endl;
		for (f = 0;f < wxinformationzth::getwxidnumber();f++) {
			if (wxinformationzth::getwxgrouplist(f, number) == 1) {
				cout << f << "�ų�Ա��Ⱥ��" << ",��Ⱥ�ڵȼ�Ϊ";
				if (wxinformationzth::getwxlevel(f, number) == 1) {
					cout << "ȺԱ" << endl;
				}
				if (wxinformationzth::getwxlevel(f, number) == 3) {
					cout << "Ⱥ��" << endl;
				}
			}
		}
	}
	else if (1) {
		cout << "�����ڸ�Ⱥ��" << endl;
	}
}

void findqqgroupmember(int i) {
	int f;
	int number = i - 1001;
	if (number < qqinformationzth::getqqgroupnumber() && number >= 0) {
		cout << i << "Ⱥ" << endl;
		for (f = 0;f < qqinformationzth::getqqidnumber();f++) {
			if (qqinformationzth::getqqgrouplist(f, number) == 1) {
				cout << f << "�ų�Ա��Ⱥ��" << ",��Ⱥ�ڵȼ�Ϊ";
				if (qqinformationzth::getqqlevel(f, number) == 1) {
					cout << "ȺԱ" << endl;
				}
				if (qqinformationzth::getqqlevel(f, number) == 3) {
					cout << "Ⱥ��" << endl;
				}
			}
		}
	}
	else if (1) {
		cout << "�����ڸ�Ⱥ��" << endl;
	}
}

void wxUserzth::groupmanage(wxUserzth &exam, int i) {//iΪȺ��//Ⱥ����
	int m, p, q, t;//m��¼����λ�ã�pΪ�߳���Ա��ţ�qΪѭ������,tΪ�����Ƿ�ͬ��
	m = i - 1001;
	int n;
	if (m > wxinformationzth::getwxgroupnumber() - 1) {
		cout << "��Ⱥ��δ����" << endl;
		return;
	}
	if (wxinformationzth::getwxgrouplist(exam.wxID, m) == 0) {
		cout << "��δ�����Ⱥ" << endl;
		return;
	}
	if (m <= wxinformationzth::getwxgroupnumber() - 1) {//-----------------------------------------------------------------------------1
		if (wxinformationzth::getwxlevel(exam.wxID, m) == 1) {//---------------------------------------------------------------------------2
		wxlevel1start:
			cout << "��1�����û����룬��2�˳�Ⱥ����3�������˵�" << endl;
			cin >> n;
			if (n == 1) {
				cout << "��ϣ��������û��ǣ�" << endl;
				cin >> n;
				if (wxinformationzth::getwxjoinin(n, m) == 0 && wxinformationzth::getwxgrouplist(n, m) != 1 && n >= 0 && n < wxinformationzth::getwxidnumber()) {
					wxinformationzth::change1wxjoinin(exam.wxID, m);
					cout << "��������" << n << "���û���Ⱥ" << endl;
					system("PAUSE");
				}
				else if (wxinformationzth::getwxjoinin(n, m) == 1) {
					cout << "���û��ѱ�����������Ⱥ" << endl;
					system("PAUSE");
				}
				else if (wxinformationzth::getwxgrouplist(n, m) == 1) {
					cout << "���û�����Ⱥ��" << endl;
					system("PAUSE");
				}
				else if (n < 0 && n >= wxinformationzth::getwxidnumber()) {
					cout << "���û�������" << endl;
					system("PAUSE");
				}
				goto wxlevel1start;
			}
			if (n == 2) {
				wxinformationzth::change0wxgrouplist(exam.wxID, m);
				cout << "�����˳�" << i << "��Ⱥ" << endl;
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
			cout << "��1��Ⱥ������2�����û���Ⱥ����3�߳�Ⱥ��Ա����4�˳�Ⱥ����5�������˵�" << endl;
			cin >> n;
			if (n == 1) {//----------------------------------------------------------------------------------------------3
				cout << "�������ΪȺ�����û��ǣ����㽫��Ϊ����Ա����";
				findwxgroupmember(i);
				cin >> n;
				if (wxinformationzth::getwxgrouplist(n, m) == 0) {//-------------------------------------------------------------------4
					cout << "���û���δ�����Ⱥ";
					system("PAUSE");
					goto wxlevelstart;
				}
				else if (wxinformationzth::getwxgrouplist(n, m) == 1 && wxinformationzth::getwxlevel(n, m) == 3) {
					cout << "���Ѿ��Ǹ�Ⱥ��Ⱥ��" << endl;
					system("PAUSE");
					goto wxlevelstart;
				}
				else if (wxinformationzth::getwxgrouplist(n, m) == 1) {
					cout << "���Ϊ" << n << "���û���Ϊ��Ⱥ��" << endl;
					wxinformationzth::change3wxlevel(n, m);
					wxinformationzth::change1wxlevel(exam.wxID, m);
					system("PAUSE");
					goto wxlevelstart;
				}
			}
			if (n == 2) {
				cout << "��ϣ��������û��ǣ�" << endl;
				cin >> n;
				if (wxinformationzth::getwxjoinin(n, m) == 0 && wxinformationzth::getwxgrouplist(n, m) != 1 && n >= 0 && n < wxinformationzth::getwxidnumber()) {
					wxinformationzth::change1wxjoinin(n, m);
					cout << "��������" << n << "���û���Ⱥ" << endl;
					system("PAUSE");
				}
				else if (wxinformationzth::getwxjoinin(n, m) == 1) {
					cout << "���û��ѱ�����������Ⱥ" << endl;
					system("PAUSE");
				}
				else if (wxinformationzth::getwxgrouplist(n, m) == 1) {
					cout << "���û�����Ⱥ��" << endl;
					system("PAUSE");
				}
				else if (n < 0 && n >= wxinformationzth::getwxidnumber()) {
					cout << "���û�������" << endl;
					system("PAUSE");
				}
				goto wxlevelstart;
			}
			if (n == 3) {
				cout << "��������Ҫ�߳��ĳ�Ա��ţ�";
				findwxgroupmember(i);
				cin >> p;
				if (wxinformationzth::getwxgrouplist(p, m) == 1 && p != exam.wxID) {
					wxinformationzth::change0wxgrouplist(p, m);
					cout << "��Ա" << p << "���߳�";
					system("PAUSE");
					goto wxlevelstart;
				}
				else if (wxinformationzth::getwxgrouplist(p, m) == 0) {
					cout << "���û�����Ⱥ��" << endl;
					system("PAUSE");
					goto wxlevelstart;
				}
				else if (p == exam.wxID) {
					cout << "�㲻���߳��Լ�" << endl;
					system("PAUSE");
					goto wxlevelstart;
				}
			}
			if (n == 4) {
				wxinformationzth::change0wxgrouplist(exam.wxID, m);
				cout << "�����˳�" << i << "��Ⱥ" << endl;
				wxinformationzth::change0wxlevel(exam.wxID, m);
				for (q = 0;q < wxinformationzth::getwxidnumber();q++) {
					if (wxinformationzth::getwxlevel(q, m) == 1) {
						wxinformationzth::change3wxlevel(q, m);
						cout << "���Ϊ" << q << "���û��Ѵ�ȺԱ��ΪȺ��";
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

void qqUserzth::groupmanage(qqUserzth &exam, int i) {//iΪȺ��//Ⱥ����
	int m, p, q, t;//m��¼����λ�ã�pΪ�߳���Ա��ţ�qΪѭ������,tΪ�����Ƿ�ͬ��
	m = i - 1001;
	int n;
	if (m > qqinformationzth::getqqgroupnumber() - 1) {
		cout << "��Ⱥ��δ����" << endl;
		return;
	}
	if (qqinformationzth::getqqgrouplist(exam.qqID, m) == 0) {
		cout << "��δ�����Ⱥ" << endl;
		return;
	}
	if (m <= qqinformationzth::getqqgroupnumber() - 1) {
		if (qqinformationzth::getqqlevel(exam.qqID, m) == 1) {
			cout << "��1�˳�Ⱥ����2�������˵�" << endl;
			cin >> n;
			if (n == 1) {
				qqinformationzth::change0qqgrouplist(exam.qqID, m);
				cout << "�����˳�" << i << "��Ⱥ" << endl;
				qqinformationzth::change0qqlevel(exam.qqID, m);
			}
			if (n == 2) {
				return;
			}
		}
		if (qqinformationzth::getqqlevel(exam.qqID, m) == 2) {
		qqlevelstart:
			int b = 0;//�������
			system("cls");
			cout << "��1������Ⱥ���룬��2�߳�Ⱥ��Ա����3�˳�Ⱥ����4�������˵�" << endl;
			cin >> n;
			if (n == 1) {
				for (q = 0;q < qqinformationzth::getqqidnumber();q++) {
					if (qqinformationzth::getqqjoinin(q, m) == 1) {
						cout << "���Ϊ" << q << "���û��������Ⱥ" << endl;
						cout << "ͬ�ⰴ1����ͬ�ⰴ0" << endl;
						cin >> t;
						if (t == 0) {
							qqinformationzth::change0qqjoinin(q, m);
							cout << "���Ϊ" << q << "���û��ѱ���ܾ���Ⱥ";
							b++;
						}
						if (t == 1) {
							qqinformationzth::change0qqjoinin(q, m);
							qqinformationzth::change1qqgrouplist(q, m);
							cout << "������Ϊ" << q << "���û�����Ⱥ";
							qqinformationzth::change1qqlevel(q, m);//��ʼ���ȼ�ΪȺԱ
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
				if (qqinformationzth::getqqgrouplist(p, m) == 1 && p != exam.qqID&&qqinformationzth::getqqlevel(p, m) == 1) {
					qqinformationzth::change0qqgrouplist(p, m);
					cout << "��Ա" << p << "���߳�";
					system("PAUSE");
					goto qqlevelstart;
				}
				else if (qqinformationzth::getqqgrouplist(p, m) == 1 && p != exam.qqID&&qqinformationzth::getqqlevel(p, m) != 1) {
					cout << "���޷��߳�����Ա��Ⱥ��" << endl;
					system("PAUSE");
					goto qqlevelstart;
				}
				else if (qqinformationzth::getqqgrouplist(p, m) == 0) {
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
				qqinformationzth::change0qqgrouplist(exam.qqID, m);
				cout << "�����˳�" << i << "��Ⱥ" << endl;
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
			cout << "��1������Ⱥ���룬��2����ȺԱ�ȼ�����3�߳�Ⱥ��Ա�����Ա����4�˳�Ⱥ����5�������˵�" << endl;
			cin >> n;
			if (n == 1) {
				for (q = 0;q < qqinformationzth::getqqidnumber();q++) {
					if (qqinformationzth::getqqjoinin(q, m) == 1) {
						cout << "���Ϊ" << q << "���û��������Ⱥ" << endl;
						cout << "ͬ�ⰴ1����ͬ�ⰴ0" << endl;
						cin >> t;
						if (t == 0) {
							qqinformationzth::change0qqjoinin(q, m);
							cout << "���Ϊ" << q << "���û��ѱ���ܾ���Ⱥ";
							b++;
						}
						if (t == 1) {
							qqinformationzth::change0qqjoinin(q, m);
							qqinformationzth::change1qqgrouplist(q, m);
							cout << "������Ϊ" << q << "���û�����Ⱥ";
							qqinformationzth::change1qqlevel(q, m);//��ʼ���ȼ�ΪȺԱ
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
					if (qqinformationzth::getqqgrouplist(n, m) == 0) {
						cout << "���û���δ�����Ⱥ";
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (n == exam.qqID) {
						cout << "������Ⱥ��" << endl;
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (qqinformationzth::getqqgrouplist(n, m) == 1 && qqinformationzth::getqqlevel(n, m) == 2) {
						cout << "���û��Ѿ��Ǹ�Ⱥ�Ĺ���Ա" << endl;
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (qqinformationzth::getqqgrouplist(n, m) == 1 && qqinformationzth::getqqlevel(n, m) == 1) {
						cout << "���Ϊ" << n << "���û���Ϊ�˹���Ա" << endl;
						qqinformationzth::change2qqlevel(n, m);
						system("PAUSE");
						goto qqlevel3start;
					}
				}
				if (n == 2) {
					cout << "���뽵ΪȺԱ���û����Ϊ��";
					findqqgroupmember(i);
					cin >> n;
					if (qqinformationzth::getqqgrouplist(n, m) == 0) {
						cout << "���û���δ�����Ⱥ";
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (n == exam.qqID) {
						cout << "������Ⱥ��" << endl;
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (qqinformationzth::getqqgrouplist(n, m) == 1 && qqinformationzth::getqqlevel(n, m) == 1) {
						cout << "���û��Ѿ��Ǹ�Ⱥ��ȺԱ" << endl;
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (qqinformationzth::getqqgrouplist(n, m) == 1 && qqinformationzth::getqqlevel(n, m) == 2) {
						cout << "���Ϊ" << n << "���û���Ϊ��ȺԱ" << endl;
						qqinformationzth::change1qqlevel(n, m);
						system("PAUSE");
						goto qqlevel3start;
					}
				}
				if (n == 3) {
					cout << "�������ΪȺ�����û��ǣ����㽫��Ϊ����Ա����";
					findqqgroupmember(i);
					cin >> n;
					if (qqinformationzth::getqqgrouplist(n, m) == 0) {
						cout << "���û���δ�����Ⱥ";
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (qqinformationzth::getqqgrouplist(n, m) == 1 && qqinformationzth::getqqlevel(n, m) == 3) {
						cout << "���Ѿ��Ǹ�Ⱥ��Ⱥ��" << endl;
						system("PAUSE");
						goto qqlevel3start;
					}
					else if (qqinformationzth::getqqgrouplist(n, m) == 1) {
						cout << "���Ϊ" << n << "���û���Ϊ��Ⱥ��" << endl;
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
				cout << "��������Ҫ�߳��ĳ�Ա��ţ�";
				findqqgroupmember(i);
				cin >> p;
				if (qqinformationzth::getqqgrouplist(p, m) == 1 && p != exam.qqID) {
					qqinformationzth::change0qqgrouplist(p, m);
					cout << "��Ա" << p << "���߳�";
					system("PAUSE");
					goto qqlevel2start;
				}
				else if (qqinformationzth::getqqgrouplist(p, m) == 0) {
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
				qqinformationzth::change0qqgrouplist(exam.qqID, m);
				cout << "�����˳�" << i << "��Ⱥ" << endl;
				qqinformationzth::change0qqlevel(exam.qqID, m);
				for (q = 0;q < qqinformationzth::getqqidnumber();q++) {
					if (qqinformationzth::getqqlevel(q, m) == 2) {
						qqinformationzth::change3qqlevel(q, m);
						cout << "���Ϊ" << q << "���û��Ѵӹ���Ա��ΪȺ��";
						break;
					}
					if (qqinformationzth::getqqlevel(q, m) == 1) {
						qqinformationzth::change3qqlevel(q, m);
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

int link[100][100] = { 0 };
void linkqq(wxUserzth exam) {//wx����
	int n, i,number=0;
	cout << "������ĸ�qq��(-1�˳�);" << endl;
	while (1) {
		cin >> n;
		if (n == -1) {
			return;
		}
		if (n < qqinformationzth::getqqidnumber()) {//�ж��Ƿ��Ѿ��иú�
			for (i = 0;i < wxinformationzth::getwxidnumber();i++) {
				if (link[n][i] == 1 && i != exam.wxID) {
					cout << "���˺��ѱ���" << endl;
					number++;
					return;
				}
				else if (link[n][exam.wxID] == 1) {
					cout << "���Ѿ����˸�qq�˺�" << endl;
					system("PAUSE");
					return;
				}

			}
			for (i = 0;i < qqinformationzth::getqqidnumber();i++) {
				if (link[i][exam.wxID] == 1) {
					cout << "���Ѿ�����һ���˺�" << endl;
					system("PAUSE");
					return;
				}
			}
			if (link[n][exam.wxID] == 0&&number==0) {
				link[n][exam.wxID] = 1;
				cout << "�Ѱ�qq���Ϊ" << n << "���û�" << endl;
				exam.qqID = n;
				system("PAUSE");
				return;
			}
		}
		else if (1) {
			cout << "�������qq�û�������" << endl;
		}
	}
}
void linkwx(qqUserzth exam) {//wx����
	int n, i,number=0;
	cout << "������ĸ�΢�ź�(-1�˳�);" << endl;
	while (1) {
		cin >> n;
		if (n == -1) {
			return;
		}
		if (n < wxinformationzth::getwxidnumber()) {//�ж��Ƿ��Ѿ��иú�
			for (i = 0;i < qqinformationzth::getqqidnumber();i++) {
				if (link[i][n] == 1 && i != exam.qqID) {
					cout << "���˺��ѱ���" << endl;
					system("PAUSE");
					return;
				}
				else if (link[exam.qqID][n] == 1) {
					cout << "���Ѿ����˸�΢���˺�" << endl;
					system("PAUSE");
					return;
				}

			}
			for (i = 0;i < wxinformationzth::getwxidnumber();i++) {
				if (link[exam.qqID][i] == 1) {
					cout << "���Ѿ�����һ���˺�" << endl;
					system("PAUSE");
					return;
				}
			}
			if (link[exam.qqID][n] == 0&&number==0) {
				link[exam.qqID][n] = 1;
				cout << "�Ѱ�΢�ű��Ϊ" << n << "���û�" << endl;
				system("PAUSE");
				return;
			}
		}
		else if (1) {
			cout << "�������΢���û�������" << endl;
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
		cout << "���б����΢�ź����ѿ�ͨqq���У�" << endl;
		
		for (i = 0;i < wxinformationzth::getwxidnumber();i++) {//5
			if (wxinformationzth::getwxfriendlist(exam.wxID, i) == 1) {//6
				for (j = 0;j < qqinformationzth::getqqidnumber();j++) {//7
					if (link[j][i] == 1) {//8
                   cout << "���" << i << "��΢�ź����ѿ�ͨqq����qq�û���Ϊ��" << j << endl;//
				   if (qqinformationzth::getqqfriendlist(q, j) == 0) {
					   cout << "�Ƿ���ӣ�1-�ǣ�2-��" << endl;
					   cin >> m;
					   if (m == 1) {
						   qqinformationzth::change1qqfriendlist(q, j);
						   cout << "��ӳɹ�" << endl;
					   }
				   }
				   else if (qqinformationzth::getqqfriendlist(q, j) == 1) {
					   cout << "�����" << endl;
				   }
					}//8
				}//7
			}//6
		}//5
	}//4
	else if (number==0) {//9
		cout << "��δ��ͨqq" << endl;
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
		cout << "���б����qq�����ѿ�ͨ΢�ŵ��У�" << endl;

		for (i = 0;i <qqinformationzth::getqqidnumber();i++) {//5
			if (qqinformationzth::getqqfriendlist(exam.qqID, i) == 1) {//6
				for (j = 0;j < wxinformationzth::getwxidnumber();j++) {//7
					if (link[j][i] == 1) {//8
						cout << "���" << i << "��qq�����ѿ�ͨ΢�ţ���΢���û���Ϊ��" << j << endl;//
						if (wxinformationzth::getwxfriendlist(q, j) == 0) {
							cout << "�Ƿ���ӣ�1-�ǣ�2-��" << endl;
							cin >> m;
							if (m == 1) {
								wxinformationzth::change1wxfriendlist(q, j);
								cout << "��ӳɹ�" << endl;
							}
						}
						else if (wxinformationzth::getwxfriendlist(q, j) == 1) {
							cout << "�����" << endl;
						}
					}//8
				}//7
			}//6
		}//5
	}//4
	else if (number == 0) {//9
		cout << "��δ��ͨ΢��" << endl;
	}//9
}


void qqdiscuss(qqUserzth &exam) {//��ʱ������
	int j, p, n;
	cout << "���봴���ĸ�Ⱥ����ʱ�����飿" << endl;
	exam.findgroup(exam);
	cin >> n;
	j = exam.creategroup(exam);
	findqqgroupmember(n);
	cout << "����Ҫ������Щ��Ա���������飿����-1���������˳���" << endl;
	while (1) {
		cin >> p;
		if (qqinformationzth::getqqgrouplist(p, n - 1001) == 1 && qqinformationzth::getqqgrouplist(p, j - 1001) != 1) {
			qqinformationzth::change1qqgrouplist(p, j - 1001);
			cout << "��Ա" << p << "�Ѽ�������Ⱥ" << endl;
		}
		else if (qqinformationzth::getqqgrouplist(p, n - 1001) == 1 && qqinformationzth::getqqgrouplist(p, j - 1001) == 1) {
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

void wxUserzth::menu(wxUserzth &exam) {
	int n;
wxstart:
	system("cls");
	cout << "1-�鿴���Ѳ����б�" << endl;
	cout << "2-�鿴Ⱥ�����б�" << endl;
	cout << "3-�޸ĸ�����Ϣ" << endl;
	cout << "4-��qq�˺�" << endl;
	cout << "5-����wxƽ̨" << endl;
	cin >> n;
	if (n == 1) {
	wxfriendstart:
		system("cls");
		cout << "����Ժ����б����ʲô������" << endl;
		cout << "1-��Ӻ���" << endl;
		cout << "2-ɾ������" << endl;
		cout << "3-�鿴�����б�" << endl;
		cout << "4-��Ӻ�������ƽ̨���˺�" << endl;
		cout << "5-���ز˵�" << endl;
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
		cout << "1-���Ⱥ" << endl;
		cout << "2-������Ⱥ" << endl;
		cout << "3-����Ⱥ" << endl;
		cout << "4-�鿴Ⱥ" << endl;
		cout << "5-���ز˵�" << endl;
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
			cout << "Ŀǰ�Ѽ����Ⱥ�У�" << endl;
			exam.findgroup(exam);
			cout << "��������ĸ�Ⱥ�Ĺ���" << endl;
			cin >> n;
			system("cls");
			exam.groupmanage(exam, n);
			system("PAUSE");
			goto wxgroupstart;
		}
		if (n == 4) {
			system("cls");
			cout << "Ŀǰ�Ѽ����Ⱥ�У�" << endl;
			exam.findgroup(exam);
			cout << "����鿴��Ա��ȺΪ��" << endl;
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
		cout << "��Ŀǰ������Ϊ��" << endl;
		cout << "�ǳ�Ϊ" << exam.wxnickname << endl;
		cout << "����Ϊ" << exam.wxage << endl;
		cout << "����Ϊ" << exam.wxbirthday << endl;
		cout << "���ڵ�Ϊ" << exam.wxlocal << endl;
		cout << "�����޸ĵ������ǣ�(-1���أ�" << endl;
		cout << "1-�ǳ�" << endl;
		cout << "2-����" << endl;
		cout << "3-����ʱ��" << endl;
		cout << "4-���ڵ�" << endl;
		cin >> n;
		if (n == 1) {
			system("cls");
			cout << "���ڵ��ǳ�Ϊ" << exam.wxnickname << endl;
			cout << "�����޸�Ϊ:" << endl;
			cin >> kk;
			exam.wxnickname = kk;
			cout << "�޸���ɣ������ǳ�Ϊ:  " << exam.wxnickname << endl;
		}
		if (n == 2) {
			system("cls");
			cout << "���ڵ�����Ϊ" << exam.wxage << endl;
			cout << "�����޸�Ϊ:" << endl;
			cin >> ii;
			exam.wxage = ii;
			cout << "�޸���ɣ���������Ϊ:  " << exam.wxage << endl;
		}
		if (n == 3) {
			system("cls");
			cout << "���ڵĳ�������Ϊ" << exam.wxbirthday << endl;
			cout << "�����޸�Ϊ:" << endl;
			cin >> ii;
			exam.wxbirthday = ii;
			cout << "�޸���ɣ����ڳ�������Ϊ:  " << exam.wxbirthday << endl;
		}
		if (n == 4) {
			system("cls");
			cout << "���ڵ����ڵ�Ϊ" << exam.wxlocal << endl;
			cout << "�����޸�Ϊ:" << endl;
			cin >> kk;
			exam.wxlocal = kk;
			cout << "�޸���ɣ��������ڵ�Ϊ:  " << exam.wxlocal << endl;
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
	cout << "1-�鿴���Ѳ����б�" << endl;
	cout << "2-�鿴Ⱥ�����б�" << endl;
	cout << "3-�޸ĸ�����Ϣ" << endl;
	cout << "4-��΢���˺�" << endl;
	cout << "5-����qqƽ̨" << endl;
	cin >> n;
	if (n == 1) {
	qqfriendstart:
		system("cls");

		cout << "����Ժ����б����ʲô������" << endl;
		cout << "1-��Ӻ���" << endl;
		cout << "2-ɾ������" << endl;
		cout << "3-�鿴�����б�" << endl;
		cout << "4-��Ӻ�������ƽ̨���˺�" << endl;
		cout << "5-���ز˵�" << endl;
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
		cout << "1-���Ⱥ" << endl;
		cout << "2-������Ⱥ" << endl;
		cout << "3-����Ⱥ" << endl;
		cout << "4-�鿴Ⱥ" << endl;
		cout << "5-���ز˵�" << endl;
		cin >> n;
		if (n == 1) {
			system("cls");
			exam.findjoinin(exam);
			system("PAUSE");
			goto qqgroupstart;
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
			cout << "Ŀǰ�Ѽ����Ⱥ�У�" << endl;
			exam.findgroup(exam);
			cout << "��������ĸ�Ⱥ�Ĺ���" << endl;
			cin >> n;
			system("cls");
			exam.groupmanage(exam, n);
			system("PAUSE");
			goto qqgroupstart;
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
		cout << "��Ŀǰ������Ϊ��" << endl;
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
			cout << "�޸���ɣ���������Ϊ:  " << exam.qqage << endl;
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
		cout << "1-��¼,2-�������˺�,3-����" << endl;
		cin >> pp;
		system("cls");

		if (pp == 1) {
			cout << "�����¼���" << endl;
			cin >> n;
			exam = wxidfind(n);
			cout << "�ҵ��û���׼����¼......" << endl;
			system("PAUSE");
			exam.menu(exam);
		}
		else if (pp == 2) {
			cout << "׼���������û�" << endl;
			cout << "1-����" << endl;
			cout << "2-����" << endl;
			cin >> n;
			if (n == 1) {
				cout << "ǰ��ע�����..." << endl;
				system("PAUSE");
				wxUserzthlist[wxinformationzth::getwxidnumber() - 1] = createwx();
				cout << "׼��ǰ����¼����" << endl;
				system("PAUSE");
			}
		}
		if (pp == 3) {
			return;
		}
		else if (pp != 1 && pp != 2&&pp!=3) {
			cout << "�������" << endl;
			system("PAUSE");
		}
	}
}

void qqloading() {
	while (1) {
		system("cls");
		int n,pp;
		qqUserzth exam;
		cout << "1-��¼,2-�������˺�,3-����" << endl;
		cin >> pp;
		system("cls");

		if (pp == 1) {
			cout << "�����¼���" << endl;
			cin >> n;
			exam = qqidfind(n);
			cout << "�ҵ��û���׼����¼......" << endl;
			system("PAUSE");
			exam.menu(exam);
		}
		else if (pp == 2) {
			cout << "׼���������û�" << endl;
			cout << "1-����" << endl;
			cout << "2-����" << endl;
			cin >> n;
			if (n == 1) {
				cout << "ǰ��ע�����..." << endl;
				system("PAUSE");
				qqUserzthlist[qqinformationzth::getqqidnumber() - 1] = createqq();
				cout << "׼��ǰ����¼����" << endl;
				system("PAUSE");
			}
		}
		if (pp == 3) {
			return;
		}
		else if (pp != 1 && pp != 2&&pp!=3) {
			cout << "�������" << endl;
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
	aa.qqlocal = "����";
	aa.qqyear = 231220;
	bb.qqnickname = "����˭qq";
	bb.qqage = 222;
	bb.qqbirthday = 20130414;
	bb.qqflag = 1;
	bb.qqlocal = "����";
	bb.qqyear = 221134;
	cc.wxnickname = "zthwx";
	cc.wxage = 23;
	cc.wxbirthday = 20190807;
	cc.wxflag = 1;
	cc.wxlocal = "����";
	cc.wxyear = 122222;
	dd.wxnickname = "����˭wx";
	dd.wxage = 22;
	dd.wxbirthday = 20030403;
	dd.wxflag = 1;
	dd.wxlocal = "�Ͼ�";
	dd.wxyear = 190824;
	qqUserzthlist[0] = aa;
	qqUserzthlist[1] = bb;
	wxUserzthlist[0] = cc;
	wxUserzthlist[1] = dd;
	
}
void platform() {
	int n;
	while (1) {
	cout << "���ƽ̨������������˰�zthԭ��" << endl;
	cout << "1-wxƽ̨" << endl;
	cout << "2-qqƽ̨" << endl;
	cout << "3-����ƽ̨�Ŀ�ͨ���" << endl;
		cin >> n;
		if (n == 1) {
			wxloading();
		}
		if (n == 2) {
			qqloading();
		}
		if (n == 3) {
			cout << "1-��ͨ΢��" << endl;
			cin >> n;
			if (n != 1) {
				cout << "�������" << endl;
				system("PAUSE");
			}
			if (n == 1) {
				cout << "΢�� �ѿ�ͨ" << endl;
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
