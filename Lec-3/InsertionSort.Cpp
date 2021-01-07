#include <bits/stdc++.h>
using namespace std;




int main(){

int arr[]={4,3,2,1};
int n=4;

for(int i=1;i<n;i++){
	//this integer will go from unsorted to sorted part
	int key=arr[i];
	int j=i-1;
	while(j>=0 && arr[j]>key){
		//make current index empty and move current element to right
		arr[j+1]=arr[j];
		//compare previous element now
		j--;
	}

	//j will point to first smaller element from the right so will be insert to j+1
	arr[j+1]=key;
}

for(int i=0;i<n;i++)
cout << arr[i] << " ";
cout << endl;


}