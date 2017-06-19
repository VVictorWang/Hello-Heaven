/*************************************************************************
	> File Name: LinkedList.h
	> Author: 
	> Mail: 
	> Created Time: Thu 02 Feb 2017 03:25:33 AM PST
 ************************************************************************/
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;
class Node{
 public:
    Node(){
        age = 17;
        name = "Victor";
        sex = "man";
        next = NULL;
    }
    Node(string name,int age,string sex){
        this->name = name;
        this->age = age;
        this->sex = sex;
        next = NULL;
    }
    int age;
    string name;
    string sex;
    Node *next;
};
class Student{
 private:
    Node *head,*tail;
    int size;
 public:
    Student(){
        head = tail = NULL;
        size = 0;
    }
    void addFStudent(string name,int age,string sex){
        Node *p = new Node(name,age,sex);
        if(head == NULL)
        {
            head = tail = p;
        }
        else{
            p->next = head;
            head = p;
        }
        size++;
    }
    void addLStudent(string name,int age,string sex){
        Node *p = new Node(name,age,sex);
        if(tail == NULL)
        {
            head = tail = p;
        }
        else{
            tail->next = p;
            tail = p;
        }
        size++;
    }
    int indexOf(string name){
        if(size == 0)
            throw runtime_error("Index out of range");
        else{
            Node *p = head;
            int i =1;
            while(p!=NULL && p->name!=name)
            {
                p = p->next;
                i++;
            }
            return i;
        }
    }
    string getLName(){
        if(size == 0)
            throw runtime_error("Index out of range");
        else
            return tail->name;
    }
    string removeFirst(){
        if(size == 0)
            throw runtime_error("empty list");
        else
        {
            Node *p = head;
            string name = p->name;
            head = p->next;
            if(head == NULL)
                tail = NULL;
            delete p;
            size--;
            return name;
        }
    }
    string removeLast(){
        if(size == 0)
            throw runtime_error("empty list");
        else if(size == 1)
        {
            return removeFirst();
        }
        else
        {
            Node *p = head;
            Node *previous = p;
            while(p!=tail)
            {
                previous = p;
                p = p->next;
            }
            string name = tail->name;
            tail = previous;
            previous->next = NULL;
            size--;
            delete p;
            return name;
        }
    }
    void add(string name,int age,string sex){
        addLStudent(name,age,sex);
    }
    void add(int index,string name,int age,string sex){
        Node *p = new Node(name,age,sex);
        if(index <= 0 && index > size)
            throw runtime_error("index out of range");
        else if(index == 1)
            addFStudent(name,age,sex);
        else if(index == size+1)
            addLStudent(name,age,sex);
        else{
            Node *now = head;
            int i=1;
            while(now!=NULL && i<index-1){
                i++;
                now = now->next;
            }
            p->next = now->next;
            now->next = p;
            size++;
        }
    }
    void clear(){
        if(size > 0)
        {
            while(head!=NULL)
            {
                Node *p = head;
                delete p;
                head = head->next;
            }
            tail = NULL;
            size = 0;
        }
    }
    bool contains(string name){
        if(size == 0)
            throw runtime_error("empty list");
        else{
            Node *p = head;
            while(p!=NULL && p->name!=name)
                p = p->next;
            if(p == NULL)
                return false;
            return true;
        }
    }
    string getName(int index){
        if(index <= 0 && index >size)
            throw runtime_error("index out of range");
        else{
            int i =1;
            Node *p = head;
            while(i<index && p!=NULL)
            {
                p = p->next;
                i++;
            }
            return p->name;
        }
    }
    int getAge(int index){
        if(index <= 0 && index >size)
            throw runtime_error("index out of range");
        else{
            int i =1;
            Node *p = head;
            while(i<index && p!=NULL)
            {
                p = p->next;
                i++;
            }
            return p->age;
        }
    }
    string getSex(int index){
        if(index <= 0 && index >size)
            throw runtime_error("index out of range");
        else{
            int i =1;
            Node *p = head;
            while(i<index && p!=NULL)
            {
                p = p->next;
                i++;
            }
            return p->sex;
        }
    }
    int getAge(string name){
        if(size == 0)
            throw runtime_error("empty list");
        else
        {
            Node *p = head;
            while(p!=NULL && p->name!=name){
                p = p->next;
            }
            if(p == NULL)
                return -1;
            return p->age;
        }
    }
    string getSex(string name){
        if(size == 0){
            throw runtime_error("empty list");
        }
        else{
            Node *p = head;
            while(p!=NULL&& p->name!=name)
            {
                p = p->next;
            }
            if(p == NULL)
                return "no such person";
            return p->sex;
        }
    }
    bool isEmpty(){
        return size==0;
    }
    void remove(string name){
        if(size == 0)
            throw runtime_error("empty list");
        else{
            Node *p = head;
            Node *previous = p;
            while(p!=NULL && p->name!=name){
                previous = p;
                p = p->next;
            }
            if(p == head)
                removeFirst();
            else if(p == tail)
                removeLast();
            else if(p == NULL){
                throw runtime_error("now element to remove");
            }
            else{
                previous->next = p->next;
                delete p;
                size--;
            }
        }
    }
    string removeAt(int index){
        if(index<=0&&index>size)
            throw runtime_error("index out of range");
        else if(size == 0)
            throw runtime_error("empty list");
        else if(index == 1)
        {
            string name = head->name;
            removeFirst();
            return name;
        }
        else if(index == size)
        {
            string name = tail->name;
            removeLast();
            return name;
        }
        else{
            int i =1;
            Node *p = head;
            Node *previous = p;
            while(i<index && p!=NULL){
                previous = p;
                p = p->next;
                i++;
            }
            string name = p->name;
            previous->next = p->next;
            delete p;
            size--;
            return name;
        }
    }
    int getSize(){
        return size;
    }
    void setName(string oriname,string name){
            Node *p = head;
            while(p->name!=oriname && p!=NULL)
            {
                p = p->next;
            }
            p->name = name;
    }
    void setAge(string oriname,int age){
            Node *p = head;
            while(p->name!=oriname && p!=NULL)
            {
                p = p->next;
            }
            p->age = age;
    }
    void setSex(string oriname,string sex){
            Node *p = head;
            while(p->name!=oriname && p!=NULL)
            {
                p = p->next;
            }
            p->sex = sex;
    }
    void set(string oriname,string name,int age,string sex){
            Node *p = head;
            while(p->name!=oriname && p!=NULL)
            {
                p = p->next;
            }
            p->name = name;
            p->age = age;
            p->sex = sex;
    }
};
#endif
