#include <iostream>
using namespace std;
int main(){
	cout<<"Enter column major matrix dimensions(i,j):"<<endl;
	int n,k,l,m;
	cin>>n;
	cin>>k;
	cout<<"Enter values for the "<<n<<"x"<<k<<" matrix"<<endl;
	int i,j,a[n][k];
	for(i=0;i<n;i++){
		for(j=0;j<k;j++){
			cout<<"pos - "<<i+1<<","<<j+1<<endl;
			cin>>a[i][j];
		}
	}
	int new_a[n*k];
	for(i=0;i<n;i++){
		for(j=0;j<k;j++){
			new_a[j*k+i]=a[i][j];
		}
	}
	cout<<"1D array is :"<<endl;
	for(i=0;i<n*k;i++){
		cout<<new_a[i]<<"\t";
	}
	cout<<"\nEnter desired position(i,j):"<<endl;
	cin>>l;
	cin>>m;
	int offset = (m-1)*k+(l-1);
	if(l>0 && m>0 && l<=n && m<=k){
		cout<<new_a[offset]<<endl;
	}
	else{
		cerr<<"Incorrect input";
		return -1;
	}
	return 0;
}
