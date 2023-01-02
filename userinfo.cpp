#include<iostream>
using namespace std;
class Userinfo{
public:
	void chooseplatform();
	 void createid(){
		cout<<"create id:\n";
		cin>>id;
		cout<<"id:"<<id<<"  has been created"<<endl;
	}
	 void createnickname(){
		 cout<<"create nickname:\n";
		 cin>>nickname;
		 cout<<"nickname:"<<nickname<<"  has been created"<<endl;
	 }
	 void createbirthday(){
		 cout<<"create birthday:year.month.day\n";
			cin>>birthyear>>birthmonth>>birthday;
		 cout<<"birthday:"<<birthyear<<"."<<birthmonth<<"."<<birthday<<endl;
	 }
	 void createlocation(){
		 cout<<"create location:\n";
		 cin>>location;
		 cout<<"location:"<<location<<"has been created"<<endl;
		 }
	 void Tyearincrease(){
		 Tyear++;
	 }
	 void loadfriendlist(*p){//导入

	 int getfriendlist(){
		 int i=0;
		 int* p=friendlist;
		 if(p==NULL){
			 cout<<"no friend"<<endl;
		    return 0;}
		 while((p++)!=NULL){
         cout<<"friend"<<++i<<":"<<*p<<endl;
		 }
		 return 0;
	 }
private:
	int id;
	char nickname[10];
	int birthyear;
	int birthmonth;
	int birthday;//生日
	int Tyear;//注册日期
	char location[30];
	int  friendlist[200];
	char* grouplist;

};
int main(){
	Userinfo example;
    int p[200];
	p[0]=11;
	p[1]=22;
	p[2]=33;
	p[3]=44;
    example.friendlist=p;
	example.getfriendlist();
		return 0;
}