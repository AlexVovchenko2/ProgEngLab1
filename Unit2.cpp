//---------------------------------------------------------------------------

#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

AnsiString task(std::vector<std::vector<float>> matrix, int n, int m, float sr) {
	int counter = 0;
	if (sr > 0) {
		for (int i = 1; i < m; i+=2) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] < 0) { counter++; }
			}
		}
		return "Negative elements in odd columns: " + (AnsiString)counter;
	}   else {
		for (int i = 0; i < m; i+=2) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] > 0) { counter++; }
			}
		}
		return "Positive elements in even columns: " + (AnsiString)counter;
	}
	return "0";
}
