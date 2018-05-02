#include "MyForm.h"

void RDToolGUI::MyForm::populateViewTree(ComputerTree<Computer> tree,TreeView view)
{
	throw gcnew System::NotImplementedException();
	bool isNewCollege = false;
	bool isNewLab = false;
	string currentLab ="";
	string currentCollege = "";

	if (tree.getInfo != nullptr)
	{
		//Call on the left tree
		populateViewTree(tree.getLeft(), view);
		//Populate the tree
		if (currentCollege != tree.getInfo->getCollege())
		{
			currentCollege = tree.getInfo->getCollege();
			isNewCollege = true;

			const std::wstring nodeName = currentCollege.c_str;

			System::Windows::Forms::TreeNode^  college = (gcnew System::Windows::Forms::TreeNode(nodeName.c_str, gcnew cli::array< System::Windows::Forms::TreeNode^  >(12) {
			
			}));

			currentLab = tree.getInfo->getLab();
			const wstring nextNodename = currentLab.c_str;
			System::Windows::Forms::TreeNode^  lab = (gcnew System::Windows::Forms::TreeNode(nextNodename.c_str, gcnew cli::array< System::Windows::Forms::TreeNode^  >(50) {

			}));

			string compName = tree.getInfo->getName();
			System::Windows::Forms::TreeNode^  computer = (gcnew System::Windows::Forms::TreeNode(compName.c_str));
			
			lab->Nodes->Add(computer);
			college->Nodes->Add(lab);
			view->Nodes->Add(college);

		}
		else if (currentLab != tree.getInfo->getLab())
		{
			currentLab = tree.getInfo->getLab();
			isNewLab = true;
			const wstring nextNodeName = currentLab.c_str;
			System::Windows::Forms::TreeNode^  lab = (gcnew System::Windows::Forms::TreeNode(nextNodeName.c_str, gcnew cli::array< System::Windows::Forms::TreeNode^  >(50) {

			}));
			string compName = tree.getInfo->getName();
			System::Windows::Forms::TreeNode^  computer = (gcnew System::Windows::Forms::TreeNode(compName.c_str));
			
			
			lab->Nodes->Add(computer);

			int collegeIndex = view->Nodes->IndexOfKey(currentCollege.c_str);
			view->Nodes[collegeIndex]->Nodes->Add(lab);
		}
		else
		{
			string compName = tree.getInfo->getName();
			System::Windows::Forms::TreeNode^  computer = (gcnew System::Windows::Forms::TreeNode(compName.c_str));
			int collegeIndex = view->Nodes->IndexOfKey(currentCollege.c_str);
			int labIndex = view->Nodes[collegeIndex]->Nodes->IndexOfKey(currentLab.c_str);
			view->Nodes[collegeIndex]->Nodes[labIndex]->Nodes->Add(computer);
		}
		//Call on the right tree
		populateViewTree(tree.getRight(), view);
	}

}
