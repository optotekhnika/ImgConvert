//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainFrm.h"

#include <Vcl.Imaging.jpeg.hpp>
#include <System.SysUtils.hpp>
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
	Radio->ItemIndex = 0;
    ButtonSave->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ButtonLoadClick(TObject *Sender)
{
	if (!Open->Execute()){
        return;
	}

	if (Open->FilterIndex == 1) {
        ImageSrc->Picture->LoadFromFile(Open->FileName);
		ImageDest->Picture->LoadFromFile(Open->FileName);
	}else{
		std::auto_ptr<TJPEGImage> jp(new TJPEGImage());
		//std::auto_ptr<TBitmap> bmp(new TBitmap());
		jp->LoadFromFile(Open->FileName);
		//bmp->Assign(jp.get());

		//String sPath = ExtractFilePath(Open->FileName);
		//sPath += _T("\\temp.bmp");
		//bmp->SaveToFile(sPath);

		//ImageSrc->Picture->LoadFromFile(sPath);
		//ImageDest->Picture->LoadFromFile(sPath);

		//DeleteFile(sPath);

		ImageSrc->Picture->Bitmap->Assign(jp.get());
		ImageDest->Picture->Bitmap->Assign(jp.get());
	}


	Caption = Open->FileName;
	ButtonSave->Enabled = true;
	Radio->Enabled = true;

	UpdateImage();
}
//---------------------------------------------------------------------------
void TMainForm::UpdateImage()
{
	if (!ImageSrc->Picture)
		return;

	int nItem = Radio->ItemIndex;
	if ( nItem < 0 )
        return;

	BYTE u8Val = 0;
    WORD u16Val = 0;
	int nPitch = 0;
	if (ImageSrc->Picture->Bitmap->PixelFormat == pf24bit){
		nPitch = 3;
	}else if (ImageSrc->Picture->Bitmap->PixelFormat == pf32bit){
		nPitch = 4;
	}else{
		return;
	}
	for (int y = 0; y < ImageSrc->Picture->Height; y++){
		LPBYTE line = (LPBYTE)ImageSrc->Picture->Bitmap->ScanLine[y];
        LPBYTE lined = (LPBYTE)ImageDest->Picture->Bitmap->ScanLine[y];
		for (int x = 0; x < ImageSrc->Picture->Width; x++){

			switch(nItem){
			case 0: u8Val = line[ 2 ];
				break;
			case 1: u8Val = line[ 1 ];
				break;
			case 2: u8Val = line[ 0 ];
				break;
			case 3: u8Val =  (BYTE)(((WORD)line[ 0 ] +
				(WORD)line[ 1 ] +
				(WORD)line[ 2 ]) / (WORD)3);
				break;
			case 4: u16Val = (((WORD)line[ 0 ] +
				(WORD)line[ 1 ] +
				(WORD)line[ 2 ]));
				if (u16Val > 255) {
                    u16Val = 255;
				}
				u8Val =  (BYTE)u16Val;
				break;
			}

			lined[ 0 ] = u8Val;
			lined[ 1 ] = u8Val;
			lined[ 2 ] = u8Val;

			line += nPitch;
            lined += nPitch;
		}
	}

	ImageSrc->Refresh();
    ImageDest->Refresh();
}
void __fastcall TMainForm::RadioClick(TObject *Sender)
{
    UpdateImage();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ButtonSaveClick(TObject *Sender)
{
	Save->InitialDir = ExtractFilePath(Open->FileName);
	//Save->FileName = ExtractFileName(Open->FileName) + String("Conv");
	String sFilename = String("-Conv");
	switch(Radio->ItemIndex){
	case 0: sFilename += "R";
		break;
	case 1: sFilename += "G";
		break;
	case 2: sFilename += "B";
		break;
	case 3: sFilename += "AverageRGB";
		break;
    case 4: sFilename += "SumRGB";
		break;
	}

	String s = ExtractFileName(Open->FileName);
	s = ChangeFileExt(s, sFilename);

	Save->FileName = s + ".bmp";

	if (!ImageDest->Picture)
		return;

	if(!Save->Execute()){
        return;
	}

   ImageDest->Picture->SaveToFile(Save->FileName);
}
//---------------------------------------------------------------------------

