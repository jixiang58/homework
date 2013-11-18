/*
 学生信息管理系统
学生：姬祥
时间: 2013.11.1

*/


#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

struct Student
{
        int StuID;
        string name;
        double Score;
}Stu[105];

int num;
void AddStudents();
bool DeleteStudents();
void ScoreSet();
void ScoreSort();
void show(Student *stu,int n);
void options();

int main()
{
        int op;
    do{
        options();
        cin>>op;
        switch(op)
        {
        case 1: AddStudents();
                break;

        case 2: if(DeleteStudents())
                                cout<<"删除学生信息成功!"<<endl;
                else
                {
                        cout<<"删除学生信息失败，请重新选择操作!"<<endl;
                }
                break;

        case 3: ScoreSet(); 
                break;

        case 4: ScoreSort();
                break;

        case 5: show(Stu,num);
                break;

        case 6: return 0;

        default: cout<<"输入错误，请重新输入！\n";
        }
        }while(1);
        return 0;
}

void options()
{
        cout<<"请选择操作:\n";
        cout<<"1.学生信息增加"<<endl;
        cout<<"2.删除学生信息"<<endl;
        cout<<"3.学生成绩录入"<<endl;
        cout<<"4.学生成绩排名"<<endl;
        cout<<"5.显示学生成绩"<<endl;
        cout<<"6.退出"<<endl;
}

void AddStudents()
{
        cout<<"请输入学生信息：\n";
        cout<<"姓名： ";
        cin>>Stu[num].name;
        cout<<"学号： ";
        cin>>Stu[num].StuID;
        num++;
}

bool DeleteStudents()
{
        if(num==0)
                return false;
        else
        {
                Stu[num].StuID=0;
                Stu[num].name="";
                Stu[num].Score=0;
                num--;
                return true;
        }
}

void ScoreSet()
{
        cout<<"请依次输入学生分数信息：\n";
        int i;
        for(i=0;i<num;i++)
        {
                cout<<Stu[i].name<<": ";
                cin>>Stu[i].Score;
        }
}

int cmp(Student a,Student b)
{
        if(a.Score==b.Score)
                return a.StuID<b.StuID;
        return a.Score>b.Score;
}

void ScoreSort()
{
        sort(Stu,Stu+num,cmp);
}

void show(Student *stu,int n)
{
        cout<<endl;
        cout<<endl;
        cout<<"--------------学生信息---------------"<<endl;
        cout<<endl;
        cout<<"排名     姓名         学号        成绩"<<endl;
        for(int i=0;i<n;i++)
        {
                cout<<i+1<<"        "<<Stu[i].name<<"        "<<Stu[i].StuID<<"        "<<Stu[i].Score<<endl;
        }
        cout<<endl;
}

