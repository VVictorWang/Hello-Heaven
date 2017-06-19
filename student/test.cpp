/*
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 02 Feb 2017 07:55:05 AM PST
 ************************************************************************/
#include<iostream>
using namespace std;
#include "student.h"
#include <cstdlib>
#include <string>
Student student;
void changeName(string );
void changeSex(string );
void changeAge(string );
void changeAll(string );
void print(Student student){
    for(int i =1;i<=student.getSize();i++)
        cout<<student.getName(i)<<"   "<<student.getAge(i)<<"     "<<student.getSex(i)<<endl;
    cout<<endl;
}
void menu(){
    cout<<"\t\t\t\t******欢迎进入学生信息管理系统****"<<endl<<endl<<endl;
    cout<<"\t\t1.输入学生信息\t\t2.打印学生信息\t\t3.查找学生"<<endl;
    cout<<"\t\t4.删除学生信息\t\t5.修改学生信息"<<"\t\t0.退出"<<endl;
}
void find(){
    string name;
    cout<<"输入你想查找的学生姓名：";
    cin>>name;
    cout<<"姓名： "<<name<<endl;
    cout<<"年龄:  "<<student.getAge(name)<<endl;
    cout<<"性别:  "<<student.getSex(name)<<endl;
}
void change(){
    cout<<"输入你想修改的学生姓名：";
    string name;
    cin>>name;
    cout<<"  "<<name<<"  "<<student.getAge(name)<<"  "<<student.getSex(name)<<endl;
    cout<<"\t1.修改姓名\t2.修改年龄\t3.修改性别\t4.修改全部信息"<<endl;
    cout<<"输入你的选择：";
    int choi;
    cin>>choi;
    switch(choi){
        case 1:changeName(name);break;
        case 2:changeAge(name);break;
        case 3:changeSex(name);break;
        case 4:changeAll(name);break;
    }
}
void changeName(string name){
    string nname;
    cout<<"输入新名字：";
    cin>>nname;
    student.setName(name,nname);
}
void changeSex(string name){
    string sex;
    cout<<"输入新性别：";
    cin>>sex;
    student.setSex(name,sex);
}
void changeAge(string name){
    int age;
    cout<<"输入新年龄：";
    cin>>age;
    student.setAge(name,age);
}
void changeAll(string name){
    changeName(name);
    changeSex(name);
    changeAge(name);
}
void add(){
    string name,sex;
    int age;
    cout<<"输入学生姓名：";
    cin>>name;
    cout<<"输入学生年龄：";
    cin>>age;
    cout<<"输入学生性别：";
    cin>>sex;
    student.add(name,age,sex);
}
void remov(){
    string name;
    cout<<"输入你想要删除的学生的姓名";
    cin>>name;
    student.remove(name);
}
int main()
{
    while(true){
    menu();
    int choice;
    cin>>choice;
    switch(choice){
        case 0:exit(0);break;
        case 1:add();break;
        case 2:print(student);break;
        case 3:find();break;
        case 4:remov();break;
        case 5:change();break;
    }}
    return 0;
}
