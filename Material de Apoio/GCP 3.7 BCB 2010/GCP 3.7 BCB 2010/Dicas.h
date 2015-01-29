//---------------------------------------------------------------------------

#ifndef DicasH
#define DicasH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormDicas : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *TabResultado;
        TMemo *Memo1;
        TTabSheet *TabDidatica;
        TMemo *Memo2;
        TTabSheet *TabTitulos;
        TMemo *Memo3;
        TTabSheet *TabMemorial;
        TMemo *Memo4;
        TLabel *Label1;
        TTabSheet *TabSheet1;
        TMemo *Memo5;
	TTabSheet *TabEntrevista;
	TMemo *Memo6;
private:	// User declarations
public:		// User declarations
        __fastcall TFormDicas(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormDicas *FormDicas;
//---------------------------------------------------------------------------
#endif
