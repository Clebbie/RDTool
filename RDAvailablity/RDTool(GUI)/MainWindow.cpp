#include "MainWindow.h"
#include<string>

void RDToolGUI::MainWindow::populateViewTree(ComputerTree<Computer>* tree, System::Windows::Forms::TreeView ^ view)
{
	//throw gcnew System::NotImplementedException();
	string currentCollege = "";
	string currentLab = "";
	Computer* currentComputer;
	//cout << "You made it here!";
	if (tree->getLeft() != nullptr)
	{
		populateViewTree(tree->getLeft(), view);
	}
	if (tree->getInfo() != nullptr)
	{
		cout << "Getting the computer..." << endl;
		cout << *currentComputer << endl;
		currentComputer = tree->getInfo();
		//check to see if the computer's college is the same...
		if (currentComputer->getCollege() != currentCollege)
		{
			currentCollege = currentComputer->getCollege();
			System::String^ test = gcnew String(currentCollege.c_str());

			System::Windows::Forms::TreeNode^  newCollege = (gcnew System::Windows::Forms::TreeNode(test));
			view->Nodes->AddRange(gcnew cli::array< System::Windows::Forms::TreeNode^  >(10) { newCollege });
			cout << "You made it here!";
			//view->Nodes->Add(newCollege, newCollege);
		}
		//check to see if the computer's lab is the same..
		if (currentComputer->getLab() != currentLab)
		{
			currentLab = currentComputer->getLab();
			System::String^ lab = gcnew String(currentLab.c_str());
			System::String^ college = gcnew String(currentCollege.c_str());

			view->Nodes->ContainsKey(college);
			//view->SelectedNode = view->Nodes->Find(college,false);

		}
		//Add the computer
	}
	if (tree->getRight() != nullptr)
	{
		populateViewTree(tree->getRight(), view);
	}
	
}
