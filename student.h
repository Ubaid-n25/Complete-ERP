#pragma once
#include <iostream> // i/o kyliyay
#include <iomanip>  // setw kyliyay setprecision bhi
#include <windows.h> // colors background kyliyay
#include <string> // for string 
#include <conio.h>// getch kyliyay
#include <cstdlib>// clear screen kyliyay
#include <limits>// input chacks kyliyay
#include <queue> // queue template
#include <thread> // text color or for loading... add in portals
#include <chrono> // same as upper used
#include <algorithm>// for used built in algo..
using namespace std;

int choice(int max, int min) {
    int choice;
    cout << "\nEnter Here : ";
    while (true) {
        cin >> choice;
        if (cin.fail() || choice < min || choice > max) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice! Enter " << min << "-" << max << ": ";
        } 
        else break;
    }
    return choice;
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clearin() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

class subject{
	string name;
	double tot_num;
	double percentage;
	char   grade;
	public://------------------------
	double obtained;
	bool   pass;
	subject(string n){
		name=n; tot_num=100; obtained=0; percentage=0; grade=' '; pass=false;
	}//-----------------------
	void add_result(double obt){
		obtained=obt;   percentage=(obtained/tot_num)*100;
		if(percentage >= 90){
		grade='A';
        pass=true;
		}
		else if(percentage >= 80){
		grade='B';
        pass=true;
		}
		else if(percentage >= 70){
		grade='C';
        pass=true;
		}
		else if(percentage >= 60){
		grade='D';
        pass=true;
		}
		else if(percentage >= 50){
		grade='E';
        pass=true;
		}
		else{
		grade='F';
        pass=false;
		}
	}//----------------
	void display_Sub(){
		if(!pass){
		cout<<setw(20)<<left<<name; cout<<setw(20)<<left<<"(Failed)\tTotal Number is Less then 50%"<<"\n";
		}
		else{
		cout<<setw(20)<<left<<name;  cout<<setw(20)<<left<<tot_num;  cout<<setw(20)<<left<<obtained;
		cout<<setw(20)<<left<<fixed<<setprecision(1)<<percentage;  cout<<setw(20)<<left<<grade; 
		cout<<endl;
	    }
	}//----------------
	bool chck_fail(){
		return !pass;
	}
};

void headresult(){
	cout<<setw(20)<<left<<"Subject Name:";  cout<<setw(20)<<left<<"Total";  cout<<setw(20)<<left<<"Obtained";
		cout<<setw(20)<<left<<"Percentage";  cout<<setw(20)<<left<<"Grade"; 
		cout<<endl;
}

struct attendance{
	double tot_attendance;
	double tot_absentees;
	double tot_presents;
	char att;
	double percentage;
	bool Status; string status;//--------------------
	attendance(){
		tot_attendance=0; tot_absentees=0; tot_presents=0; percentage=0; att=' '; Status=true; status=" ";
	}//--------------------
	void addATT(){
		tot_attendance++;
		
       while(true) {
       cin >> att;
       if(att=='P' || att=='p' || att=='A' || att=='a') break;
       else {
        cout << "Invalid input! Enter 'P' for Present or 'A' for Absent: ";
        cin.clear();
        cin.ignore(1000, '\n');
        }
    }

        if(att=='P' || att=='p'){
            tot_presents++;
        } else {
            tot_absentees++;
        }

		percentage=(tot_presents/tot_attendance)*100;
		
		if(percentage>=50){
			status="Satisfied...";
			Status=true;
		}
		else if(percentage<50){
			status="Warning...";
			Status=false;
		}
	}//---------------------
	void showATT(){
		cout<<"Attendance ..... \n";
		cout<<setw(20)<<left<<"Total Attendance: "<<tot_attendance<<endl;  
		cout<<setw(20)<<left<<"Total Presents: "<<tot_presents<<endl; 
		cout<<setw(20)<<left<<"Total Absents: "<<tot_absentees<<endl;
		cout<<setw(20)<<left<<"Percentage: "<<fixed<<setprecision(1)<<percentage<<endl;  
		cout<<setw(20)<<left<<"Status: "<<status<<endl; 
		cout<<endl;
	}
	bool chckATT(){
		return !Status;
	}
};

struct entrystudent{
	string name;
	int age;
    long long int cnic;
	string degree;
	entrystudent():name(" "),age(0),cnic(0),degree(" "){}
};
struct node_newAdmit{
	entrystudent st;
	node_newAdmit *next;
	node_newAdmit():next(nullptr){}
};

class new_admissions{
	node_newAdmit *head;
	node_newAdmit *tail;
	node_newAdmit *tempo;
	public:
		new_admissions():head(nullptr),tail(nullptr),tempo(nullptr){}//----------------------
		void add_newAddmision(string name,int age,long long int cnic,string degree){
			node_newAdmit *ptr;
			ptr=new node_newAdmit;
			ptr->st.name=name;
			ptr->st.age=age;
			ptr->st.cnic=cnic;
			ptr->st.degree=degree;
			if(head==nullptr){
				head=tail=ptr;
				tempo=head;
			}
			else{
				tail->next=ptr;
				tail=ptr;
			}
		}//--------------------------

	    int display_newAdmission() {
    if (head == nullptr) {
        cout << "Empty List...";
        getch();
        return 0;
    }

    if (tempo == nullptr)
        tempo = head;

    if (tempo == nullptr) {
        cout << "No more students in the list.\n";
        getch();
        return 0;
    }

    int choice;

    cout << setw(20) << left << "Name :"
         << setw(20) << left << "Age :"
         << setw(30) << left << "CNIC :"
         << setw(20) << left << "Degree :" << endl;

    cout << setw(20) << left << tempo->st.name
         << setw(20) << left << tempo->st.age
         << setw(30) << left << tempo->st.cnic
         << setw(20) << left << tempo->st.degree 
         << endl;

    cout << "\n\tPress 1 to Add This Student in ICS\n";
    cout << "\tPress 2 to Add This Student in FSC\n";
    cout << "\tPress 3 to Discard This Student\n";
    cout << "Choice = ";

    while (true) {
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 3) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice! Enter 1/2/3 : ";
        } else break;
    }

    tempo = tempo->next;
    system("cls");

    return choice;
}


		node_newAdmit *return_node(){
			if(head == nullptr) return nullptr;
			node_newAdmit *temp=head;
			head=head->next;
			if(head==nullptr) tail=nullptr;
			temp->next=nullptr;
			return temp;
		}	
		
		void remove_head() {
        if(head == nullptr) return;
         node_newAdmit *temp = head;
         head = head->next;
         if(tempo==temp) tempo=head;
         if(head==nullptr) tail=nullptr;
         delete temp;
        }
};

struct student{
	string name;
	int age;
	long long int cnic;
	int rollno;
	bool enroll;
	string Class;
	bool is;
	student():name(" "),age(0),cnic(0),Class(" "),rollno(0),is(true),enroll(false){}
};

struct resulti{
	subject Maths;
	subject Physics;
	subject Computer;
	subject English;
	subject Urdu;
	resulti() : Maths("MATHS"), Physics("PHYSICS"), Computer("COMPUTER"), 
                English("ENGLISH"), Urdu("URDU") {}
        void display_result(){
        	headresult();
        	Maths.display_Sub();
        	Physics.display_Sub();
        	Computer.display_Sub();
        	English.display_Sub();
        	Urdu.display_Sub();
        	double obt=Maths.obtained+Physics.obtained+Computer.obtained+English.obtained+Urdu.obtained;
            double prc=(obt/500)*100;
        	cout<<"\nTotal     : 500"<<endl;
        	cout<<"Obtained   : "<<obt<<endl;
        	cout<<"Percentage: "<<prc<<endl;
		}        
};

struct resultf{
	subject Chemistry;
	subject Physics;
	subject Biology;
	subject English;
	subject Urdu;
	resultf() : Chemistry("CHEMISTRY"), Physics("PHYSICS"), Biology("BIOLOGY"), 
                English("ENGLISH"), Urdu("URDU") {}
        void display_result(){
        	headresult();
        	Chemistry.display_Sub();
        	Physics.display_Sub();
        	Biology.display_Sub();
        	English.display_Sub();
        	Urdu.display_Sub();
              double obt=Chemistry.obtained+Physics.obtained+Biology.obtained+English.obtained+Urdu.obtained;
              double prc=(obt/500)*100;
        	cout<<"\nTotal     : 500"<<endl;
        	cout<<"Obtained   : "<<obt<<endl;
        	cout<<"Percentage: "<<prc<<endl;
		}           
};

struct i{
	student biodata;
	resulti data;
	attendance att;
};

struct f{
	student biodata;
	resultf data;
	attendance att;
};

struct nodei{
	i data;  
	nodei *next;
	nodei():next(nullptr){}
};

struct nodef{
	f data;
	nodef *next;
	nodef():next(nullptr){}
};

int icsroll=1;
int fscroll=51;

class ICS{
	nodei *head;
	nodei *tail;
	nodei *ptr;
	queue<string> q;
	public:
		ICS(){
			head=tail=ptr=nullptr;
		}//------------------------
	void add_student_ics(node_newAdmit *temp){
		if(temp==nullptr){
			cout<<"Returning .... empty data\n";
			return;
		}
		if(icsroll == 50){
        		cout<<"ICS class limit is Full...\nChecking Empty Seat..."<<endl;
        		chck_seat(temp);
        		return;
			}
		ptr=new nodei;
		ptr->data.biodata.name = temp->st.name;
		ptr->data.biodata.age  = temp->st.age;
		ptr->data.biodata.cnic = temp->st.cnic;
		ptr->data.biodata.Class= "ICS";
		ptr->data.biodata.is   = true;
		ptr->data.biodata.rollno = icsroll; 
        ptr->data.data.Maths.add_result(0);
        ptr->data.data.Physics.add_result(0);
        ptr->data.data.Computer.add_result(0);
        ptr->data.data.English.add_result(0);
        ptr->data.data.Urdu.add_result(0);
        ptr->data.att.tot_attendance = 0;
        ptr->data.att.tot_absentees = 0;
        ptr->data.att.tot_presents = 0;
        ptr->data.att.percentage = 0;
        ptr->data.att.Status = true;
        ptr->data.att.status = " ";
		if(head == nullptr){
         head = tail = ptr;
        } else {
         tail->next = ptr;
         tail = ptr;
        }
        icsroll++;
	}//-----------------
	void chck_seat(node_newAdmit *temp){
		nodei *temp2;
		temp2=head;
		bool chck=false;
		while(temp2!=nullptr){
			if(temp2->data.biodata.is == false){
				temp2->data.biodata.name = temp->st.name;
				temp2->data.biodata.age = temp->st.age;
				temp2->data.biodata.cnic = temp->st.cnic;
				temp2->data.biodata.is = true;
                temp2->data.data.Maths.add_result(0);
                temp2->data.data.Physics.add_result(0);
                temp2->data.data.Computer.add_result(0);
                temp2->data.data.English.add_result(0);
                temp2->data.data.Urdu.add_result(0);
                temp2->data.att.tot_attendance = 0;
                temp2->data.att.tot_absentees = 0;
                temp2->data.att.tot_presents = 0;
                temp2->data.att.percentage = 0;
                temp2->data.att.Status = true;
                temp2->data.att.status = " ";
				chck=true;
				return;
			}
			temp2=temp2->next;
		}
		if(!chck){
			cout<<"\nNo Seat Available Behind..."<<endl;
			return;
		}
	}	//----------------------
	void delete_st(int roll){
		nodei *temp;
		temp=head;
		if(head==nullptr){
			cout<<"Empty class...";
			return;
		}
		if(temp->data.biodata.rollno==roll){
			temp->data.biodata.is = false;
			temp->data.biodata.name="Empty";
			temp->data.biodata.cnic=0;
			temp->data.biodata.age=0;
            temp->data.data.Maths.add_result(0);
            temp->data.data.Physics.add_result(0);
            temp->data.data.Computer.add_result(0);
            temp->data.data.English.add_result(0);
            temp->data.data.Urdu.add_result(0);
            temp->data.att.tot_attendance = 0;
            temp->data.att.tot_absentees = 0;
            temp->data.att.tot_presents = 0;
            temp->data.att.percentage = 0;
            temp->data.att.Status = true;
            temp->data.att.status = " ";
            temp->data.biodata.enroll=false;
			return;
		}
		while(temp != nullptr){
			if(temp->data.biodata.rollno==roll){
				temp->data.biodata.is = false;
				temp->data.biodata.name="Empty";
			    temp->data.biodata.cnic=0;
			    temp->data.biodata.age=0;
                temp->data.data.Maths.add_result(0);
                temp->data.data.Physics.add_result(0);
                temp->data.data.Computer.add_result(0);
                temp->data.data.English.add_result(0);
                temp->data.data.Urdu.add_result(0);
                temp->data.att.tot_attendance = 0;
                temp->data.att.tot_absentees = 0;
                temp->data.att.tot_presents = 0;
                temp->data.att.percentage = 0;
                temp->data.att.Status = true;
                temp->data.att.status = " ";
                temp->data.biodata.enroll=false;
			    return;
			}
			temp=temp->next;
		}
	}//---------------------------
	void add_result_Maths(){
		nodei *temp;
		temp=head;
		int obtained;
		if(head==nullptr){
			cout<<"No students is in this class..."<<endl;
			return;
		}
		while(temp!=nullptr){
			
			if(temp->data.biodata.is == false){
            temp = temp->next;
            continue;
            }

			cout<<"Enter Obtained Numbers For Roll Number "<<temp->data.biodata.rollno<<" in Maths : ";
			
		        while(true) {
                    cin >> obtained;
                    if(cin.fail() || obtained < 0 || obtained > 100){
                    cin.clear(); 
                    cin.ignore(1000, '\n'); 
                    cout << "Invalid input! Enter a number between 0-100: ";
                } else {
                    break;
                }
            }
            
			temp->data.data.Maths.add_result(obtained);
			temp=temp->next;
		}
	}
	void add_result_Physics(){
		nodei *temp;
		temp=head;
		int obtained;
		if(head==nullptr){
			cout<<"No students is in this class..."<<endl;
			return;
		}
		while(temp!=nullptr){
						if(temp->data.biodata.is == false){
            temp = temp->next;
            continue;
            }
			cout<<"Enter Obtained Numbers For Roll Number "<<temp->data.biodata.rollno<<" in Physics : ";
		        while(true) {
                    cin >> obtained;
                    if(cin.fail() || obtained < 0 || obtained > 100){
                    cin.clear(); 
                    cin.ignore(1000, '\n'); 
                    cout << "Invalid input! Enter a number between 0-100: ";
                } else {
                    break;
                }
            }

			temp->data.data.Physics.add_result(obtained);
			temp=temp->next;
		}
	}
	void add_result_Computer(){
		nodei *temp;
		temp=head;
		int obtained;
		if(head==nullptr){
			cout<<"No students is in this class..."<<endl;
			return;
		}
		while(temp!=nullptr){
						if(temp->data.biodata.is == false){
            temp = temp->next;
            continue;
            }
			cout<<"Enter Obtained Numbers For Roll Number "<<temp->data.biodata.rollno<<" in Computer : ";
		        while(true) {
                    cin >> obtained;
                    if(cin.fail() || obtained < 0 || obtained > 100){
                    cin.clear(); 
                    cin.ignore(1000, '\n'); 
                    cout << "Invalid input! Enter a number between 0-100: ";
                } else {
                    break;
                }
            }

			temp->data.data.Computer.add_result(obtained);
			temp=temp->next;
		}
	}
	void add_result_English(){
		nodei *temp;
		temp=head;
		int obtained;
		if(head==nullptr){
			cout<<"No students is in this class..."<<endl;
			return;
		}
		while(temp!=nullptr){
						if(temp->data.biodata.is == false){
            temp = temp->next;
            continue;
            }
			cout<<"Enter Obtained Numbers For Roll Number "<<temp->data.biodata.rollno<<" in English : ";
		        while(true) {
                    cin >> obtained;
                    if(cin.fail() || obtained < 0 || obtained > 100){
                    cin.clear(); 
                    cin.ignore(1000, '\n'); 
                    cout << "Invalid input! Enter a number between 0-100: ";
                } else {
                    break;
                }
            }

			temp->data.data.English.add_result(obtained);
			temp=temp->next;
		}
	}
	void add_result_Urdu(){
		nodei *temp;
		temp=head;
		int obtained;
		if(head==nullptr){
			cout<<"No students is in this class..."<<endl;
			return;
		}
		while(temp!=nullptr){
						if(temp->data.biodata.is == false){
            temp = temp->next;
            continue;
            }
			cout<<"Enter Obtained Numbers For Roll Number "<<temp->data.biodata.rollno<<" in Urdu : ";
					        while(true) {
                    cin >> obtained;
                    if(cin.fail() || obtained < 0 || obtained > 100){
                    cin.clear(); 
                    cin.ignore(1000, '\n'); 
                    cout << "Invalid input! Enter a number between 0-100: ";
                } else {
                    break;
                }
            }

			temp->data.data.Urdu.add_result(obtained);
			temp=temp->next;
		}
	}
	void attendance_time(){
		nodei *temp;
		temp=head;
		if(head==nullptr){
			cout<<"No Data...";
			return;
		}
		while(temp!=nullptr){
			cout<<"Enter Attendance For Roll Number "<<temp->data.biodata.rollno<<" : ";
			temp->data.att.addATT();
			temp=temp->next;
		}
	}
	
	void modify_subject_result(int roll, const string &subject_name) {
    nodei *temp = head;
    if(head == nullptr) {
        cout << "No students in ICS class.\n";
        return;
    }

    while(temp != nullptr && !(temp->data.biodata.rollno == roll && temp->data.biodata.is)) {
        temp = temp->next;
    }

    if(temp == nullptr) {
        cout << "ICS Student with Roll " << roll << " not found or inactive.\n";
        return;
    }

    int obtained;
    while(true) {
        cout << "Enter obtained marks for " << subject_name << ": ";
        cin >> obtained;
        if(cin.fail() || obtained < 0 || obtained > 100) {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Invalid input! Enter a number between 0-100.\n";
        } else break;
    }

    if(subject_name == "Maths") temp->data.data.Maths.add_result(obtained);
    else if(subject_name == "Physics") temp->data.data.Physics.add_result(obtained);
    else if(subject_name == "Computer") temp->data.data.Computer.add_result(obtained);
    else if(subject_name == "English") temp->data.data.English.add_result(obtained);
    else if(subject_name == "Urdu") temp->data.data.Urdu.add_result(obtained);
    else cout << "Subject name invalid!\n";
    cout << "Result updated successfully for " << subject_name << ".\n";
   }

	
	void complain(string role){
	    string message; 
		int choice; 
		int count=1;
	    if(role=="student"){
	    	cin.ignore();
	    	cout<<"\nEnter your Complain Message : ";
	    	getline(cin,message);
	    	q.push(message);
	    	cout<<"\n\t\tComplain Submitted Successfully"<<endl;
		}
		else if(role=="admin"){
			if(q.empty()){
				cout<<"No Complains Left...."<<endl;
				getch();
				return;
			}
			cout<<"\nComplains...."<<endl;
			while(!q.empty()){
				cout<<"Complain "<<count<<" : ";
				cout<<q.front()<<endl; 
				q.pop(); count++;
				cout<<"\n Press 1 to see more or Press an key to exit..."; cin>>choice;
				if(choice!=1)
				break;
			}
		}
	}
	
    void enroll_improvement(int rollno){
    nodei *temp = head;
    while(temp != nullptr){
        if(temp->data.biodata.rollno == rollno && temp->data.biodata.is){
            cout << "\n--- ENROLMENT IMPROVEMENT PROCESS ---\n";
            bool anyUpdate = false;
            if(temp->data.data.Maths.chck_fail()){
                temp->data.data.Maths.add_result(50);
                cout << "Maths improved -> PASSED\n";
                anyUpdate = true;
            }
            if(temp->data.data.Physics.chck_fail()){
                temp->data.data.Physics.add_result(50);
                cout << "Physics improved -> PASSED\n";
                anyUpdate = true;
            }
            if(temp->data.data.Computer.chck_fail()){
                temp->data.data.Computer.add_result(50);
                cout << "Computer improved -> PASSED\n";
                anyUpdate = true;
            }
            if(temp->data.data.English.chck_fail()){
                temp->data.data.English.add_result(50);
                cout << "English improved -> PASSED\n";
                anyUpdate = true;
            }
            if(temp->data.data.Urdu.chck_fail()){
                temp->data.data.Urdu.add_result(50);
                cout << "Urdu improved -> PASSED\n";
                anyUpdate = true;
            }
            if(temp->data.att.chckATT()){
             temp->data.att.Status = true;
             temp->data.att.status = "Satisfied...";
             temp->data.att.percentage = 50;
             temp->data.att.tot_attendance = 2;
             temp->data.att.tot_presents   = 1;  
             temp->data.att.tot_absentees  = 1;
             cout << "Attendance improved -> Marked 50% (PASS)\n";
             anyUpdate = true;
            }
            if(!anyUpdate){
                cout << "No improvement needed. Student already pass & attendance ok.\n";
            } else {
                cout << "\nStudent successfully enrolled & improved.\n";
                temp->data.biodata.enroll=true;
            }

            return;
        }
        temp = temp->next;
    }

    cout << "Student not found!\n";
}


    void display_ics_class(){
    	cout<<"Press 1 to See Whole Class Data for ICS.\nPress 2 to See Enrollment Students of ICS.\nPress 0 to Back."<<endl;
    	int c;
    	c=choice(2,0);
    	if(c==0) 
		return;
    	else if(c==1){
    		nodei *temp = head;
    		if(head==nullptr){
    			cout<<"No Data Available...\n";
    	        return;
			}
			while(temp!=nullptr){
			cout<<"-----------------------------------"<<endl;
			cout<<"Name   : "<<temp->data.biodata.name<<endl;
			cout<<"Roll No: "<<temp->data.biodata.rollno<<endl;
			cout<<"Class  : "<<temp->data.biodata.Class<<endl;
			cout<<"-----------------------------------"<<endl<<endl;
			getch();
			temp=temp->next;	
			}
		}
		else{
			cout<<"Students Who Enrolled Is....\n";
			nodei *temp=head;
			if(head==nullptr){
    			cout<<"No Data Available...\n";
    			getch();
    	        return;
			}
			while(temp!=nullptr){
				if(temp->data.biodata.enroll==true){
			cout<<"-----------------------------------"<<endl;
			cout<<"Name   : "<<temp->data.biodata.name<<endl;
			cout<<"Roll No: "<<temp->data.biodata.rollno<<endl;
			cout<<"Class  : "<<temp->data.biodata.Class<<endl;
			cout<<"...Student Is Enrolled ..."<<endl;
			cout<<"-----------------------------------"<<endl<<endl;
			getch();
		}
			temp=temp->next;	
			}
		}
	}
	
	void display_All(int roll){
	    nodei *temp;
	    temp=head;
	    if(head==nullptr){
	    	return;
		}
	    int choice;
	    while(temp!=nullptr){
	    	if(temp->data.biodata.rollno==roll && temp->data.biodata.is){
	    		system("color F0");
	    		cout<<"\n\nWelcome "<<temp->data.biodata.name<<" ...\n";
	    		cout<<"Roll NO :"<<temp->data.biodata.rollno<<endl;
	    		cout<<"Class   :"<<temp->data.biodata.Class<<endl;
	    		cout<<"CNIC    :"<<temp->data.biodata.cnic<<endl;
	    		cout<<"\n\n\tPress any key to Continue..."; 
	    		getch();
	    while(true){
	    	system("cls");
	    	cout<<"\nStudent Portal.....\n\n";
	    	cout<<"Press 0 to Terminate."<<endl;
	    	cout<<"Press 1 to See Attendance."<<endl;
	    	cout<<"Press 2 to See Result."<<endl;
	    	cout<<"Press 3 to Register Complain."<<endl;
	    	cout<<"Press 4 to Enrollment to Improvement."<<endl;
	    	cout<<"\nEnter your Choice Here :"; 
	    	
	    	while(true){
    cin >> choice;
    if(cin.fail() || choice < 0 || choice > 4){
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid choice! Enter 0-4: ";
    } else break;
}
	    	
	    	if(choice==0){
	    		break;
			}
			else if(choice==1){
				temp->data.att.showATT();
				getch();
			}
			else if(choice==2){
				temp->data.data.display_result();
				getch();
			}
			else if(choice==3){
				complain("student");
				getch();
			}
			else if(choice==4){
				enroll_improvement(temp->data.biodata.rollno);
				getch();
			}
			else{
				cout<<"\n\t\t\t\tINVALID CHOICE ENTER AGAIN\n....."<<endl;
			}
		}
	}
	temp=temp->next;
	}
	}
	~ICS() {
    nodei* temp;
    while(head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    ptr  = nullptr;
    while(!q.empty()) q.pop();
}
};
class FSC{
    nodef *head;
    nodef *tail;
    nodef *ptr;
    queue<string> q;
public:
    FSC(){
        head=tail=ptr=nullptr;
    }

    void add_student_fsc(node_newAdmit *temp){
        if(temp==nullptr){
            cout<<"Returning .... empty data\n";
            return;
        }
        if(fscroll == 100){
            cout<<"FSC class limit is Full...\nChecking Empty Seat..."<<endl;
            chck_seat(temp);
            return;
        }
        ptr=new nodef;
        ptr->data.biodata.name = temp->st.name;
        ptr->data.biodata.age  = temp->st.age;
        ptr->data.biodata.cnic = temp->st.cnic;
        ptr->data.biodata.Class= "FSC";
        ptr->data.biodata.is   = true;
        ptr->data.biodata.rollno = fscroll; 
        ptr->data.data.Chemistry.add_result(0);
        ptr->data.data.Physics.add_result(0);
        ptr->data.data.Biology.add_result(0);
        ptr->data.data.English.add_result(0);
        ptr->data.data.Urdu.add_result(0);
        ptr->data.att.tot_attendance = 0;
        ptr->data.att.tot_absentees = 0;
        ptr->data.att.tot_presents = 0;
        ptr->data.att.percentage = 0;
        ptr->data.att.Status = true;
        ptr->data.att.status = " ";
        if(head == nullptr){
            head = tail = ptr;
        } else {
            tail->next = ptr;
            tail = ptr;
        }
        fscroll++;
    }

    void chck_seat(node_newAdmit *temp){
        nodef *temp2 = head;
        bool chck=false;
        while(temp2!=nullptr){
            if(temp2->data.biodata.is == false){
                temp2->data.biodata.name = temp->st.name;
                temp2->data.biodata.age = temp->st.age;
                temp2->data.biodata.cnic = temp->st.cnic;
                temp2->data.biodata.is = true;
                temp2->data.data.Chemistry.add_result(0);
                temp2->data.data.Physics.add_result(0);
                temp2->data.data.Biology.add_result(0);
                temp2->data.data.English.add_result(0);
                temp2->data.data.Urdu.add_result(0);
                temp2->data.att.tot_attendance = 0;
                temp2->data.att.tot_absentees = 0;
                temp2->data.att.tot_presents = 0;
                temp2->data.att.percentage = 0;
                temp2->data.att.Status = true;
                temp2->data.att.status = " ";
                chck=true;
                return;
            }
            temp2=temp2->next;
        }
        if(!chck){
            cout<<"\nNo Seat Available Behind..."<<endl;
            return;
        }
    }

    void delete_st(int roll){
        nodef *temp = head;
        if(head==nullptr){
            cout<<"Empty class...";
            return;
        }
        if(temp->data.biodata.rollno==roll){
            temp->data.biodata.is = false;
            temp->data.biodata.name="Empty";
			temp->data.biodata.cnic=0;
			temp->data.biodata.age=0;
            temp->data.data.Chemistry.add_result(0);
            temp->data.data.Physics.add_result(0);
            temp->data.data.Biology.add_result(0);
            temp->data.data.English.add_result(0);
            temp->data.data.Urdu.add_result(0);
            temp->data.att.tot_attendance = 0;
            temp->data.att.tot_absentees = 0;
            temp->data.att.tot_presents = 0;
            temp->data.att.percentage = 0;
            temp->data.att.Status = true;
            temp->data.att.status = " ";
            temp->data.biodata.enroll=false;
            return;
        }
        while(temp != nullptr){
            if(temp->data.biodata.rollno==roll){
                temp->data.biodata.is = false;
                temp->data.biodata.name="Empty";
		    	temp->data.biodata.cnic=0;
		    	temp->data.biodata.age=0;
                temp->data.data.Chemistry.add_result(0);
                temp->data.data.Physics.add_result(0);
                temp->data.data.Biology.add_result(0);
                temp->data.data.English.add_result(0);
                temp->data.data.Urdu.add_result(0);
                temp->data.att.tot_attendance = 0;
                temp->data.att.tot_absentees = 0;
                temp->data.att.tot_presents = 0;
                temp->data.att.percentage = 0;
                temp->data.att.Status = true;
                temp->data.att.status = " ";
                temp->data.biodata.enroll=false;
                return;
            }
            temp=temp->next;
        }
    }

    void add_result_Chemistry(){
        nodef *temp = head;
        int obtained;
        if(head==nullptr){
            cout<<"No students in this class..."<<endl;
            return;
        }
        while(temp!=nullptr){
        				if(temp->data.biodata.is == false){
            temp = temp->next;
            continue;
            }
            cout<<"Enter Obtained Numbers For Roll Number "<<temp->data.biodata.rollno<<" in Chemistry : ";
                while(true) {
                    cin >> obtained;
                    if(cin.fail() || obtained < 0 || obtained > 100){
                    cin.clear(); 
                    cin.ignore(1000, '\n'); 
                    cout << "Invalid input! Enter a number between 0-100: ";
                } else {
                    break;
                }
            }

            temp->data.data.Chemistry.add_result(obtained);
            temp=temp->next;
        }
    }

    void add_result_Physics(){
        nodef *temp = head;
        int obtained;
        if(head==nullptr){
            cout<<"No students in this class..."<<endl;
            return;
        }
        while(temp!=nullptr){
        				if(temp->data.biodata.is == false){
            temp = temp->next;
            continue;
            }
            cout<<"Enter Obtained Numbers For Roll Number "<<temp->data.biodata.rollno<<" in Physics : ";
            		        while(true) {
                    cin >> obtained;
                    if(cin.fail() || obtained < 0 || obtained > 100){
                    cin.clear(); 
                    cin.ignore(1000, '\n'); 
                    cout << "Invalid input! Enter a number between 0-100: ";
                } else {
                    break;
                }
            }

            temp->data.data.Physics.add_result(obtained);
            temp=temp->next;
        }
    }

    void add_result_Biology(){
        nodef *temp = head;
        int obtained;
        if(head==nullptr){
            cout<<"No students in this class..."<<endl;
            return;
        }
        while(temp!=nullptr){
        				if(temp->data.biodata.is == false){
            temp = temp->next;
            continue;
            }
            cout<<"Enter Obtained Numbers For Roll Number "<<temp->data.biodata.rollno<<" in Biology : ";
            		        while(true) {
                    cin >> obtained;
                    if(cin.fail() || obtained < 0 || obtained > 100){
                    cin.clear(); 
                    cin.ignore(1000, '\n'); 
                    cout << "Invalid input! Enter a number between 0-100: ";
                } else {
                    break;
                }
            }

            temp->data.data.Biology.add_result(obtained);
            temp=temp->next;
        }
    }

    void add_result_English(){
        nodef *temp = head;
        int obtained;
        if(head==nullptr){
            cout<<"No students in this class..."<<endl;
            return;
        }
        while(temp!=nullptr){
        				if(temp->data.biodata.is == false){
            temp = temp->next;
            continue;
            }
            cout<<"Enter Obtained Numbers For Roll Number "<<temp->data.biodata.rollno<<" in English : ";
            		        while(true) {
                    cin >> obtained;
                    if(cin.fail() || obtained < 0 || obtained > 100){
                    cin.clear(); 
                    cin.ignore(1000, '\n'); 
                    cout << "Invalid input! Enter a number between 0-100: ";
                } else {
                    break;
                }
            }

            temp->data.data.English.add_result(obtained);
            temp=temp->next;
        }
    }

    void add_result_Urdu(){
        nodef *temp = head;
        int obtained;
        if(head==nullptr){
            cout<<"No students in this class..."<<endl;
            return;
        }
        while(temp!=nullptr){
        				if(temp->data.biodata.is == false){
            temp = temp->next;
            continue;
            }
            cout<<"Enter Obtained Numbers For Roll Number "<<temp->data.biodata.rollno<<" in Urdu : ";
          		        while(true) {
                    cin >> obtained;
                    if(cin.fail() || obtained < 0 || obtained > 100){
                    cin.clear(); 
                    cin.ignore(1000, '\n'); 
                    cout << "Invalid input! Enter a number between 0-100: ";
                } else {
                    break;
                }
            }

            temp->data.data.Urdu.add_result(obtained);
            temp=temp->next;
        }
    }

    void attendance_time(){
        nodef *temp = head;
        if(head==nullptr){
            cout<<"No Data...";
            return;
        }
        while(temp!=nullptr){
            cout<<"Enter Attendance For Roll Number "<<temp->data.biodata.rollno<<" : ";
            temp->data.att.addATT();
            temp=temp->next;
        }
    }
    
    void modify_subject_result(int roll, const string &subject_name) {
    nodef *temp = head;
    if(head == nullptr) {
        cout << "No students in FSC class.\n";
        return;
    }

    while(temp != nullptr && !(temp->data.biodata.rollno == roll && temp->data.biodata.is)) {
        temp = temp->next;
    }

    if(temp == nullptr) {
        cout << "FSC Student with Roll " << roll << " not found or inactive.\n";
        return;
    }

    int obtained;
    while(true) {
        cout << "Enter obtained marks for " << subject_name << ": ";
        cin >> obtained;
        if(cin.fail() || obtained < 0 || obtained > 100) {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Invalid input! Enter a number between 0-100.\n";
        } else break;
    }

    if(subject_name == "Chemistry") temp->data.data.Chemistry.add_result(obtained);
    else if(subject_name == "Physics") temp->data.data.Physics.add_result(obtained);
    else if(subject_name == "Biology") temp->data.data.Biology.add_result(obtained);
    else if(subject_name == "English") temp->data.data.English.add_result(obtained);
    else if(subject_name == "Urdu") temp->data.data.Urdu.add_result(obtained);
    else cout << "Subject name invalid!\n";
    cout << "Result updated successfully for " << subject_name << ".\n";
   }


    void complain(string role){
        string message; 
        int choice; 
        int count=1;
        if(role=="student"){
            cin.ignore();
            cout<<"\nEnter your Complain Message : ";
            getline(cin,message);
            q.push(message);
            cout<<"\n\t\tComplain Submitted Successfully"<<endl;
        }
        else if(role=="admin"){
            if(q.empty()){
                cout<<"No Complains Left...."<<endl;
                getch();
                return;
            }
            cout<<"\nComplains...."<<endl;
            while(!q.empty()){
                cout<<"Complain "<<count<<" : ";
                cout<<q.front()<<endl;
                q.pop();
				 count++;
                cout<<"\n Press 1 to see more or Press an key to exit..."; cin>>choice;
                if(choice!=1)
                break;
            }
        }
    }

    void enroll_improvement(int rollno){
        nodef *temp = head;
        while(temp != nullptr){
            if(temp->data.biodata.rollno == rollno && temp->data.biodata.is){
                cout << "\n--- ENROLMENT IMPROVEMENT PROCESS ---\n";
                bool anyUpdate = false;
                if(temp->data.data.Chemistry.chck_fail()){
                    temp->data.data.Chemistry.add_result(50);
                    cout << "Chemistry improved -> PASSED\n";
                    anyUpdate = true;
                }
                if(temp->data.data.Physics.chck_fail()){
                    temp->data.data.Physics.add_result(50);
                    cout << "Physics improved -> PASSED\n";
                    anyUpdate = true;
                }
                if(temp->data.data.Biology.chck_fail()){
                    temp->data.data.Biology.add_result(50);
                    cout << "Biology improved -> PASSED\n";
                    anyUpdate = true;
                }
                if(temp->data.data.English.chck_fail()){
                    temp->data.data.English.add_result(50);
                    cout << "English improved -> PASSED\n";
                    anyUpdate = true;
                }
                if(temp->data.data.Urdu.chck_fail()){
                    temp->data.data.Urdu.add_result(50);
                    cout << "Urdu improved -> PASSED\n";
                    anyUpdate = true;
                }
                if(temp->data.att.chckATT()){
                    temp->data.att.Status = true;
                    temp->data.att.status = "Satisfied...";
                    temp->data.att.percentage = 50;
                    temp->data.att.tot_attendance = 2;
                    temp->data.att.tot_presents   = 1;  
                    temp->data.att.tot_absentees  = 1;
                    cout << "Attendance improved -> Marked 50% (PASS)\n";
                    anyUpdate = true;
                }
                if(!anyUpdate){
                    cout << "No improvement needed. Student already pass & attendance ok.\n";
                } else {
                    cout << "\nStudent successfully enrolled & improved.\n";
                    temp->data.biodata.enroll=true;
                }
                return;
            }
            temp = temp->next;
        }

        cout << "Student not found!\n";
    }
    
    void display_fsc_class(){
    	cout<<"Press 1 to See Whole Class Data for FSC.\nPress 2 to See Enrollment Students of FSC.\nPress 0 to Back."<<endl;
    	int c;
    	c=choice(2,0);
    	if(c==0) 
		return;
    	else if(c==1){
    		nodef *temp = head;
    		if(head==nullptr){
    			cout<<"No Data Available...\n";
    	        return;
			}
			while(temp!=nullptr){
			cout<<"-----------------------------------"<<endl;
			cout<<"Name   : "<<temp->data.biodata.name<<endl;
			cout<<"Roll No: "<<temp->data.biodata.rollno<<endl;
			cout<<"Class  : "<<temp->data.biodata.Class<<endl;
			cout<<"-----------------------------------"<<endl<<endl;
			getch();
			temp=temp->next;	
			}
		}
		else{
			cout<<"Students Who Enrolled Is....\n";
			nodef *temp=head;
			if(head==nullptr){
    			cout<<"No Data Available...\n";
    			getch();
    	        return;
			}
			while(temp!=nullptr){
				if(temp->data.biodata.enroll==true){
			cout<<"-----------------------------------"<<endl;
			cout<<"Name   : "<<temp->data.biodata.name<<endl;
			cout<<"Roll No: "<<temp->data.biodata.rollno<<endl;
			cout<<"Class  : "<<temp->data.biodata.Class<<endl;
			cout<<"...Student Is Enrolled ..."<<endl;
			cout<<"-----------------------------------"<<endl<<endl;
			getch();
		}
			temp=temp->next;	
			}
		}
	}

    void display_All(int roll){
        nodef *temp = head;
        if(head==nullptr){
            return;
        }
        int choice;
        while(temp!=nullptr){
            if(temp->data.biodata.rollno==roll && temp->data.biodata.is){
                system("color F0");
                cout<<"\n\nWelcome "<<temp->data.biodata.name<<" ...\n";
                cout<<"Roll NO :"<<temp->data.biodata.rollno<<endl;
                cout<<"Class   :"<<temp->data.biodata.Class<<endl;
                cout<<"CNIC    :"<<temp->data.biodata.cnic<<endl;
                cout<<"\n\n\tPress any key to Continue..."; 
                getch();
                while(true){
                    system("cls");
                    cout<<"\nStudent Portal.....\n\n";
                    cout<<"Press 0 to Terminate."<<endl;
                    cout<<"Press 1 to See Attendance."<<endl;
                    cout<<"Press 2 to See Result."<<endl;
                    cout<<"Press 3 to Register Complain."<<endl;
                    cout<<"Press 4 to Enrollment to Improvement."<<endl;
                    cout<<"\nEnter your Choice Here :"; 
                    
                    while(true){
    cin >> choice;
    if(cin.fail() || choice < 0 || choice > 4){
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid choice! Enter 0-4: ";
    } else break;
}
                    
                    if(choice==0){
                        break;
                    }
                    else if(choice==1){
                        temp->data.att.showATT();
                        getch();
                    }
                    else if(choice==2){
                        temp->data.data.display_result();
                        getch();
                    }
                    else if(choice==3){
                        complain("student");
                        getch();
                    }
                    else if(choice==4){
                        enroll_improvement(temp->data.biodata.rollno);
                        getch();
                    }
                    else{
                        cout<<"\n\t\t\t\tINVALID CHOICE ENTER AGAIN\n....."<<endl;
                    }
                }
            }
            temp=temp->next;
        }
    }
    ~FSC() {
    nodef* temp;
    while(head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    ptr  = nullptr;
    while(!q.empty()) q.pop();
}

};
