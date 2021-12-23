//---------------------------------------------------------------------------

#ifndef MainFrmH
#define MainFrmH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TRadioGroup *Radio;
	TGroupBox *GroupBox1;
	TButton *ButtonLoad;
	TButton *ButtonSave;
	TOpenDialog *Open;
	TSaveDialog *Save;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TImage *ImageDest;
	TImage *ImageSrc;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonLoadClick(TObject *Sender);
	void __fastcall RadioClick(TObject *Sender);
	void __fastcall ButtonSaveClick(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);

    void UpdateImage();
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
