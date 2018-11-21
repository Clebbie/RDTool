#pragma once
#include"Computer.h"
#include"ComputerTree.h"
#include <msclr\marshal_cppstd.h>
#include <chrono>
#include<Windows.h>
#include"RunCommand.h"


namespace RDTool
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
		static ComputerTree<Computer>* selectedTree;
		MainWindow(ComputerTree<Computer>* tree)
		{
			_tree = tree;
			selectedTree = new ComputerTree<Computer>();
			InitializeComponent();
			populateViewTree(tree, computerTree);
			isRemoving = false;
			isChecking = false;
			isAdding = false;
		}
	private: System::Windows::Forms::TextBox^  cmdBox;
	private: System::Windows::Forms::Label^  computerCountLabel;
			 int numOfComputers = 0;
	private: System::Windows::Forms::Button^  command;
	private: System::Windows::Forms::Label^  selectedCollegeLabel;
	private: System::Windows::Forms::Label^  selectedIPLabel;
	private: System::Windows::Forms::Label^  selectedMACLabel;
	private: System::Windows::Forms::Label^  selectedByIPLabel;
	private: System::Windows::Forms::Label^  lastUserCheckLabel;
	private: System::Windows::Forms::Panel^  userCheckPanel;



	public:
		static System::String^ cmd;
		System::Windows::Forms::Panel^ createPanel(System::String^ name, System::String^ status, System::Windows::Forms::FlowLayoutPanel^ display);
		void populateViewTree(ComputerTree<Computer>* tree, System::Windows::Forms::TreeView ^ view);
		static void paintPanels(ComputerTree<Computer>* tree);
		static void runCommand(String^ cmd);
		static bool isRemoving;
		static bool isChecking;
		static bool isAdding;
		static bool isSelected;

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

	private:
		System::Windows::Forms::TreeView^  computerTree;
		ComputerTree<Computer>* _tree;
	private: System::Windows::Forms::FlowLayoutPanel^  computerDisplay;



		System::Windows::Forms::MenuStrip^  menuStrip1;
		System::Windows::Forms::ToolStripMenuItem^  commandToolStripMenuItem;

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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->commandToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cmdBox = (gcnew System::Windows::Forms::TextBox());
			this->computerCountLabel = (gcnew System::Windows::Forms::Label());
			this->command = (gcnew System::Windows::Forms::Button());
			this->selectedCollegeLabel = (gcnew System::Windows::Forms::Label());
			this->selectedIPLabel = (gcnew System::Windows::Forms::Label());
			this->selectedMACLabel = (gcnew System::Windows::Forms::Label());
			this->selectedByIPLabel = (gcnew System::Windows::Forms::Label());
			this->lastUserCheckLabel = (gcnew System::Windows::Forms::Label());
			this->userCheckPanel = (gcnew System::Windows::Forms::Panel());
			this->menuStrip1->SuspendLayout();
			this->userCheckPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// computerTree
			// 
			this->computerTree->CheckBoxes = true;
			this->computerTree->Dock = System::Windows::Forms::DockStyle::Left;
			this->computerTree->Location = System::Drawing::Point(0, 24);
			this->computerTree->Name = L"computerTree";
			this->computerTree->RightToLeftLayout = true;
			this->computerTree->ShowNodeToolTips = true;
			this->computerTree->Size = System::Drawing::Size(188, 1017);
			this->computerTree->TabIndex = 0;
			this->computerTree->AfterCheck += gcnew System::Windows::Forms::TreeViewEventHandler(this, &MainWindow::computerTree_AfterSelect);
			// 
			// computerDisplay
			// 
			this->computerDisplay->AutoScroll = true;
			this->computerDisplay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->computerDisplay->Location = System::Drawing::Point(188, 24);
			this->computerDisplay->Name = L"computerDisplay";
			this->computerDisplay->Size = System::Drawing::Size(1417, 1017);
			this->computerDisplay->TabIndex = 1;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->commandToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1904, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// commandToolStripMenuItem
			// 
			this->commandToolStripMenuItem->Name = L"commandToolStripMenuItem";
			this->commandToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->commandToolStripMenuItem->Text = L"Help";
			this->commandToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::commandToolStripMenuItem_Click);
			// 
			// cmdBox
			// 
			this->cmdBox->AcceptsReturn = true;
			this->cmdBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmdBox->Location = System::Drawing::Point(188, -3);
			this->cmdBox->Name = L"cmdBox";
			this->cmdBox->Size = System::Drawing::Size(1417, 27);
			this->cmdBox->TabIndex = 3;
			// 
			// computerCountLabel
			// 
			this->computerCountLabel->AutoSize = true;
			this->computerCountLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->computerCountLabel->Location = System::Drawing::Point(1611, 0);
			this->computerCountLabel->Name = L"computerCountLabel";
			this->computerCountLabel->Size = System::Drawing::Size(176, 22);
			this->computerCountLabel->TabIndex = 4;
			this->computerCountLabel->Text = L"Computers loaded: 0";
			// 
			// command
			// 
			this->command->Location = System::Drawing::Point(113, 0);
			this->command->Name = L"command";
			this->command->Size = System::Drawing::Size(75, 23);
			this->command->TabIndex = 0;
			this->command->Text = L"Command";
			this->command->UseVisualStyleBackColor = true;
			this->command->Click += gcnew System::EventHandler(this, &MainWindow::command_Click);
			// 
			// selectedCollegeLabel
			// 
			this->selectedCollegeLabel->AutoSize = true;
			this->selectedCollegeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->selectedCollegeLabel->Location = System::Drawing::Point(1611, 75);
			this->selectedCollegeLabel->Name = L"selectedCollegeLabel";
			this->selectedCollegeLabel->Size = System::Drawing::Size(66, 20);
			this->selectedCollegeLabel->TabIndex = 5;
			this->selectedCollegeLabel->Text = L"College:";
			// 
			// selectedIPLabel
			// 
			this->selectedIPLabel->AutoSize = true;
			this->selectedIPLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->selectedIPLabel->Location = System::Drawing::Point(1611, 112);
			this->selectedIPLabel->Name = L"selectedIPLabel";
			this->selectedIPLabel->Size = System::Drawing::Size(28, 20);
			this->selectedIPLabel->TabIndex = 6;
			this->selectedIPLabel->Text = L"IP:";
			// 
			// selectedMACLabel
			// 
			this->selectedMACLabel->AutoSize = true;
			this->selectedMACLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->selectedMACLabel->Location = System::Drawing::Point(1611, 149);
			this->selectedMACLabel->Name = L"selectedMACLabel";
			this->selectedMACLabel->Size = System::Drawing::Size(48, 20);
			this->selectedMACLabel->TabIndex = 7;
			this->selectedMACLabel->Text = L"MAC:";
			// 
			// selectedByIPLabel
			// 
			this->selectedByIPLabel->AutoSize = true;
			this->selectedByIPLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->selectedByIPLabel->Location = System::Drawing::Point(1611, 180);
			this->selectedByIPLabel->Name = L"selectedByIPLabel";
			this->selectedByIPLabel->Size = System::Drawing::Size(130, 20);
			this->selectedByIPLabel->TabIndex = 8;
			this->selectedByIPLabel->Text = L"Connected by IP:";
			// 
			// lastUserCheckLabel
			// 
			this->lastUserCheckLabel->AutoSize = true;
			this->lastUserCheckLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->lastUserCheckLabel->Location = System::Drawing::Point(3, 10);
			this->lastUserCheckLabel->Name = L"lastUserCheckLabel";
			this->lastUserCheckLabel->Size = System::Drawing::Size(135, 20);
			this->lastUserCheckLabel->TabIndex = 9;
			this->lastUserCheckLabel->Text = L"Last User Check: ";
			this->lastUserCheckLabel->Click += gcnew System::EventHandler(this, &MainWindow::lastUserCheckLabel_Click);
			// 
			// userCheckPanel
			// 
			this->userCheckPanel->Controls->Add(this->lastUserCheckLabel);
			this->userCheckPanel->Location = System::Drawing::Point(1615, 27);
			this->userCheckPanel->Name = L"userCheckPanel";
			this->userCheckPanel->Size = System::Drawing::Size(277, 45);
			this->userCheckPanel->TabIndex = 10;
			this->userCheckPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainWindow::userCheckPanel_Paint);
			// 
			// MainWindow
			// 
			this->AcceptButton = this->command;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->userCheckPanel);
			this->Controls->Add(this->selectedByIPLabel);
			this->Controls->Add(this->selectedMACLabel);
			this->Controls->Add(this->selectedIPLabel);
			this->Controls->Add(this->selectedCollegeLabel);
			this->Controls->Add(this->command);
			this->Controls->Add(this->computerCountLabel);
			this->Controls->Add(this->cmdBox);
			this->Controls->Add(this->computerDisplay);
			this->Controls->Add(this->computerTree);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainWindow";
			this->Text = L"RDTool";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->userCheckPanel->ResumeLayout(false);
			this->userCheckPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void computerTree_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e)
	{
		this->computerTree->UseWaitCursor = true;
		this->computerDisplay->UseWaitCursor = true;
		this->isRemoving = true;
		this->isAdding = true;
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
				//This will add the computer selected from the viewTree and add it to the selected tree
				string name = msclr::interop::marshal_as<std::string>(e->Node->Name);
				ComputerTree<Computer>*temp = _tree->find(name);
				selectedTree->insert(temp->getInfo());
				String^ labelName = e->Node->Name;
				String^ labelStatus;

				//This will set the label for the panel
				temp->getInfo()->checkUser();
				int status = temp->getInfo()->getStatus();
				if (status == 1)
				{
					string foo = " In use by: ";
					string bar = temp->getInfo()->getUser();
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
				//This creates the panel then checks the user of the panel;
				Panel^ test = createPanel(labelName, labelStatus, computerDisplay);

				//Adds the panel to the display
				computerDisplay->Controls->Add(test);
				numOfComputers++;
				String^ computerCount = L"Computers Loaded: " + numOfComputers;
				computerCountLabel->Text = computerCount;
				


			}
			else
			{
				// This should stop the removing until the ischecking flag is set to false
				while (isChecking)
				{

				}
				//This will remove the panel and computer from the tree
				string name = msclr::interop::marshal_as<std::string>(e->Node->Name);
				ComputerTree<Computer>*temp = _tree->find(name);
				String^ labelName = e->Node->Name;
				selectedTree->remove(temp->getInfo());
				computerDisplay->Controls->RemoveByKey(e->Node->Name);
				numOfComputers--;
				String^ computerCount = L"Computers Loaded: " + numOfComputers;
				computerCountLabel->Text = computerCount;
				int size = e->Node->Parent->GetNodeCount(false);
				int falses = 0;
				for (int i = 0; i < size; i++)
				{
					if (e->Node->Parent->Nodes[i]->Checked == false)
					{
						falses++;
					}
				}
				if (size == falses)
				{
					e->Node->Parent->Checked = false;
				}
				size = e->Node->Parent->Parent->GetNodeCount(false);
				falses = 0;
				for (int i = 0; i < size; i++)
				{
					if (e->Node->Parent->Parent->Nodes[i]->Checked == false)
					{
						falses++;
					}
				}
				if (size == falses)
				{
					e->Node->Parent->Parent->Checked = false;
				}
			}
		}
		
		this->computerTree->UseWaitCursor = false;
		this->computerDisplay->UseWaitCursor = false;
		this->isRemoving = false;
		this->isAdding = false;

	}
			 //This is the event listener for the remote button
	public: System::Void remoteButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//creates the button from the sender
		Button^ ctrl = safe_cast<Button^>(sender);

		//Gets the panel name (Which is the name of the computer) then calls remote desktop on it
		string name = msclr::interop::marshal_as<std::string>(ctrl->Parent->Name->ToString());
		selectedTree->find(name)->getInfo()->remoteDesktop();
	}
			//This is the event listener for the lab view button
	public: System::Void labViewButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//creates the button from the sender
		Button^ ctrl = safe_cast<Button^>(sender);

		//Gets the panel name (which is the name of the computer) and calls lab view on it
		string name = msclr::interop::marshal_as<std::string>(ctrl->Parent->Name->ToString());
		selectedTree->find(name)->getInfo()->labView();
	}
			//This is the event listener for the magic packets button
			//TODO: Need to test this
	public: System::Void magicButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//creates the button from the sender
		Button^ ctrl = safe_cast<Button^>(sender);

		//Gets the panel name(which is the name of the computer) and calls the magic packts on it
		string name = msclr::interop::marshal_as<std::string>(ctrl->Parent->Name->ToString());
		selectedTree->find(name)->getInfo()->turnOn();
	}
	private: System::Void commandToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		String^ message = "Type a wmic command and replace the computer name with @c. Ex. wmic /node:\"@c\" bios get serialnumber\nHelpful wmic commands\n\nwmic bios get serial number // gets service tag\n\nwmic nicconfig where ipenabled=true get ipaddress, macaddress // gets IPv4, IPv6, and MAC" +
			"\n\nwmic product get // get all installed programs and their GUID's. USE SPARINGLY!\n\nwmic memorychip get capacity // gets the physical capacity of the memory ram in bytes\n\nwmic logicaldisk get size,freespace,caption // gets freespace and total space in bytes";
		String^ caption = "Help";
		MessageBoxButtons buttons = MessageBoxButtons::OK;
		MessageBox::Show(this, message, caption, buttons);
	}
	private: System::Void command_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (cmdBox->Text == L"")
		{
			String^ message = "Please enter a command.";
			String^ caption = "Error";
			MessageBoxButtons buttons = MessageBoxButtons::OK;
			MessageBox::Show(this, message, caption, buttons);
		}
		else
		{
			
			string command = msclr::interop::marshal_as<std::string>(cmdBox->Text);
			int found = command.find("@c");
			if (found != string::npos)
			{
				cmdBox->Text = L"";
				selectedTree->generateReport(command);
				String^ message = "Report Finshed. Check Your Desktop.";
				String^ caption = "Command Tool";
				MessageBoxButtons buttons = MessageBoxButtons::OK;
				MessageBox::Show(this, message, caption, buttons);
			}
			else
			{
				String^ message = "Could not find @c\nWrite your command with @c replacing the computer name\ni.e. wmic /node:\"@c\" bios get serialnumber or ping @c";
				String^ caption = "Error";
				MessageBoxButtons buttons = MessageBoxButtons::OK;
				MessageBox::Show(this, message, caption, buttons);
			}
		}
	}
private: System::Void computerRemove_Click(System::Object^  sender, System::EventArgs^  e) 
{
	Button^ ctrl = safe_cast<Button^>(sender);
	string name = msclr::interop::marshal_as<std::string>(ctrl->Parent->Name->ToString());
	auto temp = computerTree->Nodes->Find(ctrl->Parent->Name, true);
	temp[0]->Checked = false;
}
private: System::Void MainWindow_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void lastUserCheckLabel_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void userCheckPanel_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
};
}




