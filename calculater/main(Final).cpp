#include<iostream>
#include<string>
#include<vector>
#include<utility>

using namespace std;

vector<char> list;
vector<char> list_store;
vector<int> numberstore;

pair<int,int> FindClose(){
    int Opener,Closer=0;
    for(int i=0;i<list.size();i++){
        if(list[i]=='(') Opener=i;
        if(list[i]==')') return {Opener,i};
    }
    return {0,0};
}

void NumberJudger(){
    for(int i=0;i<list.size();i++){
        int s=0,h;
        if(list[i]>='0'&&list[i]<='9'){
            h=i;
            while(list[i]>='0'&&list[i]<='9'){
                s=(10*s)+list[i]-'0';
                i++;
            }
            list[h]=numberstore.size();
            numberstore.push_back(s);
            for(int j=h+1;j<i;j++) {
                list[j]=0;
            }
        }
    }    
}

void ListMakeEasy(){
    for(int i=0;i<list.size();i++){
        if(list[i]==0)
            continue;
        list_store.push_back(list[i]);
    }
    list=list_store;
}

void LtoRMakeeasy(pair<int,int> a,bool noBracket){
    int S=numberstore[list[a.first+1]];
    for(int i=a.first+1;i<=a.second-3;i+=2){
        if(list[i+1]=='+') S+=numberstore[list[i+2]];
        if(list[i+1]=='-') S-=numberstore[list[i+2]];
        if(list[i+1]=='*') S*=numberstore[list[i+2]];
        if(list[i+1]=='/') S/=numberstore[list[i+2]];
        printf("S의 상태:%d\n",S);
        cout << "list[i]: " << static_cast<int>(list[i]) << endl;
    }
    if (!noBracket){
        for(int i=a.first;i<a.second;i++) list[i]=0;
        list[a.second]=numberstore.size();
    }
    list[a.second-1]=numberstore.size();
    numberstore.push_back(S);
}

int Solver(){
    NumberJudger();
    while(FindClose().second!=0){
        LtoRMakeeasy(FindClose(),false);
        ListMakeEasy();
    }
    LtoRMakeeasy({-1,list.size()},true);
    return numberstore[list[list.size()-1]];
}

int main(){
    string respond;
    while(true){
        printf("\n계산기를 사용하시겠습니까?:");
        cin>>respond;
        if(respond=="no") break;
        printf("계산할 식:");
        numberstore={0};
        list.clear();
        list_store.clear();
        char receive=getchar();
        while(1){
            receive=getchar();
            if(receive=='\n')
                break;
            list.push_back(receive);
        }
        printf("=%d",Solver());
    }
}