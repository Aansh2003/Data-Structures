#include <iostream>
class Flight{
	public:
		void fuel_detail(float input);
		void information_entry();
		void display_info();
	private:
		int flight_number;
		char destination[100];
		float fuel=13.2,distance;
		void calc_fuel();
		
};
void Flight::fuel_detail(float input){
	fuel = input;
}
void Flight::calc_fuel(){
	if(distance<=1000){
		fuel = 500;
	}
	else if(distance>1000&&distance<=2000){
		fuel = 1100;
	}
	else if(distance>2000){
		fuel = 2200;
	}
	else{
		std::cout<<"Incorrect input";
	}
}
void Flight::information_entry(){
	std::cout<<"Enter flight number,destination,distance"<<std::endl;
	std::cin>>flight_number;
	std::cin>>destination;
	std::cin>>distance;
	calc_fuel();
}
void Flight::display_info(){
	std::cout<<"Flight number: "<<flight_number<<std::endl;
	std::cout<<"Flight destination: "<<destination <<std::endl;
	std::cout<<"Flight distance:"<<distance <<std::endl;
	std::cout<<"Flight fuel: "<<fuel <<std::endl;
}

int main(){
	Flight fl;
	fl.information_entry();
	fl.display_info();
	return 0;
}
