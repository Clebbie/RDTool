#include "MainWindow.h"
#include<string>
using namespace System;

void RDTool::MainWindow::populateViewTree(ComputerTree<Computer>* tree, System::Windows::Forms::TreeView ^ view)
{
	string currentCollege = "";
	string currentLab = "";
	Computer* currentComputer;
	String^ collegeKey;
	String^ labKey;
	String^ computerKey;
	//Call on the left branch
	if (tree->getLeft() != nullptr)
	{
		populateViewTree(tree->getLeft(), view);
	}
	//Make sure the _info is not empty
	if (tree->getInfo() != nullptr)
	{
		//store the computer
		currentComputer = tree->getInfo();
		//check to see if the computer's college is the same...
		if (currentComputer->getCollege() != currentCollege)
		{
			//Assign the local variables
			currentCollege = currentComputer->getCollege();
			collegeKey = gcnew String(currentCollege.c_str());
			//Check to see if the college already exisits
			if (!view->Nodes->ContainsKey(collegeKey))
			{
				view->Nodes->Add(collegeKey, collegeKey);
			}
		}
		//check to see if the computer's lab is the same..
		if (currentComputer->getLab() != currentLab)
		{
			currentLab = currentComputer->getLab();
			labKey = gcnew String(currentLab.c_str());
			cli::array<TreeNode^>^ found = view->Nodes->Find(collegeKey, false);
			if (!found[0]->Nodes->ContainsKey(labKey))
			{
				cli::array<TreeNode^>^ found = view->Nodes->Find(collegeKey, false);
				found[0]->Nodes->Add(labKey, labKey);
			}
		}
		//Add the computer
		computerKey = gcnew String(currentComputer->getName().c_str());
		cli::array<TreeNode^>^ found = view->Nodes->Find(collegeKey, false);

		cli::array<TreeNode^>^ found2 = found[0]->Nodes->Find(labKey, false);
		found2[0]->Nodes->Add(computerKey, computerKey);
	}
	if (tree->getRight() != nullptr)
	{
		populateViewTree(tree->getRight(), view);
	}

}

void RDTool::MainWindow::paintPanels(ComputerTree<Computer>* tree)
{
	if (!isRemoving)
	{
		//Need to traverse the layout getting the status of each one
		//probably by looking for key words (i.e. available, In use, Unknown)
		//then needs to update the status label and paint the panel.
		if (tree->getInfo() != nullptr)
		{
			if (!isRemoving)
			{
				paintPanels(tree->getLeft());
			}
			else
			{
				return;
			}
		}
		if (tree->getInfo() != nullptr)
		{
			if (!isRemoving)
			{


				int status = tree->getInfo()->getStatus();
				String^ user;
				string rawUser;
				string userName = tree->getInfo()->getUser();
				string rawName = tree->getInfo()->getName();
				String^ name = gcnew String(rawName.c_str());
				Color a;
				if (status == 1)
				{
					//Set color to yellow
					a = System::Drawing::Color::FromArgb(255, 240, 230, 140);
					rawUser = "In use by: ";
					rawUser += userName;
				}
				else if (status == 2)
				{
					//Set color to red
					a = System::Drawing::Color::FromArgb(255, 250, 128, 114);
					rawUser = "Unavailable";
				}
				else
				{
					//Set color to Green
					a = System::Drawing::Color::FromArgb(255, 144, 238, 144);
					rawUser = "Available";
				}
				user = gcnew String(rawUser.c_str());
				auto comp = MainWindow::computerDisplay->Controls->Find(name, false);

				comp[0]->BackColor = a;
				auto temp = comp[0]->Controls->Find(L"computerStatus", true);
				temp[0]->Text = user;
			}
			else
			{
				return;
			}
		}
		if (tree->getRight() != nullptr)
		{
			if (!isRemoving)
			{
				paintPanels(tree->getRight());
			}
		}
	}
}

void RDTool::MainWindow::runCommand(String^ cmd)
{
	//throw gcnew System::NotImplementedException();
	string command = msclr::interop::marshal_as<std::string>(cmd);
	selectedTree->runCommand(command);
}

String ^ RDTool::MainWindow::currentDateTime()
{
	cout << "Getting time..." << endl;
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%X", &tstruct);
	cout << "Finished!" << endl;
	String^ lastCheckBase = (L"Last Checked: " + gcnew String(buf));
	cout << "Label is set up..." << endl;

	return lastCheckBase;
}

void RDTool::MainWindow::clearSelected()
{
	selectedNameLabel->Text = L"Name: ";
	selectedCollegeLabel->Text = L"College: ";
	selectedByIPLabel->Text = L"Connected by IP: ";
	selectedMACLabel->Text = L"MAC: ";
	selectedIPLabel->Text = L"IP: ";
	freeMemoryLabel->Text = L"Free Memory: ";
	selectedComputer = NULL;
}



System::Windows::Forms::Panel^ RDTool::MainWindow::createPanel(System::String ^ name, System::String ^ status, System::Windows::Forms::FlowLayoutPanel ^ display)
{
	System::Windows::Forms::Label^ labelName = gcnew Label();

	labelName->AutoSize = true;
	labelName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	labelName->Location = System::Drawing::Point(3, 25);
	labelName->Name = L"computerName";
	labelName->Size = System::Drawing::Size(120, 22);
	labelName->Text = name;
	// 
	// computerStatus
	// 
	System::Windows::Forms::Label^ computerStatus = gcnew Label();
	computerStatus->AutoSize = true;
	computerStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	computerStatus->Location = System::Drawing::Point(160, 25);
	computerStatus->Name = L"computerStatus";
	computerStatus->Size = System::Drawing::Size(120, 22);
	computerStatus->Text = status;

	// 
	// labview button
	// 
	System::Windows::Forms::Button^ labViewButton = gcnew Button();
	System::Windows::Forms::Button^ remoteButton = gcnew Button();
	System::Windows::Forms::Button^ magicButton = gcnew Button();
	System::Windows::Forms::Button^ computerRemove = gcnew Button();
	labViewButton->Name = L"labView";
	labViewButton->Location = System::Drawing::Point(3, 54);
	labViewButton->Size = System::Drawing::Size(75, 23);
	labViewButton->Text = L"Lab View";
	labViewButton->UseVisualStyleBackColor = true;
	// 
	// remote desktop button
	// 
	remoteButton->Name = L"remoteDesktop";
	remoteButton->Location = System::Drawing::Point(140, 54);
	remoteButton->Size = System::Drawing::Size(75, 23);
	remoteButton->Text = L"Remote Desktop";
	remoteButton->UseVisualStyleBackColor = true;
	// 
	// magic packet button
	// 
	magicButton->Name = L"magic";
	magicButton->Location = System::Drawing::Point(267, 54);
	magicButton->Size = System::Drawing::Size(75, 23);
	magicButton->Text = L"Magic Packets";
	magicButton->UseVisualStyleBackColor = true;
	// 
	// computerRemove
	// 
	computerRemove->AutoSize = true;
	computerRemove->Location = System::Drawing::Point(320, 0);
	computerRemove->Name = L"computerRemove";
	computerRemove->Size = System::Drawing::Size(7, 3);
	computerRemove->TabIndex = 5;
	computerRemove->TabStop = true;
	computerRemove->Text = L"X";
	computerRemove->UseVisualStyleBackColor = true;
	

	//Panel that will be returned
	Panel^ pan = gcnew Panel();
	//Setting properties of the pannel and adding information onto it
	pan->Name = name;
	pan->Size = System::Drawing::Size(350, 80);
	pan->Controls->Add(computerRemove);
	pan->Controls->Add(labelName);
	pan->Controls->Add(computerStatus);
	pan->Controls->Add(labViewButton);
	pan->Controls->Add(remoteButton);
	pan->Controls->Add(magicButton);
	pan->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
	remoteButton->Parent = pan;
	magicButton->Parent = pan;
	labViewButton->Parent = pan;
	//
	//Color
	//

	if (status[0] == ' ')
	{

		pan->BackColor = System::Drawing::Color::FromArgb(255, 240, 230, 140);
	}
	else if (status[0] == 'U')
	{
		pan->BackColor = System::Drawing::Color::FromArgb(255, 250, 128, 114);
	}
	else
	{
		pan->BackColor = System::Drawing::Color::FromArgb(255, 144, 238, 144);
	}
	//Setting the listners for the three buttons
	remoteButton->Click += gcnew System::EventHandler(this, &MainWindow::remoteButton_Click);
	labViewButton->Click += gcnew System::EventHandler(this, &MainWindow::labViewButton_Click);
	magicButton->Click += gcnew System::EventHandler(this, &MainWindow::magicButton_Click);
	computerRemove->Click += gcnew System::EventHandler(this, &MainWindow::computerRemove_Click);
	pan->Click += gcnew System::EventHandler(this, &MainWindow::panel_Clicked);
	labelName->Click += gcnew System::EventHandler(this, &MainWindow::labelOnPanel_Clicked);
	computerStatus->Click += gcnew System::EventHandler(this, &MainWindow::labelOnPanel_Clicked);
	remoteButton->Click += gcnew System::EventHandler(this, &MainWindow::buttonOnPanel_Clicked);
	labViewButton->Click += gcnew System::EventHandler(this, &MainWindow::buttonOnPanel_Clicked);
	magicButton->Click += gcnew System::EventHandler(this, &MainWindow::buttonOnPanel_Clicked);
	display->Padding.All = 10;
	return pan;



}




