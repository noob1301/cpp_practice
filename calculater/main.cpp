/*
	실패작이다 이거야
*/
#include<iostream>
#include<vector>
#include<string>
#include<utility>

using namespace std;

vector<char> Tocalculate;
vector<pair<int,int>> SolveSequenceStore;

void FindSolveSequence(){
    int scaner=0;
    vector<int> FindOpener;
    while(scaner<Tocalculate.size()){
        if(Tocalculate[scaner]=='(')
            FindOpener.push_back(scaner);
        else if(Tocalculate[scaner]==')'){
            SolveSequenceStore.push_back({FindOpener.size()-1,scaner});
            FindOpener.pop_back();
        }    
        scaner++;    
    }
}

void OpenCloseSolver(){
    for(int i=0;i<SolveSequenceStore.size();i++){
        int n=SolveSequenceStore[i].first,m=SolveSequenceStore[i].second;
        while(n!=m){
            
        }
    }
}

void Solver(){
    FindSolveSequence();
    OpenCloseSolver();
}

int main(){
     string receiverespond;
     while(true){
         printf("계산기를 사용하시겠습니까?:");
         cin >> receiverespond;
         if(receiverespond=="No")
             break;
         printf("계산할 식:");
         char r=getchar();
         while(true){
             r=getchar();
             if(r=='\n')
                 break;
             Tocalculate.push_back(r);    
         }
         Solver();
     }
     return 0;
}