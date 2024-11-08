typedef struct filho{
    char name[50];
    int totalDeAmigos;

    struct filho **amigos;
    struct filho *prox;
} Filho;

typedef struct pai{
    char name[50], mae[50];
    int totalDeFilhos;

    Filho *primogenito;
    struct pai *prox;    
} Pai;

typedef struct {
    Pai *start, *end;
} List;

List* Create();