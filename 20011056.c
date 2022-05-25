#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 40

struct n {
    char data;
    struct n *next;
};
typedef struct n Node;
Node* top = NULL;


void push(char value) {
     Node *newNode;
    newNode = ( Node *)malloc(sizeof( Node));
    newNode->data = value; 
    if (top == NULL) {
        newNode->next = NULL;
    } else {
        newNode->next = top; 
    }
    top = newNode; 
    
}

char pop() {
    if (top == NULL) {
        printf("\nbos\n");
    } else {
         Node *temp = top;
        char temp_data = top->data;
        top = top->next;
        free(temp);
        return temp_data;
    }
}

void display() {//stack ic yapisini yazdirir.

    if (top == NULL) {
        printf("\nStack bos\n");
    } else {
        
         Node *temp = top;
        while (temp->next != NULL) {
            printf("%c ", temp->data);
            temp = temp->next;
        }
        printf("%c \n\n", temp->data);
    }
}

void binary(int sayi,int *flag){//alinan sayiyi binary formata donusturme fonksiyonudur.
		int a;
		int i;
		int tmp;
		tmp=sayi;
		int count=0;
			if(tmp<0){
				*flag=1;
				tmp=tmp*(-1);
				sayi=sayi*(-1);
			}
		
			
			while(tmp>= 1){
				
 				a=tmp%2;
 				a=a+'0';
 				
				 push(a);				 
 				 tmp = tmp/2;
 				 count++;
 				
 			}
 			
 			
			 if((sayi<=128) && count<=8 ){
			 	for(i=0;i<(8-count);i++){
			 		push('0');
				 }
				 
			 }
			 else if( sayi<=32768 && count<16 ) {
			 	for(i=0;i<(16-count);i++){
			 		push('0');
				 }
				  
			 }
			 else if(sayi<8388608 && count<24 ){
			 	for(i=0;i<(24-count);i++){
			 		push('0');
				 }
				 
			 }
			 else if(count>24){
			 	for(i=0;i<(32-count);i++){
			 		push('0');
				 }
				  
			 }
	}

void string_yap(char dizi[max],int flag){//stack char degerlerini bir diziye atarak string olusturma fonksiyonudur.
	int i=0;
	int carry=1;
	
	if(flag==0){
		
	while(top!=NULL){
		dizi[i]=pop();
		i++;
	}
	dizi[i]='\0';
	}
	else if(flag==1){
		while(top!=NULL){
			dizi[i]=pop();
			i++;
		}
		dizi[i]='\0';
	 	for(i=0;i<strlen(dizi);i++){
	 		if(dizi[i]=='0'){
	 			dizi[i]='1';
			 }
			 else if(dizi[i]=='1'){
			 	dizi[i]='0';
			 }
		 }
		for(i=strlen(dizi);i>=0;i--){
			if(dizi[i]=='1' && carry==1){
				dizi[i]='0';
			}
			else if(dizi[i]=='0' && carry==1){
				dizi[i]='1';
				carry=0;
			}
			
		}
		dizi[i]='\0';
		
	}
	
	
}
void bir_sifir_durumu(char dizi[max]){
		int i;
		int stack_len=0;
		int sifir_sayisi;
		for(i=0;i<strlen(dizi);i++){
			if(dizi[i]=='1'){
				push(dizi[i]);
			}
		}
		while(top!=NULL){
			top=top->next;
			stack_len++;
		}
		sifir_sayisi=strlen(dizi)-stack_len;
		if(sifir_sayisi>stack_len){
			printf("0' lar fazladir %d tane 1 eklenmelidir.\n",(sifir_sayisi-stack_len));
		}
		else if(sifir_sayisi<stack_len){
			printf("1'ler fazladir %d tane 0 eklenmelidir.\n",(stack_len-sifir_sayisi));
		}
		else{
			printf("1'ler ve 0'lar esit sayidadir.\n");
		}
	

}
void bir_sifir_durumu2(char dizi[max]){
	int i;
	int say_1=0;
	int say_0;
	
	for(i=0;i<strlen(dizi);i++){
		push('1');
	}
	for(i=0;i<strlen(dizi);i++){
		if(dizi[i]==pop())
			say_1++;
	}
	say_0=strlen(dizi)-say_1;
	if(say_0>say_1){
		printf("0'lar fazladir. %d kadar 1 eklenmelidir.\n",say_0-say_1);
	}
	else if(say_0<say_1){
		printf("1'ler fazladir. %d kadar 0 eklenmelidir.\n",say_1-say_0);
	}
	else{
		printf("1'ler ve 0'lar esit sayidadir.\n");
	}
	
}



int main() {
    int sayi;
    int count;
    int flag;
    int i;
    char dizi[max];
    
	flag=0;
	printf("bir sayi giriniz:");
	scanf("%d",&sayi);
	binary(sayi,&flag);
	
	string_yap(dizi,flag);
	printf("%s",dizi);
	printf("\n");

	
	bir_sifir_durumu(dizi);		//stack icine char atip stack boyutu ile dizi boyutu arasi farktan 0 ve 1 durumunu hesaplayan fonk.
	//bir_sifir_durumu2(dizi); //stack icini string boyutu kadar 1 ile doldurup karsilastirma yapan fonk. bir_sifir_durmu1 in alternatif fonk'u
	

	//display();
	
    return 0;
}
