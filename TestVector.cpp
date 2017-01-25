#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<int> intVector;
	for(int i=0;i<10;i++)
		intVector.push_back(i+5);
	for(int i=0;i<intVector.size();i++)
		cout<<intVector[i]<<"  ";
	cout<<endl;
	vector<string> string1;
	string1.push_back("Victor Wang");
	string1.push_back("Bob Jui");
	string1.push_back("Marry Hui");
	for(int i=0;i<string1.size();i++)
		cout<<string1[i]<<"  ";
	cout<<endl;
	string1.pop_back();
	vector<string> v2;
	v2.swap(string1);
	v2[0]="Gui Koi";
	for(int i=0;i<v2.size();i++)
		cout<<v2.at(i)<<"  ";
	cout<<endl;
	return 0;
}
