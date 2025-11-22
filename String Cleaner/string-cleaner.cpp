/*Error Handling is left but almost saari tick tack toe wali hi hai
And need to beautify a bit and the way of interacction to be changed a bit
like after any change would you like to  continue to the options instead of popping
the whole screen*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>//for tolower isalpha etc
using namespace std;



void welcome();
void options();
string space_remover();
void lowercase();
void punctuation_remover();
void uppercase();
void reverser();
void check_palindrome();
void clean_everything();
string str;
string choice;



void welcome(){
    cout<<"Enter your String : ";
    getline(cin,str);
    options();
}

void options(){
    cout<<"Choose an option :\n";
    cout<<"1. Remove spaces\n";
    cout<<"2. Remove punctuation:\n";
    cout<<"3. Convert to lowercase\n";
    cout<<"4. Convert to uppercase\n";
    cout<<"5. Reverse string\n";
    cout<<"6. Check palindrome\n";
    cout<<"7. Clean everything (spaces + punctuation)\n";
    cout<<"8. Edit String\n";
    cout<<"9. Exit\n\n";
    cout<< "Enter Choice : ";
    getline(cin,choice);
    switch(stoi(choice)){
        case 1:
        space_remover();
        cout<<"Your string after removing spaces : "<<str<<endl;
        options();
        case 2:
        punctuation_remover();
        cout<<"Your string after removing punctuation : "<<str<<endl;
        options();
        case 3:
        lowercase();
        cout<<"Your string after lowercase : "<<str<<endl;
        options();
        case 4:
        uppercase();
        cout<<"Your string after uppercase : "<<str<<endl;
        options();
        case 5:
        reverser();
        cout<<"Your string after reverse : "<<str<<endl;
        options();
        case 6:
        check_palindrome();
        options();
        case 7:
        clean_everything();
        cout<<"Your string after Cleaning everything (spaces + punctuation) : "<<str<<endl;
        options();
        case 8:
        welcome();
        case 9:
        exit(0);
    }
}

string space_remover(){
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    //remove shifts the spaces from begining and end
    //erase deletes the spaces fromm the new end told by remove and to the original end range
    return str;
}

void punctuation_remover(){
    str.erase(remove_if(str.begin(), str.end(), [](unsigned char c){ return ispunct(c);}), str.end());
    /*remove_if removes on condition
    [](char str){ return ispunct(str);}) is lamda expression/ unary func
    [capture](parameters)-> return_type{body}*/
}

void lowercase(){
    transform(str.begin(),str.end(), str.begin() , [](unsigned char c){return tolower(c);});
    /* transform(input range,,output start,unary op)*/
}

void uppercase(){
    transform(str.begin(),str.end(), str.begin() , [](unsigned char c){return toupper(c);});
}

void reverser(){
    reverse(str.begin(),str.end());
}

void check_palindrome(){
    int a= 0;
    int b=str.length()-1;
    while(a<b){
        if(str[a]==str[b]){
            a++;
            b--;
            continue;
        }
        else{
            cout<<"String is Not a Palindrome.\n";
            break;
        }
    }
    if (a>=b){
            cout<<"String is a Palindrome.\n";
        }
}

void clean_everything(){
    space_remover();
    punctuation_remover();
}

int main(){
    welcome();
    return 0;
}
