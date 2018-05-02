#pragma once
#include"ComputerTree.h"
#include"Computer.h"

namespace RDToolGUI {
	using namespace std;
	using namespace cli;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(ComputerTree<Computer> tree)
		{
			InitializeComponent(tree);
			//
			//TODO: Add the constructor code here
			//

		}
		void populateViewTree(ComputerTree<Computer> tree, TreeView view);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TreeView^  ComputerList;
	private: System::Windows::Forms::TextBox^  textBox1;


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
		void InitializeComponent(ComputerTree<Computer> tree)
		{
			this->ComputerList = (gcnew System::Windows::Forms::TreeView());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			populateViewTree(tree, ComputerList);
			this->SuspendLayout();
			// 
			// ComputerList
			// 
			this->ComputerList->CheckBoxes = true;
			this->ComputerList->FullRowSelect = true;
			this->ComputerList->Location = System::Drawing::Point(1, 3);
			this->ComputerList->Name = L"ComputerList";
			this->ComputerList->Size = System::Drawing::Size(186, 833);
			this->ComputerList->TabIndex = 0;
			this->ComputerList->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &MyForm::ComputerList_AfterSelect);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(193, 806);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(1207, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1432, 838);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->ComputerList);
			this->Name = L"MyForm";
			this->Text = L"RDTool";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
		{
		}
		private: System::Void ComputerList_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e)
		{
		}
		private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e)
		{
		}
	};
}

