// lab7.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <istream>
#include <stdlib.h>
//#include "head.h"

using namespace std;

class Matrix
{
private:
        float** mat;
        int columns,rows;
public:
        Matrix();
        Matrix(int,int);
        ~Matrix();
        string getCell(int, int);
        string getColumn(int);
        string getRow(int);
        string getRow_file(int);
        string getMatrix();

        void zeros(int,int);

        void addition(float);
        void changevalue(int,int,float);
        void transposition();

		void add(float);
		void multiple(float);
		void sub(float);

        void writefile(string);
        void readfile(string);
};

Matrix::Matrix()
{
        columns=0;
        rows=0;
}


Matrix::Matrix(int _columns, int _rows)
{
        columns = _columns;
        rows = _rows;
        mat = new float*[columns];
        for(int i=0;i<columns;i++)
        {
                mat[i]=new float[rows];        
        }
        for(int i=0; i<columns;i++)
        {
                for(int j=0; j<rows; j++)
                {
                        mat[i][j]=0;
                }
        }
}


Matrix::~Matrix()
{
        delete[] mat;
}

string Matrix::getCell(int row, int column)
{
        if(row>rows || column>columns)
        {
                return("Error");
        }

        stringstream ss;
        ss << mat[column-1][row-1];
        return(ss.str());
}

string Matrix::getRow(int row)
{
        stringstream ss;
        if(row>=rows)
        {
                return("Niema takiego wiersza");
        }
        else
        {
                for(int i=0;i<columns;i++)
                {
                        ss << mat[i][row-1];
                        ss << " ";
                }
        return(ss.str());
        }
}

string Matrix::getRow_file(int row)
{
        stringstream ss;
        if(row>=rows)
        {
                return("Niema takiego wiersza");
        }
        else
        {
                for(int i=0;i<columns;i++)
                {
                        
                                ss << mat[i][row];
                                ss << ";";
                }
        return(ss.str());
        }
}

string Matrix::getColumn(int column)
{
        stringstream ss;
        if (column>columns)
        {
                return("Niema takiej komumny");
        }
        else
        {
                for(int i=0;i<rows;i++)
                {
                        ss << mat[i][column-1];
                        ss << endl;
                }
                return(ss.str());
        }
}

string Matrix::getMatrix()
{
        stringstream ss;
        for (int i = 0; i < columns; i++)
        {
                for (int j = 0; j < rows; j++)
                {
                        ss << mat[i][j];
                        ss << " ";
                }
                ss<<endl;
        }
        return(ss.str());
}

void Matrix::zeros(int _rows, int _columns)
{
        for (int i=0; i<columns; i++)
        {
                for (int j=0; j<rows; j++)
                {
                        mat[i][j]=0;
                };
        };

}


void Matrix::addition(float number)
{
        for(int i=0; i<rows;i++)
        {
                for(int j=0; j<columns; j++)
                {
                        mat[i][j]+=number;
                }
        }
}

void Matrix::changevalue(int row,int column, float value)
{
        if((row-1>rows || row-1<0) || (column-1>columns || column-1<0))
        {
                cout << "Error"<<endl;
        }
        else
        {
                mat[row-1][column-1]=value;
        }

}


void Matrix::transposition()
{
        float** tmp = new float*[columns];
        for (int i = 0; i < columns; i++)
        {
                tmp[i]= new float[rows];
        }

        for(int i=0;i<columns;i++)
        {
                for(int j=0;j<rows;j++)
                {
                        tmp[i][j]=mat[i][j];
                } 

        } 
        int tmprow=rows;
        int tmpcol=columns;
        
        columns = tmprow;
        rows = tmpcol;

        delete [] mat;

        mat = new float*[columns];
        for(int i=0;i<columns;i++)
        {
                mat[i]=new float[rows];
        }

        for(int i=0;i<columns;i++)
        {
                for(int j=0;j<rows;j++)
                {
                        mat[i][j]=tmp[j][i];
                }

        }


}

void Matrix::add(float num){
	for(int i=0;i<rows;i++)
	{
		for (int j=0;j<columns;j++)
		{


		}
	}

	
}


void Matrix::sub(float num){

	for(int i=0;i<rows;i++)
	{
		for(int j=0; j<columns;j++)
		{

		}
	}

}

void Matrix::multiple(float num)
{
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{


		}

	}

}

void Matrix::writefile(string filename)
{
        filename+=".txt";
        ofstream outputfile(filename);
         if(!outputfile.is_open())
        {
                throw exception("Can't read file");
        }
         for(int i=0;i<rows;i++)
         {
                 if(i!=rows-1)
                 {
                        outputfile << getRow_file(i) << endl;
                 }
                 else
                 {
                         outputfile << getRow_file(i);
                 }

         }
         outputfile.close();
}

void Matrix::readfile(string filename)
{
        filename+=".txt";
        string lines; 
        int accrow=0, acccol=0;
        int rownum=0, colnum=0;
        string* datstring;

        string* tmp;
        int tmpcol=0;
        int tmprow=0;
        float tmpcell;

        ifstream inputFile(filename);
         if (!inputFile.is_open())
                throw exception("Can't read file");

        while (!inputFile.eof())
        {
                inputFile >> lines;
                accrow++;
        }
                while (lines[colnum]!=0)
                {
                        colnum++;
                        if(lines[colnum]==';')
                        {
                                acccol++;
                        }
                        
                }

                zeros(accrow,acccol);
                tmp=new string[acccol];

                inputFile.seekg(0,ios::beg);
                while(!inputFile.eof())
                {
                        inputFile >> lines;
                        colnum=0;
                        while (lines[colnum]!=0)
                        {
                                if(lines[colnum]!=';')
                                {
                                        tmp[tmpcol]+=lines[colnum];
                                }
                                else
                                {
                                        istringstream iss(tmp[tmpcol]);
                                        iss >> tmpcell;
                                        changevalue(tmpcol+1,rownum+1,tmpcell);
                                        tmpcol++;
                                }
                                colnum++;

                        } 
                        rownum++;
                        istringstream iss(tmp[0]);
                        iss >> tmpcell;

                        tmpcol=0; 
                        tmp=new string[acccol];
                } 
                inputFile.close();
}

int _tmain(int argc, _TCHAR* argv[])
{
      /*   float** macierz = new float*[3];
        for (int i = 0; i < 3; i++)
        {
                macierz[i]= new float[3];
        }
        macierz[0][0] = 12; macierz[0][1] = 22; macierz[0][2] = 14;
        macierz[1][0] = 54; macierz[1][1] = 6 ; macierz[1][2] = 66;
        macierz[2][0] = 59; macierz[2][1] = 79; macierz[2][2] = 90;
		*/
        
        Matrix* macierz1 = new Matrix(3,4);

       /* macierz1->readfile("primary.txt");
        macierz1->changevalue(1,1,9);
        macierz1->changevalue(3,3,7);
        macierz1->changevalue(2,2,1);*/
        cout << endl << macierz1->getMatrix() << endl;

       /* macierz1->writefile("secondary");

         Matrix* macierz2 = new Matrix(3,4);
        macierz2->readfile("secondary");
        macierz2->transposition();
		cout << endl << macierz2->getMatrix() << endl;
        macierz2->writefile("third");  
        
        Matrix* macierz3 = new Matrix(4,3);
        macierz3->readfile("third");
        macierz3->addition(5);
        macierz3->writefile("fourth"); */

//		cout << macierz1->getMatrix() << endl;
        system("pause");
        return 0;
}
