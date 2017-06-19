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
using namespace std;
template <typename T>
class Node{
 public:
    Node(){
        next = NULL;
    }
    Node(T element){
        this->element = element;
        next = NULL;
    }
    T element;
    Node<T> *next;
};
template <typename T>
class LinkedList{
 private:
    Node<T> *head,*tail;
    int size;
 public:
    LinkedList(){
        head = tail = NULL;
        size = 0;
    }
    void addFirst(T element){
        Node<T> *p = new Node<T>(element);
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
    void addLast(T element){
        Node<T> *p = new Node<T>(element);
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
    T getFirst(){
        if(size == 0)
            throw runtime_error("Index out of range");
        else
            return head->element;
    }
    T getLast(){
        if(size == 0)
            throw runtime_error("Index out of range");
        else
            return tail->element;
    }
    T removeFirst(){
        if(size == 0)
            throw runtime_error("empty list");
        else
        {
            Node<T> *p = head;
            T ele = p->element;
            head = p->next;
            if(head == NULL)
                tail = NULL;
            delete p;
            size--;
            return ele;
        }
    }
    T removeLast(){
        if(size == 0)
            throw runtime_error("empty list");
        else if(size == 1)
        {
            Node<T> *p = head;
            T ele = p->element;
            delete p;
            head = tail = NULL;
            size--;
            return ele;
        }
        else
        {
            Node<T> *p = head;
            Node<T> *previous = p;
            while(p!=tail)
            {
                previous = p;
                p = p->next;
            }
            T ele = tail->element;
            tail = previous;
            previous->next = NULL;
            size--;
            delete p;
            return ele;
        }
    }
    void add(T element){
        addLast(element);
    }
    void add(int index,T element){
        Node<T> *p = new Node<T>(element);
        if(index <= 0 && index > size)
            throw runtime_error("index out of range");
        else if(index == 1)
            addFirst(element);
        else if(index == size+1)
            addLast(element);
        else{
            Node<T> *now = head;
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
                Node<T> *p = head;
                delete p;
                head = head->next;
            }
            tail = NULL;
            size = 0;
        }
    }
    bool contains(T element){
        if(size == 0)
            throw runtime_error("empty list");
        else{
            Node<T> *p = head;
            while(p!=NULL && p->element!=element)
                p = p->next;
            if(p == NULL)
                return false;
            return true;
        }
    }
    T get(int index){
        if(index <= 0 && index >size)
            throw runtime_error("index out of range");
        else{
            int i =1;
            Node<T> *p = head;
            while(i<index && p!=NULL)
            {
                p = p->next;
                i++;
            }
            return p->element;
        }
    }
    int indexOf(T element){
        if(size == 0)
            throw runtime_error("empty list");
        else
        {
            int i =1;
            Node<T> *p = head;
            while(p!=NULL && p->element!=element){
                i++;
                p = p->next;
            }
            if(p == NULL)
                return -1;
            return i;
        }
    }
    int LastIndexOf(T element){
        if(size == 0){
            throw runtime_error("empty list");
        }
        else{
            int i =1;
            int k = -1;
            Node<T> *p = head;
            while(p!=NULL)
            {
                if(p->element==element)
                    k = i;
                p = p->next;
                i++;
            }
            return k;
        }
    }
    bool isEmpty(){
        return size==0;
    }
    void remove(T element){
        if(size == 0)
            throw runtime_error("empty list");
        else{
            Node<T> *p = head;
            Node<T> *previous = p;
            while(p!=NULL && p->element!=element){
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
    T removeAt(int index){
        if(index<=0&&index>size)
            throw runtime_error("index out of range");
        else if(size == 0)
            throw runtime_error("empty list");
        else if(index == 1)
        {
            T ele = head->element;
            removeFirst();
            return ele;
        }
        else if(index == size)
        {
            T ele = tail->element;
            removeLast();
            return ele;
        }
        else{
            int i =1;
            Node<T> *p = head;
            Node<T> *previous = p;
            while(i<index && p!=NULL){
                previous = p;
                p = p->next;
                i++;
            }
            T ele = p->element;
            previous->next = p->next;
            delete p;
            size--;
            return ele;
        }
    }
    int getSize(){
        return size;
    }
    T set(int index, T element){
        if(index<=0 && index>size)
            throw runtime_error("index out of range");
        else{
            Node<T> *p = head;
            int i =1;
            while(i<index && p!=NULL)
            {
                p = p->next;
                i++;
            }
            T ele = p->element;
            p->element = element;
            return ele;
        }
    }
};
#endif
