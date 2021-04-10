#include "poly.h"
#include <stdio.h>
#include <stdlib.h>

#define CHECK_PTR(p)  \
  do {                \
    if (p == NULL) {  \
      exit(1);        \
    }                 \
  } while (0)

/*Poly PolyAdd(const Poly *p, const Poly *q){
    Poly result;
    if(PolyIsCoeff(p) && PolyIsCoeff(q)){
        result.coeff = p -> coeff + q -> coeff;
    }
    else if(PolyIsCoeff(p)){

    }
    else if(PolyIsCoeff(q)){

    }
    else{
        Mono temp[p -> size + q -> size];
        PolyAddMonos()
    }

    return result;
} */

void PolyDestroy(Poly *p){
    if(PolyIsCoeff(p)){
        free(p);
    }
    for(int i = 0; i < p -> size; i++){
        MonoDestroy(&p->arr[i]);
    }
}
/** Funkcja która za zadanie ma zwiększyć pamięć dwukrotnie na tablice monos
 * @param monos
 * @param size
 */
void doubleSizeOfArr(Mono **monos, size_t *size){
    (*size) *= 2;
    *monos = realloc(*monos, (int)size * sizeof(Mono));
}

int MyComparator(const void *a, const void *b){
    Mono *_a = (Mono *)a;
    Mono *_b = (Mono *)b;
    if(_a->exp < _b->exp) return -1;
    else if(_a->exp == _b->exp) return 0;
    else return 1;
}

Poly PolyAddMonos(size_t count, const Mono monos[]){
    Poly result;
    Mono copyOfArray = *monos;
    qsort(&copyOfArray, count, sizeof(Mono), MyComparator);
    result.arr = malloc(sizeof(Mono));
    CHECK_PTR(result.arr);
    result.size = count;
    for(int i = 0; i < count; i++){
        result.arr[i] = monos[i];
    }
    return result;
}

void MonoPrint(Mono m){
    PolyPrint(m.p);
    printf("x^%d ", m.exp);
}
void PolyPrint(Poly h){
    if(h.arr == NULL){
        printf("%ld*", h.coeff);
    }
    else{
        for(int i = 0; i < h.size; i++){
            MonoPrint(h.arr[i]);
        }
    }
}

