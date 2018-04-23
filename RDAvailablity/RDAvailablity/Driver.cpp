#include"Computer.h"
#include"ComputerTree.h"
#include<list>



int main()
{
	//TODO: Replace this with the actual data structure
	list<Computer>* comps = new list<Computer>();
	char* header = new char[250];				//Will hold the header
	char* computerInfo = new char[55];			//Will hold each line of the file
	char* computerName = new char[20];			//Holds the Comp name as a cstring
	char* computerIP = new char[15];			//^^ IP
	char* computerMac = new char[17];			//^^ Mac
	int numberOfInfo = 0;						//Keeps track of which information is being read
	int letterIndex = 0;						//Keeps track of where the cin is on computerInfo
	int writeIndex = 0;							//Keeps track of where to write. Resetes after after each coloumn
	bool isDone = false;						//isDone reading the computerLine reset on every line
	string* name = nullptr;
	string* ip = nullptr;;
	string* mac = nullptr;;
	//TODO: Uncomment this when using on the actual thing
	//cin.getline(header, 250);

	// Read while its not the end of the file
	while (!cin.eof())
	{
		cin.getline(computerInfo, 55); 
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
					computerName = new char[20];
					numberOfInfo++;
				}
				//If done reading the IP
				else if (numberOfInfo == 1)
				{
					computerIP[writeIndex] = '\0';
					writeIndex = 0;
					letterIndex++;
					ip = new string(computerIP);
					computerIP = new char[15];
					numberOfInfo++;
				}
				//Reading the Mac
				else
				{
					computerMac[writeIndex] = '\0';
					writeIndex = 0;
					mac = new string(computerMac);
					computerMac = new char[17];
					isDone = true;
					//Not sure why but this fixes it lol
					cin.peek();
					//Creates the computer and adds it to the data structure
					Computer* temp = new Computer((*name), (*ip), (*mac));
					(*comps).push_back(*temp);
					
				}
			}
		}
		
		//Resets for the next line
		computerInfo = new char[55];
		numberOfInfo = 0;
		letterIndex = 0;
	}

	/*cout << "\n\nNow Starting remoteviewer..." << endl;
	list<Computer>::iterator it = (*comps).begin();
	cout<< "This is the computer to view " << (*it).getName() << endl;
	(*it).labView();*/
	ComputerTree<Computer> *testerino = new ComputerTree<Computer>();

	for (list<Computer>::iterator it = (*comps).begin(); it != (*comps).end(); it++)
	{
		testerino->insert(&(*it));
	}

	//cout<< (*testerino) << endl;
	cout << "*****************************Checking Statuses*************************************" << endl;
	
	(*testerino).zig();
	testerino->checkStatus();
	cout << "Inorder display" << endl;
	(*testerino).inOrderDisplay();
	cout << "Preorder display" << endl;
	(*testerino).preOrderDisplay();
	cout << "**************************Find**************************" << endl;
	Computer* foonerino = new Computer("LS-OA-01", "10.194.196.45", "18-66-DA-23B097");

	(*testerino).find(foonerino);
	

	



	return 0;
}