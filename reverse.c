/*   reverse.c */

int rev;
int* reverse(int num)
{
int rem;
while(num!=0)
{
rem=num%10;
rev=rev*10+rem;
num=num/10;
}
return &rev;
}
