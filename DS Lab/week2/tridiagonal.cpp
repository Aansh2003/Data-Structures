#include <iostream>
using namespace std;
int abs(int n){
	if(n<0){
		return -n;
	}
	return n;
}
int main(){
	cout<<"Enter tri diagonal matrix dimensions:"<<endl;
	int n,l,m;
	cin>>n;
	int a[n][n];
	cout<<"Enter values for the "<<n<<"x"<<n<<" matrix"<<endl;
	int i,j;
	for(i=0;i<n;i++){
		for(j=i-1;abs(j-i)<=1;j++){
			if(j<0){
				j++;
			}
			if(!(j<n)){
				i++;
				break;
			}
			cout<<"pos="<<i+1<<","<<j+1<<endl;
			cin>>a[i][j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(!(abs(i-j)<=1)){
				a[i][j]=0;
				cout<<a[i][j]<<" ";
			}
			else{
				cout<<a[i][j]<<" ";
			}
			if(j==2){
				cout<<"\n";
			}
		}
	}
	int new_a[n+2*(n-1)];
	int check=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i][j]!=0){
				new_a[check]=a[i][j];
				check++;
			}
		}
	}
	for(i=0;i<check;i++){
		cout<<new_a[i]<<"\t";
	}
	cout<<"\nEnter desired position(i,j):"<<endl;
	cin>>l;
	cin>>m;
	int temp1 = l;
	int temp2 = m;
	int offset = (l-1)*n+(m-1);
	(temp1>2)?(offset-=2):((temp1>1)?(offset-=1):(offset = offset));
	if(l>0 && m>0 && l<=n && m<=n && abs(l-m)<=1){
		cout<<"Value is :"<<a[l-1][m-1]<<endl;
	}
	else if(l>0 && m>0 && l<=n && m<=n){
		cout<<"Value is :"<<0<<endl;
	}
	else{
		cerr<<"Incorrect input";
		return -1;
	}
	return 0;
}
