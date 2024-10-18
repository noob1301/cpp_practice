#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<regex>

using namespace std;

class UserInformation{
public:
    string ID;
    string Password;
    pair<int,int> ManageClass;
    UserInformation(string a,string b,pair<int,int> c){
        ID=a,Password=b;
        ManageClass={c.first,c.second};
    }
};

vector<UserInformation> Userlist;

int FindUserIndex(string receive){
    for(int i=0;i<Userlist.size();i++)
        if(Userlist[i].ID==receive) return i;
    return -1;    
}

bool isAlreadyExist(string receive){
    for(int i=0;i<Userlist.size();i++)
        if(Userlist[i].ID==receive) return true;
    return false;    
}

int main(){
    int reply,UserIndex;
    string reply_str;
    regex HaveShouldOnIDandPW(R"([a-zA-Z0-9]{4,15})");
    regex DoNotHaveOnID(R"([!@#$%^&*()]+)");
    regex HaveShouldOnPW(R"([!_]+)");
    regex CantHavePatternOnPW(R"([a-zA-Z!_]{4,14}[_]+)");
    while(true){
        while(true){
            printf("1.로그인 2.회원가입 3.종료:");
            scanf("%d",&reply);
            if(reply==1){
                printf("아이디 입력:");
                cin>>reply_str;
                if(FindUserIndex(reply_str)==-1) printf("없는 아이디\n");
                else{
                    UserIndex=FindUserIndex(reply_str);
                    printf("비밀번호 입력:");
                    cin>>reply_str;
                    if(reply_str==Userlist[UserIndex].Password){
                        printf("환영합니다. %s님\n",(Userlist[UserIndex].ID).c_str());
                        break;
                    }
                    else printf("잘못된 비밀번호입니다.\n");
                }
            }
            else if(reply==2){
                printf("새로운 아이디 입력:");
                cin>>reply_str;
                if(isAlreadyExist(reply_str)) printf("이미 존재하는 아이디입니다.\n");
                else if(!regex_match(reply_str,HaveShouldOnIDandPW)||regex_search(reply_str,DoNotHaveOnID))
                    printf("아이디 형식이 맞지 않습니다.ex)4~15글자아님,특수기호 사용\n");
                else{
                    string Store_ID=reply_str,Store_Password;
                    printf("비밀번호 입력:");
                    cin>>reply_str;
                    if(!regex_match(reply_str,HaveShouldOnIDandPW)||!regex_search(reply_str,HaveShouldOnPW)||regex_match(reply_str,CantHavePatternOnPW)){
                        printf("잘못된 비밀번호 형식입니다.ex)4~15글자가 아님,!또는_미사용,_를 끝에 사용\n");
                    }
                    else{
                        Store_Password=reply_str;
                        printf("몇반을 관리?ex)3-2:");
                        int a,b;
                        scanf("%d-%d",&a,&b);
                        if(a>99||b>99) printf("존재할 수 없는 반");
                        else{
                            Userlist.push_back(UserInformation(Store_ID,Store_Password,{a,b}));
                            UserIndex=Userlist.size()-1;
                            printf("환영합니다. %님\n",(Userlist[UserIndex].ID).c_str());
                            break;
                        }
                    }
                }
            }
            else if(reply==3){
                printf("이용해 주셔서 감사합니다");
                return 0;
            }
        }
        printf("break확인됨");
    }
}