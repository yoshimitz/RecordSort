/* 
    Record Sort
    Yashar Nesvaderani
    A00984009
    Set 2D
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compare.h"

/* Main method takes in records, sorts, and prints them */
int main(int argc, char * argv[]) {
    size_t record_size = 0;
    size_t record_count = 0;
    size_t i;
    record * records;
    record * temp;
    char line[LINESIZE];
    char id[IDSIZE + 1];
    char last[NAMESIZE + 1];
    char first[NAMESIZE + 1];
    char score[NAMESIZE];
    char sort[5];
    
    if (argc > 2) {
        fprintf(stderr, "usage: %s [n+s-]", argv[0]);
        return 1;
    }
    
    if (argc == 1) {
        strcpy(sort, "id");
    } else {
        strcpy(sort, argv[1]);
        if (!is_valid_sort(sort)) {
        fprintf(stderr, "usage: %s [n+s-]", argv[0]);
        return 2;
        }
    }
    while (fgets(line, LINESIZE, stdin)) {
        if (sscanf(line, "%s%s%s%s", id, first, last, score) == 4) {
            if (is_valid_id(id) && is_valid_name(first) && is_valid_name(last) && is_valid_score(score)) {
                make_lowercase(first);
                make_lowercase(last);
                if (record_count == 0) {
                        records = malloc(sizeof(record));
                        record_size = 1;
#ifdef DEBUG
                        fprintf(stderr, "#\n"); 
#endif
                        strcpy(records[0].id, id);
                        strcpy(records[0].name.last, last);
                        strcpy(records[0].name.first, first);
                        records[0].score = atol(score);
                        record_count = 1;
                } else {
                    if (record_size == record_count) {
                        temp = realloc(records, sizeof(records[0]) * (record_size * 2));
                        if (temp == 0) {
                            fprintf(stderr, "reallocation failed \n");
                            return 4;
                        } else {
                            records = temp;
                            record_size *= 2;
                            
#ifdef DEBUG
                            fprintf(stderr, "#\n"); 
#endif
                        }
                        strcpy(records[record_count].id, id);
                        strcpy(records[record_count].name.last, last);
                        strcpy(records[record_count].name.first, first);
                        records[record_count].score = atol(score);
                        record_count++;
                    } else {
                        strcpy(records[record_count].id, id);
                        strcpy(records[record_count].name.last, last);
                        strcpy(records[record_count].name.first, first);
                        records[record_count].score = atol(score);
                        record_count++;
                    }
                }
            }
        }
    }
    
    sort_choose(records, sort, record_count);
    for (i = 0; i < record_count; i++) {
        printf("%s : %s, %s : %d\n", records[i].id, records[i].name.last, records[i].name.first, records[i].score);
    }
    
    free(records);

    return 0;
}

/* checks if id is valid */
int is_valid_id(const char s[]) {
    size_t i;
    if (strlen(s) != 9) 
        return 0;
    if (s[0] != 'a')
        return 0;
    for (i = 1; i < 9; i++) {
        if (!isdigit(s[i]))
            return 0;
    }
    return 1;
}

/* checks if name is valid length */
int is_valid_name(const char s[]) {
    return (strlen(s) < NAMESIZE);
}

/* checks if score is a valid integer between 0 and 100 */
int is_valid_score(const char score1[]) {
    char score2[NAMESIZE];
    size_t i = 0, j;
    
    while (score1[i] == '0') {
        i++;
    }
    for(j = 0; score1[i] != '\0'; i++, j++) {
        score2[j] = score1[i];
    }
    score2[j] = '\0';
    
    if (strlen(score2) > 3)
        return 0;
    for (j = 0; score2[j] != '\0'; j++) {
        if (!isdigit(score2[j]))
            return 0;
    }
    
    if (atol(score2) > 100 || atol(score2) < 0)
        return 0;
    
    return 1;
}

/* converts names to lowercase */
void make_lowercase(char s[]) {
    size_t i;
    
    for (i = 0; s[i] != '\0'; i++) {
        s[i] = tolower(s[i]);
    }
}

/* Determines if valid sort command line argument was given.
   Also lengthens shortcut commands */    
int is_valid_sort(char s[]) {
    if (strlen(s) != 4 && strlen(s) != 2)
        return 0;
    if (s[0] != 'n' && s[0] != 's')
            return 0;
    if (s[1] != '+' && s[1] != '-')
            return 0;
    if(strlen(s) == 2) {
        if (s[0] == 'n') {
            if (s[1] == '+') {
                strcpy(s, "n+s+");
                return 1;
            } else {
                strcpy(s, "n-s-");
                return 1;
            }
        } else {
            if (s[1] == '+') {
                strcpy(s, "s+n+");
                return 1;
            } else {
                strcpy(s, "s-n-");
                return 1;
            }
        }
    } else {
        if (s[0] == 'n') {
            if (s[2] != 's' || (s[3] != '+' && s[3] != '-'))
                return 0;
            }
         else {
            if (s[2] != 'n' || ((s[3] != '+') && s[3] != '-'))
                return 0;
            }
        }    
    return 1;
}

/* sorts the record list based on the given command line argument */
void sort_choose (record * records, const char sort[], int count) {
    if (strcmp(sort, "id") == 0) {
        qsort(records, count, sizeof(records[0]), cmp_id);
    } else if (strcmp(sort, "n+s+") == 0) {
        qsort(records, count, sizeof(records[0]), cmp_name_asc_score_asc);
    } else if (strcmp(sort, "n+s-") == 0) {
        qsort(records, count, sizeof(records[0]), cmp_name_asc_score_desc);
    } else if (strcmp(sort, "n-s+") == 0) {
        qsort(records, count, sizeof(records[0]), cmp_name_desc_score_asc);
    } else if (strcmp(sort, "n-s-") == 0) {
        qsort(records, count, sizeof(records[0]), cmp_name_desc_score_desc);
    } else if (strcmp(sort, "s+n+") == 0) {
        qsort(records, count, sizeof(records[0]), cmp_score_asc_name_asc); 
    } else if (strcmp(sort, "s+n-") == 0) {
        qsort(records, count, sizeof(records[0]), cmp_score_asc_name_desc); 
    } else if (strcmp(sort, "s-n+") == 0) {
        qsort(records, count, sizeof(records[0]), cmp_score_desc_name_asc); 
    } else if (strcmp(sort, "s-n-") == 0) {
        qsort(records, count, sizeof(records[0]), cmp_score_desc_name_desc); 
    }
}