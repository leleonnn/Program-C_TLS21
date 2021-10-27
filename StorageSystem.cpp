#include <iostream>

using namespace std;

int CategoryTotal=0;
int DataTotal[1]={0};
string Storage[999][999];
int store(), open(), terminatecode();

///

int menuOption(){
    string Opt;
    cout<<"________________________________"<<endl<<"Choose Option (store/open/close)"<<endl;
    cin>>Opt;
    if(Opt=="store"){
        store();
    }else if(Opt=="open"){
        open();
    }else if(Opt=="close"){
        terminateCode();
    }else{
        cout<<"Error"<<endl;
        menuOption();
    }
    return 0;
}

int terminateCode(){
    cout<<"[Closing...]";  
    return 0;
}

///

int storeIn(int x){
    string Data;
    cout<<endl<<"Store Your Data!"<<endl;
    cin>>Data;
    DataTotal[x]=DataTotal[x]+1;
    Storage[x][DataTotal[x]]=Data;
    cout<<"[Data Stored]"<<endl;
    menuOption();
    return 0;
}

int store(){
    string Category;
    cout<<endl<<"Choose Category!"<<endl;
    cin>>Category;
    for(int i=0; i<=CategoryTotal; i++){
        if(Category==Storage[i][0]){
            storeIn(i);
            return 0;
        }
    }
    CategoryTotal++;
    Storage[CategoryTotal][0]=Category;
    storeIn(CategoryTotal);
    return 0;
}

///

int openIn(int x){
    string Data;
    cout<<endl<<"Open Data"<<endl;
    cin>>Data;
    for(int i=0; i<=DataTotal[x];i++){
        if(Data==Storage[x][i]){
            cout<<"[Opening "<<Data<<"]"<<endl<<"..."<<endl;
            menuOption();
            return 0;
        }
    }
    cout<<"[Error] Data Not Found"<<endl;
    menuOption();
    return 0;
}

int open(){
    string Category;
    cout<<endl<<"Open Category"<<endl;
    cin>>Category;
    for(int i=0; i<=CategoryTotal;i++){
        if(Category==Storage[i][0]){
            openIn(i);
            return 0;
        }
    }
    cout<<"[Error] Category Not Found"<<endl;
    menuOption();
    return 0;
}

///

int main(){
    menuOption();
    return 0;
}
