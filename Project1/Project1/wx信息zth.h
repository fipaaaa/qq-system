using namespace std;
class wxinformationzth {
public:
	static bool getwxfriendlist(int i, int j) {
		return wxfriendlist[i][j];
	}
	static bool getwxgrouplist(int i, int j) {
		return wxgrouplist[i][j];
	}
	static void change1wxfriendlist(int i, int j) {
		wxfriendlist[i][j] = 1;
	}
	static void change0wxfriendlist(int i, int j) {
		wxfriendlist[i][j] = 0;
	}
	static void change1wxgrouplist(int i, int j) {
		wxgrouplist[i][j] = 1;
	}
	static void change0wxgrouplist(int i, int j) {
		wxgrouplist[i][j] = 0;
	}
	static int getwxgroupnumber() {
		return wxgroupnumber;
	}
	static void changewxgroupnumber(int i) {
		wxgroupnumber += i;
	}
	static int getwxidnumber() {
		return wxidnumber;
	}
	static void changewxidnumber(int i) {
		wxidnumber += i;
	}
	static int getwxlevel(int i, int j) {
		return wxlevel[i][j];
	}
	static void change0wxlevel(int i, int j) {
		wxlevel[i][j] = 0;
	}
	static void change1wxlevel(int i, int j) {
		wxlevel[i][j] = 1;
	}
	static void change3wxlevel(int i, int j) {
		wxlevel[i][j] = 3;
	}
	static bool getwxjoinin(int i, int j) {
		return wxjoinin[i][j];
	}
	static void change1wxjoinin(int i, int j) {
		wxjoinin[i][j] = 1;
	}
	static void change0wxjoinin(int i, int j) {
		wxjoinin[i][j] = 0;
	}
private:
	static bool wxfriendlist[100][100];//wx列表
	static bool wxgrouplist[100][100];//wx群列表
	static int  wxgroupnumber;//(0-99)//比实际少1
	static int wxidnumber;//(0-99);//比实际少1
	static int wxlevel[100][100];//竖行人，横行对应群等级//1-群员，2-管理员，3-群主
	static bool wxjoinin[100][100];//申请表

};
bool wxinformationzth::wxfriendlist[100][100] = { 0 };//wx列表
bool wxinformationzth::wxgrouplist[100][100] = { 0 };//wx群列表
int  wxinformationzth::wxgroupnumber = 0;//(0-99)//比实际少1
int wxinformationzth::wxidnumber = 0;//(0-99);//比实际少1
int wxinformationzth::wxlevel[100][100] = { 0 };//竖行人，横行对应群等级//1-群员，3-群主
bool wxinformationzth::wxjoinin[100][100] = { 0 };//申请表