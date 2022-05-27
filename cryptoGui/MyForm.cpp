#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

int main(array <String^>^ args)
{

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    cryptoGui::MyForm form;
    Application::Run(% form);
}