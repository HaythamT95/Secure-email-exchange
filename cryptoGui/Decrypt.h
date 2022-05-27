#pragma once
#include <stdio.h>
#include "sig.h"
int paramArray[2];
namespace cryptoGui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Decrypt
	/// </summary>
	public ref class Decrypt : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::Form^ otherform;
		   String^ parameters;
		   String^ msgToDec;
		   String^ keyToDec;
	public:
		Decrypt(System::Windows::Forms::Form^ o)
		{
			otherform = o;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Decrypt()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	protected:
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ Paramtxt;
	private: System::Windows::Forms::TextBox^ msgtoDectxt;
	private: System::Windows::Forms::Button^ verifybtn;
	private: System::Windows::Forms::Button^ decbtn;




	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ ExitApp;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ keyDectxt;


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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Paramtxt = (gcnew System::Windows::Forms::TextBox());
			this->msgtoDectxt = (gcnew System::Windows::Forms::TextBox());
			this->verifybtn = (gcnew System::Windows::Forms::Button());
			this->decbtn = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->ExitApp = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->keyDectxt = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(411, 27);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(380, 37);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Enter message to decrypt";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(341, 115);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(110, 24);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Parameters:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(341, 240);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 24);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Text:";
			// 
			// Paramtxt
			// 
			this->Paramtxt->Location = System::Drawing::Point(490, 122);
			this->Paramtxt->Name = L"Paramtxt";
			this->Paramtxt->Size = System::Drawing::Size(294, 22);
			this->Paramtxt->TabIndex = 4;
			// 
			// msgtoDectxt
			// 
			this->msgtoDectxt->Location = System::Drawing::Point(490, 240);
			this->msgtoDectxt->Multiline = true;
			this->msgtoDectxt->Name = L"msgtoDectxt";
			this->msgtoDectxt->Size = System::Drawing::Size(294, 107);
			this->msgtoDectxt->TabIndex = 5;
			// 
			// verifybtn
			// 
			this->verifybtn->BackColor = System::Drawing::Color::DodgerBlue;
			this->verifybtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->verifybtn->ForeColor = System::Drawing::Color::Black;
			this->verifybtn->Location = System::Drawing::Point(562, 373);
			this->verifybtn->Name = L"verifybtn";
			this->verifybtn->Size = System::Drawing::Size(136, 49);
			this->verifybtn->TabIndex = 6;
			this->verifybtn->Text = L"Verify";
			this->verifybtn->UseVisualStyleBackColor = false;
			this->verifybtn->Click += gcnew System::EventHandler(this, &Decrypt::verifybtn_Click);
			// 
			// decbtn
			// 
			this->decbtn->BackColor = System::Drawing::Color::DodgerBlue;
			this->decbtn->Enabled = false;
			this->decbtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->decbtn->ForeColor = System::Drawing::Color::Black;
			this->decbtn->Location = System::Drawing::Point(562, 443);
			this->decbtn->Name = L"decbtn";
			this->decbtn->Size = System::Drawing::Size(136, 46);
			this->decbtn->TabIndex = 7;
			this->decbtn->Text = L"Decrypt";
			this->decbtn->UseVisualStyleBackColor = false;
			this->decbtn->Click += gcnew System::EventHandler(this, &Decrypt::decbtn_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::DodgerBlue;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->button3->ForeColor = System::Drawing::Color::Black;
			this->button3->Location = System::Drawing::Point(68, 581);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(121, 53);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Back";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Decrypt::button3_Click);
			// 
			// ExitApp
			// 
			this->ExitApp->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->ExitApp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->ExitApp->ForeColor = System::Drawing::Color::Black;
			this->ExitApp->Location = System::Drawing::Point(1089, 581);
			this->ExitApp->Name = L"ExitApp";
			this->ExitApp->Size = System::Drawing::Size(127, 53);
			this->ExitApp->TabIndex = 9;
			this->ExitApp->Text = L"Exit";
			this->ExitApp->UseVisualStyleBackColor = false;
			this->ExitApp->Click += gcnew System::EventHandler(this, &Decrypt::ExitApp_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->label4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label4->Location = System::Drawing::Point(346, 181);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(47, 24);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Key:";
			// 
			// keyDectxt
			// 
			this->keyDectxt->Location = System::Drawing::Point(490, 181);
			this->keyDectxt->Name = L"keyDectxt";
			this->keyDectxt->Size = System::Drawing::Size(294, 22);
			this->keyDectxt->TabIndex = 11;
			// 
			// Decrypt
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(1262, 673);
			this->Controls->Add(this->keyDectxt);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->ExitApp);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->decbtn);
			this->Controls->Add(this->verifybtn);
			this->Controls->Add(this->msgtoDectxt);
			this->Controls->Add(this->Paramtxt);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->ForeColor = System::Drawing::Color::Olive;
			this->Name = L"Decrypt";
			this->Text = L"Decrypt";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public:
			char* decryptedKey;
			int* decKey,lenDecKey;
			int r=588, q=881, c = 0;
			int * greedyW, * greedyInd;
			int sizeOfgreedy;
			void printValues(int A[], int size) {
				greedyW = (int*)malloc(size * sizeof(int));
				greedyInd = (int*)malloc(size * sizeof(int));
				sizeOfgreedy = size;
				for (int i = 0; i < size; i++) {
					greedyW[i] = A[i];
				}
				
			}

			void subset_sum(int s[], int t[], int s_size, int t_size, int sum, int ite, int const target_sum) {
				if (target_sum == sum) {
					printValues(t, t_size);
					//subset_sum(s, t, s_size, t_size - 1, sum - s[ite], ite + 1, target_sum);
					return;
				}
				else {
					for (int i = ite; i < s_size; i++) {
						t[t_size] = s[i];
						subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
					}
				}
			}

			void generateSubsets(int s[], int size, int target_sum) {
				int* tuplet_vector = (int*)malloc(size * sizeof(int));
				subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum);
				free(tuplet_vector);
			}
			int modInverse()
			{
				for (int x = 1; x < q; x++)
					if (((r % q) * (x % q)) % q == 1) {
						
						return x;
					}
				return 0;
			}

			/* decrypt key using merkle hellman algorithm*/
		void MHdecryption(String^ keyToDec)
		{
			int* realMsg = (int*)malloc((lenDecKey-1) * sizeof(int));

			for (int i = 0; i < lenDecKey-1; i++)
			{
				c = decKey[i];
				int x;
				int msg = 0;
				x = c * modInverse() % q;
				
				int size = sizeof(w) / sizeof(w[0]);
				

				generateSubsets(w, size, x);
				
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < sizeOfgreedy; j++)
						if (w[i] == greedyW[j])
							greedyInd[j] = i + 1;
				}

				for (int i = 0; i < sizeOfgreedy; i++)
				{

					msg += pow(2, 8 - greedyInd[i]);
				}
				realMsg[i] = msg;
			}
			decryptedKey = (char*)malloc((lenDecKey) * sizeof(char));
			
			int i;
			for ( i = 0; i < lenDecKey-1; i++)
			{
				decryptedKey[i] = realMsg[i] + 0;
			}
			decryptedKey[i] = '\0';
		}

		/*input: encrypted text
		* output : original text using decryption with frog in cfb mode 
		*/
		void decryptFrogTxt(String^ msgToDec)
		{
			cipherInstance cipher;
			keyInstance keyInst;
			int keyLen = 16, i = 0, j, k, nTests, extraBytes;
			tBuffer IB, PT, CT, CTLast, CV, OP, PTLast, OB;
			BYTE keyMaterial[MAX_KEY_SIZE], IV[BLOCK_SIZE];
			char hexIV[MAX_IV_SIZE * 2 + 1], hexKeyMaterial[100];
			unsigned char IVarr[17] = { '0','0','0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0','0','0','\0'};

			char inputmsg[33],keyToUse[MAX_KEY_SIZE];
			char outputBuffer[65];
			char txtToDisplay[16];
			
			sprintf(inputmsg, "%s", msgToDec);

			size_t keyDecryptedLen = strlen(decryptedKey);
			for (i = 0; i < keyDecryptedLen; i++)
			{
				IVarr[i] = decryptedKey[i];
			}

			memcpy(keyMaterial, decryptedKey, MAX_KEY_SIZE);
			memcpy(IV, IVarr, BLOCK_SIZE);
			binaryToHexString(IV, hexIV, MAX_IV_SIZE);
			cipherInit(&cipher, MODE_CFB1, hexIV);
			
			memcpy(CV, IV, BLOCK_SIZE);
			outputBinary("KEY", (BYTE*)keyMaterial, keyLen);
			outputBinary("CV", CV, BLOCK_SIZE);
			
			char asd[33] ;
			char temp;
			for (int i = 0; i < 32 / 2; i++) {
				temp = inputmsg[i];
				inputmsg[i] = inputmsg[32 - i - 1];
				inputmsg[32 - i - 1] = temp;
			}
			for (int i = 0; i < 32; i += 2)
			{
				temp = inputmsg[i];
				inputmsg[i] = inputmsg[i + 1];
				inputmsg[i + 1] = temp;
			}
			hexStringToBinary(inputmsg, CT, 16);
			outputBinary("CT", CT, BLOCK_SIZE);

			for (i = 0; i < 400; i++) {
				binaryToHexString(keyMaterial, hexKeyMaterial, keyLen);
				makeKey(&keyInst, DIR_DECRYPT, keyLen * 8, hexKeyMaterial);

				for (j = 0; j < 10000; j++) {
					memcpy(IB, CT, BLOCK_SIZE);

					blockDecrypt(&cipher, &keyInst, IB, BLOCK_SIZE * 8, OB);

					for (k = 0; k < BLOCK_SIZE; k++)
						PT[k] = OB[k] ^ CV[k];

					memcpy(CV, CT, BLOCK_SIZE);
					if (j < 9999)
						memcpy(CT, PT, BLOCK_SIZE);

					if (j < 9999)
						memcpy(PTLast, PT, BLOCK_SIZE);
				}
				for (k = 0; k < BLOCK_SIZE; k++)
					keyMaterial[k] ^= PT[k];
				/* Add extra key material if required */
				if (keyLen > 16) {
					for (extraBytes = 0, k = BLOCK_SIZE; k < keyLen; k++, extraBytes++)
						keyMaterial[k] ^= PTLast[extraBytes];
				}
				memcpy(CV, CT, BLOCK_SIZE);
				memcpy(CT, PT, BLOCK_SIZE);
			}
			outputBinary("PT", PT, BLOCK_SIZE);

			sprintf(txtToDisplay, "%s", PT);
			String^ s = gcnew String(txtToDisplay);
			MessageBox::Show(s);
		}
		
		long long int v1(long long int b, long long int c, long long int d, long long int e) {
			
			long long int a = (((long long int)pow(b, c)) * ((long long int)(pow(d, e))));
			if (a < (long long int)pow(2, 36) - 1)
				return a % prime;
			else//(a==(long long)Math.pow(2, 36)-1)
				return (v1(b, c / 2, d, e / 2) * v1(b, c - c / 2, d, e - e / 2)) % prime;
		}

		long long int v2(long long int b, long long int c) {
			long long int a = ((long long int)pow(b, c));
			if (a < (long long int)pow(2, 36) - 1)
				return a % prime;
			else//(a==(long long)Math.pow(2, 36)-1)
				return (v2(b, c / 2) * v2(b, c - c / 2)) % prime;
		}

		/*verify message using el-gamal signature*/
		void verified(int x,int y) {

			if (v1(beta, x, x, y) == v2(alpha, message)) {
				MessageBox::Show("Signature verified");
				decbtn->Enabled = true;
			}
			else {
				MessageBox::Show("Signature missmatch");
			}
		}
		
		private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Hide();
			otherform->Show();
		}
		
		private: System::Void verifybtn_Click(System::Object^ sender, System::EventArgs^ e) {
			parameters = Paramtxt->Text;
			msgToDec = msgtoDectxt->Text;
			keyToDec = keyDectxt->Text;
			
			if (parameters->Equals("") || msgToDec->Equals("") || keyToDec->Equals(""))
			{
				MessageBox::Show("Please fill in all information");
				return;
			}
			if (!parameters->Contains(","))
			{
				MessageBox::Show("Enter parameters correctly");
				return;
			}
			array<String^>^ mySplitString = parameters->Split(',');
			if (mySplitString->Length > 2)
			{
				MessageBox::Show("Wrong input");
				return;
			}
			int i = 0;
			for each (String^ var in mySplitString)
			{
				paramArray[i++]= Convert::ToInt32(var);
			}

			mySplitString = keyToDec->Split('x');
			lenDecKey = mySplitString->Length;
			message = Convert::ToInt32(mySplitString[lenDecKey -1]);
			decKey = (int*)malloc(sizeof(int) * (lenDecKey - 1));
			for ( i = 0; i < lenDecKey - 1; i++)
			{
				decKey[i]= Convert::ToInt32(mySplitString[i]);
			}
			/*check if param equal to elgamal verify then enable decrypt button*/
			verified(paramArray[0], paramArray[1]);
		}
		private: System::Void ExitApp_Click(System::Object^ sender, System::EventArgs^ e) {
			Application::Exit();
		}
		private: System::Void decbtn_Click(System::Object^ sender, System::EventArgs^ e) {
			if (decbtn->Enabled == true)
			{
				/*decrypt key using merkle-hellman*/
				MHdecryption(keyToDec);
				/*decrypt text using frog in cfb mode*/
				decryptFrogTxt(msgToDec);
			}
		}
};
}
