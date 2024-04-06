#include "Prim.h"
#include "Kruskal.h"
#include <chrono>
#include <fstream>

int main()
{
    int n = 1000; // number of vertices
    int density = 100;
    int howmany = 100; // how many times to run
    //Graph_list Gl(5);
    //Gl.randomize(100);
    //Gl.display();
    //Prim_list(&Gl,1);
    //Kruskal_list(&Gl,1);
    //Graph_mat G(5);
    //G.randomize(100);
    //G.display();
    //Prim_mat(&G,1);
    //Kruskal_mat(&G,1);

    double sum=0;
    
    
    for(int i = 0; i < howmany; i++){
        cout << i << endl; // progress
        //Graph_list G(n);
        Graph_mat G(n);
        G.randomize(density);
        auto start = chrono::high_resolution_clock::now();
        //Prim_list(&G,0);
        //Kruskal_list(&G,0);
        //Prim_mat(&G,0);
        Kruskal_mat(&G,0);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop-start);
        //cout << duration.count() << endl;
        //plik << duration.count() << endl;
        sum += duration.count();
        }
    cout << "Average time (microseconds): " << sum/howmany << endl;
}
