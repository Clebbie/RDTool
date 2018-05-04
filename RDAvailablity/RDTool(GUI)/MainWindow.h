#pragma once
#include"Computer.h"
#include"ComputerTree.h"


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
	private: System::Windows::Forms::TreeView^  computerTree;
	public:
		MainWindow(ComputerTree<Computer>* tree)
		{
			InitializeComponent();
			populateViewTree(tree,computerTree);
			
			computerTree->Update();
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
			this->computerTree->Location = System::Drawing::Point(2, -1);
			this->computerTree->Name = L"computerTree";
			this->computerTree->Size = System::Drawing::Size(164, 749);
			this->computerTree->TabIndex = 0;
			this->computerTree->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &MainWindow::computerTree_AfterSelect);
			// 
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
	private: System::Void computerTree_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) {
	}
	};
}
