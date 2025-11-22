#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int i{};        
int j{};
int z{};
int boi{};
string k{};
string l=" --";
int counterer{};
/*new thing i cannot change array size l8r so the best and safest option 
is using vector.so cool ):)
Or i hazve to work on my pointers and references. option 1 <--|*/
vector<vector<string>> matrix{};
void grid();
void string_handler();
void inputit();
void win();
void checkit();
void options();
void noinputit();


int main(){
    l.clear();
    cout<<"Enter Grid Size: ";
    string input4;
    getline(cin,k);
    k.erase(remove(k.begin(), k.end(), ' '), k.end());
    try{z=stoi(k);
           if(z>0){
            //the way to resize that vector vector int makes a new one
            matrix.clear();
            matrix.resize(z,vector<string>(z));
            //cin was creating \n buffer
            for(int i{0};i<z;i++){
                l=l+" --";
            }
            grid();
           }
            else {
                throw std::invalid_argument("Invalid input.");}
        }
        catch(...){
            cout<<"Invalid input. Try Again: \n";
            cout<<"Enter\n1--> Input\n2--> New Game\n3--> End Game\n";
            getline(cin,input4);
            input4.erase(remove(input4.begin(), input4.end(), ' '), input4.end());
            try{
                if(stoi(input4)==1){
                    input4.clear();
                    main();}
                else if(stoi(input4)==3){
                    exit(0);}
                else if(stoi(input4)==2){
                for(int i{0};i<z;i++){      
                    for(int j=0;j<z;j++){
                        matrix[i][j].clear();}}
                        cout<<"\n New Game \n";
                        main();}
                else{
                    throw std::invalid_argument("Invalid input.");
            }}
            catch(...){
                cout<<"Invalid input. Try Again\n";
                input4.clear();
                main();
            }

            }
    
    return 0;
}


void noinputit(){
    for(int i{0};i<z;i++){
            cout<<l<<"\n";        
            for(int j=0;j<z;j++){
                cout<<"|"<<(matrix[i][j].empty()?" ":matrix[i][j]) <<" ";   
                }

            cout<<"|\n";
                }
                cout<<l;

}
void grid(){
        for(int i{0};i<z;i++){
            cout<<l<<"\n";        
            for(int j=0;j<z;j++){
                cout<<"|"<<(matrix[i][j].empty()?" ":matrix[i][j]) <<" ";   
                }

            cout<<"|\n";
                }
                cout<<l;
                inputit();
            }

void string_handler(){
        string input{};
        string input2{};
        getline(cin,input);
        input.erase(remove(input.begin(), input.end(), ' '), input.end());
        int pos1=input.find(',');
        string x=input.substr(0,pos1);
        try{
            if(pos1>0){
                //return exits complete code throw 1 exits try!!!
                boi=1;
            }else{
                throw std::invalid_argument("Invalid input.");
            }}
        catch(...){
            if (boi!=1){
                cout<<"Invalid input. Try Again: ";
                input.clear();
                options();
            }
            else{
                throw 1;
            }
        }

        if(x!="X"&& x!="O"){
            counterer--;
            cout<<"Input Error. Try Again.\n";
            cout<<"Enter\n1--> Input\n2--> New Game\n3--> End Game\n";
            getline(cin,input2);
            try{
                if(stoi(input2)==1){
                    grid();}
                else if(stoi(input2)==2){
                    for(int i{0};i<z;i++){      
                        for(int j=0;j<z;j++){
                            matrix[i][j].clear();}}
                            cout<<"\n New Game \n";
                            main();}
                else if(stoi(input2)==3){
                    exit(0);}
                else {
                    throw std::invalid_argument("Invalid input.");}
        }
        catch(...){
            cout<<"Invalid input. Try Again.\n";
            input.clear();
            options();
        }
        }

        input=input.substr(pos1+1,input.length());
        int pos2=input.find(',');
        

        try{
            if(pos2>0){
                //return exits complete code throw 1 exits try!!!
                boi=1;
            }else{
                throw std::invalid_argument("Invalid input.");
            }}
        catch(...){
            if (boi!=1){
                cout<<"Invalid input. Try Again: ";
                input.clear();
                options();
            }
            else{
                throw 1;
            }
        }

        string y=input.substr(0,pos2);
        input=input.substr(pos2+1,input.length());
        int m=stoi(y);
        int n=stoi(input);
        if(m>z || m<=0 || n>z || n<=0){
            counterer--;
            cout<<"Enter according to grid size(3X3).\n";
            cout<<"Enter\n1--> Input\n2--> New Game\n3--> End Game\n";
            getline(cin,input2);
            input2.erase(remove(input2.begin(), input2.end(), ' '), input2.end());
            if(stoi(input2)==1){
                grid();
            }else if(stoi(input2)==2){
                for(int i{0};i<z;i++){      
                    for(int j=0;j<z;j++){
                        matrix[i][j].clear();}}
            }else if(stoi(input2)==3){
                exit(0);
            }
            return;
            }

            
        if(matrix[m-1][n-1].empty()){
            matrix[m-1][n-1]=x;                           

            win();
            
        }else{
            counterer--;
            cout<<"Position occcupied already.\n";
            options();
            
            if(stoi(input2)==1){
                grid();
            }else if(stoi(input2)==2){
                for(int i{0};i<z;i++){      
                    for(int j=0;j<z;j++){
                        matrix[i][j].clear();}}
            }
        }
        grid();
}

void inputit(){
    counterer++;
    if(counterer==3*z+1){
        string input2;
        cout<<"\nPress\n1--> New Game\n2--> End Game\n";
        getline(cin,input2);
        input2.erase(remove(input2.begin(), input2.end(), ' '), input2.end());
        try{
            if(stoi(input2)==1){
                for(int i{0};i<z;i++){      
                    for(int j=0;j<z;j++){
                        matrix[i][j].clear();}}
                        cout<<"\n New Game \n";
                        main();}
            else if(stoi(input2)==2){
                exit(0);}
            else {
                throw std::invalid_argument("Invalid input.");}
        }
        catch(...){
            cout<<"Invalid input. Try Again: ";
            string_handler();
        }        
    }
    
    cout<<"\nEnter X/O and the coordinates seperated by ','(X,1,1): ";
    string_handler();
    }

void checkit(){
    string input2;
        cout<<"\nPress\n1--> New Game\n2--> End Game\n";
        getline(cin,input2);
        input2.erase(remove(input2.begin(), input2.end(), ' '), input2.end());
        try{
            if(stoi(input2)==1){
                
            for(int i{0};i<z;i++){      
                    for(int j=0;j<z;j++){
                        matrix[i][j].clear();}}
                        cout<<"\n New Game \n";
                        main();
            }else if(stoi(input2)==2){
                exit(0);
            }
            else {
                throw std::invalid_argument("Invalid input.");}
        }
        catch(...){
            cout<<"Invalid input. Try Again: ";
            string_handler();
        }
}

void win(){
    while(true){//outofbound check so use j+2 aand i+2
        for(int i{0};i<z;i++){      
                    for(int j=0;j<z;j++){
                        if(j+2<z;matrix[i][j]=="X" && matrix[i][j+1]=="X" && matrix[i][j+2]=="X" ){noinputit();
                            cout<<"\nX WIN\n";checkit();grid();return;}
                        if(j+2<z;matrix[i][j]=="O" && matrix[i][j+1]=="O" && matrix[i][j+2]=="O" ){noinputit();
                            cout<<"\nO WIN\n";checkit();grid();return;}
                        if(i+2<z;matrix[i][j]=="X" && matrix[i+1][j]=="X" && matrix[i+2][j]=="X" ){noinputit();
                            cout<<"\nX WIN\n";checkit();grid();return;}
                        if(i+2<z;matrix[i][j]=="O" && matrix[i+1][j]=="O"&& matrix[i+2][j]=="O" ){noinputit();
                            cout<<"\nO WIN\n";checkit();grid();return;}
                        if(j+2<z && i+2<z;matrix[i][j]=="X" && matrix[i+1][j+1]=="X" && matrix[i+2][j+2]=="X" ){noinputit();
                            cout<<"\nX WIN\n";checkit();grid();return;}
                        if(j+2<z && i+2<z;matrix[i][j]=="O" && matrix[i+1][j+1]=="O" && matrix[i+2][j+2]=="O" ){noinputit();
                            cout<<"\nO WIN\n";checkit();grid();return;}
                        }
                        }
                        break;
                    }
        grid();
    }

void options(){
    string input3;
    cout<<"Enter\n1--> Input\n2--> New Game\n3--> End Game\n";
            getline(cin,input3);
            input3.erase(remove(input3.begin(), input3.end(), ' '), input3.end());
            try{
            if(stoi(input3)==1){
                grid();}
            else if(stoi(input3)==2){
                for(int i{0};i<z;i++){      
                    for(int j=0;j<z;j++){
                        matrix[i][j].clear();}}
                        cout<<"\n New Game \n";
                        main();}
            else if(stoi(input3)==3){
                exit(0);}
            else {
                throw std::invalid_argument("Invalid input.");}
        }
        catch(...){
            cout<<"Invalid input. Try Again\n";
            options();
        }
}

