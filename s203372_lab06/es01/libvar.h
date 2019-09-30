typedef struct stud{
    char nome[36];
    char cognome[36];
    char matricola[36];
    struct stud *next;
    struct stud *prev;
    struct ris{
        int crediti;
        float media;
    }voti;
}stu;

