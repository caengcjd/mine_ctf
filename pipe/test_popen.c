#include<stdio.h>  
int main()  
{  
    FILE        *fp;  
    int i;  
    char        *p;  
    char        buf[128];  
    fp = popen("./test_print", "r");  
    if(fp ==NULL) {  
        printf("NG\n");  
        return -1;  
    }  
    fgets(buf, 128, fp);  
    pclose(fp);  
    return 0;  
}  
