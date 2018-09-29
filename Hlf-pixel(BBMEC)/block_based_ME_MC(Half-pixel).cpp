#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

ifstream::pos_type size;
char *memblock;
ofstream outFile,errorFile,testFile;

int main()
{
    ifstream file("D:\\Video Compression\\Hlf-pixel(BBMEC)\\foreman.yuv",ios::in|ios::ate);

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
       int y1[144][176];
        int k=((3-1)*(176*144))+((3-1)*2*(88*72));
        //int k=0;
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

        int y2[144][176];
        // k=2*(176*144)+2*2*(88*72);
         //k=((271-1)*(176*144))+((271-1)*2*(88*72));
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
int block_1[17][17],block_2[17][17];int temp_block[17][17];
int pos_x=0,pos_y=0;
int p1[]={0,1,-1,2,-2,3,-3,4,-4,5,-5,6,-6,7,-7,8,-8};
int p2[]={0,1,-1,2,-2,3,-3,4,-4,5,-5,6,-6,7,-7,8,-8};
long int error=999999999;
long int temp_error[16][16];
int temp_error_new [16][16];
int p_x=0,p_y=0;
int flag=0;
int minimal_error_matrix[16][16];
long long int new_sum=0;
long int error_hP=0,sum_hP=0;
 outFile.open("Result.txt");
 errorFile.open("ErrorFile.txt");
 testFile.open("testing.txt");

    cout<<"\n\nProcessing";
    int load;
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

                if(((pos_x+p1[l])<0 && (pos_y+p2[k])<0 ) || ((pos_x+p1[l]+15)>175 && (pos_y+p2[k])<0 ) || ((pos_x+p1[l])<0 && (pos_y+p2[k]+15)>143 ) || ((pos_x+p1[l]+15)>175 && (pos_y+p2[k]+15)>143 )) {
                    flag=2;
outFile<<"Block Position(ref. frame)="<<(pos_x+p1[l])<<","<<(pos_y+p2[k])<<"-->"<<"Invalid!\n";
};
if(flag==0){
int x=0;
if((pos_y+p2[k])<0){
        flag=1;
        outFile<<"Block Position(ref. frame)="<<(pos_x+p1[l])<<","<<(pos_y+p2[k])<<"-->"<<"Error= ";

    for(int m=0;m<(abs(pos_y+p2[k]));m++){
    for(int i=pos_x+p1[l];i<(pos_x+p1[l]+16);i++){

        block_1[m][x]=y1[0][i];
    x++;

    }
    x=0;
    }
    for(int i=(abs(pos_y+p2[k]));i<16;i++){
                    for(int j=0;j<16;j++){
             block_1[i][j]=y1[pos_y+p2[k]+i][pos_x+p1[l]+j];


                    }
             }


/*testFile<<"Block Position(ref. frame)="<<(pos_x+p1[l])<<","<<(pos_y+p2[k])<<"\n";
             for(int i=0;i<16;i++){
                  for(int j=0;j<16;j++){

                       testFile<<block_1[i][j]<<"\t";

                    }
                   testFile<<"\n";
            }*/




x=0;
}

//////////////
int y=0;
int kol_1=15;
if((pos_y+p2[k]+15)>143){
    flag=1;
    outFile<<"Block Position(ref. frame)="<<(pos_x+p1[l])<<","<<(pos_y+p2[k])<<"-->"<<"Error= ";

    for(int m=0;m<((pos_y+p2[k]+15)-143);m++){
    for(int i=pos_x+p1[l];i<(pos_x+p1[l]+16);i++){

        block_1[kol_1][y]=y1[143][i];
    y++;

    }
    kol_1=kol_1-1;
    y=0;
    }
    for(int i=0;i<=(15-((pos_y+p2[k]+15)-143));i++){
                    for(int j=0;j<16;j++){
             block_1[i][j]=y1[pos_y+p2[k]+i][pos_x+p1[l]+j];


                    }
             }







y=0;
}
///////////////////

x=0;
if((pos_x+p1[l])<0){
    flag=1;
    outFile<<"Block Position(ref. frame)="<<(pos_x+p1[l])<<","<<(pos_y+p2[k])<<"-->"<<"Error= ";

    for(int m=0;m<(abs(pos_x+p1[l]));m++){
    for(int i=pos_y+p2[k];i<(pos_y+p2[k]+16);i++){

        block_1[x][m]=y1[i][0];
    x++;

    }
    x=0;
    }
    for(int i=0;i<16;i++){
                    for(int j=(abs(pos_x+p1[l]));j<16;j++){
             block_1[i][j]=y1[pos_y+p2[k]+i][pos_x+p1[l]+j];


                    }
             }





x=0;
}
/////////////
/*y=0;

if((pos_x+p1[l]+15)>175){

    for(int m=15;m<(15-((pos_x+p1[l]+15)-175));m--){
    for(int i=pos_y+p2[k];i<(pos_y+p2[k]+17);i++){

        block_1[y][m]=y1[i][175];
    y++;

    }
    y=0;
    }
    for(int i=0;i<16;i++){
                    for(int j=0;j<=(15-((pos_x+p1[l]+15)-175));j++){
             block_1[i][j]=y1[pos_y+p2[k]+i][pos_x+p1[l]+j];


                    }
             }







y=0;
}
*/
///////////
int kol=15;
if((pos_x+p1[l]+15)>175){
    flag=1;
    outFile<<"Block Position(ref. frame)="<<(pos_x+p1[l])<<","<<(pos_y+p2[k])<<"-->"<<"Error= ";

for(int a=0;a<((pos_x+p1[l]+15)-175);a++){
    for(int i=pos_y+p2[k];i<(pos_y+p2[k]+16);i++){

        block_1[y][kol]=y1[i][175];

        //block_1[y][14]=y1[i][175];
    y++;

    }
    y=0;
    kol=kol-1;


    }


    for(int i=0;i<16;i++){
                    for(int j=0;j<=(15-((pos_x+p1[l]+15)-175));j++){
             block_1[i][j]=y1[pos_y+p2[k]+i][pos_x+p1[l]+j];


                    }
             }






y=0;
}




                if(flag==0){
//cout<<"Block Position(ref. frame)="<<(pos_x+p1[l])<<","<<(pos_y+p2[k])<<"\n";
 outFile<<"Block Position(ref. frame)="<<(pos_x+p1[l])<<","<<(pos_y+p2[k])<<"-->"<<"Error= ";

              for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){
             block_1[i][j]=y1[pos_y+p2[k]+i][pos_x+p1[l]+j];


                    }
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

                        temp_block[i][j]=block_1[i][j];
                    }}


            for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){
                    minimal_error_matrix[i][j]=(block_2[i][j]-block_1[i][j]);
                    }
                }
            }

               ///////////half pixel
              /* if(flag==1){

                for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){
                block_1[i+1][j+1]=block_1[i][j];
               }
                }

                for(int i=0;i<16;i++){
                block_1[0][0]=block_1[0][i];
                }

               }*/
               /////////





                    /* for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){
                block_1[i+1][j+1]=block_1[i][j];
               }
                }

                      for(int i=0;i<16;i++){
                block_1[i][0]=y1[p_x-1][p_y+i];////
                     }
*/









                ///////////psnr












}


        }
}

//cout<<"Match Position="<<p_x<<","<<(p_y)<<"\n";
//cout<<"Minimal Error="<<error<<endl;
////half pixel
            for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){

                        block_1[i][j]=temp_block[i][j];
                    }}

error_hP=0;sum_hP=0;
if(p_x+16<176){


                     for(int i=0;i<16;i++){
                block_1[i][16]=y1[p_y+i][p_x+16];////
                     }
                    }
                    else{

                            for(int i=0;i<16;i++){
                      block_1[i][16]=block_1[i][15];
                            }

                    }



                     for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){

                    block_1[i][j]=((block_1[i][j]+block_1[i][j+1]) /2);


                    }

                    }
                    //print


                    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){

            temp_error[i][j]=pow((block_2[i][j]-block_1[i][j]),2);// sum of sqared error


                    }

                    }


     for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){

                        sum_hP=sum_hP+temp_error[i][j];


            }

                    }

           error_hP=sum_hP;


            if(error>error_hP){

outFile<<"Previous Error = "<<error<<"\n\n";


                    error=error_hP;
                     p_x=(p_x);
                     p_y=(p_y);
                   outFile<<"**********************************here\n";
                    outFile<<"("<<(p_x+0.5f)<<","<<p_y<<")"<<"\n";
                    outFile<<"Error for (HP +X)= "<<error_hP<<"\n\n";
            }
    ////////
//////////////////HP-1

            for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){

                        block_1[i][j]=temp_block[i][j];
                    }}
error_hP=0;sum_hP=0;
if((p_x-1)<0){


                ///////shift

                            for(int i=16;i>=0;i--){
                    for(int j=16;j>=0;j--){
                block_1[i][j+1]=block_1[i][j];
               }
                }

                for(int i=0;i<16;i++){
                block_1[i][0]=block_1[i][1];
                }

               }


                    else{


                            for(int i=16;i>=0;i--){
                    for(int j=16;j>=0;j--){
                block_1[i][j+1]=block_1[i][j];
               }
                }

                for(int i=0;i<16;i++){
                block_1[i][0]=y1[p_y+i][p_x-1];
                }

               }






                     for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){

                    block_1[i][j]=((block_1[i][j]+block_1[i][j+1]) /2);
                     //testFile<<block_1[i][j]<<"\t";

                    }
                   // testFile<<"\n";
                    }
                    //print


                    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){

            temp_error[i][j]=pow((block_2[i][j]-block_1[i][j]),2);// sum of sqared error


                    }

                    }


     for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){

                        sum_hP=sum_hP+temp_error[i][j];


            }

                    }

           error_hP=sum_hP;


            if(error>error_hP){

outFile<<"Previous Error = "<<error<<"\n\n";


                    error=error_hP;
                     p_x=(p_x);
                     p_y=(p_y);
                   outFile<<"**********************************here\n";
                    outFile<<"("<<(p_x-0.5f)<<","<<p_y<<")"<<"\n";
                    outFile<<"Error for (HP -X)= "<<error_hP<<"\n\n";
            }

            /////////////////
          //////  half-pixel (Y -1)
           for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){

                        block_1[i][j]=temp_block[i][j];
                    }}
error_hP=0;sum_hP=0;
if((p_y-1)<0){


                ///////shift


                            for(int i=16;i>=0;i--){
                    for(int j=16;j>=0;j--){
                block_1[i+1][j]=block_1[i][j];
               }
                }

                for(int i=0;i<16;i++){
                block_1[0][i]=block_1[1][i];
                }

               }


                    else{


                            for(int i=16;i>=0;i--){
                    for(int j=16;j>=0;j--){
                block_1[i+1][j]=block_1[i][j];
               }
                }

                for(int i=0;i<16;i++){
                block_1[0][i]=y1[p_y-1][p_x+i];
                }

               }



                     for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){

                    block_1[i][j]=((block_1[i][j]+block_1[i+1][j]) /2);
                   //  testFile<<block_1[i][j]<<"\t";

                    }
                   // testFile<<"\n";
                    }
                    //print


                    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){

            temp_error[i][j]=pow((block_2[i][j]-block_1[i][j]),2);// sum of sqared error


                    }

                    }


     for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){

                        sum_hP=sum_hP+temp_error[i][j];


            }

                    }

           error_hP=sum_hP;


            if(error>error_hP){

outFile<<"\nPrevious Error = "<<error<<"\n";


                    error=error_hP;
                     p_x=(p_x);
                     p_y=(p_y);
                   outFile<<"**********************************here\n";
                    outFile<<"("<<(p_x)<<","<<(p_y-0.5f)<<")"<<"\n";
                    outFile<<"Error for (HP -Y)= "<<error_hP<<"\n\n";
            }
////////////////(HP +Y)

  for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){

                        block_1[i][j]=temp_block[i][j];
                    }}
error_hP=0;sum_hP=0;
if((p_y+16)<144){


                ///////shift
    testFile<<"X="<<p_x<<","<<"Y="<<(p_y)<<"\n";
        testFile<<"here (p_y+16)<144--------------------------------\n\n\n";

     for(int i=0;i<16;i++){
                block_1[16][i]=y1[p_y+16][p_x+i];////
                     }
                    }

                    else{
testFile<<"X="<<p_x<<","<<"Y="<<(p_y)<<"\n";
        testFile<<"here (p_y+16)=>144--------------------------------\n\n\n";
                            for(int i=0;i<16;i++){
                      block_1[16][i]=block_1[15][i];
                            }

                    }


                    testFile<<"*********************************\n";
                     for(int i=0;i<=16;i++){
                    for(int j=0;j<16;j++){

                        testFile<<block_1[i][j]<<"\t";

                    }
                    testFile<<"\n";
                    }
                    testFile<<"*********************************\n";
                    testFile<<"*********************************\n";



                     for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){

                    block_1[i][j]=((block_1[i][j]+block_1[i+1][j]) /2);
                    testFile<<block_1[i][j]<<"\t";

                    }
                   testFile<<"\n";
                    }
                    //print


                    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){

            temp_error[i][j]=pow((block_2[i][j]-block_1[i][j]),2);// sum of sqared error


                    }

                    }


     for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){

                        sum_hP=sum_hP+temp_error[i][j];


            }

                    }

           error_hP=sum_hP;


            if(error>error_hP){


outFile<<"Previous Error = "<<error<<"\n\n";

                    error=error_hP;
                     p_x=(p_x);
                     p_y=(p_y);
                   outFile<<"**********************************here\n";
                    outFile<<"("<<(p_x)<<","<<(p_y+0.5f)<<")"<<"\n";
                    outFile<<"Error for (HP +Y)= "<<error_hP<<"\n\n";
            }

//////////////////////


outFile<<"\n";
outFile<<"Match Position="<<p_x<<","<<(p_y)<<"\n";
outFile<<"Minimal Error="<<error<<"\n";
new_sum=new_sum+error;
if((pos_x!=p_x)||(pos_y!=p_y)){
  outFile<<"Changed!"<<"\n";
}
outFile<<"\n\n\n";
outFile<<"------------------------------------------\n";

errorFile<<"Match Position= "<<p_x<<","<<(p_y)<<"\n";
errorFile<<"Minimal Error="<<error<<"\n\n";
int count_z=0;
          for(int i=0;i<16;i++){
                    for(int j=0;j<16;j++){
                   // errorFile<< minimal_error_matrix[i][j]<<"\t";
                    if(minimal_error_matrix[i][j]==0) count_z++;
                    }
                   // errorFile<<"\n";
                }
//errorFile<<"Number of Zeroes="<<count_z<<"\n";
//errorFile<<"-------------------------------------------\n\n";


error=999999999;
//cout<<error<<"\n";

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



      //  outFile.close();
         file.close();
        testFile.close();
         int garbage;
         cin>>garbage;////////////no need
        delete memblock;
  }

 else
        cout<<"unable";


     return 0;
}


