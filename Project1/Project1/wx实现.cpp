#include"�û���Ϣzth.h";
#include"wx��Ϣzth.h";
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
	exam.wxID = wxinformation::getwxidnumber();//��һ��Ϊ0
	wxinformation::changewxidnumber(1);//id+1
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
	exam.wxflag=1;
	exam.wxyear = getmytime();
	cout << "wxyear:" << exam.wxyear << endl;
	cout << "ע������ɣ����ȡ��ĵ�¼���:";
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
	cout << "δ�ҵ�"<<i<<"��΢���û�" << endl;
	system("PAUSE");
}
void wxUser::addfriend(wxUser &exam) {//��Ӻ���
	system("cls");
	int i, number;
	cout << "��Ҫ��ӵĺ��ѱ�ţ�";
	cin >> number;//i<100
	i = number;
	if (wxinformation::getwxfriendlist(exam.wxID, i) != 1 && i < wxinformation::getwxidnumber()&&i!=exam.wxID) {
		wxinformation::change1wxfriendlist(exam.wxID, i);//���д���ǰ�˻�
		cout << "����" << number << "�ź��ѹ�ϵ�ѽ���" << endl;
		system("PAUSE");
	}
	else if (i == exam.wxID) {
		cout << "�㲻�ܼ��Լ�Ϊ����" << endl;
		system("PAUSE");
	}
	else if (wxinformation::getwxfriendlist(exam.wxID, i) == 1) {
		cout << "�ѽ������ѹ�ϵ�������ظ�����" << endl;
		system("PAUSE");
	}
	if (i >= wxinformation::getwxidnumber()) {
		cout << "���û�������" << endl;
		system("PAUSE");
	}
}
void wxUser::deletefriend(wxUser &exam) {//ɾ������
	system("cls");
	int i, number;
	cout << "������Ҫɾ���ĺ��ѱ��";
	cin >> number;
	i = number;
	if (wxinformation::getwxfriendlist(exam.wxID, i) == 1) {
		wxinformation::change0wxfriendlist(exam.wxID, i);
		cout << "����" << number << "�ź��ѹ�ϵ��ɾ��" << endl;
		system("PAUSE");
	}
	else if (wxinformation::getwxfriendlist(exam.wxID, i) == 0) {
		cout << "����ú�����δ�������ѹ�ϵ" << endl;
		system("PAUSE");
	}
}
void wxUser::findfriend(wxUser &exam) {//�ҵ����к���
	system("cls");
	int i, number = 0;
	for (i = 0;i < wxinformation::getwxidnumber();i++) {
		if ((wxinformation::getwxfriendlist(exam.wxID, i) == 1) && (wxinformation::getwxfriendlist(i, exam.wxID) == 0)) {
			cout << "����" << i << "���ѽ������ߺ��ѹ�ϵ" << endl;
			number++;
		}
		else if ((wxinformation::getwxfriendlist(exam.wxID, i) == 1) && (wxinformation::getwxfriendlist(i, exam.wxID) == 1) && (i != exam.wxID)) {
			cout << "����" << i << "���ѽ���˫�ߺ��ѹ�ϵ" << endl;
			number++;
		}
	}
	if (number == 0) {
		cout << "��δ���κ��˽������ѹ�ϵ" << endl;
	}
	system("PAUSE");
}
int wxUser::creategroup(wxUser &exam) {//��Ⱥ
	int  number;

	cout << "���봴��һ����Ⱥ��" << endl;
	wxinformation::change1wxgrouplist(exam.wxID, wxinformation::getwxgroupnumber());//����Ϊ�û�����ΪȺ��
	number = wxinformation::getwxgroupnumber() + 1001;
	cout << "Ⱥ��Ϊ" << number << "��Ⱥ�ѽ���" << endl;
	wxinformation::change3wxlevel(exam.wxID, wxinformation::getwxgroupnumber());
	wxinformation::changewxgroupnumber(1);
	getchar();
	return number;
}
void wxUser::findjoinin(wxUser &exam){
	int i, m,number=0;
	for (i = 0;i < wxinformation::getwxgroupnumber();i++) {
		if (wxinformation::getwxjoinin(exam.wxID,i)) {
			cout << "�㱻�������" << i+1001 << "��Ⱥ" << endl;
			cout << "�Ƿ�����Ⱥ��1-���룬2-�����룬���������ʸ�3-�����룬���������ʸ�-1�˳�)" << endl;
			cin >> m;
			if (m == 1) {
				wxinformation::change1wxgrouplist(exam.wxID, i);
				cout << "���Ѿ�������" << i + 1001 << "��Ⱥ";
			}
			if (m == 2) {
				cout << "�Ƽ�������״" << endl;
			}
			if (m == 3) {
				wxinformation::change0wxjoinin(exam.wxID, i);
				cout << "���ѷ��������ʸ�" << endl;
			}
			number++;
		}
	}
	if (number == 0) {
		cout << "��δ���κ���������Ⱥ" << endl;
	}
}
void wxUser::findgroup(wxUser &exam) {//��Ⱥ
	int i, number = 0;
	for (i = 0;i < wxinformation::getwxgroupnumber();i++) {
		if (wxinformation::getwxgrouplist(exam.wxID, i) == 1) {
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
	if (number<wxinformation::getwxgroupnumber()&&number>=0) {
		cout << i << "Ⱥ" << endl;
		for (f = 0;f < wxinformation::getwxidnumber();f++) {
			if (wxinformation::getwxgrouplist(f, number) == 1) {
				cout << f << "�ų�Ա��Ⱥ��" << ",��Ⱥ�ڵȼ�Ϊ";
				if (wxinformation::getwxlevel(f, number) == 1) {
					cout << "ȺԱ" << endl;
				}
				if (wxinformation::getwxlevel(f, number) == 3) {
					cout << "Ⱥ��" << endl;
				}
			}
		}
	}
	else if (1) {
		cout << "�����ڸ�Ⱥ��" << endl;
	}
}

void wxUser::groupmanage(wxUser &exam, int i) {//iΪȺ��//Ⱥ����
	int m, p, q, t;//m��¼����λ�ã�pΪ�߳���Ա��ţ�qΪѭ������,tΪ�����Ƿ�ͬ��
	m = i - 1001;
	int n;
	if (m > wxinformation::getwxgroupnumber() - 1) {
		cout << "��Ⱥ��δ����" << endl;
		return;
	}
	if (wxinformation::getwxgrouplist(exam.wxID, m) == 0) {
		cout << "��δ�����Ⱥ" << endl;
		return;
	}
	if (m <= wxinformation::getwxgroupnumber() - 1) {//-----------------------------------------------------------------------------1
		if (wxinformation::getwxlevel(exam.wxID, m) == 1) {//---------------------------------------------------------------------------2
			wxlevel1start:
			cout << "��1�����û����룬��2�˳�Ⱥ����3�������˵�" << endl;
			cin >> n;
			if (n == 1) {
				cout << "��ϣ��������û��ǣ�" << endl;
				cin >> n;
				if (wxinformation::getwxjoinin(n, m) == 0 && wxinformation::getwxgrouplist(n, m) != 1&&n>=0&&n<wxinformation::getwxidnumber()) {
					wxinformation::change1wxjoinin(exam.wxID, m);
					cout << "��������" << n << "���û���Ⱥ"<<endl;
					system("PAUSE");
				}
				else if (wxinformation::getwxjoinin(n, m) == 1) {
					cout << "���û��ѱ�����������Ⱥ" << endl;
					system("PAUSE");
				}
				else if (wxinformation::getwxgrouplist(n, m) == 1) {
					cout << "���û�����Ⱥ��" << endl;
					system("PAUSE");
				}
				else if (n < 0 && n >= wxinformation::getwxidnumber()) {
					cout << "���û�������" << endl;
					system("PAUSE");
				}
				goto wxlevel1start;
			}
			if (n == 2) {
				wxinformation::change0wxgrouplist(exam.wxID, m);
				cout << "�����˳�" << i << "��Ⱥ" << endl;
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
			cout << "��1��Ⱥ������2�����û���Ⱥ����3�߳�Ⱥ��Ա����4�˳�Ⱥ����5�������˵�" << endl;
			cin >> n;
			if (n == 1) {//----------------------------------------------------------------------------------------------3
				cout << "�������ΪȺ�����û��ǣ����㽫��Ϊ����Ա����";
				findwxgroupmember(i);
				cin >> n;
				if (wxinformation::getwxgrouplist(n, m) == 0) {//-------------------------------------------------------------------4
					cout << "���û���δ�����Ⱥ";
					system("PAUSE");
					goto wxlevelstart;
				}
				else if (wxinformation::getwxgrouplist(n, m) == 1 && wxinformation::getwxlevel(n, m) == 3) {
					cout << "���Ѿ��Ǹ�Ⱥ��Ⱥ��" << endl;
					system("PAUSE");
					goto wxlevelstart;
				}
				else if (wxinformation::getwxgrouplist(n, m) == 1) {
					cout << "���Ϊ" << n << "���û���Ϊ��Ⱥ��" << endl;
					wxinformation::change3wxlevel(n, m);
					wxinformation::change1wxlevel(exam.wxID, m);
					system("PAUSE");
					goto wxlevelstart;
				}
			}
			if (n == 2) {
				cout << "��ϣ��������û��ǣ�" << endl;
				cin >> n;
				if (wxinformation::getwxjoinin(n, m) == 0 && wxinformation::getwxgrouplist(n, m) != 1 && n >= 0 && n < wxinformation::getwxidnumber()) {
					wxinformation::change1wxjoinin(n, m);
					cout << "��������" << n << "���û���Ⱥ" << endl;
					system("PAUSE");
				}
				else if (wxinformation::getwxjoinin(n, m) == 1) {
					cout << "���û��ѱ�����������Ⱥ" << endl;
					system("PAUSE");
				}
				else if (wxinformation::getwxgrouplist(n, m) == 1) {
					cout << "���û�����Ⱥ��" << endl;
					system("PAUSE");
				}
				else if (n < 0 && n >= wxinformation::getwxidnumber()) {
					cout << "���û�������" << endl;
					system("PAUSE");
				}
				goto wxlevelstart;
			}
			if (n == 3) {
				findwxgroupmember(i);
				cout << "��������Ҫ�߳��ĳ�Ա��ţ�";
				findwxgroupmember(i);
				cin >> p;
				if (wxinformation::getwxgrouplist(p, m) == 1 && p != exam.wxID) {
					wxinformation::change0wxgrouplist(p, m);
					cout << "��Ա" << p << "���߳�";
					system("PAUSE");
					goto wxlevelstart;
				}
				else if (wxinformation::getwxgrouplist(p, m) == 0) {
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
				wxinformation::change0wxgrouplist(exam.wxID, m);
				cout << "�����˳�" << i << "��Ⱥ" << endl;
				wxinformation::change0wxlevel(exam.wxID, m);
				for (q = 0;q < wxinformation::getwxidnumber();q++) {
					if (wxinformation::getwxlevel(q, m) == 1) {
						wxinformation::change3wxlevel(q, m);
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
void wxUser::addotherfriend(wxUser &exam) {
	cout << "���б����΢�ź����ѿ�ͨqq���У�" << endl;
	int i, m, number;
	wxUser examwx;
	for (i = 0;i < wxinformation::getwxidnumber();i++) {
		if (wxinformation::getwxfriendlist(exam.wxID, i) == 1) {
			examwx = wxidfind(i);
			if (examwx.qqflag == 0) {
				cout << "���" << i << "��΢�ź���δ��ͨqq"<<endl;
			}
			if (examwx.qqflag == 1) {
				cout << "���" << i << "��΢�ź����ѿ�ͨqq����qq�û���Ϊ��" << examwx.qqID << endl;;//ע���޸�
			}
		}
	}
}
void wxUser::menu(wxUser &exam) {
	int n;
wxstart:
	system("cls");
	cout << "1-�鿴���Ѳ����б�" << endl;
	cout << "2-�鿴Ⱥ�����б�" << endl;
	cout << "3-�޸ĸ�����Ϣ" << endl;
	cout << "4-����wxƽ̨" << endl;
	cin >> n;
	if (n == 1) {
	friendstart:
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
	changestart:
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
		cout << "1-��¼,2-�������˺�" << endl;
		cin >> n;
		system("cls");

		if (n == 1) {
			cout << "�����¼���" << endl;
			cin >> n;
			exam = wxidfind(n);
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
				wxuserlist[wxinformation::getwxidnumber() - 1] = createwx();
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