#pragma once
#include "MainWindow.h"

namespace RDTool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class RunCommand : public System::Windows::Forms::Form
	{
	public:
		RunCommand()
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		String^ getCommand();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RunCommand()
		{
			if (components)
			{
				delete components;
			}
		}
		String^ cmd;
	private: System::Windows::Forms::Label^  info;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  run;
	private: System::Windows::Forms::Button^  Cancel;
	

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
			this->info = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->run = (gcnew System::Windows::Forms::Button());
			this->Cancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// info
			// 
			this->info->AutoSize = true;
			this->info->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->info->Location = System::Drawing::Point(161, 53);
			this->info->Name = L"info";
			this->info->Size = System::Drawing::Size(214, 22);
			this->info->TabIndex = 0;
			this->info->Text = L"Type the command to run";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 122);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(529, 20);
			this->textBox1->TabIndex = 1;
			// 
			// run
			// 
			this->run->Location = System::Drawing::Point(95, 186);
			this->run->Name = L"run";
			this->run->Size = System::Drawing::Size(75, 23);
			this->run->TabIndex = 2;
			this->run->Text = L"Run";
			this->run->UseVisualStyleBackColor = true;
			this->run->Click += gcnew System::EventHandler(this, &RunCommand::run_Click);
			// 
			// Cancel
			// 
			this->Cancel->Location = System::Drawing::Point(405, 186);
			this->Cancel->Name = L"Cancel";
			this->Cancel->Size = System::Drawing::Size(75, 23);
			this->Cancel->TabIndex = 3;
			this->Cancel->Text = L"Cancel";
			this->Cancel->UseVisualStyleBackColor = true;
			this->Cancel->Click += gcnew System::EventHandler(this, &RunCommand::Cancel_Click);
			// 
			// RunCommand
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(553, 261);
			this->Controls->Add(this->Cancel);
			this->Controls->Add(this->run);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->info);
			this->Name = L"RunCommand";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Run Command";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void run_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		
		if (textBox1->Text == L"")
		{
			String^ message = "Enter a command";
			String^ caption = "Error";
			//MessageBox err;
			MessageBoxButtons buttons = MessageBoxButtons::OK;
			MessageBox::Show(this, message, caption, buttons);
		}
		else
		{
			string command = msclr::interop::marshal_as<std::string>(textBox1->Text);
			/*MainWindow::selectedTree->runCommand(command);*/
			this->Close();
		}
	}
	private: System::Void Cancel_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		this->Close();
	}
};
}
