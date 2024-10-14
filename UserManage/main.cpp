#include<iostream>
#include<string>
#include<regex>
#include<vector>

using namespace std;

class User{
public:
    string name;
    int old;
    string mail;
    string password;
    User(string a,int b,string c,string d){
        name=a,mail=c,password=d;
        old=b;
    }
};

vector<User> list;

void AddUser(){
    int reply_d;
    string reply_sN,reply_sM,reply_sP;
    printf("정보입력(이름 나이 이메일주소 비번):");
    cin>>reply_sN>>reply_d>>reply_sM>>reply_sP;
    list.push_back(User(reply_sN,reply_d,reply_sM,reply_sP));
}

void ChangeInformation(){
    string reply_cN;
}

void DeleteUser(){
    
}

int main(){
    int receive;
    while(true){
        printf("\n1.회원가입 2.정보변경 3.회원탈퇴:");
        scanf("%d",&receive);
        if(receive==1) AddUser();
        else if(receive==2) ChangeInformation();
        else if(receive==3) DeleteUser();
        else break;
    }
}