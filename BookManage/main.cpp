#include<iostream>
#include<string>
#include<vector>

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
    for(int i=0;i<list.size();i++) printf("%d:%d %d년 이름:%s 작가:%s\n",list[i].number,list[i].writtenyear,(list[i].bookname).c_str(),(list[i].authorname).c_str());
}

int main(){
    string reply;
    while(true){
        printf("---\n1:등록 2:삭제 3:검색 4:종료");
        cin >> reply;
        if(reply=="1") add();
        else if(reply=="2") remove();
        //else if(reply=="3") search();
        else break;
    }
}