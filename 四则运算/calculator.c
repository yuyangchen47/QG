#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>
#define MaxSize 30
//定义一个函数，一个是所要输入的字符串，一个是用来存储后缀表达式 
void trans(char *exp,char *postexp){
	struct{
		char data[MaxSize];
		int top;
	}String;   //用于存储符号的栈
	int i = 0;
	String.top = -1;
	//依次读取字符串中的字符 
	 while(*exp!='\0'){
	 	switch(*exp){
	 		case '(' : String.top++;							//如果左括号，则直接入栈 
	 					String.data[String.top] = *exp;
	 					exp++;
	 					break;
	 		case ')':  while(String.data[String.top] != '('){      //若为右括号，在未匹配到左括号时一直弹出并存到postexp中 
	 						postexp[i++]=String.data[String.top];  //若匹配到左括号则直接弹出不储存 
                    		String.top--;
			 			}
			 			String.top--;
			 			exp++;
			 			break;
			case '+':
			case '-':  while(String.top!=-1 && String.data[String.top]!='('){   //若字符为加减运算符时，分类讨论：1.此时字符栈为空，直接入栈 ， 并存到postexp中 
							postexp[i++]=String.data[String.top]; 				//2.字符栈不为空但有左括号，直接入栈 并存到postexp中 
                    		String.top--;										//3.字符串不为空同时没有左括号，则一直弹出字符栈里的运算符，再入栈 并存到postexp中 
						}
						String.top++;
						String.data[String.top] = *exp;
						exp++;
						break;
			case '*':
			case '/':	while(String.data[String.top]=='*' || String.data[String.top]=='/'){      //若字符为乘除运算符时，此时栈顶的元素与之优先级相等，则弹出栈中元素，再入栈并存到postexp中  
							postexp[i++]=String.data[String.top]; 								//若字符为乘除运算，且栈顶元素优先级低，则直接入栈 并存到postexp中 
                    		String.top--;
						}
						String.top++;
						String.data[String.top] = *exp;
						exp++;
						break;
			case ' ':	break;
			default:	while(*exp >= '0' && *exp <= '9'){					//当为数字字符时，转换为整型，同时存到放置后缀表达式的字符串中 
							postexp[i++]=*exp; 
                    		exp++;
						}
						postexp[i++]=' ';
		}
	 } 
	 while(String.top != -1){							//将字符栈中的元素取出并存到postexp中  
	 	postexp[i++]=String.data[String.top]; 
        String.top--;
	 }
	 postexp[i]='\0';
} 
//用来对后缀表达式求值的函数 
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
							printf("除零错误，分母不能为0");
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
    printf("中缀表达式为:%s\n",exp);
    printf("后缀表达式为:%s\n",postexp);
    printf("计算结果为：%g\n",compvalue(postexp));
     
	return 0;
}
