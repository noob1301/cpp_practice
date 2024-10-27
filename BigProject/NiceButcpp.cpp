#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<regex>

using namespace std;

class ClassInformation{
public:
    int grade;
    int classNumber;
    ClassInformation()=default;
    ClassInformation(int grade,int classNumber):grade(grade),classNumber(classNumber){}
};

class UserInformation{
public:
    string ID;
    string Password;
    ClassInformation classInformation;
    UserInformation(string a,string b,ClassInformation c):ID(a),Password(b),classInformation(c){}
};

class StudentInformation : public ClassInformation{
public:
    int number;
    string name;
    string detail;
    StudentInformation(int a,int b,int c,string d){
        grade=a;
        classNumber=b;
        number=c;
        name=d;
        detail="NULL";
    }
};

vector<UserInformation> Userlist;
vector<StudentInformation> StudentsList;

int FindUserIndex(string receive){
    for(int i=0;i<Userlist.size();i++)
        if(Userlist[i].ID==receive) return i;
    return -1;
}

bool isAlreadyExists(string receive){
    for(int i=0;i<Userlist.size();i++)
        if(Userlist[i].ID==receive) return true;
    return false;    
}

void AddStudentInformation(int grade,int classNumber){
    int receiveGrade,receiveClassNumber,number;
    string name;
    printf("학생 정보를 입력ex)3-1 10 안현준:");
    scanf("%d-%d %d",&receiveGrade,&receiveClassNumber,&number);
    cin>>name;
    if(receiveGrade!=grade||receiveClassNumber!=classNumber) printf("자신의 반만 추가가능합니다!\n");
    else if(number>99) printf("불가능한 번호\n");
    else{
        StudentsList.push_back(StudentInformation(receiveGrade,receiveClassNumber,number,name));
        printf("추가 완료.\n");
    }
}

void ChangeStudentInformation(int grade,int class_num){
    bool HavingSameClass=false;
    int receive;
    vector<int> MathingStudntsIndexList;
    for(int i=0;i<StudentsList.size();i++)
        if(StudentsList[i].grade==grade&&StudentsList[i].classNumber==class_num){
            MatchingStudentsIndexList.push_back(i);
            printf("%d번 %s 세특%s\n",StudentsList[i].number,StudentsList[i].name.c_str(),(StudentsList[i].detail=="NULL")?"무":"유");
            HavingSameClass=true;
        }
    if(!HavingSameClass){
        printf("학생 미존재\n");
        return;
    }
    
}

int main(){
    int reply,UserIndex;
    string reply_str;
    regex HaveShouldOnID(R"([a-zA-Z0-9]{4,15})");
    regex DoNotHaveOnID(R"([!@#$%^&*()]+)");
    regex HaveShouldOnPW(R"([a-zA-Z0-9!_]{4,15})");
    regex HaveShouldOnPW2(R"([!_]+)");
    regex CantHavePatternOnPW(R"([a-zA-Z!_]{3,14}[_]+)");
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
                if(isAlreadyExists(reply_str)) printf("이미 존재하는 아이디입니다.\n");
                else if(!regex_match(reply_str,HaveShouldOnID)||regex_search(reply_str,DoNotHaveOnID))
                    printf("아이디 형식이 맞지 않습니다.ex)4~15글자아님,특수기호 사용\n");
                else{
                    string Store_ID=reply_str,Store_Password;
                    printf("비밀번호 입력:");
                    cin>>reply_str;
                    if(!regex_match(reply_str,HaveShouldOnPW)||!regex_search(reply_str,HaveShouldOnPW2)||regex_match(reply_str,CantHavePatternOnPW)){
                        printf("잘못된 비밀번호 형식입니다.ex)4~15글자가 아님,!또는_미사용,_를 끝에 사용\n");
                    }
                    else{
                        Store_Password=reply_str;
                        printf("몇반을 관리?ex)3-2:");
                        int a,b;
                        scanf("%d-%d",&a,&b);
                        if(a>99||a<1||b>99||b<1) printf("존재할 수 없는 반");
                        else{
                            Userlist.push_back(UserInformation(Store_ID,Store_Password,ClassInformation(a,b)));
                            UserIndex=Userlist.size()-1;
                            printf("환영합니다. %s님\n",(Userlist[UserIndex].ID).c_str());
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
        while(true){
            printf("[%d학년%d반]1.학생 추가 2.학생 정보 변경 3.학생 정보 출력 4.로그아웃:",Userlist[UserIndex].classInformation.grade,Userlist[UserIndex].classInformation.classNumber);
            scanf("%d",&reply);
            if(reply==1) AddStudentInformation(Userlist[UserIndex].classInformation.grade,Userlist[UserIndex].classInformation.classNumber);
            else if(reply==2) ChangeStudentInformation(Userlist[UserIndex].classInformation.grade,Userlist[UserIndex].classInformation.classNumber);
            /*else if(reply==3)*/
            else break;
        }
    }
}