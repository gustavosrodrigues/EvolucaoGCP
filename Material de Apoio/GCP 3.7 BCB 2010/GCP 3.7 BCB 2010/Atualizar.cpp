//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <IniFiles.hpp>
#include "Principal.h"
#include "Atualizar.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IdBaseComponent"
#pragma link "IdComponent"
#pragma link "IdHTTP"
#pragma link "IdTCPClient"
#pragma link "IdTCPConnection"
#pragma resource "*.dfm"
TFormAtualizar *FormAtualizar;
bool houve_erro;
bool ja_verificou_gcp;
bool ja_verificou_regras;

AnsiString endereco_base = "http://cc.alegrete.unipampa.edu.br/gcp/";

//---------------------------------------------------------------------------
__fastcall TFormAtualizar::TFormAtualizar(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormAtualizar::Button1Click(TObject *Sender)
{

	ja_verificou_gcp = true;

//	----- Faz o download da versao mais atualizada do GCP, de acordo com o arquivo lastversion.txt -----

//	Determina a pasta GCP, que est� uma acima do arquivo execut�vel
	String exeFile = Application->ExeName;
	String exePath = ExtractFilePath(exeFile);
	exePath = exePath.SubString(1,exePath.Length()-2);
	String GCPPath = ExtractFilePath(exePath);

//	AnsiString endereco_base = "http://gcp.bugs3.com/gcp/";

	TFileStream* fs = new TFileStream(GCPPath+"lastversion.txt", fmCreate);
//    Carrega e analisa o arquivo da versao lastversion.txt
	try {

		AnsiString endereco_lastversion = endereco_base + "lastversion.txt";
		Memo1->Lines->Add("Fazendo download do arquivo " + endereco_lastversion + " para a pasta " + GCPPath + " ...");


		IdHTTP1->Get(endereco_lastversion, fs);
		delete fs;

		String xx = GCPPath + "lastversion.txt";
		TIniFile *ini = new TIniFile(xx);

		AnsiString ultima_versao = ini->ReadString("Principal", "ultima_versao", "erro");
		Memo1->Lines->Add("A vers�o mais atualizado do GCP � a " + ultima_versao);
		Memo1->Lines->Add("A vers�o instalada do GCP � a " + versao);

		if (versao!=ultima_versao) {

	//	Carrega os arquivos da ultima versao do GCP
		 Memo1->Lines->Add("Atualizando para a vers�o " + ultima_versao + "...");

	//    Cria o diretorio no disco local
		AnsiString OutputFolder = GCPPath + ultima_versao;
		if (CreateDirectory(OutputFolder.c_str(), NULL) ||
		ERROR_ALREADY_EXISTS == GetLastError())
		{
			AnsiString endereco_pasta_lastversion = endereco_base + "versions/" + ultima_versao;

			int nro_arquivos = ini->ReadInteger("Principal", "nro_arquivos", 0);
			houve_erro=false;
			for (int i = 0; i < nro_arquivos; i++) {
				 String file_name = ini->ReadString("Download", "arquivo"+IntToStr(i+1), "erro");
				 TFileStream* fc = new TFileStream(GCPPath + ultima_versao + "\\"+file_name, fmCreate);
				 AnsiString endereco_arquivo = endereco_pasta_lastversion + "/" + file_name;
				 Memo1->Lines->Add("Fazendo download do arquivo " + endereco_arquivo + " para a pasta " + GCPPath+ultima_versao + " ...");
				 try {
					IdHTTP1->Get(endereco_arquivo, fc);
				 }   catch (const Exception &e) {
						Memo1->Lines->Add("Erro: " + e.Message);
						houve_erro=true;
					}
				 delete fc;
			}
			if (!houve_erro) {
				Memo1->Lines->Add("Atualiza��o conclu�da com sucesso.");
//				Redirecionamento do Launcher  ---------------------------------
				AnsiString gcplauncherini = GCPPath +  "GCPLauncher.ini";
				TIniFile *launcher = new TIniFile(gcplauncherini);
				launcher->WriteString("Principal", "versao", ultima_versao);
				delete launcher;
//				 Perguntar se deseja reiniciar
				if (Application->MessageBoxA(L"� preciso reiniciar o GCP para que a atualiza��o tenha efeito.\n Deseja reiniciar agora?",L"Aten��o",MB_YESNO)==ID_YES) {
					AnsiString nome_arq_GCPLauncher = GCPPath + "\\GCPLauncher.exe";
					ShellExecute(Handle, "open", nome_arq_GCPLauncher.c_str(), 0, 0,
					SW_NORMAL);
					exit(0);
				}
			}
			else {
				 Memo1->Lines->Add("Atualiza��o n�o pode ser conclu�da.");
			}

		}
		else
		{
			Memo1->Lines->Add("Erro ao criar o diret�rio " + OutputFolder + ".");
			delete ini;
		}
		}
		else
			Memo1->Lines->Add("Esta j� � a vers�o mais atualizada do GCP. Nada a fazer.");

		delete ini;
	}

	catch (const Exception &e) {
			Memo1->Lines->Add("Erro: " + e.Message);
			delete fs;
	}


}
//---------------------------------------------------------------------------
void __fastcall TFormAtualizar::IdHTTP1WorkBegin(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCountMax)

{
	ProgressBar1->Position = 0;
	ProgressBar1->Max = AWorkCountMax;
}
//---------------------------------------------------------------------------
void __fastcall TFormAtualizar::IdHTTP1Work(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCount)

{
	ProgressBar1->Position = AWorkCount;
	Application->ProcessMessages();
}
//---------------------------------------------------------------------------
void __fastcall TFormAtualizar::Button2Click(TObject *Sender)
{
	IdHTTP1->Disconnect();
	houve_erro=true;
}
//---------------------------------------------------------------------------
void __fastcall TFormAtualizar::IdHTTP1WorkEnd(TObject *ASender, TWorkMode AWorkMode)

{
	if (ProgressBar1->Position==ProgressBar1->Max) {
		  Memo1->Lines->Add("Download conclu�do.");
	}
	else
		Memo1->Lines->Add("Download cancelado.");
}
//---------------------------------------------------------------------------
void __fastcall TFormAtualizar::Button3Click(TObject *Sender)
{

	FormAtualizar->Close();

}
//---------------------------------------------------------------------------

void __fastcall TFormAtualizar::FormShow(TObject *Sender)
{
	ja_verificou_gcp=false;

}
//---------------------------------------------------------------------------

void __fastcall TFormAtualizar::FormActivate(TObject *Sender)
{
	if (!ja_verificou_gcp) {
          Button4Click(this);
		  Button1Click(this);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormAtualizar::Button4Click(TObject *Sender)
{

	ja_verificou_regras = true;

//	----- Faz o download das regras do GCP, de acordo com o arquivo lastversion.txt -----

//	Determina a pasta GCP, que est� uma acima do arquivo execut�vel
	String exeFile = Application->ExeName;
	String exePath = ExtractFilePath(exeFile);
	exePath = exePath.SubString(1,exePath.Length()-2);
	String GCPPath = ExtractFilePath(exePath);

//	AnsiString endereco_base = "http://gcp.bugs3.com/gcp/";
	Memo1->Lines->Add("Iniciando atualiza��o das regras.");

	TFileStream* fs = new TFileStream(GCPPath+"lastversion.txt", fmCreate);
//    Carrega e analisa o arquivo da versao lastversion.txt
	try {

		AnsiString endereco_lastversion = endereco_base + "lastversion.txt";
		Memo1->Lines->Add("Fazendo download do arquivo " + endereco_lastversion + " para a pasta " + GCPPath + " ...");

//		TFileStream* fs = new TFileStream(GCPPath+"lastversion.txt", fmCreate);
		IdHTTP1->Get(endereco_lastversion, fs);
		delete fs;

		String xx = GCPPath + "lastversion.txt";
		TIniFile *ini = new TIniFile(xx);

		int nro_regras = ini->ReadInteger("Principal", "nro_arquivos_regras", 0);


	//    Cria o diretorio no disco local
		AnsiString OutputFolder = GCPPath + "\\regras";
		if (CreateDirectory(OutputFolder.c_str(), NULL) ||
		ERROR_ALREADY_EXISTS == GetLastError())
		{
			AnsiString endereco_pasta_regras = endereco_base + "regras/";

//			int nro_arquivos = ini->ReadInteger("Principal", "nro_arquivos", 0);
			houve_erro=false;
			for (int i = 0; i < nro_regras; i++) {
				 String file_name = ini->ReadString("Regras", "arquivo"+IntToStr(i+1), "erro");
				 TFileStream* fc = new TFileStream(GCPPath  + "regras\\"+file_name, fmCreate);
				 AnsiString endereco_arquivo = endereco_pasta_regras + file_name;
				 Memo1->Lines->Add("Fazendo download do arquivo " + endereco_arquivo + " para a pasta " + GCPPath+"regras" + " ...");
				 try {
					IdHTTP1->Get(endereco_arquivo, fc);
				 }   catch (const Exception &e) {
						Memo1->Lines->Add("Erro: " + e.Message);
						houve_erro=true;
					}
				 delete fc;
			}
			if (!houve_erro) {
				Memo1->Lines->Add("Atualiza��o das regras conclu�da com sucesso.");
//
			}
			else {
				 Memo1->Lines->Add("Atualiza��o das regras n�o pode ser conclu�da.");
			}

		}
		else
		{
			Memo1->Lines->Add("Erro ao criar o diret�rio " + OutputFolder + ".");
			delete ini;
		}
		delete ini;
	}

	catch (const Exception &e) {
			Memo1->Lines->Add("Erro: " + e.Message);
			delete fs;

	}
}
//---------------------------------------------------------------------------

void __fastcall TFormAtualizar::Button5Click(TObject *Sender)
{

//    Verifica se h� conectividade e, caso positivo, verifica se h� nova vers�o dispon�vel para downlaod

//	Determina a pasta local do GCP, que est� uma acima do arquivo execut�vel
	String exeFile = Application->ExeName;
	String exePath = ExtractFilePath(exeFile);
	exePath = exePath.SubString(1,exePath.Length()-2);
	String GCPPath = ExtractFilePath(exePath);

//	AnsiString endereco_base = "http://gcp.bugs3.com/gcp/";

	TFileStream* fs = new TFileStream(GCPPath+"lastversion.txt", fmCreate);
//    Carrega e analisa o arquivo da versao lastversion.txt
	try {

		AnsiString endereco_lastversion = endereco_base + "lastversion.txt";
		Memo1->Lines->Add("Fazendo download do arquivo " + endereco_lastversion + " para a pasta " + GCPPath + " ...");


		IdHTTP1->Get(endereco_lastversion, fs);
		delete fs;

		String xx = GCPPath + "lastversion.txt";
		TIniFile *ini = new TIniFile(xx);

		AnsiString ultima_versao = ini->ReadString("Principal", "ultima_versao", "erro");
		Memo1->Lines->Add("A vers�o mais atualizado do GCP � a " + ultima_versao);
		Memo1->Lines->Add("A vers�o instalada do GCP � a " + versao);

		delete ini;

		if (versao!=ultima_versao) {

			if (Application->MessageBoxA(L"Existe uma vers�o mais nova do GCP dispon�vel para download.\n Deseja atualizar agora?",L"Aten��o",MB_YESNO)==ID_YES) {
				  FormAtualizar->ShowModal();
			}

		}

	}

	catch (const Exception &e) {
			Memo1->Lines->Add("Erro: " + e.Message);
			delete fs;
	}

}
//---------------------------------------------------------------------------

