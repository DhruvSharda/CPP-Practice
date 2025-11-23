/*Error Handling is left but almost saari tick tack toe wali hi hai
And need to beautify a bit and the way of interacction to be changed a bit
like after any change would you like to  continue to the options instead of popping
the whole screen*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;


string choice;
vector<string> amigo{};
int boi{};

void welcome();
void insert();
void deleter();
void search();
void update();
void display();

void welcome(){
    cout<<"============="<<"\nDynamic Array Manager\n"<<"=============\n";
    cout<<"1. Insert Element\n";
    cout<<"2. Delete Element\n";
    cout<<"3. Search Element\n";
    cout<<"4. Update Element\n";
    cout<<"5. Display Array\n";
    cout<<"6. Exit\n";
    cout<<"\nEnter Your Choice : ";
    getline(cin,choice);
    switch(stoi(choice)){
        case 1:
        insert();
        cout<< "Element Inserted Successfully.\n";
        welcome();
        case 2:
        deleter();
        cout<< "Element Deleted Successfully.\n";
        welcome();
        case 3:
        search();
        welcome();
        case 4:
        update();
        welcome();
        case 5:
        display();
        welcome();
        case 6:
        exit(0);
    }
}

void insert(){
    amigo.resize(boi+1);
    string value;
    cout<<"Enter value to insert : ";
    getline(cin,value);
    amigo[boi]=value;
    boi++;
}


void deleter(){
    string value;
    cout<<"Enter index value to delete : ";
    getline(cin,value);
    if(boi<stoi(value) || stoi(value)<0){
        cout<<"No Element at such index exists.";
        return;
    }
    amigo[stoi(value)].clear();
}


void search(){
    string value;
    cout<<"Enter element to search for : ";
    getline(cin,value);
    for(int i{}; i<amigo.size();i++){
        if(amigo[i]==value){
            cout<<"Element found at index : "<<i<<endl;
            return;
        }
    }
    cout<<"Element not found.\n";
}

void update(){
    string value;
    cout<<"Enter element to update for : ";
    getline(cin,value);
    for(int i{}; i<amigo.size();i++){
        if(amigo[i]==value){
            string updated_element;
            cout<<"Update Element to : ";
            getline(cin,updated_element);
            amigo[i]=updated_element;
            cout<<"Element updated successfully.\n";
            return;
        }
    }
    cout<<"No such Element found.\n";
}

void display(){
    cout<<"Current Array : ";
    for(int i{}; i<amigo.size();i++){
        cout<<amigo[i]<<" ";
        }
        cout<<"\n";
    }



int main(){
    welcome();
    return 0;
}