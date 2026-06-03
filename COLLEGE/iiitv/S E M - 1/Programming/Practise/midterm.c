// #include<stdio.h> 

// int main(){ 

//     int x= 5;
//     int y = x++ + ++x;
//     printf("%d", y);
//     return 0;
// }

// #include<stdio.h> 

// int main(){ 

//     int a =10;
//     int b = printf("%d ", a--);
//     printf("%d \n", b);
//     return 0;
// }


// #include<stdio.h> 

// int main(){ 

//     int a =2, b=3;
//     int c = a-- * ++b;
//     printf("%d", c);
//     return 0;
// }


#include<stdio.h> 

void main(){ 
    int x=0;
    int y = printf("%d", x) && printf("%d", x+1);
    printf("%d", y);
}