
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    int a;
    int b;
    int c;
} Code;

int compare(const void *p1, const void *p2) {
    const Code *code1 = (const Code *)p1;
    const Code *code2 = (const Code *)p2;

    if (code1->a != code2->a) {
        return code1->a - code2->a;
    } else if (code1->b != code2->b) {
        return code1->b - code2->b;
    } else {
        return code1->c - code2->c;
    }
}

bool is_valid_code(const char *code) {
    return strlen(code) == 6 &&
           islower(code[0]) &&
           islower(code[2]) &&
           islower(code[4]) &&
           isdigit(code[1]) &&
           isdigit(code[3]) &&
           isdigit(code[5]);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    Code codes[1000];
    size_t num_codes = 0;
    char buffer[7];

    while (fscanf(file, "%6s", buffer) != EOF) {
        if (is_valid_code(buffer)) {
            sscanf(buffer, "%*c%d%*c%d%*c%d",
                   &codes[num_codes].a,
                   &codes[num_codes].b,
                   &codes[num_codes].c);
            num_codes++;
        }
    }

    fclose(file);

    qsort(codes, num_codes, sizeof(Code), compare);

	printf("Frozen computers: ");
    for (size_t i = 0; i < num_codes; i++) {
        printf("c%dr%ds%d", codes[i].a, codes[i].b, codes[i].c);
        if (i < num_codes - 1) {
            printf(", ");
        }
    }

    printf(".\n");
    return 0;
}
