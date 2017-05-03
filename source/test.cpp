// Code to simulate the translation process based on explicit diffusion and mass action properties of tRNAs, ribosome and mRNAs.

/*
 To compile and run the code run:
 
	g++ main.cpp -o test
	./test
 
*/

// Declaring Header Files
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <sys/time.h>
#include <cstring>

// Fixed parameters
#define MAX_GENES 5000				// Maximum number of genes supported
#define MAX_GENE_LEN_ALLW 5000		// Maximum allowed gene length in codons
#define MAX_TIME 2400000			// Maximum time of the simulation
#define char_len_tRNA 1.5e-8		// Characteristic length of tRNA
#define char_len_ribo 3e-8			// Characteristic length of ribosome
#define char_time_tRNA 5.719e-4		// Characteristic time of movement for tRNA (4.45e-7 * 1285.1)
#define char_time_ribo 5e-4			// Characteristic time of movement for tRNA

// Default global variables
int seed = 1;						// Seed for RNG
int n_genes = 1;					// Number of genes
int tot_ribo = 2e5;					// Total ribosomes
int tot_tRNA = 3.3e6;				// Total tRNAs
int tot_mRNA = 0;					// Total mRNA (initialization)
double tot_space = 4.2e-17;			// Total space within a cell
double avail_space_t = 1.24e7;		// Available space for tRNAs
double avail_space_r = 1.56e6;		// Available space for ribosomes
double tot_time = 1500;				// Total time for simulation
double time_thres = 1000;			// Threshold time for analysis of e_times

// Run options
int printOpt[7] = {0,0,0,0,0,0,0};
char out_prefix[150] = "output";	// Prefix for output file names
char out_file[150];
char fasta_file[150] = "example/input/S.cer.genom";
char code_file[150] = "example/input/S.cer.tRNA";



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Associate functions
// To shuffle the elements of an array
// (Each function that doesn't need to return a value should be void)

void shuffle (int *array, size_t n){
    if (n > 1){
        size_t i;
        for (i = 0; i < n - 1; i++){
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1); //generates random number between 1 and n?
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

// Create ribosome and mRNA based structures

int main() {
    return 0;

}

