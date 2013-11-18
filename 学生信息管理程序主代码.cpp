/*
 ѧ����Ϣ����ϵͳ
ѧ��������
ʱ��: 2013.11.1

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
                                cout<<"ɾ��ѧ����Ϣ�ɹ�!"<<endl;
                else
                {
                        cout<<"ɾ��ѧ����Ϣʧ�ܣ�������ѡ�����!"<<endl;
                }
                break;

        case 3: ScoreSet(); 
                break;

        case 4: ScoreSort();
                break;

        case 5: show(Stu,num);
                break;

        case 6: return 0;

        default: cout<<"����������������룡\n";
        }
        }while(1);
        return 0;
}

void options()
{
        cout<<"��ѡ�����:\n";
        cout<<"1.ѧ����Ϣ����"<<endl;
        cout<<"2.ɾ��ѧ����Ϣ"<<endl;
        cout<<"3.ѧ���ɼ�¼��"<<endl;
        cout<<"4.ѧ���ɼ�����"<<endl;
        cout<<"5.��ʾѧ���ɼ�"<<endl;
        cout<<"6.�˳�"<<endl;
}

void AddStudents()
{
        cout<<"������ѧ����Ϣ��\n";
        cout<<"������ ";
        cin>>Stu[num].name;
        cout<<"ѧ�ţ� ";
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
        cout<<"����������ѧ��������Ϣ��\n";
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
        cout<<"--------------ѧ����Ϣ---------------"<<endl;
        cout<<endl;
        cout<<"����     ����         ѧ��        �ɼ�"<<endl;
        for(int i=0;i<n;i++)
        {
                cout<<i+1<<"        "<<Stu[i].name<<"        "<<Stu[i].StuID<<"        "<<Stu[i].Score<<endl;
        }
        cout<<endl;
}

