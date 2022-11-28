#include <iostream>
class Employee{
	public:
		Employee();
	private:
		void data_read();
		void calc_net_sal();
		void calc_gross_sal();
		void display();
		int Employee_Number;
		char Employee_name[200];
		double da,it;
		double da_var,it_var,Net_Salary,Gross_Salary,basic;
		
};
Employee::Employee(){
	data_read();
	calc_gross_sal();
	calc_net_sal();
	display();
}
void Employee::data_read(){
	std::cout<<"Enter employee number , employee name and basic salary"<<std::endl;
	std::cin>>Employee_Number;
	std::cin>>Employee_name;
	std::cin>>basic;
	da = basic*12/100;
}
void Employee::calc_gross_sal(){
	Gross_Salary = basic+da;
	it = Gross_Salary *18/100;
}
void Employee::calc_net_sal(){
	Net_Salary = Gross_Salary - it;
}

void Employee::display(){
	std::cout<<"Gross salary:"<<Gross_Salary<<std::endl;
	std::cout<<"Net salary:"<<Net_Salary<<std::endl;
}
int main(){
	int N,i;
	std::cout<<"Enter number of employees"<<std::endl;
	std::cin>>N;
	for(i=0;i<=N;i++){
		Employee emp[i];
	}
	return 0;
}

