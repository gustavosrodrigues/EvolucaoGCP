//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <IniFiles.hpp>
#include "Principal_Launcher.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//	Colocar o arquivo GCPLauncher.exe na pasta raiz do GCP.

//    Determina a pasta GCP
	String exeFile = Application->ExeName;
	String exePath = ExtractFilePath(exeFile);
//	exePath = exePath.SubString(1,exePath.Length()-2);

//	Abre o arquivo lastversion.txt
	String xx = exePath + "GCPLauncher.ini";
	TIniFile *ini = new TIniFile(xx);

//	A versao padrao é a 3.7
	AnsiString ultima_versao = ini->ReadString("Principal", "versao", "3.7");

	AnsiString nome_arq_GCP = exePath + "\\" + ultima_versao + "\\GCP.exe";

	try {
        ShellExecute(Handle, "open", nome_arq_GCP.c_str(), 0, 0,
		SW_NORMAL);
	} catch (const Exception &e) {
		Application->MessageBox(L"GCP não está instalado corretamente. " ,L"Erro",0);
	}

	delete ini;
	exit(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormActivate(TObject *Sender)
{
	Button1Click(this);
}
//---------------------------------------------------------------------------
