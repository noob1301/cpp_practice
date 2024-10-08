#include<iostream>
#include<string>
#include<vector>
#include<utility>

using namespace std;

vector<char> list;
vector<char> list_store;
vector<int> numberstore={0};

bool MatchingFinder(){
    for(int i=0;i<list.size();i++)
        if(list[i]==')') return true;
    return false;    
}

pair<int,int> MatchingIndex(){
    int OpenIndex;
    for(int i=0;i<list.size();i++){
        if(list[i]=='(') OpenIndex=i;
        if(list[i]==')') return {OpenIndex,i};
    }
}

void ListMakeSimple(){
    list_store.clear();
    for(int i=0;i<list.size();i++){
        if(list[i]==0) continue;
        else list_store.push_back(list[i]);
    }
    list=list_store;
}

void NumberParshing(){
    int Sum;
    for(int i=0;i<list.size();i++){
         if(list[i]>='0'&&list[i]<='9'&&list[i]!='('){
             Sum=0;
             while(list[i]>='0'&&list[i]<='9'){
                 Sum=Sum*10+list[i]-'0';
                 list[i]=0;
                 i++;
             }
         list[i-1]=numberstore.size();
         numberstore.push_back(Sum);
         }
    }
    ListMakeSimple();
}

void Calculater(pair<int,int> Index){
    int Result=numberstore[list[Index.first+1]];
    for(int i=Index.first+1;i<=Index.second-3;i+=2){
        if(list[i+1]=='+') Result+=numberstore[list[i+2]];
        if(list[i+1]=='-') Result-=numberstore[list[i+2]];
        if(list[i+1]=='*') Result*=numberstore[list[i+2]];
        if(list[i+1]=='/') Result/=numberstore[list[i+2]];
    }
    for(int i=Index.first;i<Index.second;i++) list[i]=0;
    if(!MatchingFinder()) list[Index.second-1]=numberstore.size();
    else list[Index.second]=numberstore.size();
    numberstore.push_back(Result);
    ListMakeSimple();
}

int solver(){
    NumberParshing();
    while(MatchingFinder()) Calculater(MatchingIndex());
    Calculater({-1,list.size()});
    return numberstore[list[0]];
}

int main(){
    while(true){
        string respond;
        printf("계산기를 사용하시겠습니까?:");
        cin>>respond;
        if(respond=="no") break;
        numberstore={0};
        list.clear();
        printf("계산할 식:");
        char Respond=getchar();
        while(true){
            Respond=getchar();
            if(Respond=='\n') break;
            list.push_back(Respond);
        }
        printf("=%d\n",solver());
    }
}