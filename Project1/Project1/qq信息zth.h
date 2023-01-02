using namespace std;
class qqinformationzth {
public:
	static bool getqqfriendlist(int i, int j) {
		return qqfriendlist[i][j];
	}
	static bool getqqgrouplist(int i, int j) {
		return qqgrouplist[i][j];
	}
	static void change1qqfriendlist(int i, int j) {
		qqfriendlist[i][j] = 1;
	}
	static void change0qqfriendlist(int i,int j) {
		qqfriendlist[i][j] = 0;
	}
	static void change1qqgrouplist(int i, int j) {
		qqgrouplist[i][j] = 1;
	}
	static void change0qqgrouplist(int i, int j) {
		qqgrouplist[i][j] = 0;
	}
	static int getqqgroupnumber() {
		return qqgroupnumber;
	}
	static void changeqqgroupnumber(int i) {
		qqgroupnumber += i;
	}
	static int getqqidnumber() {
		return qqidnumber;
	}
	static void changeqqidnumber(int i) {
		qqidnumber += i;
	}
	static int getqqlevel(int i, int j) {
		return qqlevel[i][j];
	}
	static void change0qqlevel(int i, int j){
		qqlevel[i][j] = 0;
		}
	static void change1qqlevel(int i, int j) {
		qqlevel[i][j] = 1;
	}
	static void change2qqlevel(int i, int j) {
		qqlevel[i][j] = 2;
	}
	static void change3qqlevel(int i, int j) {
		qqlevel[i][j] = 3;
	}
	static bool getqqjoinin(int i, int j) {
		return qqjoinin[i][j];
	}
	static void change1qqjoinin(int i, int j) {
		qqjoinin[i][j] = 1;
	}
	static void change0qqjoinin(int i, int j) {
		qqjoinin[i][j] = 0;
	}
private:
	static bool qqfriendlist[100][100] ;//qq列表
	static bool qqgrouplist[100][100];//qq群列表
	static int  qqgroupnumber;//(0-99)//比实际少1
    static int qqidnumber;//(0-99);//比实际少1
	static int qqlevel[100][100];//竖行人，横行对应群等级//1-群员，2-管理员，3-群主
    static bool qqjoinin[100][100];//申请表

};
bool qqinformationzth::qqfriendlist[100][100] = {0};//qq列表
 bool qqinformationzth::qqgrouplist[100][100] = { 0 };//qq群列表
int  qqinformationzth::qqgroupnumber=0;//(0-99)//比实际少1
 int qqinformationzth::qqidnumber=0;//(0-99);//比实际少1
 int qqinformationzth::qqlevel[100][100] = { 0 };//竖行人，横行对应群等级//1-群员，2-管理员，3-群主
 bool qqinformationzth::qqjoinin[100][100] = { 0 };//申请表