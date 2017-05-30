#ifndef BENFORD_H_
#define BENFORD_H_

typedef struct benford {
	char counts[9];
	int total;
} benford_t;

benford_t* benford_new();
void benford_free(benford_t* bf);
int benford_set(benford_t* bf, long int* number);
int benford_setf(benford_t* bf, float* number);

// private functions
void benford_setLead_(long int* subject, int lead);
int benford_nextLead_(benford_t* bf);

#endif // BENFORD_H_
