#include <iostream>
#include<omp.h>

using namespace std;

int minVal(int arr[],int n){
	int minVal=arr[0];
	#pragma omp parallel for reduction(min:minVal)
	for(int i=0;i<n;i++){
		if(arr[i]<minVal){
			minVal=arr[i];
		}
	}	
	return minVal;
}

int maxVal(int arr[],int n){
	int maxVal=arr[0];
	#pragma omp parallel for reducion(max:maxVal)
	for(int i=0;i<n;i++){
		if(arr[i]>maxVal){
			maxVal=arr[i];
		}
	}
	return maxVal;
}
int sum(int arr[],int n){
	int sum=0;
	#pragma omp parallel for(+:sum)
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	return sum;
}
int avg(int arr[],int n){
	return (double)sum(arr,n)/n;
}
int main(){
	int n=7;
	int arr[]={11,22,4,27,89,23,45};
	cout<<"Min VAlue: "<<minVal(arr,n)<<"\n";
	cout<<"Max VAlue: "<<maxVal(arr,n)<<"\n";
cout<<"SumVAlue: "<<sum(arr,n)<<"\n";

cout<<"Average VAlue: "<<avg(arr,n)<<"\n";


	
}