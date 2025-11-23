//Error Handling is left but almost saari tick tack toe wali hi hai
#include <iostream>
#include <string>
#include <vector>
#include <fstream> //for saving and loading file
using namespace std;

string choice;
string input;
int boi{};
vector<string> Document;

void welcome();
void write();
void read();
void append();
void save(const vector<string>&Document);
vector<string> load();

void welcome(){
    cout<<"============="<<"\n File Storage\n"<<"=============\n";
    cout<<"1. Write to File\n";
    cout<<"2. Read File\n";
    cout<<"3. Append to File\n";
    cout<<"4. Exit\n";
    cout<<"\nEnter Your Choice : ";
    getline(cin,choice);
    cout<<"\n";
    switch(stoi(choice)){
        case 1:
        write();
        cout<<"\nFile written successfully\n";
        save(Document);
        break;
        case 2:
        read();
        save(Document);
        break;
        case 3:
        append();
        save(Document);
        break;
        case 4:
        exit(0);
    }
    welcome();
}


void write(){
    Document.resize(boi+1);
    cout<<"Enter text to write : ";
    getline(cin,input);
    Document[boi]=input;
    boi++;
}

void read(){
    cout<<"Reading file...\n\n";
    cout<<"Contents of file:\n";
    for(int i{};i<Document.size();i++){
        cout<<Document[i]<<"\n";
    }
}

void append(){
    Document.resize(boi+1);
    cout<<"Enter text to append : ";
    getline(cin,input);
    Document[boi]=input;
    boi++;
}

vector<string> load(){
    vector<string> docs;
    ifstream doc("doc.txt");

    int size;
    doc.read((char*)&size,sizeof(size));
    for (int i=0; i<size;i++) {
        string c;
        int len ;
        
        doc.read((char*)&len,sizeof(len));
        c.resize(len);
        doc.read(&c[0],len);
        docs.push_back(c);
    }
    return docs;
}

void save(const vector<string>&Document){
    ofstream doc("doc.txt");
    int size=Document.size();
    doc.write((char*)&size,sizeof(size));
    for (const string &c : Document) {
        int len=c.size();
        doc.write((char*)&len,sizeof(len));
        doc.write(c.c_str(),len);
    }
    doc.close();
    }

int main (){
    Document=load();
    welcome();
    return 0;
}