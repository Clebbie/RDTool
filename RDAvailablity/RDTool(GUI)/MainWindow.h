#pragma once
#include"Computer.h"
#include"ComputerTree.h"
#include <msclr\marshal_cppstd.h>


namespace RDToolGUI
{

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
			populateViewTree(tree, computerTree);
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
	private: System::Windows::Forms::FlowLayoutPanel^  computerDisplay;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::Panel^  panel7;
	private: System::Windows::Forms::Panel^  panel8;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  computerStatus;
	private: System::Windows::Forms::Label^  labelName;








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
			this->computerDisplay = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->computerStatus = (gcnew System::Windows::Forms::Label());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->computerDisplay->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// computerTree
			// 
			this->computerTree->CheckBoxes = true;
			this->computerTree->Dock = System::Windows::Forms::DockStyle::Left;
			this->computerTree->Location = System::Drawing::Point(0, 0);
			this->computerTree->Name = L"computerTree";
			this->computerTree->ShowNodeToolTips = true;
			this->computerTree->Size = System::Drawing::Size(188, 1041);
			this->computerTree->TabIndex = 0;
			this->computerTree->AfterCheck += gcnew System::Windows::Forms::TreeViewEventHandler(this, &MainWindow::computerTree_AfterSelect);
			// 
			// computerDisplay
			// 
			this->computerDisplay->Controls->Add(this->panel2);
			this->computerDisplay->Controls->Add(this->panel3);
			this->computerDisplay->Controls->Add(this->panel4);
			this->computerDisplay->Controls->Add(this->panel5);
			this->computerDisplay->Controls->Add(this->panel6);
			this->computerDisplay->Controls->Add(this->panel7);
			this->computerDisplay->Controls->Add(this->panel8);
			this->computerDisplay->Controls->Add(this->panel1);
			this->computerDisplay->Dock = System::Windows::Forms::DockStyle::Fill;
			this->computerDisplay->Location = System::Drawing::Point(188, 0);
			this->computerDisplay->Name = L"computerDisplay";
			this->computerDisplay->Size = System::Drawing::Size(1716, 1041);
			this->computerDisplay->TabIndex = 1;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::Info;
			this->panel2->Controls->Add(this->computerStatus);
			this->panel2->Controls->Add(this->labelName);
			this->panel2->Controls->Add(this->button3);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Location = System::Drawing::Point(3, 3);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(318, 77);
			this->panel2->TabIndex = 1;
			// 
			// computerStatus
			// 
			this->computerStatus->AutoSize = true;
			this->computerStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->computerStatus->Location = System::Drawing::Point(129, 6);
			this->computerStatus->Name = L"computerStatus";
			this->computerStatus->Size = System::Drawing::Size(185, 22);
			this->computerStatus->TabIndex = 4;
			this->computerStatus->Text = L" is in use by yarn0000";
			// 
			// labelName
			// 
			this->labelName->AutoSize = true;
			this->labelName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelName->Location = System::Drawing::Point(3, 6);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(120, 22);
			this->labelName->TabIndex = 3;
			this->labelName->Text = L"LS-ADMIN-02";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(239, 50);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(118, 50);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Remote Desktop";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainWindow::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(3, 50);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// panel3
			// 
			this->panel3->Location = System::Drawing::Point(327, 3);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(369, 77);
			this->panel3->TabIndex = 3;
			// 
			// panel4
			// 
			this->panel4->Location = System::Drawing::Point(702, 3);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(369, 77);
			this->panel4->TabIndex = 4;
			// 
			// panel5
			// 
			this->panel5->Location = System::Drawing::Point(1077, 3);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(369, 77);
			this->panel5->TabIndex = 5;
			// 
			// panel6
			// 
			this->panel6->Location = System::Drawing::Point(3, 86);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(318, 77);
			this->panel6->TabIndex = 6;
			// 
			// panel7
			// 
			this->panel7->Location = System::Drawing::Point(327, 86);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(369, 77);
			this->panel7->TabIndex = 7;
			// 
			// panel8
			// 
			this->panel8->Location = System::Drawing::Point(702, 86);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(369, 77);
			this->panel8->TabIndex = 0;
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(1077, 86);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(369, 77);
			this->panel1->TabIndex = 2;
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->computerDisplay);
			this->Controls->Add(this->computerTree);
			this->Name = L"MainWindow";
			this->Text = L"RDTool";
			this->computerDisplay->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		void populateViewTree(ComputerTree<Computer>* tree, System::Windows::Forms::TreeView ^ view);
		//void createPanel(String^ name, String^ status,FlowLayoutPanel^ display);
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
				String^ labelName = e->Node->Name;
				String^ labelStatus = temp->getInfo()->getStatus().ToString();
				//computerDisplay->Controls->Add(createPanel(labelName, labelStatus));

			}
			else
			{
				//TODO: find the computer in the selectedTree and remove it!
				string name = msclr::interop::marshal_as<std::string>(e->Node->Name);
				ComputerTree<Computer>*temp = _tree->find(name);
				String^ labelName = e->Node->Name;
				//computerDisplay->Controls->RemoveByKey(labelName);
				selectedTree->remove(temp->getInfo());

			}
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		string name = msclr::interop::marshal_as<std::string>(this->Parent->Name);
		cout << name << endl;
		
	}
};
}
