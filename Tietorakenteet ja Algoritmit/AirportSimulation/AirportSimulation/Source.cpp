/*
Tietorakenteet ja algoritmit -  2. harjoitystyö
Minna Hannula
*/
#include "Random.h"
#include "Runway.h"
#include "Plane.h"
void run_idle(int time)
/*
Post: The specified time is printed with a message that the runway is idle.
*/
{
	cout << time << ": Runway is idle." << endl;
}

void initialize(int &end_time, int &queue_limit,
	double &arrival_rate, double &departure_rate, char &choise)
	/*
	Pre:  The user specifies the number of time units in the simulation,
		  the maximal queue sizes permitted,
		  and the expected arrival and departure rates for the airport.
	Post: The program prints instructions and initializes the parameters
		  end_time, queue_limit, arrival_rate, and departure_rate to
		  the specified values.
	Uses: utility function user_says_yes
	*/

{
	if (choise == '1')
		cout << "This program simulates an airport with only one runway." << endl
		<< "One plane can land or depart in each unit of time." << endl << endl;
	else if (choise == '2')
		cout << "This program simulates an airport with two runways." << endl
		<< "One runway is used for landings and one is used for departures." << endl << endl;
	else if (choise == '3')
		cout << "This program simulates an airport with two runways." << endl
		<< "Runways are used firstly for landings or departures." << endl
		<< "But if another runway is idle for a time unit, plane can either land or departure from the runway." << endl << endl;
	else if(choise == '4')
		cout << "This program simulates an airport with three runways." << endl
		<< "One runway is used for landings, another for departures and third runway is an extra runway." << endl
		<< "Third runway is used when needed." << endl << endl;

	cout << "Up to what number of planes can be waiting to land "
		<< "or take off at any time? " << flush;
	cin >> queue_limit;

	cout << "How many units of time will the simulation run?" << flush;
	cin >> end_time;

	bool acceptable;
	do {
		cout << "Expected number of arrivals per unit time?" << flush;
		cin >> arrival_rate;
		cout << "Expected number of departures per unit time?" << flush;
		cin >> departure_rate;
		if (arrival_rate < 0.0 || departure_rate < 0.0)
			cerr << "These rates must be nonnegative." << endl;
		else
			acceptable = true;

		if (acceptable && arrival_rate + departure_rate > 1.0)
			cerr << "Safety Warning: This airport will become saturated. " << endl;

	} while (!acceptable);
}

void choise1(int &end_time, int &queue_limit,
	double &arrival_rate, double &departure_rate, int &flight_number, Random &variable)     //  Airport simulation program
/*
Pre:  None
Post: The program performs a random simulation of the airport, showing
	  the status of the runway at each time interval, and prints out a
	  summary of airport operation at the conclusion.
Uses: Classes Runway, Plane and functions run_idle
*/
{
	Runway small_airport(queue_limit);
	for (int current_time = 0; current_time < end_time; current_time++) { //  loop over time intervals
		int number_arrivals = variable.poisson(arrival_rate);  //  current arrival requests
		for (int i = 0; i < number_arrivals; i++) {
			Plane current_plane(flight_number++, current_time, arriving);
			if (small_airport.can_land(current_plane) != success)
				current_plane.refuse();
		}

		int number_departures = variable.poisson(departure_rate); //  current departure requests
		for (int j = 0; j < number_departures; j++) {
			Plane current_plane(flight_number++, current_time, departing);
			if (small_airport.can_depart(current_plane) != success)
				current_plane.refuse();
		}

		Plane moving_plane;
		switch (small_airport.activity(current_time, moving_plane)) {
			//  Let at most one Plane onto the Runway at current_time.
		case land:
			moving_plane.land(current_time);
			break;
		case takeOff:
			moving_plane.fly(current_time);
			break;
		case idle:
			run_idle(current_time);
		}
	}
	small_airport.shut_down(end_time);	
}

void choise2(int &end_time, int &queue_limit,
	double &arrival_rate, double &departure_rate, int &flight_number, Random &variable) 
/*
	Pre:  None
	Post : The program performs a random simulation of the airport, showing
	the status of the runway at each time interval, and prints out a
	summary of airport operation at the conclusion.
	Uses : Classes Runway, Plane and functions run_idle
*/
{
	Runway arrivals(queue_limit);
	Runway departures(queue_limit);
	for (int current_time = 0; current_time < end_time; current_time++) { //  loop over time intervals
		int number_arrivals = variable.poisson(arrival_rate);  //  current arrival requests
		for (int i = 0; i < number_arrivals; i++) {
			Plane current_plane(flight_number++, current_time, arriving);
			if (arrivals.can_land(current_plane) != success)
				current_plane.refuse();
		}

		int number_departures = variable.poisson(departure_rate); //  current departure requests
		for (int j = 0; j < number_departures; j++) {
			Plane current_plane(flight_number++, current_time, departing);
			if (departures.can_depart(current_plane) != success)
				current_plane.refuse();
		}

		Plane plane;
		switch (arrivals.activity(current_time, plane)) {
			//  Let at most one Plane onto the Runway at current_time.
		case land:
			plane.land(current_time);
			break;
		case takeOff:
			plane.fly(current_time);
			break;
		case idle:
			run_idle(current_time);
		}

		switch (departures.activity(current_time, plane)) {
			//  Let at most one Plane onto the Runway at current_time.
		case land:
			plane.land(current_time);
			break;
		case takeOff:
			plane.fly(current_time);
			break;
		case idle:
			run_idle(current_time);
		}
	}
	cout << " --- Arrvilas ---" << endl;
	arrivals.shut_down(end_time);
	cout << " --- Departures ---" << endl;
	departures.shut_down(end_time);
}

void choise3(int &end_time, int &queue_limit,
double &arrival_rate, double &departure_rate, int &flight_number, Random &variable) 
/*
	Pre:  None
	Post : The program performs a random simulation of the airport, showing
	the status of the runway at each time interval, and prints out a
	summary of airport operation at the conclusion.
	Uses : Classes Runway, Plane and functions run_idle
*/ 
{
	Runway arrivals(queue_limit);
	Runway departures(queue_limit);
	for (int current_time = 0; current_time < end_time; current_time++) { //  loop over time intervals
		int number_arrivals = variable.poisson(arrival_rate);  //  current arrival requests
		for (int i = 0; i < number_arrivals; i++) {
			Plane current_plane(flight_number++, current_time, arriving);
			if (departures.size_departures() == 0 && departures.size_arrvilas() == 0) //Tarkistetaan onko jonot tyhjät
				departures.can_land(current_plane);
			else if (arrivals.can_land(current_plane) != success)
				if (departures.can_land(current_plane) != success)
					current_plane.refuse();
		}
		int number_departures = variable.poisson(departure_rate); //  current departure requests
		for (int j = 0; j < number_departures; j++) {
			Plane current_plane(flight_number++, current_time, departing);
			if (arrivals.size_departures() == 0 && arrivals.size_arrvilas() == 0)
				arrivals.can_depart(current_plane);
			else if (departures.can_depart(current_plane) != success)
				if(arrivals.can_depart(current_plane) != success)
					current_plane.refuse();
		}
		Plane plane;
		switch (arrivals.activity(current_time, plane)) {
			//  Let at most one Plane onto the Runway at current_time.
		case land:
			plane.land(current_time);
			break;
		case takeOff:
			cout << "Arrivals runway" << endl;
			plane.fly(current_time);
			break;
		case idle:
			cout << "Arrivals runway ";
			run_idle(current_time);
		}
		switch (departures.activity(current_time, plane)) {
			//  Let at most one Plane onto the Runway at current_time.
		case land:
			cout << "Departures runway" << endl;
			plane.land(current_time);
			break;
		case takeOff:
			plane.fly(current_time);
			break;
		case idle:
			cout << "Departures runway. ";
			run_idle(current_time);
		}
	}
	cout << "--- Arrivals ---" << endl;
	arrivals.shut_down(end_time);
	cout << endl << "--- Departures ---" << endl;
	departures.shut_down(end_time);
}

void choise4(int &end_time, int &queue_limit,
	double &arrival_rate, double &departure_rate, int &flight_number, Random &variable) 
/*
	Pre:  None
	Post : The program performs a random simulation of the airport, showing
	the status of the runway at each time interval, and prints out a
	summary of airport operation at the conclusion.
	Uses : Classes Runway, Plane and functions run_idle
*/
{
	Runway arrivals(queue_limit);
	Runway departures(queue_limit);
	Runway leftover(queue_limit);

	for (int current_time = 0; current_time < end_time; current_time++) { //  loop over time intervals
		int number_arrivals = variable.poisson(arrival_rate);  //  current arrival requests
		for (int i = 0; i < number_arrivals; i++) {
			Plane current_plane(flight_number++, current_time, arriving);
			if (arrivals.can_land(current_plane) != success)
				if (leftover.can_land(current_plane) != success)
					current_plane.refuse();
		}
		int number_departures = variable.poisson(departure_rate); //  current departure requests
		for (int j = 0; j < number_departures; j++) {
			Plane current_plane(flight_number++, current_time, departing);
			if (departures.can_depart(current_plane) != success)
				if(leftover.size_arrvilas() == 0) //Tarkistetan, että jonossa ei saapuvia koneita. 
					if (leftover.can_depart(current_plane) != success)
						current_plane.refuse();
		}
		Plane plane;
		switch (arrivals.activity(current_time, plane)) {
			//  Let at most one Plane onto the Runway at current_time.
		case land:
			cout << "Arriwals runway" << endl;
			plane.land(current_time);
			break;
		case takeOff:
			cout << "Arriwals runway" << endl;
			cout << "Nope" << endl;
			break;
		case idle:
			cout << "Arriwals runway ";
			run_idle(current_time);
		}
		switch (departures.activity(current_time, plane)) {
			//  Let at most one Plane onto the Runway at current_time.
		case land:
			cout << "Departures runway" << endl;
			cout << "Nope" << endl;
			break;
		case takeOff:
			cout << "Departures runway" << endl;
			plane.fly(current_time);
			break;
		case idle:
			cout << "Departures runway. ";
			run_idle(current_time);
		}
		switch (leftover.activity(current_time, plane)) {
			//  Let at most one Plane onto the Runway at current_time.
		case land:
			cout << "Leftover runway" << endl;
			plane.land(current_time);
			break;
		case takeOff:
			cout << "Leftover runway" << endl;
			plane.fly(current_time);
			break;
		case idle:
			cout << "Leftover runway. ";
			run_idle(current_time);
		}
	}
	cout << "--- Arrivals ---" << endl;
	arrivals.shut_down(end_time);
	cout << endl << "--- Departures ---" << endl;
	departures.shut_down(end_time);
	cout << endl << "--- Leftover ---" << endl;
	leftover.shut_down(end_time);
}

int main() 
/*
Pre:  The user must supply time intervals the simulation is to
	  run, the expected number of planes arriving, the expected number
	  of planes departing per time interval, and the
	  maximum allowed size for runway queues.
Post: The program prints a user menu and performs a random simulation of the airport by callig choise1, choise1, choise3 or chise4 functions.
Uses: Class Random and functions initialize, choise1, choise1, choise3, chise4
*/
{
	char choise;		     // user choise of the simulation 
	int end_time;            //  time to run simulation
	int queue_limit;         //  size of Runway queues
	int flight_number = 0;
	double arrival_rate, departure_rate;
	Random variable;


	cout << "This program simulates an airport." << endl;
	cout << "You can choose how you would like to simulate the airport." << endl;
	cout << "[1] Use only one runway for departures and landings." << endl;
	cout << "[2] Use two runways, one for landings and one for departures." << endl;
	cout << "[3] Use two runways, mainly for landings or departures." << endl 
		 << "    If runway is idle, it can be used either landings or departures." << endl;
	cout << "[4] Use three runways. Two runways are used mainly for landings and one runways is used for departures." << endl
	     << "    If one of the landing runways is idle, it can be used for departures." << endl;
	cout << "Your choise: ";
	cin >> choise;
	cout << endl;

	initialize(end_time, queue_limit, arrival_rate, departure_rate, choise);


	switch(choise){ 
	case '1': 
		choise1(end_time, queue_limit, arrival_rate, departure_rate, flight_number, variable);
		break;
	
	case '2': 
		choise2(end_time, queue_limit, arrival_rate, departure_rate, flight_number, variable);
		break;
	case '3':
		choise3(end_time, queue_limit, arrival_rate, departure_rate, flight_number, variable);
		break;
	case '4':
		choise4(end_time, queue_limit, arrival_rate, departure_rate, flight_number, variable);
		break;
	}

	system("pause");

}