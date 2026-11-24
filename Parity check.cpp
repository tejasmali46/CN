#include <iostream>
using namespace std;
int main(){
int n, data[20], count=0,parity;
 cout<<"Enter number of bits:";
 cin>>n;
 
 cout<<"\nEnter data bits:";
 for(int i=0;i<n;i++){
 	cin>>data[i];
 	if(data[i]==1){
 		count++;
	 }
 }
 if(count%2==0){
 	parity = 0;
 }
 else{
 	parity = 1;
 }
cout<<"Parity Bit"<<parity;

cout<<"\nTransmitted data:";
for(int i=0;i<n;i++){
 	cout<<data[i];
	 }
	 cout<<parity;
 
 
 int recieved[20],total=0;
 cout<<"\nEnter recieved data:";
 for(int i=0;i<=n;i++){
 	cin>>recieved[i];
 	if(recieved[i]==1){
 		total++;
	 }
 }
 if(total%2==0){
 	cout<<"No error detected";
 }
 else{
 	cout<<"Error detected";
 }
}
