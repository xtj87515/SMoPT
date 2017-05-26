#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>
#include <cstdlib>

// Fixed parameters
#define MAX_GENES 5000                   // Maximum number of genes supported
#define MAX_GENE_LEN_ALLW 5000           // Maximum allowed gene length in codons


// Default global variables
int seed = 1;                   // Seed for RNG
int n_genes = 5000;              // Number of genes


// Run options
char fasta_file[150] = "../example/input/S.cer.genom";
char code_file[150] = "../example/input/S.cer.tRNA";

// Create ribosome and mRNA based structures
typedef struct
{	int seq[MAX_GENE_LEN_ALLW];		// Codon sequence of the gene
    int len;						// Length of the gene
    int exp;						// Gene expression level
    double ini_prob;				// Initiation probability of the mRNA
} gene;

typedef struct
{   char codon;                // Codon
    int tid;                     // tRNA id
    int gcn;                     // tRNA gene copy number
    double wobble;                // Wobble parameter
} trna;


// Reading the processed sequence file
int Read_FASTA_File(char *filename, gene *Gene)
{	FILE *fh;
    int c1=0;  // Represents line number
    char curr_char;
    
    fh=fopen(filename, "r");
    
    if(!fh)					// Check if file exists
    {	std::cout <<"\nModified FASTA/Sequence File Doesn't Exist\n" << std::endl;
        //Help_out();
        exit(1);
    }
    
    fscanf(fh,"%lf",&Gene[c1].ini_prob);
    
    do
    {	fscanf(fh,"%d",&Gene[c1].exp);
        
        int c2 = 0; // Represents number of sequence
        do
        {	fscanf(fh,"%d",&Gene[c1].seq[c2]);
            c2++;
            curr_char = fgetc(fh);
        }while(curr_char != '\n');
        Gene[c1].len = c2;
        
        c1++;
        //std::cout <<c1<< std::endl;
    }while(fscanf(fh,"%lf",&Gene[c1].ini_prob) ==1);
    return(0);
}


 // Read in tRNA file
 int Read_tRNA_File(char *filename, trna *cTRNA)
{	FILE *fh;
    int c1=0;
    //char curr_char;
 
    fh=fopen(filename, "r");
 
    if(!fh)					// Check if file exists
    {	std::cout << "\ntRNA File Doesn't Exist\n" << std::endl;
        //Help_out();
        exit(1);
    }

    while(fscanf(fh,"%s",&cTRNA[c1].codon)==1)
    {	fscanf(fh,"%d%d%lf",&cTRNA[c1].tid,&cTRNA[c1].gcn,&cTRNA[c1].wobble);
        c1++;
        std::cout << c1 << std::endl;
    }
    return(0);
}
 

int main(int argc, char *argv[]){
    
    // User specified parameters for quick test
    gene *Gene = new gene[n_genes];
    if(Gene == NULL)
    {	std::cout << "Too many genes\nOut of memory\n" << std::endl;
        exit(1);
    }
    
    // Initialize the various sturctures
    trna *cTRNA = new trna[61];
    if(cTRNA == NULL)
    {   std::cout << "Too many tRNAs\nOut of memory\n" << std::endl;
        exit(1);
    }
    
    // Read in the numeric seq
    Read_FASTA_File(fasta_file, Gene);
    
    // Read in the trna code file
    Read_tRNA_File(code_file, cTRNA);
    
}

