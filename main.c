#include<stdio.h>

int array_create(int *array){
    char symbol;
    for(int i=0; i<20; i++){
        scanf("%i%c", &array[i], &symbol);
        if(symbol == '\n'){
            i++;
            return i;
        }
    }
}

int index_first_negative_function(int *array, int *number){
    for (int i=0; i<*number; i++){
        if (array[i]<0){
            return i;
        }
    }
}

int index_last_negative_function(int *array, int *number){
    int index_last_negative=-1;
    for (int i=0; i<*number; i++){
        if (array[i]<0){
            index_last_negative=i;
        }
    }
    return index_last_negative;
}

int multi_between_negative_function(int *array, int *number){
    int multi_between_negative=1;
    for(int i=index_first_negative_function(array, number); i<index_last_negative_function(array, number); i++){
        multi_between_negative=multi_between_negative*array[i];
    }
    return multi_between_negative;
}

int multi_before_and_after_negative_function(int *array, int *number){
    int multi_before_and_after_negative=1;
    for(int i=0; i<index_first_negative_function(array, number); i++){
        multi_before_and_after_negative=multi_before_and_after_negative*array[i];
    }
    for(int i=index_last_negative_function(array, number); i<*number; i++){
        multi_before_and_after_negative=multi_before_and_after_negative*array[i];
    }
    return multi_before_and_after_negative;
}

int main(){
    int function;
    scanf("%i", &function);
    int array[20];
    int number=array_create(array);
    switch (function){
        case 0:
            printf("%i\n", index_first_negative_function(array, &number));
            break;
        case 1:
            printf("%i\n", index_last_negative_function(array, &number));
            break;
        case 2:
            printf("%i\n", multi_between_negative_function(array, &number));
            break;
        case 3:
            printf("%i\n", multi_before_and_after_negative_function(array, &number));
            break;
        default:
            printf("Данные некорректны\n");
    }
}