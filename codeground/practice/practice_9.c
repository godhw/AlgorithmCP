/* Please use the chemical symbols in the periodic table below when you solve this problem.
   "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
   "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
   "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
   "Y","Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
   "Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
   "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
   "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
   "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
   "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
   "No", "Lr"   */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Answer = 0;
char ch[14] = {'H', 'B', 'C', 'N', 'O', 'F', 'P', 'S', 'K', 'Y', 'I', 'W', 'U', 'V'};
char String[][3] = {
     "He", "Li", "Be", "Ne", "Na", "Mg", "Al",
   "Si", "Cl", "Ar", "Ca", "Sc", "Ti", "Cr", "Mn", "Fe",
   "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
   "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
   "Te", "Xe", "Cs", "Ba", "Hf", "Ta", "Re", "Os", "Ir", "Pt", "Au",
   "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
   "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
   "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
   "Th", "Pa", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
   "No", "Lr"};
int first[26];
int second[26][26];

int solve() {
    char* str = (char*)malloc(sizeof(char)*50001);
    scanf("%s", str);
    int flag;
    int mainflag = 1;
    int sol[50002];
    int i;
    sol[0] = 1;

    for (i = 0; i < strlen(str); i++) {
        sol[i+1] = 0;
            if (i > 0 && second[str[i-1]-'a'][str[i]-'a']) {
                sol[i+1] |= sol[i-1];
            }
            if (first[str[i] - 'a']) {
                sol[i+1] |= sol[i];
            }
    }
    int ans = sol[strlen(str)];
    free(str);
    return ans;
}

int main(void) {
    int T, test_case;
    for (int i = 0; i < 26; i++) {
        first[i] = 0;
        for (int j = 0; j < 26; j++) {
            second[i][j] = 0;
        }
    }
    for (int i = 0; i < 100; i++) {
        second[String[i][0] - 'A'][String[i][1] - 'a'] = 1;
    }
    for (int i = 0; i < 14; i++) {
        first[ch[i] - 'A'] = 1;
    }
    freopen("practice_9_input.txt", "r", stdin);

    setbuf(stdout, NULL);

    scanf("%d", &T);

    for (test_case = 0; test_case < T; test_case++) {
        Answer = solve();
        printf("Case #%d\n", test_case + 1);
        if (Answer) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}