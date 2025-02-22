//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	StringGrid1->Hide();
	LabelMatrix->Hide();
	EditMatrix->Hide();
	Button2->Hide();
}

int n, m;
int n1 = 0; int m1 = 0;

//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int n,m;
	AnsiString s1, s2;
	s1 = EditRows->Text;
	s2 = EditColumns->Text;
	size->Caption = s1 + "x" + s2;
	Form1->n = StrToInt(s1);
	Form1->m = StrToInt(s2);
	StringGrid1->RowCount = Form1->n;
	StringGrid1->ColCount = Form1->m;
	if (Form1->n > 0 && Form1->m > 0){
		StringGrid1->Show();
		LabelMatrix->Show();
		EditMatrix->Show();
		Button2->Show();
	}else{
		LabelMatrix->Caption = "Incorrect size";
		LabelMatrix->Show();
    }
}
//---------------------------------------------------------------------------



/*void __fastcall TForm1::EditMatrixChange(TObject *Sender)
{
	StringGrid1->Cells[1][1] = EditMatrix->Text;
}    */
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
/*void __fastcall TForm1::EditMatrixKeyPress(TObject *Sender, System::WideChar &Key)
{
	if (Key == 13){
		StringGrid1->Cells[n1][m1] = EditMatrix->Text;
	}
	n1 += 1;
}   */

AnsiString fmsg(int a, int b){
	AnsiString s;
	if (a == -1 || b == -1){
		s = "full";
	}
	else { s = "Enter elem [" + (AnsiString)a + "]" + "[" + (AnsiString)b + "]"; }
	return s;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	//const AnsiString msg = "Enter elem ";
	//AnsiString msgFull = msg + "[" + (AnsiString)n1 + "]" + "[" + (AnsiString)m1 + "]";

	if (m1 < Form1->m && n1 < Form1->n){
		StringGrid1->Cells[m1][n1] = EditMatrix->Text;
		m1++;
	}
	else if (m1 >= Form1->m && n1 < Form1->n-1){
		m1 = 0;
		n1++;
		StringGrid1->Cells[m1][n1] = EditMatrix->Text;
		m1 += 1;
		LabelMatrix->Caption = fmsg(n1, m1);
	}
	else if(m1 < Form1->m && n1 >= Form1->n){

	}
	else{

	}
	LabelMatrix->Caption = fmsg((m1 >= Form1->m) ? ((n1 + 1 >= Form1->n) ? -1 : n1 + 1) : n1, (m1 >= Form1->m) ? 0 : m1);
}
//---------------------------------------------------------------------------
