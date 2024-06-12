/*
This simple command-line tool is designed to take a list of C operators provided as command-line arguments, 
sort them according to their precedence, and print them in order of their precedence along with a brief description. 
It initializes a predefined list of C operators and their respective precedence and descriptions. 
*/

#include <stdio.h>
#include <string.h>

#define N_OPERATORS 49
#define DESC_LEN 44
#define SYM_LEN 9

typedef struct {
  char symbols[SYM_LEN];
  char description[DESC_LEN];
} OPERATOR;

void insertion_sort(int arr[], int n);

int add_indices(const OPERATOR ops[], int indices[], int argc, char **argv);

void init_operators(OPERATOR operators[]);

void print_result(OPERATOR operators[], int indices[], int n_elem);

void print_usage(void);

int main(int argc, char **argv) {

  if (argc == 2 && strcmp(argv[1], "--help") == 0) {
    print_usage();
    return 0;
  }


  OPERATOR operators[N_OPERATORS];

  // Initializes an array of operators in order of precedence
  init_operators(operators);

  int indices[argc * 2]; //  Holds the indices of the provided operators

  int n_elem = add_indices(operators, indices, argc, argv);

  // Sorts in order of precedence
  insertion_sort(indices, n_elem);

  print_result(operators, indices, n_elem);
  return 0;
}

void insertion_sort(int arr[], int n) {
  int j, key;
  for (int i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

int add_indices(const OPERATOR ops[], int indices[], int argc, char **argv) {
  int n_elem = 0;
  for (int i = 1; i < argc; i++) {
    int found = 0;
    for (int j = 0; found < 2 && j < N_OPERATORS; j++) {
      if (strcmp(ops[j].symbols, argv[i]) == 0) {
        indices[(n_elem)++] = j;
        found++;
      }
    }
    if (found == 0) {
      printf("Unknown operator: %s\n", argv[i]);
    }
  }
  return n_elem;
}

void print_result(OPERATOR operators[], int indices[], int n_elem) {
  printf("High.                           P:   A:\n");
  for (int i = 0; i < n_elem; i++) {
    printf("%s\n", operators[indices[i]].description);
  }
  printf("Low.\n");
}

void print_usage(void) {
  printf("Usage: cprec [operator1] [operator2] ... [operatorN]\n");
  printf("The argument should be provided inside \"\" eg: cprec \"++\" \"*\"");
  printf("This program takes a list of C operators as command line arguments "
         "and prints them in order of their precedence.\n");
  printf("Use '--help' to display this message.\n");
}

void init_operators(OPERATOR operators[]) {
  operators[0] =
      (OPERATOR){.symbols = "++",
                 .description = "++       Postfix increment      2    L-T-R"};
  operators[1] =
      (OPERATOR){.symbols = "--",
                 .description = "--       Postfix decrement      2    L-T-R"};
  operators[2] =
      (OPERATOR){.symbols = "()",
                 .description = "()       Function call          2    L-T-R"};
  operators[3] =
      (OPERATOR){.symbols = "[]",
                 .description = "[]       Array subscripting     2    L-T-R"};
  operators[4] =
      (OPERATOR){.symbols = ".",
                 .description = ".        Reference member       2    L-T-R"};
  operators[5] =
      (OPERATOR){.symbols = "->",
                 .description = "->       Pointer member         2    L-T-R"};
  operators[6] =
      (OPERATOR){.symbols = "++",
                 .description = "++       Prefix increment       3    R-T-L"};
  operators[7] =
      (OPERATOR){.symbols = "--",
                 .description = "--       Prefix decrement       3    R-T-L"};
  operators[8] =
      (OPERATOR){.symbols = "+",
                 .description = "+        Unary plus             3    R-T-L"};
  operators[9] =
      (OPERATOR){.symbols = "-",
                 .description = "-        Unary minus            3    R-T-L"};
  operators[10] =
      (OPERATOR){.symbols = "!",
                 .description = "!        Logical NOT            3    R-T-L"};
  operators[11] =
      (OPERATOR){.symbols = "~",
                 .description = "~        Bitwise NOT            3    R-T-L"};
  operators[12] =
      (OPERATOR){.symbols = "()",
                 .description = "()       Type cast              3    R-T-L"};
  operators[13] =
      (OPERATOR){.symbols = "*",
                 .description = "*        Dereference            3    R-T-L"};
  operators[14] =
      (OPERATOR){.symbols = "&",
                 .description = "&        Address-of             3    R-T-L"};
  operators[15] =
      (OPERATOR){.symbols = "sizeof",
                 .description = "sizeof   Sizeof                 3    R-T-L"};
  operators[16] =
      (OPERATOR){.symbols = "_Alignof",
                 .description = "_Alignof Alignment              3    R-T-L"};
  operators[17] =
      (OPERATOR){.symbols = "*",
                 .description = "*        Multiplication         5    L-T-R"};
  operators[18] =
      (OPERATOR){.symbols = "/",
                 .description = "/        Division               5    L-T-R"};
  operators[19] =
      (OPERATOR){.symbols = "%",
                 .description = "%        Modulo                 5    L-T-R"};
  operators[20] =
      (OPERATOR){.symbols = "+",
                 .description = "+        Addition               6    L-T-R"};
  operators[21] =
      (OPERATOR){.symbols = "-",
                 .description = "-        Subtraction            6    L-T-R"};
  operators[22] =
      (OPERATOR){.symbols = "<<",
                 .description = "<<       Bitwise left shift     7    L-T-R"};
  operators[23] =
      (OPERATOR){.symbols = ">>",
                 .description = ">>       Bitwise right shift    7    L-T-R"};
  operators[24] =
      (OPERATOR){.symbols = "<",
                 .description = "<        Less than              9    L-T-R"};
  operators[25] =
      (OPERATOR){.symbols = "<=",
                 .description = "<=       LTE                    9    L-T-R"};
  operators[26] =
      (OPERATOR){.symbols = ">",
                 .description = ">        Greater than           9    L-T-R"};
  operators[27] =
      (OPERATOR){.symbols = ">=",
                 .description = ">=       GTE                    9    L-T-R"};
  operators[28] =
      (OPERATOR){.symbols = "==",
                 .description = "==       Equal to               10   L-T-R"};
  operators[29] =
      (OPERATOR){.symbols = "!=",
                 .description = "!=       Not equal to           10   L-T-R"};
  operators[30] =
      (OPERATOR){.symbols = "&",
                 .description = "&        Bitwise AND            11   L-T-R"};
  operators[31] =
      (OPERATOR){.symbols = "^",
                 .description = "^        Bitwise XOR            12   L-T-R"};
  operators[32] =
      (OPERATOR){.symbols = "|",
                 .description = "|        Bitwise OR             13   L-T-R"};
  operators[33] =
      (OPERATOR){.symbols = "&&",
                 .description = "&&       Logical AND            14   L-T-R"};
  operators[34] =
      (OPERATOR){.symbols = "||",
                 .description = "||       Logical OR             15   L-T-R"};
  operators[35] =
      (OPERATOR){.symbols = "?:",
                 .description = "?:       Ternary conditional    17   R-T-L"};
  operators[36] =
      (OPERATOR){.symbols = "?",
                 .description = "?        Ternary conditional    17   R-T-L"};
  operators[37] =
      (OPERATOR){.symbols = "=",
                 .description = "=        Direct assignment      17   R-T-L"};
  operators[38] =
      (OPERATOR){.symbols = "+=",
                 .description = "+=       Assignment sum         17   R-T-L"};
  operators[39] =
      (OPERATOR){.symbols = "-=",
                 .description = "-=       Assignment difference  17   R-T-L"};
  operators[40] =
      (OPERATOR){.symbols = "*=",
                 .description = "*=       Assignment product     17   R-T-L"};
  operators[41] =
      (OPERATOR){.symbols = "/=",
                 .description = "/=       Assignment quotient    17   R-T-L"};
  operators[42] =
      (OPERATOR){.symbols = "%=",
                 .description = "%=       Assignment remainder   17   R-T-L"};
  operators[43] =
      (OPERATOR){.symbols = "<<=",
                 .description = "<<=      Assignment left shift  17   R-T-L"};
  operators[44] =
      (OPERATOR){.symbols = ">>=",
                 .description = ">>=      Assignment right shift 17   R-T-L"};
  operators[45] =
      (OPERATOR){.symbols = "&=",
                 .description = "&=       Assignment bitwise AND 17   R-T-L"};
  operators[46] =
      (OPERATOR){.symbols = "^=",
                 .description = "^=       Assignment bitwise XOR 17   R-T-L"};
  operators[47] =
      (OPERATOR){.symbols = "|=",
                 .description = "|=       Assignment bitwise OR  17   R-T-L"};
  operators[48] = (OPERATOR){
      .symbols = ",",
      .description = ",        Comma                  18   L-T-R",
  };
}
