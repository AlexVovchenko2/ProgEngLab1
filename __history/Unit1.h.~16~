//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <vector>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *LabelRows;
	TLabel *LabelColumns;
	TEdit *EditRows;
	TEdit *EditColumns;
	TStringGrid *StringGrid1;
	TButton *Button1;
	TLabel *size;
	TLabel *LabelMatrix;
	TEdit *EditMatrix;
	TButton *Button2;
	TButton *Button3;
	TLabel *LabelComment;
	TLabel *LabelAnswer;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	int n, m;
	std::vector< std::vector<float> > matrix;
	void createVect(){
		std::vector<float> temp;
		for (int i = 0; i < this->m; i++) {
			for (int j = 0; j < this->n; j++)
				temp.push_back(0.0);
			this->matrix.push_back(temp);
			temp.clear();
		}
	}
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
