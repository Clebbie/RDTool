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

	private: System::Windows::Forms::Label^  label1;
	//private: System::Windows::Forms::Button^  labViewButton;
	private: System::Windows::Forms::Button^  remoteButton;
	private: System::Windows::Forms::Button^  test;
	private: System::Windows::Forms::FlowLayoutPanel^  computerDisplay;

	public: System::Windows::Forms::Panel^ createPanel(System::String^ name, System::String^ status, System::Windows::Forms::FlowLayoutPanel^ display);




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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->test = (gcnew System::Windows::Forms::Button());
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
			this->computerDisplay->AutoScroll = true;
			this->computerDisplay->Dock = System::Windows::Forms::DockStyle::Fill;
			this->computerDisplay->Location = System::Drawing::Point(188, 0);
			this->computerDisplay->Name = L"computerDisplay";
			this->computerDisplay->Size = System::Drawing::Size(1716, 1041);
			this->computerDisplay->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(10, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(277, 22);
			this->label1->TabIndex = 0;
			this->label1->Text = L"LS-ADMIN-02 in use by yarn0000";
			// 
			// test
			// 
			this->test->Location = System::Drawing::Point(0, 0);
			this->test->Name = L"test";
			this->test->Size = System::Drawing::Size(75, 23);
			this->test->TabIndex = 0;
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
			this->ResumeLayout(false);

		}
#pragma endregion
		void populateViewTree(ComputerTree<Computer>* tree, System::Windows::Forms::TreeView ^ view);
		ComputerTree<Computer>* selectedTree;
	private: System::Void computerTree_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e)
	{
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
				String^ labelStatus;
				int status = temp->getInfo()->getStatus();

				if (status == 1)
				{
					string foo = " In use by: ";
					string bar = temp->getInfo()->getUser()->c_str();
					foo += bar;
					labelStatus = gcnew String(foo.c_str());
				}
				else if (status == 2)
				{
					labelStatus = L"Unavailable";
				}
				else
				{
					labelStatus = L"Available";
				}
				Panel^ test = createPanel(labelName, labelStatus, computerDisplay);
				temp->getInfo()->checkUser();
				if (status == 1)
				{
					test->BackColor = test->BackColor.LightYellow;
				}
				else if (status == 2)
				{
					test->BackColor = test->BackColor.IndianRed;
					
				}
				else
				{
					test->BackColor = test->BackColor.Green;
				}
				computerDisplay->Controls->Add(test);
				
				

			}
			else
			{
				string name = msclr::interop::marshal_as<std::string>(e->Node->Name);
				ComputerTree<Computer>*temp = _tree->find(name);
				String^ labelName = e->Node->Name;
				//computerDisplay->Controls->RemoveByKey(labelName);
				selectedTree->remove(temp->getInfo());
				computerDisplay->Controls->RemoveByKey(e->Node->Name);

			}
		}
	}
	//private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	//	//string name = msclr::interop::marshal_as<std::string>(this->Parent->Name);
	//	
	//	string name = msclr::interop::marshal_as<std::string>(button2->Parent->Name->ToString());
	//	cout << name << endl;
	//	
	//}
	public: System::Void remoteButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Button^ ctrl = safe_cast<Button^>(sender);
		
		string name = msclr::interop::marshal_as<std::string>(ctrl->Parent->Name->ToString());
		selectedTree->find(name)->getInfo()->remoteDesktop();
	}
	public: System::Void labViewButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Button^ ctrl = safe_cast<Button^>(sender);

		string name = msclr::interop::marshal_as<std::string>(ctrl->Parent->Name->ToString());
		selectedTree->find(name)->getInfo()->labView();
	}
	public: System::Void magicButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Button^ ctrl = safe_cast<Button^>(sender);

		string name = msclr::interop::marshal_as<std::string>(ctrl->Parent->Name->ToString());
		selectedTree->find(name)->getInfo()->turnOn();
	}

};

}
