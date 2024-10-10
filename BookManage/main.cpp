#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

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
    while(scanf("%d",&receive)){
        for(int i=receive;i<list.size()-1;i++) list[i]=list[i+1];
        list.pop_back();
    }
}

int main(){
    string reply;
    while(true){
        printf("---\n1:등록 2:삭제 3:검색 4:종료:");
        cin >> reply;
        if(reply=="1") add();
        else if(reply=="2") remove();
        //else if(reply=="3") search();
        else break;
    }
}