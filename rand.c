#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdint.h>
#define INT_MAX 1000
static unsigned int rnd(unsigned  int seed){

//srand(seed);
return rand();

}


int main(int argc,char * argv[]){

 int n[100];
 for(int i=0;i<argc-1;i++){
  n[i]=atoi(argv[i+1]);
} 

int skip=!!fork()+2*(!!fork());
for(uint32_t i=skip;i!=INT_MAX;i+=4){
int x=rnd(i);
for(int j=0;j<argc-1;j++){
if(n[j]==x){
printf("haha! %d %d\n",j,i);
fflush(stdout);
}
}
}
}
