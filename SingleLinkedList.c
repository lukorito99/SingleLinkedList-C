#include<stdlib.h>
#include<stdio.h>
#include<string.h>


typedef struct Node_Data
{
    int val;
    struct Node_Data* next;

} ND;

typedef struct Text_Node_Data
{

    char *Text;
    struct Text_Node_Data* follows;


} TND;

typedef struct Float_Node_Data
{
    float y;
    struct Float_Node_Data* tails;

} FND;

void DisplayWholeNum(ND* z);
void UpdateNumList(ND* t);
ND* InsertToNumList(ND* x);
int NumElementExists(ND* f, int x);
void DeleteNum(ND* v);
ND* UpdateListBegin(ND* f);

void Decimal(FND* z);
FND* InsertToDecimalList(FND* k);
int  DecimalValExists(FND* j,float h);
void DeleteDec(FND* h);
void DisplayDecimal(FND* w);
FND* UpdateDecimalListBegin(FND* q);

void UpdateTextList(TND* t);
void DisplayText(TND* v);
char* DynamicString();
TND* UpdateTextListBegin(TND* f);
TND* InsertToTextList(TND* x);
int TextExists(TND* w,char* t);
void DeleteText(TND* h);

int NumElementExists(ND* f, int x)
{
    ND* current = f;
    int freq = 0;
    while (current != NULL)
    {
        if (current->val == x)
        {
            freq++;
            current = current->next;
        }
        else
        {
            current = current->next;
        }
    }

    return freq;
}

void UpdateNumList(ND* t)
{
    ND* current = t;

    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = (ND*)malloc(sizeof(ND));

    if (current->next == NULL)  //check if malloc was successful
    {
        printf("Your data cannot be successfully stored!\n");
    }

    else
    {

        current->next->val = 0;
        current->next->next = NULL;

        printf("Enter data:\n");
        scanf("%d", &current->next->val);
    }



}

ND* UpdateListBegin(ND* f)  //pointer to head pointer
{
    if (f == NULL)
    {
        printf("List begin cannot be updated as list is empty.\n");
        return f;
    }
    else
    {

        ND* g;
        g = (ND*)malloc(sizeof(ND));

        if (g == NULL)  //check if malloc was successful
        {
            printf("Error begin of list CANNOT be updated!\n");

        }

        else
        {


            printf("List beginning can be successfully updated!\n");

            g->val = 0;
            g->next = f;


            printf("Enter data:\n");
            scanf("%d", &g->val);
            printf("List begin has been updated.\n");


        }
        return g;

    }

}

ND* InsertToNumList(ND* x)
{
    ND* current = x, * headchanged = NULL, * NodeToBeInserted = NULL, * TemporaryNode = NULL;

    int choice, data;

V:
    printf("\nDo you wish to insert before or after an already specified data?\nIf BEFORE input 1 else if AFTER input 2:\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
A:
        printf("\nOkay insert will be done BEFORE.Enter specified data:\n");
        scanf("%d",&data);


        switch (NumElementExists(current, data))
        {
        case 1:

            if (current->val == data)
            {
                printf("Insert will be done before beginning of list.\n");
                headchanged = UpdateListBegin(current);
            }
            else
            {
                headchanged = NULL;

                NodeToBeInserted = (ND*)malloc(sizeof(ND));
                if (NodeToBeInserted != NULL) //malloc was successful
                {
                    printf("\nEnter data to be inserted:\n");
                    scanf("%d", &NodeToBeInserted->val);

                    while(current!=NULL)
                    {
                        if(current->next!=NodeToBeInserted && current->next->val==data)
                        {
                            NodeToBeInserted->next=current->next;
                            current->next=NodeToBeInserted;
                            break;
                        }
                        else
                        {
                            current=current->next;
                            continue;
                        }
                    }





                }
            }
            break;



        case 0:

            printf("Specified data does not exist:\n");
            goto A;



        }
        if (NumElementExists(current, data) > 1)
        {
            printf("\nSpecified data exists more than once.\n");
            if(current->val==data)
            {
                printf("Insert will be done before beginning of list.\n");
                headchanged = UpdateListBegin(current);
                int g=NumElementExists(headchanged, data)-1,z=0;
                ND* Y[g];

                for(int i=0; i<g; i++)
                {
                    Y[i]=(ND*)malloc(sizeof(ND));
                    if(Y[i])
                    {
                        printf("Enter data to be inserted:\n");
                        scanf("%d",&Y[i]->val);
                        Y[i]->next=NULL;

                    }
                }

                ND** previous=&headchanged->next->next;
                ND *f;

                while(*previous && z<g)
                {
                    TemporaryNode=*previous;
                    if(TemporaryNode->val==data)
                    {

                        previous=&headchanged;
                        while(*previous)
                        {
                            f=*previous;
                            if(f->next==TemporaryNode)
                            {
                                f->next=Y[z];
                                Y[z]->next=TemporaryNode;
                                previous=&(f->next);

                            }
                            else
                            {
                                previous=&(f->next);
                            }
                        }


                        previous=&(TemporaryNode->next);
                        z++;

                    }
                    else
                    {
                        previous=&(TemporaryNode->next);
                    }
                }





            }
            else
            {
                int g=NumElementExists(current, data),z=0;
                ND* Q[g];
                headchanged=NULL;

                for(int i=0; i<g; i++)
                {
                    Q[i]=(ND*)malloc(sizeof(ND));
                    if(Q[i])
                    {
                        printf("Enter data to be inserted:\n");
                        scanf("%d",&Q[i]->val);
                        Q[i]->next=NULL;

                    }
                }

                ND** previous=&current;
                ND *f;

                while(*previous && z<g)
                {
                    TemporaryNode=*previous;
                    if(TemporaryNode->val==data)
                    {

                        previous=&current;
                        while(*previous)
                        {
                            f=*previous;
                            if(f->next==TemporaryNode)
                            {
                                f->next=Q[z];
                                Q[z]->next=TemporaryNode;
                                previous=&(f->next);

                            }
                            else
                            {
                                previous=&(f->next);
                            }
                        }


                        previous=&(TemporaryNode->next);
                        z++;

                    }
                    else
                    {
                        previous=&(TemporaryNode->next);
                    }
                }

            }

        }
        break;
    case 2:
        headchanged = NULL;
A1:
        printf("\nOkay insert will be done AFTER.Enter specified data:\n");
        scanf("%d", &data);

        switch(NumElementExists(current, data))
        {
        case 0:
            printf("Specified data does not exist:\n");
            goto A1;
        case 1:

            NodeToBeInserted=(ND*)malloc(sizeof(ND));
            if(NodeToBeInserted)
            {
                printf("Enter data to be inserted:\n");
                scanf("%d",&NodeToBeInserted->val);
                NodeToBeInserted->next=NULL;
            }

            while(current)
            {
                if(current->val==data)
                {
                    NodeToBeInserted->next=current->next;
                    current->next=NodeToBeInserted;
                    break;
                }
                else
                {
                    current=current->next;
                }
            }


        }

        if(NumElementExists(current, data)>1)
        {
            headchanged = NULL;
            printf("\nSpecified data exists more than once.\n");
            int g=NumElementExists(current, data),z=0;
            ND* V[g];

            for(int i=0; i<g; i++)
            {
                V[i]=(ND*)malloc(sizeof(ND));
                if(V[i])
                {
                    printf("Enter data to be inserted:\n");
                    scanf("%d",&V[i]->val);
                    V[i]->next=NULL;

                }
            }

            while(current && z<g)
            {
                if(current->val==data)
                {
                    V[z]->next=current->next;
                    current->next=V[z];
                    current=current->next;
                    z++;

                }
                else
                {
                    current=current->next;
                }
            }




        }

        break;
    default:
        headchanged = NULL;
        printf("\nUnrecognized input!\n");
        goto V;

    }

    return headchanged;

}

void DeleteNum(ND* v)
{
    ND* current = v;
    ND* j;
    ND**previous=&current;
    int to_be_deleted,l;
S:
    printf("\nEnter data to be deleted:\n");
    scanf("%d",&to_be_deleted);
    l=NumElementExists(current,to_be_deleted);

    switch(l)
    {
    case 0:
        printf("Entered data does not exist!\n");
        goto S;
    case 1:

        while(*previous)
        {
            j=*previous;

            if(j->val==to_be_deleted)
            {
                *previous=j->next;

                free(j);
            }
            else
            {
                previous=&(j->next);

            }
        }



        break;


    }

    if(l>1)
    {
        printf("Data to be deleted exists more than once.\n");

        while(*previous)
        {
            j=*previous;
            if(j->val==to_be_deleted)
            {
                *previous=j->next;
                free(j);
            }
            else
            {
                previous=&(j->next);
            }
        }



    }


    DisplayWholeNum(current);

}

void DisplayWholeNum(ND* z)
{

    ND* current = z;
    int count=1;
    while (current != NULL)
    {
        printf("\nNode %d storing %d at address: %5p\n",count,current->val, current);
        current = current->next;
        count++;
    }


}


void Decimal(FND* z)
{

    FND* current = z;

    while (current->tails != NULL)
    {
        current = current->tails;
    }
    current->tails = (FND*)malloc(sizeof(FND));

    if (current->tails == NULL)  //check if malloc was successful
    {
        printf("Your data cannot be successfully stored!\n");
    }

    else
    {

        current->tails->y = 0.00;
        current->tails->tails = NULL;

        printf("Enter data:\n");
        scanf("%f", &current->tails->y);
    }




}

FND* UpdateDecimalListBegin(FND* q)
{
    if (q == NULL)
    {
        printf("List begin cannot be updated as list is empty.\n");
        return q;
    }
    else
    {

        FND* g;
        g = (FND*)malloc(sizeof(FND));

        if (g == NULL)  //check if malloc was successful
        {
            printf("Error begin of list CANNOT be updated!\n");

        }

        else
        {


            printf("List beginning can be successfully updated!\n");

            g->y = 0.00;
            g->tails = q;


            printf("Enter data:\n");
            scanf("%f", &g->y);
            printf("List begin has been updated.\n");


        }
        return g;

    }

}

void DisplayDecimal(FND* w)
{
    FND* current = w;
    int count=1;
    while (current != NULL)
    {
        printf("\nNode %d storing %5f at address:%5p\n",count,current->y, current);
        current = current->tails;
        count++;
    }


}

int  DecimalValExists(FND* j,float h)
{
    FND* current = j;
    int freq = 0;
    while (current != NULL)
    {
        if (current->y == h)
        {
            freq++;
            current = current->tails;
        }
        else
        {
            current = current->tails;
        }
    }

    return freq;
}

FND* InsertToDecimalList(FND* k)
{
    FND* current = k, * headchanged = NULL, * NodeToBeInserted = NULL, * TemporaryNode = NULL;

    int choice;
    float data;

V:
    printf("\nDo you wish to insert before or after an already specified data?\nIf BEFORE input 1 else if AFTER input 2:\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
A:
        printf("\nOkay insert will be done BEFORE.Enter specified data:\n");
        scanf("%f", &data);


        switch (DecimalValExists(current, data))
        {
        case 1:

            if (current->y == data)
            {
                printf("Insert will be done before beginning of list.\n");
                headchanged = UpdateDecimalListBegin(current);
            }
            else
            {
                headchanged = NULL;

                NodeToBeInserted = (FND*)malloc(sizeof(FND));
                if (NodeToBeInserted != NULL) //malloc was successful
                {
                    printf("\nEnter data to be inserted:\n");
                    scanf("%f", &NodeToBeInserted->y);

                    while(current!=NULL)
                    {
                        if(current->tails!=NodeToBeInserted && current->tails->y==data)
                        {
                            NodeToBeInserted->tails=current->tails;
                            current->tails=NodeToBeInserted;
                            break;
                        }
                        else
                        {
                            current=current->tails;
                            continue;
                        }
                    }

                }
            }
            break;

        case 0:

            printf("Specified data does not exist:\n");
            goto A;

        }
        if (DecimalValExists(current, data) > 1)
        {
            printf("\nSpecified data exists more than once.\n");
            if(current->y==data)
            {
                printf("Insert will be done before beginning of list.\n");
                headchanged = UpdateDecimalListBegin(current);
                int g=DecimalValExists(headchanged, data)-1,z=0;
                FND* Y[g];

                for(int i=0; i<g; i++)
                {
                    Y[i]=(FND*)malloc(sizeof(FND));
                    if(Y[i])
                    {
                        printf("Enter data to be inserted:\n");
                        scanf("%f",&Y[i]->y);
                        Y[i]->tails=NULL;

                    }
                }

                FND** previous=&headchanged->tails->tails;
                FND *f;

                while(*previous && z<g)
                {
                    TemporaryNode=*previous;
                    if(TemporaryNode->y==data)
                    {

                        previous=&headchanged;
                        while(*previous)
                        {
                            f=*previous;
                            if(f->tails==TemporaryNode)
                            {
                                f->tails=Y[z];
                                Y[z]->tails=TemporaryNode;
                                previous=&(f->tails);

                            }
                            else
                            {
                                previous=&(f->tails);
                            }
                        }


                        previous=&(TemporaryNode->tails);
                        z++;

                    }
                    else
                    {
                        previous=&(TemporaryNode->tails);
                    }
                }

            }
            else
            {
                int g=DecimalValExists(current, data),z=0;
                FND* Q[g];
                headchanged=NULL;

                for(int i=0; i<g; i++)
                {
                    Q[i]=(FND*)malloc(sizeof(ND));
                    if(Q[i])
                    {
                        printf("Enter data to be inserted:\n");
                        scanf("%f",&Q[i]->y);
                        Q[i]->tails=NULL;

                    }
                }

                FND** previous=&current;
                FND *f;

                while(*previous && z<g)
                {
                    TemporaryNode=*previous;
                    if(TemporaryNode->y==data)
                    {

                        previous=&current;
                        while(*previous)
                        {
                            f=*previous;
                            if(f->tails==TemporaryNode)
                            {
                                f->tails=Q[z];
                                Q[z]->tails=TemporaryNode;
                                previous=&(f->tails);

                            }
                            else
                            {
                                previous=&(f->tails);
                            }
                        }


                        previous=&(TemporaryNode->tails);
                        z++;

                    }
                    else
                    {
                        previous=&(TemporaryNode->tails);
                    }
                }

            }

        }
        break;
    case 2:
        headchanged = NULL;
A1:
        printf("\nOkay insert will be done AFTER.Enter specified data:\n");
        scanf("%f", &data);

        switch(DecimalValExists(current, data))
        {
        case 0:
            printf("Specified data does not exist:\n");
            goto A1;
        case 1:

            NodeToBeInserted=(FND*)malloc(sizeof(FND));
            if(NodeToBeInserted)
            {
                printf("Enter data to be inserted:\n");
                scanf("%f",&NodeToBeInserted->y);
                NodeToBeInserted->tails=NULL;
            }

            while(current)
            {
                if(current->y==data)
                {
                    NodeToBeInserted->tails=current->tails;
                    current->tails=NodeToBeInserted;
                    break;
                }
                else
                {
                    current=current->tails;
                }
            }


        }

        if(DecimalValExists(current, data)>1)
        {
            headchanged = NULL;
            printf("\nSpecified data exists more than once.\n");
            int g=DecimalValExists(current, data),z=0;
            FND* V[g];

            for(int i=0; i<g; i++)
            {
                V[i]=(FND*)malloc(sizeof(FND));
                if(V[i])
                {
                    printf("Enter data to be inserted:\n");
                    scanf("%f",&V[i]->y);
                    V[i]->tails=NULL;

                }
            }

            while(current && z<g)
            {
                if(current->y==data)
                {
                    V[z]->tails=current->tails;
                    current->tails=V[z];
                    current=current->tails;
                    z++;

                }
                else
                {
                    current=current->tails;
                }
            }




        }

        break;
    default:
        headchanged = NULL;
        printf("\nUnrecognized input!\n");
        goto V;

    }

    return headchanged;




}

void DeleteDec(FND* h)
{

    FND* current = h;
    FND* j;
    float to_be_deleted;
S:
    printf("\nEnter data to be deleted:\n");
    scanf("%f", &to_be_deleted);
    int l=DecimalValExists(current,to_be_deleted);
    FND**previous=&current;
    switch(l)
    {
    case 0:
        printf("\nData does not exist!!\n");
        goto S;
    case 1:

        while(*previous)
        {
            j=*previous;

            if(j->y==to_be_deleted)
            {
                *previous=j->tails;

                free(j);
            }
            else
            {
                previous=&(j->tails);

            }
        }

        break;


    }

    if(l>1)
    {
        printf("Data to be deleted exists more than once.\n");

        while(*previous)
        {
            j=*previous;
            if(j->y==to_be_deleted)
            {
                *previous=j->tails;
                free(j);
            }
            else
            {
                previous=&(j->tails);
            }
        }



    }
    DisplayDecimal(current);

}

char* DynamicString()
{

    char *temp_line=NULL,*line=NULL;
    size_t size=0,index=0;
    int x=EOF;
    printf("Enter data:\n");
    while(x)
    {
        x=getc(stdin);

        if(x==EOF || x=='\n')
        {
            x=0;

        }
        if(size<=index)
        {
            size+=1;
            temp_line=realloc(line,size);
            if(!temp_line)
            {
                free(line);
                line=NULL;
                break;
            }
            line=temp_line;
        }
        line[index++]=x;
    }

    return line;
}


void UpdateTextList(TND* t)
{
    TND* current = t;

    while (current->follows != NULL)
    {
        current = current->follows;
    }
    current->follows = (TND*)malloc(sizeof(TND));

    if (current->follows == NULL)  //check if malloc was successful
    {
        printf("Your data cannot be successfully stored!\n");
    }

    else
    {
        fflush(stdin);//to clear buffer of previous variable so as not to skip when enter is pressed after input
        current->follows->Text=DynamicString();
        current->follows->follows = NULL;

    }
}

void DisplayText(TND* v)
{
    TND* current = v;
    int count=1;
    while (current != NULL)
    {
        printf("\nNode %d storing text:%3s at address:%5p\n",count,current->Text,current);

        fflush(stdin);
        current = current->follows;
        count++;
    }
}

TND* UpdateTextListBegin(TND* f)
{
    if (f == NULL)
    {
        printf("List begin cannot be updated as list is empty.\n");
        return f;
    }
    else
    {

        TND* g;
        g = (TND*)malloc(sizeof(TND));

        if (g == NULL)  //check if malloc was successful
        {
            printf("Error begin of list CANNOT be updated!\n");

        }

        else
        {
            printf("List beginning can be successfully updated!\n");

            g->follows= f;
            fflush(stdin);
            g->Text=DynamicString();
            printf("List begin has been updated.\n");

        }
        return g;
    }
}

int TextExists(TND* w,char* t)
{
    TND* current = w;
    int freq = 0;
    while (current != NULL)
    {
        if (strcmp(t,current->Text)==0)
        {
            freq++;
            current = current->follows;
        }
        else
        {
            current = current->follows;
        }
    }

    return freq;
}
TND* InsertToTextList(TND* x)
{
    TND* current = x, * headchanged = NULL, * NodeToBeInserted = NULL, * TemporaryNode = NULL;

    int choice;
    char *data;

V:
    printf("\nDo you wish to insert before or after an already specified data?\nIf BEFORE input 1 else if AFTER input 2:\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
A:
        printf("\nOkay insert will be done BEFORE.\n");
        fflush(stdin);
        data=DynamicString();


        switch (TextExists(current, data))
        {
        case 1:

            if (strcmp(current->Text,data)==0)
            {
                printf("Insert will be done before beginning of list.\n");
                headchanged = UpdateTextListBegin(current);
            }
            else
            {
                headchanged = NULL;

                NodeToBeInserted = (TND*)malloc(sizeof(TND));
                if (NodeToBeInserted != NULL) //malloc was successful
                {
                    fflush(stdin);
                    NodeToBeInserted->Text=DynamicString();

                    while(current!=NULL)
                    {
                        if(current->follows!=NodeToBeInserted && strcmp(current->follows->Text,data)==0)
                        {
                            NodeToBeInserted->follows=current->follows;
                            current->follows=NodeToBeInserted;
                            break;
                        }
                        else
                        {
                            current=current->follows;
                            continue;
                        }
                    }

                }
            }
            break;

        case 0:

            printf("Specified data does not exist:\n");
            goto A;

        }
        if (TextExists(current, data) > 1)
        {
            printf("\nSpecified data exists more than once.\n");
            if(strcmp(current->Text,data)==0)
            {
                printf("Insert will be done before beginning of list.\n");
                headchanged = UpdateTextListBegin(current);
                int g=TextExists(headchanged, data)-1,z=0;
                TND* Y[g];

                for(int i=0; i<g; i++)
                {
                    Y[i]=(TND*)malloc(sizeof(TND));
                    if(Y[i])
                    {
                        fflush(stdin);
                        Y[i]->Text=DynamicString();
                        Y[i]->follows=NULL;

                    }
                }

                TND** previous=&headchanged->follows->follows;
                TND *f;

                while(*previous && z<g)
                {
                    TemporaryNode=*previous;
                    if(strcmp(TemporaryNode->Text,data)==0)
                    {

                        previous=&headchanged;
                        while(*previous)
                        {
                            f=*previous;
                            if(f->follows==TemporaryNode)
                            {
                                f->follows=Y[z];
                                Y[z]->follows=TemporaryNode;
                                previous=&(f->follows);

                            }
                            else
                            {
                                previous=&(f->follows);
                            }
                        }


                        previous=&(TemporaryNode->follows);
                        z++;

                    }
                    else
                    {
                        previous=&(TemporaryNode->follows);
                    }
                }


            }
            else
            {
                int g=TextExists(current, data),z=0;
                TND* Q[g];
                headchanged=NULL;

                for(int i=0; i<g; i++)
                {
                    Q[i]=(TND*)malloc(sizeof(TND));
                    if(Q[i])
                    {
                        fflush(stdin);
                        Q[i]->Text=DynamicString();
                        Q[i]->follows=NULL;

                    }
                }

                TND** previous=&current;
                TND *f;

                while(*previous && z<g)
                {
                    TemporaryNode=*previous;
                    if(strcmp(TemporaryNode->Text,data)==0)
                    {

                        previous=&current;
                        while(*previous)
                        {
                            f=*previous;
                            if(f->follows==TemporaryNode)
                            {
                                f->follows=Q[z];
                                Q[z]->follows=TemporaryNode;
                                previous=&(f->follows);

                            }
                            else
                            {
                                previous=&(f->follows);
                            }
                        }


                        previous=&(TemporaryNode->follows);
                        z++;

                    }
                    else
                    {
                        previous=&(TemporaryNode->follows);
                    }
                }

            }

        }
        break;
    case 2:
        headchanged = NULL;
A1:
        printf("\nOkay insert will be done AFTER.\n");
        fflush(stdin);
        data=DynamicString();

        switch(TextExists(current, data))
        {
        case 0:
            printf("Specified data does not exist:\n");
            goto A1;
        case 1:

            NodeToBeInserted=(TND*)malloc(sizeof(TND));
            if(NodeToBeInserted)
            {
                fflush(stdin);
                NodeToBeInserted->Text=DynamicString();
                NodeToBeInserted->follows=NULL;
            }

            while(current)
            {
                if(strcmp(current->Text,data)==0)
                {
                    NodeToBeInserted->follows=current->follows;
                    current->follows=NodeToBeInserted;
                    break;
                }
                else
                {
                    current=current->follows;
                }
            }


        }

        if(TextExists(current, data)>1)
        {
            headchanged = NULL;
            printf("\nSpecified data exists more than once.\n");
            int g=TextExists(current, data),z=0;
            TND* V[g];

            for(int i=0; i<g; i++)
            {
                V[i]=(TND*)malloc(sizeof(ND));
                if(V[i])
                {
                    fflush(stdin);
                    V[i]->Text=DynamicString();
                    V[i]->follows=NULL;

                }
            }

            while(current && z<g)
            {
                if(strcmp(current->Text,data)==0)
                {
                    V[z]->follows=current->follows;
                    current->follows=V[z];
                    current=current->follows;
                    z++;

                }
                else
                {
                    current=current->follows;
                }
            }




        }

        break;
    default:
        headchanged = NULL;
        printf("\nUnrecognized input!\n");
        goto V;

    }

    return headchanged;

}

void DeleteText(TND* h)
{
    TND* current = h;
    TND* j;
    char* to_be_deleted;
    fflush(stdin);
S:
    to_be_deleted=DynamicString();

    int l=TextExists(current,to_be_deleted);
    TND**previous=&current;
    switch(l)
    {
    case 0:
        printf("Entered data does not exist!\n");
        goto S;
    case 1:

        while(*previous)
        {
            j=*previous;

            if(strcmp(j->Text,to_be_deleted)==0)
            {
                *previous=j->follows;
                free(j);
            }
            else
            {
                previous=&(j->follows);
            }
        }

        break;


    }

    if(l>1)
    {
        printf("Data to be deleted exists more than once.\n");

        while(*previous)
        {
            j=*previous;
            if(strcmp(j->Text,to_be_deleted)==0)
            {
                *previous=j->follows;
                free(j);
            }
            else
            {
                previous=&(j->follows);
            }
        }

    }

    DisplayText(current);
}

int main()
{
    //Pointers to First item of respective list
    ND* head = NULL;
    ND* new_head = NULL;//if UpdateListBegin is called
    ND* new_head_updated=NULL;//Insert is done before head

    TND* textbegin = NULL;
    TND* new_textbegin = NULL;//if UpdateDecimalListBegin is called
    TND* new_textbegin_updated=NULL;//Insert is done before head

    FND* point = NULL;
    FND* new_point = NULL;//if UpdateDecimalListBegin is called
    FND* new_point_updated=NULL;//Insert is done before head

    int response;
    char d;
    int confirm, Delete, insertornot;

X:
    printf("What data do you wish to store?\nInput 1 if whole numbers,2 if decimal,3 if text and 4 in NO.\n");

    while(!(scanf("%d",&response)))
    {
        fflush(stdin);
        goto X;
    }

    switch (response)
    {
    case 1:
        head = (ND*)malloc(sizeof(ND));
        if (!head)  //check if malloc was successful
        {
            printf("\nYour data cannot be successfully stored!\n");
        }

        else
        {

            printf("\nYour data can be successfully stored!\n");
            head->val = 0;
            head->next = NULL;

            printf("\nEnter data:\n");
            scanf("%d",&head->val);
        }



        for (; 1 == 1;)
        {

            printf("\nTo stop data input enter C else input P \n");
            scanf(" %c", &d);
            if (d == 'C')
            {
                break;
            }
            else
            {
                UpdateNumList(head);
                continue;
            }


        }

A:
        printf("\nDo you wish to update beginning of list?\nIf so input 1 else input 2\n");

        while(!(scanf("%d",&confirm)))
        {
            fflush(stdin);
            goto A;
        }

        switch (confirm)
        {
        case 1:
            new_head = UpdateListBegin(head);
            DisplayWholeNum(new_head);
            break;
        case 2:
            printf("\nBeginning of List will not be updated.\n");
            DisplayWholeNum(head);
            break;
        default:
            printf("\nUnrecognized input!!\n");
            goto A;
        }


F:
        printf("\nDo you wish to insert new data?\nIf so input 1 else input 2\n");
        while(!(scanf("%d",&insertornot)))
        {
            fflush(stdin);
            goto F;
        }

        switch (insertornot)
        {
        case 1:
            if(new_head!=NULL)
            {
                new_head_updated=InsertToNumList(new_head);
                if(new_head_updated!=NULL)
                {
                    DisplayWholeNum(new_head_updated);
                }
                else
                {
                    DisplayWholeNum(new_head);
                }
            }
            else
            {
                new_head_updated=InsertToNumList(head);
                if(new_head_updated!=NULL)
                {
                    DisplayWholeNum(new_head_updated);
                }
                else
                {
                    DisplayWholeNum(head);
                }
            }

            break;
        case 2:
            printf("\nOkay no insert of new data will be done\n");
            break;
        default:
            printf("\nUnrecognized input!\n");
            goto F;
        }

B:
        printf("\nDo you wish to delete data?\nIf so input 1 else input 2\n");
        while(!(scanf("%d",&Delete)))
        {
            fflush(stdin);
            goto B;
        }
        switch (Delete)
        {

        case 1:
            //Neither UpdateListBegin or Insert was done before head
            if(new_head==NULL && new_head_updated==NULL)
            {
                DeleteNum(head);
            }
            //UpdateListBegin was called but insert was not before head
            if(new_head!=NULL && new_head_updated==NULL)
            {
                DeleteNum(new_head);
            }
            //UpdateListBegin was called  and Insert was before head
            if(new_head!=NULL&& new_head_updated!=NULL)
            {
                DeleteNum(new_head_updated);
            }
            //Only Insert was before head called
            if(new_head_updated!=NULL)
            {
                DeleteNum(new_head_updated);
            }
            break;
        case 2:
            printf("\nNo data will be deleted.Records will remain as:\n");
            //Neither UpdateListBegin or Insert was done before head
            if(new_head==NULL && new_head_updated==NULL)
            {

                DisplayWholeNum(head);

            }
            //UpdateListBegin was called
            if(new_head!=NULL && new_head_updated==NULL)
            {

                DisplayWholeNum(new_head);
            }
            //UpdateListBegin was called  and Insert was before head
            if(new_head!=NULL)
            {
                if(new_head_updated!=NULL)
                {

                    DisplayWholeNum(new_head_updated);

                }
            }

            break;
        default:
            printf("Unrecognized input!\n");
            goto B;

        }

        break;
    case 2:
        point = (FND*)malloc(sizeof(FND));
        if (point == NULL)  //check if malloc was successful
        {
            printf("\nYour data cannot be successfully stored!\n");
        }

        else
        {
            printf("\nYour data can be successfully stored!\n");
            point->y = 0.00;
            point->tails = NULL;

            printf("\nEnter data:\n");
            scanf("%f", &point->y);
        }

        for (; 1 == 1;)
        {

            printf("\nTo stop data input enter C else input P \n");
            scanf(" %c", &d);
            if (d == 'C')
            {
                break;
            }
            else
            {
                Decimal(point);
                continue;
            }

        }

A1:
        printf("\nDo you wish to update beginning of list?\nIf so input 1 else input 2\n");
        while(!(scanf("%d",&confirm)))
        {
            fflush(stdin);
            goto A1;
        }

        switch (confirm)
        {
        case 1:

            new_point = UpdateDecimalListBegin(point);
            DisplayDecimal(new_point);

            break;
        case 2:
            printf("\nBeginning of List will not be updated.\n");
            DisplayDecimal(point);
            break;
        default:
            printf("\nUnrecognized input!!\n");
            goto A1;
        }

F1:
        printf("\nDo you wish to insert new data?\nIf so input 1 else input 2\n");
        while(!(scanf("%d",&insertornot)))
        {
            fflush(stdin);
            goto F1;
        }
        switch (insertornot)
        {
        case 1:

            if(new_point!=NULL)
            {
                new_point_updated=InsertToDecimalList(new_point);
                if(new_point_updated!=NULL)
                {
                    DisplayDecimal(new_point_updated);
                }
                else
                {
                    DisplayDecimal(new_point);
                }
            }
            else
            {
                new_point_updated=InsertToDecimalList(point);
                if(new_point_updated!=NULL)
                {
                    DisplayDecimal(new_point_updated);
                }
                else
                {
                    DisplayDecimal(point);
                }
            }


            break;
        case 2:
            printf("\nOkay no insert of new data will be done\n");

            break;
        case 3:
            printf("\nUnrecognized input!\n");
            goto F1;
        }

B1:
        printf("\nDo you wish to delete data?\nIf so input 1 else input 2\n");
        while(!(scanf("%d",&Delete)))
        {
            fflush(stdin);
            goto B1;
        }

        switch (Delete)
        {

        case 1:
            //Neither UpdateDecimalListBegin or Insert was done before head
            if(new_point==NULL && new_point_updated==NULL)
            {
                DeleteDec(point);
            }
            //UpdateListBegin was called but insert was not before head
            if(new_point!=NULL && new_point_updated==NULL)
            {
                DeleteDec(new_point);

            }
            //UpdateListBegin was called  and Insert was before head
            if(new_point!=NULL&& new_point_updated!=NULL)
            {

                DeleteDec(new_point_updated);

            }
            //Only Insert was before head called
            if(new_point_updated!=NULL)
            {
                DeleteDec(new_point_updated);
            }
            break;
        case 2:
            printf("\nNo data will be deleted.Records will remain as:\n");
            //Neither UpdateDecimalListBegin or Insert was done before head
            if(new_point==NULL && new_point_updated==NULL)
            {

                DisplayDecimal(point);

            }
            //UpdateDecimalListBegin was called
            if(new_point!=NULL && new_point_updated==NULL)
            {

                DisplayDecimal(new_point);
            }
            //UpdateDecimalListBegin was called  and Insert was before head
            if(new_point!=NULL)
            {
                if(new_point_updated!=NULL)
                {

                    DisplayDecimal(new_point_updated);

                }
            }

            break;
        default:
            printf("Unrecognized input!\n");
            goto B;

        }

        break;
    case 3:
        textbegin = (TND*)malloc(sizeof(TND));
        if (!textbegin)  //check if malloc was successful
        {

            printf("\nYour data cannot be successfully stored!\n");
        }
        else
        {
            fflush(stdin);
            printf("\nYour data can be successfully stored!\n");
            textbegin->Text=DynamicString();

            textbegin->follows = NULL;

        }
        for (; 1 == 1;)
        {
            printf("\nTo stop data input enter C else input P \n");
            scanf(" %c", &d);
            if (d == 'C')
            {
                break;
            }
            else
            {
                UpdateTextList(textbegin);
                continue;
            }

        }

A2:
        printf("\nDo you wish to update beginning of list?\nIf so input 1 else input 2\n");
        while(!(scanf("%d",&confirm)))
        {
            fflush(stdin);
            goto A2;
        }
        switch (confirm)
        {
        case 1:
            new_textbegin = UpdateTextListBegin(textbegin);
            DisplayText(new_textbegin);
            break;
        case 2:
            printf("\nBeginning of List will not be updated.\n");
            DisplayText(textbegin);
            break;
        default:
            printf("\nUnrecognized input!!\n");
            goto A2;
        }

F2:
        printf("\nDo you wish to insert new data?\nIf so input 1 else input 2\n");
        while(!(scanf("%d",&insertornot)))
        {
            fflush(stdin);
            goto F2;
        }
        switch (insertornot)
        {
        case 1:
            if(new_textbegin!=NULL)
            {
                new_textbegin_updated=InsertToTextList(new_textbegin);
                if(new_textbegin_updated!=NULL)
                {
                    DisplayText(new_textbegin_updated);
                }
                else
                {
                    DisplayText(new_textbegin);
                }
            }
            else
            {
                new_textbegin_updated=InsertToTextList(textbegin);
                if(new_textbegin_updated!=NULL)
                {
                    DisplayText(new_textbegin_updated);
                }
                else
                {
                    DisplayText(textbegin);
                }
            }
            break;
        case 2:
            printf("\nOkay no insert of new data will be done\n");
            break;
        case 3:
            printf("\nUnrecognized input!\n");
            goto F2;
        }

B2:
        printf("\nDo you wish to delete data?\nIf so input 1 else input 2\n");
        while(!(scanf("%d",&Delete)))
        {
            fflush(stdin);
            goto B2;
        }

        switch (Delete)
        {
        case 1:
            //Neither UpdateTextListBegin or Insert was done before head
            if(new_textbegin==NULL && new_textbegin_updated==NULL)
            {
                DeleteText(textbegin);
            }
            //UpdateTextBegin was called but insert was not before head
            if(new_textbegin!=NULL && new_textbegin_updated==NULL)
            {
                DeleteText(new_textbegin);
            }
            //UpdateTextBegin was called  and Insert was before head
            if(new_textbegin!=NULL&& new_textbegin_updated!=NULL)
            {
                DeleteText(new_textbegin_updated);
            }
            //Only Insert was before head called
            if(new_textbegin_updated!=NULL)
            {
                DeleteText(new_textbegin_updated);
            }
            break;
        case 2:
            printf("\nNo data will be deleted.Records will remain as:\n");
            //Neither UpdateTextListBegin or Insert was done before head
            if(new_textbegin==NULL && new_textbegin_updated==NULL)
            {

                DisplayText(textbegin);

            }
            //UpdateTextListBegin was called
            if(new_textbegin!=NULL && new_textbegin_updated==NULL)
            {

                DisplayText(new_textbegin);
            }
            //UpdateTextListBegin was called  and Insert was before head
            if(new_textbegin!=NULL)
            {
                if(new_textbegin_updated!=NULL)
                {

                    DisplayText(new_textbegin_updated);

                }
            }

            break;
        default:
            printf("Unrecognized input!\n");
            goto B2;


        }

        break;
    case 4:
        printf("Okay.\n");
        break;
    default:
        printf("Unrecognized input!\n");
        goto X;

    }

}
