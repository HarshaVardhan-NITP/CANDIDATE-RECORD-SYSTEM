#include<bits/stdc++.h>
#include<conio.h>
#include<sstream> 
using namespace std;
class Record{
	public:
		char name[40];
		int age;
		int id;
		float salary;
	public:
		void setdata(char str[],int a,float f){
			fstream fs;
			fs.open("EMPLOYEE.DAT",ios::in|ios::binary|ios::out|ios::app);
			strcpy(name,str);
			fs<<"NAME: "<<name<<"    ";
			fs<<"AGE: "<<a<<"    ";
			fs<<"SALARY: "<<f<<"\n";
			fs.close();	
			cout<<"RECORD SUCCESSFULLY ADDED!!"<<"\n";
		}
};
int main(){
	char name[40];
	string s,name1,age2,salary2;
	int age;
	Record rec;
	float salary;
	string line;
	fstream fs;
	int id;
	while(1){
		system("cls");
		char another='y';
		cout<<"                                                   1. ADD RECORD"<<"\n";
		cout<<"                                                   2. LISTS THE RECORD"<<"\n";
		cout<<"                                                   3. MODIFY RECORDS"<<"\n";
		cout<<"                                                   4. DELETE A RECORD"<<"\n";
		cout<<"                                                   5. EXIT"<<"\n";
		cout<<"                                                   YOUR CHOICE: ";
		int choice;
		cin>>choice;
		switch(choice){
			case 1:
				system("cls");
				while(another=='y'){
					system("cls");
					cout<<"PLEASE ENTER YOUR NAME:  ";
					cin>>name;
					cout<<"\nPLEASE ENTER YOUR AGE: ";
					cin>>age;
					cout<<"\nPLEASE ENTER YOUR SALARY: ";
					cin>>salary;
					rec.setdata(name,age,salary);
					cout<<"\nDO YOU WANT TO ADD ANOTHER RECORD TYPE(y/n): "<<"\n";
					cin>>another;
				}
				break;
			case 2:
				system("cls");
            	fs.open("EMPLOYEE.DAT",ios::in|ios::binary|ios::out|ios::app);
            	while(getline(fs,s)){
            		cout<<s<<"\n";
				}
				getch();
				fs.close();
				break;
			case 3:
				system("cls");
				while(another=='y'){
					system("cls");
					vector<string>data;
					stringstream age1,salary1;
					fs.open("EMPLOYEE.DAT",ios::in|ios::binary|ios::out);
					cout<<"PLEASE ENTER THE NAME OF RECORD YOU WANT TO MODIFY: ";
					cin>>name;
					cout<<"PLEASE ENTER MODIFIED NAME: ";
					cin>>name1;
					cout<<"PLEASE ENTER MODIFIED AGE: ";
					cin>>age;
					cout<<"PLEASE ENTER MODIFIED SALARY: ";
					cin>>salary;
					age1<<age;
					salary1<<salary;
					age1>>age2;
					salary1>>salary2;
					s="";
					s=s+"NAME: "+name1+"    "+"AGE: "+age2+"    "+"SALARY: "+salary2;
					while(getline(fs,line)){
						size_t found=line.find(name);
						if(found!=string::npos){
							data.push_back(s);
						}
						else{
							data.push_back(line);
						}
					}
					fs.close();
					fs.open("EMPLOYEE.DAT",ios::in|ios::binary|ios::out|ios::trunc);
					int loop;
					for(loop=0;loop<data.size();loop++){
						fs<<data[loop]<<"\n";
					}
					fs.close();
					cout<<"DO YOU WANT TO CHANGE ANY OTHER RECORD TYPE(y/n): ";
					cin>>another;
				}
				break;
			case 4:
				system("cls");
				while(another=='y'){
					system("cls");
					fs.open("EMPLOYEE.DAT",ios::in|ios::binary|ios::out);
					cout<<"PLEASE ENTER THE NAME WHICH RECORD YOU WANT TO REMOVE/DELETE: ";
					cin>>name;
					vector<string>data1;
					while(getline(fs,line)){
						size_t found1=line.find(name);
						if(found1!=string::npos){
							continue;
						}
						else{
							data1.push_back(line);
						}
					}	
					fs.close();
					fs.open("EMPLOYEE.DAT",ios::in|ios::binary|ios::out|ios::trunc);
					int l;
					for(l=0;l<data1.size();l++){
						fs<<data1[l]<<"\n";
					}
					fs.close();
					cout<<"DO YOU WANT TO DELETE ANY OTHER RECORD TYPE(y/n): ";
					cin>>another;
				}
				break;
			case 5:
				exit(0);
		}
	}	
	return 0;
}
