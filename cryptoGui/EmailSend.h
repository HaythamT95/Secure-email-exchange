#pragma once
#include "frog.h"
#include <iostream>
#include <cstring>
#include <Windows.h>
#include <tchar.h>
#include "EASendMailObj.tlh"
#include "TESTS.h"
#include "sig.h"

#define FORMOK 0
#define BADEMAILFROM 1
#define BADEMAILTO 2
#define BADKEY 3
#define BADTEXT 4

const int ConnectNormal = 0;
const int ConnectSSLAuto = 1;
const int ConnectSTARTTLS = 2;
const int ConnectDirectSSL = 3;
const int ConnectTryTLS = 4;

char outputCT[65];

char FromArray[125];
char ToArray[125];
char keyArray[125];
char subjectArray[125];
char textArray[16];
char usernameArray[100];
char passwordArray[100];
int w[8] = { 2,7,11,21,42,89,180,354 };

namespace cryptoGui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace EASendMailObjLib;

	/// <summary>
	/// Summary for EmailSend
	/// </summary>
	public ref class EmailSend : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::Form^ otherform;
		   String^ username;
		   String^ pass;
	public:
		EmailSend(System::Windows::Forms::Form^ o)
		{
			otherform = o;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		
		EmailSend(System::Windows::Forms::Form^ o,String^ userName,String^ password)
		{
			otherform = o;
			username = userName;
			pass = password;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EmailSend()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ senderEmailtxt;
	private: System::Windows::Forms::TextBox^ receiverEmailtxt;
	private: System::Windows::Forms::TextBox^ keytxt;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textArea;

	private: System::Windows::Forms::Button^ sendBtn;
	private: System::Windows::Forms::Button^ exitBtn;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ subjectTxt;
	private: System::Windows::Forms::Button^ backToOption;

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->senderEmailtxt = (gcnew System::Windows::Forms::TextBox());
			this->receiverEmailtxt = (gcnew System::Windows::Forms::TextBox());
			this->keytxt = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textArea = (gcnew System::Windows::Forms::TextBox());
			this->sendBtn = (gcnew System::Windows::Forms::Button());
			this->exitBtn = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->subjectTxt = (gcnew System::Windows::Forms::TextBox());
			this->backToOption = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(519, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(175, 46);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Fill Form";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(298, 96);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 29);
			this->label2->TabIndex = 1;
			this->label2->Text = L"From:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->Location = System::Drawing::Point(298, 155);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 29);
			this->label3->TabIndex = 2;
			this->label3->Text = L"To:";
			// 
			// senderEmailtxt
			// 
			this->senderEmailtxt->Location = System::Drawing::Point(473, 96);
			this->senderEmailtxt->Name = L"senderEmailtxt";
			this->senderEmailtxt->Size = System::Drawing::Size(269, 22);
			this->senderEmailtxt->TabIndex = 3;
			// 
			// receiverEmailtxt
			// 
			this->receiverEmailtxt->Location = System::Drawing::Point(473, 161);
			this->receiverEmailtxt->Name = L"receiverEmailtxt";
			this->receiverEmailtxt->Size = System::Drawing::Size(269, 22);
			this->receiverEmailtxt->TabIndex = 4;
			// 
			// keytxt
			// 
			this->keytxt->Location = System::Drawing::Point(473, 226);
			this->keytxt->Name = L"keytxt";
			this->keytxt->Size = System::Drawing::Size(269, 22);
			this->keytxt->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->label4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label4->Location = System::Drawing::Point(298, 219);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(60, 29);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Key:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->label5->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label5->Location = System::Drawing::Point(298, 349);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(66, 29);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Text:";
			// 
			// textArea
			// 
			this->textArea->Location = System::Drawing::Point(473, 349);
			this->textArea->Multiline = true;
			this->textArea->Name = L"textArea";
			this->textArea->Size = System::Drawing::Size(269, 115);
			this->textArea->TabIndex = 8;
			// 
			// sendBtn
			// 
			this->sendBtn->BackColor = System::Drawing::Color::DodgerBlue;
			this->sendBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->sendBtn->Location = System::Drawing::Point(553, 501);
			this->sendBtn->Name = L"sendBtn";
			this->sendBtn->Size = System::Drawing::Size(116, 43);
			this->sendBtn->TabIndex = 9;
			this->sendBtn->Text = L"Send";
			this->sendBtn->UseVisualStyleBackColor = false;
			this->sendBtn->Click += gcnew System::EventHandler(this, &EmailSend::sendBtn_Click);
			// 
			// exitBtn
			// 
			this->exitBtn->BackColor = System::Drawing::Color::Red;
			this->exitBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->exitBtn->Location = System::Drawing::Point(1123, 605);
			this->exitBtn->Name = L"exitBtn";
			this->exitBtn->Size = System::Drawing::Size(96, 46);
			this->exitBtn->TabIndex = 10;
			this->exitBtn->Text = L"Exit";
			this->exitBtn->UseVisualStyleBackColor = false;
			this->exitBtn->Click += gcnew System::EventHandler(this, &EmailSend::exitBtn_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->label6->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label6->Location = System::Drawing::Point(298, 287);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(100, 29);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Subject:";
			// 
			// subjectTxt
			// 
			this->subjectTxt->Location = System::Drawing::Point(473, 293);
			this->subjectTxt->Name = L"subjectTxt";
			this->subjectTxt->Size = System::Drawing::Size(269, 22);
			this->subjectTxt->TabIndex = 12;
			// 
			// backToOption
			// 
			this->backToOption->BackColor = System::Drawing::Color::DodgerBlue;
			this->backToOption->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->backToOption->Location = System::Drawing::Point(62, 605);
			this->backToOption->Name = L"backToOption";
			this->backToOption->Size = System::Drawing::Size(123, 46);
			this->backToOption->TabIndex = 13;
			this->backToOption->Text = L"Back";
			this->backToOption->UseVisualStyleBackColor = false;
			this->backToOption->Click += gcnew System::EventHandler(this, &EmailSend::backToOption_Click);
			// 
			// EmailSend
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(1262, 673);
			this->Controls->Add(this->backToOption);
			this->Controls->Add(this->subjectTxt);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->exitBtn);
			this->Controls->Add(this->sendBtn);
			this->Controls->Add(this->textArea);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->keytxt);
			this->Controls->Add(this->receiverEmailtxt);
			this->Controls->Add(this->senderEmailtxt);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"EmailSend";
			this->Text = L"EmailSend";
			this->Load += gcnew System::EventHandler(this, &EmailSend::EmailSend_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
			public:
				String^ emailFrom;

				String^ emailTo;

				String^ key;

				String^ subject;

				String^ text;
				String^ encryptedKeyMH;

				int failOrPass;
				int r, q, c = 0;
				int * greedyW, * greedyInd;
				int sizeOfgreedy;
				/*******************************************************************/
				long long int createR(long long int b, long long int c) {
					long long a = ((long long int)pow(b, c));
					if (a < (long long int)pow(2, 36) - 1)
						return a % prime;
					else//(a==(long long)Math.pow(2, 36)-1)
						return (createR(b, c / 2) * createR(b, c - c / 2)) % prime;
				}

				long long int invK() {
					for (int x = 1; x < prime - 1; x++)
						if ((k * x) % (prime - 1) == 1)
							return x;
					return 1;
				}

				long long int createS() {
					long long int a = (invK() * (message - z * r1)) % (prime - 1);
					if (a >= 0)
						return a;
					else
						return (a + prime - 1);
				}

				/*sign key using el-gamal signature*/
				void signature()
				{
					//beta = ((long long int)pow(alpha, z)) % prime;
					r1 = createR(alpha, k);
					s = createS();
					encryptedKeyMH += ",";
					encryptedKeyMH += r1.ToString();
					encryptedKeyMH += ",";
					encryptedKeyMH += s.ToString();
					encryptedKeyMH += ")";
					
				}
				void swap(int* xp, int* yp)
				{
					int temp = *xp;
					*xp = *yp;
					*yp = temp;
				}
				void sort(int arr[])
				{
					int i, j;
					for (i = 0; i < 7; i++)
					{
						for (j = 0; j < 8 - i - 1; j++)
						{
							if (arr[j] > arr[j + 1])
							{
								swap(&arr[j], &arr[j + 1]);
							}
						}
					}
				}
				int sum(int a[])
				{
					int i, sum = 0;
					for (i = 0; i < 8; i++)
					{
						sum = sum + a[i];
					}
					return(sum);
				}
				void rvereseArray(int arr[], int start, int end)
				{
					int temp;
					while (start < end)
					{
						temp = arr[start];
						arr[start] = arr[end];
						arr[end] = temp;
						start++;
						end--;
					}
				}
				/*encrypt key using merkle hellman knapsack algorithm*/
				void MerkleHellmanEncrypt(char key_mh[])
				{
					
					int* arrkey = (int*)malloc(strlen(key_mh) * sizeof(int));
					for (int i = 0; i < strlen(key_mh); i++)
					{
						arrkey[i] = key_mh[i] - 0;
						
					}
					int sizeOfarrKey = strlen(key_mh);

					int  i, j;
					int b[8], * a;
					int key;

					int sizeOfKeyBin = 0;
					int* eArrKey;

					eArrKey = (int*)malloc(sizeOfarrKey * sizeof(int));

					for (int sizeArr = 0; sizeArr < sizeOfarrKey; sizeArr++)
					{
						key = arrkey[sizeArr];
						a = (int*)malloc(sizeof(int) * (8));
						for (i = 0; i < 8; i++)
						{
							a[i] = 0;
						}

						q = 881;
						sort(w);

						int tmp = key;

						r = 588;

						for (i = 0; i < 8; i++)
						{
							b[i] = (r * w[i]) % q;
						}

						for (i = 0; key > 0; i++)
						{
							a[i] = key % 2;
							key /= 2;
						}
						rvereseArray(a, 0, 7);

						for (i = 0, j = 0; j < 8; i++, j++) {
							if (i == 8)
								i = 0;
							c += (a[j] * b[i]);
						}

						eArrKey[sizeArr] = c;
						c = 0;
						free(a);
					}

					encryptedKeyMH = "(";
					for ( i = 0; i < sizeOfarrKey; i++)
					{
						encryptedKeyMH += eArrKey[i].ToString();
						encryptedKeyMH+="x";
					}
					int x = eArrKey[0];
					int sum = 0;
					while (x != 0)
					{
						sum += x % 10;
						x /= 10;
					}

					encryptedKeyMH+=sum.ToString();
					message = sum;
					signature();
				}
				int modInverse()
				{
					for (int x = 1; x < q; x++)
						if (((r % q) * (x % q)) % q == 1) {
							return x;
						}
					return 0;
				}
				void printValues(int A[], int size) {
					greedyW = (int*)malloc(size * sizeof(int));
					greedyInd = (int*)malloc(size * sizeof(int));
					sizeOfgreedy = size;
					for (int i = 0; i < size; i++) {
						greedyW[i] = A[i];
					}
					printf("\n");
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
				/*******************************************************************/
				/* handle user input from screen 
				call encryption methods
				*/
				int UserInput() {
					int keyAsNumber;

					if ((!emailFrom->Contains("@hotmail.com") && !emailFrom->Contains("@gmail.com")) || emailFrom->Equals("")) {
						return BADEMAILFROM;
					}
					if ((!emailFrom->Contains("@hotmail.com") && !emailTo->Contains("@gmail.com")) || emailTo->Equals("")) {
						return BADEMAILTO;
					}
				
					if (text->Length > 15 || text->Length == 0) {
						return BADTEXT;
					}
					char str[125];
					char input[16];
					char outputBuffer[65];
					size_t keyLen;

					sprintf(str, "%s", key);
					keyLen = strlen(str);
					if(keyLen<5 || keyLen>125)
						return BADKEY;

					sprintf(input, "%s", text);
					
					/*Filling the parameters*/
					/*encrypt(msg&key) and send email*/
					encrypt(input, str);
					MerkleHellmanEncrypt(str);

					String^ s = gcnew String(outputCT);
					MessageBox::Show(s);
					
					sprintf(FromArray, "%s", emailFrom);
					sprintf(ToArray, "%s", emailTo);
					sprintf(keyArray, "%s", encryptedKeyMH);
					sprintf(subjectArray, "%s", subject);
					sprintf(usernameArray, "%s", username);
					sprintf(passwordArray, "%s", pass);
					SendMails();
					
					return FORMOK;
				}

				/*input: text and key
				* output: encrypted text using frog in cfb mode
				*/
				void encrypt(char input[],char key[])
				{
					cipherInstance cipher;
					keyInstance keyInst;
					int keyLen = 16, i = 0, j, k, nTests, extraBytes;
					tBuffer IB, PT, CT, CTLast, CV, OP, PTLast, OB;
					BYTE keyMaterial[MAX_KEY_SIZE], IV[BLOCK_SIZE];
					char hexIV[MAX_IV_SIZE * 2 + 1], hexKeyMaterial[100];
					unsigned char IVarr[17] = { '0','0','0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0' ,'0','0','0','0','\0'};

					size_t keyEncryptedLen = strlen(key);
					
					for (i = 0; i < 16; i++)
					{
						if (i < keyEncryptedLen)
							IVarr[i] =(unsigned char) key[i];
					}					

					memcpy(keyMaterial, key, MAX_KEY_SIZE);
					memcpy(IV, IVarr, BLOCK_SIZE);
					binaryToHexString(IV, hexIV, MAX_IV_SIZE);
					memcpy(CV, IV, BLOCK_SIZE);
					memcpy(IB, IV, BLOCK_SIZE);

					binaryToHexString(IV, hexIV, MAX_IV_SIZE);
					cipherInit(&cipher, MODE_CFB1, hexIV);

					binaryToHexString(keyMaterial, hexKeyMaterial, keyLen);
					makeKey(&keyInst, DIR_ENCRYPT, keyLen * 8, hexKeyMaterial);

					outputBinary("CV", CV, BLOCK_SIZE);
					memcpy(PT, input, BLOCK_SIZE);
					outputBinary("PT", PT, BLOCK_SIZE);

					for (i = 0; i < 400; i++) {
						binaryToHexString(keyMaterial, hexKeyMaterial, keyLen);
						makeKey(&keyInst, DIR_ENCRYPT, keyLen * 8, hexKeyMaterial);

						for (j = 0; j < 10000; j++) {
							for (k = 0; k < BLOCK_SIZE; k++)
								IB[k] = PT[k] ^ CV[k];

							blockEncrypt(&cipher, &keyInst, IB, BLOCK_SIZE * 8, CT);

							if (j == 0)
								memcpy(PT, CV, BLOCK_SIZE);
							else
								memcpy(PT, CTLast, BLOCK_SIZE);

							memcpy(CV, CT, BLOCK_SIZE);
							if (j < 9999)
								memcpy(CTLast, CT, BLOCK_SIZE);
						}
						for (k = 0; k < BLOCK_SIZE; k++)
							keyMaterial[k] ^= CT[k];
						/* Add extra key material if required */
						if (keyLen > 16) {
							for (extraBytes = 0, k = BLOCK_SIZE; k < keyLen; k++, extraBytes++)
								keyMaterial[k] ^= CTLast[extraBytes];
						}
						memcpy(PT, CTLast, BLOCK_SIZE);
						memcpy(CV, CT, BLOCK_SIZE);
					}
					binaryToHexString(CT, outputCT, BLOCK_SIZE);
				}

				/*convert string to BSTR (used for email protocol sending)*/
				inline BSTR ConvertStringToBSTR(const char* pSrc)
				{
					if (!pSrc) return NULL;

					DWORD cwch;

					BSTR wsOut(NULL);

					if (cwch = ::MultiByteToWideChar(CP_ACP, 0, pSrc,
						-1, NULL, 0))//get size minus NULL terminator
					{
						cwch--;
						wsOut = ::SysAllocStringLen(NULL, cwch);

						if (wsOut)
						{
							if (!::MultiByteToWideChar(CP_ACP,
								0, pSrc, -1, wsOut, cwch))
							{
								if (ERROR_INSUFFICIENT_BUFFER == ::GetLastError())
									return wsOut;
								::SysFreeString(wsOut);//must clean up
								wsOut = NULL;
							}
						}

					};

					return wsOut;
				};

				/*send mails protocol*/
				void SendMails() {
					::CoInitialize(NULL);

					IMailPtr oSmtp = NULL;
					oSmtp.CreateInstance(__uuidof(EASendMailObjLib::Mail));
					oSmtp->LicenseCode = _T("TryIt");

					// Set your sender email address
					oSmtp->FromAddr = ConvertStringToBSTR(FromArray);
					
					// Add recipient email address
					oSmtp->AddRecipientEx(ConvertStringToBSTR(ToArray), 0);

					// Set email subject
					oSmtp->Subject = ConvertStringToBSTR(subjectArray);

					// Set email body
					oSmtp->BodyText = _T("Text: ");
					oSmtp->BodyText += ConvertStringToBSTR(outputCT);
					oSmtp->BodyText += _T("\nSignature: ");
					oSmtp->BodyText += ConvertStringToBSTR(keyArray);

					// Your SMTP server address
					if(emailFrom->Contains("@gmail.com"))
						oSmtp->ServerAddr = _T("smtp.gmail.com");
					if(emailFrom->Contains("@hotmail.com"))
						oSmtp->ServerAddr = _T("smtp.office365.com");

					// User and password for ESMTP authentication, if your server doesn't
					// require User authentication, please remove the following codes.
					oSmtp->UserName = ConvertStringToBSTR(usernameArray);
					oSmtp->Password = ConvertStringToBSTR(passwordArray);

					// Most mordern SMTP servers require SSL/TLS connection now.
					// ConnectTryTLS means if server supports SSL/TLS, SSL/TLS will be used automatically.
					oSmtp->ConnectType = ConnectTryTLS;

					// If your SMTP server uses 587 port
					// oSmtp->ServerPort = 587;

					// If your SMTP server requires SSL/TLS connection on 25/587/465 port
					oSmtp->ServerPort = 587; // 25 or 587 or 465
					oSmtp->ConnectType = ConnectSSLAuto;

					_tprintf(_T("Start to send email ...\r\n"));

					if (oSmtp->SendMail() == 0)
					{
						_tprintf(_T("email was sent successfully!\r\n"));
					}
					else
					{
						_tprintf(_T("failed to send email with the following error: %s\r\n"),
							(const TCHAR*)oSmtp->GetLastErrDescription());
					}
				}
				

	private: System::Void exitBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void sendBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		char* text_char_array;
		
		emailFrom = senderEmailtxt->Text;

		emailTo = receiverEmailtxt->Text;

		key = keytxt->Text;

		subject = subjectTxt->Text;

		text = textArea->Text;

		failOrPass = UserInput();

		switch (failOrPass)
		{
		case 0:
			MessageBox::Show("Mail was send successfully");
			break;
		case 1:
			MessageBox::Show("Something is wrong with your email, Try Again");
			break;
		case 2:
			MessageBox::Show("Something is wrong with the email you are sending to, Try Again");
			break;
		case 3:
			MessageBox::Show("Please enter a key with length between [5-125]");
			break;
		case 4:
			MessageBox::Show("Please enter a text with length between [1-15]");
			break;
		}
		
	}
	private: System::Void EmailSend_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void backToOption_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		otherform->Show();
	}
};

}
