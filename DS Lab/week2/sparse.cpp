#include <iostream>
using namespace std;
struct oneD{
	int row;
	int column;
	int value;
};
int main(){
	cout<<"Enter sparse matrix dimensions(i,j):"<<endl;
	int n,k,l,m,sparse;
	cin>>n;
	cin>>k;
	cout<<"Enter values for the "<<n<<"x"<<k<<" matrix"<<endl;
	int i,j,a[n][k];
	for(i=0;i<n;i++){
		for(j=0;j<k;j++){
			cout<<"pos - "<<i+1<<","<<j+1<<endl;
			cin>>a[i][j];
			if(a[i][j]==0){
				sparse++;
			}
		}
	}
	if(sparse<n*k-sparse){
		cerr<<"Not sparse";
		return -1;
	}
	oneD arr[n*k-sparse];
	int check;
	for(i=0;i<n;i++){
		for(k=0;k<n;k++){
			if(a[i][j]!=0){
				arr[check].row=i;
				arr[check].column=j;
				arr[check].value=a[i][j];
				cout<<arr[check].row<<"\t"<<arr[check].column<<"\t"<<arr[check].value<<"\n";
				check++;
			}
		}
	}
}
