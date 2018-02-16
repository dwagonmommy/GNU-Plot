// Demo of sending data via temporary files.  The default is to send data to gnuplot directly
// through stdin.
//
// Compile it with:
//   g++ -o example-tmpfile example-tmpfile.cc -lboost_iostreams -lboost_system -lboost_filesystem

#include <map>
#include <vector>
#include <cmath>
#include <Math.h>
#include <stdlib.h>
#include <string>

#include "gnuplot-iostream.h"
using namespace std;

typedef vector< vector<float> > Matrix;
typedef vector<float> Row;

int findDet(Matrix arrayIn,int inputs)
{
    float det = 0;
        if(inputs == 2)
            {
    return det = arrayIn[0][0] * arrayIn[1][1] - arrayIn[0][1]*arrayIn[1][0];
            }
            else{
            
            
            for(int i = 0; i < inputs; i++)
            {
                const size_t N = inputs - 1; // the dimension of the matrix
                Matrix newmatrix;
                
                int posa = 0;
                int posb = 0;
                for(int a = 0; (a < inputs - 1 && (posa < inputs)); a++)
                {
                    Row row(N);
                    posb = 0;
                    if(a == 0)
                        {
                            posa++;
                        }
                        
                        
                    
                    
                    for(int b = 0; (b < inputs - 1 && posb < inputs); b++)
                    {
                        if(b == i)
                        {
                            posb++;
                        }
                        row[b] = arrayIn[posa][posb];
                        posb++;
                    }
                    posa++;
                    newmatrix.push_back(row);
                    
                }
                
                

                
                
                int lowerT = findDet(newmatrix,inputs-1);               
                det = det + arrayIn[0][i]*pow(-1,i) * lowerT;
                


            }
                
            }
    return det;
    
}

int findcofactor(Matrix arrayIn,int inputs,int y,int x)
{
    float det = 0;
    const size_t N = inputs - 1; // the dimension of the matrix
    Matrix newmatrix;
                int posa = 0;
                int posb = 0;
                for(int a = 0; (a < inputs - 1 && (posa < inputs)); a++)
                {
                    Row row(N);
                    posb = 0;
                    if(a == x)
                        {
                            posa++;
                        }
                        
                        
                    
                    
                    for(int b = 0; (b < inputs - 1 && posb < inputs); b++)
                    {
                        if(b == y)
                        {
                            posb++;
                        }
                        row[b] = arrayIn[posa][posb];
                        posb++;
                    }
                    posa++;
                    newmatrix.push_back(row);
                    
                }
                    return findDet(newmatrix,inputs-1);
            }
                
            

    




int main() {
	Gnuplot gp;
        gp << "set terminal ggi\n";
        gp << "set key bmargin left\n";
        int numInputs;
        cout << "How many inputs?" << endl;
        cin >> numInputs;
        
        int numsx[numInputs];
        int numsy[numInputs];
        int c, d, swap;
        cout << "Enter inputs(x input then y input): " << endl;
        for(int i = 0; i < numInputs;i++)
        {
            double x;
            double y;
            cin >> x;
            cin >> y;
            numsx[i] = x;
            numsy[i] = y;
        }
        
          
const size_t N = numInputs; // the dimension of the matrix
Matrix polymatrix;
system("clear");
        for(size_t i = 0; i < N; ++i)
{
    Row row(N);
    
    for(size_t j = 0; j < N; ++j)
    {   

        int pos = j;

        //row[j] = numin;
        
        row[N-1-j] = pow(numsx[i],pos);
    }

    polymatrix.push_back(row); // push each row after you fill it
}
      
        int determinant =  findDet(polymatrix,numInputs);
        
        if(numInputs == 2)
        {
            for(int i = 0; i < numInputs; i++)
            {
                for(int j = 0; j < numInputs; j++)
                {
                    polymatrix[i][j] = ((1.0/determinant)* pow(-1,i+j) * polymatrix[i][j]);
                }
            }
            float temp = polymatrix[0][0];
            polymatrix[0][0] = polymatrix[1][1];
            polymatrix[1][1] = temp;
        }
        else
        {


            const size_t M = numInputs; // the dimension of the matrix
            //if size 2 skip
            Matrix cofactormatrix;

                    for(size_t i = 0; i < M; ++i)
            {
                Row row(M);

                for(size_t j = 0; j < M; ++j)
                {
                    int cofactorNeg = 1;
                    if((i+j)%2==1)
                    {
                        cofactorNeg = cofactorNeg*-1;
                    }
                    row[j] = cofactorNeg * findcofactor(polymatrix,numInputs,i,j);
                }

                cofactormatrix.push_back(row); // push each row after you fill it
            }


            const size_t Z = numInputs; // the dimension of the matrix
            //if size 2 skip
            Matrix transCofMatrix;

                    for(size_t i = 0; i < Z; ++i)
            {
                Row row(Z);

                for(size_t j = 0; j < Z; ++j)
                {
                    row[j] = cofactormatrix[j][i];
                }

                transCofMatrix.push_back(row); // push each row after you fill it
            }
            for(int i = 0; i < numInputs; i++)
            {
                for(int j = 0; j < numInputs; j++)
                {
                    polymatrix[i][j] = ((1.0/determinant)* cofactormatrix[i][j]);
                }
            }
        }
        
        float result[numInputs];
        for(int i = 0;i < numInputs;i++)
        {
            result[i] = 0;
            for(int j = 0;j <numInputs;j++)
            {
                result[i] = result[i] + (polymatrix[i][j] * numsy[j]);
            }
        }
        

        string resultString = "";
 
        for(int i = 0; i < numInputs;i++)
        {
            ostringstream convert;
            ostringstream convert2;  
            if(i == numInputs - 1)
            {
                convert << result[i];
                resultString = resultString + convert.str();
            }
            else
            {
                convert << result[i];
                convert2 << numInputs - 1 - i;
                resultString = resultString + "(" + convert.str() + "*x)**" + convert2.str() + "+"; 
            }
        }
        gp << "set multiplot" << endl;
        
        gp << "plot";
        for(int i = 0; i < numInputs - 1; i++)
        {
            gp << " '-' w p ls 1,";\
        }
        gp << " '-' w p ls 1, ";
        gp << "(" << resultString << ") w l ls 1 " << endl;
        for(int i = 0; i < numInputs; i++)
        {
        
        gp << numsx[i] << " " << numsy[i] << endl;
        gp << "e" << endl;
        }
        
        
        


        
	// Data will be sent via a temporary file.  These are erased when you call
	// gp.clearTmpfiles() or when gp goes out of scope.  If you pass a filename
	// (e.g. "gp.file1d(pts, 'mydata.dat')"), then the named file will be created
	// and won't be deleted (this is useful when creating a script).
	//gp << "plot" << gp.file1d(xy_pts_A) << "with lines title 'cubic'" << std::endl;
        cin.get();
        cin.get();
        std::cout << "Press enter to exit." << std::endl;
	std::cin.get();
        gp << "exit" << endl;
         
        return 0;

}