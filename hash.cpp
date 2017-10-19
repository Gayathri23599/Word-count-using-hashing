#include<iostream>
#include<math.h>
#include<string.h>
#include<fstream>
#include<iomanip>
#include<algorithm>
using namespace std;
class Hash
{
	string *a;
	int *c,n;
	int count;
	public:
		Hash(){
			count = 0;
			n = 281;
			c = new int[n];
			a = new string[n];
			for(int i =0;i<n;i++)
				c[i] = 0;
		}
		Hash(int x){
			count = 0;
			n = x;
			c = new int[x];
			a = new string[x];
			for(int i=0;i<x;i++)
				c[i] = 0;
		}
		void insert(string);
		int hash(string);
		void display();
};
void Hash::insert(string x){
	int y = hash(x);
	a[y] = x;
	c[y] += 1;
}
int Hash::hash(string x){
	count++;
	int k = x.length();
	unsigned long long int s = 0;
	for(int i=0;i<k;i++){
		s+=(x[k-i-1]*pow(37,i));
	}
	return s%n;
}
void Hash::display(){
	for(int i=0;i<n;i++){
		if(c[i]!=0)
			cout<<setw(20)<<a[i]<<'\t'<<c[i]<<endl;
	}
	cout<<"Total word count:"<<count<<endl;
}
int main()
{
	string data;
	Hash a;
	char dat[25];
	cout<<"Enter the file name"<<endl;
	cin>>dat;
	ifstream infile;
	infile.open(dat);
	infile>>data;
	if(infile.fail())
		cout<<"Error in opening the file.Check the file name or enter the entire path"<<endl;
	else{
		while(!infile.eof()){
			a.insert(data);
			infile>>data;
			replace(data.begin(),data.end(),'.',' ');
			replace(data.begin(),data.end(),',',' ');
		}
		a.display();
		infile.close();
	}
	return 0;
}
