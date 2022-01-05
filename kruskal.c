#include<stdio.h>
#define max 7
int graph[max][max],n=0,a=0,value[max];

void insertedge();
void sort();
void kruskal();
int find(int x);
void uni(int a,int b);
void print();

struct edgelist
{
    int start,end,w;
}edge[max],A[max];



int main()
{
    int i,j;
    printf("Enter the adjacent matrix\n");
    for(i=0;i<max;i++)
        for(j=0;j<max;j++)
            scanf("%d",&graph[i][j]);
    insertedge();
    sort();
    kruskal();
    print();
    return 0;
}

void insertedge()
{
    int i,j;
    for(i=0;i<max;i++)
        for(j=0;j<max;j++)
        {
            if(i==j)
                break;
            if(graph[i][j]!=0)
            {
               edge[n].start=i;
               edge[n].end=j;
               edge[n].w=graph[i][j];
               n++;
            }   
        }
    for(i=0;i<max;i++)
        value[i]=i;
            
}

void sort()
{
    int i,j;
    struct edgelist temp;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if(edge[j].w>edge[j+1].w)
            {
                temp = edge[j+1];
                edge[j+1]=edge[j];
                edge[j]=temp;
            }
}

void kruskal()
{
    int i;
    for(i=0;i<n;i++)
    {
        if(find(edge[i].start)!=find(edge[i].end))
        {

            A[a]=edge[i];
            uni(edge[i].start,edge[i].end);
            a++;
        }
    }

}

int find(int x)
{
    if(value[x]!=x)
    {
        return find(value[x]);
    }
    else
        return x;
}

void uni(int a,int b)
{
    value[find(a)]=b;
}

void print()
{
    int i,cost=0;
    printf("The edge of minimal spaning tree\n");
    for(i=0;i<a;i++)
    {
        printf("%d - %d : %d\n",A[i].end,A[i].start,A[i].w);
        cost=cost+A[i].w;
    }
    printf("cost value:%d",cost);
}
