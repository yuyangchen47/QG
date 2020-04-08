#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>
#define MaxSize 30
//����һ��������һ������Ҫ������ַ�����һ���������洢��׺���ʽ 
void trans(char *exp,char *postexp){
	struct{
		char data[MaxSize];
		int top;
	}String;   //���ڴ洢���ŵ�ջ
	int i = 0;
	String.top = -1;
	//���ζ�ȡ�ַ����е��ַ� 
	 while(*exp!='\0'){
	 	switch(*exp){
	 		case '(' : String.top++;							//��������ţ���ֱ����ջ 
	 					String.data[String.top] = *exp;
	 					exp++;
	 					break;
	 		case ')':  while(String.data[String.top] != '('){      //��Ϊ�����ţ���δƥ�䵽������ʱһֱ�������浽postexp�� 
	 						postexp[i++]=String.data[String.top];  //��ƥ�䵽��������ֱ�ӵ��������� 
                    		String.top--;
			 			}
			 			String.top--;
			 			exp++;
			 			break;
			case '+':
			case '-':  while(String.top!=-1 && String.data[String.top]!='('){   //���ַ�Ϊ�Ӽ������ʱ���������ۣ�1.��ʱ�ַ�ջΪ�գ�ֱ����ջ �� ���浽postexp�� 
							postexp[i++]=String.data[String.top]; 				//2.�ַ�ջ��Ϊ�յ��������ţ�ֱ����ջ ���浽postexp�� 
                    		String.top--;										//3.�ַ�����Ϊ��ͬʱû�������ţ���һֱ�����ַ�ջ��������������ջ ���浽postexp�� 
						}
						String.top++;
						String.data[String.top] = *exp;
						exp++;
						break;
			case '*':
			case '/':	while(String.data[String.top]=='*' || String.data[String.top]=='/'){      //���ַ�Ϊ�˳������ʱ����ʱջ����Ԫ����֮���ȼ���ȣ��򵯳�ջ��Ԫ�أ�����ջ���浽postexp��  
							postexp[i++]=String.data[String.top]; 								//���ַ�Ϊ�˳����㣬��ջ��Ԫ�����ȼ��ͣ���ֱ����ջ ���浽postexp�� 
                    		String.top--;
						}
						String.top++;
						String.data[String.top] = *exp;
						exp++;
						break;
			case ' ':	break;
			default:	while(*exp >= '0' && *exp <= '9'){					//��Ϊ�����ַ�ʱ��ת��Ϊ���ͣ�ͬʱ�浽���ú�׺���ʽ���ַ����� 
							postexp[i++]=*exp; 
                    		exp++;
						}
						postexp[i++]=' ';
		}
	 } 
	 while(String.top != -1){							//���ַ�ջ�е�Ԫ��ȡ�����浽postexp��  
	 	postexp[i++]=String.data[String.top]; 
        String.top--;
	 }
	 postexp[i]='\0';
} 
//�����Ժ�׺���ʽ��ֵ�ĺ��� 
float compvalue(char *postexp){
	struct{
		float data[MaxSize];
		int top;
	}value;
	int a,b,c,d;
	value.top = -1;
	while(*postexp!='\0'){
		switch(*postexp){
			case '+' : 	a=value.data[value.top];
               			value.top--;
                		b=value.data[value.top];
                		value.top--;
                		c=b+a;
                		value.top++;
                		value.data[value.top]=c;
                		break;
        	case '-' :	a=value.data[value.top];
               			value.top--;
                		b=value.data[value.top];
                		value.top--;
                		c=b-a;
                		value.top++;
                		value.data[value.top]=c;
                		break;
            case '*' :	a=value.data[value.top];
               			value.top--;
                		b=value.data[value.top];
                		value.top--;
                		c=b*a;
                		value.top++;
                		value.data[value.top]=c;
                		break;
            case '/' :	a=value.data[value.top];
               			value.top--;
                		b=value.data[value.top];
                		value.top--;
                		if(a != 0){
                			c= b / a;
                			value.top++;
                			value.data[value.top]=c;
						}
						else{
							printf("������󣬷�ĸ����Ϊ0");
							exit(0);
						}
                		break;
            case ' ' :	break;
            default :	d = 0;
            			while(*postexp >= '0' && *postexp <= '9'){
            				d = d * 10 + *postexp - '0';
            				postexp++;
						}
						value.top++;
						value.data[value.top] = d;
						break;
		}
		postexp++;
	}
	return value.data[value.top];
}

int main(){
	char exp[MaxSize],postexp[MaxSize];
    scanf("%s",&exp);
    trans(exp,postexp);
    printf("��׺���ʽΪ:%s\n",exp);
    printf("��׺���ʽΪ:%s\n",postexp);
    printf("������Ϊ��%g\n",compvalue(postexp));
     
	return 0;
}
