#include <bits/stdc++.h>
using namespace std;
int top=-1;
void push(char *a,int elem){
    a[++top]=elem;
}
void pop(char *a){
    if (top==-1){
        return ;
    }
    top--;
}
char visit(char *a){
    if(top!=-1){
        return a[top];
    } else {
        return ' ';
    }
}
int main() {
    int length, i;
    char a[30];
    char bracket[100];
    cout << "��������������: ";
    scanf("%s", bracket);
    getchar();
    length = (int) strlen(bracket);
    for (int j = 0; j < length; ++j) {
        if (bracket[j] == '(' || bracket[j] == '{' || bracket[j] == '[') {
            push(a, bracket[j]);
        } else {
            if (bracket[j] == ')') {
                if (visit(a) == ']') {
                    pop(a);
                } else {
                    cout << "���Ų�ƥ��";
                    return 0;
                }
            } else if (visit(a)=='{'){
                if (visit(a) == '{') {
                    pop(a);
                } else {
                    printf("���Ų�ƥ��");
                    return 0;
                }
            }else{
                if (visit(a) == '[') {
                    pop(a);
                } else {
                    printf("���Ų�ƥ��");
                    return 0;
                }
            }
        }
    }
    if (top!=-1) {
        printf("���Ų�ƥ��");
    }else{
        printf("����ƥ��");
    }
}