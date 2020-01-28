
#ifndef Strassen_improved_hpp
#define Strassen_improved_hpp

#include <stdio.h>

void sum_matrix_blocks(float **C,
                       const size_t C_f_row,
                       const size_t C_f_col,
                       float ** A,
                       const size_t A_f_row,
                       const size_t A_f_col,
                       float ** B,
                       const size_t B_f_row,
                       const size_t B_f_col,
                       const size_t n);

void sub_matrix_blocks(float **C,
                       const size_t C_f_row,
                       const size_t C_f_col,
                       float ** A,
                       const size_t A_f_row,
                       const size_t A_f_col,
                       float ** B,
                       const size_t B_f_row,
                       const size_t B_f_col,
                       const size_t n);

void naive_aux(float **C, const size_t C_f_row, const size_t C_f_col,
               float **A, const size_t A_f_row, const size_t A_f_col,
               float **B, const size_t B_f_row, const size_t B_f_col,
               const size_t n);

void strassen_aux_improved(float **C, const size_t C_f_row, const size_t C_f_col,
                           float **A, const size_t A_f_row, const size_t A_f_col,
                           float **B, const size_t B_f_row, const size_t B_f_col,
                           const size_t n);


void strassen_improved(float **C, float **A, float **B, const size_t n);


#endif /* Strassen_improved_hpp */
