/*Error Handling left*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

string no;
int idk{};
struct Account{
    string name;
    string pin;
    string ini_dep;
    string acc_no;
};

struct tsss{
    string trions;
};

vector<tsss> trions;

vector<Account> accounts;

int boi{};

string login_acc();
int create_acc(vector<Account>& accounts,vector<tsss>& trions);
void acc_menu();
void depo(vector<Account>& accounts);
void wtrw(vector<Account>& accounts);
void balance(vector<Account>& accounts);
void transactions(vector<Account>& accounts);
void save_acc(const vector<Account>& accounts,const vector<tsss>& trions);
void load_data();

void login(){
    string choice;
cout<<"=============================\n"<<"    BANK ACCOUNT SYSTEM    \n"<<"=============================\n";
cout<<"1. Create New Account\n";
cout<<"2. Login To Existing Account\n";
cout<<"3. Exit\n\n";
cout<<"Enter your choice: ";
getline(cin,choice);
switch(stoi(choice)){
    case 1:
    create_acc(accounts,trions);
    save_acc(accounts,trions);
    break;
    case 2:
    login_acc();
    break;
    case 3:
    exit(0);
}
acc_menu();
}   

int create_acc(vector<Account>& accounts,vector<tsss>&trions){
    int boi=accounts.size();
    Account temp;
    cout<<"Enter your name: ";
    getline(cin,temp.name);
    cout<<"Set a 4-digit PIN: ";
    getline(cin,temp.pin);
    cout<<"Enter initial Deposit: Rs ";
    getline(cin,temp.ini_dep);
    cout<<"\nAccount created successfully!\n";
    cout<<"Your Account Number is: "<<boi+1;
    temp.acc_no=to_string(boi+1);//to_string converts int to string
    //not using iterator and for loop as accounts is empty rn
    trions.resize(idk+1);
    trions[idk].trions=temp.ini_dep+" initial deposit (Balance: Rs "+temp.ini_dep+")";
    idk++;
    
    accounts.push_back(temp);/*no need of resize before as pushback itself creates new space,
    thus if i add resize it creates empty structs*/
    no=to_string(boi+1);
    save_acc(accounts,trions);
    return boi;
}

string login_acc(){
    cout<<"Enter Account Number: ";
    getline(cin,no);
    for(auto it=accounts.begin(); it!=accounts.end();it++){
        if(it->acc_no==no){
            string pin;
            cout<<"Enter PIN: ";
            getline(cin,pin);
            if(it->pin==pin){
                cout<<"\nLogin Successful!\n";
                cout<<"Welcome, "<<it->name<<endl;             
            }
        }
    }    
    return no;   
}


void acc_menu(){
    string choice;
    cout<<"\n----------------------------\n"<<"        ACCOUNT MENU        \n"<<"----------------------------\n";
    cout<<"1. Deposit Money\n";
    cout<<"2. Withraw Money\n";
    cout<<"3. Check Balance\n";
    cout<<"4. View Transaction History\n";
    cout<<"5. Logout\n\n";
    cout<<"Enter your choice: ";
    getline(cin,choice);
    switch(stoi(choice)){
        case 1:
        depo(accounts);
        save_acc(accounts,trions);
        cout<<"\n----------------------------\n";
        break;
        case 2:
        wtrw(accounts);
        save_acc(accounts,trions);
        cout<<"\n----------------------------\n";
        break;
        case 3:
        balance(accounts);
        cout<<"\n----------------------------\n";
        break;
        case 4:
        transactions(accounts);
        cout<<"\n----------------------------\n";
        break;
        case 5:
        cout<<"Logged out successfully.";
        cout<<"\n----------------------------\n";
        login();
        break;
    }
    acc_menu();
}

void save_acc(const vector<Account>& accounts,const vector<tsss>& trions){
    ofstream ACC("accounts.bin", ios::binary);
    int size=accounts.size();
    int size2=trions.size();
    ACC.write((char*)&size,sizeof(size));
    for(const Account&c:accounts){
        int len=c.acc_no.size();
        ACC.write((char*)&len,sizeof(len));
        ACC.write(c.acc_no.c_str(),len);//c_str() is used because some things like binary have to have data conveerted in c format

        len=c.name.size();
        ACC.write((char*)&len,sizeof(len));
        ACC.write(c.name.c_str(),len);

        len=c.pin.size();
        ACC.write((char*)&len,sizeof(len));
        ACC.write(c.pin.c_str(),len);

        len=c.ini_dep.size();
        ACC.write((char*)&len,sizeof(len));
        ACC.write(c.ini_dep.c_str(),len);

    }

    ACC.write((char*)&size2,sizeof(size2));
    for(const tsss&c:trions){
        int len=c.trions.size();
        ACC.write((char*)&len,sizeof(len));
        ACC.write(c.trions.c_str(),len);
    }

    ACC.close();
}

void load_data(){
    ifstream ACC("accounts.bin", ios::binary);

    if (!ACC) return;

    int size;
    ACC.read((char*)&size,sizeof(size));
    for(int i{};i<size;i++){
        Account c;
        int len;

        ACC.read((char*)&len,sizeof(len));
        c.acc_no.resize(len);
        ACC.read(&c.acc_no[0],len);

        ACC.read((char*)&len,sizeof(len));
        c.name.resize(len);
        ACC.read(&c.name[0],len);

        ACC.read((char*)&len,sizeof(len));
        c.pin.resize(len);
        ACC.read(&c.pin[0],len);

        ACC.read((char*)&len,sizeof(len));
        c.ini_dep.resize(len);
        ACC.read(&c.ini_dep[0],len);

        accounts.push_back(c);
    }

    int size2;
    ACC.read((char*)&size2,sizeof(size2));

    for(int i{};i<size2;i++){
        tsss c;
        int len;

        ACC.read((char*)&len,sizeof(len));
        c.trions.resize(len);
        ACC.read(&c.trions[0],len);

        trions.push_back(c);
    }

}

void depo(vector<Account>& accounts){
    for(auto it=accounts.begin();it!=accounts.end();it++){
            if(it->acc_no==no){
                string amo;
                cout<<"Enter amount to deposit: Rs ";
                getline(cin,amo);
                it->ini_dep=to_string(stoi(it->ini_dep)+stoi(amo));
                cout<<"\nDeposit successfull!\n";
                cout<<"Updated  Balance: Rs "<<it->ini_dep;
                trions.resize(idk+1);
                trions[idk].trions=amo+" deposited (Balance: Rs "+it->ini_dep+")";
                idk++;
                amo.clear();
            }
        }
    }

void wtrw(vector<Account>& accounts){
    for(auto it=accounts.begin();it!=accounts.end();it++){
            if(it->acc_no==no){
                string amo;
                cout<<"Enter amount to withraw: Rs ";
                getline(cin,amo);
                it->ini_dep=to_string(stoi(it->ini_dep)-stoi(amo));
                cout<<"\nWithraw successfull!\n";
                cout<<"Updated  Balance: Rs "<<it->ini_dep;
                trions.resize(idk+1);
                trions[idk].trions=amo+" withdrawn (Balance: Rs "+it->ini_dep+")";
                idk++;
                amo.clear();
            }
        }
    }

void balance(vector<Account>& accounts){
    for(auto it=accounts.begin();it!=accounts.end();it++){
            if(it->acc_no==no){
                cout<<"Current balance: Rs "<<it->ini_dep;
            }
        }
}

void transactions(vector<Account>& accounts){ 
        for(auto it=accounts.begin();it!=accounts.end();it++){
            if(it->acc_no==no){
                for(int i{};i<trions.size();i++){
                    cout<<trions[i].trions<<endl;
                }
            }
        }
}


int main(){
    load_data();
    login();
    return 0;
}