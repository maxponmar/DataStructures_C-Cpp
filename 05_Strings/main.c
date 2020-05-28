#include <stdio.h>

typedef enum { false, true } bool;

int StringLength(char *s) {
    int i;
    for (i=0;s[i]!='\0';i++) {}
    return i;
}

void ToggleCase(char *s) {
    int i;
	for (i=0;s[i]!='\0';i++)
    {
        if (s[i] >= 97 && s[i] <= 122)
            s[i] -= 32;
        else if (s[i] >= 65 && s[i] <= 90)
            s[i] += 32;
    }
}

void ToUpper(char *s) {
    int i;
	for (i=0;s[i]!='\0';i++)
    {
        if (s[i] >= 97 && s[i] <= 122)
            s[i] -= 32;
    }
}

void ToLower(char *s) {
    int i;
	for(i=0;s[i]!='\0';i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
            s[i] += 32;
    }
}

int countVowels(char *s) {
    int countV = 0;
    int i;
	for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
            || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            countV++;
        }
    }
    return countV;
}

int countConsonants(char *s) {
    int Consonants = 0;
    int i;
	for (i = 0; s[i] != '\0'; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
			if (!(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
            	|| s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')) {
            	Consonants++;
        	}
        }
    }
    return Consonants;
}

int countWords(char *s) {
    int countW = 0;
    int i;
	for (i = 0; s[i] != '\0'; i++) {
        if(s[i] == ' ' && s[i-1] != ' ') {
            countW++;
        }
    }
    return ++countW;
}

bool ValidateString(char *s) {
	int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (!(s[i] >= 'a' && s[i] <= 'z') &&
            !(s[i] >= 'A' && s[i] <= 'Z') &&
            !(s[i] >= '0' && s[i] <= '9'))
              return false;
    }
    return true;
}

void ReverseString(char *s) {
    int i,j;
    for (j=0;s[j]!='\0';j++) {}
    j--;
    char temp;
    for (i=0;i<j;i++,j--) {
        s[i] = s[i] + s[j];
        s[j] = s[i] - s[j];
        s[i] = s[i] - s[j];
    }
}

bool CompareString(char *s1, char *s2) {
    int i;
	for (i=0;s1[i]!= '\0'||s2[i]!='\0';i++) {
        if (s1[i]!=s2[i])
            return false;
    }
    return true;
}

bool Palindrome(char *s) {
    int i = 0, j = 0;
    for (j=0;s[j]!='\0';j++) {}
    j--;
    while (i<j) {
        if (s[i]!=s[j])
            return false;
        i++; j--;
    }
    return true;
}

void DuplicatesHash(char * s) {
    int hash[26] = {0};
    int i;
	for (i=0;s[i]!='\0';i++)
        hash[s[i]-97]++;
    for (i=0;i<26;i++) {
        if (hash[i]>1)
            printf("%c x %d\n",i+97,hash[i]);
    }
}

void DuplicatesBitwise(char *s) {
    unsigned int H = 0;
    int i;
	for (i=0;s[i]!='\0';i++) {
        unsigned int x = 1;
        x = x << (s[i] - 97);
        if (H & x)
            printf("%c is a duplicate\n",s[i]);
        else
            H = H | x;
    }
}

bool Anagram(char *s1, char *s2) {
    int H[26] = {0};
    int i;
	for (i=0;s1[i]!='\0';i++)
        H[s1[i]-97]++;
    for (i=0;s2[i]!='\0';i++) {
        H[s2[i]-97]--;
        if (H[s2[i]-97]<0)
			return false;
    }
    for (i=0;i<26;i++) {
        if (H[i]>0)
			return false;
    }
    return true;
}


void Permutation_v1(char s[], int k) {
    static int A[10]={0};
    static char Res[10];
	int i;
    if (s[k] == '\0') {
        Res[k] = '\0';
        printf("%s\n", Res);
    }
    else {
        for (i = 0; s[i] != '\0'; i++) {
            if (A[i] == 0) {
                Res[k] = s[i];
                A[i] = 1;
                Permutation_v1(s, k+1);
                A[i] = 0;
            }
        }
    }
}

void swap(char *a, char *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void Permutation_v2(char s[], int l, int h) {
    int i;
	if (l==h)
        printf("%s\n", s);
    else {
        for (i = l; i <= h; i++) {
            swap (&s[l],&s[i]);
            Permutations_v2(s, l+1, h);
            swap (&s[l],&s[i]);
        }
    }
}

int main() {

	// char name[] = {65,66,67} <- Char Array
	// char name[] = {'a','b','c'} <- Char Array
	// char name[] = {'a','b','c','\0'} <- String (use \0)
	// char name[] = "Max" <- String (Compiler automatically add '\0')

	// char name[] = {'a','b','c','\0'} <- Allocated in Stack
	// char *name = {'a','b','c'}  <- Allocated in Heap implicitly (Although you don't use malloc)

	//printf("%d", name) <- prints the numbers that represent every character
	//printf("%s", name) <- prints the string

	//scanf("%s",name) <- read the string from the keyboard (Only 1 string, if you type "max ponce" it will only store "max")
	//gets(name) <- read the string from the keyboard (You can type more than 1 string, e.g. "max ponce")

    char s[] = "WelcomE";

    printf("String: %s\n", s);
    printf("String length: %d\n", StringLength(s));

	ToggleCase(s);
	printf("Toggle Case: %s\n", s);

	ToLower(s);
	printf("Lower Case: %s\n", s);

	ToUpper(s);
	printf("Upper Case: %s\n", s);

	printf("Num. Vowels: %d\n", countVowels(s));
	printf("Num. Consonants: %d\n", countConsonants(s));
	printf("Num. Words: %d\n", countWords(s));
	printf("Valid? %d\n", ValidateString(s));
	ReverseString(s);
	printf("Reverse: %s\n", s);

	char s1[] = "hola";
	char s2[] = "hola";
	char s3[] = "anitalavalatina";

	printf("s1 = %s\n", s1);
	printf("s2 = %s\n", s2);
	printf("s = %s\n", s);
	printf("s1 == s2? %d\n", CompareString(s1 , s2));
	printf("s1 == s? %d\n", CompareString(s1 , s));
	printf("s3 = %s\n", s3);
	printf("Palindrome s3?: %d\n", Palindrome(s3));

	printf("Duplicates (Hash) in %s\n", s3);
	DuplicatesHash(s3);
	printf("DuplicatesBitwise\n");
	DuplicatesBitwise(s3);

	char s4[] = "decimal";
	char s5[] = "medical";
	printf("Anagram: %d\n", Anagram(s4,s5));

	printf("Permutation ABC\n");
	char s6[] = "ABC";
	Permutation_v2(s6,0);

    return 0;
}
