#include<bits/stdc++.h>
using namespace std;
#include<fstream>
#include<stdlib.h>
#include<windows.h>
#include <unistd.h>
COORD coord= {0,0}; // this is global variable
void build(string );
void Bus_book_view(string, string, string, string);
//ofstream: Stream class to write on files
//ifstream: Stream class to read from files
void gotoxy(int x,int y)//change Cursor Location
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
class Bus
{
public:
    string Name;
    string number;
    int seat;
    void bus_info(string s,int n)
    {
        cout<<"Bus Name   : "<<Name<<endl;
        cout<<"Bus Number : "<<number<<endl;
    }
    Bus()
    {
        seat=40;
    }
} bus_cls[20];
class Passenger
{
public:
    int booking ;

    string Name;
    string Phone_Number;
    string Destination ;
    string Date;
    string Time;
    string Bus_name;
public:
    void display()
    {
        cout<<"\n";
        cout<<"  User  Name   : "<<Name<<endl;
        cout<<"  Travel From  : "<<Destination<<endl;
        cout<<"  Date         : "<<Date<<endl;
        cout<<"  Time         : "<<Time<<endl;
        cout<<"  Bus Name     : "<<Bus_name<<endl;
        cout<<endl;
    }
} seat[50];
string Find_Route()
{
    system("color 0B");
    ifstream file;
    file.open("Route.text");
    vector<string> root;
    string line;
    int cnt=2,i=1;
    int x=65;
    gotoxy(64,1);
    cout<<" _______________________________";
    gotoxy(x,cnt++);
    while(getline(file,line))
    {
        if(cnt==3)
        {
            cout<<"|       Available Route       |"<<endl,
                gotoxy(x,cnt++);
            cout<<"|-----------------------------|"<<endl;
        }
        gotoxy(x,cnt);
        cout<<"| "<<i++<<" . "<<line;
        gotoxy(x+30,cnt++);
        cout<<"|";
        root.push_back(line);
    }
    gotoxy(x,cnt);
    cout<<"|_____________________________|";
    file.close();

    gotoxy(41,4);
    int choice;
    cin>>choice;
    if(choice==-1)
    {
        return "-1";
    }

    choice--;
    if(choice>=root.size()||choice<0)
    {
        return Find_Route();
    }
    return root[choice];
}
void Add_Route()
{
    system("color 0B");
    ifstream file;
    file.open("Route.text");
    vector<string> root;
    string line;
    int cnt=2,i=1;
    system("cls");
    int x=65;
    gotoxy(64,1);
    cout<<" _______________________________";
    gotoxy(x,cnt++);
    while(getline(file,line))
    {
        if(cnt==3)
        {
            cout<<"|       Available Route       |"<<endl,
                gotoxy(x,cnt++);
            cout<<"|-----------------------------|"<<endl;
        }
        gotoxy(x,cnt);
        cout<<"| "<<i++<<" . "<<line;
        gotoxy(x+30,cnt++);
        cout<<"|";
        root.push_back(line);
    }
    gotoxy(x,cnt);
    cout<<"|_____________________________|";
    file.close();


    cnt=2;
    gotoxy(0,cnt++);
    cout<<" _____________________________"<<endl;
    cout<<"| From :                     |"<<endl;
    cout<<"|____________________________|"<<endl;
    cout<<"| To   :                     |"<<endl;
    cout<<"|____________________________|"<<endl;
    cout<<" *Press 0 for back. "<<endl;

    string from,to,dis;
    gotoxy(9,cnt);
    cin>>from;
    if(from=="0")
        return;
    gotoxy(9,cnt+=2);
    cin>>to;
    dis=from+" To "+to;
    fstream myf("Route.text", ios::in | ios::out | ios::app);
    myf<<dis<<endl;
    myf.close();
}
void Bus_Display()
{
    int i,j=3;
    gotoxy(50,0);
    cout<<"  __________";
    gotoxy(50,1);
    cout<<" |       (+)|";
    gotoxy(50,2);
    cout<<" |      ____|";
    char c='A';
    for(i=0; i<40; i++)
    {
        gotoxy(50,j++);

        cout<<c<<"| "<<seat[i].booking;
        i++;
        cout<<" "<<seat[i].booking;
        i++;
        cout<<"  "<<seat[i].booking;
        i++;
        cout<<" "<<seat[i].booking<<" |";
        c++;
    }
    gotoxy(50,j);
    cout<<" |__________|";
    gotoxy(0,1);
}
void Bus_Details(string BUS)
{
    ifstream file;
    BUS+=".text";
    file.open(BUS.c_str());
    string line;
    cout<<"Bus Schedule (Time) "<<endl;
    cout<<"--------------------"<<endl;
    int cnt=0,i=0;
    while(getline(file,line))
    {
        if(cnt%2==0)
        {
            cnt++;
            bus_cls[i].Name=line;
        }
        else
        {
            cnt++;
            bus_cls[i].number=line;
            i++;
        }
    }
    file.close();
    cout<<" Bus Name    : ";
    cin>>bus_cls[i].Name;
    cout<<" Bus Number  : ";
    cin>>bus_cls[i].number;
    ofstream myfile;
    BUS+=".text";
    myfile.open(BUS.c_str());
    int     j=i;
    for(int i=0; i<j; i++)
    {
        myfile<<bus_cls[i].Name<<endl;
        myfile<<bus_cls[i].number<<endl;
    }
    myfile.close();
}
string Select_Date(string route)
{
    system("color F0");
    getchar();
    vector<string>dt;
    ifstream file;
    string filename=route+".text";
    file.open(filename.c_str());
    string line;
    int i=0;
    int x=65,y=2;
    gotoxy(64,1);
    cout<<" _______________________";
    while(getline(file,line))
    {
        if(i==0)
        {
            gotoxy(x,y++);
            cout<<"|  Date  (dd/mm/yy)   |"<<endl;
            gotoxy(x,y++);
            cout<<"|---------------------|"<<endl;
        }
        gotoxy(x,y++);
        dt.push_back(line);
        cout<<"| "<<++i<<". "<<line[0]<<line[1]<<"/"<<line[2]<<line[3]<<"/"<<line[4]<<line[5]<<line[6]<<line[7]<<"       |"<<endl;
    }
    gotoxy(x,y);
    cout<<"|_____________________|";
    if(dt.size()==0)
    {
        system("cls");
        gotoxy(25,10);
        cout<<"NO Date Available "<<endl;
        gotoxy(25,11);
        system("pause");
        return "-1";
    }
    file.close();
    gotoxy(41,5);
    int cho;
    cin>>cho;
    if(cho==-1)
    {
        return "-1";
    }
    if(cho>dt.size())
        return Select_Date(route);
    return dt[cho-1];
}
void Add_Date(string rut)
{
    rut+=".text";
    system("color F0");
    system("cls");
    getchar();
    ifstream file(rut.c_str());
    string line;
    int i=0;
    int x=65,y=2;
    system("cls");
    vector<string>dt;
    gotoxy(64,1);
    cout<<" _______________________";
    while(getline(file,line))
    {
        if(i==0)
        {
            gotoxy(x,y++);
            cout<<"|  Date  (dd/mm/yy)   |"<<endl;
            gotoxy(x,y++);
            cout<<"|---------------------|"<<endl;
        }
        gotoxy(x,y++);
        dt.push_back(line);
        cout<<"| "<<++i<<". "<<line[0]<<line[1]<<"/"<<line[2]<<line[3]<<"/"<<line[4]<<line[5]<<line[6]<<line[7]<<"       |"<<endl;
    }
    gotoxy(x,y);
    cout<<"|_____________________|";
    file.close();
    y=8;
    gotoxy(40,y++);
    cout<<"    Enter New Date "<<endl;
    gotoxy(40,y++);
    cout<<"======================";
    gotoxy(40,y);
    cout<<"      dd/mm/yyyy "<<endl;
    string d,m,yy,s;
    gotoxy(46,y);
    cin>>d;
    gotoxy(49,y);
    cin>>m;
    gotoxy(52,y);
    cin>>yy;
    s=d+m+yy;
    dt.push_back(s);
    ofstream f(rut.c_str());
    for(int i=0; i<dt.size(); i++)
        f<<dt[i]<<endl;
    f.close();
}
string Add_Time()
{
    ifstream myfile;
    myfile.open("Time.text");
    string line;
    vector<string>root;
    int index=0;
    int x=65,y=2;
    gotoxy(64,1);
    cout<<" ___________________";
    while(getline(myfile,line))
    {
        root.push_back(line);
        if(line=="\0")
            continue;
        if(index==0)
        {
            gotoxy(x,y++);
            cout<<"|   Dept. Time    |"<<endl;
            gotoxy(x,y++);
            cout<<"|-----------------|"<<endl;
        }
        gotoxy(x,y++);
        cout<<"| "<<++index<<" . "<<line[0]<<line[1]<<" : "<<line[2]<<line[3];
        if(line[4]!='\0')
            cout<<line[4];

        cout<<"     |"<<endl;
    }
    gotoxy(x,y);
    cout<<"|_________________|";
    myfile.close();
    gotoxy(41,6);
    int i;
    cin>>i;
    if(i==-1)
        return "-1";
    if(i>root.size())
        return Add_Time();
    return root[i-1];
}
string Select_Time( string route,string date)
{
    system("color F0");
    string DET=route+date;
    string filename=DET+".text";
    ifstream file;
    file.open(filename.c_str());
    vector<string> root;
    map<string,int>ck;
    string line;
    int index=0;
    int x=65,y=2;
    gotoxy(64,1);
    cout<<" ___________________";
    while(getline(file,line))
    {
        ck[line]++;
        if(ck[line]>1)
            continue;
        root.push_back(line);
        if(line=="\0")
            continue;
        if(index==0)
        {
            gotoxy(x,y++);
            cout<<"|   Dept. Time    |"<<endl;
            gotoxy(x,y++);
            cout<<"|-----------------|"<<endl;
        }
        gotoxy(x,y++);
        cout<<"| "<<++index<<" . "<<line[0]<<line[1]<<" : "<<line[2]<<line[3];
        if(line[4]!='\0')
            cout<<line[4];

        cout<<"     |"<<endl;
    }
    gotoxy(x,y);
    cout<<"|_________________|";
    if(index==0)
    {
        system("cls");
        gotoxy(20,10);
        cout<<"NO Time Added Yet!!!"<<endl;
        gotoxy(20,11);
        system("pause");
        return "-1";
    }
    file.close();
    gotoxy(41,6);
    int i;
    cin>>i;
    if(i==-1)
    {
        return "-1";
    }
    if(i>root.size())
        return Select_Time(route,date);
    return root[i-1];
}

void fileopen(string route)
{
    ifstream myfile;
    myfile.open(route.c_str());
    int cnt=0,i=-1;
    string line;
    while(getline(myfile,line))
    {
        cnt++;
        if(cnt%4==1)
        {
            i++;
            if(line=="0")
                seat[i].booking=0;
            else
                seat[i].booking=1;
        }
        else if(cnt%4==2)
        {
            seat[i].Name=line;
        }
        else if(cnt%4==3)
        {
            seat[i].Phone_Number=line;
        }
        else if(cnt%4==0)
        {
            seat[i].Destination=line;
        }

    }
    myfile.close();
}
void New_Bus(string name)
{
    system("cls");
    Bus_book_view("","","",name);
    string route=Find_Route();
    if(route=="-1")return;
    system("cls");
    Bus_book_view(route,"","",name);
    string date=Select_Date(route);
    if(date=="-1")
    {
        system("cls");
        Add_Date(route);
        system("cls");
        Bus_book_view(route,"","",name);
        date=Select_Date(route);
    }
    system("cls");
    Bus_book_view(route,date,"",name);
    string time=Add_Time();
    while(time=="-1")
    {
        return;
    }
    string str=route+date+".text";
    ifstream ff;
    ff.open(str.c_str());
    vector<string>tm;
    string line;
    map<string,int>mp;
    mp[time]++;
    tm.push_back(time);
    while(getline(ff,line))
    {
        mp[line]++;
        if(mp[line]>1)
            continue;

        tm.push_back(line);
    }
    ff.close();
    ofstream fle;
    fle.open(str.c_str());
    for(int i=0; i<tm.size(); i++)
    {
        fle<<tm[i]<<endl;
    }
    fle.close();
    system("cls");
    Bus_book_view(route,date,time,name);
    gotoxy(0,2);

    string Name=route+date+time+".text";
    ifstream file;
    file.open(Name.c_str());
    line="";
    vector<string>v;
    vector<int>sit;
    while(getline(file,line))
    {
        string nm;
        int st=0,ck=0;
        for(int i=0; i<line.size(); i++)
        {
            if(line[i]=='|')
            {
                ck++;
                continue;
            }
            if(ck==0)
                nm+=line[i];
            else
                st=st*10+line[i]-48;
        }
        if(nm==name)
        {
            system("cls");
            gotoxy(25,12);
            cout<<"Already One bus is added !!! ";
            gotoxy(25,13);
            system("pause");
            return;
        }
        v.push_back(nm);
        sit.push_back(st);
    }
    file.close();

    v.push_back(name);
    sit.push_back(40);
    ofstream write;
    write.open(Name.c_str());
    for(int i=0; i<v.size(); i++)
    {
        write<<v[i]<<'|'<<sit[i]<<endl;
    }
    write.close();

    string busfile=route+date+time+name;
    build(busfile);
    system("cls");
    gotoxy(25,10);
    cout<<"BUS ADDED SUCCESSFULL"<<endl;
    system("pause");
}
int Select_Bus(string s)
{
    system("color 0F");
    ifstream file;
    file.open(s.c_str());
    string line;
    vector<string>v;
    vector<int>sit;
    int i=0,ind=0;
    while(getline(file,line))
    {
        string nm;
        int st=0,ck=0;
        for(int i=0; i<line.size(); i++)
        {
            if(line[i]=='|')
            {
                ck++;
                continue;
            }
            if(ck==0)
                nm+=line[i];
            else
                st=st*10+line[i]-48;
        }
        v.push_back(nm);
        sit.push_back(st);
        bus_cls[ind++].Name=nm;
    }
    int x=64,y=1;
    gotoxy(x,y++);
    cout<<" ____________________________________";
    gotoxy(x,y++);
    cout<<"|  Available Buses     Available Seat|"<<endl;
    gotoxy(x,y++);
    cout<<"|_________________  _________________|";
    for(int j=0; j<ind; j++)
    {
        gotoxy(x,y);
        cout<<"|"<<j+1<<" . "<<v[j];
        gotoxy(x+27,y);
        cout<<sit[j];
        gotoxy(x+37,y++);
        cout<<"|";

    }
    gotoxy(x,y++);
    cout<<"|____________________________________|";
    gotoxy(41,7);
    int b;
    cin>>b;
    if(b==-1)
        return -1;
    if(b>ind)
        return Select_Bus(s);
    return b-1;
}
int Select_Bus(string s,string bname)
{
    system("color 0F");
    ifstream file;
    file.open(s.c_str());
    string line;
    int i=0,ind=0;
    vector<string>v;
    vector<int>sit;
    while(getline(file,line))
    {
        string nm;
        int st=0,ck=0;
        for(int i=0; i<line.size(); i++)
        {
            if(line[i]=='|')
            {
                ck++;
                continue;
            }
            if(ck==0)
                nm+=line[i];
            else
                st=st*10+line[i]-48;
        }
        if(nm!=bname)
            continue;

        v.push_back(nm);
        sit.push_back(st);
        bus_cls[ind++].Name=nm;
    }
    if(ind==0)
        return -1;
    else
        return 0;
}
bool Password(string pass)
{
    system("cls");
    ifstream myfile;
    myfile.open(pass.c_str());
    string line;
    string password;
    getline(myfile,line);
    myfile.close();
    gotoxy(35,7);
    cout<<"               Log In\n";
    gotoxy(35,8);
    cout<<"  --------------------------------\n";
    gotoxy(37,9);
    cout<<"Password : ";
    cin>>password;
    system("cls");
    if(password==line)
    {
        return true;
    }
    return false;
}
void Change_Password()
{
    cout<<"Enter Code \n";
    string code;
    cin>>code;
    if(code!="9655")
    {
        cout<<"Wrong Code\n";
        system("Pause");
        return;
    }
    ofstream myfile;
    myfile.open("Password.text");
    cout<<"Enter New Password : ";
    string pass;
    cin>>pass;
    myfile<<pass;
    myfile.close();
    return;
}
void Check_info(string bus_name)
{
    system("cls");
    while(1)
    {
        system("cls");
        Bus_book_view("","","",bus_name);
        string route=Find_Route();
        if(route=="-1")return;
        system("cls");
        Bus_book_view(route,"","",bus_name);
        string date=Select_Date(route);
        if(date=="-1")return;
        system("cls");
        Bus_book_view(route,date,"",bus_name);
        string time=Select_Time(route,date);
        if(time=="-1")return;
        string loc=route+date+time+".text";

        int bus_no=Select_Bus(loc,bus_name);
        if(bus_no==-1)
        {
            system("cls");
            gotoxy(12,12);
            cout<<"No Bus Available!!"<<endl;
            gotoxy(12,13);
            system("pause");
            return;
        }
        system("cls");
        string m_file=route+date+time+bus_name+".text";
        fileopen(m_file);
        Bus_Display();
        string  s;
        cout<<"From "<<route<<endl;
        cout<<"Enter Seat Number : (A-J,1-4)\n";
        cin>>s;
        int d=s[0]-65,e=s[1]-49;
        int sit=d*4+e;
        if(sit>=0&&sit<40)
        {
            if(seat[sit].booking==1)
            {
                seat[sit].Date=date;
                seat[sit].Time=time;
                seat[sit].Bus_name=bus_name;
                seat[sit].display();
            }
            else
                cout<<"Not Booked Yet"<<endl;
        }
        else
        {
            cout<<"Wrong Seat Number"<<endl;
        }
        cout<<"Do You Want To Check Again ? (y/n)"<<endl;
        cin>>s;
        if(s=="y")
            Check_info(bus_name);
        return;
    }
}
void build(string dis)
{
    ofstream myfile;
    dis+=".text";
    myfile.open(dis.c_str());
    for(int i=0; i<4*40; i++)
    {
        if(i%4==0)
            myfile<<"0\n";
        else
            myfile<<"\n";
    }
    myfile.close();
}
void Bus_book_view(string root, string date,string time,string BBus)
{
    system("cls");
    if(time=="\0")
        time="        ";
    gotoxy(30,1);
    cout<<" ________________________________";
    gotoxy(30,2);
    cout<<"|             Menu               |";
    gotoxy(30,3);
    cout<<"|________________________________|";
    gotoxy(30,4);
    cout<<"| Route  : "<<root;
    gotoxy(63,4);
    cout<<"|";
    gotoxy(30,5);
    cout<<"| Date   : ";
    if(date.size()>0)
        cout<<date[0]<<date[1]<<'/'<<date[2]<<date[3]<<"/20"<<date[6]<<date[7];

    gotoxy(63,5);
    cout<<"|";
    gotoxy(30,6);
    cout<<"| Time   : "<<time[0]<<time[1];
    if(time!="        ")
        cout<<" : ";
    else
        cout<<"   ";

    cout<<time[2]<<time[3];
    gotoxy(63,6);
    cout<<"|";
    gotoxy(30,7);
    cout<<"| Bus    : "<<BBus;

    gotoxy(63,7);
    cout<<"|";
    gotoxy(30,8);
    cout<<"|________________________________|";
    gotoxy(32,9);
    cout<<"*Press -1 To cancel "<<endl;

}
void User_Info(string route,string name,string phone)
{
    gotoxy(0,0);
    cout<<"___________________________________"<<endl;
    cout<<"| Route  : "<<route;
    gotoxy(35,1);
    cout<<"|"<<endl;
    cout<<"| User Name   : "<<name;
    gotoxy(35,2);
    cout<<"|"<<endl;
    gotoxy(0,3);
    cout<<"| User Number : "<<phone;
    gotoxy(35,3);
    cout<<"|"<<endl;
    cout<<"|__________________________________|"<<endl;
    cout<<" *Enter -1 To Back . "<<endl;
}
void Seat_Booking()
{
    gotoxy(0,2);
    getchar();
    string name,direction,phonenumber;

    int chose=1;
    system("cls");
    Bus_book_view("","","","");

    string route=Find_Route();
    if(route=="-1")
        return;

    Bus_book_view(route,"","","");

    string date=Select_Date(route);
    if(date=="-1")
        return;
    Bus_book_view(route,date,"","");

    gotoxy(0,2);
    string time=Select_Time(route,date);
    if(time=="-1")
        return;
    Bus_book_view(route,date,time,"");


    string des=route+date+time+".text";
    gotoxy(0,2);

    int bus_number=Select_Bus(route+date+time+".text");
    if(bus_number==-1)
        return;
    Bus_book_view(route,date,time,bus_cls[bus_number].Name);

    string location=route+date+time+bus_cls[bus_number].Name+".text";

    system("cls");
    cout<<" From "<<route<<endl;
    fileopen(location);
    Bus_Display();
    getchar();

    User_Info(route,"","");
    gotoxy(16,2);
    getline(cin,name);
    if(name=="-1")
        return;
    User_Info(route,name,"");
    gotoxy(16,3);
    getline(cin,phonenumber);
    if(phonenumber=="-1")
        return;
    User_Info(route,name,phonenumber);

    while(1)
    {
        while(chose==1||chose==3)
        {
            system("cls");
            Bus_Display();
            User_Info(route,name,phonenumber);
            if(chose==3)
            {
                cout<<"Seat Already Booked "<<endl;
                cout<<"Do you want to continue Booking ?(y/n)"<<endl;
                string ck;
                cin>>ck;
                if(ck=="n")
                    return;
            }
            system("cls");
            Bus_Display();
            User_Info(route,name,phonenumber);
            gotoxy(0,6);
            cout<<"Seat Number : ";
            string s;
            cin>>s;
            if(s=="-1")
                return ;
            int d=s[0]-65,e=s[1]-49;
            int sit=d*4+e;
            if(seat[sit].booking==0)
            {
                cout<<"Confirm Booking \n  1. Yes   2. No \n";
                cin>>chose;
                if(chose==1)
                {
                    seat[sit].booking=1;
                    seat[sit].Name=name;
                    seat[sit].Phone_Number=phonenumber;
                    seat[sit].Destination=route;
                    break;
                }
                else
                    return;
            }
            else if(seat[sit].booking==1)
            {
                chose=3;

            }
        }
        ofstream myfile;
        myfile.open(location.c_str());
        for(int i=0; i<40; i++)
        {
            myfile<<seat[i].booking<<"\n";
            myfile<<seat[i].Name<<"\n";
            myfile<<seat[i].Phone_Number<<"\n";
            myfile<<seat[i].Destination<<"\n";
        }
        myfile.close();

        ifstream ff;
        ff.open(des.c_str());
        string line;
        vector<string>v;
        vector<int>sit;
        while(getline(ff,line))
        {
            string nm;
            int st=0,ck=0;
            for(int i=0; i<line.size(); i++)
            {
                if(line[i]=='|')
                {
                    ck++;
                    continue;
                }
                if(ck==0)
                    nm+=line[i];
                else
                    st=st*10+line[i]-48;
            }
            v.push_back(nm);
            sit.push_back(st);
        }
        ff.close();
        ofstream write;
        write.open(des.c_str());
        for(int i=0; i<v.size(); i++)
        {
            write<<v[i]<<'|';
            if(v[i]==bus_cls[bus_number].Name)
                write<<sit[i]-1<<endl;
            else
                write<<sit[i]<<endl;
        }
        write.close();
    }
}
void Bus_Company(int ck,string name)
{
    system("color 70");
    system("cls");
    string pass;
    int i=0;
    if(ck==0)
    {
        ifstream myfile;
        myfile.open("CompanyList.text");
        string line;
        map<string,string>v;
        while(getline(myfile,line))
        {
            if(i%2==0)
                name=line;
            else
            {
                pass=line;
                v[name]=pass;
            }
            i++;
        }
        myfile.close();
        while(1)
        {
            system("cls");
            gotoxy(35,4);
            cout<<" ________________________________";
            gotoxy(35,5);
            cout<<"|          Bus Operator          |";
            gotoxy(35,6);
            cout<<"|________________________________|";
            gotoxy(35,7);
            cout<<"| Name     :                     |";
            gotoxy(35,8);
            cout<<"| Password :                     |";
            gotoxy(35,9);
            cout<<"----------------------------------";
            gotoxy(48,7);
            getchar();
            getline(cin,name);
            gotoxy(48,8);
            cin>>pass;
            if(v[name]==pass)
                break;
            system("cls");
            gotoxy(37,9);
            cout<<"Wrong Password"<<endl;
            gotoxy(37,10);
            cout<<"Do You Want to Try Again ? (y/n)";
            gotoxy(37,11);
            string s;
            cin>>s;
            if(s=="n")
            {
                return;
            }
        }
    }
    system("cls");
    gotoxy(35,3);

    cout<<"-------"<<name<<"-------\n";
    gotoxy(40,5);
    cout<<"1. Seat Query\n";
    gotoxy(40,6);
    cout<<"2. Change Password\n";
    gotoxy(40,7);
    cout<<"3. Add New Bus\n";
    gotoxy(40,8);
    cout<<"4. Main Menu\n";
    gotoxy(40,10);
    cout<<"Enter : ";

    int  choice;
    cin>>choice;
    if(choice==1)
    {
        Check_info(name);
    }
    else if(choice==2)
    {
        cout<<"Not Done Yet "<<endl;
        system("pause");
        //Change_Password();
    }
    else if(choice==3)
    {
        New_Bus(name);
    }
    else if(choice==4)
        return;

    Bus_Company(ck+1,name);
}
void Add_Bus_Company()
{
    system("cls");
    gotoxy(35,4);
    cout<<" ________________________________";
    gotoxy(35,5);
    cout<<"|          Bus Company           |";
    gotoxy(35,6);
    cout<<"|________________________________|";
    gotoxy(35,7);
    cout<<"| Name     :                     |";
    gotoxy(35,8);
    cout<<"| Password :                     |";
    gotoxy(35,9);
    cout<<"----------------------------------";
    gotoxy(48,7);
    string name,pass;
    getchar();
    getline(cin,name);
    gotoxy(48,8);
    cin>>pass;
    ifstream myfile;
    myfile.open("CompanyList.text");
    string line;
    vector<string>v;
    while(getline(myfile,line))
    {
        v.push_back(line);
    }
    myfile.close();
    v.push_back(name);
    v.push_back(pass);
    ofstream file;
    file.open("CompanyList.text");
    for(int i=0; i<v.size(); i++)
    {
        file<<v[i]<<endl;
        i++;
        file<<v[i]<<endl;
    }
    file.close();

}
void Search()
{
    system("color 0F");
    int i,j,k,l,m,n,x=35,y=12;
    string number;
    system("cls");
    gotoxy(x,y++);
    cout<<"______________________________________";
    gotoxy(x,y++);
    cout<<"| Mobile Number :                    |";
    gotoxy(x,y++);
    cout<<"|____________________________________|";
    gotoxy(x+18,y-2);
    cin>>number;
    ifstream file;
    file.open("Route.text");
    string line;
    string FILE;
    while(getline(file,line))//route
    {
        string root=line;
        ifstream file1;
        FILE=line;
        string tem=FILE+".text";
        file1.open(tem.c_str());
        string line1;
        while(getline(file1,line1))//date
        {
            string date=line1;
            ifstream file2;
            FILE=line+date;
            tem=FILE+".text";
            file2.open(tem.c_str());
            string line2;
            while(getline(file2,line2))//time
            {
                string time=line2;
                ifstream file3;
                FILE=line+date+time;
                tem=FILE+".text";
                file3.open(tem.c_str());
                string line3;
                while(getline(file3,line3))
                {
                    string Name;
                    for(int i=0; i<line3.size(); i++)
                    {
                        if(line3[i]=='|')
                        {
                            break;
                        }
                        Name+=line3[i];
                    }
                    cout<<Name<<endl;
                    string loc=root+date+time+Name+".text";
                    fileopen(loc);

                    for(int i=0;i<40;i++)
                    {
                        if(seat[i].Phone_Number==number)
                        {
                            system("cls");


                            int x=35,y=10;
                            gotoxy(x,y++);
                            cout<<' ';
                            for(int j=0;j<39;j++)
                            cout<<"_";

                            gotoxy(x,y);
                            cout<<"|  User  Name   : "<<seat[i].Name<<endl;
                            gotoxy(x+40,y++);
                            cout<<"|";

                            gotoxy(x,y);
                            cout<<"|  Travel From  : "<<root<<endl;
                            gotoxy(x+40,y++);
                            cout<<"|";

                            gotoxy(x,y);
                            cout<<"|  Date         : "<<date[0]<<date[1]<<"/"<<date[2]<<date[3]<<"/"<<date[4]<<date[5]<<date[6]<<date[7]<<endl;
                             gotoxy(x+40,y++);
                            cout<<"|";

                            gotoxy(x,y);
                            cout<<"|  Time         : "<<time[0]<<time[1]<<":"<<time[2]<<time[3]<<endl;
                             gotoxy(x+40,y++);
                            cout<<"|";

                            gotoxy(x,y);
                            cout<<"|  Bus Name     : "<<Name<<endl;
                             gotoxy(x+40,y++);
                            cout<<"|";

                            gotoxy(x,y);
                            cout<<"|  Seat Number  : ";
                            char c=(i/4)+65;
                            int m=i%4;//01625811026
                            m++;
                            cout<<c<<m<<endl;
                             gotoxy(x+40,y++);
                            cout<<"|";
                            gotoxy(x,y++);

                            cout<<"|";
                            for(int j=0;j<39;j++)
                            cout<<"_";
                            cout<<"|"<<endl;

                            gotoxy(x,y+=2);
                            system("pause");
                        }
                    }
                }

            }

        }
    }


}
void Authority(int cnt)
{
    system("color 70");
    system("cls");
    if(cnt==0)
    {
        while(Password("authpass.text")==false)
        {
            gotoxy(37,9);
            cout<<"Wrong Password"<<endl;
            gotoxy(37,10);
            cout<<"Try Again ? (y/n)";
            gotoxy(37,11);
            string s;
            cin>>s;
            if(s=="n")
            {
                return;
            }
        }
    }
    system("cls");
    int x=36,y=5;
    gotoxy(35,3);
    system("color 70");
    cout<<"__________ADMIN PANEL__________"<<endl;
    gotoxy(x,y++);
    cout<<"  1. Seat Query\n";
    gotoxy(x,y++);
    cout<<"  2. Add Bus Operator\n";
    gotoxy(x,y++);
    cout<<"  3. Add Route\n";
    gotoxy(x,y++);
    cout<<"  4. Add Date\n";
    gotoxy(x,y++);
    cout<<"  5. Back\n";
    gotoxy(x,y++);
    cout <<"Enter : ";
    string ck;
    cin>>ck;
    if(ck=="1")
    {
        Search();
    }
    else if(ck=="2")
    {
        Add_Bus_Company();
    }
    else if(ck=="3")
    {
        Add_Route();
    }
    else if(ck=="4")
    {
        system("cls");
        string root=Find_Route();
        Add_Date(root);
    }
    else if(ck=="5")
    {
        return;
    }

    Authority(cnt+1);
}
int main()
{
    while(1)
    {
        system("cls");
        system("color B0");
        gotoxy(44,4);
        cout<<" ___________________________";
        gotoxy(44,5);
        cout<<"|***     TRIP TO BD      ***|"<<endl;
        gotoxy(44,6);
        cout<<"|---------------------------|";
        gotoxy(44,7);
        cout<<"|  1. USER MENU             |";
        gotoxy(44,8);
        cout<<"|  2. BUS OPERATOR          |";
        gotoxy(44,9);
        cout<<"|  3. AUTHORITY             |";
        gotoxy(44,10);
        cout<<"|  4. Exit                  |";
        gotoxy(44,11);
        cout<<"|---------------------------|";
        gotoxy(44,12);
        cout<<"| Enter :                   |";
        gotoxy(44,13);
        cout<<"|___________________________|";
        gotoxy(54,12);
        string choise;
        cin>>choise;
        if(choise=="1")
            Seat_Booking();
        else if(choise=="2")
            Bus_Company(0,"");
        else if(choise=="3")
            Authority(0);
        else if(choise=="4")
        {
            system("cls");
            cout<<"Have A good Day !"<<endl;
            return 0;
        }
    }
    return 0;
}
