#include <iostream>
using namespace std;
int abs(int n){
	if(n<0){
		return -n;
	}
	return n;
}
int main(){
	cout<<"Enter upper triangular matrix dimensions:"<<endl;
	int n,inputi,inputj;
	cin>>n;
	cout<<"Enter values for the "<<n<<"x"<<n<<" matrix"<<endl;
	int i,j,arr[n][n];
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			cout<<"pos - "<<i+1<<","<<j+1<<endl;
			cin>>arr[i][j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(!(j>=i)){
				arr[i][j]=0;
				cout<<arr[i][j]<<" ";
			}
			else{
				cout<<arr[i][j]<<" ";
			}
			if(j==2){
				cout<<"\n";
			}
		}
	}
	int new_a[n+(n*(n-1))/2];
	int check=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(arr[i][j]!=0){
				new_a[check]=arr[i][j];
				check++;
			}
		}
	}
	cout<<"1D array is :"<<endl;
	for(i=0;i<check;i++){
		cout<<new_a[i]<<"\t";
	}
	cout<<"\nEnter desired position(i,j):"<<endl;
	cin>>inputi;
	cin>>inputj;
	int temp1 = inputi;
	int temp2 = inputj;
	int offset = (inputi-1)*n+(inputj-1);
	(abs(temp2-temp1)==2)?(offset-=3):((abs(temp2-temp1)==1)?(offset-=1):(offset=offset));
	if(inputj>=inputi && inputj<=n && inputi<=n && inputj>0 && inputi>0){
		cout<<"Value is :"<<new_a[offset]<<endl;
	}
	else if(inputj<=n && inputi<=n && inputj>0 && inputi>0){
		cout<<"Value is :"<<0<<endl;
	}
	else{
		cerr<<"Incorrect input";
		return -1;
	}
	return 0;
}
