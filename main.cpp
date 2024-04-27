#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <fstream>
#include "glut.h"

struct Pac_Man {
	std::pair<double, double> position = { 14., 7.5 };
	std::pair<int, int> position_in_array = { 14, 7. };
	std::string direction;
	double speed = 0.001;
};

struct Red_Ghost {
	std::pair<double, double> position = { 14., 19.5 };
	std::string direction;
	double speed = 0.0001;
};

struct Blue_Ghost {
	std::pair<double, double> position = { 12., 16.5 };
	std::string direction;
	double speed = 0.0001;
};

struct Pink_Ghost {
	std::pair<double, double> position = { 14., 16.5 };
	std::string direction;
	double speed = 0.0001;
};

struct Orange_Ghost {
	std::pair<double, double> position = { 16., 16.5 };
	std::string direction;
	double speed = 0.0001;
};

//Global variables
bool Game_Over = false;
int Count_Of_HP = 3;
int Count_Of_cookies = 244;
int Count_of_Points = 0;
int Level = 1;
int Count_of_Clicks = 0;
double Move = 0.;

std::vector<std::vector<int>> Map(32, std::vector<int>(28));

//Entity
Pac_Man PacMan;
Red_Ghost RedGhost;
Blue_Ghost BlueGhost;
Pink_Ghost PinkGhost;
Orange_Ghost OrangeGhost;


void ReNew_PacMan_Position() {
	if (PacMan.direction == "Right") {
		if ((Map[PacMan.position_in_array.second][PacMan.position_in_array.first + 1] == 1) && (int(PacMan.position.first * 10. - (double)PacMan.position_in_array.first * 10) == 5))
			return;
		else if ((Map[PacMan.position_in_array.second][PacMan.position_in_array.first + 1] == 1) && (int(PacMan.position.first * 10. - (double)PacMan.position_in_array.first * 10) == 5)) {
			PacMan.position.first += 0.1;
			return;
		}
		else {
			PacMan.position.first += 0.1;
			//std::cout << Map[PacMan.position_in_array.second][PacMan.position_in_array.first + 1] << "\n\n";
			if (int(PacMan.position.first * 10) % 10 == 5) PacMan.position_in_array.first += 1;
		}

		/*if (Map[PacMan.position_in_array.second][PacMan.position_in_array.first + 1] == 1) return;
		else {
			PacMan.position.first += 1;
			PacMan.position_in_array.first += 1;
		}*/
		std::cout << PacMan.position_in_array.first << ' ' << PacMan.position_in_array.second << '\n';
	}
	else if (PacMan.direction == "Left") {
		if ((Map[PacMan.position_in_array.second][PacMan.position_in_array.first - 1] == 1) && (int(PacMan.position.first * 10. - (double)PacMan.position_in_array.first * 10) == 5))
			return;
		else if ((Map[PacMan.position_in_array.second][PacMan.position_in_array.first - 1] == 1) && (int(PacMan.position.first * 10. - (double)PacMan.position_in_array.first * 10) == 5)) {
			PacMan.position.first -= 0.1;
			return;
		}
		else {
			PacMan.position.first -= 0.1;
			//std::cout << Map[PacMan.position_in_array.second][PacMan.position_in_array.first + 1] << "\n\n";
			if (int(PacMan.position.first * 10) % 10 == 5) PacMan.position_in_array.first -= 1;
		}

		/*if (Map[PacMan.position_in_array.second][PacMan.position_in_array.first - 1] == 1) return;
		else {
			PacMan.position.first -= 1;
			PacMan.position_in_array.first -= 1;
		}*/
		std::cout << PacMan.position_in_array.first << ' ' << PacMan.position_in_array.second << '\n';
	}
	else if (PacMan.direction == "Up") {
		if ((Map[PacMan.position_in_array.second + 1][PacMan.position_in_array.first] == 1) && (int(PacMan.position.second * 10. - (double)PacMan.position_in_array.second * 10) == 5))
			return;
		else if ((Map[PacMan.position_in_array.second + 1][PacMan.position_in_array.first] == 1) && (int(PacMan.position.second * 10. - (double)PacMan.position_in_array.second * 10) == 5)) {
			PacMan.position.second += 0.1;
			return;
		}
		else {
			PacMan.position.second += 0.1;
			//std::cout << Map[PacMan.position_in_array.second][PacMan.position_in_array.first + 1] << "\n\n";
			if (int(PacMan.position.second * 10) % 10 == 5) PacMan.position_in_array.second += 1;
		}
		/*if (Map[PacMan.position_in_array.second + 1][PacMan.position_in_array.first] == 1) return;
		else {
			PacMan.position.second += 1;
			PacMan.position_in_array.second += 1;
		}*/
		std::cout << PacMan.position_in_array.first << ' ' << PacMan.position_in_array.second << '\n';
	}
	else if (PacMan.direction == "Down") {
		if ((Map[PacMan.position_in_array.second - 1][PacMan.position_in_array.first] == 1) && (int(PacMan.position.second * 10. - (double)PacMan.position_in_array.second * 10) == 5))
			return;
		else if ((Map[PacMan.position_in_array.second - 1][PacMan.position_in_array.first] == 1) && (int(PacMan.position.second * 10. - (double)PacMan.position_in_array.second * 10) == 5)) {
			PacMan.position.second -= 0.1;
			return;
		}
		else {
			PacMan.position.second -= 0.1;
			//std::cout << Map[PacMan.position_in_array.second][PacMan.position_in_array.first + 1] << "\n\n";
			if (int(PacMan.position.second * 10) % 10 == 5) PacMan.position_in_array.second -= 1;
		}
		/*if (Map[PacMan.position_in_array.second - 1][PacMan.position_in_array.first] == 1) return;
		else {
			PacMan.position.second -= 1;
			PacMan.position_in_array.second -= 1;
		}*/
		std::cout << PacMan.position_in_array.first << ' ' << PacMan.position_in_array.second << '\n';
	}
}


void Keyboard(unsigned char key, int x, int y) {
	++Count_of_Clicks;
	if (key == 'w' || key == 'W' || key == 'ц' || key == 'Ц') {
		PacMan.direction = "Up";
	}
	else if (key == 's' || key == 'S' || key == 'ы' || key == 'Ы') {
		PacMan.direction = "Down";
	}
	else if (key == 'd' || key == 'D' || key == 'в' || key == 'В') {
		if (Count_of_Clicks == 1) {
			PacMan.position.first += 0.5;
			PacMan.position_in_array.first = 14;
		}
		PacMan.direction = "Right";
	}
	else if (key == 'a' || key == 'A' || key == 'ф' || key == 'Ф') {
		if (Count_of_Clicks == 1) {
			PacMan.position.first -= 0.5;
			PacMan.position_in_array.first = 13;
		}
		PacMan.direction = "Left";
	}
}


void Draw_Whalls() {
	{
		glLineWidth(3);
		glColor3ub(0, 0, 255);
		glBegin(GL_LINES);
		//Внешняя линия
		{
			glVertex2d(0.5, 0.5);
			glVertex2d(0.5, 5.5);

			glVertex2d(0.5, 5.5);
			glVertex2d(2.5, 5.5);

			glVertex2d(2.5, 5.5);
			glVertex2d(2.5, 6.5);

			glVertex2d(2.5, 6.5);
			glVertex2d(0.5, 6.5);

			glVertex2d(0.5, 6.5);
			glVertex2d(0.5, 11.5);

			glVertex2d(0.5, 11.5);
			glVertex2d(5.5, 11.5);

			glVertex2d(5.5, 11.5);
			glVertex2d(5.5, 15.5);

			glVertex2d(5.5, 15.5);
			glVertex2d(0., 15.5);

			glVertex2d(0., 17.5);
			glVertex2d(5.5, 17.5);

			glVertex2d(5.5, 17.5);
			glVertex2d(5.5, 21.5);

			glVertex2d(5.5, 21.5);
			glVertex2d(0.5, 21.5);

			glVertex2d(0.5, 21.5);
			glVertex2d(0.5, 30.5);

			glVertex2d(0.5, 30.5);
			glVertex2d(13.5, 30.5);

			glVertex2d(13.5, 30.5);
			glVertex2d(13.5, 26.5);

			glVertex2d(13.5, 26.5);
			glVertex2d(14.5, 26.5);

			glVertex2d(14.5, 26.5);
			glVertex2d(14.5, 30.5);

			glVertex2d(14.5, 30.5);
			glVertex2d(27.5, 30.5);

			glVertex2d(27.5, 30.5);
			glVertex2d(27.5, 21.5);

			glVertex2d(27.5, 21.5);
			glVertex2d(22.5, 21.5);

			glVertex2d(22.5, 21.5);
			glVertex2d(22.5, 17.5);

			glVertex2d(22.5, 17.5);
			glVertex2d(28, 17.5);

			glVertex2d(28, 15.5);
			glVertex2d(22.5, 15.5);

			glVertex2d(22.5, 15.5);
			glVertex2d(22.5, 11.5);

			glVertex2d(22.5, 11.5);
			glVertex2d(27.5, 11.5);

			glVertex2d(27.5, 11.5);
			glVertex2d(27.5, 6.5);

			glVertex2d(27.5, 6.5);
			glVertex2d(25.5, 6.5);

			glVertex2d(25.5, 6.5);
			glVertex2d(25.5, 5.5);

			glVertex2d(25.5, 5.5);
			glVertex2d(27.5, 5.5);

			glVertex2d(27.5, 5.5);
			glVertex2d(27.5, 0.5);

			glVertex2d(27.5, 0.5);
			glVertex2d(0.5, 0.5);
		}
		//Нижняя часть 
		{
			//Big Left
			{
				glVertex2d(2.5, 2.5);
				glVertex2d(11.5, 2.5);

				glVertex2d(11.5, 2.5);
				glVertex2d(11.5, 3.5);

				glVertex2d(11.5, 3.5);
				glVertex2d(8.5, 3.5);

				glVertex2d(8.5, 3.5);
				glVertex2d(8.5, 6.5);

				glVertex2d(8.5, 6.5);
				glVertex2d(7.5, 6.5);

				glVertex2d(7.5, 6.5);
				glVertex2d(7.5, 3.5);

				glVertex2d(7.5, 3.5);
				glVertex2d(2.5, 3.5);

				glVertex2d(2.5, 3.5);
				glVertex2d(2.5, 2.5);
			}

			//Mid Down
			{
				glVertex2d(13.5, 2.5);
				glVertex2d(14.5, 2.5);

				glVertex2d(14.5, 2.5);
				glVertex2d(14.5, 5.5);

				glVertex2d(14.5, 5.5);
				glVertex2d(17.5, 5.5);

				glVertex2d(17.5, 5.5);
				glVertex2d(17.5, 6.5);

				glVertex2d(17.5, 6.5);
				glVertex2d(10.5, 6.5);

				glVertex2d(10.5, 6.5);
				glVertex2d(10.5, 5.5);

				glVertex2d(10.5, 5.5);
				glVertex2d(13.5, 5.5);

				glVertex2d(13.5, 5.5);
				glVertex2d(13.5, 2.5);
			}

			//Mid Top
			{
				glVertex2d(10.5, 11.5);
				glVertex2d(13.5, 11.5);

				glVertex2d(13.5, 11.5);
				glVertex2d(13.5, 8.5);

				glVertex2d(13.5, 8.5);
				glVertex2d(14.5, 8.5);

				glVertex2d(14.5, 8.5);
				glVertex2d(14.5, 11.5);

				glVertex2d(14.5, 11.5);
				glVertex2d(17.5, 11.5);

				glVertex2d(17.5, 11.5);
				glVertex2d(17.5, 12.5);

				glVertex2d(17.5, 12.5);
				glVertex2d(10.5, 12.5);

				glVertex2d(10.5, 12.5);
				glVertex2d(10.5, 11.5);
			}

			//Big Right
			{
				glVertex2d(16.5, 2.5);
				glVertex2d(25.5, 2.5);

				glVertex2d(25.5, 2.5);
				glVertex2d(25.5, 3.5);

				glVertex2d(25.5, 3.5);
				glVertex2d(20.5, 3.5);

				glVertex2d(20.5, 3.5);
				glVertex2d(20.5, 6.5);

				glVertex2d(20.5, 6.5);
				glVertex2d(19.5, 6.5);

				glVertex2d(19.5, 6.5);
				glVertex2d(19.5, 3.5);

				glVertex2d(19.5, 3.5);
				glVertex2d(16.5, 3.5);

				glVertex2d(16.5, 3.5);
				glVertex2d(16.5, 2.5);
			}

			//Small Lef
			{
				glVertex2d(4.5, 5.5);
				glVertex2d(5.5, 5.5);

				glVertex2d(5.5, 5.5);
				glVertex2d(5.5, 9.5);

				glVertex2d(5.5, 9.5);
				glVertex2d(2.5, 9.5);

				glVertex2d(2.5, 9.5);
				glVertex2d(2.5, 8.5);

				glVertex2d(2.5, 8.5);
				glVertex2d(4.5, 8.5);

				glVertex2d(4.5, 8.5);
				glVertex2d(4.5, 5.5);

				//
				glVertex2d(7.5, 8.5);
				glVertex2d(11.5, 8.5);

				glVertex2d(11.5, 8.5);
				glVertex2d(11.5, 9.5);

				glVertex2d(11.5, 9.5);
				glVertex2d(7.5, 9.5);

				glVertex2d(7.5, 9.5);
				glVertex2d(7.5, 8.5);
			}

			//Small Right
			{
				glVertex2d(16.5, 8.5);
				glVertex2d(20.5, 8.5);

				glVertex2d(20.5, 8.5);
				glVertex2d(20.5, 9.5);

				glVertex2d(20.5, 9.5);
				glVertex2d(16.5, 9.5);

				glVertex2d(16.5, 9.5);
				glVertex2d(16.5, 8.5);
				////

				glVertex2d(22.5, 5.5);
				glVertex2d(23.5, 5.5);

				glVertex2d(23.5, 5.5);
				glVertex2d(23.5, 8.5);

				glVertex2d(23.5, 8.5);
				glVertex2d(25.5, 8.5);

				glVertex2d(25.5, 8.5);
				glVertex2d(25.5, 9.5);

				glVertex2d(25.5, 9.5);
				glVertex2d(22.5, 9.5);

				glVertex2d(22.5, 9.5);
				glVertex2d(22.5, 5.5);
			}
		}
		//Середина
		{
			glVertex2d(10.5, 14.5);
			glVertex2d(17.5, 14.5);

			glVertex2d(17.5, 14.5);
			glVertex2d(17.5, 18.5);

			glVertex2d(17.5, 18.5);
			glVertex2d(15, 18.5);

			glVertex2d(13, 18.5);
			glVertex2d(10.5, 18.5);

			glVertex2d(10.5, 18.5);
			glVertex2d(10.5, 14.5);

			////
			glVertex2d(7.5, 11.5);
			glVertex2d(8.5, 11.5);

			glVertex2d(8.5, 11.5);
			glVertex2d(8.5, 15.5);

			glVertex2d(8.5, 15.5);
			glVertex2d(7.5, 15.5);

			glVertex2d(7.5, 15.5);
			glVertex2d(7.5, 11.5);

			////
			glVertex2d(19.5, 11.5);
			glVertex2d(20.5, 11.5);

			glVertex2d(20.5, 11.5);
			glVertex2d(20.5, 15.5);

			glVertex2d(20.5, 15.5);
			glVertex2d(19.5, 15.5);

			glVertex2d(19.5, 15.5);
			glVertex2d(19.5, 11.5);

			////
			glVertex2d(7.5, 17.5);
			glVertex2d(8.5, 17.5);

			glVertex2d(8.5, 17.5);
			glVertex2d(8.5, 20.5);

			glVertex2d(8.5, 20.5);
			glVertex2d(11.5, 20.5);

			glVertex2d(11.5, 20.5);
			glVertex2d(11.5, 21.5);

			glVertex2d(11.5, 21.5);
			glVertex2d(8.5, 21.5);

			glVertex2d(8.5, 21.5);
			glVertex2d(8.5, 24.5);

			glVertex2d(8.5, 24.5);
			glVertex2d(7.5, 24.5);

			glVertex2d(7.5, 24.5);
			glVertex2d(7.5, 17.5);

			////
			glVertex2d(16.5, 20.5);
			glVertex2d(19.5, 20.5);

			glVertex2d(19.5, 20.5);
			glVertex2d(19.5, 17.5);

			glVertex2d(19.5, 17.5);
			glVertex2d(20.5, 17.5);

			glVertex2d(20.5, 17.5);
			glVertex2d(20.5, 24.5);

			glVertex2d(20.5, 24.5);
			glVertex2d(19.5, 24.5);

			glVertex2d(19.5, 24.5);
			glVertex2d(19.5, 21.5);

			glVertex2d(19.5, 21.5);
			glVertex2d(16.5, 21.5);

			glVertex2d(16.5, 21.5);
			glVertex2d(16.5, 20.5);
		}
		//Верхняя часть
		{
			//Left
			{
				glVertex2d(2.5, 23.5);
				glVertex2d(5.5, 23.5);

				glVertex2d(5.5, 23.5);
				glVertex2d(5.5, 24.5);

				glVertex2d(5.5, 24.5);
				glVertex2d(2.5, 24.5);

				glVertex2d(2.5, 24.5);
				glVertex2d(2.5, 23.5);

				////
				glVertex2d(2.5, 26.5);
				glVertex2d(5.5, 26.5);

				glVertex2d(5.5, 26.5);
				glVertex2d(5.5, 28.5);

				glVertex2d(5.5, 28.5);
				glVertex2d(2.5, 28.5);

				glVertex2d(2.5, 28.5);
				glVertex2d(2.5, 26.5);

				////
				glVertex2d(7.5, 26.5);
				glVertex2d(11.5, 26.5);

				glVertex2d(11.5, 26.5);
				glVertex2d(11.5, 28.5);

				glVertex2d(11.5, 28.5);
				glVertex2d(7.5, 28.5);

				glVertex2d(7.5, 28.5);
				glVertex2d(7.5, 26.5);
			}
			//Mid
			{
				glVertex2d(10.5, 24.5);
				glVertex2d(17.5, 24.5);

				glVertex2d(17.5, 24.5);
				glVertex2d(17.5, 23.5);

				glVertex2d(17.5, 23.5);
				glVertex2d(14.5, 23.5);

				glVertex2d(14.5, 23.5);
				glVertex2d(14.5, 20.5);

				glVertex2d(14.5, 20.5);
				glVertex2d(13.5, 20.5);

				glVertex2d(13.5, 20.5);
				glVertex2d(13.5, 23.5);

				glVertex2d(13.5, 23.5);
				glVertex2d(10.5, 23.5);

				glVertex2d(10.5, 23.5);
				glVertex2d(10.5, 24.5);
			}
			//Right
			{
				glVertex2d(20.5, 26.5);
				glVertex2d(20.5, 28.5);

				glVertex2d(20.5, 28.5);
				glVertex2d(16.5, 28.5);

				glVertex2d(16.5, 28.5);
				glVertex2d(16.5, 26.5);

				glVertex2d(16.5, 26.5);
				glVertex2d(20.5, 26.5);

				////
				glVertex2d(22.5, 26.5);
				glVertex2d(25.5, 26.5);

				glVertex2d(25.5, 26.5);
				glVertex2d(25.5, 28.5);

				glVertex2d(25.5, 28.5);
				glVertex2d(22.5, 28.5);

				glVertex2d(22.5, 28.5);
				glVertex2d(22.5, 26.5);

				////
				glVertex2d(22.5, 23.5);
				glVertex2d(25.5, 23.5);

				glVertex2d(25.5, 23.5);
				glVertex2d(25.5, 24.5);

				glVertex2d(25.5, 24.5);
				glVertex2d(22.5, 24.5);

				glVertex2d(22.5, 24.5);
				glVertex2d(22.5, 23.5);
			}
		}

		//Ворота к приведениям
		/*glColor3ub(200, 0, 0);
		glVertex2d(13, 18.5);
		glVertex2d(15, 18.5);*/
		glEnd();
	}
}
void Draw_PacMan() {
	ReNew_PacMan_Position();

	if (Map[PacMan.position_in_array.second][PacMan.position_in_array.first] == 2) {
		Map[PacMan.position_in_array.second][PacMan.position_in_array.first] = 0;
		Count_of_Points += 10;
	}

	double ForDraw;
	glColor3ub(255, 255, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; ++i) {
		ForDraw = i * acos(-1) / 180;
		glVertex2d(PacMan.position.first + 0.7 * cos(ForDraw), PacMan.position.second + 0.7 * sin(ForDraw));
	}
	glEnd();
}
void Draw_Coords() {
	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2d(27., 0);
	glVertex2d(27., 32);

	glVertex2d(26., 0);
	glVertex2d(26., 32);

	glVertex2d(25., 0);
	glVertex2d(25., 32);

	glVertex2d(24., 0);
	glVertex2d(24., 32);

	glVertex2d(23., 0);
	glVertex2d(23., 32);

	glVertex2d(22., 0);
	glVertex2d(22., 32);

	glVertex2d(21., 0);
	glVertex2d(21., 32);

	glVertex2d(20., 0);
	glVertex2d(20., 32);

	glVertex2d(19., 0);
	glVertex2d(19., 32);

	glVertex2d(18., 0);
	glVertex2d(18., 32);

	glVertex2d(17., 0);
	glVertex2d(17., 32);

	glVertex2d(16., 0);
	glVertex2d(16., 32);

	glVertex2d(15., 0);
	glVertex2d(15., 32);

	glVertex2d(14., 0);
	glVertex2d(14., 32);

	glVertex2d(13., 0);
	glVertex2d(13., 32);

	glVertex2d(12., 0);
	glVertex2d(12., 32);

	glVertex2d(11., 0);
	glVertex2d(11., 32);

	glVertex2d(10., 0);
	glVertex2d(10., 32);

	glVertex2d(9., 0);
	glVertex2d(9., 32);

	glVertex2d(8., 0);
	glVertex2d(8., 32);

	glVertex2d(7., 0);
	glVertex2d(7., 32);

	glVertex2d(6., 0);
	glVertex2d(6., 32);

	glVertex2d(5., 0);
	glVertex2d(5., 32);

	glVertex2d(4., 0);
	glVertex2d(4., 32);

	glVertex2d(3., 0);
	glVertex2d(3., 32);

	glVertex2d(2., 0);
	glVertex2d(2., 32);

	glVertex2d(1., 0);
	glVertex2d(1., 32);

	glVertex2d(0., 0);
	glVertex2d(0., 32);



	glVertex2d(0., 31);
	glVertex2d(28., 31);

	glVertex2d(0., 30);
	glVertex2d(28., 30);

	glVertex2d(0., 29);
	glVertex2d(28., 29);

	glVertex2d(0., 28);
	glVertex2d(28., 28);

	glVertex2d(0., 27);
	glVertex2d(28., 27);

	glVertex2d(0., 26);
	glVertex2d(28., 26);

	glVertex2d(0., 25);
	glVertex2d(28., 25);

	glVertex2d(0., 24);
	glVertex2d(28., 24);

	glVertex2d(0., 23);
	glVertex2d(28., 23);

	glVertex2d(0., 22);
	glVertex2d(28., 22);

	glVertex2d(0., 21);
	glVertex2d(28., 21);

	glVertex2d(0., 20);
	glVertex2d(28., 20);

	glVertex2d(0., 19);
	glVertex2d(28., 19);

	glVertex2d(0., 18);
	glVertex2d(28., 18);

	glVertex2d(0., 17);
	glVertex2d(28., 17);

	glVertex2d(0., 16);
	glVertex2d(28., 16);

	glVertex2d(0., 15);
	glVertex2d(28., 15);

	glVertex2d(0., 14);
	glVertex2d(28., 14);

	glVertex2d(0., 13);
	glVertex2d(28., 13);

	glVertex2d(0., 12);
	glVertex2d(28., 12);

	glVertex2d(0., 11);
	glVertex2d(28., 11);

	glVertex2d(0., 10);
	glVertex2d(28., 10);

	glVertex2d(0., 9);
	glVertex2d(28., 9);

	glVertex2d(0., 8);
	glVertex2d(28., 8);

	glVertex2d(0., 7);
	glVertex2d(28., 7);

	glVertex2d(0., 6);
	glVertex2d(28., 6);

	glVertex2d(0., 5);
	glVertex2d(28., 5);

	glVertex2d(0., 4);
	glVertex2d(28., 4);

	glVertex2d(0., 3);
	glVertex2d(28., 3);

	glVertex2d(0., 2);
	glVertex2d(28., 2);

	glVertex2d(0., 1);
	glVertex2d(28., 1);
	glEnd();
}
void Draw_Cooks() {
	glColor3ub(255, 100, 0);
	double ForDraw;
	for (int j = 0; j < 32; ++j) {
		for (int k = 0; k < 28; ++k) {
			if (Map[j][k] == 2) {
				glBegin(GL_POLYGON);
				for (int i = 0; i < 360; ++i) {
					ForDraw = i * acos(-1) / 180;
					glVertex2d((k + 0.5) + 0.2 * cos(ForDraw), (j + 0.5) + 0.2 * sin(ForDraw));
				}
				glEnd();
			}
		}
	}
}
void Draw_Enerjazer() {
	glColor3ub(255, 255, 255);
	if (Map[7][1] == 3) {
		double ForDraw;
		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; ++i) {
			ForDraw = i * acos(-1) / 180;
			glVertex2d((1 + 0.5) + 0.3 * cos(ForDraw), (7 + 0.5) + 0.3 * sin(ForDraw));
		}
		glEnd();
	}
	if (Map[7][26] == 3) {
		double ForDraw;
		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; ++i) {
			ForDraw = i * acos(-1) / 180;
			glVertex2d((26 + 0.5) + 0.3 * cos(ForDraw), (7 + 0.5) + 0.3 * sin(ForDraw));
		}
		glEnd();
	}
	if (Map[27][1] == 3) {
		double ForDraw;
		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; ++i) {
			ForDraw = i * acos(-1) / 180;
			glVertex2d((1 + 0.5) + 0.3 * cos(ForDraw), (27 + 0.5) + 0.3 * sin(ForDraw));
		}
		glEnd();
	}
	if (Map[27][26] == 3) {
		double ForDraw;
		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; ++i) {
			ForDraw = i * acos(-1) / 180;
			glVertex2d((26 + 0.5) + 0.3 * cos(ForDraw), (27 + 0.5) + 0.3 * sin(ForDraw));
		}
		glEnd();
	}
}

void Display(void) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.f, 28.f, 0.f, 32.f, 0.f, 1.f);
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Draw_Whalls();
	Draw_PacMan();
	Draw_Cooks();
	Draw_Enerjazer();

	//Отрисовка Красного
	//Отрисовка Голубого
	//Отрисовка Розового
	//Отрисовка Оранжевого

	//Draw_Coords();

	if (!Game_Over) glutPostRedisplay();

	glutSwapBuffers();
}

void Make_Map() {
	std::ifstream fin("Map.txt");

	std::string str_map;
	fin >> str_map;
	int Indx_in_str_map = 0;
	for (int i = 31; i >= 0; --i) {
		for (int j = 0; j < 28; ++j) {
			Map[i][j] = str_map[Indx_in_str_map] - 48;
			++Indx_in_str_map;
		}
	}
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	Make_Map();

	/*for (int i = 0; i < 32; ++i) {
		for (int j = 0; j < 28; ++j) {
			std::cout << Map[i][j] << ' ';
		}
		std::cout << '\n';
	}*/

	//Инициализация
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(150, 10);
	glutInitWindowSize(784, 896);
	glutCreateWindow("Window");

	glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);


	// Основной цикл GLUT
	glutMainLoop();
}