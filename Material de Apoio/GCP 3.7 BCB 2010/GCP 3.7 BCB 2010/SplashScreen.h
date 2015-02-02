//---------------------------------------------------------------------------

#ifndef SplashScreenH
#define SplashScreenH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <ComCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFormSplash : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TTimer *Timer1;
        TImage *Image2;
        TProgressBar *ProgressBar1;
        TShape *Shape1;
        TShape *Shape2;
        TShape *Shape3;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TPanel *Panel1;
        TMemo *Memo1;
        TShape *Shape4;
        TLabel *Label6;
        TTimer *Timer2;
        TShape *Shape5;
        TLabel *Label7;
	TImage *Image3;
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Label6MouseEnter(TObject *Sender);
        void __fastcall Label6MouseLeave(TObject *Sender);
        void __fastcall Label6Click(TObject *Sender);
        void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Label8Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormSplash(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSplash *FormSplash;
//---------------------------------------------------------------------------
#endif
