#include "MainWindow.h"
#include<string>

void RDToolGUI::MainWindow::populateViewTree(ComputerTree<Computer>* tree, System::Windows::Forms::TreeView ^ view)
{
	//throw gcnew System::NotImplementedException();
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
				view->Nodes->Add(collegeKey,collegeKey);
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

System::Windows::Forms::Panel^ RDToolGUI::MainWindow::createPanel(System::String ^ name, System::String ^ status, System::Windows::Forms::FlowLayoutPanel ^ display)
{
	/*throw gcnew System::NotImplementedException();*/
	// 
	// labelName
	//
	System::Windows::Forms::Label^ labelName = gcnew Label();

	labelName->AutoSize = true;
	labelName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	labelName->Location = System::Drawing::Point(3, 15);
	labelName->Name = L"computerName";
	labelName->Size = System::Drawing::Size(120, 22);
	labelName->Text = name;
	// 
	// computerStatus
	// 
	System::Windows::Forms::Label^ computerStatus= gcnew Label();
	computerStatus->AutoSize = true;
	computerStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	computerStatus->Location = System::Drawing::Point(140, 15);
	computerStatus->Name = L"computerStatus";
	computerStatus->Size = System::Drawing::Size(120, 22);
	computerStatus->Text = status;
	// 
	// button3
	// 
	System::Windows::Forms::Button^ labViewButton = gcnew Button();
	System::Windows::Forms::Button^ remoteButton = gcnew Button();
	System::Windows::Forms::Button^ magicButton = gcnew Button();
	labViewButton->Name = L"labView";
	labViewButton->Location = System::Drawing::Point(3, 54);
	labViewButton->Size = System::Drawing::Size(75, 23);
	labViewButton->Text = L"Lab View";
	labViewButton->UseVisualStyleBackColor = true;
	// 
	// button2
	// 
	
	remoteButton->Name = L"remoteDesktop";
	remoteButton->Location = System::Drawing::Point(140, 54);
	remoteButton->Size = System::Drawing::Size(75, 23);
	remoteButton->Text = L"Remote Desktop";
	remoteButton->UseVisualStyleBackColor = true;
	
	// 
	// button1
	// 
	magicButton->Name = L"magic";
	magicButton->Location = System::Drawing::Point(267, 54);
	magicButton->Size = System::Drawing::Size(75, 23);
	magicButton->Text = L"Magic Packets";
	magicButton->UseVisualStyleBackColor = true;
	

	Panel^ pan = gcnew Panel();

	pan->Name = name;
	pan->Size = System::Drawing::Size(350, 80);
	pan->Controls->Add(labelName);
	pan->Controls->Add(computerStatus);
	pan->Controls->Add(labViewButton);
	pan->Controls->Add(remoteButton);
	pan->Controls->Add(magicButton);
	pan->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
	remoteButton->Parent = pan;
	magicButton->Parent = pan;
	labViewButton->Parent = pan;
	
	remoteButton->Click += gcnew System::EventHandler(this, &MainWindow::remoteButton_Click);
	labViewButton->Click += gcnew System::EventHandler(this, &MainWindow::labViewButton_Click);
	magicButton->Click += gcnew System::EventHandler(this, &MainWindow::magicButton_Click);
	display->Padding.All = 10;
	return pan;

	
	
}

 


