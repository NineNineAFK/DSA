#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define INF 9999999
#define V 3

int G[V][V]{
    {0,5,2},
    {5,0,1},
    {2,1,0},
};

int main(){
    int no_edge;
    int selected[V];

    memset(selected,false, sizeof(selected));

    no_edge=0;
    selected[V]=true;
    int x,y;

    printf("edge: weight\n");
     
    while(no_edge<V-1){

        int min=INF;
        x=0;
        y=0;

        for (int i=0; i < V, i++) {
            if ( selected[i]){

                for (int j=0; j < V; j++ ){
                    if( !selected[j] && G[i][j] ){
                        if (min>G[i][j]){
                            min=G[i][j];
                            i=x;
                            j=y;

                        }
                    }
                }
            }
        } printf("%d  %d  %d", x, y, G[x][y]);
            selected[y]=true;
            ++no_edge;




    }







return 0;


}