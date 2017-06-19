/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 02 Feb 2017 04:48:55 AM PST
 ************************************************************************/

#include<iostream>
using namespace std;
#include <string>
#include "LinkedList.h"
void print(LinkedList<string> list){
    for(int i=1;i<=list.getSize();i++)
        cout<<list.get(i)<<"  ";
    cout<<endl;
}
int main()
{
    LinkedList<string> list;
    list.add("Victor");
    list.add("Wang");
    list.addFirst("Hello");
    list.addLast("World");
    print(list);
    cout<<list.removeFirst()<<endl;
    print(list);
    cout<<list.removeLast()<<endl;
    print(list);
    list.add(2,"HeaVon");
    print(list);
    cout<<list.contains("Victor")<<endl;
    cout<<list.contains("FHY")<<endl;
    cout<<list.indexOf("HeaVon")<<endl;
    list.add(3,"Victor");
    cout<<list.LastIndexOf("Victor")<<endl;
    print(list);
    cout<<list.removeAt(3)<<endl;
    print(list);
    list.remove("Wang");
    print(list);
    cout<<list.set(2,"Wang")<<endl;
    print(list);
    cout<<list.getSize()<<endl;
    cout<<list.getFirst()<<endl;
    cout<<list.getLast()<<endl;
    return 0;
}
