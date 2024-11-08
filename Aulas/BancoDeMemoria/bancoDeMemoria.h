#define LENGTH 5

typedef union data{
    char c_data;
    int i_data;
}Data;

typedef struct{
    Data item;
    int next;
} Node;

typedef struct{
    Node bank[LENGTH];
    int first_empty, start, end;
}Bank;

Bank* Create();