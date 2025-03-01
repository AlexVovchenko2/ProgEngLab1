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
	Button3->Hide();
	LabelComment->Hide();
	LabelAnswer->Hide();
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
		Button1->Hide();
        Form1->createVect();
		StringGrid1->Show();
		//LabelMatrix->Show();
		//EditMatrix->Show();
		//Button2->Show();
		Button3->Show();
	}else{
		LabelMatrix->Caption = "Incorrect size";
		LabelMatrix->Show();
    }
}
//---------------------------------------------------------------------------

AnsiString fmsg(int a, int b){
	AnsiString s;
	if (a == -1 || b == -1){
		s = "full";
		Form1->Button2->Hide();
        Form1->LabelMatrix->Hide();
		Form1->Button3->Show();
		Form1->EditMatrix->Hide();
	}
	else { s = "Enter elem [" + (AnsiString)a + "]" + "[" + (AnsiString)b + "]"; }
	return s;
}

//---------------------------------------------------------------------------
//void __fastcall TForm1::Button2Click(TObject *Sender)
//{
	//const AnsiString msg = "Enter elem ";
	//AnsiString msgFull = msg + "[" + (AnsiString)n1 + "]" + "[" + (AnsiString)m1 + "]";
	/*AnsiString buff;
	if (m1 < Form1->m && n1 < Form1->n){
		buff = EditMatrix->Text;
		StringGrid1->Cells[m1][n1] = buff;
		Form1->matrix[m1][n1] = StrToFloat(buff);
		Form1->sum += StrToFloat(buff);
		m1++;
	}
	else if (m1 >= Form1->m && n1 < Form1->n-1){
		m1 = 0;
		n1++;
		buff = EditMatrix->Text;
		StringGrid1->Cells[m1][n1] = buff;
		Form1->matrix[m1][n1] = StrToFloat(buff);
		Form1->sum += StrToFloat(buff);
		m1 += 1;
		LabelMatrix->Caption = fmsg(n1, m1);
	}
	else if(m1 < Form1->m && n1 >= Form1->n){

	}
	else{

	}
	LabelMatrix->Caption = fmsg((m1 >= Form1->m) ?
		((n1 + 1 >= Form1->n) ? -1 : n1 + 1) : n1, (m1 >= Form1->m) ? 0 : m1); */
   /*	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			Form1->matrix[m1][n1] = StrToFloat(StringGrid1->Cells[i][j]);
		}
	} */
//}

//---------------------------------------------------------------------------

//function from unit2
AnsiString task(std::vector<std::vector<float>> matrix, int n, int m, float sr);

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = (StringGrid1->Cells[i][j] != "") ?
			 StrToFloat(StringGrid1->Cells[i][j]) : 0;
			sum += matrix[i][j];
		}
	}

	float sr = sum/(n*m);
	LabelComment->Caption = "Arithmetic mean: " + (AnsiString)sr;
	LabelComment->Show();
	AnsiString s = task(matrix, n, m, sr);
	LabelAnswer->Caption = s;
	Button3->Hide();
	LabelAnswer->Show();
}
//---------------------------------------------------------------------------
