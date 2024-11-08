int Fibo(int n){
    return (n < 2) ? 2 : (Fibo(n - 2) + Fibo(n - 1));
}

int main(){
    int n;

    printf("Selecione o n-esimo digito: ");
    scanf("%d", &n);

    printf("O n-esimo elemento da sequencia de fibonacci é: %d", Fibo(n));
}