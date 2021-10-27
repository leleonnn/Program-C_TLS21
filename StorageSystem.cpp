#include <iostream>

using namespace std;

int CategoryTotal=0;
int DataTotal[1]={0};
string Storage[999][999];
void store(), open();

///

int terminateCode(){
    return 0;
}

void menuOption(){
    string Opt;
    cout<<"________________________________"<<endl<<"Choose Option (store/open/close)"<<endl;
    cin>>Opt;
    if(Opt=="store"){
            store();
    }else if(Opt=="open"){
            open();
    }else if(Opt=="close"){
            cout<<"[Closing...]"; 
            terminateCode();
    }else{
            cout<<"Error"<<endl;
            menuOption();
    }
}

///

void storeIn(int x){
    string Data;
    cout<<endl<<"Store Your Data!"<<endl;
    cin>>Data;
    DataTotal[x]=DataTotal[x]+1;
    Storage[x][DataTotal[x]]=Data;
    cout<<"[Data Stored]"<<endl;
    menuOption();
}

void store(){
    string Category;
    cout<<endl<<"Choose Category!"<<endl;
    cin>>Category;
    for(int i=0; i<=CategoryTotal; i++){
        if(Category==Storage[i][0]){
            storeIn(i);
        }
    }
    CategoryTotal++;
    Storage[CategoryTotal][0]=Category;
    storeIn(CategoryTotal);
}

///

void openIn(int x){
    string Data;
    cout<<endl<<"Open Data"<<endl;
    cin>>Data;
    for(int i=0; i<=DataTotal[x];i++){
        if(Data==Storage[x][DataTotal[x]]){
            cout<<"[Opening "<<Data<<"]"<<endl<<"..."<<endl;
            menuOption();
        }
    }
    cout<<"[Error] Data Not Found"<<endl;
    menuOption();
}

void open(){
    string Category;
    cout<<endl<<"Open Category"<<endl;
    cin>>Category;
    for(int i=0; i<=CategoryTotal;i++){
        if(Category==Storage[i][0]){
            openIn(i);
        }
    }
    cout<<"[Error] Category Not Found"<<endl;
    menuOption();
}

///

int main(){
    menuOption();
    return 0;
}
