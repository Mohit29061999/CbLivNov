#include <bits/stdc++.h>
using namespace std;

int c=0;

int turn=0;  //turn ==0 means we have to count only

void splitArray(int a[],int n,int i,int l[],int j,int r[],int k){
	//base case:
	if(i==n){
		int s1=0;
		for(int w=0;w<j;w++)
			s1+=l[w];

		int s2=0;
		for(int w=0;w<k;w++)
			s2+=r[w];

		if(s1==s2){
          c++;
          if(turn==1){
			for(int w=0;w<j;w++)
				cout << l[w] << " ";
			cout << " and ";

			for(int w=0;w<k;w++)
				cout << r[w] << " ";
			
             cout << endl;
          }
		}

		return;

	}

	//add ith to left part
	l[j]=a[i];
	splitArray(a,n,i+1,l,j+1,r,k);

	//add ith to right part
	r[k]=a[i];
	splitArray(a,n,i+1,l,j,r,k+1);


}

int main(){
	int n;
	cin>>n;

	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];

	int l[n];
	int r[n];

    sort(a,a+n);

    //pahle count chahiye then ouput 
  
  splitArray(a,n,0,l,0,r,0);
  cout << c << endl;

  turn =1;  //means print solution

   splitArray(a,n,0,l,0,r,0);

}
