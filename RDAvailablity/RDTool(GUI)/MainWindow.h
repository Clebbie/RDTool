#pragma once
#include"Computer.h"
#include"ComputerTree.h"
#include <msclr\marshal_cppstd.h>


namespace RDToolGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{

	public:
		MainWindow(ComputerTree<Computer>* tree)
		{
			_tree = tree;
			selectedTree = new ComputerTree<Computer>();
			InitializeComponent();
			populateViewTree(tree,computerTree);
			//computerTree->Update();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TreeView^  computerTree;
			 ComputerTree<Computer>* _tree;
	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->computerTree = (gcnew System::Windows::Forms::TreeView());
			this->SuspendLayout();
			// 
			// computerTree
			// 
			this->computerTree->CheckBoxes = true;
			//this->computerTree->FullRowSelect = true;
			this->computerTree->Location = System::Drawing::Point(2, -1);
			this->computerTree->Name = L"computerTree";
			this->computerTree->ShowNodeToolTips = true;
			this->computerTree->Size = System::Drawing::Size(195, 749);
			this->computerTree->TabIndex = 0;
			//this->computerTree->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &MainWindow::computerTree_AfterSelect);
			computerTree->AfterCheck += gcnew TreeViewEventHandler(this, &MainWindow::computerTree_AfterSelect);
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1382, 749);
			this->Controls->Add(this->computerTree);
			this->Name = L"MainWindow";
			this->Text = L"RDTool";
			this->ResumeLayout(false);

		}
#pragma endregion
		void populateViewTree(ComputerTree<Computer>* tree, System::Windows::Forms::TreeView ^ view);
		ComputerTree<Computer>* selectedTree;
	private: System::Void computerTree_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) {
		//College level selected
		if (e->Node->Level == 0)
		{
			if (e->Node->Checked)
			{
				//Expand all children
				e->Node->ExpandAll();
				
				int size = e->Node->GetNodeCount(false);
				for (int i = 0; i < size; i++)
				{
					if (!e->Node->Nodes[i]->Checked)
					{
						//Select every child of the node and set to true
						e->Node->Nodes[i]->Checked = true;
					}
				}
			}
			else
			{

				int size = e->Node->GetNodeCount(false);
				e->Node->Collapse();
				for (int i = 0; i < size; i++)
				{
					if (e->Node->Nodes[i]->Checked)
					{
						e->Node->Nodes[i]->Checked = false;
					}
				}
			}
		}
		//Lab level selected
		else if (e->Node->Level == 1)
		{
			if (e->Node->Checked)
			{
				int size = e->Node->GetNodeCount(false);
				e->Node->ExpandAll();
				for (int i = 0; i < size; i++)
				{
					if (!e->Node->Nodes[i]->Checked)
					{
						e->Node->Nodes[i]->Checked = true;
					}
				}
			}
			else
			{
				int size = e->Node->GetNodeCount(false);
				e->Node->Collapse();
				e->Node->ExpandAll();
				for (int i = 0; i < size; i++)
				{
					if (e->Node->Nodes[i]->Checked)
					{
						e->Node->Nodes[i]->Checked = false;
						//TODO: find the computer in the selectedTree and remove it!
					}
				}
			}
			cout << (*selectedTree) << endl;
		}
		//Last level is selected
		else
		{
			if (e->Node->Checked)
			{
				//TODO: Find the computer in the _tree and add it to the selectedTree
				string name = msclr::interop::marshal_as<std::string>(e->Node->Name);
				ComputerTree<Computer>*temp = _tree->find(name);
				selectedTree->insert(temp->getInfo());

			}
			else
			{
				//TODO: find the computer in the selectedTree and remove it!
				string name = msclr::interop::marshal_as<std::string>(e->Node->Name);
				ComputerTree<Computer>*temp = _tree->find(name);
				selectedTree->remove(temp->getInfo());
			}
		}
	}
	};
}
