//
//  main.cpp
//  school
//
//  Created by Kevin Bolger on 07/02/2018.
//  Copyright © 2018 Kevin Bolger. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class rectangle {
private:

	// Dimensions of rectangle
	int width;
	int height;

	// Alias assignment (informal)
	string name = "unnamed";

public:

	// Setting & Getting name/alias
	void set_name(string str){ name = str; };
	string get_name(){ return name; };

	// Setting & Getting Dimensions
	void set_values(int x, int y){ width = x; height = y; };
	void set_width(int x){ width = x; };
	void set_height(int y){ height = y; };
	int get_width(){ return width; };
	int get_height(){ return height; };

	// Derived Values
	int area(){ return width*height; };
	int perimeter(){ return 2 * width + 2 * height; };
	string type(){ if (width == height) return "square"; else return "rectangle"; };

	// Summarising attributes
	void summary(){ cout << "Name: " << name << "\nSquare or Rectangle: " << type() << "\n\tWidth = " << get_width() << "\n\tHeight = " << get_height() << "\n\tArea = " << area() << "\n\tPerimeter = " << perimeter() << "\n"; };
};

class circle {

	// Dimensions & Constants
	int radius;
	float const pi = 22 / 7;

	// Alias assignment (informal)
	string name = "unnamed";

public:

	// Setting & Getting name/alias
	void set_name(string str){ name = str; };
	string get_name(){ return name; };

	// Derived Values
	float area(){ return pi*pow(radius, 2); };
	float circumference(){ return 2 * pi*radius; };
	void set_radius(int r){ radius = r; };
	int get_diameter(){ return 2 * radius; };
	int get_radius(){ return radius; };

	// Summarising attributes
	void summary(){ cout << "Name: " << name << "\n\tRadius/Diameter = " << get_radius() << "/" << get_diameter() << "\n\tArea = " << area() << "\n\tCircumference = " << circumference() << "\n"; };

};

// Function to determine if user is done with the program.
bool finished(){
	int choice;
tryagain:
	cout << "\nContinue/Exit? Enter 1 to Continue, 0 to exit\n";
	cout << "Choose: ";
	cin >> choice;
	if (choice == 0){ return true; }
	else if (choice == 1){ return false; }
	else {
		cout << "\nSorry, not a valid option.\n";
		goto tryagain;
	}
}

// A custom message to display on program close.
void exitMessage(){
	cout << "\n**************************************************\n\nThank you for using geomPal by Kevin Bolger.\n\tPlease come again soon!\n\n**************************************************\n";
}

int main() {

	/*
	Basically, this program takes the shape classes and using user input, generates summaries of the shape the user chose. Will add support for more shapes over time.
	*/

	// Welcome screen and user directory.
	cout << "Welcome to GeomPal, by Kevin Bolger\n";
	cout << "\nTo get started, choose the shape that you are interested in from the list below by typing the value in to the console and pressing return\n\n";
choose_shape:
	int x, y, r; rectangle rect; circle circ; string name;
	cout << "1 - Rectangle/Square\n";
	cout << "2 - Circle\n\n";
	cout << "Which shape do you want to explore?\n";
	int i;
	cin >> i;
	if (i == 1){ goto choice_rectangle; }
	else if (i == 2){ goto choice_circle; }
	else {
		cout << "\nSorry, not a valid value. Please try again.\n\n";
		goto choose_shape;
	};

	// Actions if Rectangle is chosen
choice_rectangle:
	cout << "\nProvide values for your rectangle.\n";
	cout << "\tWidth: ";
	cin >> x;
	cout << "\tHeight: ";
	cin >> y;
	rect.set_values(x, y);
	cout << "\nGive your rectangle a fun name, for the laugh!";
	cout << "\nName: ";
	// The below code was taken from the following solution on StackOverflow.
	// https://stackoverflow.com/questions/3731529/program-is-skipping-over-getline-without-taking-user-input
	// Further refined and moren information provided about the ignore function here:
	// https://stackoverflow.com/questions/25475384/when-and-why-do-i-need-to-use-cin-ignore-in-c
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, name);
	rect.set_name(name);
	cout << "\n";
	cout << "\nSee a summary of your rectanlge below:\n\n";
	rect.summary();
	if (finished()){ goto end; }
	else{
		cout << "\nOk, we'll bring you back to the start.\n\n";
		goto choose_shape;
	};

	// Actions if circle is chosen
choice_circle:
	cout << "\nProvide radius value for your circle.\n";
	cout << "\tRadius: ";
	cin >> r;
	circ.set_radius(r);
	cout << "\nGive your rectangle a fun name, for the laugh!";
	cout << "\nName: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, name);
	circ.set_name(name);
	cout << "\n";
	cout << "\nSee a summary of your circle below:\n\n";
	circ.summary();
	if (finished()){ goto end; }
	else{
		cout << "\nOk, we'll bring you back to the start.\n\n";
		goto choose_shape;
	};

end:
	// Exit message, for the craic.
	exitMessage();
	return 0;
}
