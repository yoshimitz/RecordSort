/* 
    Compare Functions
    Yashar Nesvaderani
    A00984009
    Set 2D
*/

#include <string.h>
#include "compare.h"

/* compares ids in ascending order */
int cmp_id (const void *p, const void *q) {
    const record *pp = p;
    const record *qq = q;
    
    return (strcmp(pp->id, qq->id));
}

/* compares names in ascending order, if names are same compares
    scores in ascending order */
int cmp_name_asc_score_asc (const void *p, const void *q) {
    const record *pp = p;
    const record *qq = q;
    
    if (strcmp(pp->name.last, qq->name.last) != 0) {
        return strcmp(pp->name.last, qq->name.last);
    } else {
        if (strcmp(pp->name.first, qq->name.first) !=0) {
            return strcmp(pp->name.first, qq->name.first);
        } else {
            return (pp->score - qq->score);
        }
    } 
}

/* compares names in ascending order, if names are same compares
    scores in descending order */
int cmp_name_asc_score_desc (const void *p, const void *q) {
    const record *pp = p;
    const record *qq = q;
    
    if (strcmp(pp->name.last, qq->name.last) != 0) {
        return strcmp(pp->name.last, qq->name.last);
    } else {
        if (strcmp(pp->name.first, qq->name.first) !=0) {
            return strcmp(pp->name.first, qq->name.first);
        } else {
            return (qq->score - pp->score);
        }
    } 
}

/* compares names in descending order, if names are same compares
    scores in ascending order */
int cmp_name_desc_score_asc (const void *p, const void *q) {
    const record *pp = p;
    const record *qq = q;
    
    if (strcmp(pp->name.last, qq->name.last) != 0) {
        return -1 * strcmp(pp->name.last, qq->name.last);
    } else {
        if (strcmp(pp->name.first, qq->name.first) !=0) {
            return -1 * strcmp(pp->name.first, qq->name.first);
        } else {
            return (pp->score - qq->score);
        }
    } 
}

/* compares names in descending order, if names are same compares
    scores in descending order */
int cmp_name_desc_score_desc (const void *p, const void *q) {
    const record *pp = p;
    const record *qq = q;
    
    if (strcmp(pp->name.last, qq->name.last) != 0) {
        return -1 * strcmp(pp->name.last, qq->name.last);
    } else {
        if (strcmp(pp->name.first, qq->name.first) !=0) {
            return -1 * strcmp(pp->name.first, qq->name.first);
        } else {
            return (qq->score - pp->score);
        }
    } 
}

/* compares scores in ascending order, if scores are the same compares the names in ascending order. */
int cmp_score_asc_name_asc (const void *p, const void *q) {
    const record *pp = p;
    const record *qq = q;
    
    if ((pp->score - qq->score) != 0) {
        return (pp->score - qq->score);
    } else {
        if (strcmp(pp->name.last, qq->name.last) != 0) {
            return strcmp(pp->name.last, qq->name.last);
        } else {
            return strcmp(pp->name.first, qq->name.first);
        }
    }
}

/* compares scores in ascending order, if scores are the same compares the names in descending order. */
int cmp_score_asc_name_desc (const void *p, const void *q) {
    const record *pp = p;
    const record *qq = q;
    
    if ((pp->score - qq->score) != 0) {
        return (pp->score - qq->score);
    } else {
        if (strcmp(pp->name.last, qq->name.last) != 0) {
            return -1 * strcmp(pp->name.last, qq->name.last);
        } else {
            return -1 * strcmp(pp->name.first, qq->name.first);
        }
    }
}

/* compares scores in descending order, if scores are the same compares the names in ascending order. */
int cmp_score_desc_name_asc (const void *p, const void *q) {
    const record *pp = p;
    const record *qq = q;
    
    if ((qq->score - pp->score) != 0) {
        return (qq->score - pp->score);
    } else {
        if (strcmp(pp->name.last, qq->name.last) != 0) {
            return strcmp(pp->name.last, qq->name.last);
        } else {
            return strcmp(pp->name.first, qq->name.first);
        }
    }
}

/* compares scores in descending order, if scores are the same compares the names in descending order. */
int cmp_score_desc_name_desc (const void *p, const void *q) {
    const record *pp = p;
    const record *qq = q;
    
    if ((qq->score - pp->score) != 0) {
        return (qq->score - pp->score);
    } else {
        if (strcmp(pp->name.last, qq->name.last) != 0) {
            return -1 * strcmp(pp->name.last, qq->name.last);
        } else {
            return -1 * strcmp(pp->name.first, qq->name.first);
        }
    }
}