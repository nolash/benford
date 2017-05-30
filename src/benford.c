#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "benford.h"

float benford_distribution[9] = {
	0.301, // 1
	0.176, // 2
	0.125, // 3
	0.097, // 4
	0.079, // 5
	0.067, // 6
	0.058, // 7 
	0.051, // 8
	0.046  // 9
};

void benford_setLead_(long int* subject, int lead) {
	char order;
	float norm;
	
	order = (int)log10(*subject);
	norm = (int)(*subject / (float)pow(10, order));
	*subject -= norm * pow(10, order);
	*subject += lead * pow(10, order);
}

int benford_set(benford_t* bf, long int* number) {
	int lead;
	
	lead = benford_nextLead_(bf);
	benford_setLead_(number, lead + 1);
	
	return 0;
}

int benford_setf(benford_t* bf, float* number) {
	float intpart, decpart;
	long int intnumber;
	
	decpart = modff(*number, &intpart);
	intnumber = (int)intpart;
	
	benford_set(bf, &intnumber);
	
	*number = (float)intnumber + decpart;
	
	return 0;
}

int benford_nextLead_(benford_t* bf) {
	int i;
	float ratio;
	
	for (i = 0; i < 9; i++) {
		
		ratio = bf->counts[i] / (bf->total + 1.f);
		if (ratio < benford_distribution[i]) {
			bf->counts[i]++;
			bf->total++;
			return i;
		}
	}
	
	return -1;
}

/**
 * \fn benford_t* benford_new()
 * \brief Constructs a new benford number distribution generator
 */
benford_t* benford_new() {
	benford_t* bf;
	int i;
	
	bf = malloc(sizeof(benford_t));
	
	if (bf == NULL) {
		return 0;
	}
	for (i = 0; i < 9; i++) {
		bf->counts[i] = 0;
	}
	
	bf->total = 0;
	
	return bf;
}

/**
 * \fn benford_t* benford_free()
 * \brief Free up resources from distribution generator
 */
void benford_free(benford_t* bf) {
	if (bf != NULL) {
		free(bf);
	}
}
