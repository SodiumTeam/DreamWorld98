#include "AppWindow.h"
#include <stdexcept>
#include <iostream>
#include <windows.h>
#include <shellapi.h>

using namespace std;

void setConsoleColor(WORD c)																					//change Console Text
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
	
void showSettings()
{
	cout << "\nSettings" << endl;
	cout << "Window Mode:  640x 480" << endl;
	cout << "Graphicsmode: Direct X 11" << endl;

}
void openWebPage()
{
	LPCTSTR helpFile = "htdocs\index.html";
	ShellExecute(NULL, "open", helpFile, NULL, NULL, SW_SHOWNORMAL);
}

float coordinate_x, coordinate_y, coordinate_z;																	//Basic Vars
uint32_t width, height;
int t_ticks;
char input;

int main(void)
{
	
	HWND console = GetConsoleWindow();																			//Console Appearence
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 500, 340, TRUE);
	SetConsoleTitle("DREAMENGINE CONSOLE");
	
	
	setConsoleColor(1);																							//Basic Informations and Input possibilities
	cout << "##-------------------------------------------------------------##" << endl;
	setConsoleColor(3);
	cout << "	  DREAMWORLD98 INITIAL ALPHA RELEASE !!! 0.01\n" << endl;

	cout << "\nINFO: DREAMENGINE CONSOLE FOR TESTING PURPOSES; BUILD NUMBER 00002\n" << endl;
	cout << "graphic mode:" << "x" << endl;
	cout << "coordinates: X:" << coordinate_x << "Y:" << coordinate_y << "Z:" << coordinate_z << flush << endl;
	
	setConsoleColor(4);
	cout << "\n[N]ew Game [L]oad Game [S]ettings [O]pen Website [E]xit" << endl;

	

	do {

	userConsoleInput:

		cout << "\ninput:	";
		cin >> input;
		if (input == 'N' || input == 'n') {
			setConsoleColor(5);
			cout << "##-----------------------------LOG-----------------------------##\n" << endl;

			try

			{

				AppWindow app;																						//run the main window

				if (app.init()) {


					while (app.isRun())
					{


						cerr << "##    " << t_ticks << " Ticks since run \r" << flush;								//count the ticks
						t_ticks++;

						app.broadcast();
					}
				}
			}



			catch (const std::runtime_error& error)
			{
				MessageBox(nullptr, error.what(), "An error has occured", MB_OK);
			}

		}
		else if (input == 'S' || input == 's') {
			showSettings();
			goto userConsoleInput;

		}
		else if (input == 'o' || input == 'O') {
			openWebPage();
			goto userConsoleInput;
		}
		else if (input == 'E' || input == 'e') {
			return 0;
		}
		else

			cout << "Wrong Input!" << endl;
			goto userConsoleInput;

	} while (input == 'n' || input == 'N' && input == 's' || input == 'S' && input == 'l' || input == 'L' && input=='o' || input=='O'&& input == 'e' || input == 'E');

	
	
	return 0;
}