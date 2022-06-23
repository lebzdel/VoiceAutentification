#pragma once
#include "AboutForm.h"
#include "User.h"
#include "Solvation.h"
#include "MFCC.h"
#include <vector>
#include <msclr\marshal_cppstd.h>

Solvation solve;

namespace kwork {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		String^ filePath;
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ menuToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ quitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;


	private: System::Windows::Forms::Label^ Passward;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ LoginTextBox;
	private: System::Windows::Forms::Button^ LogInButton;
	private: System::Windows::Forms::Button^ RegisterButton;
	private: System::Windows::Forms::TextBox^ FilePathTextBox;




	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->quitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Passward = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->LoginTextBox = (gcnew System::Windows::Forms::TextBox());
			this->LogInButton = (gcnew System::Windows::Forms::Button());
			this->RegisterButton = (gcnew System::Windows::Forms::Button());
			this->FilePathTextBox = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->menuToolStripMenuItem,
					this->aboutToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(10, 3, 0, 3);
			this->menuStrip1->Size = System::Drawing::Size(471, 25);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menuToolStripMenuItem
			// 
			this->menuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->quitToolStripMenuItem });
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(50, 19);
			this->menuToolStripMenuItem->Text = L"Menu";
			// 
			// quitToolStripMenuItem
			// 
			this->quitToolStripMenuItem->Name = L"quitToolStripMenuItem";
			this->quitToolStripMenuItem->Size = System::Drawing::Size(97, 22);
			this->quitToolStripMenuItem->Text = L"Quit";
			this->quitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::quitToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 19);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::aboutToolStripMenuItem_Click);
			// 
			// Passward
			// 
			this->Passward->AutoSize = true;
			this->Passward->Location = System::Drawing::Point(74, 97);
			this->Passward->Name = L"Passward";
			this->Passward->Size = System::Drawing::Size(90, 19);
			this->Passward->TabIndex = 2;
			this->Passward->Text = L"Record file: ";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(106, 62);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 19);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Name: ";
			this->label1->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
			// 
			// LoginTextBox
			// 
			this->LoginTextBox->Location = System::Drawing::Point(171, 59);
			this->LoginTextBox->Name = L"LoginTextBox";
			this->LoginTextBox->Size = System::Drawing::Size(169, 26);
			this->LoginTextBox->TabIndex = 4;
			// 
			// LogInButton
			// 
			this->LogInButton->Location = System::Drawing::Point(110, 142);
			this->LogInButton->Name = L"LogInButton";
			this->LogInButton->Size = System::Drawing::Size(99, 29);
			this->LogInButton->TabIndex = 5;
			this->LogInButton->Text = L"Log In";
			this->LogInButton->UseVisualStyleBackColor = true;
			this->LogInButton->Click += gcnew System::EventHandler(this, &MainForm::LogInButton_Click);
			// 
			// RegisterButton
			// 
			this->RegisterButton->Location = System::Drawing::Point(231, 142);
			this->RegisterButton->Name = L"RegisterButton";
			this->RegisterButton->Size = System::Drawing::Size(99, 29);
			this->RegisterButton->TabIndex = 6;
			this->RegisterButton->Text = L"Register";
			this->RegisterButton->UseVisualStyleBackColor = true;
			this->RegisterButton->Click += gcnew System::EventHandler(this, &MainForm::RegisterButton_Click);
			// 
			// FilePathTextBox
			// 
			this->FilePathTextBox->Location = System::Drawing::Point(171, 94);
			this->FilePathTextBox->Name = L"FilePathTextBox";
			this->FilePathTextBox->Size = System::Drawing::Size(169, 26);
			this->FilePathTextBox->TabIndex = 7;
			this->FilePathTextBox->Text = L"example (\"male1.wav\")";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(471, 216);
			this->Controls->Add(this->FilePathTextBox);
			this->Controls->Add(this->RegisterButton);
			this->Controls->Add(this->LogInButton);
			this->Controls->Add(this->LoginTextBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Passward);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Imprint MT Shadow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MainForm";
			this->Text = L"VoiceAutentification";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		#pragma endregion

		private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void quitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			Close();
		}
		private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			AboutForm ^aboutWindow = gcnew AboutForm();
			//aboutWindow -> Show();
			aboutWindow->ShowDialog();
		}
		private: System::Void RegisterButton_Click(System::Object^ sender, System::EventArgs^ e) {
			int result;
			if (msclr::interop::marshal_as< std::string >(FilePathTextBox->Text).find('/') != std::string::npos) {
				result = 4;
			}
			else {
				string name = msclr::interop::marshal_as< std::string >(LoginTextBox->Text);
				string filePath = msclr::interop::marshal_as< std::string >("Records/Register/" + FilePathTextBox->Text);
				result = solve.RegisterNewUser(name, filePath);
			}

			switch (result)
			{
			case 1:
				MessageBox::Show(
					"You have been successfully registered!",
					"Congratulations",
					MessageBoxButtons::OK
				);
				break;
			
			case 0: 
				MessageBox::Show(
					"Your login is already used",
					"No register",
					MessageBoxButtons::OK
				);
				break;

			case 2: 
				MessageBox::Show(
					"Your file was not found",
					"No register",
					MessageBoxButtons::OK
				);
				break;

			case 3: 
				MessageBox::Show(
					"Your the file does not meet the requirements",
					"No register",
					MessageBoxButtons::OK
				);
				break;

			case 4:
				MessageBox::Show(
					"Please, write filename without address.\nYour file should be located in the folder \"Records/Register\".",
					"No register",
					MessageBoxButtons::OK
				);
				break;

			default:
				break;
			}
		}
		private: System::Void registerToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void LogInButton_Click(System::Object^ sender, System::EventArgs^ e) {
			int result;
			if (msclr::interop::marshal_as< std::string >(FilePathTextBox->Text).find('/') != std::string::npos) {
				result = 5;
			}
			else {
				string name = msclr::interop::marshal_as< std::string >(LoginTextBox->Text);
				string filePath = msclr::interop::marshal_as< std::string >("Records/LogIn/" + FilePathTextBox->Text);
				result = solve.CheckUser(name, filePath);
			}
			switch (result)
			{
			case 0:
				MessageBox::Show(
					"Your name is already used",
					"Sorry",
					MessageBoxButtons::OK
				);
				break;
			case 1:
				MessageBox::Show(
					"Access is allowed",
					"Congratulations",
					MessageBoxButtons::OK
				);
				break;
			case 2:
				MessageBox::Show(
					"Access denied",
					"Sorry",
					MessageBoxButtons::OK
				);
				break;
			case 3:
				MessageBox::Show(
					"Your file was not found",
					"Sorry",
					MessageBoxButtons::OK
				);
				break;
			case 4:
				MessageBox::Show(
					"Your the file does not meet the requirements",
					"Sorry",
					MessageBoxButtons::OK
				);
				break;
			case 5:
				MessageBox::Show(
					"Please, write filename without address.\nYour file should be located in the folder \"Records/LogIn\".",
					"Sorry",
					MessageBoxButtons::OK
				);
				break;
			default:
				break;
			}
		}
		private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		}


};
}
