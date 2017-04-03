/*
    Holds the macros and function definitions for the rs and cmp programs.
    Yashar Nesvaderani
    A00984009
    Set 2D
*/
#ifndef SORT_H

#define SORT_H
#define IDSIZE   10
#define NAMESIZE 20
#define LINESIZE 256

/* Structure to hold first and last name. */
typedef struct{
    char last[NAMESIZE];
    char first[NAMESIZE];
} name;

/* Structure to hold ID, name, and score. */
typedef struct {
    char id[IDSIZE];
    name name;
    int  score;
} record;

int is_valid_id(const char[]);
int is_valid_name(const char[]);
int is_valid_score(const char[]);
void make_lowercase(char[]);
int is_valid_sort (char[]);
void sort_choose (record *, const char[], int);
int cmp_id (const void *, const void *);
int cmp_name_asc_score_asc (const void *, const void *);
int cmp_name_asc_score_desc (const void *, const void *);
int cmp_name_desc_score_asc (const void *, const void *);
int cmp_name_desc_score_desc (const void *, const void *);
int cmp_score_asc_name_asc (const void *, const void *);
int cmp_score_asc_name_desc (const void *, const void *);
int cmp_score_desc_name_asc (const void *, const void *);
int cmp_score_desc_name_desc (const void *, const void *);

#endif

