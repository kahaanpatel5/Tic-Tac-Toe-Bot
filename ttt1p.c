//Author: Kahaan Patel
//Purpose: Tic Tac Toe
//Date: June 20th, 2021
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>

void print(char *);
void check(char *);
void playX(char *);
void playO(char *);
int x=0;
int main()
{
    int n;
    char c, box[]={"123456789"};
    printf("Choose your player (X/O): ");
    scanf("%c", &c);
    c=toupper(c);
    for(int i=0; i<4; i++)
    {
        printf("\n");
        print(box);
        if(c=='X')
        {
            turn1:
            printf("\nX's turn. Enter the position to be placed: ");
            scanf("%d", &n);
            if((box[n-1]!='X')&&(box[n-1]!='O'))
            {
                box[n-1]='X';
            }
            else
            {
                printf("\nPosition already marked. Try again.");
                goto turn1;
            }
        }
        else
        {
            printf("\nX's turn.\n");
            playX(box);
        }
        check(box);
        if(x==1)
        goto end;
        printf("\n");
        print(box);
        if(c=='O')
        {
            turn2:
            printf("\nO's turn. Enter the position to be placed: ");
            scanf("%d", &n);
            if((box[n-1]!='X')&&(box[n-1]!='O'))
            {
                box[n-1]='O';
            }
            else
            {
                printf("\nPosition already marked. Try again.");
                goto turn2;
            }
        }
        else
        {
            printf("\nO's turn.\n");
            playO(box);
        }
        check(box);
        if(x==1)
        goto end;
    }
    printf("\n");
    print(box);
    if(c=='X')
    {
        turn3:
        printf("\nX's turn. Enter the position to be placed: ");
        scanf("%d", &n);
        if((box[n-1]!='X')&&(box[n-1]!='O'))
        {
            box[n-1]='X';
        }
        else
        {
            printf("\nPosition already marked. Try again.");
            goto turn3;
        }
    }
    else
    {
        printf("\nX's turn.\n");
        playX(box);
    }
    check(box);
    if(x==1)
    goto end;
    printf("\nGame Tied!");
    end:
    printf("\n\n");
    print(box);
    printf("-----End Of Game-----\n\n");
    system("pause");
    return 0;
}
void print(char *b)
{
    for(int i=0; i<2; i++)
    printf(" %c |", *(b+i));
    printf(" %c \n", *(b+2));
    printf("___|___|___\n");
    for(int i=3; i<5; i++)
    printf(" %c |", *(b+i));
    printf(" %c \n", *(b+5));
    printf("___|___|___\n");
    for(int i=6; i<8; i++)
    printf(" %c |", *(b+i));
    printf(" %c \n", *(b+8));
    printf("   |   |   \n\n");
}
void check(char *b)
{
    for(int i=0; i<3; i++)
    {
        if(*(b+i)==*(b+i+3)&&*(b+i+3)==*(b+i+6))
        {
            printf("\n%c wins!", *(b+i));
            x=1;
        }
    }
    for(int i=0; i<9; i+=3)
    {
        if(*(b+i)==*(b+i+1)&&*(b+i+1)==*(b+i+2))
        {
            printf("\n%c wins!", *(b+i));
            x=1;
        }
    }
    if(*(b+0)==*(b+4)&&*(b+4)==*(b+8))
    {
        printf("\n%c wins!", *(b+0));
        x=1;
    }
    else if(*(b+2)==*(b+4)&&*(b+4)==*(b+6))
    {
        printf("\n%c wins!", *(b+2));
        x=1;
    }
}
void playX(char *b)
{
    static int n=0, r;
    if(n==0)
    {
        srand(time(0));
        while((r!=1)&&(r!=2)&&(r!=6)&&(r!=8))
        {
            r=rand()%9;
        }
        if(r==1)
        r=0;
        *(b+r)='X';
        n++;
        return;
    }
    else if((n==1)&&(*(b+1)=='O'||*(b+3)=='O'||*(b+5)=='O'||*(b+7)=='O'))
    {
        *(b+4)='X';
        n++;
        return;
    }
    else if((n==2)&&(*(b+0)=='X')&&(*(b+1)=='O'))
    {
        *(b+6)='X';
        n++;
        return;
    }
    else if((n==2)&&(*(b+2)=='X')&&(*(b+1)=='O'))
    {
        *(b+8)='X';
        n++;
        return;
    }
    else if((n==2)&&(*(b+6)=='X')&&(*(b+3)=='O'))
    {
        *(b+8)='X';
        n++;
        return;
    }
    else if((n==2)&&(*(b+8)=='X')&&(*(b+5)=='O'))
    {
        *(b+6)='X';
        n++;
        return;
    }
    else if((n==1)&&(*(b+r)='X'))
    {
        if(*(b+8-r)!='O')
        {
            *(b+8-r)='X';
            n=3;
            return;
        }
        else
        {
            for(int i=0; i<4; i+=2)
            {
                if(*(b+i)=='1'+i)
                {
                    *(b+i)='X';
                    n=3;
                    return;
                }
            }
            for(int i=6; i<10; i+=2)
            {
                if(*(b+i)=='1'+i)
                {
                    *(b+i)='X';
                    n=3;
                    return;
                }
            }
        }
    }
    n=3;
    for(int i=0; i<9; i+=3)
    {
        if(((*(b+i)==*(b+i+1))||(*(b+i+1)==*(b+i+2))||(*(b+i)==*(b+i+2)))&&((*(b+i)=='1'+i)||(*(b+i+1)=='2'+i)||(*(b+i+2)=='3'+i))&&(*(b+i)=='X'||*(b+i+1)=='X'||*(b+i+2)=='X'))
        {
            for(int j=i; j<i+3; j++)
            {
                if(*(b+j)!='X')
                {
                    *(b+j)='X';
                    return;
                }
            }
        }
    }
    for(int i=0; i<3; i++)
    {
        if(((*(b+i)==*(b+i+3))||(*(b+i+3)==*(b+i+6))||(*(b+i)==*(b+i+6)))&&((*(b+i)=='1'+i)||(*(b+i+3)=='4'+i)||(*(b+i+6)=='7'+i))&&(*(b+i)=='X'||*(b+i+3)=='X'||*(b+i+6)=='X'))
        {
            for(int j=i; j<9+i; j+=3)
            {
                if(*(b+j)!='X')
                {
                    *(b+j)='X';
                    return;
                }
            }
        }
    }
    if(((*(b+0)==*(b+4))||(*(b+4)==*(b+8))||(*(b+0)==*(b+8)))&&((*(b+0)=='1')||(*(b+4)=='5')||(*(b+8)=='9'))&&(*(b+0)=='X'||*(b+4)=='X'||*(b+8)=='X'))
    {
        for(int j=0; j<12; j+=4)
        {
            if(*(b+j)!='X')
            {
                *(b+j)='X';
                return;
            }
        }
    }
    else if(((*(b+2)==*(b+4))||(*(b+4)==*(b+6))||(*(b+2)==*(b+6)))&&((*(b+2)=='3')||(*(b+4)=='5')||(*(b+6)=='7'))&&(*(b+2)=='X'||*(b+4)=='X'||*(b+6)=='X'))
    {
        for(int j=2; j<8; j+=2)
        {
            if(*(b+j)!='X')
            {
                *(b+j)='X';
                return;
            }
        }
    }
    for(int i=0; i<9; i+=3)
    {
        if(((*(b+i)==*(b+i+1))||(*(b+i+1)==*(b+i+2))||(*(b+i)==*(b+i+2)))&&((*(b+i)=='1'+i)||(*(b+i+1)=='2'+i)||(*(b+i+2)=='3'+i))&&(*(b+i)=='O'||*(b+i+1)=='O'||*(b+i+2)=='O'))
        {
            for(int j=i; j<i+3; j++)
            {
                if(*(b+j)!='O')
                {
                    *(b+j)='X';
                    return;
                }
            }
        }
    }
    for(int i=0; i<3; i++)
    {
        if(((*(b+i)==*(b+i+3))||(*(b+i+3)==*(b+i+6))||(*(b+i)==*(b+i+6)))&&((*(b+i)=='1'+i)||(*(b+i+3)=='4'+i)||(*(b+i+6)=='7'+i))&&(*(b+i)=='O'||*(b+i+3)=='O'||*(b+i+6)=='O'))
        {
            for(int j=i; j<9+i; j+=3)
            {
                if(*(b+j)!='O')
                {
                    *(b+j)='X';
                    return;
                }
            }
        }
    }
    if(((*(b+0)==*(b+4))||(*(b+4)==*(b+8))||(*(b+0)==*(b+8)))&&((*(b+0)=='1')||(*(b+4)=='5')||(*(b+8)=='9'))&&(*(b+0)=='O'||*(b+4)=='O'||*(b+8)=='O'))
    {
        for(int j=0; j<12; j+=4)
        {
            if(*(b+j)!='O')
            {
                *(b+j)='X';
                return;
            }
        }
    }
    else if(((*(b+2)==*(b+4))||(*(b+4)==*(b+6))||(*(b+2)==*(b+6)))&&((*(b+2)=='3')||(*(b+4)=='5')||(*(b+6)=='7'))&&(*(b+2)=='O'||*(b+4)=='O'||*(b+6)=='O'))
    {
        for(int j=2; j<8; j+=2)
        {
            if(*(b+j)!='O')
            {
                *(b+j)='X';
                return;
            }
        }
    }
    for(int i=0; i<4; i+=2)
    {
        if(*(b+i)=='1'+i)
        {
            *(b+i)='X';
            return;
        }
    }
    for(int i=6; i<10; i+=2)
    {
        if(*(b+i)=='1'+i)
        {
            *(b+i)='X';
            return;
        }
    }
    if(*(b+4)=='5')
    {
        *(b+4)='X';
        return;
    }
    for(int i=1; i<9; i+=2)
    {
        if(*(b+i)=='1'+i)
        {
            *(b+i)='X';
            return;
        }
    }
}
void playO(char *b)
{
    static int n=0;
    if((n==0)&&(*(b+4)!='X'))
    {
        *(b+4)='O';
        n++;
        return;
    }
    else if((n==0)&&(*(b+4)=='X'))
    {
        *(b+8)='O';
        n++;
        return;
    }
    else if((n==1)&&((*(b+0)==*(b+8))||(*(b+2)==*(b+6))))
    {
        *(b+1)='O';
        n++;
        return;
    }
    n+=2;
    for(int i=0; i<9; i+=3)
    {
        if(((*(b+i)==*(b+i+1))||(*(b+i+1)==*(b+i+2))||(*(b+i)==*(b+i+2)))&&((*(b+i)=='1'+i)||(*(b+i+1)=='2'+i)||(*(b+i+2)=='3'+i))&&(*(b+i)=='O'||*(b+i+1)=='O'||*(b+i+2)=='O'))
        {
            for(int j=i; j<i+3; j++)
            {
                if(*(b+j)!='O')
                {
                    *(b+j)='O';
                    return;
                }
            }
        }
    }
    for(int i=0; i<3; i++)
    {
        if(((*(b+i)==*(b+i+3))||(*(b+i+3)==*(b+i+6))||(*(b+i)==*(b+i+6)))&&((*(b+i)=='1'+i)||(*(b+i+3)=='4'+i)||(*(b+i+6)=='7'+i))&&(*(b+i)=='O'||*(b+i+3)=='O'||*(b+i+6)=='O'))
        {
            for(int j=i; j<9+i; j+=3)
            {
                if(*(b+j)!='O')
                {
                    *(b+j)='O';
                    return;
                }
            }
        }
    }
    if(((*(b+0)==*(b+4))||(*(b+4)==*(b+8))||(*(b+0)==*(b+8)))&&((*(b+0)=='1')||(*(b+4)=='5')||(*(b+8)=='9'))&&(*(b+0)=='O'||*(b+4)=='O'||*(b+8)=='O'))
    {
        for(int j=0; j<12; j+=4)
        {
            if(*(b+j)!='O')
            {
                *(b+j)='O';
                return;
            }
        }
    }
    else if(((*(b+2)==*(b+4))||(*(b+4)==*(b+6))||(*(b+2)==*(b+6)))&&((*(b+2)=='3')||(*(b+4)=='5')||(*(b+6)=='7'))&&(*(b+2)=='O'||*(b+4)=='O'||*(b+6)=='O'))
    {
        for(int j=2; j<8; j+=2)
        {
            if(*(b+j)!='O')
            {
                *(b+j)='O';
                return;
            }
        }
    }
    for(int i=0; i<9; i+=3)
    {
        if(((*(b+i)==*(b+i+1))||(*(b+i+1)==*(b+i+2))||(*(b+i)==*(b+i+2)))&&((*(b+i)=='1'+i)||(*(b+i+1)=='2'+i)||(*(b+i+2)=='3'+i))&&(*(b+i)=='X'||*(b+i+1)=='X'||*(b+i+2)=='X'))
        {
            for(int j=i; j<i+3; j++)
            {
                if(*(b+j)!='X')
                {
                    *(b+j)='O';
                    return;
                }
            }
        }
    }
    for(int i=0; i<3; i++)
    {
        if(((*(b+i)==*(b+i+3))||(*(b+i+3)==*(b+i+6))||(*(b+i)==*(b+i+6)))&&((*(b+i)=='1'+i)||(*(b+i+3)=='4'+i)||(*(b+i+6)=='7'+i))&&(*(b+i)=='X'||*(b+i+3)=='X'||*(b+i+6)=='X'))
        {
            for(int j=i; j<9+i; j+=3)
            {
                if(*(b+j)!='X')
                {
                    *(b+j)='O';
                    return;
                }
            }
        }
    }
    if(((*(b+0)==*(b+4))||(*(b+4)==*(b+8))||(*(b+0)==*(b+8)))&&((*(b+0)=='1')||(*(b+4)=='5')||(*(b+8)=='9'))&&(*(b+0)=='X'||*(b+4)=='X'||*(b+8)=='X'))
    {
        for(int j=0; j<12; j+=4)
        {
            if(*(b+j)!='X')
            {
                *(b+j)='O';
                return;
            }
        }
    }
    else if(((*(b+2)==*(b+4))||(*(b+4)==*(b+6))||(*(b+2)==*(b+6)))&&((*(b+2)=='3')||(*(b+4)=='5')||(*(b+6)=='7'))&&(*(b+2)=='X'||*(b+4)=='X'||*(b+6)=='X'))
    {
        for(int j=2; j<8; j+=2)
        {
            if(*(b+j)!='X')
            {
                *(b+j)='O';
                return;
            }
        }
    }
    for(int i=0; i<4; i+=2)
    {
        if(*(b+i)=='1'+i)
        {
            *(b+i)='O';
            return;
        }
    }
    for(int i=6; i<10; i+=2)
    {
        if(*(b+i)=='1'+i)
        {
            *(b+i)='O';
            return;
        }
    }
    for(int i=1; i<9; i+=2)
    {
        if(*(b+i)=='1'+i)
        {
            *(b+i)='O';
            return;
        }
    }
}