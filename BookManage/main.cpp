#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

/*
이것도 망했다 익어야
*/

using namespace std;

class Aboutbook{
public:    
    int number;
    int writtenyear;
    string bookname;
    string authorname;
    Aboutbook(int a,int b,string c,string d){
        number=a;
        writtenyear=b;
        bookname=c;
        authorname=d;
    }
    bool operator<(const Aboutbook&a)const{
        return number<a.number;
    }
};

vector<Aboutbook> list;

void add(){
    while(true){
        int num,year;
        string book,author;
        printf("책 정보를 입력하세요(number year bookname authorname):");
        cin >> num >> year >> book >> author;
        if(author=="end") break;
        list.push_back(Aboutbook(num,year,book,author));
    }
}

void remove(){
    int receive;
    std::sort(list.begin(),list.end());
    for(int i=0;i<list.size();i++) printf("%d:%d %s %s\n",list[i].number,list[i].writtenyear,(list[i].bookname).c_str(),(list[i].authorname).c_str());
    printf("삭제할 책 번호(띄어쓰기로 구분):");
    while(scanf("%d",receive)){
        int index=0;
        while(index<list.size()){
            if(list[index].number==receive) break;
        }
        if(list[index].number!=receive) continue;
        else{
            for(int i=index;i<list.size()-2;i++) list.at(i)=list.at(i);
        }
    }
    list.pop_back();
}

int main(){
    string reply;
    while(true){
        printf("---\n1:등록 2:삭제 3:검색 4:종료\n입력:");
        cin >> reply;
        if(reply=="1") add();
        else if(reply=="2") remove();
        //else if(reply=="3") search();
        else break;
    }
}