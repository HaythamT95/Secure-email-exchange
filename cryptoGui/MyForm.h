#pragma once
#include "EncryptOrDecrypt.h"
#include "sig.h"

namespace cryptoGui {

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
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ goToFormBtn;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ userEmailtxt;
	private: System::Windows::Forms::TextBox^ userPasstxt;



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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->goToFormBtn = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->userEmailtxt = (gcnew System::Windows::Forms::TextBox());
			this->userPasstxt = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(274, 59);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(666, 46);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Welcome to secure email exchange ";
			// 
			// goToFormBtn
			// 
			this->goToFormBtn->BackColor = System::Drawing::Color::DodgerBlue;
			this->goToFormBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->goToFormBtn->Location = System::Drawing::Point(535, 528);
			this->goToFormBtn->Name = L"goToFormBtn";
			this->goToFormBtn->Size = System::Drawing::Size(159, 63);
			this->goToFormBtn->TabIndex = 1;
			this->goToFormBtn->Text = L"Get Started";
			this->goToFormBtn->UseVisualStyleBackColor = false;
			this->goToFormBtn->Click += gcnew System::EventHandler(this, &MyForm::goToFormBtn_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(317, 184);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 29);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Email";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->Location = System::Drawing::Point(317, 286);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(120, 29);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Password";
			// 
			// userEmailtxt
			// 
			this->userEmailtxt->Location = System::Drawing::Point(483, 184);
			this->userEmailtxt->Name = L"userEmailtxt";
			this->userEmailtxt->Size = System::Drawing::Size(269, 22);
			this->userEmailtxt->TabIndex = 4;
			// 
			// userPasstxt
			// 
			this->userPasstxt->Location = System::Drawing::Point(483, 292);
			this->userPasstxt->Name = L"userPasstxt";
			this->userPasstxt->PasswordChar = '*';
			this->userPasstxt->Size = System::Drawing::Size(269, 22);
			this->userPasstxt->TabIndex = 5;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(1262, 673);
			this->Controls->Add(this->userPasstxt);
			this->Controls->Add(this->userEmailtxt);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->goToFormBtn);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public:
			/*calculate beta given secret integer z and prime and primitive root alpha
			* for el-gamal signature
			*/
			void calcBeta()
			{
				beta = ((long long int)pow(alpha, z)) % prime;
			}

		private: System::Void goToFormBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ userName = userEmailtxt->Text;
			String^ password = userPasstxt->Text;
			if (userName->Equals("") || password->Equals(""))
			{
				MessageBox::Show("Please fill in all information");
				return;
			}
			if (!userName->Contains("@gmail.com") && !userName->Contains("@hotmail.com") && !userName->Contains("@outlook.com"))
			{
				MessageBox::Show("Please enter correct address");
				return;
			}
			calcBeta();
			this->Hide();
			EncryptOrDecrypt^ EOD = gcnew EncryptOrDecrypt(this,userName,password);
			EOD->Show();
		}
		private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		}
	};
}
