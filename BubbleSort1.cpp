#include <iostream>
#include<omp.h>
using namespace std;

void bubble(int arr[],int n){
for(int i=0;i<n-1;i++)
{
for(int j=0;j<n-i-1;j++){
	if(arr[j]>arr[j+1]){
	swap (arr[j],arr[j+1]);
}
}
}
}
void pbubble(int arr[],int n){
//sort odd index number
for(int i=0;i<n;++i)
{
#pragma omp for
for(int j=1;j<n;j+=2){
	if(arr[j]<arr[j-1]){
	swap (arr[j],arr[j-1]);
}
}
#pragma omp barrier
for(int j=2;j<n;j+=2){
	if(arr[j]<arr[j-1]){
	swap (arr[j],arr[j-1]);
}
}
}
}
void printArray(int arr[],int n){
for(int i=0;i<n;i++){
cout<<arr[i]<<" ";

}
}


int main(){
int n=10;
int arr[n];
for(int i=0;i<n;i++){
cin>>arr[i];
}
bubble(arr,n);
cout<<"Sequential Bubble Sort";
printArray(arr,n);

pbubble(arr,n);
cout<<"Parallel Bubble Sort";
printArray(arr,n);

}