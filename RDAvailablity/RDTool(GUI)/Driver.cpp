#include"Computer.h"
#include"ComputerTree.h"
#include <iostream>
#include <list>
#include <fstream>
#include <iomanip>
#include"MainWindow.h"
using namespace std;
using namespace System;
using namespace System::Windows::Forms;



int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//TODO: Replace this with the actual data structure
	ComputerTree<Computer> *testerino = new ComputerTree<Computer>();
	char* header = new char[250];				//Will hold the header
	string computerInfo;						//Will hold each line of the file
	string inputFileName;						//Will hold the name of the file
	char* computerName = new char[100];			//Holds the Comp name as a cstring
	char* computerIP = new char[100];			//^^ IP
	char* computerMac = new char[100];			//^^ Mac
	int numberOfInfo = 0;						//Keeps track of which information is being read
	int letterIndex = 0;						//Keeps track of where the cin is on computerInfo
	int writeIndex = 0;							//Keeps track of where to write. Resetes after after each coloumn
	bool isDone = false;						//isDone reading the computerLine reset on every line
	string* name = nullptr;
	string* ip = nullptr;
	string* mac = nullptr;


	//TODO: Uncomment this when using on the actual thing
	//cin.getline(header, 250);

	//Set the name for the input file name
	inputFileName = "SP18 Computer List.csv";

	//Create input file object
	fstream inputFile(inputFileName);

	std::getline(inputFile, computerInfo);

	//Open the file and pull information
	if (inputFile.is_open())
	{

		// Read while its not the end of the file
		while (!inputFile.eof())
		{

			//cin.getline(computerInfo, 55);
			std::getline(inputFile, computerInfo);

			/* This part of the program will take the line aquired from the CSV file (computer info)
			* and split it accordingly to extract the comptuer name, ip address, and mac. */

			//To extract the computer name we start create a substring starting at index 0 an going all the way to the first comma
			string computerName = computerInfo.substr(0, computerInfo.find(",", 0));

			//To extract the ip address we start in the fist comma and add one to move the index off the comma
			//then the length of the substring will be dictated by the length of charactares in-between the first and second comma
			string ipAddress = computerInfo.substr(computerInfo.find(",", 0) + 1, computerInfo.find(",", 17) - (computerInfo.find(",", 0) + 1));

			//Finally, the mac address will start at the index after the second comma, and will be of length 17
			string macAddress = computerInfo.substr(computerInfo.find(",", 17) + 1, 17);

			size_t found = computerInfo.find_last_of(',');
			string college = computerInfo.substr(found + 1, computerInfo.length());

			//Here we create the computer objects and parse the information for the constructor
			//Once the objec is in place, we add it to the tree
			Computer* temp = new Computer((computerName), (ipAddress), (macAddress), (college));
			testerino->insert(temp);
			inputFile.peek();
			
		}
	}
	else
	{
		std::cout << "File is not available" << endl;
	}

	//Displays tree
	cout << "************************************************************" << endl;
	//testerino->inOrderDisplay();

	//This will let you see whats going on
	//system("PAUSE");
	RDToolGUI::MainWindow form(testerino);
	Application::Run(%form);
	return 0;
}