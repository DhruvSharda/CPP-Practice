//Error Handling is left but almost saari tick tack toe wali hi hai
#include <iostream>
#include <string>
#include <vector>
#include <fstream> //for saving and loading file
using namespace std;

int boi{1};
string choice{};
string alas{};
string s{};

void welcome();
void All_Contacts();
void search();
void deleter();

struct Contact{
    string name;
    string number;
    string email;
};

void save_file(const vector<Contact>& contacts);

vector<Contact> contacts;

vector<Contact> load_file(){
    vector<Contact> contacts;
    ifstream  contact("contacts.bin", ios::binary);

    if (!contact) return contacts;

    int size;
    contact.read((char*)&size,sizeof(size));

    for (int i=0; i<size;i++) {
        Contact c;
        int len ;
        
        contact.read((char*)&len,sizeof(len));
        c.name.resize(len);
        contact.read(&c.name[0],len);

        contact.read((char*)&len,sizeof(len));
        c.number.resize(len);
        contact.read(&c.number[0],len);

        contact.read((char*)&len,sizeof(len));
        c.email.resize(len);
        contact.read(&c.email[0],len);

        contacts.push_back(c);
    }
    return contacts;
}


int main(){
    contacts=load_file();
    welcome();
    return 0;
}

Contact create_contact(){
    /*here like we use void func for no return or int func 
    for int return here we are using contact 
    func for returning to contact*/
    Contact temp;
    cout<<"Enter Contact Name : ";
    getline(cin,temp.name);
    cout<<"Enter Contact Number : ";
    getline(cin,temp.number);
    cout<<"Enter Email : ";
    getline(cin,temp.email);
    cout<<"\n"<<"Contact Saved Successfully!\n\n";
    return temp ;
}

Contact update_contact(){
    cout<<"Enter name of the contact to be updated : ";
    getline(cin,alas);
    for(auto it=contacts.begin(); it !=contacts.end();it++){
        if(it->name==alas){
            cout<<"Enter Contact Name : ";
            getline(cin,it->name);
            cout<<"Enter Contact Number : ";
            getline(cin,it->number);
            cout<<"Enter Email : ";
            getline(cin,it->email);
            cout<<"\n"<<"Contact Updated Successfully!\n\n";
            alas.clear();
            return *it;
        }
    }
    cout << "Contact not found!\n";
    return Contact{};
}

void welcome(){
    boi=1;
    cout<<"============="<<"\nContact Book\n"<<"=============\n";
    cout<<"1. Add Contact\n";
    cout<<"2. View All Contacts\n";
    cout<<"3. Search Contact\n";
    cout<<"4. Delete Contact\n";
    cout<<"5. Update Contact\n";
    cout<<"6. Save to file\n";
    cout<<"7. Exit\n";
    cout<<"\nEnter Your Choice : ";
    getline(cin,choice);
    cout<<"\n";
    switch(stoi(choice)){
        case 1:
           contacts.push_back(create_contact());
            cout<<"\n";
        welcome();
        case 2:
            All_Contacts();
        welcome();
        case 3:
            search();
        welcome();
        case 4:
            deleter();
        welcome();
        case 5:
            update_contact();
        welcome();
        case 6:
            save_file(contacts);
        welcome();
        case 7:
            exit(0);
        welcome();
    }
}


void All_Contacts(){
    for(const Contact &c: contacts){
        /* range based loop, here : stands for,
        for every element inside the container, run the loop,
        so contact:contacts stand for, for every struct contact in verctor contacts,
        here we used &c instead of c beacuse it refferences instead of copying
        making program runn faster,and finally const is useed so nothing can be changeed in loop*/
        cout<< "Contact "<<boi<<"\n";boi++;
        cout << "\nName: " << c.name;
        cout << "\nContact no. : " << c.number;
        cout << "\nEmail: " << c.email;
        cout << "\n-------------------------\n";
    }

}

void search(){
    cout<<"Enter name to search : ";
    getline(cin,s);
    
    if(contacts.empty()){
            cout<<"Contact Book is Empty.\n";
        }
    else{
        for(const Contact &c: contacts){
            if(c.name==s){
                cout<< "Contact found\n";
                cout << "\nName: " << c.name;
                cout << "\nContact no. : " << c.number;
                cout << "\nEmail: " << c.email;
                cout << "\n-------------------------\n";
            }
            else{
                cout<<"Contact not found\n";
            }
        }}

}

void deleter(){
    cout<<"Enter name of the contact to be deleted : ";
    getline(cin,alas);
    for(auto it=contacts.begin(); it !=contacts.end();it++){
        if(it->name==alas){
            contacts.erase(it);
            break;
        }
    }

}

void save_file(const vector<Contact>&contacts){
    ofstream contact("contacts.bin", ios::binary);
    int size=contacts.size();
    contact.write((char*)&size,sizeof(size));
    for (const Contact &c : contacts) {
        int len=c.name.size();
        contact.write((char*)&len,sizeof(len));
        contact.write(c.name.c_str(),len);

        len=c.number.size();
        contact.write((char*)&len,sizeof(len));
        contact.write(c.number.c_str(),len);

        len=c.email.size();
        contact.write((char*)&len,sizeof(len));
        contact.write(c.email.c_str(),len);
    }
    contact.close();
    }

