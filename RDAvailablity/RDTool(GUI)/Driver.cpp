#include"Computer.h"
#include"ComputerTree.h"
#include"MyForm.h"
#include <iostream>
using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
int main(cli::array<String^>^args) 
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	

	//TODO: Replace this with the actual data structure
	ComputerTree<Computer> *testerino = new ComputerTree<Computer>();
	char* header = new char[250];				//Will hold the header
	string computerInfo;			//Will hold each line of the file
	char* computerName = new char[100];			//Holds the Comp name as a cstring
	char* computerIP = new char[100];			//^^ IP
	char* computerMac = new char[100];			//^^ Mac
	char* computerCollege = new char[100];		//^^ College
	int numberOfInfo = 0;						//Keeps track of which information is being read
	int letterIndex = 0;						//Keeps track of where the cin is on computerInfo
	int writeIndex = 0;							//Keeps track of where to write. Resetes after after each coloumn
	bool isDone = false;						//isDone reading the computerLine reset on every line
	string* name = nullptr;
	string* ip = nullptr;
	string* mac = nullptr;
	string* college = nullptr;
	//TODO: Uncomment this when using on the actual thing
	cin.getline(header, 250);

	// Read while its not the end of the file
	while (!cin.eof())
	{
		
		//cin.getline(computerInfo, 55);
		std::getline(std::cin, computerInfo);
		isDone = false;
		//Go through computer until you reach the end
		while (!isDone)
		{
			
			//check to see if the readIndex is a comma or end of line
			if (computerInfo[letterIndex] != ',' && computerInfo[letterIndex] != '\0')
			{
				//If reading the name
				if (numberOfInfo == 0)
				{
					computerName[writeIndex] = computerInfo[letterIndex];
					writeIndex++;
					letterIndex++;
				}
				//If reading the IP
				else if (numberOfInfo == 1)
				{
					computerIP[writeIndex] = computerInfo[letterIndex];
					writeIndex++;
					letterIndex++;
				}
				//Reading the Mac
				else
				{
					computerMac[writeIndex] = computerInfo[letterIndex];
					writeIndex++;
					letterIndex++;
				}
			}
			//If the readIndex is a comma or end of line
			else
			{
				//If done reading the name
				if (numberOfInfo == 0)
				{
					computerName[writeIndex] = '\0';
					writeIndex = 0;
					letterIndex++;
					name = new string(computerName);
					delete[] computerName;
					computerName = new char[100];
					numberOfInfo++;
				}
				//If done reading the IP
				else if (numberOfInfo == 1)
				{
					computerIP[writeIndex] = '\0';
					writeIndex = 0;
					letterIndex++;
					ip = new string(computerIP);
					delete[] computerIP;
					computerIP = new char[100];
					numberOfInfo++;
				}
				//Reading the Mac
				else if (numberOfInfo == 2)
				{
					computerMac[writeIndex] = '\0';
					writeIndex = 0;
					mac = new string(computerMac);
					delete[] computerMac;
					computerMac = new char[100];
					numberOfInfo++;
				}
				else
				{
					computerCollege[writeIndex] = '\0';
					writeIndex = 0;
					college = new string(computerCollege);
					delete[] computerCollege;
					computerCollege = new char[100];
					isDone = true;
					//Creates the computer and adds it to the data structure
					Computer* temp = new Computer((*name), (*ip), (*mac), (*college));
					testerino->insert(temp);
				}
			}
		}
		
		//Resets for the next line
		numberOfInfo = 0;
		letterIndex = 0;
		//Check if eof
		cin.peek();
	}
	RDToolGUI::MyForm form(*testerino);
	Application::Run(%form);
	//testerino->inOrderDisplay();
	return 0;
}