#include <iostream>
#include <string.h>
#define SIZE 50

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct senarai {
	int keutamaan;
	char kerja[200];
};

senarai senaraiSaya[SIZE];

void paparMenu();
int count();
void papar(int index);
void susunMenaik();
void tukar(int x, int y);

int main() {
	
	// print menu
	// boleh choose dari menu
	// choose 1: tambah
	// choose 2: tolak
	// choose 3: sort
	// choose 4: search
	// choose 5: 
	
	while (1) {
		paparMenu();
		
		int pilihan;
		
		scanf("%d", &pilihan);
		
		switch (pilihan) {
			case 1:
			{
				char kerja[200];
				int keutamaan;
				
				cin.clear();
				cin.sync();
				
				printf("\n Masukkan Nama kerja (e.g. basuh pinggan):");
				cin.getline(kerja, sizeof(kerja));
				
				printf("\n Masukkan keutamaan kerja (e.g. 7)");
				scanf("%d", &keutamaan);
				
				for(int i = 0; i < SIZE; i++) {
					if (senaraiSaya[i].keutamaan == 0) {
						senaraiSaya[i].keutamaan = keutamaan;
						strcpy(senaraiSaya[i].kerja, kerja);
						break;
					}
				}
				break;
			}
			case 2:
			{
			
				int index = 0;
				printf("\n Masukkan no. kerja untuk di edit: ");
				scanf("%d", &index);
				
				char kerja1[200];
				int keutamaan1;
				
				cin.clear();
				cin.sync();
				
				printf("\n Masukkan Nama kerja (e.g. basuh pinggan):");
				cin.getline(kerja1, sizeof(kerja1));
				
				printf("\n Masukkan keutamaan kerja (e.g. 7)");
				scanf("%d", &keutamaan1);
				
				senaraiSaya[index - 1].keutamaan = keutamaan1;
				strcpy(senaraiSaya[index - 1].kerja, kerja1);
				
				break;
			}
			case 3:
			{
				int cari = 0;
				printf("\n Masukkan no. kerja untuk di buang: ");
				scanf("%d", &cari);
				
				cari = cari - 1;
				
				bool jumpaKe = false;
				
				for (int i = 0; i < SIZE; i++) {
					
					if (cari == i) {
						senaraiSaya[i].keutamaan = 0;
						strcpy(senaraiSaya[i].kerja, "");
							
						jumpaKe = true;
					}
					
					if (jumpaKe == true && senaraiSaya[i].keutamaan != 0) {
						senaraiSaya[i - 1].keutamaan = senaraiSaya[i].keutamaan;
						strcpy(senaraiSaya[i - 1].kerja, senaraiSaya[i].kerja);
						
						senaraiSaya[i].keutamaan = 0;
						strcpy(senaraiSaya[i].kerja, "");
					}
				}
				
				break;
			}
			case 4:
			{
				int cari = 0;
				printf("\n Masukkan no. kerja untuk di cari: ");
				scanf("%d", &cari);
				
				cari = cari - 1;
				
				for (int i = 0; i < SIZE; i++) {
					
					if (cari == i) {
						papar(i);
						break;
					}
				}
				
				break;
			}
			case 5:
			{
				susunMenaik();
				break;
			}
				
		}
	}
	
	return 0;
}

void paparMenu() {
	printf(
		"\nKerja Saya\n"
		"----------"
	);
	
	if (count() == 0) {
		printf(
			"\nTiada kerja lagi"
		);
	} else {
		for(int i = 0; i < SIZE; i++) {
			if (senaraiSaya[i].keutamaan == 0) {
				break;
			}
			
			printf("\n%d. %s", i + 1, senaraiSaya[i].kerja);
		}
	}
	
	printf(
		"\n\n\n ------------------\n 1. tambah kerja"
		"\n 2. edit kerja"
		"\n 3. delete kerja"
		"\n 4. search kerja"
		"\n 5. susun kerja"
		"\n\n Pilihan anda: "
	);
	
	
}

int count(){
	int counter = 0;
	for(int i = 0; i < SIZE; i++) {
		if (senaraiSaya[i].keutamaan == 0) {
			break;
		}
		
		counter++;
	}
	
	return counter;
}

void papar(int index) {
	printf(
		"\nKerja: %s"
		"\nKeutamaan: %d",
		senaraiSaya[index].kerja,
		&senaraiSaya[index].keutamaan
	);
}

void susunMenaik()
{
	int first, second, index;
 
    // One by one move boundary of unsorted subarray
    for (first = 0; first < SIZE-1; first++)
    {
    	if(senaraiSaya[first].keutamaan == 0){
    		break;
		}
		
        // Find the minimum element in unsorted array
        index = first;
        for (second = first+1; second < SIZE; second++){
        	
        	if(senaraiSaya[second].keutamaan == 0){
    			break;
			}
			
        	if (senaraiSaya[second].keutamaan > senaraiSaya[index].keutamaan)
            	index = second;
		}
        // Swap the found minimum element with the first element
        tukar(index, first);
    }
}

void tukar(int x, int y)
{
    senarai temp = senaraiSaya[x];
    senaraiSaya[x] = senaraiSaya[y];
    senaraiSaya[y] = temp;
}
