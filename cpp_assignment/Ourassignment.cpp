#include <iostream>
#include<iomanip>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <vector>
#include <algorithm>
#include<ctime>
#include<time.h>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"
using namespace std;
string skip(38,'=');
#define find_str(a, b) std::find(a.begin(), a.end(), b) == a.end() //Bo_date = 32758 
struct Product
{
    int Id;
    char name[15];
    int Qty;
};
class Book{
    private:
    int Id;
    char name[15];
    int Qty;
    public:
    void get_Book(void);
    int get_Id(void)
    {
        return Id;
    }
    
};


void add_Book(void);
void show_Book(void);
void show_All(void);
void delete_Book(void);
void Re_Book(void);
void Bo_Book(void);
void Edit_Book(void);
void Report_Bo(void);
void Report_Re(void);


Book it;
fstream file;
int main(){
    int option;
    while(1)
    {
        system("cls");
        cout<<"| Borrow and Return Book Simulater |"<<endl;
        cout << skip << endl;
        cout<<"********MENU********"<<endl;
        cout << skip << endl;
        cout<<"1. Add New Book"<<endl;
        cout<<"2. Show Book"<<endl;
        cout<<"3. Delete Book"<<endl;
        cout<<"4. Return Book"<<endl;
        cout<<"5. Borrow Book"<<endl;
        cout<<"6. Edit Book"<<endl;
        cout<<"7. Report Borrow"<<endl;
        cout<<"8. Report Return"<<endl;
        cout<<"9. Exit"<<endl;
        cout<<"Enter Option No. : ";
        cin>>option;
        switch (option)
        {
        case 1:{
            add_Book();
            cout<<"Press any key for Main Menu...";
            getch();
            break;
        }
        case 2:{
            cout<<"_________________________________________________\n";
            
            show_All();
            cout<<"_________________________________________________\n";
            cout<<"Press any key for Main Menu...";
            getch();
            break;
        }
       
        case 3:{
            delete_Book();
            cout<<"Press any key for Main Menu...";
            getch();
            break;
        }
        case 4:{
           Re_Book();
             getch();
            break;
        }
        case 5:{
            Bo_Book();
            getch();
            break;
        }     case 6:{
            Edit_Book();
            getch();
            break;
        }  case 7:{
            Report_Bo();
            cout<<"_________________________________________________\n";
            cout<<"Press any key for Main Menu...";
            getch();
            break;
        }case 8:{
            Report_Re();
            cout<<"_________________________________________________\n";
            cout<<"Press any key for Main Menu...";
            getch();
            break;
        }   
         case 9:{
           exit(0);
        }     
        default:{cout<<"Incorrect Option"; exit(0);
            break;
        }
        }
    }
    return 0;
}
void add_Book() 
{
    int Id,Qty;
    string name;
    char ch='y';
    
    fstream outfile;
    outfile.open("stock.txt",ios::app);
    while (ch == 'y'||ch=='Y')
    {
        enter:
        cout<<"Enter Book Id : ";
    cin>>Id;
    if(Id < 0){
        cout<<"Please enter data again"<<endl;
        goto enter;
    }
     cout<<"Enter Book Name : ";
     cin>>name;
     cout<<"Enter Qty : ";
     cin>>Qty;
     if(Id < 0){
        cout<<"Quantity can not below zero Please Enter data again"<<endl;
        goto enter;
    }
        outfile << Id <<endl<< name <<endl<< Qty << endl;
       
         cout<<"do you want to add more book? (y/n) : ";
     cin>>ch;
    }

     outfile.close();
     cout<<"Press any button to continuous";
}

void show_All(void)
{
    string Id="Id"  ,Qty="Qty" ;
    string name = "Name";
    file.open("stock.txt",ios::in|ios::binary);
    if(!file)
    {
        cout<<"File not found";
        exit(0);
    }
    else{
            while(!file.eof()) {
                
                 cout <<"  : "<< right << setw(6) << Id<< " : ";
                 cout <<right<<setw(15)<< name << " : ";
                 cout <<right<<setw(6)<< Qty << " : "<<endl;
                 file >> Id >> name>>Qty;
                 }
        
           file << Id << " "<< name << " "<< Qty << endl;
    }
    file.close();
}

void delete_Book(){
    int no;
    cout<<"Enter Item Id to Delete : ";
    cin>>no;
    ofstream file2;
    file2.open("new.txt",ios::out|ios::binary);
    file.open("stock.txt",ios::in|ios::binary);
    if(! file)
    {
        cout<<"File not Found";
        exit(0);
    }
    else
    {
        file.read((char*)&it,sizeof(it));
        while(!file.eof())
        {
            if(no != it.get_Id())
            {
                file2.write((char*)&it,sizeof(it)); ///ใส่ตามจำนวนข้อมูลในfile
            }
            file.read((char*)&it,sizeof(it));
        }
    }
    file2.close();
    file.close();
    remove("stock.txt");
    rename("new.txt","stock.txt");
    cout<<"Press any button to continuous";
}
void Re_Book(void){
    
     string data_arey[2000][3],line;
    ifstream file("stock.txt");
    int r = 0,c=0,i=0,r2=0;
    int Re_no = 0,Re_num = 0,Re_all_num = 0;
    int Re_date = 0,Bo_date=0;
    char choice;
    if(file.is_open()){
    while (getline(file,line))
    {
        i++;
        data_arey[r][c] = line;

        if(i%3 == 0){
c = -1;
r++;

        }c++;
    }file.close();
    }
    
    Bogain:
    string data_arey_bo[2000][8],line2,find;
    cout<<"Enter your Borrow id : ";
    cin>>find;
    ifstream file2("Borrow.txt");
    int c2=0,i2=0;
     while (getline(file2,line2))
    {
        i2++;
        data_arey_bo[r2][c2] = line2;

        if(i2%7 == 0){
c2 = -1;
r2++;

        }c2++;
    }
    cout<<"Enter Book Id to Return : ";
    cin>>Re_no;
    cout<<"Enter number of Book to Return : ";
    cin>>Re_num;
     Re_all_num = Re_all_num + Re_num;
    if(Re_all_num > 3) {
        cout<<"Error!! Please enter Id book to return again"<<endl;
        Re_all_num = 0;
        goto Bogain;
    }else if (Re_all_num < 3){
        cout<<"do you  want to Return more book? (y/n) ";
        cin>>choice;
        switch (choice)
        {
        case 'y': 
        goto Bogain;
            break;
            case 'Y': 
        goto Bogain;
            break;
            case 'n': 
         case 'N': 
            break;
        
        default:
            break;
        }

    }

int y = 1;
string s = to_string(Re_no);
int check=0;
for(r2 = 0;r2<r;r2++){
        if (data_arey[r2][0]==s)
        {
            check=1;
            break;
        }
}
if (check==1)
{int cal = stoi (s),Borrowed = stoi( data_arey[r2][2]) ,sum_Bo = 0 ;

    ofstream myfile;
    fstream file;
    myfile.open ("stock.txt");
    sum_Bo=Borrowed+Re_num;
    string sum_s = to_string(sum_Bo);
    int Re_day1 ,Re_mon1 ,Re_year1,diff,d;
    data_arey[r2][2]=sum_s;
    for(int r3 = 0;r3<r;r3++){
        for (int i3 = 0; i3 < 3; i3++)
        {
            myfile << data_arey[r3][i3]<<"\n";
        }  
       }  file.close();

file.open("Return.txt",std::ios::in | std::ios::out | std::ios::app);
date:
cout << "Enter return date : Day Month Year\r\n";
    cin >> Re_day1 >>Re_mon1 >> Re_year1 ;
    if(Re_day1<0||Re_mon1<0||Re_year1<0){
        cout<<"Please Enter data again"<<endl;
        goto date;
    }
 Re_date = (((Re_year1*12)+Re_mon1)*30)+Re_day1;
if(file2.is_open()){
    int check=0;
for(r2 = 0;r2<r;r2++){
        if (data_arey_bo[r2][0]==find)
        {
            check=1;
            break;
        }
        cout<<data_arey_bo[r2][4]<<"   "<<data_arey_bo[r2][5]<<"   "<<data_arey_bo[r2][6]<<"   "<<endl;
        

}int day1= stoi(data_arey_bo[r2][4]),mon1= stoi(data_arey_bo[r2][5]),year1= stoi(data_arey_bo[r2][6]);

if (check==1){
Bo_date = (((year1*12)+mon1)*30)+day1;
}   else {cout<<"no borrow id found";goto end;}
}
 diff =Re_date -Bo_date;
 if(diff > 10){
    cout<<"You have to pay the fine for exceeding the specified date.";
 }else {cout<<"Press any button to continuous";goto end; }
 r2=r2+=1;
  file << r2<<"\n"<< data_arey[r2][0]<<"\n"<< data_arey[r2][1]<<"\n"<< Re_num<<"\n"<< Re_day1<<"\n"<< Re_mon1<<"\n"<< Re_year1<<"\n";
file.close();
 myfile.close();
}else{
    cout<<"no data"<<endl;
    end:
    cout<< "Press any button to continuous";
}

}void Bo_Book(void){
 string data_arey[2000][3],line;
    ifstream file("stock.txt");
    int r = 0,c=0,i=0,r2=0;
    int no = 0,num = 0,all_num = 0,day1 = 0,mon1 = 0,year1=0;
    time_t Bo_date;
    char choice;
    if(file.is_open()){
    while (getline(file,line))
    {
        i++;
        data_arey[r][c] = line;

        if(i%3 == 0){
c = -1;
r++;

        }c++;
    }file.close();
    }
    Bogain:
    cout<<"Enter Book Id to Borrow : ";
    cin>>no;
    num:
    cout<<"Enter number of Book to Borrow : ";
    cin>>num;if(num<0){
        cout<<"enter number to borrow again"<<endl;
        goto num;
    }
     all_num = all_num + num;
    if(all_num > 3) {
        cout<<"Please Enter the Book Id to Borrow again. "<<endl;
        all_num = 0;
        goto Bogain;
    }else if (all_num < 3){
        cout<<"do you to borrow again? (y/n) ";
        cin>>choice;
        switch (choice)
        {
        case 'y': 
        goto Bogain;
            break;
            case 'Y': 
        goto Bogain;
            break;
            case 'n': 
         case 'N': 
            break;
        
        default:
            break;
        }

    }

int y = 1;
string s = to_string(no);
int check=0;
for(r2 = 0;r2<r;r2++){
        if (data_arey[r2][0]==s)
        {
            check=1;
            
            break;
        }
}
if (check==1)
{int cal = stoi (s),Borrowed = stoi( data_arey[r2][2]) ,sum_Bo = 0 ;

    ofstream myfile;
    fstream file;
    myfile.open ("stock.txt");
    sum_Bo=Borrowed-num;
    string sum_s = to_string(sum_Bo);
    data_arey[r2][2]=sum_s;
    for(int r3 = 0;r3<r;r3++){
        for (int i3 = 0; i3 < 3; i3++)
        {
            myfile << data_arey[r3][i3]<<"\n";
            cout<<data_arey[r3][i3]<<endl;
        }  
       }  file.close();

file.open("Borrow.txt",std::ios::in | std::ios::out | std::ios::app);
date:
cout << "Enter Borrow Date : Day Month Year\r\n";
    cin >> day1 >> mon1 >> year1 ;
    if(day1<0||mon1<0||year1<0)
    {
        cout<<"Please Enter data again"<<endl;goto date;
    }
 Bo_date = (((year1*12)+mon1)*30)+day1;

// 
 string data_arey_bo[2000][8],line2;
    ifstream file2("Borrow.txt");
    int r2 = 0,c2=0,i2=0;
    
if(file2.is_open()){
    while (getline(file2,line2))
    {
        i2++;
        data_arey_bo[r2][c2] = line2;

        if(i2%7 == 0){
c2 = -1;
r2++;

        }c2++;
    }file2.close();
    
}
r2=r2+=1;
// 
    
  file << r2 <<"\n"<< data_arey[r2][0]<<"\n"<< data_arey[r2][1]<<"\n"<< num<<"\n"<< day1<<"\n"<< mon1<<"\n"<< year1<<"\n";
file.close();
 myfile.close();
}else{
    cout<<"no data"<<endl;
}
cout<<"Press any button to continuous";


} void Edit_Book(void){
 string data_arey[2000][3],line;
    ifstream file("stock.txt");
    int r = 0,c=0,i=0,r2=0;
    
if(file.is_open()){
    while (getline(file,line))
    {
        i++;
        data_arey[r][c] = line;

        if(i%3 == 0){
c = -1;
r++;

        }c++;
    }file.close();
    
    
    int id=0;
    cout<<"Enter ID : ";
    cin>>id;

int y = 1;
string s = to_string(id);
int check=0;
for(r2 = 0;r2<r;r2++){
        if (data_arey[r2][0]==s)
        {
            check=1;
            break;
        }
}
if (check==1)
{
    ofstream myfile;
    myfile.open ("stock.txt");
    string data1="",data2="";
    cout<<"Enter name : ";
    cin>>data1;
    cout<<"Enter Quantity : ";
    cin>>data2;
    data_arey[r2][1]=data1;
    data_arey[r2][2]=data2;
    cout<<data_arey[r2][0]<<" "<<data_arey[r2][1]<<" "<<data_arey[r2][2];
    for(int r3 = 0;r3<r;r3++){
        for (int i3 = 0; i3 < 3; i3++)
        {
            myfile << data_arey[r3][i3]<<"\n";
        }
        
}

 myfile.close();
}else{
    cout<<"no data"<<endl;
}
}cout<<"Press any button to continuous";
}
void Report_Bo(void)
{
    string Re_Id="Id Book"  , Re_name = "Book Name",Re_num = "Borrowed Book",Re_day1 = "Day",Re_mon1 = "Month",Re_year1 ="Year",Re_r2="No.";
    file.open("Borrow.txt",ios::in|ios::binary);
    
    if(!file)
    {
        cout<<"File not found";
        exit(0);
    }
    else{
            while(!file.eof()) {

                 cout <<right<<setw(3)<< Re_r2 << " : ";
                 cout <<right<<setw(8)<< Re_Id << " : ";
                  cout <<right<<setw(20)<< Re_name << " : ";
                  cout <<right<<setw(14)<< Re_num << " : ";
                   cout <<right<<setw(3)<< Re_day1 << " : ";
                    cout <<right<<setw(5)<< Re_mon1 << " : ";
                     cout <<right<<setw(6)<< Re_year1 << " : "<<endl;
                 file>>Re_r2 >> Re_Id >> Re_name>>Re_num>>Re_day1>>Re_mon1>>Re_year1;
                 }file.close();
        
           file << Re_r2 <<" "<< Re_Id <<" "<< Re_name<<" "<<Re_num<<" "<<Re_day1<<" "<<Re_mon1<<" "<<Re_year1;
    }
    file.close();
}void Report_Re(void)
{
    string Id="Id"  , name = "Name",num = "Return",day1 = "Day",mon1 = "Month",year1 ="Year",r2="No.";
    file.open("Return.txt",ios::in|ios::binary);
    if(!file)
    {
        cout<<"File not found";
        exit(0);
    }
    else{
            while(!file.eof()) {
                  cout <<right<<setw(3)<< r2 << " : ";
                 cout <<right<<setw(8)<< Id << " : ";
                  cout <<right<<setw(20)<< name << " : ";
                  cout <<right<<setw(14)<< num << " : ";
                   cout <<right<<setw(3)<< day1 << " : ";
                    cout <<right<<setw(5)<< mon1 << "   : ";
                     cout <<right<<setw(6)<< year1 << " : "<<endl;
                 file >>r2>> Id >> name>>num>>day1>>mon1>>year1;
                 }file.close();
        
           file << r2 <<" "<< Id <<" "<< name<<" "<<num<<" "<<day1<<" "<<mon1<<" "<<year1;
    }
    file.close();
}
/*void show_All(void){
    string data_arey[2000][3],line;
    ifstream file("stock.txt");
    int r = 0,c=0,i=0;
    
if(file.is_open()){
    while (getline(file,line))
    {
        i++;
        data_arey[r][c] = line;

        if(i%3 == 0){
c = -1;
r++;

        }c++;
    }file.close();
    
}else cout<<"file not found";
int y = 1;
for(int r2 = 0;r2<r;r2++){
    for(int c2 = 0;c2<3;c2++){
        cout<<data_arey[r2][c2]<<" ";
        if (y %3 == 0){
            cout<<endl;
            y =0;
        }
        y++;
    }
}
}
*/
