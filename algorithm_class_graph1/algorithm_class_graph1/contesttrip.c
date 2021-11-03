#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INFINITE 99999

struct DOT {

	double x;
	double y;
	int idx;
	int UNION;

};


struct edge {

	double d; //distacne
	int src;
	int dest;

};

int MAKESET(struct DOT*, int);
double calDistance(double x1, double y1, double x2, double y2);
void selectionSort(struct edge* ptr, int m);

struct edge** tPtr;
struct edge* E;
struct edge* sortE;
struct DOT* dotPtr;

int main() {
	int fNum = 0;
	int m = 0;




	printf(" enter the number of freckles. :  ");
	scanf("%d", &fNum);

	dotPtr = (struct DOT*)malloc(sizeof(struct DOT) * fNum);

	if (dotPtr == NULL) {
		printf(" error. malloc failed . ");
		exit(1);
	}

	for (int i = 0; i < fNum; i++) {
		scanf("%lf %lf", &dotPtr[i].x, &dotPtr[i].y);
		dotPtr[i].UNION = i;
	}

	MAKESET(dotPtr, fNum);

	selectionSort(sortE, m);


	for (int i = 0; i < m; i++) {

		if (FINDESET(sortE[i]) != 0) {
			UNIONSET(sortE[i]);
		}


	}
}

int MAKESET(struct DOT* ptr, int n) {

	int k = 0;
	int m = 0; //sortE index
	int* s;
	tPtr = (struct edge**)malloc(sizeof(struct edge) * n);
	for (int i = 0; i < n; i++) {
		tPtr[i] = (struct edge*)malloc(sizeof(struct edge) * n);
	}
	E = (struct edge*)malloc(sizeof(struct edge) * n * n);


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			tPtr[i][j].d = INFINITE;
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {

			tPtr[i][j].src = i;
			tPtr[i][j].dest = j;
			tPtr[i][j].d = calDistance(ptr[i].x, ptr[i].y, ptr[j].x, ptr[j].y);
		}
	}

	for (int i = 0; i < n * n; i++) {
		E[i].d = INFINITE;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (tPtr[i][j].d < INFINITE) {
				E[m] = tPtr[i][j];
				m++;
			}
		}
	}

	m--;
	sortE = (struct edge*)malloc(sizeof(struct edge) * m);

	for (int i = 0; i < m; i++) {
		sortE[i] = E[i];
	}

	return m;

}

double calDistance(double x1, double y1, double x2, double y2) {

	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));


}

void selectionSort(struct edge* ptr, int m) {
	int min;

	for (int i = 1; i < m - 1; i++) {
		min = i;
		for (int j = i + 1; j < m; j++) {
			if (ptr[j + 1].d < ptr[min].d) {
				min = j;
			}
		}

		if (min != i) {
			ptr[i + 1] = ptr[min];
		}
	}


}

int FINDSET(struct Dot* ptr) {
	if (dotPtr[ptr.src].UNION == dotPtr[ptr.dest].UNION) {
		return 1;
	}
	else return 0;
}

void UNION(struct Dot* ptr) {
	// change union
}