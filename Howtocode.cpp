#include<iostream>
#include<string>
#include <iomanip>
using namespace std;

string food;
int Num;
int table;
int price[]={};
int menu;

void home(){
    cout << "---------------Please select--------------"<<endl;
    cout << "COSTOMER : 1"<< setw(16) <<"EMPLOYEE : 2"<< setw(14) <<"HOST : 3 "<<endl;
    cout << ": ";
    cin >> Num;
}

void employ(){
    cout << "-----------------EMPLOYEE-----------------"<<endl;
    cout << "Order : "<< food <<endl;
    cout << "Table : " << table << endl;
    cout << "Price : " << pice[menu] << " Baht "<< endl;
}

void menuu(){
    if(menu==1){
        cout << "size : 1.normal 45 / 2.extra 55 "<<endl;
        cout << "select size : ";
        cin >> size;
        food = "Khao man Gai"; 
        if(size==1) price[menu]= 45;
        else if(size==2) price[menu] = 55;

}
void customer(){
    int more;
    int size;
    cout << "-----------------COSTOMER-----------------"<<endl;
    cout << "select Table : "<<endl;
    for(int i=1; i<=5 ;i++) cout << "1 : Table "<< i<<endl;
    cout << ": ";
    cin >> table;

    for(int i=1; i<=5 ;i++){
    if (table==i){
    cout << "1.Khao man Gai price : normal 45/extra 55 "<<endl;
    cout << "2.Khao ka Moo price : normal 45/extra 55 "<<endl;
    cout << "3.wagyu A5  price : 990 "<<endl;
    cout << "4.Salmon sasimi : price : 150 "<<endl;
    cout << "5.Tom yum kung : price : 99 "<<endl;
    cout << "select : ";
    cin >> menu;  
    }
    if(menu==2){
        cout << "size : 1.normal 45 / 2.extra 55 "<<endl;
        cout << "select size : ";
        cin >> size;
        food = "Khao ka Moo"; 
        if(size==1) price[menu] = 45;
        else if(size==2) price[menu] = 55;
       }
    }
    if(menu==3){
        food = "wagyu A5"; 
        price[menu] = 990;
    }
    if(menu==4){
        food = "Salmon sasimi"; 
        price[menu] = 150;
    }
    if(menu==5){
        food = "Tom yum kung"; 
        price[menu] = 99;
    }
}

}


int main(){
    home();
    if(Num==1) customer();
    
    if(Num==2){
        string password;
        cout << "-----------------EMPLOYEE-----------------"<<endl;
         cout << "password : ";
         cin >> password;
         if(password=="Employ898") employ();
         else cout << "password : " << "______wrong password!!!______";
    }
        
}
