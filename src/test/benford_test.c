#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "benford.h"

#define TESTCOUNT 200

int setLead() {
	long int t = 123456;
	int d = 4;
	benford_setLead_(&t, d);
	
	if (t != 323456) {
		return -1;
	}
	
	return 0;
}

void getSequence(char *leads, int count) {
	int i;
	benford_t* bf = benford_new();
	for (i = 0; i < count; i++) {
		*(leads+i) = benford_nextLead_(bf);
	}
	benford_free(bf);
}

int getLeads(int count) {
	int i;
	char *res = calloc(sizeof(int), count);
	int *rescount = calloc(sizeof(int), 9);
	
	getSequence(res, count);
	
	for (i = 0; i < count; i++) {
		(*(rescount + (*(res+i))))++;
	}
	for (i = 0; i < 9; i++) {
		printf("%i: %i\n", i, *(rescount+i));
	}
	return 0;
}

int getInts(int count) {
	int i;
	
	long int min = 123;
	long int max = 912346789;
	
	char* leads = malloc(sizeof(char) * count);
	getSequence(leads, count);
	
	benford_t* bf = benford_new();
	
	for (i = 0; i < TESTCOUNT; i++) {
		long int n = (rand() % (max - min)) + min + 1;
		long int r = n;
		benford_set(bf, &r);
		printf("%i: [%i?] %li -> %li\n", i, *(leads+i) + 1, n, r);
	}
	
	benford_free(bf);
	return 0;
}

int getFloats(int count) {
	int i;
	
	float min = 123.f;
	float max = 123455.f;
	
	char* leads = malloc(sizeof(char) * count);
	getSequence(leads, count);
	
	benford_t* bf = benford_new();
	
	for (i = 0; i < TESTCOUNT; i++) {
		float n = ((float)rand() / (float)RAND_MAX) * (max - min) + min;
		float r = n;
		benford_setf(bf, &r);
		printf("%i: [%i?] %.3f -> %.3f\n", i, *(leads+i) + 1, n, r);
	}
	
	benford_free(bf);
	return 0;
}

int main() {
	int e;
	
	srand(clock());
	
	if ((e = setLead()) > 0) {
		return e;
	}
	if ((e = getLeads(TESTCOUNT)) > 0) {
		return e;
	}
	if ((e = getInts(TESTCOUNT)) > 0) {
		return e;
	} 
	if ((e = getFloats(TESTCOUNT)) > 0) {
		return e;
	}
	return 0;
}
