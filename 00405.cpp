#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> v_2_1;
vector<int> v_2_2;
vector<int> v_3_1;
vector<int> v_3_2;
vector<int> v_3_3;
//====================================================================================================================================
//function take character and return number
int character_to_int(char s)
{
		if(s=='a' || s=='A')
			return 0;
		else if(s=='b' || s=='B')
			return 1;
		else if(s=='c' || s=='C')
			return 2;
		else if(s=='d' || s=='D')
			return 3;
		else if(s=='e' || s=='E')
			return 4;
		else if(s=='f' || s=='F')
			return 5;
		else if(s=='g' || s=='G')
			return 6;
		else if(s=='h' || s=='H')
			return 7;
		else if(s=='i' || s=='I')
			return 8;
		else if(s=='j' || s=='J')
			return 9;
		else if(s=='k' || s=='K')
			return 10;
		else if(s=='l' || s=='L')
			return 11;
		else if(s=='m' || s=='M')
			return 12;
		else if(s=='n' || s=='N')
			return 13;
		else if(s=='o' || s=='O')
			return 14;
		else if(s=='p' || s=='P')
			return 15;
		else if(s=='q' || s=='Q')
			return 16;
		else if(s=='r' || s=='R')
			return 17;
		else if(s=='s' || s=='S')
			return 18;
		else if(s=='t' || s=='T')
			return 19;
		else if(s=='u' || s=='U')
			return 20;
		else if(s=='v' || s=='V')
			return 21;
		else if(s=='w' || s=='W')
			return 22;
		else if(s=='x' || s=='X')
			return 23;
		else if(s=='y' || s=='Y')
			return 24;
		else if(s=='z' || s=='Z')
			return 25;
		else
			return -1;
}
//====================================================================================================================================
//function take number and return character
char int_char(int n)
{
	if(n==0)
		return 'A';
	if(n==1)
		return 'B';
	if(n==2)
		return 'C';
	if(n==3)
		return 'D';
	if(n==4)
		return 'E';
	if(n==5)
		return 'F';
	if(n==6)
		return 'G';
	if(n==7)
		return 'H';
	if(n==8)
		return 'I';
	if(n==9)
		return 'J';
	if(n==10)
		return 'K';
	if(n==11)
		return 'L';
	if(n==12)
		return 'M';
	if(n==13)
		return 'N';
	if(n==14)
		return 'O';
	if(n==15)
		return 'P';
	if(n==16)
		return 'Q';
	if(n==17)
		return 'R';
	if(n==18)
		return 'S';
	if(n==19)
		return 'T';
	if(n==20)
		return 'U';
	if(n==21)
		return 'V';
	if(n==22)
		return 'W';
	if(n==23)
		return 'X';
	if(n==24)
		return 'Y';
	if(n==25)
		return 'Z';
	else
		return '@';
}
//====================================================================================================================================
// function to find inverse of determined
int inverse_det(int det)
{
	int det_inv;
	if(det==1)
		det_inv=1;
	else if(det==3)
		det_inv=9;
	else if(det==5)
		det_inv=21;
	else if(det==7)
		det_inv=15;
	else if(det==9)
		det_inv=3;
	else if(det==11)
		det_inv=19;
	else if(det==15)
		det_inv=7;
	else if(det==17)
		det_inv=23;
	else if(det==19)
		det_inv=11;
	else if(det==21)
		det_inv=5;
	else if(det==23)
		det_inv=17;
	else if(det==25)
		det_inv=25;
	else
		det_inv=0;

	return det_inv;
}
//====================================================================================================================================
// this function to find keys and decryption of ciphertext with key matrix 2*2 and decryption of ciphertext
void Keys_and_decryption_2()
{
	// input the known plaintext and corresponding ciphertext to find keys
	string plain_t,cipher_t,allcipher;
	cout<<"Enter 8 char from knwon plaintext without space : \n";
	cin>>plain_t;
	cout<<"========================================================================\n";
	cout<<"Enter corresponding ciphertext without space : \n";
	cin>>cipher_t;
	cout<<"========================================================================\n";
	//this arrays to take the input of plaintext and corresponding ciphertext and keys as numbers
	int pn1[2],pn2[2],pn3[2],pn4[2],cn1[2],cn2[2],cn3[2],cn4[2],k1[2][2],k2[2];

	for(int i =0 ;i<2;i++)
	{
		pn1[i]=character_to_int(plain_t[i]);
		pn2[i]=character_to_int(plain_t[i+2]);
		pn3[i]=character_to_int(plain_t[i+4]);
		pn4[i]=character_to_int(plain_t[i+6]);
		cn1[i]=character_to_int(cipher_t[i]);
		cn2[i]=character_to_int(cipher_t[i+2]);
		cn3[i]=character_to_int(cipher_t[i+4]);
		cn4[i]=character_to_int(cipher_t[i+6]);
	}
	// 3 loop to find the first column by substitution and save the result in the key 'K1' 
	// and find the second column by substitution and save the result in the key 'K1'
	//and find the value of key2 "k2" 
	int p10=pn1[0],p11=pn1[1],p20=pn2[0],p21=pn2[1],p30=pn3[0],p31=pn3[1],p40=pn4[0],p41=pn4[1];
	int c10=cn1[0],c20=cn2[0],c30=cn3[0],c40=cn4[0],c11=cn1[1],c21=cn2[1],c31=cn3[1],c41=cn4[1];
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
			for(int k=0;k<26;k++)
			{
				//first column
				if((((p10*i+p11*j+k)%26)==c10) && (((p20*i+p21*j+k)%26)==c20) && (((p30*i+p31*j+k)%26)==c30) && (((p40*i+p41*j+k)%26)==c40))
				{
					v_2_1.push_back(i);
					v_2_1.push_back(j);
					k2[0]=k;
					k2[1]=k;
				}
				//second column
				if((((p10*i+p11*j+k)%26)==c11) && (((p20*i+p21*j+k)%26)==c21) && (((p30*i+p31*j+k)%26)==c31) && (((p40*i+p41*j+k)%26)==c41))
				{
					v_2_2.push_back(i);
					v_2_2.push_back(j);
				}
			}
		}
	}
	k1[0][0]=v_2_1[0];
	k1[1][0]=v_2_1[1];
	k1[0][1]=v_2_2[0];
	k1[1][1]=v_2_2[1];
	//display key 1
	cout<<"The first Key is : \n";
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			cout<<" "<<k1[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"========================================================================\n";
	//display key 2
	cout<<"The secoend Key is : \n";
	cout<<" ["<<k2[0]<<"  "<<k2[1]<<"]"<<endl;
	cout<<"========================================================================\n";
	//======================================================== find inverse of key 1 ============================================================================
	//matrix to save the inverse of k1
	int mat_inv[2][2];
	int indx00=k1[0][0] , indx01=k1[0][1] , indx10=k1[1][0] , indx11=k1[1][1];
	//find the value of determined
	int det=((indx00*indx11)-(indx01*indx10))%26;
	if(det>=0)
		det=det;
	else
		det+=26;
	//find the inverse key to decryption
	int inv_det=inverse_det(det);
	mat_inv[0][0]=((indx11*inv_det)%26);
	mat_inv[1][1]=((indx00*inv_det)%26);
	mat_inv[0][1]=(((-1*indx01+26)*inv_det)%26);
	mat_inv[1][0]=(((-1*indx10+26)*inv_det)%26);

	cout<<"The inverse of first Key is : \n";
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			cout<<" "<<mat_inv[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"========================================================================\n";
	//======================================================== Decryption of ciphertext =================================================================
	cout<<"Enter all cipher without space and with MaxLength 500 : \n";
	cin>>allcipher;
	cout<<"========================================================================\n";
	int c[2],a[500];
	// if condition to enter cipher with even length 
	if(allcipher.length()%2==0)
	{
		// take character by character from cipher and retun the number value of char and save in array 'a[]' the decryption result
		for(int i=0;i<allcipher.length();i+=2)
		{
			c[0]=character_to_int(allcipher[i]);
			c[1]=character_to_int(allcipher[i+1]);
			a[i]=(((c[0]-k2[0])*mat_inv[0][0])+((c[1]-k2[1])*mat_inv[1][0]))%26;
			a[i+1]=(((c[0]-k2[1])*mat_inv[0][1])+((c[1]-k2[1])*mat_inv[1][1]))%26;
		}
	}
	else
	{
		cout<<"The ciphertext must be have even length \n";
	} 
	// for any value in negative result array of decryption add 26 to find result in Z26
	for(int i=0;i<allcipher.length();i++)
	{
		if(a[i]<0)
			a[i]+=26;
	}
	cout<<"The plaintext after decryption : \n";
	for(int i=0;i<allcipher.length();i++)
	{
		cout<<int_char(a[i]);
	} 
	cout<<"\n========================================================================\n";
}
//====================================================================================================================================
// this function to find keys and decryption of ciphertext with key matrix 3*3 and decryption of ciphertext
void Keys_and_decryption_3()
{
	// input the known plaintext and corresponding ciphertext to find keys
	string plain_t,cipher_t,allcipher;
	cout<<"Enter 18 char from knwon plaintext without space : \n";
	cin>>plain_t;
	cout<<"========================================================================\n";
	cout<<"Enter corresponding ciphertext without space : \n";
	cin>>cipher_t;
	cout<<"========================================================================\n";
	//this arrays to take the input of plaintext and corresponding ciphertext and keys as numbers
	int p1[3],p2[3],p3[3],p4[3],p5[3],p6[3],c1[3],c2[3],c3[3],c4[3],c5[3],c6[3],k1[3][3],k2[3];

	for(int i = 0 ; i < 3 ; i++)
	{
		p1[i]=character_to_int(plain_t[i]);
		p2[i]=character_to_int(plain_t[i+3]);
		p3[i]=character_to_int(plain_t[i+6]);
		p4[i]=character_to_int(plain_t[i+9]);
		p5[i]=character_to_int(plain_t[i+12]);
		p6[i]=character_to_int(plain_t[i+15]);
		c1[i]=character_to_int(cipher_t[i]);
		c2[i]=character_to_int(cipher_t[i+3]);
		c3[i]=character_to_int(cipher_t[i+6]);
		c4[i]=character_to_int(cipher_t[i+9]);
		c5[i]=character_to_int(cipher_t[i+12]);
		c6[i]=character_to_int(cipher_t[i+15]);
	}
	// 4 loop to find the first column by substitution and save the result in the key 'K1' 
	// and find the second column by substitution and save the result in the key 'K1'
	// and find the third column by substitution and save the result in the key 'K1'
	int p10=p1[0],p11=p1[1],p12=p1[2],p20=p2[0],p21=p2[1],p22=p2[2],p30=p3[0],p31=p3[1],p32=p3[2],
		p40=p4[0],p41=p4[1],p42=p4[2],p50=p5[0],p51=p5[1],p52=p5[2],p60=p6[0],p61=p6[1],p62=p6[2];
	int c10=c1[0],c20=c2[0],c30=c3[0],c40=c4[0],c11=c1[1],c21=c2[1],c31=c3[1],c41=c4[1],c12=c1[2],
		c22=c2[2],c32=c3[2],c42=c4[2],c50=c5[0],c51=c5[1],c52=c5[2],c60=c6[0],c61=c6[1],c62=c6[2];
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
			for(int k=0;k<26;k++)
			{
				for(int m=0;m<26;m++)
				{
					//first column
					if((((p10*i+p11*j+p12*k+m)%26)==c10) && (((p20*i+p21*j+p22*k+m)%26)==c20) && (((p30*i+p31*j+p32*k+m)%26)==c30)
						&& (((p40*i+p41*j+p42*k+m)%26)==c40) && (((p50*i+p51*j+p52*k+m)%26)==c50) && (((p60*i+p61*j+p62*k+m)%26)==c60))
					{
						v_3_1.push_back(i);
						v_3_1.push_back(j);
						v_3_1.push_back(k);
						k2[0]=m;
						k2[1]=m;
						k2[2]=m;
					}
					//second column
					if((((p10*i+p11*j+p12*k+m)%26)==c11) && (((p20*i+p21*j+p22*k+m)%26)==c21) && (((p30*i+p31*j+p32*k+m)%26)==c31)
						&& (((p40*i+p41*j+p42*k+m)%26)==c41) && (((p50*i+p51*j+p52*k+m)%26)==c51) && (((p60*i+p61*j+p62*k+m)%26)==c61))
					{
						v_3_2.push_back(i);
						v_3_2.push_back(j);
						v_3_2.push_back(k);
					}
					//third column
					if((((p10*i+p11*j+p12*k+m)%26)==c12) && (((p20*i+p21*j+p22*k+m)%26)==c22) && (((p30*i+p31*j+p32*k+m)%26)==c32)
						&& (((p40*i+p41*j+p42*k+m)%26)==c42) && (((p50*i+p51*j+p52*k+m)%26)==c52) && (((p60*i+p61*j+p62*k+m)%26)==c62))
					{
						v_3_3.push_back(i);
						v_3_3.push_back(j);
						v_3_3.push_back(k);
					}
				}
			}
		}
	}
	k1[0][0]=v_3_1[0];
	k1[1][0]=v_3_1[1];
	k1[2][0]=v_3_1[2];
	k1[0][1]=v_3_2[0];
	k1[1][1]=v_3_2[1];
	k1[2][1]=v_3_2[2];
	k1[0][2]=v_3_3[0];
	k1[1][2]=v_3_3[1];
	k1[2][2]=v_3_3[2];
	//display key 1
	cout<<"The first Key is : \n";
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<" "<<k1[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"========================================================================\n";
	//display key 2
	cout<<"The secoend Key is : \n";
	cout<<" ["<<k2[0]<<"  "<<k2[1]<<"  "<<k2[2]<<"]"<<endl;
	cout<<"========================================================================\n";
	//======================================================== find inverse of key 1 ============================================================================
	int mat_Minors[3][3],mat_inv[3][3];
	int indx00=k1[0][0] , indx01=k1[0][1] , indx02=k1[0][2] , indx10=k1[1][0] , indx11=k1[1][1] ,
		indx12=k1[1][2] , indx20=k1[2][0] , indx21=k1[2][1] , indx22=k1[2][2] ;
	//find the value of determined
	int det=(((indx00*indx11*indx22)+(indx01*indx12*indx20)+(indx02*indx10*indx21))-((indx01*indx10*indx22)+(indx00*indx12*indx21)+(indx02*indx11*indx20)))%26;
	if(det>=0)
		det=det;
	else
		det+=26;
	//find the inverse key to decryption
	//find the Minors and Cofactors
	mat_Minors[0][0]=(((indx11*indx22)-(indx12*indx21))%26);
	mat_Minors[0][1]=-1*(((indx10*indx22)-(indx12*indx20))%26);
	mat_Minors[0][2]=(((indx10*indx21)-(indx11*indx20))%26);
	mat_Minors[1][0]=-1*(((indx01*indx22)-(indx02*indx21))%26);
	mat_Minors[1][1]=(((indx00*indx22)-(indx02*indx20))%26);
	mat_Minors[1][2]=-1*(((indx00*indx21)-(indx01*indx20))%26);
	mat_Minors[2][0]=(((indx01*indx12)-(indx02*indx11))%26);
	mat_Minors[2][1]=-1*(((indx00*indx12)-(indx02*indx10))%26);
	mat_Minors[2][2]=(((indx00*indx11)-(indx01*indx10))%26);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(mat_Minors[i][j]<0)
			{
				mat_Minors[i][j]+=26;
			}
		}
	}
	//Adjugate and 1/Determinant * matrix
	mat_inv[0][0]=mat_Minors[0][0];
	mat_inv[1][0]=mat_Minors[0][1];
	mat_inv[2][0]=mat_Minors[0][2];
	mat_inv[0][1]=mat_Minors[1][0];
	mat_inv[1][1]=mat_Minors[1][1];
	mat_inv[2][1]=mat_Minors[1][2];
	mat_inv[0][2]=mat_Minors[2][0];
	mat_inv[1][2]=mat_Minors[2][1];
	mat_inv[2][2]=mat_Minors[2][2];

	int inv_det=inverse_det(det);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			mat_inv[i][j]=(mat_inv[i][j]*inv_det)%26;
		}
	}
	cout<<"The inverse of first Key is : \n";
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<" "<<mat_inv[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"========================================================================\n";
	//======================================================== Decryption of ciphertext =================================================================
	cout<<"Enter all cipher without space and with MaxLength 500 : \n";
	cin>>allcipher;
	cout<<"========================================================================\n";
	int ci[3],a[500];
	// condition to enter cipher with divided by 3 length 
	if(allcipher.length()%3==0)
	{
		// take character by character from cipher and retun the number value of char and save in array 'a[]' the decryption result
		for(int i=0;i<allcipher.length();i+=3)
		{
			ci[0]=character_to_int(allcipher[i]);
			ci[1]=character_to_int(allcipher[i+1]);
			ci[2]=character_to_int(allcipher[i+2]);
			a[i]=(((ci[0]-k2[0])*mat_inv[0][0])+((ci[1]-k2[1])*mat_inv[1][0])+((ci[2]-k2[2])*mat_inv[2][0]))%26;
			a[i+1]=(((ci[0]-k2[0])*mat_inv[0][1])+((ci[1]-k2[1])*mat_inv[1][1])+((ci[2]-k2[2])*mat_inv[2][1]))%26;
			a[i+2]=(((ci[0]-k2[0])*mat_inv[0][2])+((ci[1]-k2[1])*mat_inv[1][2])+((ci[2]-k2[2])*mat_inv[2][2]))%26;
		}
	}
	else
	{
		cout<<"The ciphertext must be divided by 3 length \n";
	} 
	// for any value in negative result array of decryption add 26 to find result in Z26
	for(int i=0;i<allcipher.length();i++)
	{
		if(a[i]<0)
			a[i]+=26;
	}
	cout<<"The plaintext after decryption : \n";
	for(int i=0;i<allcipher.length();i++)
	{
		cout<<int_char(a[i]);
	} 
	cout<<"\n========================================================================\n";

}
void main()
{
	int k,key;
	do
	{
		cout<<"Enter matrix Key 2 or 3 : ";
		cin>>key;
		if(key==2)
		{
			Keys_and_decryption_2();
		}
		else if(key == 3)
		{
			Keys_and_decryption_3();
		}
		else
		{
			cout<<"ERROR! you must enter 2 or 3 ";
		}

		cout<<"press 1 to repeat again \n";
		cout<<"===============================\n";
		cout<<"press another number to exit \n";
		cin>>k;
	}while(k==1);
	system("pause");
}