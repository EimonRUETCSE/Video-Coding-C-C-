#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

ifstream::pos_type size;
char *memblock;
ofstream outFile,errorFile;

int main()
{
    ifstream file("D:\\Video Compression\\Block_Based_ME&MC\\Without_Boundary\\foreman.yuv",ios::in|ios::ate);

    if(file.is_open()){
        size=file.tellg();
        unsigned char* memblock;
        memblock=new unsigned char [size];
        file.seekg(0,ios::beg);
        file.read((char*)memblock,size);

        cout<<"The complete file count is in memory.\n\n\n";

       // for(int l=0;l<size;l++){
       //     cout<<"memblock[] is = "<<(int)memblock[l]<<" index was l = "<<l<<endl;

       // }
       // file.close();
       int y1[200][200];
        //int k=((270-1)*(176*144))+((270-1)*2*(88*72));
        int k=0;
    for(int i=0;i<144;i++){
             for(int j=0;j<176;j++){



        y1[i][j]=(int)memblock[k];
        k++;


       }

       }

       outFile.open("Y_frame(1).txt");
       for(int i=0;i<144;i++){
             for(int j=0;j<176;j++){
       // cout<<y1[i][j]<<'\t';
        outFile<<y1[i][j]<<',';

             }
            // cout<<'\n';
             outFile<<"\n\n";
             }
            cout<<"Frame 1 has been saved as ref. frame."<<"\n";
             outFile.close();

        int y2[200][200];
        // k=2*(176*144)+2*2*(88*72);
        // k=((271-1)*(176*144))+((271-1)*2*(88*72));
        k=3*(176*144)+(3*2*(88*72));
    for(int i=0;i<144;i++){
             for(int j=0;j<176;j++){



        y2[i][j]=(int)memblock[k];
        k++;


       }

       }

             outFile.open("Y_frame(4).txt");
       for(int i=0;i<144;i++){
             for(int j=0;j<176;j++){
        //cout<<y2[i][j]<<'\t';
        outFile<<y2[i][j]<<',';

             }
            // cout<<'\n';
             outFile<<"\n\n";
             }
            cout<<"Frame 4 has been saved as Current Frame."<<"\n";
             outFile.close();
               //cout<<y2[][]<<'\t';

///////////////block 16X16///////////
cout<<"\n\nEnter p(1-8)= "<<endl;
int p;
cin>>p;
p=((2*p)+1);
int block_1[16][16],block_2[16][16];
int pos_x=0,pos_y=0;
int p1[]={0,1,-1,2,-2,3,-3,4,-4,5,-5,6,-6,7,-7,8,-8};
int p2[]={0,1,-1,2,-2,3,-3,4,-4,5,-5,6,-6,7,-7,8,-8};
long int error=INFINITY;
long int temp_error[16][16];
int temp_error_new [16][16];
int p_x=0,p_y=0;
int flag=0;
int minimal_error_matrix[16][16];
long long int new_sum=0;
 outFile.open("Result.txt");
 errorFile.open("ErrorFile.txt");

    cout<<"\n\nProcessing";
    for(int pos_y=0;pos_y<144;pos_y=pos_y+16){
            for(int pos_x=0;pos_x<176;pos_x=pos_x+16){
                    cout<<"...";
       // cout<<"Block Position(Current Frame)="<<(pos_x)<<","<<(pos_y)<<"\n";
        outFile<<"Block Position(Current Frame)="<<(pos_x)<<","<<(pos_y)<<"\n\n";
         errorFile<<"Current block= "<<(pos_x)<<","<<(pos_y)<<" -->";
             for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){
             block_2[i][j]=y2[pos_y+i][pos_x+j];


                    }
             }

             ////////////////


          //   for(int i=0;i<16;i++){
                //    for(int j=0;j<16;j++){
                        //    outFile<<block_2[i][j]<<",";
                   // }
                   // outFile<<"\n";
           //  }


outFile<<"------------------------------\n";


for(int l=0;l<p;l++){


        for(int k=0;k<p;k++){

                flag=0;

                if((pos_x+p1[l])<0 || (pos_x+p1[l]>175)||(pos_y+p2[k])<0 || (pos_y+p1[k]>143)) {
                    flag=1;
outFile<<"Block Position(ref. frame)="<<(pos_x+p1[l])<<","<<(pos_y+p2[k])<<"-->"<<"Invalid!\n";
};




                if(flag==0){
//cout<<"Block Position(ref. frame)="<<(pos_x+p1[l])<<","<<(pos_y+p2[k])<<"\n";
 outFile<<"Block Position(ref. frame)="<<(pos_x+p1[l])<<","<<(pos_y+p2[k])<<"-->"<<"Error= ";

              for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){
             block_1[i][j]=y1[pos_y+p2[k]+i][pos_x+p1[l]+j];


                    }
             }

             ///////////////////////

          //   for(int i=0;i<16;i++){
               //     for(int j=0;j<16;j++){

                      //  outFile<<block_1[i][j]<<",";

                   // }
                   // outFile<<"\n";
            // }


for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){

            temp_error[i][j]=pow((block_2[i][j]-block_1[i][j]),2);// sum of sqared error


                    }

                    }

    long  int sum=0;
     for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){

                        sum=sum+temp_error[i][j];


            }

                    }

            int error_new=sum;
           // cout<<"Error for ref. frame= "<<error_new<<"\n";
           outFile<<error_new<<"\n";
            if(error>error_new){


                    error=error_new;
                    p_x=(pos_x+p1[l]);
                    p_y=(pos_y+p2[k]);

            for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){
                    minimal_error_matrix[i][j]=(block_2[i][j]-block_1[i][j]);
                    }
                }

                ///////////psnr



                    }






        }
        }
}

//cout<<"Match Position="<<p_x<<","<<(p_y)<<"\n";
//cout<<"Minimal Error="<<error<<endl;

outFile<<"\n";
outFile<<"Match Position="<<p_x<<","<<(p_y)<<"\n";
outFile<<"Minimal Error="<<error<<"\n";
new_sum=new_sum+error;
if((pos_x!=p_x)||(pos_y!=p_y)){
  outFile<<"Changed!"<<"\n";
}
outFile<<"\n\n\n";
outFile<<"------------------------------------------\n";

errorFile<<"Match Position= "<<p_x<<","<<(p_y)<<"\n\n";
errorFile<<"Minimal Error="<<error<<"\n";
int count_z=0;
          for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){
                    errorFile<< minimal_error_matrix[i][j]<<"\t";
                    if(minimal_error_matrix[i][j]==0) count_z++;
                    }
                    errorFile<<"\n";
                }
errorFile<<"Number of Zeroes="<<count_z<<"\n";
errorFile<<"-------------------------------------------\n\n";


error=INFINITY;

    }
}

float mse=0;
mse=(new_sum/(176*144));
cout<<"\n\n\nMSE="<<mse<<"\n";

float psnr=0;

psnr= 20*log10(255/sqrt(mse));
cout<<"PSNR="<<psnr<<"\n\n\n";

outFile.close();
errorFile.close();

/////////////print//////


///////////////
int block_1_same[16][16];
             for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){
             block_1_same[i][j]=y1[79+i][79+j];

                    }
             }

int block_1_n1_y[16][16];
             for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){
             block_1_n1_y[i][j]=y1[79+16+i][79+j];

                    }
             }

int block_1_p1_y[16][16];
             for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){
             block_1_p1_y[i][j]=y1[79-16+i][79+j];

                    }
             }

int block_1_p1_x[16][16];
             for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){
             block_1_p1_x[i][j]=y1[79+i][79+16+j];

                    }
             }

int block_1_n1_x[16][16];
             for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){
             block_1_n1_x[i][j]=y1[79+i][79-16+j];

                    }
             }


////////////print/////
 for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){

                           // cout<<block_1_n1_y[i][j]<<',';
                    }
                   // cout<<'\n';
                    }
/////////////
int temp_same[16][16];
for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){

                            temp_same[i][j]=abs(block_1[i][j]-block_1_same[i][j]);
                    }

                    }

        int sum=0;
     for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){

                        sum=sum+temp_same[i][j];


            }
                    }
            int error_same=sum;
            //cout<<error_same;
///////////////////////////////////
int temp_p_x[16][16];
for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){

                            temp_p_x[i][j]=abs(block_1[i][j]-block_1_p1_x[i][j]);
                    }

                    }

    sum=0;
     for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){

                        sum=sum+temp_p_x[i][j];


            }
                    }
            int error_p_x=sum;
             // cout<<error_p_x;
//////////////////////
int temp_n_x[16][16];
for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){

                            temp_n_x[i][j]=abs(block_1[i][j]-block_1_n1_x[i][j]);
                    }

                    }

    sum=0;
     for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){

                        sum=sum+temp_n_x[i][j];


            }
                    }
            int error_n_x=sum;
            //  cout<<error_n_x;

//////////
int temp_p_y[16][16];
for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){

                            temp_p_y[i][j]=abs(block_1[i][j]-block_1_p1_y[i][j]);
                    }

                    }

    sum=0;
     for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){

                        sum=sum+temp_p_y[i][j];


            }
                    }
            int error_p_y=sum;
             //cout<<error_p_y;
    //////////////
    int temp_n_y[16][16];
for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){

                            temp_n_y[i][j]=abs(block_1[i][j]-block_1_n1_y[i][j]);
                    }

                    }

    sum=0;
     for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){

                        sum=sum+temp_n_y[i][j];


            }
                    }
            int error_n_y=sum;

       //       cout<<"Error for block at the same position(80,80) ="<<error_same<<'\n';
       //          cout<<"Error for block at the (+X axis) position ="<<error_p_x<<'\n';
       //             cout<<"Error for block at the (-X axis) position ="<<error_n_x<<'\n';
       //                cout<<"Error for block at the (+Y axis) position ="<<error_p_y<<'\n';
        //                  cout<<"Error for block at the (-Y axis) position ="<<error_n_y<<'\n';

         //                   cout<<"\n\n"<<endl;
        ///////////////error///////
        int temp[16][16];
for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){

                            temp[i][j]=block_1[i][j]-block_1_same[i][j];
                    }

                    }
                     //  cout<<"Error=\n\n"<<endl;

             //   outFile.open("Error.txt");
    //for(int i=0;i<16;i++){
                   // for(int j=0;j<16;j++){

                          //  cout<<temp[i][j]<<',';
                         //   outFile<<temp[i][j]<<',';
                            //  outFile<<' ';
                  //  }
                       // outFile<<'\n';
                       // cout<<'\n';
                   // }


        outFile.close();
         file.close();
         int garbage;
         cin>>garbage;////////////no need
        delete memblock;
    }
    else
        cout<<"unable";


     return 0;
}

