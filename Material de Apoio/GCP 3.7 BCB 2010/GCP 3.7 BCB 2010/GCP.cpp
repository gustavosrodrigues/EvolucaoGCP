//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Didatica_candidatos.cpp", FormDidaticaCandidatos);
USEFORM("Entrevista_candidatos.cpp", FormEntrevista_candidatos);
USEFORM("cabecalho.cpp", FormCabecalho);
USEFORM("SplashScreen.cpp", FormSplash);
USEFORM("Dialogo.cpp", NroDlg);
USEFORM("DefesaProjeto_candidatos.cpp", FormDefesaProjeto_candidatos);
USEFORM("Atualizar.cpp", FormAtualizar);
USEFORM("DefesaProjeto.cpp", FormDefesaProjeto);
USEFORM("Dicas.cpp", FormDicas);
USEFORM("PegaData.cpp", SelData);
USEFORM("Abertura.cpp", FormAbertura);
USEFORM("Configuracao.cpp", FormConfiguracao);
USEFORM("Atas.cpp", FormAtas);
USEFORM("Principal.cpp", Form1);
USEFORM("Resultado.cpp", FormResultado);
USEFORM("Entrevista.cpp", FormEntrevista);
USEFORM("Escrita.cpp", FormEscrita);
USEFORM("Titulos.cpp", FormTitulos);
USEFORM("Didatica.cpp", FormDidatica);
USEFORM("Log.cpp", FormLog);
//---------------------------------------------------------------------------
String arquivo_entrada;
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR ae, int)
{
        try
        {
                 arquivo_entrada = ae;
                 Application->Initialize();
                 Application->Title = "Gerenciador de Concursos P�blicos - UNIPAMPA";
                 Application->CreateForm(__classid(TForm1), &Form1);
				Application->CreateForm(__classid(TFormConfiguracao), &FormConfiguracao);
				Application->CreateForm(__classid(TFormAtas), &FormAtas);
				Application->CreateForm(__classid(TFormTitulos), &FormTitulos);
				Application->CreateForm(__classid(TFormDidatica), &FormDidatica);
				Application->CreateForm(__classid(TFormEscrita), &FormEscrita);
				Application->CreateForm(__classid(TFormResultado), &FormResultado);
				Application->CreateForm(__classid(TFormEntrevista), &FormEntrevista);
				Application->CreateForm(__classid(TFormAbertura), &FormAbertura);
				Application->CreateForm(__classid(TFormSplash), &FormSplash);
				Application->CreateForm(__classid(TNroDlg), &NroDlg);
				Application->CreateForm(__classid(TFormCabecalho), &FormCabecalho);
				Application->CreateForm(__classid(TFormDidaticaCandidatos), &FormDidaticaCandidatos);
				Application->CreateForm(__classid(TFormEntrevista_candidatos), &FormEntrevista_candidatos);
				Application->CreateForm(__classid(TFormDicas), &FormDicas);
				Application->CreateForm(__classid(TSelData), &SelData);
				Application->CreateForm(__classid(TFormDefesaProjeto), &FormDefesaProjeto);
				Application->CreateForm(__classid(TFormDefesaProjeto_candidatos), &FormDefesaProjeto_candidatos);
				Application->CreateForm(__classid(TFormAtualizar), &FormAtualizar);
				Application->CreateForm(__classid(TFormLog), &FormLog);
				DecimalSeparator = ',';
                 DateSeparator = '/';
				 ShortDateFormat = "d/m/yyyy";
                 ShortTimeFormat = "h:n:s";
                 ShortTimeFormat = "hh:nn:ss";
                 LongTimeFormat = "HH:nn:ss";


                 Application->Run();

        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------