
#include <bits/stdc++.h> 
using namespace std; 

 
#define d 256 


void search(char pat[], char txt[], int q) 
{ 
	int M = strlen(pat); 
	int N = strlen(txt); 
	int i, j; 
	int p = 0; 
	int t = 0; 
	int h = 1; 

 
	for (i = 0; i < M - 1; i++) 
		h = (h * d) % q; 

	// Calculate the hash value of pattern and first 
	// window of text 
	for (i = 0; i < M; i++) 
	{ 
		p = (d * p + pat[i]) % q; 
		t = (d * t + txt[i]) % q; 
	} 

	// Slide the pattern over text one by one 
	for (i = 0; i <= N - M; i++) 
	{ 

		
		if ( p == t ) 
		{ 

			for (j = 0; j < M; j++) 
			{ 
				if (txt[i+j] != pat[j]) 
					break; 
			} 

			
			if (j == M) 
				cout<<"Pattern found at index "<< i<<endl; 
		} 

		
		if ( i < N-M ) 
		{ 
			t = (d*(t - txt[i]*h) + txt[i+M])%q; 

			
			if (t < 0) 
			t = (t + q); 
		} 
	} 
} 


int main() 
{ 
	char txt[] = "MAHIN MITTAL"; 
	char pat[] = "HIN"; 
		

	int q = 101; 
	

	search(pat, txt, q); 
	cout<<"mahins-MacBook-Air:~ mahinmittal$ ";
	return 0; 
} 

 
