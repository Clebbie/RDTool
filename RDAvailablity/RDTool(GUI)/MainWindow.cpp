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

//void RDToolGUI::MainWindow::createPanel(String ^ name, String ^ status, FlowLayoutPanel^ display)
//{
//	throw gcnew System::NotImplementedException();
//	// TODO: insert return statement here
//	//Panel^ out = gcnew Panel();
//	//out->Name = name;
//
//	
//}
