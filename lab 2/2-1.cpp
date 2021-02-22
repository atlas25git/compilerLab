#include<bits/stdc++.h

char input[100];

int i,l;


int A();
int a();
int B();
int c();
int x();
int y();



int main(){

    printf("\nRecursive descent parsing for the following grammar\n"); 
    printf("\nA->aBC\nB->x|xy'/@\n"); 
    printf("\nEnter the string to be checked:"); 
    gets(input);

    if(A())
    {
        if(input[i+1]=='\0')
        printf("\nString is accepted");

    else
    printf("\nString is not accepted");

    }

    else

    printf("\nString not accepted");

    getch();
    return 0;

}

int A() {

    if(a())
        {
            if(B())
                 {
                    if(c()) return(1);
                    else return(0);
    }
    }

  return(0);
}

int B()

{
    if(input[i]=='+')
        {
        i++;
    if(x()){
        if(y()) return(1);

    else    return(1);

            }

    else return(0);

        }

    else return(0);

}

int x(){

    return 1;

}

int y(){

    
    return(1);
        }

int a(){

    return 1;

}

int c(){

    
    return(1);
        }



